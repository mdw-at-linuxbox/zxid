/* zxcall.c  -  Web Service Client tool
 * Copyright (c) 2010 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing.
 * Licensed under Apache License 2.0, see file COPYING.
 * $Id: zxcot.c,v 1.5 2009-11-29 12:23:06 sampo Exp $
 *
 * 27.8.2009, created --Sampo
 */

#include "platform.h"  /* for dirent.h */

#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

#include "errmac.h"
#include "zx.h"
#include "zxid.h"
#include "zxidconf.h"
#include "c/zxidvers.h"
#include "c/zx-const.h"
#include "c/zx-ns.h"
#include "c/zx-data.h"

char* help =
"zxcall  -  Web Service Client tool R" ZXID_REL "\n\
SAML 2.0 and ID-WSF 2.0 are standards for federated identity and web services.\n\
Copyright (c) 2010 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.\n\
NO WARRANTY, not even implied warranties. Licensed under Apache License v2.0\n\
See http://www.apache.org/licenses/LICENSE-2.0\n\
Send well researched bug reports to the author. Home: zxid.org\n\
\n\
Usage: zxcall [options] -s SESID -t SVCTYPE <soap_req_body.xml >soap_resp.xml\n\
       zxcall [options] -a IDP USER:PW -t SVCTYPE <soap_req_body.xml >soap_resp.xml\n\
       zxcall [options] -a IDP USER:PW -t SVCTYPE -nd # Discovery only\n\
       zxcall [options] -a IDP USER:PW   # Authentication only\n\
       zxcall [options] -s SESID -im EID # Identity Mapping to EID\n\
       zxcall [options] -s SESID -l      # List session cache\n\
  -c CONF          Optional configuration string (default -c PATH=/var/zxid/)\n\
                   Most of the configuration is read from /var/zxid/zxid.conf\n\
  -s SESID         Session ID referring to a directory in /var/zxid/ses\n\
                   Use zxidhlo to do SSO and then cut and paste from there.\n\
  -a IDP USER:PW   Use Authentication service to authenticate the user and\n\
                   create session. IDP is IdP's Entity ID. This is alternative to -s\n\
  -t SVCTYPE       Service Type URI. Used for discovery. Mandatory (omitting -t\n\
                   causes authorization only mode, provided that -az was specified).\n\
  -u URL           Optional endpoint URL or ProviderID. Discovery must match this.\n\
  -di DISCOOPTS    Optional discovery options. Query string format.\n\
  -din N           Discovery index (default: 1=pick first).\n\
  -az AZCREDS      Optional authorization credentials. Query string format.\n\
                   N.B. For authorization to work PDP_URL configuration option is needed.\n\
  -im DSTEID       Map session's login identity to identity at some other SP\n\
  -e SOAPBODY      Pass SOAP body as argument (default is to read from STDIN)\n\
  -b               In response, only return content of SOAP body, omitting Envelope and Body.\n\
  -nd              Discovery only (you need to specify -t SVCTYPE as well)\n\
  -n               Dryrun. Do not actually make call. Instead print it to stdout.\n\
  -l               List EPR cache (you need to specify -s SEDID or -a as well)\n\
  -v               Verbose messages.\n\
  -q               Be extra quiet.\n\
  -d               Turn on debugging.\n\
  -dc              Dump config.\n\
  -h               This help message\n\
  --               End of options\n\
\n\
echo '<query>Foo</query>' | zxcall -a https://idp.tas3.eu/zxididp?o=B user:pw -t urn:x-demo-svc\n\
\n";

int dryrun  = 0;
int verbose = 1;
int out_fmt = 0;
int din = 1;
int di_only = 0;
int listses = 0;
char* entid = 0;
char* idp   = 0;
char* user  = 0;
char* sid = 0;
char* svc = 0;
char* url = 0;
char* di  = 0;
char* az  = 0;
char* im_to = 0;
char* bdy = 0;
zxid_conf* cf;

