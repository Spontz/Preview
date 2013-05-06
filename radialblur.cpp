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

void render_radialblur (int tex, int iterations, int recursive, float alpha, float separation, float x, float y) {

	float step;
	float offset, offsetX, offsetY;
	int i;

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tex);
	glColor4f(1.0f, 1.0f, 1.0f, alpha);

	if (recursive) {

		for (i=0; i<iterations; i++) {

			copyColorBuffer();

			step = (float) i / iterations;
			offset = step * separation * (float) i;
			offsetX = offset * (x - 0.5f);
			offsetY = offset * (0.5f - y);

			glBegin(GL_QUADS);

				glTexCoord2f (offsetX,offsetY+1);
				glVertex2f   (-offset,1+offset);

				glTexCoord2f (offsetX,offsetY);
				glVertex2f   (-offset,-offset);

				glTexCoord2f (offsetX+1,offsetY);
				glVertex2f   (1+offset,-offset);

				glTexCoord2f (offsetX+1,offsetY+1);
				glVertex2f   (1+offset,1+offset);

			glEnd();
		}

	} else {

		copyColorBuffer();
		glBegin(GL_QUADS);

		for (i=0; i<iterations; i++) {

			step = (float) i / iterations;
			offset = step * separation * (float) i;
			offsetX = offset * (x - 0.5f);
			offsetY = offset * (0.5f - y);

			glTexCoord2f (offsetX,offsetY+1);
			glVertex2f   (-offset,1+offset);

			glTexCoord2f (offsetX,offsetY);
			glVertex2f   (-offset,-offset);

			glTexCoord2f (offsetX+1,offsetY);
			glVertex2f   (1+offset,-offset);

			glTexCoord2f (offsetX+1,offsetY+1);
			glVertex2f   (1+offset,1+offset);
		}

		glEnd();
	}

	glDisable(GL_TEXTURE_2D);
}
