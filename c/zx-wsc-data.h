/* c/zx-wsc-data.h - WARNING: This header was auto generated by xsd2sg.pl. DO NOT EDIT!
 * $Id$ */
/* Datastructure design, topography, and layout
 * Copyright (c) 2006,2010 Sampo Kellomaki (sampo@iki.fi),
 * All Rights Reserved. NO WARRANTY. See file COPYING for
 * terms and conditions of use. Element and attributes names as well
 * as some topography are derived from schema descriptions that were used as
 * input and may be subject to their own copright. */

#ifndef _c_zx_wsc_data_h
#define _c_zx_wsc_data_h

#include "zx.h"
#include "c/zx-const.h"
#include "c/zx-data.h"

#ifndef ZX_ELEM_EXT
#define ZX_ELEM_EXT  /* This extension point should be defined by who includes this file. */
#endif

/* -------------------------- wsc_DerivedKeyToken -------------------------- */
/* refby( ) */
#ifndef zx_wsc_DerivedKeyToken_EXT
#define zx_wsc_DerivedKeyToken_EXT
#endif

struct zx_wsc_DerivedKeyToken_s {
  ZX_ELEM_EXT
  zx_wsc_DerivedKeyToken_EXT
  struct zx_wsse_SecurityTokenReference_s* SecurityTokenReference;	/* {0,1} nada */
  struct zx_wsc_Properties_s* Properties;	/* {0,1}  */
  struct zx_elem_s* Generation;	/* {0,1} xs:unsignedLong */
  struct zx_elem_s* Offset;	/* {0,1} xs:unsignedLong */
  struct zx_elem_s* Length;	/* {0,1} xs:unsignedLong */
  struct zx_elem_s* Label;	/* {0,1} xs:string */
  struct zx_elem_s* Nonce;	/* {0,1} xs:base64Binary */
  struct zx_attr_s* Algorithm;	/* {0,1} attribute xs:anyURI */
  struct zx_attr_s* Id;	/* {0,1} attribute xs:ID */
};

int zx_DEC_ATTR_wsc_DerivedKeyToken(struct zx_ctx* c, struct zx_wsc_DerivedKeyToken_s* x);
int zx_DEC_ELEM_wsc_DerivedKeyToken(struct zx_ctx* c, struct zx_wsc_DerivedKeyToken_s* x);
struct zx_wsc_DerivedKeyToken_s* zx_NEW_wsc_DerivedKeyToken(struct zx_ctx* c, struct zx_elem_s* father);
int zx_LEN_SO_wsc_DerivedKeyToken(struct zx_ctx* c, struct zx_wsc_DerivedKeyToken_s* x);
char* zx_ENC_SO_wsc_DerivedKeyToken(struct zx_ctx* c, struct zx_wsc_DerivedKeyToken_s* x, char* p);
struct zx_str* zx_EASY_ENC_SO_wsc_DerivedKeyToken(struct zx_ctx* c, struct zx_wsc_DerivedKeyToken_s* x);

#ifdef ZX_ENA_AUX
struct zx_wsc_DerivedKeyToken_s* zx_DEEP_CLONE_wsc_DerivedKeyToken(struct zx_ctx* c, struct zx_wsc_DerivedKeyToken_s* x, int dup_strs);
void zx_DUP_STRS_wsc_DerivedKeyToken(struct zx_ctx* c, struct zx_wsc_DerivedKeyToken_s* x);
int zx_WALK_SO_wsc_DerivedKeyToken(struct zx_ctx* c, struct zx_wsc_DerivedKeyToken_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx));
int zx_WALK_WO_wsc_DerivedKeyToken(struct zx_ctx* c, struct zx_wsc_DerivedKeyToken_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx));
#endif

#ifdef ZX_ENA_GETPUT
struct zx_attr_s* zx_wsc_DerivedKeyToken_GET_Algorithm(struct zx_wsc_DerivedKeyToken_s* x);
struct zx_attr_s* zx_wsc_DerivedKeyToken_GET_Id(struct zx_wsc_DerivedKeyToken_s* x);

