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

#ifndef __UTILS_H
#define __UTILS_H

#ifdef __cplusplus
extern "C" {
#endif

// ******************************************************************

#ifdef _WIN32
	#ifndef strcasecmp
	#define strcasecmp _stricmp
	#endif

	#define strdup _strdup
#endif

// ******************************************************************

// from SDL library, cut and paste :-)
#define SDL_LIL_ENDIAN	1234
#define SDL_BIG_ENDIAN	4321

#if  defined(__i386__) || defined(__ia64__) || defined(WIN32) || \
	 defined(_WIN32) || \
    (defined(__alpha__) || defined(__alpha)) || \
     defined(__arm__) || \
    (defined(__mips__) && defined(__MIPSEL__)) || \
     defined(__SYMBIAN32__) || \
     defined(__x86_64__) || \
     defined(__LITTLE_ENDIAN__)
#define SDL_BYTEORDER	SDL_LIL_ENDIAN
#else
#define SDL_BYTEORDER	SDL_BIG_ENDIAN
#endif

// ******************************************************************

void screenquad ();
void texscreenquad ();
void copyColorBuffer ();
void camera_set2d ();
void camera_restore ();

// ******************************************************************

#ifdef __cplusplus
}
#endif

#endif