/* Called by:  main x8, zxcall_main, zxcot_main */
static void opt(int* argc, char*** argv, char*** env)
{
  struct zx_str* ss;
  if (*argc <= 1) return;
  
  while (1) {
    ++(*argv); --(*argc);
    
    if (!(*argc) || ((*argv)[0][0] != '-')) break;  /* normal exit from options loop */
    
    switch ((*argv)[0][1]) {
    case '-': if ((*argv)[0][2]) break;
      ++(*argv); --(*argc);
      DD("End of options by --");
      return;  /* -- ends the options */

    case 'a':
      switch ((*argv)[0][2]) {
      case '\0':
	++(*argv); --(*argc);
	if ((*argc) < 2) break;
	idp = (*argv)[0];
	++(*argv); --(*argc);
	user = (*argv)[0];
	continue;
      case 'z':
	++(*argv); --(*argc);
	if ((*argc) < 1) break;
	az = (*argv)[0];
	continue;
      }
      break;

    case 'b':
      switch ((*argv)[0][2]) {
      case '\0':
	++out_fmt;
	continue;
      }
      break;

    case 'c':
      switch ((*argv)[0][2]) {
      case '\0':
	++(*argv); --(*argc);
	if ((*argc) < 1) break;
	zxid_parse_conf(cf, (*argv)[0]);
	continue;
      }
      break;

    case 'd':
      switch ((*argv)[0][2]) {
      case '\0':
	++zx_debug;
	continue;
      case 'i':
        switch ((*argv)[0][3]) {
	case '\0':
	  ++(*argv); --(*argc);
	  if ((*argc) < 1) break;
	  di = (*argv)[0];
	  continue;
	case 'n':
	  ++(*argv); --(*argc);
	  if ((*argc) < 1) break;
	  sscanf((*argv)[0], "%i", &din);
	  continue;
	}
      case 'c':
	ss = zxid_show_conf(cf);
	if (verbose>1) {
	  printf("\n======== CONF ========\n%.*s\n^^^^^^^^ CONF ^^^^^^^^\n",ss->len,ss->s);
	  exit(0);
	}
	fprintf(stderr, "\n======== CONF ========\n%.*s\n^^^^^^^^ CONF ^^^^^^^^\n",ss->len,ss->s);
	continue;
      }
      break;

    case 'e':
      switch ((*argv)[0][2]) {
      case '\0':
	++(*argv); --(*argc);
	if ((*argc) < 1) break;
	bdy = (*argv)[0];
	continue;
      }
      break;

    case 'i':
      switch ((*argv)[0][2]) {
      case 'm':
	++(*argv); --(*argc);
	if ((*argc) < 1) break;
	im_to = (*argv)[0];
	continue;
      }
      break;

    case 'l':
      switch ((*argv)[0][2]) {
      case '\0':
	++listses;
	continue;
#if 0
      case 'i':
	if (!strcmp((*argv)[0],"-license")) {
	  extern char* license;
	  fprintf(stderr, license);
	  exit(0);
	}
	break;
#endif
      }
      break;

    case 'n':
      switch ((*argv)[0][2]) {
      case 'd':
	++di_only;
	continue;
      case '\0':
	++dryrun;
	continue;
      }
      break;

    case 'q':
      switch ((*argv)[0][2]) {
      case '\0':
	verbose = 0;
	continue;
      }
      break;

    case 's':
      switch ((*argv)[0][2]) {
      case '\0':
	++(*argv); --(*argc);
	if ((*argc) < 1) break;
	sid = (*argv)[0];
	continue;
      }
      break;

    case 't':
      switch ((*argv)[0][2]) {
      case '\0':
	++(*argv); --(*argc);
	if ((*argc) < 1) break;
	svc = (*argv)[0];
	continue;
      }
      break;

    case 'u':
      switch ((*argv)[0][2]) {
      case '\0':
	++(*argv); --(*argc);
	if ((*argc) < 1) break;
	url = (*argv)[0];
	continue;
      }
      break;

    case 'v':
      switch ((*argv)[0][2]) {
      case '\0':
	++verbose;
	continue;
      }
      break;

    } 
    /* fall thru means unrecognized flag */
    if (*argc)
      fprintf(stderr, "Unrecognized flag `%s'\n", (*argv)[0]);
help:
    fprintf(stderr, help);
    /*fprintf(stderr, "version=0x%06x rel(%s)\n", zxid_version(), zxid_version_str());*/
    exit(3);
  }
  if (!sid && !idp) {
    fprintf(stderr, "MUST specify either -s or -a\n");
    goto help;
  }
}