struct zx_wsse_SecurityTokenReference_s* zx_wsc_DerivedKeyToken_GET_SecurityTokenReference(struct zx_wsc_DerivedKeyToken_s* x, int n);
struct zx_wsc_Properties_s* zx_wsc_DerivedKeyToken_GET_Properties(struct zx_wsc_DerivedKeyToken_s* x, int n);
struct zx_elem_s* zx_wsc_DerivedKeyToken_GET_Generation(struct zx_wsc_DerivedKeyToken_s* x, int n);
struct zx_elem_s* zx_wsc_DerivedKeyToken_GET_Offset(struct zx_wsc_DerivedKeyToken_s* x, int n);
struct zx_elem_s* zx_wsc_DerivedKeyToken_GET_Length(struct zx_wsc_DerivedKeyToken_s* x, int n);
struct zx_elem_s* zx_wsc_DerivedKeyToken_GET_Label(struct zx_wsc_DerivedKeyToken_s* x, int n);
struct zx_elem_s* zx_wsc_DerivedKeyToken_GET_Nonce(struct zx_wsc_DerivedKeyToken_s* x, int n);

int zx_wsc_DerivedKeyToken_NUM_SecurityTokenReference(struct zx_wsc_DerivedKeyToken_s* x);
int zx_wsc_DerivedKeyToken_NUM_Properties(struct zx_wsc_DerivedKeyToken_s* x);
int zx_wsc_DerivedKeyToken_NUM_Generation(struct zx_wsc_DerivedKeyToken_s* x);
int zx_wsc_DerivedKeyToken_NUM_Offset(struct zx_wsc_DerivedKeyToken_s* x);
int zx_wsc_DerivedKeyToken_NUM_Length(struct zx_wsc_DerivedKeyToken_s* x);
int zx_wsc_DerivedKeyToken_NUM_Label(struct zx_wsc_DerivedKeyToken_s* x);
int zx_wsc_DerivedKeyToken_NUM_Nonce(struct zx_wsc_DerivedKeyToken_s* x);

struct zx_wsse_SecurityTokenReference_s* zx_wsc_DerivedKeyToken_POP_SecurityTokenReference(struct zx_wsc_DerivedKeyToken_s* x);
struct zx_wsc_Properties_s* zx_wsc_DerivedKeyToken_POP_Properties(struct zx_wsc_DerivedKeyToken_s* x);
struct zx_elem_s* zx_wsc_DerivedKeyToken_POP_Generation(struct zx_wsc_DerivedKeyToken_s* x);
struct zx_elem_s* zx_wsc_DerivedKeyToken_POP_Offset(struct zx_wsc_DerivedKeyToken_s* x);
struct zx_elem_s* zx_wsc_DerivedKeyToken_POP_Length(struct zx_wsc_DerivedKeyToken_s* x);
struct zx_elem_s* zx_wsc_DerivedKeyToken_POP_Label(struct zx_wsc_DerivedKeyToken_s* x);
struct zx_elem_s* zx_wsc_DerivedKeyToken_POP_Nonce(struct zx_wsc_DerivedKeyToken_s* x);

void zx_wsc_DerivedKeyToken_PUSH_SecurityTokenReference(struct zx_wsc_DerivedKeyToken_s* x, struct zx_wsse_SecurityTokenReference_s* y);
void zx_wsc_DerivedKeyToken_PUSH_Properties(struct zx_wsc_DerivedKeyToken_s* x, struct zx_wsc_Properties_s* y);
void zx_wsc_DerivedKeyToken_PUSH_Generation(struct zx_wsc_DerivedKeyToken_s* x, struct zx_elem_s* y);
void zx_wsc_DerivedKeyToken_PUSH_Offset(struct zx_wsc_DerivedKeyToken_s* x, struct zx_elem_s* y);
void zx_wsc_DerivedKeyToken_PUSH_Length(struct zx_wsc_DerivedKeyToken_s* x, struct zx_elem_s* y);
void zx_wsc_DerivedKeyToken_PUSH_Label(struct zx_wsc_DerivedKeyToken_s* x, struct zx_elem_s* y);
void zx_wsc_DerivedKeyToken_PUSH_Nonce(struct zx_wsc_DerivedKeyToken_s* x, struct zx_elem_s* y);

void zx_wsc_DerivedKeyToken_PUT_Algorithm(struct zx_wsc_DerivedKeyToken_s* x, struct zx_attr_s* y);
void zx_wsc_DerivedKeyToken_PUT_Id(struct zx_wsc_DerivedKeyToken_s* x, struct zx_attr_s* y);

