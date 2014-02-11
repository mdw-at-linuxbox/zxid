#!/usr/bin/perl
# Copyright (c) 2012-2014 Synergetics SA (sampo@synergetics.be), All Rights Reserved.
# Copyright (c) 2010 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
# This is confidential unpublished proprietary source code of the author.
# NO WARRANTY, not even implied warranties. Contains trade secrets.
# Distribution prohibited unless authorized in writing.
# Licensed under Apache License 2.0, see file COPYING.
# $Id$
#
# 9.2.2014, created based on zxidnewuser.pl --Sampo
#
# Web GUI for recovering password, possibly in middle of login sequence.
# The AuthnRequest is preserved through new user creation by passing ar.

$from = 'sampo-pwbot-noreply@zxid.org';
$admin_mail = 'sampo-pwadm@zxid.org';
$dir = '/var/zxid/idp';

$usage = <<USAGE;
Web GUI for creating new user, possibly in middle of login sequence.
Usage: http://localhost:8081/zxidrecoverpw.pl?QUERY_STRING
       ./zxidrecoverpw.pl -a QUERY_STRING
         -a Ascii mode
USAGE
    ;
die $USAGE if $ARGV[0] =~ /^-[Hh?]/;

use Data::Dumper;
use MIME::Base64;

close STDERR;
open STDERR, ">>/var/tmp/zxid.stderr" or die "Cant open error log: $!";
select STDERR; $|=1; select STDOUT;

($sec,$min,$hour,$mday,$mon,$year,$wday,$yday,$isdst) = gmtime(time);
$ts = sprintf "%04d%02d%02d-%02d%02d%02d", $year+1900, $mon+1, $mday, $hour, $min, $sec;
#warn "$$: START env: " . Dumper(\%ENV);

$ENV{QUERY_STRING} ||= shift;
cgidec($ENV{QUERY_STRING});

if ($ENV{CONTENT_LENGTH}) {
    sysread STDIN, $data, $ENV{CONTENT_LENGTH};
    #warn "GOT($data) $ENV{CONTENT_LENGTH}";
    cgidec($data);
}
warn "$$: cgi: " . Dumper(\%cgi);

sub uridec {
    my ($val) = @_;
    $val =~ s/\+/ /g;
    $val =~ s/%([0-9a-f]{2})/chr(hex($1))/gsexi;  # URI decode
    return $val;
}

sub urienc {
    my ($val) = @_;
    $val =~ s/([^A-Za-z0-9.,_-])/sprintf("%%%02x",ord($1))/gsex; # URI enc
    return $val;
}

sub cgidec {
    my ($d) = @_;
    for $nv (split '&', $d) {
	($n, $v) = split '=', $nv, 2;
	$cgi{$n} = uridec($v);
    }
}

sub readall {
    my ($f) = @_;
    my ($pkg, $srcfile, $line) = caller;
    undef $/;         # Read all in, without breaking on lines
    open F, "<$f" or die "$srcfile:$line: Cant read($f): $!";
    binmode F;
    my $x = <F>;
    close F;
    return $x;
}

sub show_templ {
    my ($templ, $hr) = @_;
    $templ = readall($templ);
    $templ =~ s/!!(\w+)/$$hr{$1}/gs;
    my $len = length $templ;
    syswrite STDOUT, "Content-Type: text/html\r\nContent-Length: $len\r\n\r\n$templ";
    exit;
}

sub redirect {
    my ($url) = @_;
    syswrite STDOUT, "Location: $url\r\n\r\n";
    exit;
}

sub send_mail {
    my ($to, $subj, $body) = @_;
    open S, "|/usr/sbin/sendmail -i -B 8BITMIME -t" or die "No sendmail in path: $! $?";
    $msg = <<MAIL;
From: $from
To: $to
Subject: $subj
MIME-Version: 1.0
Content-Type: text/plain; charset=ISO-8859-1
Content-Transfer-Encoding: 8bit

$body
MAIL
;
    warn "msr($msg)";
    print S $msg;
    close S;
}

