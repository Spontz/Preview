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

#ifndef __MATH3D_H
#define __MATH3D_H

#ifdef __cplusplus
extern "C" {
#endif

// ******************************************************************

// define pi number
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// define degree to radian
#ifndef DTR
#define DTR (M_PI / 180.0)
#endif

// define radian to degree
#ifndef RTD
#define RTD (180.0 / M_PI)
#endif

// ******************************************************************

// matrix 4x4 of floats
typedef float matrix_t[4][4];

// vector type
typedef struct
{
	float x, y, z;
} vector_t;

// plane type
typedef struct
{
	float normal[3];
	float dist;
	char signbits;
} plane_t;

// ******************************************************************

void matrix_mul (matrix_t a, matrix_t b, matrix_t out);
void matrix_cpy (matrix_t a, matrix_t b);

void matrix_id (matrix_t m);

void matrix_scale (matrix_t m, float sx, float sy, float sz);

void matrix_xrotation (matrix_t m, float angle);
void matrix_yrotation (matrix_t m, float angle);
void matrix_zrotation (matrix_t m, float angle);
void matrix_rotation_matrix (matrix_t mat, float xa, float ya, float za);
void matrix_rotation (matrix_t m, float xa, float ya, float za);

void matrix_translate (matrix_t m, float tx, float ty, float tz);

void matrix_transpose (matrix_t mt, matrix_t m);
void matrix_inverse (matrix_t mi, matrix_t m);

// ******************************************************************

float vector_magnitude (vector_t *v);
void vector_normalize (vector_t *v);
float vector_dotproduct (vector_t *a, vector_t *b);
void vector_crossproduct (vector_t *a, vector_t *b, vector_t *c);
void vector_add (vector_t *a, vector_t *b, vector_t *r);
void vector_sub (vector_t *a, vector_t *b, vector_t *r);
void vector_scale (vector_t *a, float scale, vector_t *r);
void vector_div (vector_t *a, float scale, vector_t *r);
float vector_angle (vector_t *a, vector_t *b);

void vector_transform (vector_t *v, matrix_t m);

// ******************************************************************

#ifdef __cplusplus
}
#endif

#endif
