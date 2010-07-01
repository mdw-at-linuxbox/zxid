/* c/zx-tas3-getput.c - WARNING: This file was automatically generated. DO NOT EDIT!
 * $Id$ */
/* Code generation design Copyright (c) 2006 Sampo Kellomaki (sampo@iki.fi),
 * All Rights Reserved. NO WARRANTY. See file COPYING for terms and conditions
 * of use. Some aspects of code generation were driven by schema
 * descriptions that were used as input and may be subject to their own copyright.
 * Code generation uses a template, whose copyright statement follows. */

/** getput-templ.c  -  Auxiliary functions template: cloning, freeing, walking data
 ** Copyright (c) 2006 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 ** Author: Sampo Kellomaki (sampo@iki.fi)
 ** This is confidential unpublished proprietary source code of the author.
 ** NO WARRANTY, not even implied warranties. Contains trade secrets.
 ** Distribution prohibited unless authorized in writing.
 ** Licensed under Apache License 2.0, see file COPYING.
 ** Id: getput-templ.c,v 1.8 2009-08-30 15:09:26 sampo Exp $
 **
 ** 30.5.2006, created, Sampo Kellomaki (sampo@iki.fi)
 ** 6.8.2006, factored from enc-templ.c to separate file --Sampo
 **
 ** N.B: wo=wire order (needed for exc-c14n), so=schema order
 ** Edit with care! xsd2sg.pl applies various substitutions to this file.
 **/

#include <memory.h>
#include "errmac.h"
#include "zx.h"
#include "c/zx-const.h"
#include "c/zx-data.h"
#include "c/zx-tas3-data.h"



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_tas3_Credentials_NUM_Assertion) */

