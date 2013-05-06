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
#include "utils.h"

// ******************************************************************

#define GL_EPSILON 0.005f

// ******************************************************************

void screenquad () {

	glBegin (GL_QUADS);
		glVertex2f (0-GL_EPSILON, 0-GL_EPSILON);
		glVertex2f (1+GL_EPSILON, 0-GL_EPSILON);
		glVertex2f (1+GL_EPSILON, 1+GL_EPSILON);
		glVertex2f (0-GL_EPSILON, 1+GL_EPSILON);
	glEnd ();
}

// ******************************************************************

void texscreenquad () {

	glBegin (GL_QUADS);
		glTexCoord2f (0,0);
		glVertex2f (0,0);

		glTexCoord2f (1,0);
		glVertex2f (1,0);

		glTexCoord2f (1,1);
		glVertex2f (1,1);

		glTexCoord2f (0,1);
		glVertex2f (0,1);
	glEnd ();
}

// ******************************************************************

void copyColorBuffer () {

	glCopyTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, 0, 0, 512, 512);
}

// ******************************************************************

void camera_set2d () {

	glMatrixMode (GL_PROJECTION);
	glPushMatrix ();
	glLoadIdentity ();
	glOrtho (0,1, 0,1, -1,1);

	glMatrixMode (GL_MODELVIEW);
	glPushMatrix ();
	glLoadIdentity ();
}

// ******************************************************************

void camera_restore () {

	glMatrixMode (GL_MODELVIEW);
	glPopMatrix ();
	glMatrixMode (GL_PROJECTION);
	glPopMatrix ();

	glMatrixMode (GL_MODELVIEW);
}
