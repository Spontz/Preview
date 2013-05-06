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

#include <math.h>
#include "extensions.h"
#include "3dsdraw.h"

// ******************************************************************

GLenum getPrimitive(int vertexes) {

	switch (vertexes) {
		case 3: return GL_TRIANGLES;
		case 4: return GL_QUADS;
		case 2: return GL_LINES;
		case 1: return GL_POINTS;
		default: return GL_POLYGON;
	}
}

// ******************************************************************

void render_boundingbox(H3dsBoundingBox *box) {

	glBegin(GL_QUADS);
		glVertex3f(box->min[0], box->min[1], box->min[2]);
		glVertex3f(box->max[0], box->min[1], box->min[2]);
		glVertex3f(box->max[0], box->max[1], box->min[2]);
		glVertex3f(box->min[0], box->max[1], box->min[2]);

		glVertex3f(box->min[0], box->min[1], box->max[2]);
		glVertex3f(box->max[0], box->min[1], box->max[2]);
		glVertex3f(box->max[0], box->max[1], box->max[2]);
		glVertex3f(box->min[0], box->max[1], box->max[2]);

		glVertex3f(box->min[0], box->min[1], box->min[2]);
		glVertex3f(box->max[0], box->min[1], box->min[2]);
		glVertex3f(box->max[0], box->min[1], box->max[2]);
		glVertex3f(box->min[0], box->min[1], box->max[2]);

		glVertex3f(box->min[0], box->max[1], box->min[2]);
		glVertex3f(box->max[0], box->max[1], box->min[2]);
		glVertex3f(box->max[0], box->max[1], box->max[2]);
		glVertex3f(box->min[0], box->max[1], box->max[2]);
	glEnd();
}

// ******************************************************************

void render_boundingsphere(H3dsBoundingSphere *sphere) {

	glPushMatrix();
	glTranslatef(sphere->center[0], sphere->center[1], sphere->center[2]);
	glRotatef(90, 1, 0, 0);
	gluSphere(gluNewQuadric(), sphere->radius, 20, 20);
	glPopMatrix();
}

// ******************************************************************

static void matrixInvert(float m[16]) {

	float temp[16];

	temp[0] = m[0];
	temp[1] = m[4];
	temp[2] = m[8];
	temp[3] = 0.0f;

	temp[4] = m[1];
	temp[5] = m[5];
	temp[6] = m[9];
	temp[7] = 0.0f;

	temp[8]  = m[2];
	temp[9]  = m[6];
	temp[10] = m[10];
	temp[11] = 0.0f;
	temp[15] = 1.0f;

	temp[12] = -(m[12]*m[0])-(m[13]*m[1])-(m[14]*m[2]);
	temp[13] = -(m[12]*m[4])-(m[13]*m[5])-(m[14]*m[6]);
	temp[14] = -(m[12]*m[8])-(m[13]*m[9])-(m[14]*m[10]);

	memcpy(m, temp, sizeof(float)*16);
}

// ******************************************************************
// each function assumes the opengl state is correct for each case
// ******************************************************************

void render_onlyvertex3ds (H3dsScene *scene) {

	H3dsMeshObj *mesh;
	int nmesh, nvert;

	glBegin(GL_POINTS);
	for (nmesh=0; nmesh<scene->meshobjs; nmesh++) {

		mesh = &scene->meshobjlist[nmesh];
		for (nvert=0; nvert<mesh->verts; nvert++)
			glVertex3fv((GLfloat*)&mesh->vertlist[nvert]);
	}
	glEnd();
}

// ******************************************************************
// vertex3f
// ******************************************************************

void render_vertex3ds_tri (H3dsMeshObj *mesh) {

	int nface, nvert;
	word v;

	glBegin(GL_TRIANGLES);
	for (nface=0; nface<mesh->faces; nface++) {

		for (nvert=0; nvert<3; nvert++) {
			v = mesh->facelist[nface].v[nvert].vertex;
			glVertex3fv((GLfloat*)&mesh->vertlist[v]);
		}
	}
	glEnd();
}

// ******************************************************************

