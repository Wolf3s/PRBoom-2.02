// Emacs style mode select   -*- C++ -*- 
//-----------------------------------------------------------------------------
//
// $Id: r_data.h,v 1.6 1998/05/03 22:55:43 killough Exp $
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
//  Refresh module, data I/O, caching, retrieval of graphics
//  by name.
//
//-----------------------------------------------------------------------------


#ifndef __R_DATA__
#define __R_DATA__

#include "r_defs.h"
#include "r_state.h"

#ifdef __GNUG__
#pragma interface
#endif

// Retrieve column data for span blitting.
byte*
R_GetColumn
( int           tex,
  int           col );


// I/O, setting up the stuff.
void R_InitData (void);
void R_PrecacheLevel (void);


// Retrieval.
// Floor/ceiling opaque texture tiles,
// lookup by name. For animation?
int R_FlatNumForName (const char* name);   // killough -- const added


// Called by P_Ticker for switches and animations,
// returns the texture number for the texture name.
int R_TextureNumForName (const char *name);    // killough -- const added
int R_CheckTextureNumForName (const char *name); 

void R_InitTranMap(int);      // killough 3/6/98: translucency initialization
int R_ColormapNumForName(const char *name);      // killough 4/4/98

extern byte *main_tranmap, *tranmap;

#endif

//----------------------------------------------------------------------------
//
// $Log: r_data.h,v $
// Revision 1.6  1998/05/03  22:55:43  killough
// Add tranmap external declarations
//
// Revision 1.5  1998/04/06  04:48:25  killough
// Add R_ColormapNumForName() prototype
//
// Revision 1.4  1998/03/09  07:26:34  killough
// Add translucency map caching
//
// Revision 1.3  1998/03/02  12:10:05  killough
// Add R_InitTranMap prototype
//
// Revision 1.2  1998/01/26  19:27:34  phares
// First rev with no ^Ms
//
// Revision 1.1.1.1  1998/01/19  14:03:08  rand
// Lee's Jan 19 sources
//
//
//----------------------------------------------------------------------------