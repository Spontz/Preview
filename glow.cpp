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

void render_glow (int tex, int backuptex, float threshold_R, float threshold_G, float threshold_B, int accum, float radius) {

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, backuptex);
	copyColorBuffer();
	render_highpassfilter(tex, threshold_R, threshold_G, threshold_B, accum);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	render_boxblur(tex, radius);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, backuptex);
	glBlendFunc(GL_ONE, GL_ONE);
	glColor4f(1,1,1,1);
	texscreenquad();
	glDisable(GL_TEXTURE_2D);
}