sub send_detail {
    my ($subj) = @_;
    send_mail($admin_mail, $subj, <<BODY);
intervention: $cgi{'ivent'}
uid: $cgi{'au'}
pw: $pw
ip: $ENV{REMOTE_ADDR}
email: $cgi{'email'}
im: $cgi{'im'}
tel: $cgi{'tel'}

Comments or special requests:
$cgi{'comment'}

Attributes:
$at
EOF
BODY
    ;
}

### MAIN

if (length $cgi{'continue'}) {
    if ($cgi{'zxidpurl'} && $cgi{'zxrfr'} && $cgi{'ar'}) {
       warn "Redirecting back to IdP";
       redirect("$cgi{'zxidpurl'}?o=$cgi{'zxrfr'}&ar=$cgi{'ar'}");
    } else {
       warn "Redirecting back to index page.";
       redirect("/");
    }
}

if (length $cgi{'ok'}) {
    if ($cgi{'ivent'} ne 'block' && $cgi{'ivent'} ne 'human' && $cgi{'ivent'} ne 'auto') {
	warn "No intervention chosen. Redirecting back to index page.";
	redirect("/");
    }

    if (length $cgi{'au'} < 3 || length $cgi{'au'} > 40) {
	$cgi{'ERR'} = "Username must be at least 3 characters long (and no longer than 40 chars).";
    } elsif ($cgi{'au'} !~ /^[A-Za-z0-9_-]+$/s) {
	$cgi{'ERR'} = "Username can only contain characters [A-Za-z0-9_-]";
    } elsif (! -e "${dir}uid/$cgi{'au'}") {
	$cgi{'ERR'} = "Username not known.";
    } else {
	warn "Reset password for user($cgi{'au'})";

	open R, "</dev/urandom" or die "Cant open read /dev/urandom: $!";
	sysread R, $pw, 9;
	close R;
	$pw = encode_base64($pw,'');
	
	$at =  readall("${dir}uid/$cgi{'au'}/.bs/.at");
	$at .= readall("${dir}uid/$cgi{'au'}/.bs/.optat");
	($email) = $at =~ /^email:\s+(\S+)$/m;
	
	open LOG, ">>${dir}uid/$cgi{'au'}/.log" or die "Cant open write .log: $!";
	print LOG "$ts Password reset for $cgi{'au'} email($email) ip=$ENV{REMOTE_ADDR}\n" or die "Cant write .log: $!";
	close LOG or die "Cant close write .log: $!";

	$human = readall("${dir}uid/$cgi{'au'}/.human");
	if ($human < 1 && $cgi{'ivent'} ne 'human') {
	    open P, "|./zxpasswd $cgi{'au'} ${dir}uid" or die "Cant open pipe to zxpasswd: $! $?";
	    print P $pw;
	    close P;
	    if ($cgi{'ivent'} eq 'auto' && $email) {
		send_mail($email, "Password reset", <<BODY);
Your new password is: $pw

Please login with the new password within 24h to prevent expiration.

Delete this mail, to prevent exposure of the password, as soon as
you have confirmed that the password works. You may keep a private
record of the password in a network inaccessible place, but please
do not use this mail as long term record as inappropriate access
to your mailbox could compromise your account.

If you do not wish to receive passwords by email, please request
human intervention when resetting your password.
BODY
;
		# *** password expiration code
	    }
	    $pw = '(omitted)';
	    send_detail("PW Reset Auto $cgi{'au'}");
	} else {
	    send_detail("PW Reset Human $cgi{'au'}");
	}
	
	if ($cgi{'zxidpurl'} && $cgi{'zxrfr'} && $cgi{'ar'}) {
	    warn "Password reset for user($cgi{'au'})";
	    $cgi{MSG} = "Success! Password reset for user $cgi{'au'}. Check your email (including spam folder). Click Continue to get back to IdP login.";
	    show_templ("newuser-status.html", \%cgi);
        } else {
	    warn "Password reset for user($cgi{'au'})";
	    $cgi{MSG} = "Success! Password reset for user $cgi{'au'}. Check your email (including spam folder). Click Continue to get back to top.";
	    show_templ("newuser-status.html", \%cgi);
	}
    }
}

$cgi{'ip'} = $ENV{REMOTE_ADDR};
show_templ("recoverpw-main.html", \%cgi);

__END__
