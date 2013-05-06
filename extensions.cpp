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

#include "extensions.h"
#include "math3d.h"

// ******************************************************************

static tGlExtensions ext;

// has all extensions?
int extensions;

// ******************************************************************

#ifdef _WIN32

// WGL_ARB_multitexture
PFNGLACTIVETEXTUREARBPROC		glActiveTextureARB = NULL;
PFNGLCLIENTACTIVETEXTUREARBPROC	glClientActiveTextureARB = NULL;
PFNGLMULTITEXCOORD2FARBPROC		glMultiTexCoord2fARB = NULL;
PFNGLMULTITEXCOORD2FVARBPROC	glMultiTexCoord2fvARB = NULL;
PFNGLMULTITEXCOORD3FARBPROC		glMultiTexCoord3fARB = NULL;
PFNGLMULTITEXCOORD3FVARBPROC	glMultiTexCoord3fvARB = NULL;

// GL_ARB_texture_compression
PFNGLCOMPRESSEDTEXIMAGE2DARBPROC glCompressedTexImage2DARB = NULL;

// GL_EXT_compiled_vertex_array
PFNGLLOCKARRAYSEXTPROC		glLockArraysEXT = NULL;
PFNGLUNLOCKARRAYSEXTPROC	glUnlockArraysEXT = NULL;

// GL_EXT_blend_subtract
PFNGLBLENDEQUATIONEXTPROC glBlendEquationEXT = NULL;

// WGL_EXT_extensions_string
PFNWGLGETEXTENSIONSSTRINGARBPROC wglGetExtensionsStringARB = NULL;

// WGL_ARB_pbuffer
PFNWGLCREATEPBUFFERARBPROC		wglCreatePbufferARB = NULL;
PFNWGLGETPBUFFERDCARBPROC		wglGetPbufferDCARB = NULL;
PFNWGLRELEASEPBUFFERDCARBPROC	wglReleasePbufferDCARB = NULL;
PFNWGLDESTROYPBUFFERARBPROC		wglDestroyPbufferARB = NULL;
PFNWGLQUERYPBUFFERARBPROC		wglQueryPbufferARB = NULL;

// WGL_ARB_make_current_read
PFNWGLMAKECONTEXTCURRENTARBPROC wglMakeContextCurrentARB = NULL;

// WGL_ARB_pixel_format
PFNWGLGETPIXELFORMATATTRIBIVARBPROC	wglGetPixelFormatAttribivARB = NULL;
PFNWGLGETPIXELFORMATATTRIBFVARBPROC	wglGetPixelFormatAttribfvARB = NULL;
PFNWGLCHOOSEPIXELFORMATARBPROC		wglChoosePixelFormatARB = NULL;

// WGL_ARB_render_texture
PFNWGLBINDTEXIMAGEARBPROC		wglBindTexImageARB = NULL;
PFNWGLRELEASETEXIMAGEARBPROC	wglReleaseTexImageARB = NULL;
PFNWGLSETPBUFFERATTRIBARBPROC	wglSetPbufferAttribARB = NULL;

#endif

/* *************************************************************
 check if an extension is available
**************************************************************** */

int check_extension(char *name) {

	const char *s = NULL;

	s = (char *) glGetString(GL_EXTENSIONS);
	if (strstr(s, name)) return TRUE;

#ifdef _WIN32
	if (ext.ext_extensions_string) {
		s = wglGetExtensionsStringARB(wglGetCurrentDC());
		if (strstr(s, name)) return TRUE;
	}
#endif

	return FALSE;
}

/* *************************************************************
 get extensions procedures
**************************************************************** */