/*() List session and especially its EPR cache to stdout.
 * Typical name: /var/zxid/ses/SESID/SVCTYPE,SHA1
 *
 * cf:: ZXID configuration object, also used for memory allocation
 * ses:: Session object in whose EPR cache the file is searched
 *
 * See also: zxid_find_epr() */

/* Called by:  main */
int zxid_print_session(zxid_conf* cf, zxid_ses* ses)
{
  struct zx_root_s* r;
  int epr_len, din = 0;
  char path[ZXID_MAX_BUF];
  char* epr_buf;  /* MUST NOT come from stack. */
  DIR* dir;
  struct dirent * de;
  zxid_epr* epr;
  struct zx_a_Metadata_s* md;
  struct zx_str* ss;
  
  D_INDENT("lstses: ");

  if (!name_from_path(path, sizeof(path), "%s" ZXID_SES_DIR "%s", cf->path, ses->sid)) {
    D_DEDENT("lstses: ");
    return 0;
  }
  
  printf("SESID:  %s\nSESDIR: %s\n", ses->sid, path);
  dir = opendir(path);
  if (!dir) {
    perror("opendir to find epr in session");
    ERR("Opening session for find epr by opendir failed path(%s) sesptr=%p", path, ses);
    D_DEDENT("lstses: ");
    return 0;
  }

  while (de = readdir(dir)) {
    D("%d Considering file(%s)", din, de->d_name);
    if (de->d_name[0] == '.')  /* . .. and "hidden" files */
      continue;
    if (de->d_name[strlen(de->d_name)-1] == '~')  /* Ignore backups from hand edited EPRs. */
      continue;
    D("%d Checking EPR content file(%s)", din, de->d_name);
    epr_buf = read_all_alloc(cf->ctx, "lstses", 1, &epr_len,
			     "%s" ZXID_SES_DIR "%s/%s", cf->path, ses->sid, de->d_name);
    if (!epr_buf)
      continue;
    
    r = zx_dec_zx_root(cf->ctx, epr_len, epr_buf, "lstses");
    if (!r || !r->EndpointReference) {
      ERR("No EPR found. Failed to parse epr_buf(%.*s)", epr_len, epr_buf);
      continue;
    }
    epr = r->EndpointReference;
    ZX_FREE(cf->ctx, r);

    md = epr->Metadata;
    if (!md || !md->ServiceType || !md->ServiceType->content || !md->ServiceType->content->len) {
      ERR("No Metadata %p or ServiceType. Failed to parse epr_buf(%.*s)", md, epr_len, epr_buf);
      printf("EPR %d no service type\n", ++din);
    } else {
      ss = md->ServiceType->content;
      printf("EPR %d SvcType: %.*s\n", ++din, ss->len, ss->s);
    }
    ss = zxid_get_epr_address(cf, epr);
    printf("  URL:         %.*s\n", ss?ss->len:0, ss?ss->s:"");
    ss = zxid_get_epr_entid(cf, epr);
    printf("  EntityID:    %.*s\n", ss?ss->len:0, ss?ss->s:"");
    ss = zxid_get_epr_desc(cf, epr);
    printf("  Description: %.*s\n", ss?ss->len:0, ss?ss->s:"");
  }
  ZX_FREE(cf->ctx, epr_buf);
  closedir(dir);
  D_DEDENT("lstses: ");
  return 0;
}

#ifndef zxcall_main
#define zxcall_main main
#endif

/*() Web Services Client tool */

