// Emacs style mode select   -*- C++ -*- 
//-----------------------------------------------------------------------------
//
// $Id: p_maputl.h,v 1.1 1998/05/03 22:19:26 killough Exp $
//
// Copyright (C) 1993-1996 by id Software, Inc.
//
// This source is available for distribution and/or modification
// only under the terms of the DOOM Source Code License as
// published by id Software. All rights reserved.
//
// The source is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// FITNESS FOR A PARTICULAR PURPOSE. See the DOOM Source Code License
// for more details.
//
// DESCRIPTION:
//      Map utility functions
//
//-----------------------------------------------------------------------------

#ifndef __P_MAPUTL__
#define __P_MAPUTL__

#include "r_defs.h"

// mapblocks are used to check movement against lines and things
#define MAPBLOCKUNITS   128
#define MAPBLOCKSIZE    (MAPBLOCKUNITS*FRACUNIT)
#define MAPBLOCKSHIFT   (FRACBITS+7)
#define MAPBMASK        (MAPBLOCKSIZE-1)
#define MAPBTOFRAC      (MAPBLOCKSHIFT-FRACBITS)

#define PT_ADDLINES     1
#define PT_ADDTHINGS    2
#define PT_EARLYOUT     4

typedef struct {
  fixed_t     x;
  fixed_t     y;
  fixed_t     dx;
  fixed_t     dy;
} divline_t;

typedef struct {
  fixed_t     frac;           // along trace line
  boolean     isaline;
  union {
    mobj_t* thing;
    line_t* line;
  } d;
} intercept_t;

typedef boolean (*traverser_t)(intercept_t *in);

fixed_t P_AproxDistance (fixed_t dx, fixed_t dy);
int     P_PointOnLineSide (fixed_t x, fixed_t y, line_t *line);
int     P_PointOnDivlineSide (fixed_t x, fixed_t y, divline_t *line);
void    P_MakeDivline (line_t *li, divline_t *dl);
fixed_t P_InterceptVector (divline_t *v2, divline_t *v1);
int     P_BoxOnLineSide (fixed_t *tmbox, line_t *ld);
void    P_LineOpening (line_t *linedef);
void    P_UnsetThingPosition(mobj_t *thing);
void    P_SetThingPosition(mobj_t *thing);
boolean P_BlockLinesIterator (int x, int y, boolean func(line_t *));
boolean P_BlockThingsIterator(int x, int y, boolean func(mobj_t *));
boolean ThingIsOnLine(mobj_t *t, line_t *l);  // killough 3/15/98
boolean P_PathTraverse(fixed_t x1, fixed_t y1, fixed_t x2, fixed_t y2,
                       int flags, boolean trav(intercept_t *));

extern fixed_t opentop;
extern fixed_t openbottom;
extern fixed_t openrange;
extern fixed_t lowfloor;
extern divline_t trace;

#endif  // __P_MAPUTL__

//----------------------------------------------------------------------------
//
// $Log: p_maputl.h,v $
// Revision 1.1  1998/05/03  22:19:26  killough
// External declarations formerly in p_local.h
//
//
//----------------------------------------------------------------------------
