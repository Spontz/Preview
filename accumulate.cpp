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
#include "filters.h"

// ******************************************************************

void render_accumulate_ext (int tex, int accum) {

	int i;

	// enable multitexturing
	multitex_enable(GL_TEXTURE0_ARB);
	glBindTexture(GL_TEXTURE_2D, tex);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	copyColorBuffer();

	multitex_enable(GL_TEXTURE1_ARB);
	glBindTexture(GL_TEXTURE_2D, tex);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_COMBINE_ARB);
	glTexEnvi(GL_TEXTURE_ENV, GL_SOURCE0_RGB_ARB, GL_PREVIOUS_ARB);
	glTexEnvi(GL_TEXTURE_ENV, GL_SOURCE1_RGB_ARB, GL_TEXTURE);
	glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_RGB_ARB, GL_ADD);

	glBlendFunc (GL_ONE, GL_ONE);
	glColor4f (1,1,1,1);
	glBegin (GL_QUADS);
	for (i=0; i<accum/2; i++) {
		glMultiTexCoord2fARB(GL_TEXTURE0_ARB, 0, 0);
		glMultiTexCoord2fARB(GL_TEXTURE1_ARB, 0, 0);
		glVertex2f (0,0);

		glMultiTexCoord2fARB(GL_TEXTURE0_ARB, 1, 0);
		glMultiTexCoord2fARB(GL_TEXTURE1_ARB, 1, 0);
		glVertex2f (1,0);

		glMultiTexCoord2fARB(GL_TEXTURE0_ARB, 1, 1);
		glMultiTexCoord2fARB(GL_TEXTURE1_ARB, 1, 1);
		glVertex2f (1,1);

		glMultiTexCoord2fARB(GL_TEXTURE0_ARB, 0, 1);
		glMultiTexCoord2fARB(GL_TEXTURE1_ARB, 0, 1);
		glVertex2f (0,1);
	}
	glEnd ();

	multitex_disable(GL_TEXTURE1_ARB);
	multitex_disable(GL_TEXTURE0_ARB);
}

// ******************************************************************

void render_accumulate (int tex, int accum) {

	int i;

	// accumulate color buffer
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tex);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	copyColorBuffer();

	glBegin (GL_QUADS);
	for (i=0; i<accum; i++) {
		glTexCoord2f (0,0);
		glVertex2f (0,0);

		glTexCoord2f (1,0);
		glVertex2f (1,0);

		glTexCoord2f (1,1);
		glVertex2f (1,1);

		glTexCoord2f (0,1);
		glVertex2f (0,1);
	}
	glEnd ();
	glDisable(GL_TEXTURE_2D);
}