/* Called by: */
int zxcall_main(int argc, char** argv, char** env)
{
  int siz, got, n;
  char* p;
  struct zx_str* ss;
  zxid_ses* ses;
  zxid_entity* idp_meta;
  zxid_epr* epr;

  strncpy(zx_instance, "\tzxcall", sizeof(zx_instance));
  cf = zxid_new_conf_to_cf(0);
  opt(&argc, &argv, &env);
  
  if (sid) {
    D("Existing session sesid(%s)", sid);
    ses = zxid_fetch_ses(cf, sid);
    if (!ses) {
      ERR("Session not found or error in session sesid(%s)", sid);
      return 1;
    }
  } else {
    D("Obtain session from authentication service(%s)", idp);
    idp_meta = zxid_get_ent(cf, idp);
    if (!idp_meta) {
      ERR("IdP metadata not found and could not be fetched. idp(%s)", idp);
      return 1;
    }
    for (p = user; !ONE_OF_2(*p, ':', 0); ++p) ;
    if (*p)
      *p++ = 0;
    ses = zxid_as_call(cf, idp_meta, user, p);
    if (!ses) {
      ERR("Login using Authentication Service failed idp(%s)", idp);
      return 1;
    }
  }

  if (listses)
    return zxid_print_session(cf, ses);   

  if (im_to) {
    D("Map to identity at eid(%s)", im_to);
    zxid_map_identity_token(cf, ses, im_to, 0);
    //printf("%.*s\n", nameid->gg.content->len, nameid->gg.content->s);
    return 0;
  }

  if (di_only) {
    D("Discover only. svctype(%s), index=%d", STRNULLCHK(svc), din);
    epr = zxid_get_epr(cf, ses, svc, url, di, 0 /*action*/, din);
    if (!epr) {
      ERR("Discovery failed to find any epr of service type(%s)", STRNULLCHK(svc));
      return 3;
    }
    ss = zxid_get_epr_address(cf, epr);
    printf("Found epr. index=%d service type(%s)\n  URL:         %.*s\n",
	   din, STRNULLCHK(svc), ss?ss->len:0, ss?ss->s:"");
    ss = zxid_get_epr_entid(cf, epr);
    printf("  EntityID:    %.*s\n", ss?ss->len:0, ss?ss->s:"");
    ss = zxid_get_epr_desc(cf, epr);
    printf("  Description: %.*s\n", ss?ss->len:0, ss?ss->s:"");
    return 0;
  }
  
  if (svc) {
    D("Call service svctype(%s)", svc);
    if (!bdy) {
      if (verbose)
	fprintf(stderr, "Reading SOAP request body from stdin...\n");
      siz = 4096;
      p = bdy = ZX_ALLOC(cf->ctx, siz);
      while (1) {
	n = read_all_fd(0, p, siz+bdy-p-1, &got);
	if (n == -1) {
	  perror("reading SOAP req from stdin");
	  break;
	}
	p += got;
	if (got < siz+bdy-p-1) break;
	siz += 60*1024;
	REALLOCN(bdy, siz);
      }
      *p = 0;
    }
    if (dryrun) {
      if (verbose)
	fprintf(stderr, "Dryrun. Call aborted.\n");
      return 0;
    }
    if (verbose)
      fprintf(stderr, "Calling...\n");
    
    ss = zxid_call(cf, ses, svc, url, di, az, bdy);
    if (!ss || !ss->s) {
      ERR("Call failed %p", ss);
      return 2;
    }
    if (verbose)
      fprintf(stderr, "Call returned %d bytes.\n", ss->len);
    if (out_fmt) {
      p = zxid_extract_body(cf, ss->s);
      printf("%s", p);
    } else
      printf("%.*s", ss->len, ss->s);
  } else if (az) {
    D("Call Az(%s)", az);
    if (dryrun) {
      if (verbose)
	fprintf(stderr, "Dryrun. zxid_az() aborted.\n");
      return 0;
    }
    if (zxid_az_cf_ses(cf, az, ses)) {
      if (verbose)
	fprintf(stderr, "Permit.\n");
      return 0;
    } else {
      if (verbose)
	fprintf(stderr, "Deny.\n");
      return 1;
    }
  } else {
    D("Neither service type (-t) nor -az supplied. Performed only authentication. %d",0);
    if (verbose)
      fprintf(stderr, "Authentication only.\n");
  }
  return 0;
}

/* EOF  --  zxcall.c */