int zx_tas3_Credentials_NUM_Assertion(struct zx_tas3_Credentials_s* x)
{
  struct zx_sa_Assertion_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Assertion; y; ++n, y = (struct zx_sa_Assertion_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_tas3_Credentials_GET_Assertion) */

struct zx_sa_Assertion_s* zx_tas3_Credentials_GET_Assertion(struct zx_tas3_Credentials_s* x, int n)
{
  struct zx_sa_Assertion_s* y;
  if (!x) return 0;
  for (y = x->Assertion; n>=0 && y; --n, y = (struct zx_sa_Assertion_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_tas3_Credentials_POP_Assertion) */

struct zx_sa_Assertion_s* zx_tas3_Credentials_POP_Assertion(struct zx_tas3_Credentials_s* x)
{
  struct zx_sa_Assertion_s* y;
  if (!x) return 0;
  y = x->Assertion;
  if (y)
    x->Assertion = (struct zx_sa_Assertion_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_tas3_Credentials_PUSH_Assertion) */

void zx_tas3_Credentials_PUSH_Assertion(struct zx_tas3_Credentials_s* x, struct zx_sa_Assertion_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Assertion->gg.g;
  x->Assertion = z;
}

/* FUNC(zx_tas3_Credentials_REV_Assertion) */

void zx_tas3_Credentials_REV_Assertion(struct zx_tas3_Credentials_s* x)
{
  struct zx_sa_Assertion_s* nxt;
  struct zx_sa_Assertion_s* y;
  if (!x) return;
  y = x->Assertion;
  if (!y) return;
  x->Assertion = 0;
  while (y) {
    nxt = (struct zx_sa_Assertion_s*)y->gg.g.n;
    y->gg.g.n = &x->Assertion->gg.g;
    x->Assertion = y;
    y = nxt;
  }
}

/* FUNC(zx_tas3_Credentials_PUT_Assertion) */

void zx_tas3_Credentials_PUT_Assertion(struct zx_tas3_Credentials_s* x, int n, struct zx_sa_Assertion_s* z)
{
  struct zx_sa_Assertion_s* y;
  if (!x || !z) return;
  y = x->Assertion;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Assertion = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_Assertion_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_tas3_Credentials_ADD_Assertion) */

void zx_tas3_Credentials_ADD_Assertion(struct zx_tas3_Credentials_s* x, int n, struct zx_sa_Assertion_s* z)
{
  struct zx_sa_Assertion_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Assertion->gg.g;
    x->Assertion = z;
    return;
  case -1:
    y = x->Assertion;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sa_Assertion_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Assertion; n > 1 && y; --n, y = (struct zx_sa_Assertion_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_tas3_Credentials_DEL_Assertion) */

void zx_tas3_Credentials_DEL_Assertion(struct zx_tas3_Credentials_s* x, int n)
{
  struct zx_sa_Assertion_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Assertion = (struct zx_sa_Assertion_s*)x->Assertion->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa_Assertion_s*)x->Assertion;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa_Assertion_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Assertion; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_Assertion_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_tas3_Credentials_NUM_EncryptedAssertion) */

int zx_tas3_Credentials_NUM_EncryptedAssertion(struct zx_tas3_Credentials_s* x)
{
  struct zx_sa_EncryptedAssertion_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->EncryptedAssertion; y; ++n, y = (struct zx_sa_EncryptedAssertion_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_tas3_Credentials_GET_EncryptedAssertion) */

struct zx_sa_EncryptedAssertion_s* zx_tas3_Credentials_GET_EncryptedAssertion(struct zx_tas3_Credentials_s* x, int n)
{
  struct zx_sa_EncryptedAssertion_s* y;
  if (!x) return 0;
  for (y = x->EncryptedAssertion; n>=0 && y; --n, y = (struct zx_sa_EncryptedAssertion_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_tas3_Credentials_POP_EncryptedAssertion) */

struct zx_sa_EncryptedAssertion_s* zx_tas3_Credentials_POP_EncryptedAssertion(struct zx_tas3_Credentials_s* x)
{
  struct zx_sa_EncryptedAssertion_s* y;
  if (!x) return 0;
  y = x->EncryptedAssertion;
  if (y)
    x->EncryptedAssertion = (struct zx_sa_EncryptedAssertion_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_tas3_Credentials_PUSH_EncryptedAssertion) */

void zx_tas3_Credentials_PUSH_EncryptedAssertion(struct zx_tas3_Credentials_s* x, struct zx_sa_EncryptedAssertion_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->EncryptedAssertion->gg.g;
  x->EncryptedAssertion = z;
}

/* FUNC(zx_tas3_Credentials_REV_EncryptedAssertion) */

void zx_tas3_Credentials_REV_EncryptedAssertion(struct zx_tas3_Credentials_s* x)
{
  struct zx_sa_EncryptedAssertion_s* nxt;
  struct zx_sa_EncryptedAssertion_s* y;
  if (!x) return;
  y = x->EncryptedAssertion;
  if (!y) return;
  x->EncryptedAssertion = 0;
  while (y) {
    nxt = (struct zx_sa_EncryptedAssertion_s*)y->gg.g.n;
    y->gg.g.n = &x->EncryptedAssertion->gg.g;
    x->EncryptedAssertion = y;
    y = nxt;
  }
}

/* FUNC(zx_tas3_Credentials_PUT_EncryptedAssertion) */

void zx_tas3_Credentials_PUT_EncryptedAssertion(struct zx_tas3_Credentials_s* x, int n, struct zx_sa_EncryptedAssertion_s* z)
{
  struct zx_sa_EncryptedAssertion_s* y;
  if (!x || !z) return;
  y = x->EncryptedAssertion;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->EncryptedAssertion = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_EncryptedAssertion_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_tas3_Credentials_ADD_EncryptedAssertion) */

void zx_tas3_Credentials_ADD_EncryptedAssertion(struct zx_tas3_Credentials_s* x, int n, struct zx_sa_EncryptedAssertion_s* z)
{
  struct zx_sa_EncryptedAssertion_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->EncryptedAssertion->gg.g;
    x->EncryptedAssertion = z;
    return;
  case -1:
    y = x->EncryptedAssertion;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sa_EncryptedAssertion_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->EncryptedAssertion; n > 1 && y; --n, y = (struct zx_sa_EncryptedAssertion_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_tas3_Credentials_DEL_EncryptedAssertion) */

void zx_tas3_Credentials_DEL_EncryptedAssertion(struct zx_tas3_Credentials_s* x, int n)
{
  struct zx_sa_EncryptedAssertion_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->EncryptedAssertion = (struct zx_sa_EncryptedAssertion_s*)x->EncryptedAssertion->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa_EncryptedAssertion_s*)x->EncryptedAssertion;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa_EncryptedAssertion_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->EncryptedAssertion; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_EncryptedAssertion_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_tas3_Credentials_NUM_sa11_Assertion) */

int zx_tas3_Credentials_NUM_sa11_Assertion(struct zx_tas3_Credentials_s* x)
{
  struct zx_sa11_Assertion_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->sa11_Assertion; y; ++n, y = (struct zx_sa11_Assertion_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_tas3_Credentials_GET_sa11_Assertion) */

struct zx_sa11_Assertion_s* zx_tas3_Credentials_GET_sa11_Assertion(struct zx_tas3_Credentials_s* x, int n)
{
  struct zx_sa11_Assertion_s* y;
  if (!x) return 0;
  for (y = x->sa11_Assertion; n>=0 && y; --n, y = (struct zx_sa11_Assertion_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_tas3_Credentials_POP_sa11_Assertion) */

struct zx_sa11_Assertion_s* zx_tas3_Credentials_POP_sa11_Assertion(struct zx_tas3_Credentials_s* x)
{
  struct zx_sa11_Assertion_s* y;
  if (!x) return 0;
  y = x->sa11_Assertion;
  if (y)
    x->sa11_Assertion = (struct zx_sa11_Assertion_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_tas3_Credentials_PUSH_sa11_Assertion) */

void zx_tas3_Credentials_PUSH_sa11_Assertion(struct zx_tas3_Credentials_s* x, struct zx_sa11_Assertion_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->sa11_Assertion->gg.g;
  x->sa11_Assertion = z;
}

/* FUNC(zx_tas3_Credentials_REV_sa11_Assertion) */

void zx_tas3_Credentials_REV_sa11_Assertion(struct zx_tas3_Credentials_s* x)
{
  struct zx_sa11_Assertion_s* nxt;
  struct zx_sa11_Assertion_s* y;
  if (!x) return;
  y = x->sa11_Assertion;
  if (!y) return;
  x->sa11_Assertion = 0;
  while (y) {
    nxt = (struct zx_sa11_Assertion_s*)y->gg.g.n;
    y->gg.g.n = &x->sa11_Assertion->gg.g;
    x->sa11_Assertion = y;
    y = nxt;
  }
}

/* FUNC(zx_tas3_Credentials_PUT_sa11_Assertion) */

void zx_tas3_Credentials_PUT_sa11_Assertion(struct zx_tas3_Credentials_s* x, int n, struct zx_sa11_Assertion_s* z)
{
  struct zx_sa11_Assertion_s* y;
  if (!x || !z) return;
  y = x->sa11_Assertion;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->sa11_Assertion = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_Assertion_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_tas3_Credentials_ADD_sa11_Assertion) */

void zx_tas3_Credentials_ADD_sa11_Assertion(struct zx_tas3_Credentials_s* x, int n, struct zx_sa11_Assertion_s* z)
{
  struct zx_sa11_Assertion_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->sa11_Assertion->gg.g;
    x->sa11_Assertion = z;
    return;
  case -1:
    y = x->sa11_Assertion;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sa11_Assertion_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->sa11_Assertion; n > 1 && y; --n, y = (struct zx_sa11_Assertion_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_tas3_Credentials_DEL_sa11_Assertion) */

void zx_tas3_Credentials_DEL_sa11_Assertion(struct zx_tas3_Credentials_s* x, int n)
{
  struct zx_sa11_Assertion_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->sa11_Assertion = (struct zx_sa11_Assertion_s*)x->sa11_Assertion->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa11_Assertion_s*)x->sa11_Assertion;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa11_Assertion_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->sa11_Assertion; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_Assertion_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_tas3_Credentials_NUM_ff12_Assertion) */

int zx_tas3_Credentials_NUM_ff12_Assertion(struct zx_tas3_Credentials_s* x)
{
  struct zx_ff12_Assertion_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->ff12_Assertion; y; ++n, y = (struct zx_ff12_Assertion_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_tas3_Credentials_GET_ff12_Assertion) */

struct zx_ff12_Assertion_s* zx_tas3_Credentials_GET_ff12_Assertion(struct zx_tas3_Credentials_s* x, int n)
{
  struct zx_ff12_Assertion_s* y;
  if (!x) return 0;
  for (y = x->ff12_Assertion; n>=0 && y; --n, y = (struct zx_ff12_Assertion_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_tas3_Credentials_POP_ff12_Assertion) */

struct zx_ff12_Assertion_s* zx_tas3_Credentials_POP_ff12_Assertion(struct zx_tas3_Credentials_s* x)
{
  struct zx_ff12_Assertion_s* y;
  if (!x) return 0;
  y = x->ff12_Assertion;
  if (y)
    x->ff12_Assertion = (struct zx_ff12_Assertion_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_tas3_Credentials_PUSH_ff12_Assertion) */

void zx_tas3_Credentials_PUSH_ff12_Assertion(struct zx_tas3_Credentials_s* x, struct zx_ff12_Assertion_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->ff12_Assertion->gg.g;
  x->ff12_Assertion = z;
}

/* FUNC(zx_tas3_Credentials_REV_ff12_Assertion) */

void zx_tas3_Credentials_REV_ff12_Assertion(struct zx_tas3_Credentials_s* x)
{
  struct zx_ff12_Assertion_s* nxt;
  struct zx_ff12_Assertion_s* y;
  if (!x) return;
  y = x->ff12_Assertion;
  if (!y) return;
  x->ff12_Assertion = 0;
  while (y) {
    nxt = (struct zx_ff12_Assertion_s*)y->gg.g.n;
    y->gg.g.n = &x->ff12_Assertion->gg.g;
    x->ff12_Assertion = y;
    y = nxt;
  }
}

/* FUNC(zx_tas3_Credentials_PUT_ff12_Assertion) */

void zx_tas3_Credentials_PUT_ff12_Assertion(struct zx_tas3_Credentials_s* x, int n, struct zx_ff12_Assertion_s* z)
{
  struct zx_ff12_Assertion_s* y;
  if (!x || !z) return;
  y = x->ff12_Assertion;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->ff12_Assertion = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ff12_Assertion_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_tas3_Credentials_ADD_ff12_Assertion) */

void zx_tas3_Credentials_ADD_ff12_Assertion(struct zx_tas3_Credentials_s* x, int n, struct zx_ff12_Assertion_s* z)
{
  struct zx_ff12_Assertion_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->ff12_Assertion->gg.g;
    x->ff12_Assertion = z;
    return;
  case -1:
    y = x->ff12_Assertion;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ff12_Assertion_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ff12_Assertion; n > 1 && y; --n, y = (struct zx_ff12_Assertion_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_tas3_Credentials_DEL_ff12_Assertion) */

void zx_tas3_Credentials_DEL_ff12_Assertion(struct zx_tas3_Credentials_s* x, int n)
{
  struct zx_ff12_Assertion_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->ff12_Assertion = (struct zx_ff12_Assertion_s*)x->ff12_Assertion->gg.g.n;
    return;
  case -1:
    y = (struct zx_ff12_Assertion_s*)x->ff12_Assertion;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ff12_Assertion_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ff12_Assertion; n > 1 && y->gg.g.n; --n, y = (struct zx_ff12_Assertion_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_tas3_Credentials_NUM_Attribute) */

int zx_tas3_Credentials_NUM_Attribute(struct zx_tas3_Credentials_s* x)
{
  struct zx_sa_Attribute_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Attribute; y; ++n, y = (struct zx_sa_Attribute_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_tas3_Credentials_GET_Attribute) */

struct zx_sa_Attribute_s* zx_tas3_Credentials_GET_Attribute(struct zx_tas3_Credentials_s* x, int n)
{
  struct zx_sa_Attribute_s* y;
  if (!x) return 0;
  for (y = x->Attribute; n>=0 && y; --n, y = (struct zx_sa_Attribute_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_tas3_Credentials_POP_Attribute) */

struct zx_sa_Attribute_s* zx_tas3_Credentials_POP_Attribute(struct zx_tas3_Credentials_s* x)
{
  struct zx_sa_Attribute_s* y;
  if (!x) return 0;
  y = x->Attribute;
  if (y)
    x->Attribute = (struct zx_sa_Attribute_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_tas3_Credentials_PUSH_Attribute) */

void zx_tas3_Credentials_PUSH_Attribute(struct zx_tas3_Credentials_s* x, struct zx_sa_Attribute_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Attribute->gg.g;
  x->Attribute = z;
}

/* FUNC(zx_tas3_Credentials_REV_Attribute) */

void zx_tas3_Credentials_REV_Attribute(struct zx_tas3_Credentials_s* x)
{
  struct zx_sa_Attribute_s* nxt;
  struct zx_sa_Attribute_s* y;
  if (!x) return;
  y = x->Attribute;
  if (!y) return;
  x->Attribute = 0;
  while (y) {
    nxt = (struct zx_sa_Attribute_s*)y->gg.g.n;
    y->gg.g.n = &x->Attribute->gg.g;
    x->Attribute = y;
    y = nxt;
  }
}

/* FUNC(zx_tas3_Credentials_PUT_Attribute) */

void zx_tas3_Credentials_PUT_Attribute(struct zx_tas3_Credentials_s* x, int n, struct zx_sa_Attribute_s* z)
{
  struct zx_sa_Attribute_s* y;
  if (!x || !z) return;
  y = x->Attribute;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Attribute = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_Attribute_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_tas3_Credentials_ADD_Attribute) */

void zx_tas3_Credentials_ADD_Attribute(struct zx_tas3_Credentials_s* x, int n, struct zx_sa_Attribute_s* z)
{
  struct zx_sa_Attribute_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Attribute->gg.g;
    x->Attribute = z;
    return;
  case -1:
    y = x->Attribute;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sa_Attribute_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Attribute; n > 1 && y; --n, y = (struct zx_sa_Attribute_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_tas3_Credentials_DEL_Attribute) */

void zx_tas3_Credentials_DEL_Attribute(struct zx_tas3_Credentials_s* x, int n)
{
  struct zx_sa_Attribute_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Attribute = (struct zx_sa_Attribute_s*)x->Attribute->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa_Attribute_s*)x->Attribute;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa_Attribute_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Attribute; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_Attribute_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_tas3_Credentials_NUM_EncryptedAttribute) */

int zx_tas3_Credentials_NUM_EncryptedAttribute(struct zx_tas3_Credentials_s* x)
{
  struct zx_sa_EncryptedAttribute_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->EncryptedAttribute; y; ++n, y = (struct zx_sa_EncryptedAttribute_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_tas3_Credentials_GET_EncryptedAttribute) */

struct zx_sa_EncryptedAttribute_s* zx_tas3_Credentials_GET_EncryptedAttribute(struct zx_tas3_Credentials_s* x, int n)
{
  struct zx_sa_EncryptedAttribute_s* y;
  if (!x) return 0;
  for (y = x->EncryptedAttribute; n>=0 && y; --n, y = (struct zx_sa_EncryptedAttribute_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_tas3_Credentials_POP_EncryptedAttribute) */

struct zx_sa_EncryptedAttribute_s* zx_tas3_Credentials_POP_EncryptedAttribute(struct zx_tas3_Credentials_s* x)
{
  struct zx_sa_EncryptedAttribute_s* y;
  if (!x) return 0;
  y = x->EncryptedAttribute;
  if (y)
    x->EncryptedAttribute = (struct zx_sa_EncryptedAttribute_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_tas3_Credentials_PUSH_EncryptedAttribute) */

void zx_tas3_Credentials_PUSH_EncryptedAttribute(struct zx_tas3_Credentials_s* x, struct zx_sa_EncryptedAttribute_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->EncryptedAttribute->gg.g;
  x->EncryptedAttribute = z;
}

/* FUNC(zx_tas3_Credentials_REV_EncryptedAttribute) */

void zx_tas3_Credentials_REV_EncryptedAttribute(struct zx_tas3_Credentials_s* x)
{
  struct zx_sa_EncryptedAttribute_s* nxt;
  struct zx_sa_EncryptedAttribute_s* y;
  if (!x) return;
  y = x->EncryptedAttribute;
  if (!y) return;
  x->EncryptedAttribute = 0;
  while (y) {
    nxt = (struct zx_sa_EncryptedAttribute_s*)y->gg.g.n;
    y->gg.g.n = &x->EncryptedAttribute->gg.g;
    x->EncryptedAttribute = y;
    y = nxt;
  }
}

/* FUNC(zx_tas3_Credentials_PUT_EncryptedAttribute) */

void zx_tas3_Credentials_PUT_EncryptedAttribute(struct zx_tas3_Credentials_s* x, int n, struct zx_sa_EncryptedAttribute_s* z)
{
  struct zx_sa_EncryptedAttribute_s* y;
  if (!x || !z) return;
  y = x->EncryptedAttribute;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->EncryptedAttribute = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_EncryptedAttribute_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_tas3_Credentials_ADD_EncryptedAttribute) */

void zx_tas3_Credentials_ADD_EncryptedAttribute(struct zx_tas3_Credentials_s* x, int n, struct zx_sa_EncryptedAttribute_s* z)
{
  struct zx_sa_EncryptedAttribute_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->EncryptedAttribute->gg.g;
    x->EncryptedAttribute = z;
    return;
  case -1:
    y = x->EncryptedAttribute;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sa_EncryptedAttribute_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->EncryptedAttribute; n > 1 && y; --n, y = (struct zx_sa_EncryptedAttribute_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_tas3_Credentials_DEL_EncryptedAttribute) */

void zx_tas3_Credentials_DEL_EncryptedAttribute(struct zx_tas3_Credentials_s* x, int n)
{
  struct zx_sa_EncryptedAttribute_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->EncryptedAttribute = (struct zx_sa_EncryptedAttribute_s*)x->EncryptedAttribute->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa_EncryptedAttribute_s*)x->EncryptedAttribute;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa_EncryptedAttribute_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->EncryptedAttribute; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_EncryptedAttribute_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_tas3_Credentials_NUM_xac_Attribute) */

int zx_tas3_Credentials_NUM_xac_Attribute(struct zx_tas3_Credentials_s* x)
{
  struct zx_xac_Attribute_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->xac_Attribute; y; ++n, y = (struct zx_xac_Attribute_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_tas3_Credentials_GET_xac_Attribute) */

struct zx_xac_Attribute_s* zx_tas3_Credentials_GET_xac_Attribute(struct zx_tas3_Credentials_s* x, int n)
{
  struct zx_xac_Attribute_s* y;
  if (!x) return 0;
  for (y = x->xac_Attribute; n>=0 && y; --n, y = (struct zx_xac_Attribute_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_tas3_Credentials_POP_xac_Attribute) */

struct zx_xac_Attribute_s* zx_tas3_Credentials_POP_xac_Attribute(struct zx_tas3_Credentials_s* x)
{
  struct zx_xac_Attribute_s* y;
  if (!x) return 0;
  y = x->xac_Attribute;
  if (y)
    x->xac_Attribute = (struct zx_xac_Attribute_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_tas3_Credentials_PUSH_xac_Attribute) */

void zx_tas3_Credentials_PUSH_xac_Attribute(struct zx_tas3_Credentials_s* x, struct zx_xac_Attribute_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->xac_Attribute->gg.g;
  x->xac_Attribute = z;
}

/* FUNC(zx_tas3_Credentials_REV_xac_Attribute) */

void zx_tas3_Credentials_REV_xac_Attribute(struct zx_tas3_Credentials_s* x)
{
  struct zx_xac_Attribute_s* nxt;
  struct zx_xac_Attribute_s* y;
  if (!x) return;
  y = x->xac_Attribute;
  if (!y) return;
  x->xac_Attribute = 0;
  while (y) {
    nxt = (struct zx_xac_Attribute_s*)y->gg.g.n;
    y->gg.g.n = &x->xac_Attribute->gg.g;
    x->xac_Attribute = y;
    y = nxt;
  }
}

/* FUNC(zx_tas3_Credentials_PUT_xac_Attribute) */

void zx_tas3_Credentials_PUT_xac_Attribute(struct zx_tas3_Credentials_s* x, int n, struct zx_xac_Attribute_s* z)
{
  struct zx_xac_Attribute_s* y;
  if (!x || !z) return;
  y = x->xac_Attribute;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->xac_Attribute = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_xac_Attribute_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_tas3_Credentials_ADD_xac_Attribute) */

void zx_tas3_Credentials_ADD_xac_Attribute(struct zx_tas3_Credentials_s* x, int n, struct zx_xac_Attribute_s* z)
{
  struct zx_xac_Attribute_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->xac_Attribute->gg.g;
    x->xac_Attribute = z;
    return;
  case -1:
    y = x->xac_Attribute;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_xac_Attribute_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->xac_Attribute; n > 1 && y; --n, y = (struct zx_xac_Attribute_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_tas3_Credentials_DEL_xac_Attribute) */

void zx_tas3_Credentials_DEL_xac_Attribute(struct zx_tas3_Credentials_s* x, int n)
{
  struct zx_xac_Attribute_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->xac_Attribute = (struct zx_xac_Attribute_s*)x->xac_Attribute->gg.g.n;
    return;
  case -1:
    y = (struct zx_xac_Attribute_s*)x->xac_Attribute;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_xac_Attribute_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->xac_Attribute; n > 1 && y->gg.g.n; --n, y = (struct zx_xac_Attribute_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_tas3_Credentials_GET_id) */
struct zx_str* zx_tas3_Credentials_GET_id(struct zx_tas3_Credentials_s* x) { return x->id; }
/* FUNC(zx_tas3_Credentials_PUT_id) */
void zx_tas3_Credentials_PUT_id(struct zx_tas3_Credentials_s* x, struct zx_str* y) { x->id = y; }
/* FUNC(zx_tas3_Credentials_GET_usage) */
struct zx_str* zx_tas3_Credentials_GET_usage(struct zx_tas3_Credentials_s* x) { return x->usage; }
/* FUNC(zx_tas3_Credentials_PUT_usage) */
void zx_tas3_Credentials_PUT_usage(struct zx_tas3_Credentials_s* x, struct zx_str* y) { x->usage = y; }
/* FUNC(zx_tas3_Credentials_GET_Id) */
struct zx_str* zx_tas3_Credentials_GET_Id(struct zx_tas3_Credentials_s* x) { return x->Id; }
/* FUNC(zx_tas3_Credentials_PUT_Id) */
void zx_tas3_Credentials_PUT_Id(struct zx_tas3_Credentials_s* x, struct zx_str* y) { x->Id = y; }
/* FUNC(zx_tas3_Credentials_GET_actor) */
struct zx_str* zx_tas3_Credentials_GET_actor(struct zx_tas3_Credentials_s* x) { return x->actor; }
/* FUNC(zx_tas3_Credentials_PUT_actor) */
void zx_tas3_Credentials_PUT_actor(struct zx_tas3_Credentials_s* x, struct zx_str* y) { x->actor = y; }
/* FUNC(zx_tas3_Credentials_GET_mustUnderstand) */
struct zx_str* zx_tas3_Credentials_GET_mustUnderstand(struct zx_tas3_Credentials_s* x) { return x->mustUnderstand; }
/* FUNC(zx_tas3_Credentials_PUT_mustUnderstand) */
void zx_tas3_Credentials_PUT_mustUnderstand(struct zx_tas3_Credentials_s* x, struct zx_str* y) { x->mustUnderstand = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_tas3_ESLApply_NUM_ESLRef) */

int zx_tas3_ESLApply_NUM_ESLRef(struct zx_tas3_ESLApply_s* x)
{
  struct zx_tas3_ESLRef_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->ESLRef; y; ++n, y = (struct zx_tas3_ESLRef_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_tas3_ESLApply_GET_ESLRef) */

struct zx_tas3_ESLRef_s* zx_tas3_ESLApply_GET_ESLRef(struct zx_tas3_ESLApply_s* x, int n)
{
  struct zx_tas3_ESLRef_s* y;
  if (!x) return 0;
  for (y = x->ESLRef; n>=0 && y; --n, y = (struct zx_tas3_ESLRef_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_tas3_ESLApply_POP_ESLRef) */

struct zx_tas3_ESLRef_s* zx_tas3_ESLApply_POP_ESLRef(struct zx_tas3_ESLApply_s* x)
{
  struct zx_tas3_ESLRef_s* y;
  if (!x) return 0;
  y = x->ESLRef;
  if (y)
    x->ESLRef = (struct zx_tas3_ESLRef_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_tas3_ESLApply_PUSH_ESLRef) */

void zx_tas3_ESLApply_PUSH_ESLRef(struct zx_tas3_ESLApply_s* x, struct zx_tas3_ESLRef_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->ESLRef->gg.g;
  x->ESLRef = z;
}

/* FUNC(zx_tas3_ESLApply_REV_ESLRef) */

void zx_tas3_ESLApply_REV_ESLRef(struct zx_tas3_ESLApply_s* x)
{
  struct zx_tas3_ESLRef_s* nxt;
  struct zx_tas3_ESLRef_s* y;
  if (!x) return;
  y = x->ESLRef;
  if (!y) return;
  x->ESLRef = 0;
  while (y) {
    nxt = (struct zx_tas3_ESLRef_s*)y->gg.g.n;
    y->gg.g.n = &x->ESLRef->gg.g;
    x->ESLRef = y;
    y = nxt;
  }
}

/* FUNC(zx_tas3_ESLApply_PUT_ESLRef) */

void zx_tas3_ESLApply_PUT_ESLRef(struct zx_tas3_ESLApply_s* x, int n, struct zx_tas3_ESLRef_s* z)
{
  struct zx_tas3_ESLRef_s* y;
  if (!x || !z) return;
  y = x->ESLRef;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->ESLRef = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_tas3_ESLRef_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_tas3_ESLApply_ADD_ESLRef) */

void zx_tas3_ESLApply_ADD_ESLRef(struct zx_tas3_ESLApply_s* x, int n, struct zx_tas3_ESLRef_s* z)
{
  struct zx_tas3_ESLRef_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->ESLRef->gg.g;
    x->ESLRef = z;
    return;
  case -1:
    y = x->ESLRef;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_tas3_ESLRef_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ESLRef; n > 1 && y; --n, y = (struct zx_tas3_ESLRef_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_tas3_ESLApply_DEL_ESLRef) */

void zx_tas3_ESLApply_DEL_ESLRef(struct zx_tas3_ESLApply_s* x, int n)
{
  struct zx_tas3_ESLRef_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->ESLRef = (struct zx_tas3_ESLRef_s*)x->ESLRef->gg.g.n;
    return;
  case -1:
    y = (struct zx_tas3_ESLRef_s*)x->ESLRef;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_tas3_ESLRef_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ESLRef; n > 1 && y->gg.g.n; --n, y = (struct zx_tas3_ESLRef_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_tas3_ESLApply_NUM_Obligation) */

int zx_tas3_ESLApply_NUM_Obligation(struct zx_tas3_ESLApply_s* x)
{
  struct zx_xa_Obligation_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Obligation; y; ++n, y = (struct zx_xa_Obligation_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_tas3_ESLApply_GET_Obligation) */

struct zx_xa_Obligation_s* zx_tas3_ESLApply_GET_Obligation(struct zx_tas3_ESLApply_s* x, int n)
{
  struct zx_xa_Obligation_s* y;
  if (!x) return 0;
  for (y = x->Obligation; n>=0 && y; --n, y = (struct zx_xa_Obligation_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_tas3_ESLApply_POP_Obligation) */

struct zx_xa_Obligation_s* zx_tas3_ESLApply_POP_Obligation(struct zx_tas3_ESLApply_s* x)
{
  struct zx_xa_Obligation_s* y;
  if (!x) return 0;
  y = x->Obligation;
  if (y)
    x->Obligation = (struct zx_xa_Obligation_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_tas3_ESLApply_PUSH_Obligation) */

void zx_tas3_ESLApply_PUSH_Obligation(struct zx_tas3_ESLApply_s* x, struct zx_xa_Obligation_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Obligation->gg.g;
  x->Obligation = z;
}

/* FUNC(zx_tas3_ESLApply_REV_Obligation) */

void zx_tas3_ESLApply_REV_Obligation(struct zx_tas3_ESLApply_s* x)
{
  struct zx_xa_Obligation_s* nxt;
  struct zx_xa_Obligation_s* y;
  if (!x) return;
  y = x->Obligation;
  if (!y) return;
  x->Obligation = 0;
  while (y) {
    nxt = (struct zx_xa_Obligation_s*)y->gg.g.n;
    y->gg.g.n = &x->Obligation->gg.g;
    x->Obligation = y;
    y = nxt;
  }
}

/* FUNC(zx_tas3_ESLApply_PUT_Obligation) */

void zx_tas3_ESLApply_PUT_Obligation(struct zx_tas3_ESLApply_s* x, int n, struct zx_xa_Obligation_s* z)
{
  struct zx_xa_Obligation_s* y;
  if (!x || !z) return;
  y = x->Obligation;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Obligation = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_xa_Obligation_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_tas3_ESLApply_ADD_Obligation) */

void zx_tas3_ESLApply_ADD_Obligation(struct zx_tas3_ESLApply_s* x, int n, struct zx_xa_Obligation_s* z)
{
  struct zx_xa_Obligation_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Obligation->gg.g;
    x->Obligation = z;
    return;
  case -1:
    y = x->Obligation;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_xa_Obligation_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Obligation; n > 1 && y; --n, y = (struct zx_xa_Obligation_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_tas3_ESLApply_DEL_Obligation) */

void zx_tas3_ESLApply_DEL_Obligation(struct zx_tas3_ESLApply_s* x, int n)
{
  struct zx_xa_Obligation_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Obligation = (struct zx_xa_Obligation_s*)x->Obligation->gg.g.n;
    return;
  case -1:
    y = (struct zx_xa_Obligation_s*)x->Obligation;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_xa_Obligation_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Obligation; n > 1 && y->gg.g.n; --n, y = (struct zx_xa_Obligation_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_tas3_ESLPolicies_NUM_ESLApply) */

int zx_tas3_ESLPolicies_NUM_ESLApply(struct zx_tas3_ESLPolicies_s* x)
{
  struct zx_tas3_ESLApply_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->ESLApply; y; ++n, y = (struct zx_tas3_ESLApply_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_tas3_ESLPolicies_GET_ESLApply) */

struct zx_tas3_ESLApply_s* zx_tas3_ESLPolicies_GET_ESLApply(struct zx_tas3_ESLPolicies_s* x, int n)
{
  struct zx_tas3_ESLApply_s* y;
  if (!x) return 0;
  for (y = x->ESLApply; n>=0 && y; --n, y = (struct zx_tas3_ESLApply_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_tas3_ESLPolicies_POP_ESLApply) */

struct zx_tas3_ESLApply_s* zx_tas3_ESLPolicies_POP_ESLApply(struct zx_tas3_ESLPolicies_s* x)
{
  struct zx_tas3_ESLApply_s* y;
  if (!x) return 0;
  y = x->ESLApply;
  if (y)
    x->ESLApply = (struct zx_tas3_ESLApply_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_tas3_ESLPolicies_PUSH_ESLApply) */

void zx_tas3_ESLPolicies_PUSH_ESLApply(struct zx_tas3_ESLPolicies_s* x, struct zx_tas3_ESLApply_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->ESLApply->gg.g;
  x->ESLApply = z;
}

/* FUNC(zx_tas3_ESLPolicies_REV_ESLApply) */

void zx_tas3_ESLPolicies_REV_ESLApply(struct zx_tas3_ESLPolicies_s* x)
{
  struct zx_tas3_ESLApply_s* nxt;
  struct zx_tas3_ESLApply_s* y;
  if (!x) return;
  y = x->ESLApply;
  if (!y) return;
  x->ESLApply = 0;
  while (y) {
    nxt = (struct zx_tas3_ESLApply_s*)y->gg.g.n;
    y->gg.g.n = &x->ESLApply->gg.g;
    x->ESLApply = y;
    y = nxt;
  }
}

/* FUNC(zx_tas3_ESLPolicies_PUT_ESLApply) */

void zx_tas3_ESLPolicies_PUT_ESLApply(struct zx_tas3_ESLPolicies_s* x, int n, struct zx_tas3_ESLApply_s* z)
{
  struct zx_tas3_ESLApply_s* y;
  if (!x || !z) return;
  y = x->ESLApply;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->ESLApply = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_tas3_ESLApply_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_tas3_ESLPolicies_ADD_ESLApply) */

void zx_tas3_ESLPolicies_ADD_ESLApply(struct zx_tas3_ESLPolicies_s* x, int n, struct zx_tas3_ESLApply_s* z)
{
  struct zx_tas3_ESLApply_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->ESLApply->gg.g;
    x->ESLApply = z;
    return;
  case -1:
    y = x->ESLApply;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_tas3_ESLApply_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ESLApply; n > 1 && y; --n, y = (struct zx_tas3_ESLApply_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_tas3_ESLPolicies_DEL_ESLApply) */

void zx_tas3_ESLPolicies_DEL_ESLApply(struct zx_tas3_ESLPolicies_s* x, int n)
{
  struct zx_tas3_ESLApply_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->ESLApply = (struct zx_tas3_ESLApply_s*)x->ESLApply->gg.g.n;
    return;
  case -1:
    y = (struct zx_tas3_ESLApply_s*)x->ESLApply;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_tas3_ESLApply_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ESLApply; n > 1 && y->gg.g.n; --n, y = (struct zx_tas3_ESLApply_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_tas3_ESLPolicies_GET_id) */
struct zx_str* zx_tas3_ESLPolicies_GET_id(struct zx_tas3_ESLPolicies_s* x) { return x->id; }
/* FUNC(zx_tas3_ESLPolicies_PUT_id) */
void zx_tas3_ESLPolicies_PUT_id(struct zx_tas3_ESLPolicies_s* x, struct zx_str* y) { x->id = y; }
/* FUNC(zx_tas3_ESLPolicies_GET_usage) */
struct zx_str* zx_tas3_ESLPolicies_GET_usage(struct zx_tas3_ESLPolicies_s* x) { return x->usage; }
/* FUNC(zx_tas3_ESLPolicies_PUT_usage) */
void zx_tas3_ESLPolicies_PUT_usage(struct zx_tas3_ESLPolicies_s* x, struct zx_str* y) { x->usage = y; }
/* FUNC(zx_tas3_ESLPolicies_GET_Id) */
struct zx_str* zx_tas3_ESLPolicies_GET_Id(struct zx_tas3_ESLPolicies_s* x) { return x->Id; }
/* FUNC(zx_tas3_ESLPolicies_PUT_Id) */
void zx_tas3_ESLPolicies_PUT_Id(struct zx_tas3_ESLPolicies_s* x, struct zx_str* y) { x->Id = y; }
/* FUNC(zx_tas3_ESLPolicies_GET_actor) */
struct zx_str* zx_tas3_ESLPolicies_GET_actor(struct zx_tas3_ESLPolicies_s* x) { return x->actor; }
/* FUNC(zx_tas3_ESLPolicies_PUT_actor) */
void zx_tas3_ESLPolicies_PUT_actor(struct zx_tas3_ESLPolicies_s* x, struct zx_str* y) { x->actor = y; }
/* FUNC(zx_tas3_ESLPolicies_GET_mustUnderstand) */
struct zx_str* zx_tas3_ESLPolicies_GET_mustUnderstand(struct zx_tas3_ESLPolicies_s* x) { return x->mustUnderstand; }
/* FUNC(zx_tas3_ESLPolicies_PUT_mustUnderstand) */
void zx_tas3_ESLPolicies_PUT_mustUnderstand(struct zx_tas3_ESLPolicies_s* x, struct zx_str* y) { x->mustUnderstand = y; }





/* FUNC(zx_tas3_ESLRef_GET_ref) */
struct zx_str* zx_tas3_ESLRef_GET_ref(struct zx_tas3_ESLRef_s* x) { return x->ref; }
/* FUNC(zx_tas3_ESLRef_PUT_ref) */
void zx_tas3_ESLRef_PUT_ref(struct zx_tas3_ESLRef_s* x, struct zx_str* y) { x->ref = y; }
/* FUNC(zx_tas3_ESLRef_GET_xpath) */
struct zx_str* zx_tas3_ESLRef_GET_xpath(struct zx_tas3_ESLRef_s* x) { return x->xpath; }
/* FUNC(zx_tas3_ESLRef_PUT_xpath) */
void zx_tas3_ESLRef_PUT_xpath(struct zx_tas3_ESLRef_s* x, struct zx_str* y) { x->xpath = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_tas3_Status_NUM_Status) */

int zx_tas3_Status_NUM_Status(struct zx_tas3_Status_s* x)
{
  struct zx_lu_Status_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Status; y; ++n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_tas3_Status_GET_Status) */

struct zx_lu_Status_s* zx_tas3_Status_GET_Status(struct zx_tas3_Status_s* x, int n)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  for (y = x->Status; n>=0 && y; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_tas3_Status_POP_Status) */

struct zx_lu_Status_s* zx_tas3_Status_POP_Status(struct zx_tas3_Status_s* x)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  y = x->Status;
  if (y)
    x->Status = (struct zx_lu_Status_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_tas3_Status_PUSH_Status) */

void zx_tas3_Status_PUSH_Status(struct zx_tas3_Status_s* x, struct zx_lu_Status_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Status->gg.g;
  x->Status = z;
}

/* FUNC(zx_tas3_Status_REV_Status) */

void zx_tas3_Status_REV_Status(struct zx_tas3_Status_s* x)
{
  struct zx_lu_Status_s* nxt;
  struct zx_lu_Status_s* y;
  if (!x) return;
  y = x->Status;
  if (!y) return;
  x->Status = 0;
  while (y) {
    nxt = (struct zx_lu_Status_s*)y->gg.g.n;
    y->gg.g.n = &x->Status->gg.g;
    x->Status = y;
    y = nxt;
  }
}

/* FUNC(zx_tas3_Status_PUT_Status) */

void zx_tas3_Status_PUT_Status(struct zx_tas3_Status_s* x, int n, struct zx_lu_Status_s* z)
{
  struct zx_lu_Status_s* y;
  if (!x || !z) return;
  y = x->Status;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Status = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_tas3_Status_ADD_Status) */

void zx_tas3_Status_ADD_Status(struct zx_tas3_Status_s* x, int n, struct zx_lu_Status_s* z)
{
  struct zx_lu_Status_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Status->gg.g;
    x->Status = z;
    return;
  case -1:
    y = x->Status;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_lu_Status_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Status; n > 1 && y; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_tas3_Status_DEL_Status) */

void zx_tas3_Status_DEL_Status(struct zx_tas3_Status_s* x, int n)
{
  struct zx_lu_Status_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Status = (struct zx_lu_Status_s*)x->Status->gg.g.n;
    return;
  case -1:
    y = (struct zx_lu_Status_s*)x->Status;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_lu_Status_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Status; n > 1 && y->gg.g.n; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_tas3_Status_GET_code) */
struct zx_str* zx_tas3_Status_GET_code(struct zx_tas3_Status_s* x) { return x->code; }
/* FUNC(zx_tas3_Status_PUT_code) */
void zx_tas3_Status_PUT_code(struct zx_tas3_Status_s* x, struct zx_str* y) { x->code = y; }
/* FUNC(zx_tas3_Status_GET_comment) */
struct zx_str* zx_tas3_Status_GET_comment(struct zx_tas3_Status_s* x) { return x->comment; }
/* FUNC(zx_tas3_Status_PUT_comment) */
void zx_tas3_Status_PUT_comment(struct zx_tas3_Status_s* x, struct zx_str* y) { x->comment = y; }
/* FUNC(zx_tas3_Status_GET_ctlpt) */
struct zx_str* zx_tas3_Status_GET_ctlpt(struct zx_tas3_Status_s* x) { return x->ctlpt; }
/* FUNC(zx_tas3_Status_PUT_ctlpt) */
void zx_tas3_Status_PUT_ctlpt(struct zx_tas3_Status_s* x, struct zx_str* y) { x->ctlpt = y; }
/* FUNC(zx_tas3_Status_GET_id) */
struct zx_str* zx_tas3_Status_GET_id(struct zx_tas3_Status_s* x) { return x->id; }
/* FUNC(zx_tas3_Status_PUT_id) */
void zx_tas3_Status_PUT_id(struct zx_tas3_Status_s* x, struct zx_str* y) { x->id = y; }
/* FUNC(zx_tas3_Status_GET_ref) */
struct zx_str* zx_tas3_Status_GET_ref(struct zx_tas3_Status_s* x) { return x->ref; }
/* FUNC(zx_tas3_Status_PUT_ref) */
void zx_tas3_Status_PUT_ref(struct zx_tas3_Status_s* x, struct zx_str* y) { x->ref = y; }
/* FUNC(zx_tas3_Status_GET_Id) */
struct zx_str* zx_tas3_Status_GET_Id(struct zx_tas3_Status_s* x) { return x->Id; }
/* FUNC(zx_tas3_Status_PUT_Id) */
void zx_tas3_Status_PUT_Id(struct zx_tas3_Status_s* x, struct zx_str* y) { x->Id = y; }
/* FUNC(zx_tas3_Status_GET_actor) */
struct zx_str* zx_tas3_Status_GET_actor(struct zx_tas3_Status_s* x) { return x->actor; }
/* FUNC(zx_tas3_Status_PUT_actor) */
void zx_tas3_Status_PUT_actor(struct zx_tas3_Status_s* x, struct zx_str* y) { x->actor = y; }
/* FUNC(zx_tas3_Status_GET_mustUnderstand) */
struct zx_str* zx_tas3_Status_GET_mustUnderstand(struct zx_tas3_Status_s* x) { return x->mustUnderstand; }
/* FUNC(zx_tas3_Status_PUT_mustUnderstand) */
void zx_tas3_Status_PUT_mustUnderstand(struct zx_tas3_Status_s* x, struct zx_str* y) { x->mustUnderstand = y; }





/* EOF -- c/zx-tas3-getput.c */