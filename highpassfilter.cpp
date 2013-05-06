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

void render_highpassfilter_noext (float threshold_R, float threshold_G, float threshold_B) {

	// invert color buffer
	glBlendFunc (GL_ONE_MINUS_DST_COLOR, GL_ZERO);
	glColor4f (1,1,1,1);
	screenquad ();

	// add the threshold
	glBlendFunc (GL_ONE, GL_ONE);
	glColor4f (threshold_R, threshold_G, threshold_B, 1);
	screenquad ();

	// invert color buffer
	glBlendFunc (GL_ONE_MINUS_DST_COLOR, GL_ZERO);
	glColor4f (1,1,1,1);
	screenquad ();
}

// ******************************************************************

void render_highpassfilter_ext (float threshold_R, float threshold_G, float threshold_B) {

	// substract the threshold
	glBlendFunc (GL_ONE, GL_ONE);
	glBlendEquationEXT (GL_FUNC_REVERSE_SUBTRACT_EXT);
	glColor4f (threshold_R, threshold_G, threshold_B, 0);
	screenquad ();
	glBlendEquationEXT (GL_FUNC_ADD_EXT);
}

// ******************************************************************

void render_highpassfilter (int tex, float threshold_R, float threshold_G, float threshold_B, int accum) {

	// disable texturing
	glDisable(GL_TEXTURE_2D);

	// highpass color filter itself
	if (extensions) render_highpassfilter_ext(threshold_R, threshold_G, threshold_B);
	else render_highpassfilter_noext(threshold_R, threshold_G, threshold_B);

	// accumulate color buffer
	glBlendFunc(GL_ONE, GL_ONE);
	glColor4f(1,1,1,1);
	render_accumulate(tex, accum);
}