void render_vertex3ds_poly (H3dsMeshObj *mesh) {

	int nface, nvert;
	word v;

	for (nface=0; nface<mesh->faces; nface++) {

		glBegin(GL_POLYGON);
		for (nvert=0; nvert<mesh->facelist[nface].vertexes; nvert++) {
			v = mesh->facelist[nface].v[nvert].vertex;
			glVertex3fv((GLfloat*)&mesh->vertlist[v]);
		}
		glEnd();
	}
}

// ******************************************************************

void render_vertex3ds (H3dsScene *scene) {

	H3dsMeshObj *mesh;
	int nmesh;

	for (nmesh=0; nmesh<scene->meshobjs; nmesh++) {

		mesh = &scene->meshobjlist[nmesh];
		if (mesh->hasNonTriangles) render_vertex3ds_poly(mesh);
		else render_vertex3ds_tri(mesh);
	}
}

// ******************************************************************
// utility to set materials
// ******************************************************************

void setMaterial (H3dsMaterial *mat) {

	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,(float*)&mat->Ambient);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,(float*)&mat->Diffuse);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,(float*)&mat->Specular);
	glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,mat->shiny);
}

// ******************************************************************
// vertex3f + normal per face + materials
// ******************************************************************

void render_flat3ds (H3dsScene *scene) {

	H3dsMeshObj *mesh;
	H3dsMaterial *mat, *curmat = NULL;
	int nmesh, nface, nvert;
	word v;

	for (nmesh=0; nmesh<scene->meshobjs; nmesh++) {

		mesh = &scene->meshobjlist[nmesh];
		for (nface=0; nface<mesh->faces; nface++) {

			mat = mesh->facelist[nface].material;
			if (mat && (mat != curmat)) {
				setMaterial(mat);
				curmat = mat;
			}

			glBegin(GL_POLYGON);
			glNormal3fv(mesh->facelist[nface].normal);
			for (nvert=0; nvert<mesh->facelist[nface].vertexes; nvert++) {
				v = mesh->facelist[nface].v[nvert].vertex;
				glVertex3fv((GLfloat*)&mesh->vertlist[v]);
			}
			glEnd();
		}
	}

	if (scene->hasTransp) {

		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		for (nmesh=0; nmesh<scene->meshobjs; nmesh++) {

			mesh = &scene->meshobjlist[nmesh];
			for (nface=0; nface<mesh->transpfaces; nface++) {

				mat = mesh->transpfacelist[nface].material;
				if (mat && (mat != curmat)) {
					glColor4f(0,0,0,mat->transp);
					setMaterial(mat);
					curmat = mat;
				}

				glBegin(GL_POLYGON);
				glNormal3fv(mesh->transpfacelist[nface].normal);
				for (nvert=0; nvert<mesh->transpfacelist[nface].vertexes; nvert++) {
					v = mesh->transpfacelist[nface].v[nvert].vertex;
					glVertex3fv((GLfloat*)&mesh->vertlist[v]);
				}
				glEnd();
			}
		}
	}
}

// ******************************************************************
// vertex3f + normal per vertex + materials
// ******************************************************************

void render_smooth3ds (H3dsScene *scene) {

	H3dsMeshObj *mesh;
	H3dsMaterial *mat, *curmat = NULL;
	int nmesh, nface, nvert;
	word v;

	for (nmesh=0; nmesh<scene->meshobjs; nmesh++) {

		mesh = &scene->meshobjlist[nmesh];
		for (nface=0; nface<mesh->faces; nface++) {

			mat = mesh->facelist[nface].material;
			if (mat && (mat != curmat)) {
				setMaterial(mat);
				curmat = mat;
			}

			glBegin(GL_POLYGON);
			for (nvert=0; nvert<mesh->facelist[nface].vertexes; nvert++) {
				v = mesh->facelist[nface].v[nvert].vertex;
				glNormal3fv(mesh->vertlist[v].normal);
				glVertex3fv((GLfloat*)&mesh->vertlist[v]);
			}
			glEnd();
		}
	}

	if (scene->hasTransp) {

		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		for (nmesh=0; nmesh<scene->meshobjs; nmesh++) {

			mesh = &scene->meshobjlist[nmesh];
			for (nface=0; nface<mesh->transpfaces; nface++) {

				mat = mesh->transpfacelist[nface].material;
				if (mat && (mat != curmat)) {
					glColor4f(0,0,0,mat->transp);
					setMaterial(mat);
					curmat = mat;
				}

				glBegin(GL_POLYGON);
				for (nvert=0; nvert<mesh->transpfacelist[nface].vertexes; nvert++) {
					v = mesh->transpfacelist[nface].v[nvert].vertex;
					glNormal3fv(mesh->vertlist[v].normal);
					glVertex3fv((GLfloat*)&mesh->vertlist[v]);
				}
				glEnd();
			}
		}
	}
}