int setup_extensions() {

	// reset the extension
	memset(&ext, 0, sizeof(tGlExtensions));

	glGetIntegerv(GL_MAX_TEXTURE_SIZE, (GLint*)&ext.max_tex_size);
	glGetIntegerv(GL_MAX_TEXTURE_UNITS_ARB, (GLint*)&ext.max_tus);

	// multitexture
	if (check_extension("GL_ARB_multitexture")) {
		ext.multitexture = TRUE;

#ifdef _WIN32
		glActiveTextureARB = (PFNGLACTIVETEXTUREARBPROC) wglGetProcAddress("glActiveTextureARB");
		glClientActiveTextureARB = (PFNGLCLIENTACTIVETEXTUREARBPROC) wglGetProcAddress("glClientActiveTextureARB");
		glMultiTexCoord2fARB = (PFNGLMULTITEXCOORD2FARBPROC) wglGetProcAddress("glMultiTexCoord2fARB");
		glMultiTexCoord2fvARB = (PFNGLMULTITEXCOORD2FVARBPROC) wglGetProcAddress("glMultiTexCoord2fvARB");
		glMultiTexCoord3fARB = (PFNGLMULTITEXCOORD3FARBPROC) wglGetProcAddress("glMultiTexCoord3fARB");
		glMultiTexCoord3fvARB = (PFNGLMULTITEXCOORD3FVARBPROC) wglGetProcAddress("glMultiTexCoord3fvARB");
		if (!(glActiveTextureARB && glClientActiveTextureARB &&
			glMultiTexCoord2fARB && glMultiTexCoord2fvARB &&
			glMultiTexCoord3fARB && glMultiTexCoord3fvARB))
				ext.multitexture = FALSE;
#endif
	}

	// multisample
	if (check_extension("GL_ARB_multisample")) {
		ext.multisample = TRUE;
	}

	// texture_compression
	if (check_extension("GL_ARB_texture_compression")) {
		ext.texture_compression = TRUE;

#ifdef _WIN32
		glCompressedTexImage2DARB = (PFNGLCOMPRESSEDTEXIMAGE2DARBPROC) wglGetProcAddress("glCompressedTexImage2DARB");
		if (!glCompressedTexImage2DARB) ext.texture_compression = FALSE;
#endif
	}

	// texture cube map
	if (check_extension("GL_ARB_texture_cube_map")) {
		ext.texture_cube_map = TRUE;
	}

	// texture env add
	if (check_extension("GL_ARB_texture_env_add")) {
		ext.texture_env_add = TRUE;
	}

	// texture env combine
	if (check_extension("GL_ARB_texture_env_combine")) {
		ext.texture_env_combine = TRUE;
	}

	// texture env dot3
	if (check_extension("GL_ARB_texture_env_dot3")) {
		ext.texture_env_dot3 = TRUE;
	}

	// anisotropic
	if (check_extension("GL_EXT_texture_filter_anisotropic")) {
		ext.anisotropic = TRUE;
	}

	// vertex_array
	if (check_extension("GL_EXT_compiled_vertex_array")) {
		ext.vertex_array = TRUE;

#ifdef _WIN32
		glLockArraysEXT = (PFNGLLOCKARRAYSEXTPROC) wglGetProcAddress("glLockArraysEXT");
		glUnlockArraysEXT = (PFNGLUNLOCKARRAYSEXTPROC) wglGetProcAddress("glUnlockArraysEXT");
		if (!(glLockArraysEXT && glUnlockArraysEXT)) ext.vertex_array = FALSE;
#endif
	}

	// blend subtract
	if (check_extension("GL_EXT_blend_subtract")) {
		ext.blend_subtract = TRUE;

#ifdef _WIN32
		glBlendEquationEXT	= (PFNGLBLENDEQUATIONEXTPROC) wglGetProcAddress("glBlendEquationEXT");
		if (!glBlendEquationEXT) ext.blend_subtract = FALSE;
#endif
	}

	// generate_mipmap
	if (check_extension("GL_SGIS_generate_mipmap")) {
		ext.generate_mipmap = TRUE;
	}

#ifdef _WIN32
	// ext_extensions_string
	if (check_extension("WGL_EXT_extensions_string")) {
		wglGetExtensionsStringARB = (PFNWGLGETEXTENSIONSSTRINGARBPROC) wglGetProcAddress("wglGetExtensionsStringARB");

		if (wglGetExtensionsStringARB)
			ext.ext_extensions_string = TRUE;
	}

	// pbuffer
	if (check_extension("WGL_ARB_pbuffer") && check_extension("WGL_ARB_make_current_read") &&
		check_extension("WGL_ARB_pixel_format") && check_extension("WGL_ARB_render_texture")) {

		wglCreatePbufferARB = (PFNWGLCREATEPBUFFERARBPROC) wglGetProcAddress("wglCreatePbufferARB");
		wglGetPbufferDCARB = (PFNWGLGETPBUFFERDCARBPROC) wglGetProcAddress("wglGetPbufferDCARB");
		wglReleasePbufferDCARB = (PFNWGLRELEASEPBUFFERDCARBPROC) wglGetProcAddress("wglReleasePbufferDCARB");
		wglDestroyPbufferARB = (PFNWGLDESTROYPBUFFERARBPROC) wglGetProcAddress("wglDestroyPbufferARB");
		wglQueryPbufferARB = (PFNWGLQUERYPBUFFERARBPROC) wglGetProcAddress("wglQueryPbufferARB");

		wglMakeContextCurrentARB = (PFNWGLMAKECONTEXTCURRENTARBPROC) wglGetProcAddress("wglMakeContextCurrentARB");

		wglGetPixelFormatAttribivARB = (PFNWGLGETPIXELFORMATATTRIBIVARBPROC) wglGetProcAddress("wglGetPixelFormatAttribivARB");
		wglGetPixelFormatAttribfvARB = (PFNWGLGETPIXELFORMATATTRIBFVARBPROC) wglGetProcAddress("wglGetPixelFormatAttribfvARB");
		wglChoosePixelFormatARB = (PFNWGLCHOOSEPIXELFORMATARBPROC) wglGetProcAddress("wglChoosePixelFormatARB");

		wglBindTexImageARB = (PFNWGLBINDTEXIMAGEARBPROC) wglGetProcAddress("wglBindTexImageARB");
		wglReleaseTexImageARB = (PFNWGLRELEASETEXIMAGEARBPROC) wglGetProcAddress("wglReleaseTexImageARB");
		wglSetPbufferAttribARB = (PFNWGLSETPBUFFERATTRIBARBPROC) wglGetProcAddress("wglSetPbufferAttribARB");

		if (wglCreatePbufferARB && wglGetPbufferDCARB && wglReleasePbufferDCARB && wglDestroyPbufferARB &&
			wglQueryPbufferARB && wglMakeContextCurrentARB && wglGetPixelFormatAttribivARB &&
			wglGetPixelFormatAttribfvARB && wglChoosePixelFormatARB &&
			wglBindTexImageARB && wglReleaseTexImageARB && wglSetPbufferAttribARB)
				ext.pbuffer = TRUE;
	}
#endif

	if (!ext.multitexture || !ext.texture_cube_map ||
		!ext.texture_env_add || !ext.texture_env_combine ||
		!ext.blend_subtract || !ext.generate_mipmap) {
			return 0;
	}

	return 1;
}

