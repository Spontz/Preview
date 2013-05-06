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

void drawOffsetQuad(float offsetX, float offsetY, float alpha) {

	glColor4f(0,0,0,alpha);

	glTexCoord2f(0+offsetX,0+offsetY);
	glVertex2f(0,0);

	glTexCoord2f(1+offsetX,0+offsetY);
	glVertex2f(1,0);

	glTexCoord2f(1+offsetX,1+offsetY);
	glVertex2f(1,1);

	glTexCoord2f(0+offsetX,1+offsetY);
	glVertex2f(0,1);
}

// ******************************************************************

void drawOffsetQuadMulti(float offsetX, float offsetY) {

	glMultiTexCoord2fARB(GL_TEXTURE0_ARB, 0+offsetX, 0+offsetY);
	glMultiTexCoord2fARB(GL_TEXTURE1_ARB, 0-offsetX, 0-offsetY);
	glVertex2f(0,0);

	glMultiTexCoord2fARB(GL_TEXTURE0_ARB, 1+offsetX, 0+offsetY);
	glMultiTexCoord2fARB(GL_TEXTURE1_ARB, 1-offsetX, 0-offsetY);
	glVertex2f(1,0);

	glMultiTexCoord2fARB(GL_TEXTURE0_ARB, 1+offsetX, 1+offsetY);
	glMultiTexCoord2fARB(GL_TEXTURE1_ARB, 1-offsetX, 1-offsetY);
	glVertex2f(1,1);

	glMultiTexCoord2fARB(GL_TEXTURE0_ARB, 0+offsetX, 1+offsetY);
	glMultiTexCoord2fARB(GL_TEXTURE1_ARB, 0-offsetX, 1-offsetY);
	glVertex2f(0,1);
}

// ******************************************************************

void render_boxblur_noext (int tex, float radius) {

	float pixelX, pixelY;
	float nOffset;

	// vanilla OpenGL
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tex);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	nOffset = 1.0f;
	pixelX = nOffset / 512.0f;
	pixelY = nOffset / 512.0f;

	for (;;) {

		copyColorBuffer();
		glBegin(GL_QUADS);
			drawOffsetQuad(-pixelX, 0, 0.50f);
			drawOffsetQuad(+pixelX, 0, 0.33f);
		glEnd();

		copyColorBuffer();
		glBegin(GL_QUADS);
			drawOffsetQuad(0, -pixelY, 0.50f);
			drawOffsetQuad(0, +pixelY, 0.33f);
		glEnd();

		if (nOffset < radius) {
			nOffset *= 2;
			if (nOffset > radius) nOffset = radius;
			pixelX = nOffset / 512.0f;
			pixelY = nOffset / 512.0f;
		}
		else break;
	}

	glDisable(GL_TEXTURE_2D);
}

// ******************************************************************

void render_boxblur_ext (int tex, float radius) {

	float color[4] = {0.5f,0.5f,0.5f,0.5f};
	float pixelX, pixelY;
	float nOffset;

	multitex_enable(GL_TEXTURE0_ARB);
	glBindTexture(GL_TEXTURE_2D, tex);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	copyColorBuffer();

	multitex_enable(GL_TEXTURE1_ARB);
	glBindTexture(GL_TEXTURE_2D, tex);
	glTexEnvfv(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, color);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_COMBINE_ARB);
	glTexEnvi(GL_TEXTURE_ENV, GL_SOURCE0_RGB_ARB, GL_PREVIOUS_ARB);
	glTexEnvi(GL_TEXTURE_ENV, GL_SOURCE0_ALPHA_ARB, GL_CONSTANT_ARB);
	glTexEnvi(GL_TEXTURE_ENV, GL_SOURCE1_RGB_ARB, GL_TEXTURE);
	glTexEnvi(GL_TEXTURE_ENV, GL_SOURCE2_RGB_ARB, GL_CONSTANT_ARB);
	glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_RGB_ARB, GL_INTERPOLATE_ARB);
	glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_ALPHA_ARB, GL_REPLACE);

	glColor4f(1,1,1,0.33f);

	nOffset = 1.0f;
	pixelX = nOffset / 512.0f;
	pixelY = nOffset / 512.0f;

	for (;;) {

		copyColorBuffer();
		glBegin(GL_QUADS);
			drawOffsetQuadMulti(+pixelX, 0);
		glEnd();

		copyColorBuffer();
		glBegin(GL_QUADS);
			drawOffsetQuadMulti(0, +pixelY);
		glEnd();

		if (nOffset < radius) {
			nOffset *= 2;
			if (nOffset > radius) nOffset = radius;
			pixelX = nOffset / 512.0f;
			pixelY = nOffset / 512.0f;
		}
		else break;
	}

	multitex_disable(GL_TEXTURE1_ARB);
	multitex_disable(GL_TEXTURE0_ARB);
}

// ******************************************************************

void render_boxblur (int tex, float radius) {

	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	if (extensions) render_boxblur_ext (tex, radius);
	else render_boxblur_noext (tex, radius);
}