// ******************************************************************
// only normals as lines
// ******************************************************************

void render_facenormals3ds (H3dsScene *scene, float scale) {

	float middle[3];
	H3dsMeshObj *mesh;
	int nmesh, nface, nvert;
	word v;

	glBegin(GL_LINES);
	for (nmesh=0; nmesh<scene->meshobjs; nmesh++) {

		mesh = &scene->meshobjlist[nmesh];
		for (nface=0; nface<mesh->faces; nface++) {

			if (mesh->facelist[nface].vertexes < 3) continue;

			middle[0] = middle[1] = middle[2] = 0.0f;
			for (nvert=0; nvert<mesh->facelist[nface].vertexes; nvert++) {
				v = mesh->facelist[nface].v[nvert].vertex;
				middle[0] += mesh->vertlist[v].x;
				middle[1] += mesh->vertlist[v].y;
				middle[2] += mesh->vertlist[v].z;
			}
			middle[0] /= (float) mesh->facelist[nface].vertexes;
			middle[1] /= (float) mesh->facelist[nface].vertexes;
			middle[2] /= (float) mesh->facelist[nface].vertexes;

			glVertex3fv(middle);
			glVertex3f(	middle[0] + mesh->facelist[nface].normal[0] * scale,
						middle[1] + mesh->facelist[nface].normal[1] * scale,
						middle[2] + mesh->facelist[nface].normal[2] * scale);
		}
	}
	glEnd();
}

// ******************************************************************

void render_vertexnormals3ds (H3dsScene *scene, float scale) {

	H3dsMeshObj *mesh;
	int nmesh, nvertex;

	glBegin(GL_LINES);
	for (nmesh=0; nmesh<scene->meshobjs; nmesh++) {

		mesh = &scene->meshobjlist[nmesh];
		for (nvertex=0; nvertex<mesh->verts; nvertex++) {

			H3dsVert *vert = &mesh->vertlist[nvertex];

			glVertex3fv(&vert->x);
			glVertex3f(	vert->x + vert->normal[0] * scale,
						vert->y + vert->normal[1] * scale,
						vert->z + vert->normal[2] * scale);
		}
	}
	glEnd();
}

// ******************************************************************

void render_allvertexnormals3ds (H3dsScene *scene, float scale) {

	H3dsMeshObj *mesh;
	int nmesh, nvertex;

	glBegin(GL_LINES);
	for (nmesh=0; nmesh<scene->meshobjs; nmesh++) {

		mesh = &scene->meshobjlist[nmesh];
		for (nvertex=0; nvertex<mesh->verts; nvertex++) {

			H3dsVert *vert = &mesh->vertlist[nvertex];

			glColor4f(1,0,0,0);
			glVertex3fv(&vert->x);
			glVertex3f(	vert->x + vert->tangent[0] * scale,
						vert->y + vert->tangent[1] * scale,
						vert->z + vert->tangent[2] * scale);

			glColor4f(0,1,0,0);
			glVertex3fv(&vert->x);
			glVertex3f(	vert->x + vert->binormal[0] * scale,
						vert->y + vert->binormal[1] * scale,
						vert->z + vert->binormal[2] * scale);

			glColor4f(0,0,1,0);
			glVertex3fv(&vert->x);
			glVertex3f(	vert->x + vert->normal[0] * scale,
						vert->y + vert->normal[1] * scale,
						vert->z + vert->normal[2] * scale);
		}
	}
	glEnd();
}

// ******************************************************************
// vertex3f + texcoord2f
// ******************************************************************