void zx_wsc_DerivedKeyToken_PUT_SecurityTokenReference(struct zx_wsc_DerivedKeyToken_s* x, int n, struct zx_wsse_SecurityTokenReference_s* y);
void zx_wsc_DerivedKeyToken_PUT_Properties(struct zx_wsc_DerivedKeyToken_s* x, int n, struct zx_wsc_Properties_s* y);
void zx_wsc_DerivedKeyToken_PUT_Generation(struct zx_wsc_DerivedKeyToken_s* x, int n, struct zx_elem_s* y);
void zx_wsc_DerivedKeyToken_PUT_Offset(struct zx_wsc_DerivedKeyToken_s* x, int n, struct zx_elem_s* y);
void zx_wsc_DerivedKeyToken_PUT_Length(struct zx_wsc_DerivedKeyToken_s* x, int n, struct zx_elem_s* y);
void zx_wsc_DerivedKeyToken_PUT_Label(struct zx_wsc_DerivedKeyToken_s* x, int n, struct zx_elem_s* y);
void zx_wsc_DerivedKeyToken_PUT_Nonce(struct zx_wsc_DerivedKeyToken_s* x, int n, struct zx_elem_s* y);

void zx_wsc_DerivedKeyToken_ADD_SecurityTokenReference(struct zx_wsc_DerivedKeyToken_s* x, int n, struct zx_wsse_SecurityTokenReference_s* z);
void zx_wsc_DerivedKeyToken_ADD_Properties(struct zx_wsc_DerivedKeyToken_s* x, int n, struct zx_wsc_Properties_s* z);
void zx_wsc_DerivedKeyToken_ADD_Generation(struct zx_wsc_DerivedKeyToken_s* x, int n, struct zx_elem_s* z);
void zx_wsc_DerivedKeyToken_ADD_Offset(struct zx_wsc_DerivedKeyToken_s* x, int n, struct zx_elem_s* z);
void zx_wsc_DerivedKeyToken_ADD_Length(struct zx_wsc_DerivedKeyToken_s* x, int n, struct zx_elem_s* z);
void zx_wsc_DerivedKeyToken_ADD_Label(struct zx_wsc_DerivedKeyToken_s* x, int n, struct zx_elem_s* z);
void zx_wsc_DerivedKeyToken_ADD_Nonce(struct zx_wsc_DerivedKeyToken_s* x, int n, struct zx_elem_s* z);

void zx_wsc_DerivedKeyToken_DEL_SecurityTokenReference(struct zx_wsc_DerivedKeyToken_s* x, int n);
void zx_wsc_DerivedKeyToken_DEL_Properties(struct zx_wsc_DerivedKeyToken_s* x, int n);
void zx_wsc_DerivedKeyToken_DEL_Generation(struct zx_wsc_DerivedKeyToken_s* x, int n);
void zx_wsc_DerivedKeyToken_DEL_Offset(struct zx_wsc_DerivedKeyToken_s* x, int n);
void zx_wsc_DerivedKeyToken_DEL_Length(struct zx_wsc_DerivedKeyToken_s* x, int n);
void zx_wsc_DerivedKeyToken_DEL_Label(struct zx_wsc_DerivedKeyToken_s* x, int n);
void zx_wsc_DerivedKeyToken_DEL_Nonce(struct zx_wsc_DerivedKeyToken_s* x, int n);

void zx_wsc_DerivedKeyToken_REV_SecurityTokenReference(struct zx_wsc_DerivedKeyToken_s* x);
void zx_wsc_DerivedKeyToken_REV_Properties(struct zx_wsc_DerivedKeyToken_s* x);
void zx_wsc_DerivedKeyToken_REV_Generation(struct zx_wsc_DerivedKeyToken_s* x);
void zx_wsc_DerivedKeyToken_REV_Offset(struct zx_wsc_DerivedKeyToken_s* x);
void zx_wsc_DerivedKeyToken_REV_Length(struct zx_wsc_DerivedKeyToken_s* x);
void zx_wsc_DerivedKeyToken_REV_Label(struct zx_wsc_DerivedKeyToken_s* x);
void zx_wsc_DerivedKeyToken_REV_Nonce(struct zx_wsc_DerivedKeyToken_s* x);

