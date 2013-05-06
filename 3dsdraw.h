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

#ifndef __3DSDRAW_H
#define __3DSDRAW_H

#ifdef __cplusplus
extern "C" {
#endif

// ******************************************************************

#include "3dsload.h"

// ******************************************************************

void render_boundingbox(H3dsBoundingBox *box);
void render_boundingsphere(H3dsBoundingSphere *sphere);

// ******************************************************************

void render_onlyvertex3ds (H3dsScene *scene);
void render_vertex3ds (H3dsScene *scene);
void render_flat3ds (H3dsScene *scene);
void render_smooth3ds (H3dsScene *scene);
void render_facenormals3ds (H3dsScene *scene, float scale);
void render_vertexnormals3ds (H3dsScene *scene, float scale);
void render_allvertexnormals3ds (H3dsScene *scene, float scale);
void render_texture3ds (H3dsScene *scene);
void render_normal3ds (H3dsScene *scene);
void render_bump3ds (H3dsScene *scene, GLuint texture, GLuint cube_map);

// ******************************************************************

#ifdef __cplusplus
}
#endif

#endif