void render_texture3ds_tri (H3dsMeshObj *mesh, unsigned int *curtex) {

	H3dsMaterial *mat;
	int nface, nvert;
	word v;

	glBegin(GL_TRIANGLES);
	for (nface=0; nface<mesh->faces; nface++) {

		mat = mesh->facelist[nface].material;
		if (mat) {
			if (mat->hTex > 0) {
				if (mat->hTex != *curtex) {
					glEnd();
					glBindTexture(GL_TEXTURE_2D, mat->hTex);
					*curtex = mat->hTex;
					glBegin(GL_TRIANGLES);
				}
			} else {
				// skip faces without texture
				if (!mat->TexFilename) continue;
			}
		}

		for (nvert=0; nvert<3; nvert++) {
			v = mesh->facelist[nface].v[nvert].vertex;
			glTexCoord2fv((GLfloat*)&mesh->facelist[nface].v[nvert].u);
			glVertex3fv((GLfloat*)&mesh->vertlist[v]);
		}
	}
	glEnd();
}

// ******************************************************************

void render_texture3ds_poly (H3dsMeshObj *mesh, unsigned int *curtex) {

	H3dsMaterial *mat;
	int nface, nvert;
	word v;

	for (nface=0; nface<mesh->faces; nface++) {

		mat = mesh->facelist[nface].material;
		if (mat) {
			if (mat->hTex > 0) {
				if (mat->hTex != *curtex) {
					glBindTexture(GL_TEXTURE_2D, mat->hTex);
					*curtex = mat->hTex;
				}
			} else {
				// skip faces without texture
				if (!mat->TexFilename) continue;
			}
		}

		glBegin(GL_POLYGON);
			for (nvert=0; nvert<mesh->facelist[nface].vertexes; nvert++) {
			v = mesh->facelist[nface].v[nvert].vertex;
			glTexCoord2fv((GLfloat*)&mesh->facelist[nface].v[nvert].u);
			glVertex3fv((GLfloat*)&mesh->vertlist[v]);
		}
		glEnd();
	}
}

// ******************************************************************

void render_texture3ds (H3dsScene *scene) {

	H3dsMeshObj *mesh;
	int nmesh;
	unsigned int curtex = 99999;

	for (nmesh=0; nmesh<scene->meshobjs; nmesh++) {

		mesh = &scene->meshobjlist[nmesh];
		if (mesh->maps == 0) continue;
		if (mesh->hasNonTriangles) render_texture3ds_poly(mesh, &curtex);
		else render_texture3ds_tri(mesh, &curtex);
	}
}

// ******************************************************************
// vertex3f + normal per vertex
// ******************************************************************

void render_normal3ds_tri (H3dsMeshObj *mesh) {

	int nface, nvert;
	word v;

	glBegin(GL_TRIANGLES);
	for (nface=0; nface<mesh->faces; nface++) {

		for (nvert=0; nvert<3; nvert++) {
			v = mesh->facelist[nface].v[nvert].vertex;
			glNormal3fv(mesh->vertlist[v].normal);
			glVertex3fv((GLfloat*)&mesh->vertlist[v]);
		}
	}
	glEnd();
}

// ******************************************************************

void render_normal3ds_poly (H3dsMeshObj *mesh) {

	int nface, nvert;
	word v;

	for (nface=0; nface<mesh->faces; nface++) {

		glBegin(GL_POLYGON);
		for (nvert=0; nvert<mesh->facelist[nface].vertexes; nvert++) {
			v = mesh->facelist[nface].v[nvert].vertex;
			glNormal3fv(mesh->vertlist[v].normal);
			glVertex3fv((GLfloat*)&mesh->vertlist[v]);
		}
		glEnd();
	}
}

// ******************************************************************

void render_normal3ds (H3dsScene *scene) {

	H3dsMeshObj *mesh;
	int nmesh;

	for (nmesh=0; nmesh<scene->meshobjs; nmesh++) {

		mesh = &scene->meshobjlist[nmesh];
		if (mesh->hasNonTriangles) render_normal3ds_poly(mesh);
		else render_normal3ds_tri(mesh);
	}
}

// ******************************************************************
// dot3 bumpmapping
// ******************************************************************

