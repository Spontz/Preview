/*
Copyright (C) 2004-2005 Kolian^Spöntz

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

*/

#ifndef __FILTERS_H
#define __FILTERS_H

#ifdef __cplusplus
extern "C" {
#endif

// ******************************************************************

void render_blackwhite (int tex);
void render_invert ();
void render_color ();
void render_accumulate (int tex, int accum);
void render_boxblur (int tex, float radius);

void render_highpassfilter (int tex, float threshold_R, float threshold_G, float threshold_B, int accum);

void render_glow (int tex, int backuptex, float threshold_R, float threshold_G, float threshold_B, int accum, float radius);

// ******************************************************************

void render_radialblur (int tex, int iterations, int recursive, float alpha, float separation, float x, float y);

void render_radialglow (int tex, int backuptex, float threshold_R, float threshold_G, float threshold_B, int accum,
						int iterations, int recursive, float alpha, float separation, float x, float y, int srcBlend, int dstBlend);

// ******************************************************************

#ifdef __cplusplus
}
#endif

#endif