#endif
/* -------------------------- wsc_Properties -------------------------- */
/* refby( zx_wsc_DerivedKeyToken_s ) */
#ifndef zx_wsc_Properties_EXT
#define zx_wsc_Properties_EXT
#endif

struct zx_wsc_Properties_s {
  ZX_ELEM_EXT
  zx_wsc_Properties_EXT
};

int zx_DEC_ATTR_wsc_Properties(struct zx_ctx* c, struct zx_wsc_Properties_s* x);
int zx_DEC_ELEM_wsc_Properties(struct zx_ctx* c, struct zx_wsc_Properties_s* x);
struct zx_wsc_Properties_s* zx_NEW_wsc_Properties(struct zx_ctx* c, struct zx_elem_s* father);
int zx_LEN_SO_wsc_Properties(struct zx_ctx* c, struct zx_wsc_Properties_s* x);
char* zx_ENC_SO_wsc_Properties(struct zx_ctx* c, struct zx_wsc_Properties_s* x, char* p);
struct zx_str* zx_EASY_ENC_SO_wsc_Properties(struct zx_ctx* c, struct zx_wsc_Properties_s* x);

#ifdef ZX_ENA_AUX
struct zx_wsc_Properties_s* zx_DEEP_CLONE_wsc_Properties(struct zx_ctx* c, struct zx_wsc_Properties_s* x, int dup_strs);
void zx_DUP_STRS_wsc_Properties(struct zx_ctx* c, struct zx_wsc_Properties_s* x);
int zx_WALK_SO_wsc_Properties(struct zx_ctx* c, struct zx_wsc_Properties_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx));
int zx_WALK_WO_wsc_Properties(struct zx_ctx* c, struct zx_wsc_Properties_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx));
#endif

#ifdef ZX_ENA_GETPUT










#endif
/* -------------------------- wsc_SecurityContextToken -------------------------- */
/* refby( ) */
#ifndef zx_wsc_SecurityContextToken_EXT
#define zx_wsc_SecurityContextToken_EXT
#endif

struct zx_wsc_SecurityContextToken_s {
  ZX_ELEM_EXT
  zx_wsc_SecurityContextToken_EXT
  struct zx_attr_s* Id;	/* {0,1} attribute xs:ID */
};

int zx_DEC_ATTR_wsc_SecurityContextToken(struct zx_ctx* c, struct zx_wsc_SecurityContextToken_s* x);
int zx_DEC_ELEM_wsc_SecurityContextToken(struct zx_ctx* c, struct zx_wsc_SecurityContextToken_s* x);
struct zx_wsc_SecurityContextToken_s* zx_NEW_wsc_SecurityContextToken(struct zx_ctx* c, struct zx_elem_s* father);
int zx_LEN_SO_wsc_SecurityContextToken(struct zx_ctx* c, struct zx_wsc_SecurityContextToken_s* x);
char* zx_ENC_SO_wsc_SecurityContextToken(struct zx_ctx* c, struct zx_wsc_SecurityContextToken_s* x, char* p);
struct zx_str* zx_EASY_ENC_SO_wsc_SecurityContextToken(struct zx_ctx* c, struct zx_wsc_SecurityContextToken_s* x);

#ifdef ZX_ENA_AUX
struct zx_wsc_SecurityContextToken_s* zx_DEEP_CLONE_wsc_SecurityContextToken(struct zx_ctx* c, struct zx_wsc_SecurityContextToken_s* x, int dup_strs);
void zx_DUP_STRS_wsc_SecurityContextToken(struct zx_ctx* c, struct zx_wsc_SecurityContextToken_s* x);
int zx_WALK_SO_wsc_SecurityContextToken(struct zx_ctx* c, struct zx_wsc_SecurityContextToken_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx));
int zx_WALK_WO_wsc_SecurityContextToken(struct zx_ctx* c, struct zx_wsc_SecurityContextToken_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx));
#endif

#ifdef ZX_ENA_GETPUT
struct zx_attr_s* zx_wsc_SecurityContextToken_GET_Id(struct zx_wsc_SecurityContextToken_s* x);





void zx_wsc_SecurityContextToken_PUT_Id(struct zx_wsc_SecurityContextToken_s* x, struct zx_attr_s* y);





#endif

#endif