void render_bump3ds (H3dsScene *scene, GLuint texture, GLuint cube_map) {

	float m[16];
	float lightWorld[3], light[3];
	H3dsMeshObj *mesh;
	int nmesh, nface, nvert;
	word v;

	// light in world space (hardcoded)
	lightWorld[0] = 0;
	lightWorld[1] = 0;
	lightWorld[2] = 500;

	// get the current modelview matrix
	glMatrixMode(GL_MODELVIEW);
	glGetFloatv(GL_MODELVIEW_MATRIX, m);
	matrixInvert(m);

	// transform light from world space to modelview space
	light[0] = (lightWorld[0]*m[0]) + (lightWorld[1]*m[4]) + (lightWorld[2]*m[8]);
	light[1] = (lightWorld[0]*m[1]) + (lightWorld[1]*m[5]) + (lightWorld[2]*m[9]);
	light[2] = (lightWorld[0]*m[2]) + (lightWorld[1]*m[6]) + (lightWorld[2]*m[10]);

	// first pass to calculate TC vector of each vertex
	for (nmesh=0; nmesh<scene->meshobjs; nmesh++) {

		mesh = &scene->meshobjlist[nmesh];
		for (nvert=0; nvert<mesh->verts; nvert++) {

			H3dsVert *vert = &mesh->vertlist[nvert];
			float lv[3], len;

			// vector between vertex and light (in modelview space)
			lv[0] = light[0] - vert->x;
			lv[1] = light[1] - vert->y;
			lv[2] = light[2] - vert->z;

			// normalization
			len = (float) sqrt((lv[0]*lv[0])+(lv[1]*lv[1])+(lv[2]*lv[2]));
			if (len != 0.0f) {
				lv[0] /= len;
				lv[1] /= len;
				lv[2] /= len;
			}

			// transform!
			vert->result[0] = (lv[0]*vert->tangent[0])  + (lv[1]*vert->tangent[1])  + (lv[2]*vert->tangent[2]);
			vert->result[1] = (lv[0]*vert->binormal[0]) + (lv[1]*vert->binormal[1]) + (lv[2]*vert->binormal[2]);
			vert->result[2] = (lv[0]*vert->normal[0])   + (lv[1]*vert->normal[1])   + (lv[2]*vert->normal[2]);
		}
	}

	// TU0 = normal map texture
	multitex_enable(GL_TEXTURE0_ARB);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	// TU1 = normalization cube map
	glActiveTextureARB(GL_TEXTURE1_ARB);
	glClientActiveTextureARB(GL_TEXTURE1_ARB);
	glEnable(GL_TEXTURE_CUBE_MAP_ARB);
	glBindTexture(GL_TEXTURE_CUBE_MAP_ARB, cube_map);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_COMBINE_ARB);
	glTexEnvi(GL_TEXTURE_ENV, GL_SOURCE0_RGB_ARB, GL_PREVIOUS_ARB);
	glTexEnvi(GL_TEXTURE_ENV, GL_SOURCE1_RGB_ARB, GL_TEXTURE);
	glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_RGB_ARB, GL_DOT3_RGB_ARB);

	for (nmesh=0; nmesh<scene->meshobjs; nmesh++) {

		mesh = &scene->meshobjlist[nmesh];
		if (mesh->maps == 0) continue;

		for (nface=0; nface<mesh->faces; nface++) {

			glBegin(GL_POLYGON);
			for (nvert=0; nvert<mesh->facelist[nface].vertexes; nvert++) {
				v = mesh->facelist[nface].v[nvert].vertex;
				glMultiTexCoord2fvARB(GL_TEXTURE0_ARB, (GLfloat*)&mesh->facelist[nface].v[nvert].u);
				glMultiTexCoord3fvARB(GL_TEXTURE1_ARB, (GLfloat*)&mesh->vertlist[v].result);
				glVertex3fv((GLfloat*)&mesh->vertlist[v]);
			}
			glEnd();
		}
	}

	// disable TU1
	glActiveTextureARB(GL_TEXTURE1_ARB);
	glClientActiveTextureARB(GL_TEXTURE1_ARB);
	glDisable(GL_TEXTURE_CUBE_MAP_ARB);

	// disable TU0
	multitex_disable(GL_TEXTURE0_ARB);
}
