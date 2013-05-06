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

#ifndef __EXTENSIONS_H
#define __EXTENSIONS_H

// ******************************************************************

#include <qgl.h>

// ******************************************************************

#ifdef __cplusplus
extern "C" {
#endif

// ******************************************************************

#ifdef _WIN32

	#include "glext.h"
	#include "wglext.h"

	// GL_ARB_multitexture
	extern PFNGLACTIVETEXTUREARBPROC		glActiveTextureARB;
	extern PFNGLCLIENTACTIVETEXTUREARBPROC	glClientActiveTextureARB;
	extern PFNGLMULTITEXCOORD2FARBPROC		glMultiTexCoord2fARB;
	extern PFNGLMULTITEXCOORD2FVARBPROC		glMultiTexCoord2fvARB;
	extern PFNGLMULTITEXCOORD3FARBPROC		glMultiTexCoord3fARB;
	extern PFNGLMULTITEXCOORD3FVARBPROC		glMultiTexCoord3fvARB;

	// GL_ARB_texture_compression
	extern PFNGLCOMPRESSEDTEXIMAGE2DARBPROC glCompressedTexImage2DARB;

	// GL_EXT_compiled_vertex_array
	extern PFNGLLOCKARRAYSEXTPROC	glLockArraysEXT;
	extern PFNGLUNLOCKARRAYSEXTPROC	glUnlockArraysEXT;

	// GL_EXT_blend_subtract
	extern PFNGLBLENDEQUATIONEXTPROC glBlendEquationEXT;

	// WGL_EXT_extensions_string
	extern PFNWGLGETEXTENSIONSSTRINGARBPROC wglGetExtensionsStringARB;

	// WGL_ARB_pbuffer
	extern PFNWGLCREATEPBUFFERARBPROC		wglCreatePbufferARB;
	extern PFNWGLGETPBUFFERDCARBPROC		wglGetPbufferDCARB;
	extern PFNWGLRELEASEPBUFFERDCARBPROC	wglReleasePbufferDCARB;
	extern PFNWGLDESTROYPBUFFERARBPROC		wglDestroyPbufferARB;
	extern PFNWGLQUERYPBUFFERARBPROC		wglQueryPbufferARB;

	// WGL_ARB_make_current_read
	extern PFNWGLMAKECONTEXTCURRENTARBPROC wglMakeContextCurrentARB;

	// WGL_ARB_pixel_format
	extern PFNWGLGETPIXELFORMATATTRIBIVARBPROC	wglGetPixelFormatAttribivARB;
	extern PFNWGLGETPIXELFORMATATTRIBFVARBPROC	wglGetPixelFormatAttribfvARB;
	extern PFNWGLCHOOSEPIXELFORMATARBPROC		wglChoosePixelFormatARB;

	// WGL_ARB_render_texture
	extern PFNWGLBINDTEXIMAGEARBPROC		wglBindTexImageARB;
	extern PFNWGLRELEASETEXIMAGEARBPROC		wglReleaseTexImageARB;
	extern PFNWGLSETPBUFFERATTRIBARBPROC	wglSetPbufferAttribARB;

#elif __APPLE__

	#include <OpenGL/glext.h>

#else

	#define GL_GLEXT_PROTOTYPES 1
	#include "glext.h"

	#define glBlendEquationEXT glBlendEquation

#endif

// ******************************************************************

extern int extensions;

// ******************************************************************

typedef struct {

	int max_tex_size;
	int max_tus;

	// ARB extensions
	char multitexture;
	char multisample;
	char texture_compression;
	char texture_cube_map;
	char texture_env_add;
	char texture_env_combine;
	char texture_env_dot3;

	// EXT extensions
	char anisotropic;
	char vertex_array;
	char blend_subtract;

	// SGIS extensions
	char generate_mipmap;

	// Windows only extensions
	char ext_extensions_string;
	char pbuffer;

} tGlExtensions;

// ******************************************************************

int setup_extensions();
GLuint setup_normalizationCubeMap();
void multitex_enable (GLenum tex);
void multitex_disable (GLenum tex);

// ******************************************************************

#ifdef __cplusplus
}
#endif

#endif