// ******************************************************************

void generateNormalizationCubeMap() {

	int i, j, size = 32;
	float offset = 0.5f;
	float halfSize = 16.0f;
	vector_t tempVector, midVector = {offset, offset, offset};
	unsigned char *bytePtr;
	unsigned char *data;

	// allocate a temporary buffer
	data = (unsigned char *) malloc(32*32*3);

	// positive x
	bytePtr = data;
	for (j=0; j<size; j++) {

		for(i=0; i<size; i++) {
			tempVector.x = halfSize;
			tempVector.y = -(j+offset-halfSize);
			tempVector.z = -(i+offset-halfSize);

			vector_normalize(&tempVector);
			vector_scale(&tempVector, 0.5f, &tempVector);
			vector_add(&tempVector, &midVector, &tempVector);

			bytePtr[0] = (unsigned char) (tempVector.x*255);
			bytePtr[1] = (unsigned char) (tempVector.y*255);
			bytePtr[2] = (unsigned char) (tempVector.z*255);

			bytePtr += 3;
		}
	}
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB,
					0, GL_RGBA8, 32, 32, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

	// negative x
	bytePtr = data;
	for (j=0; j<size; j++) {

		for(i=0; i<size; i++) {
			tempVector.x = -halfSize;
			tempVector.y = -(j+offset-halfSize);
			tempVector.z = i+offset-halfSize;

			vector_normalize(&tempVector);
			vector_scale(&tempVector, 0.5f, &tempVector);
			vector_add(&tempVector, &midVector, &tempVector);

			bytePtr[0] = (unsigned char) (tempVector.x*255);
			bytePtr[1] = (unsigned char) (tempVector.y*255);
			bytePtr[2] = (unsigned char) (tempVector.z*255);

			bytePtr += 3;
		}
	}
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB,
					0, GL_RGBA8, 32, 32, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

	// positive y
	bytePtr = data;
	for (j=0; j<size; j++) {

		for(i=0; i<size; i++) {
			tempVector.x = i+offset-halfSize;
			tempVector.y = halfSize;
			tempVector.z = j+offset-halfSize;

			vector_normalize(&tempVector);
			vector_scale(&tempVector, 0.5f, &tempVector);
			vector_add(&tempVector, &midVector, &tempVector);

			bytePtr[0] = (unsigned char) (tempVector.x*255);
			bytePtr[1] = (unsigned char) (tempVector.y*255);
			bytePtr[2] = (unsigned char) (tempVector.z*255);

			bytePtr += 3;
		}
	}
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB,
					0, GL_RGBA8, 32, 32, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

	// negative y
	bytePtr = data;
	for (j=0; j<size; j++) {

		for(i=0; i<size; i++) {
			tempVector.x = i+offset-halfSize;
			tempVector.y = -halfSize;
			tempVector.z = -(j+offset-halfSize);

			vector_normalize(&tempVector);
			vector_scale(&tempVector, 0.5f, &tempVector);
			vector_add(&tempVector, &midVector, &tempVector);

			bytePtr[0] = (unsigned char) (tempVector.x*255);
			bytePtr[1] = (unsigned char) (tempVector.y*255);
			bytePtr[2] = (unsigned char) (tempVector.z*255);

			bytePtr += 3;
		}
	}
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB,
					0, GL_RGBA8, 32, 32, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

	// positive z
	bytePtr = data;
	for (j=0; j<size; j++) {

		for(i=0; i<size; i++) {
			tempVector.x = i+offset-halfSize;
			tempVector.y = -(j+offset-halfSize);
			tempVector.z = halfSize;

			vector_normalize(&tempVector);
			vector_scale(&tempVector, 0.5f, &tempVector);
			vector_add(&tempVector, &midVector, &tempVector);

			bytePtr[0] = (unsigned char) (tempVector.x*255);
			bytePtr[1] = (unsigned char) (tempVector.y*255);
			bytePtr[2] = (unsigned char) (tempVector.z*255);

			bytePtr += 3;
		}
	}
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB,
					0, GL_RGBA8, 32, 32, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

	// negative z
	bytePtr = data;
	for (j=0; j<size; j++) {

		for(i=0; i<size; i++) {
			tempVector.x = -(i+offset-halfSize);
			tempVector.y = -(j+offset-halfSize);
			tempVector.z = -halfSize;

			vector_normalize(&tempVector);
			vector_scale(&tempVector, 0.5f, &tempVector);
			vector_add(&tempVector, &midVector, &tempVector);

			bytePtr[0] = (unsigned char) (tempVector.x*255);
			bytePtr[1] = (unsigned char) (tempVector.y*255);
			bytePtr[2] = (unsigned char) (tempVector.z*255);

			bytePtr += 3;
		}
	}
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB,
					0, GL_RGBA8, 32, 32, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

	free(data);
}

// ******************************************************************

GLuint setup_normalizationCubeMap() {

	GLuint cube_map;

	glGenTextures(1, &cube_map);
	glBindTexture(GL_TEXTURE_CUBE_MAP_ARB, cube_map);
	generateNormalizationCubeMap();
	glTexParameteri(GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	return cube_map;
}

// ******************************************************************

void multitex_enable (GLenum tex) {

	glActiveTextureARB(tex);
	glClientActiveTextureARB(tex);
	glEnable(GL_TEXTURE_2D);
}

// ******************************************************************

void multitex_disable (GLenum tex) {

	glActiveTextureARB(tex);
	glClientActiveTextureARB(tex);
	glDisable(GL_TEXTURE_2D);
}
