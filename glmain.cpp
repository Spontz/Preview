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

#include "glmain.h"

// ******************************************************************

#define BLEND_FUNC 10

int blendFunc[BLEND_FUNC] = {	GL_ZERO,
								GL_ONE,
								GL_DST_COLOR,
								GL_ONE_MINUS_DST_COLOR,
								GL_SRC_ALPHA,
								GL_ONE_MINUS_SRC_ALPHA,
								GL_DST_ALPHA,
								GL_ONE_MINUS_DST_ALPHA,
								GL_SRC_COLOR,
								GL_ONE_MINUS_SRC_COLOR
							};

char *blendName[BLEND_FUNC] = {	"ZERO",
								"ONE",
								"DST_COLOR",
								"ONE_MINUS_DST_COLOR",
								"SRC_ALPHA",
								"ONE_MINUS_SRC_ALPHA",
								"DST_ALPHA",
								"ONE_MINUS_DST_ALPHA",
								"SRC_COLOR",
								"ONE_MINUS_SRC_COLOR"
							};

// ******************************************************************

#define RENDER_MODES 13

char *renderName[RENDER_MODES] = {	"vertexes",
									"wireframe",
									"bounding_box",
									"bounding_sphere",
									"color",
									"flat",
									"shaded",
									"face_normals",
									"vertex_normals",
									"normals",
									"texture",
									"environment",
									"bump"
							};

// ******************************************************************

GLMain::GLMain(QWidget* parent, const char* name) : QGLWidget(parent, name) {

	scene = NULL;
	bkRed = bkGreen = bkBlue = 0; // 3DStudio -> 135
	xRot = yRot = zRot = 0.0f;
	xPos = yPos = zPos = 0.0f;
	displayOrigins = false;
	rotateOrigin = false;
	zDist = -500.0f;
	zNear = 0.1f;
	zFar = 4000.0f;
	fovy = 45;
	zSensivity = 1.0f;
	leftButton = rightButton = false;

	numLayers = 1;
	layerCount = 1;
	resetLayer(0, "Layer 1");

	updates = true;
	setAcceptDrops(true);
}

// ******************************************************************

GLMain::~GLMain() {
}

// ******************************************************************

void GLMain::dragEnterEvent(QDragEnterEvent *event) {

	event->accept(
		QUriDrag::canDecode(event)
	);
}

void GLMain::dropEvent(QDropEvent *event) {

	QStringList files;

	if (QUriDrag::decodeLocalFiles(event, files)) {
		if (loadObject(files[0])) {
			emit newDraggedFile();
		}
	}
}

// ******************************************************************

void GLMain::drawAxes() {

	glBegin(GL_LINES);
		glColor4f  (1.0f, 0.0f, 0.0f, 1.0f);
		glVertex3f (0.0f, 0.0f, 0.0f);
		glVertex3f (3*scaleNormal, 0.0f, 0.0f);

		glColor4f  (0.0f, 1.0f, 0.0f, 1.0f);
		glVertex3f (0.0f, 0.0f, 0.0f);
		glVertex3f (0.0f, 3*scaleNormal, 0.0f);

		glColor4f  (0.0f, 0.0f, 1.0f, 1.0f);
		glVertex3f (0.0f, 0.0f, 0.0f);
		glVertex3f (0.0f, 0.0f, 3*scaleNormal);
	glEnd();
}

// ******************************************************************

void GLMain::paintGL() {

	int i, j;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// disable texture by default
	glDisable(GL_TEXTURE_2D);

	if (scene == NULL) return;

	// setup projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective (fovy, (float) width / (float) height, zNear, zFar);

	// setup modelview matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0, 0, zDist);
	glRotatef(xRot, 1,0,0);
	glRotatef(yRot, 0,1,0);
	glRotatef(zRot, 0,0,1);

	// display world origin
	if (displayOrigins) drawAxes();

	// setup the rotation center and display object origin
	if (!rotateOrigin) {
		glTranslatef(xPos, yPos, zPos);
		if (displayOrigins) drawAxes();
	}
	else if (displayOrigins) {
		glPushMatrix();
		glTranslatef(-xPos, -yPos, -zPos);
		drawAxes();
		glPopMatrix();
	}

	// for LWOs
	if (scene->sourceFile == FILE_LWO) glScalef(-1,1,1);

	glEnable(GL_BLEND);

	// loop layers
	for (i=0; i<numLayers; i++) {

		// skip layer if disabled
		if (layers[i].disabled) continue;

		// set blending
		glBlendFunc(blendFunc[layers[i].srcBlend], blendFunc[layers[i].dstBlend]);

		float fred = layers[i].red/255.f;
		float fgreen = layers[i].green/255.f;
		float fblue = layers[i].blue/255.f;
		float falpha = layers[i].alpha/255.f;

		// set color
		glColor4f(fred, fgreen, fblue, falpha);

		if (layers[i].effectMode == 0) {

			// set smoothing
			if (layers[i].smooth) {
				glEnable(GL_POINT_SMOOTH);
				glEnable(GL_LINE_SMOOTH);
				glEnable(GL_POLYGON_SMOOTH);
			}

			// set culling
			switch (layers[i].cull) {
			case 0:
				glDisable(GL_CULL_FACE);
				break;
			case 1:
				glEnable(GL_CULL_FACE);
				glCullFace(GL_BACK);
				break;
			case 2:
				glEnable(GL_CULL_FACE);
				glCullFace(GL_FRONT);
				break;
			}

			// disable texture by default
			glDisable(GL_TEXTURE_2D);

			// prepare colors for use them if needed
			float ambient[4] = {0,0,0,1};
			float diffuse[4] = {fred, fgreen, fblue, 1};
			float specular[4] = {fred, fgreen, fblue, 1};

			switch (layers[i].renderMode) {

			case RM_VERTEXES:
				glPointSize(layers[i].width);
				glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
				render_onlyvertex3ds(scene);
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
				glPointSize(1.0f);
				break;

			case RM_WIREFRAME:
				glLineWidth(layers[i].width);
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
				render_vertex3ds(scene);
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
				glLineWidth(1.0f);
				break;

			case RM_BOUNDINGBOX:
				glLineWidth(layers[i].width);
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
				render_boundingbox(&scene->box);
				for (j=0; j<scene->meshobjs; j++) {
					if (scene->meshobjlist[j].verts > 0)
						render_boundingbox(&scene->meshobjlist[j].box);
				}
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
				glLineWidth(1.0f);
				break;

			case RM_BOUNDINGSPHERE:
				glLineWidth(layers[i].width);
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
				render_boundingsphere(&scene->sphere);
				for (j=0; j<scene->meshobjs; j++) {
					if (scene->meshobjlist[j].verts > 0)
						render_boundingsphere(&scene->meshobjlist[j].sphere);
				}
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
				glLineWidth(1.0f);
				break;

			case RM_COLOR:
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
				render_vertex3ds(scene);
				break;

			case RM_FLAT:
				glEnable(GL_LIGHTING);
				glEnable(GL_LIGHT0);
				glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
				glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
				glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
				glShadeModel(GL_FLAT);
				render_flat3ds(scene);
				glDisable(GL_LIGHT0);
				glDisable(GL_LIGHTING);
				break;

			case RM_SHADED:
				glEnable(GL_LIGHTING);
				glEnable(GL_LIGHT0);
				glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
				glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
				glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
				glShadeModel(GL_SMOOTH);
				render_smooth3ds(scene);
				glShadeModel(GL_FLAT);
				glDisable(GL_LIGHT0);
				glDisable(GL_LIGHTING);
				break;

			case RM_FACENORMALS:
				glLineWidth(layers[i].width);
				render_facenormals3ds(scene, scaleNormal);
				glLineWidth(1.0f);
				break;

			case RM_VERTEXNORMALS:
				glLineWidth(layers[i].width);
				render_vertexnormals3ds(scene, scaleNormal);
				glLineWidth(1.0f);
				break;

			case RM_ALLVERTEXNORMALS:
				glLineWidth(layers[i].width);
				render_allvertexnormals3ds(scene, scaleNormal);
				glLineWidth(1.0f);
				break;

			case RM_TEXTURE:
				glEnable(GL_TEXTURE_2D);
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
				render_texture3ds(scene);
				glDisable(GL_TEXTURE_2D);
				break;

			case RM_ENVIRONMENT:
				if (layers[i].texture == 0) break;
				glEnable(GL_TEXTURE_2D);
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
				glBindTexture(GL_TEXTURE_2D, layers[i].texture);
				glEnable(GL_TEXTURE_GEN_S);
				glEnable(GL_TEXTURE_GEN_T);
				glTexGenf(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
				glTexGenf(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
				render_normal3ds(scene);
				glDisable(GL_TEXTURE_GEN_S);
				glDisable(GL_TEXTURE_GEN_T);
				glDisable(GL_TEXTURE_2D);
				break;

			case RM_BUMP:
				if (layers[i].texture == 0) break;
				if (extensions) render_bump3ds(scene, layers[i].texture, cube_map);
				break;
			}

			// disable smoothing
			if (layers[i].smooth) {
				glDisable(GL_POINT_SMOOTH);
				glDisable(GL_LINE_SMOOTH);
				glDisable(GL_POLYGON_SMOOTH);
			}
		}
		else if (layers[i].effectMode == 1) {

			glDisable(GL_CULL_FACE);
			glDisable(GL_DEPTH_TEST);
			camera_set2d();

			switch (layers[i].filterMode) {

			case FM_BLACKWHITE:
				render_blackwhite(luminance);
				break;

			case FM_INVERT:
				render_invert();
				break;

			case FM_COLOR:
				render_color();
				break;

			case FM_ACCUMULATE:
				render_accumulate(rtt, layers[i].accum);
				break;

			case FM_HIGHPASSFILTER:
				render_highpassfilter(rtt, 1-fred, 1-fgreen, 1-fblue, layers[i].accum);
				break;

			case FM_BOXBLUR:
				render_boxblur(rtt, layers[i].radius);
				break;

			case FM_GLOW:
				render_glow(rtt, rtt_tmp, 1-fred, 1-fgreen, 1-fblue, layers[i].accum, layers[i].radius);
				break;

			case FM_RADIALBLUR:
				render_radialblur(rtt, layers[i].accum2, layers[i].recursive, falpha, layers[i].radius/200.f, 0.5f, 0.5f);
				break;

			case FM_RADIALGLOW:
				render_radialglow(rtt, rtt_tmp, 1-fred, 1-fgreen, 1-fblue, layers[i].accum, layers[i].accum2, layers[i].recursive, falpha, layers[i].radius/200.f, 0.5f, 0.5f, blendFunc[layers[i].srcBlend], blendFunc[layers[i].dstBlend]);
				break;
			}

			camera_restore();
			glEnable(GL_DEPTH_TEST);
		}
	}

	glDisable(GL_BLEND);
}

// ******************************************************************

void GLMain::setTextureParameters(GLint min_filter) {

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, min_filter);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
}

// ******************************************************************

void GLMain::initializeGL() {

	// temporary buffer
	char *tex;

	// cube map texture
	extensions = setup_extensions();
	if (extensions) cube_map = setup_normalizationCubeMap();

	// rtt texture
	glGenTextures(1, &rtt);
	glBindTexture(GL_TEXTURE_2D, rtt);
	setTextureParameters(GL_LINEAR);
	tex = (char *) malloc(512*512*3);
	memset(tex, 0, 512*512*3);
	glTexImage2D (GL_TEXTURE_2D, 0, 3, 512, 512, 0, GL_RGB, GL_UNSIGNED_BYTE, tex);
	free(tex);

	// rtt backup texture
	glGenTextures(1, &rtt_tmp);
	glBindTexture(GL_TEXTURE_2D, rtt_tmp);
	setTextureParameters(GL_LINEAR);
	tex = (char *) malloc(512*512*3);
	memset(tex, 0, 512*512*3);
	glTexImage2D (GL_TEXTURE_2D, 0, 3, 512, 512, 0, GL_RGB, GL_UNSIGNED_BYTE, tex);
	free(tex);

	// luminance texture
	glGenTextures(1, &luminance);
	glBindTexture(GL_TEXTURE_2D, luminance);
	setTextureParameters(GL_LINEAR);
	tex = (char *) malloc(512*512);
	memset(tex, 0, 512*512);
	glTexImage2D (GL_TEXTURE_2D, 0, 1, 512, 512, 0, GL_LUMINANCE, GL_UNSIGNED_BYTE, tex);
	free(tex);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	glClearColor(bkRed/255.f, bkGreen/255.f, bkBlue/255.f, 0);
}

// ******************************************************************

void GLMain::resizeGL(int w, int h) {

	glViewport(0, 0, (GLint) w, (GLint) h);
	width = w;
	height = h;
}

// ******************************************************************

GLuint GLMain::uploadTexture(QImage tex) {

	GLuint texture;

	glEnable(GL_TEXTURE_2D);
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	setTextureParameters(GL_LINEAR_MIPMAP_NEAREST);

	QImage gltex = QGLWidget::convertToGLFormat(tex);
	gluBuild2DMipmaps(GL_TEXTURE_2D, gltex.depth()/8, gltex.width(), gltex.height(),
						(gltex.depth()==24 ? GL_RGB : GL_RGBA), GL_UNSIGNED_BYTE, gltex.bits());

	return texture;
}

// ******************************************************************

int GLMain::loadObject(QString s) {

	H3dsScene *tmp;

	QString path = s;
	path.truncate(s.findRev('/')+1);
	file = s.section('/', -1);

	tmp = model_load((char *) s.ascii());
	if (tmp == NULL) {
		QMessageBox::critical(this,"Error","Unable to load file\nOnly 3DS and LWO2 are supported",
				QMessageBox::Ok,QMessageBox::NoButton,QMessageBox::NoButton);
		return 0;
	}

	H3dsMaterial *mat = tmp->materials;
	while (mat) {

		if (mat->hTex > 0) {

			QImage tex = QImage(QString(path + mat->TexFilename), 0);
			if (!tex.isNull()) mat->hTex = uploadTexture(tex);
			else {
				mat->hTex = 0;
				QMessageBox::warning(this,"Warning",QString("Texture '%1' not found").arg(mat->TexFilename),
						QMessageBox::Ok,QMessageBox::NoButton,QMessageBox::NoButton);
			}
		}
		mat = (H3dsMaterial*) mat->next;
	}

	// update camera and field of view parameters
	xPos = -tmp->sphere.center[0];
	yPos = -tmp->sphere.center[1];
	zPos = -tmp->sphere.center[2];
	// for LWOs
	if (tmp->sourceFile == FILE_LWO) xPos = -xPos;

	xRot = yRot = zRot = 0.0f;

	// camera distance
	zDist = -tmp->sphere.radius / tan((fovy/2.0f) * 3.1415926535f / 180.0f);

	// length of the normals
	scaleNormal = tmp->sphere.radius / 40.0f;

	// mouse sensivity in zoom
	float rz = tmp->box.max[2] - tmp->box.min[2];
	zSensivity = rz / 200.0f;

	// update scene
	if (scene != NULL) model_free(scene);
	scene = tmp;

	return 1;
}

// ******************************************************************

QString GLMain::getInfo(bool *warn) {

	if (!scene) {
		*warn = true;
		return "No object loaded";
	}

	QString result = file + QString("\nMeshes: %1\nFaces: %2\nVertexes: %3")
						.arg(scene->meshobjs)
						.arg(scene->faces)
						.arg(scene->vertexes);

	QString warns = NULL;
	if (scene->hasUnknownPolys) warns += "\nUnknown polygons";
	if (scene->hasNonTriangles) warns += "\nNot only triangles";
	if (scene->hasUnknownTexmaps) warns += "\nUnknown texture maps";

	if (warns != NULL) {
		result += "\n" + warns;
		*warn = true;
	} else *warn = false;

	return result;
}

// ******************************************************************

bool GLMain::getExtensions() {
	return extensions;
}

// ******************************************************************

QString GLMain::getExtensionsInfo() {

	QString result = QString("Vendor: %1\nRenderer: %2\nVersion: %3")
						.arg((char *) glGetString(GL_VENDOR))
						.arg((char *) glGetString(GL_RENDERER))
						.arg((char *) glGetString(GL_VERSION));

	if (extensions) result += "\n\nAll needed extensions are available";
	else result += "\n\nNOT using extensions";

	return result;
}

// ******************************************************************

QString GLMain::getViewInfo() {

	QString result = QString("Distance: %1\n").arg(-zDist);
	result += QString("Scaling Factor: %1\n\n").arg(scaleNormal);
	result += QString("Center X: %1\nCenter Y: %2\nCenter Z: %3\n\n")
						.arg(xPos)
						.arg(yPos)
						.arg(zPos);
	result += QString("Rotation X: %1\nRotation Y: %2\nRotation Z: %3")
						.arg(xRot)
						.arg(yRot)
						.arg(zRot);

	return result;
}

// ******************************************************************

void GLMain::setBackgroundColor(QColor color) {
	bkRed = color.red();
	bkGreen = color.green();
	bkBlue = color.blue();
	glClearColor(bkRed/255.f, bkGreen/255.f, bkBlue/255.f, 0);
}

QColor GLMain::getBackgroundColor() {
	return QColor(bkRed, bkGreen, bkBlue);
}

// ******************************************************************

void GLMain::toggleDisplayOrigins(bool value) {
	displayOrigins = value;
}

// ******************************************************************

void GLMain::toggleRotateOrigin(bool value) {
	rotateOrigin = value;
}

// ******************************************************************

float GLMain::benchmark() {

	GLfloat rot, oldRot = yRot;

	QTime time1 = QTime::currentTime();
	for (rot = 0.0f; rot <= 360.0f; rot += 2.0f) {
		yRot = oldRot + rot;
		updateGL();
	}
	QTime time2 = QTime::currentTime();
	yRot = oldRot;

	int msecs = time1.msecsTo(time2);
	return 1000.0f * 181.0f / (float) msecs;
}

// ******************************************************************

void GLMain::getKeyValue(char *line, char *key, char *value) {

	char *s = line;

	// read spaces or tabs
	while ((s[0] == ' ') || (s[0] == '\t')) {
		s++;
	}

	// get key
	while ((s[0] != ' ') && (s[0] != '\t')) {
		key++[0] = s++[0];
	}
	key[0] = 0;

	// read spaces or tabs
	while ((s[0] == ' ') || (s[0] == '\t')) {
		s++;
	}

	// get value
	while ((s[0] != 0) && ((s[0] != '\n') && (s[0] != '\r'))) {
		value++[0] = s++[0];
	}
	value[0] = 0;
}

// ******************************************************************

void GLMain::loadLayers(const QString &file) {

	char line[256], key[64], value[256];
	int layer = 0;

	// get path of the file
	QString path = file;
	path.truncate(file.findRev('/')+1);

	FILE *f = fopen(file, "rt");

	for (;;) {

		if (fgets(line,256,f) == NULL) break;
		if ((line[0] == ';') || (line[0] == '\n') || (line[0] == '\r')) continue;

		if (line[0] == '{') {
			if (layer < MAX_LAYERS) resetLayer(layer, "Unknown");
			else break;
		}
		else if (line[0] == '}') {
			layer++;
		}
		else {
			getKeyValue(line, key, value);
			if (strcasecmp(key, "name") == 0) layers[layer].name = QString(value);
			else if (strcasecmp(key, "disabled") == 0) layers[layer].disabled = true;
			else if (strcasecmp(key, "blend") == 0) {
				sscanf(value, "%d %d", &layers[layer].srcBlend, &layers[layer].dstBlend);
			}
			else if (strcasecmp(key, "color") == 0) {
				sscanf(value, "%d %d %d %d", &layers[layer].red, &layers[layer].green,
											&layers[layer].blue, &layers[layer].alpha);
			}
			else if (strcasecmp(key, "effect") == 0) layers[layer].effectMode = atoi(value);
			else if (strcasecmp(key, "rendermode") == 0) layers[layer].renderMode = atoi(value);
			else if (strcasecmp(key, "width") == 0) layers[layer].width = atof(value);
			else if (strcasecmp(key, "smooth") == 0) layers[layer].smooth = true;
			else if (strcasecmp(key, "cull") == 0) layers[layer].cull = atoi(value);
			else if (strcasecmp(key, "texture") == 0) {
				QImage tex = QImage(QString(path + value), 0);
				if (tex.isNull()) {
					QMessageBox::warning(this,"Warning",QString("Texture '%1' not found").arg(QString(path + value)),
							QMessageBox::Ok,QMessageBox::NoButton,QMessageBox::NoButton);
				}
				else loadTexture(layer, tex, value);
			}
			else if (strcasecmp(key, "filtermode") == 0) layers[layer].filterMode = atoi(value);
			else if (strcasecmp(key, "radius") == 0) layers[layer].radius = atof(value);
			else if (strcasecmp(key, "accum") == 0) layers[layer].accum = atoi(value);
			else if (strcasecmp(key, "accum2") == 0) layers[layer].accum2 = atoi(value);
			else if (strcasecmp(key, "recursive") == 0) layers[layer].recursive = true;
			else {
				QMessageBox::warning(this,"Warning",QString("Unknown variable '%1' in file").arg(key),
						QMessageBox::Ok,QMessageBox::NoButton,QMessageBox::NoButton);
			}
		}
	}

	fclose(f);

	// if empty layers file
	if (layer == 0) {
		resetLayer(0, "Layer 1");
		layer = 1;
	}

	// update counters
	numLayers = layer;
	layerCount = layer;
}

// ******************************************************************

void GLMain::saveLayers(const QString &file) {

	FILE *f = fopen(file, "wt");

	for (int i=0; i<numLayers; i++) {

		fprintf(f,"{\n");
		fprintf(f,QString("\tname %1\n").arg(layers[i].name));
		if (layers[i].disabled) fprintf(f,"\tdisabled 1\n");

		fprintf(f,"\tblend %d %d\n", layers[i].srcBlend, layers[i].dstBlend);
		fprintf(f,"\tcolor %d %d %d %d\n", layers[i].red, layers[i].green, layers[i].blue, layers[i].alpha);
		fprintf(f,"\teffect %d\n", layers[i].effectMode);

		if (layers[i].effectMode == 0) {
			fprintf(f,"\trendermode %d\n", layers[i].renderMode);
			fprintf(f,"\twidth %f\n", layers[i].width);
			if (layers[i].smooth) fprintf(f,"\tsmooth 1\n");
			fprintf(f,"\tcull %d\n", layers[i].cull);
			if (layers[i].textureFile) fprintf(f,QString("\ttexture %1\n").arg(layers[i].textureFile));
		}
		else if (layers[i].effectMode == 1) {
			fprintf(f,"\tfiltermode %d\n", layers[i].filterMode);
			fprintf(f,"\tradius %f\n", layers[i].radius);
			fprintf(f,"\taccum %d\n", layers[i].accum);
			fprintf(f,"\taccum2 %d\n", layers[i].accum2);
			if (layers[i].recursive) fprintf(f,"\trecursive 1\n");
		}

		fprintf(f,"}\n");
	}

	fclose(f);
}

// ******************************************************************

void GLMain::exportLayers() {

	FILE *f;
	int i;

	// generate a file with all the object layers
	f = fopen("object.layer", "wt");

	for (i=0; i<numLayers; i++) {

		// is disabled?
		if (layers[i].disabled) continue;

		// is an render mode?
		if (layers[i].effectMode != 0) continue;

		float fred = layers[i].red/255.f;
		float fgreen = layers[i].green/255.f;
		float fblue = layers[i].blue/255.f;
		float falpha = layers[i].alpha/255.f;

		// export the layer!
		fprintf(f,"{\r\n");
		fprintf(f,"\tblend %s %s\r\n", blendName[layers[i].srcBlend], blendName[layers[i].dstBlend]);

		fprintf(f,"\tmode %s\r\n", renderName[layers[i].renderMode]);

		if (layers[i].cull == 1) fprintf(f,"\tcullface back\r\n");
		else if (layers[i].cull == 2) fprintf(f,"\tcullface front\r\n");

		fprintf(f,"\tcolor %f %f %f %f\r\n", fred, fgreen, fblue, falpha);

		switch (layers[i].renderMode) {

		case RM_VERTEXES:
			fprintf(f,"\tlinewidth %f\r\n", layers[i].width);
			break;

		case RM_WIREFRAME:
			fprintf(f,"\tlinewidth %f\r\n", layers[i].width);
			break;

		case RM_BOUNDINGBOX:
			fprintf(f,"\tlinewidth %f\r\n", layers[i].width);
			break;

		case RM_COLOR:
			break;

		case RM_FLAT:
			break;

		case RM_SHADED:
			break;

		case RM_FACENORMALS:
			fprintf(f,"\tlinewidth %f\r\n", layers[i].width);
			break;

		case RM_VERTEXNORMALS:
			fprintf(f,"\tlinewidth %f\r\n", layers[i].width);
			break;

		case RM_ALLVERTEXNORMALS:
			fprintf(f,"\tlinewidth %f\r\n", layers[i].width);
			break;

		case RM_TEXTURE:
			break;

		case RM_ENVIRONMENT:
			fprintf(f,QString("\ttexture %1\r\n").arg(layers[i].textureFile));
			break;

		case RM_BUMP:
			fprintf(f,QString("\ttexture %1\r\n").arg(layers[i].textureFile));
			break;
		}

		fprintf(f,"}\r\n");
	}

	fclose(f);

	// generate a file with all the effects
	f = fopen("effects.spo", "wt");
	int effectLayer = 1;

	for (i=0; i<numLayers; i++) {

		// is disabled?
		if (layers[i].disabled) continue;

		// is an effect?
		if (layers[i].effectMode != 1) continue;

		float fred = layers[i].red/255.f;
		float fgreen = layers[i].green/255.f;
		float fblue = layers[i].blue/255.f;
		float falpha = layers[i].alpha/255.f;

		// export the effect!
		switch (layers[i].filterMode) {

		case FM_BLACKWHITE:
			fprintf(f,"[efxBlackWhite]\n");
			break;

		case FM_INVERT:
			fprintf(f,"[efxInverse]\n");
			break;

		case FM_HIGHPASSFILTER:
			fprintf(f,"[efxHighPassFilter]\n");
			fprintf(f,"fThreshold %f %f %f\n", 1-fred, 1-fgreen, 1-fblue);
			fprintf(f,"fAccum %d\n", layers[i].accum);
			break;

		case FM_BOXBLUR:
			fprintf(f,"[efxBoxBlur]\n");
			fprintf(f,"fRadius %f\n", layers[i].radius);
			break;

		case FM_GLOW:
			fprintf(f,"[efxGlow]\n");
			fprintf(f,"fThreshold %f %f %f\n", 1-fred, 1-fgreen, 1-fblue);
			fprintf(f,"fAccum %d\n", layers[i].accum);
			fprintf(f,"fRadius %f\n", layers[i].radius);
			break;

		case FM_RADIALBLUR:
			fprintf(f,"[efxRadialBlur]\n");

			fprintf(f,"fIterations %d\n", layers[i].accum2);
			if (layers[i].recursive) fprintf(f,"fRecursive 1\n");
			else fprintf(f,"fRecursive 0\n");

			fprintf(f,"fAlpha1 %f\n", falpha);
			fprintf(f,"fAlpha2 %f\n", falpha);

			fprintf(f,"fSeparation1 %f\n", layers[i].radius/200.f);
			fprintf(f,"fSeparation2 %f\n", layers[i].radius/200.f);

			fprintf(f,"fPosX1 %f\n", 0.5f);
			fprintf(f,"fPosY1 %f\n", 0.5f);
			fprintf(f,"fPosX2 %f\n", 0.5f);
			fprintf(f,"fPosY2 %f\n", 0.5f);
			break;

		case FM_RADIALGLOW:
			fprintf(f,"[efxRadialGlow]\n");

			fprintf(f,"fThreshold %f %f %f\n", 1-fred, 1-fgreen, 1-fblue);
			fprintf(f,"fAccum %d\n", layers[i].accum);

			fprintf(f,"fIterations %d\n", layers[i].accum2);
			if (layers[i].recursive) fprintf(f,"fRecursive 1\n");
			else fprintf(f,"fRecursive 0\n");

			fprintf(f,"fAlpha1 %f\n", falpha);
			fprintf(f,"fAlpha2 %f\n", falpha);

			fprintf(f,"fSeparation1 %f\n", layers[i].radius/200.f);
			fprintf(f,"fSeparation2 %f\n", layers[i].radius/200.f);

			fprintf(f,"fPosX1 %f\n", 0.5f);
			fprintf(f,"fPosY1 %f\n", 0.5f);
			fprintf(f,"fPosX2 %f\n", 0.5f);
			fprintf(f,"fPosY2 %f\n", 0.5f);
			break;
		}

		fprintf(f,"layer %d\n", effectLayer++);
		fprintf(f,"\n");
	}

	fclose(f);
}

// ******************************************************************

void GLMain::mousePressEvent(QMouseEvent* e) {

	mouse = e->pos();
	if (e->button() == LeftButton) leftButton = true;
	if (e->button() == RightButton) rightButton = true;
}

void GLMain::mouseReleaseEvent(QMouseEvent* e) {

	leftButton = rightButton = false;
}

void GLMain::mouseMoveEvent(QMouseEvent* e) {

	QPoint current = e->pos();

	if (leftButton) {
		yRot += (current.x() - mouse.x()) * 0.5f;
		xRot += (current.y() - mouse.y()) * 0.5f;
	}
	if (rightButton) {
		zDist += (current.y() - mouse.y()) * zSensivity;
		if (zDist > 0.0f) zDist = 0.0f;
	}

	mouse = current;
	updateGL();
}

// ******************************************************************

int GLMain::addLayer(const QString &text) {

	if (numLayers < MAX_LAYERS) {
		resetLayer(numLayers, text);
		numLayers++;
		layerCount++;
		return 1;
	}
	else return 0;
}

void GLMain::removeLayer(int layer) {

	numLayers--;
	for (int i=layer; i<numLayers; i++) {
		layers[i] = layers[i+1];
	}
}

int GLMain::getLayerCount() {

	return layerCount;
}

void GLMain::upLayer(int layer) {

	t_layer tmp = layers[layer];
	layers[layer] = layers[layer-1];
	layers[layer-1] = tmp;
}

void GLMain::downLayer(int layer) {

	t_layer tmp = layers[layer];
	layers[layer] = layers[layer+1];
	layers[layer+1] = tmp;
}

void GLMain::resetLayer(int layer, const QString &text) {

	layers[layer].name = text;
	layers[layer].disabled = false;

	layers[layer].srcBlend = 1;
	layers[layer].dstBlend = 0;

	layers[layer].red = 191;
	layers[layer].green = 191;
	layers[layer].blue = 191;
	layers[layer].alpha = 255;

	layers[layer].effectMode = 0;

	layers[layer].renderMode = 0;
	layers[layer].width = 1.0f;
	layers[layer].smooth = false;
	layers[layer].cull = 0;
	layers[layer].image = QImage();
	layers[layer].texture = 0;
	layers[layer].textureFile = QString();

	layers[layer].filterMode = 0;
	layers[layer].radius = 0;
	layers[layer].accum = 0;
	layers[layer].accum2 = 0;
	layers[layer].recursive = false;
}

// ******************************************************************

void GLMain::setUpdates(bool update) {
	updates = update;
}

void GLMain::update() {
	if (updates) updateGL();
}

// ******************************************************************

void GLMain::setName(int layer, const QString &text) {
	layers[layer].name = text;
}

QString GLMain::getName(int layer) {
	return layers[layer].name;
}

void GLMain::setDisabled(int layer, bool flag) {
	layers[layer].disabled = flag;
}

bool GLMain::getDisabled(int layer) {
	return layers[layer].disabled;
}

// ******************************************************************

void GLMain::setSrcBlend(int layer, int mode) {
	layers[layer].srcBlend = mode;
}

int GLMain::getSrcBlend(int layer) {
	return layers[layer].srcBlend;
}

void GLMain::setDstBlend(int layer, int mode) {
	layers[layer].dstBlend = mode;
}

int GLMain::getDstBlend(int layer) {
	return layers[layer].dstBlend;
}

// ******************************************************************

void GLMain::setRed(int layer, int color) {
	layers[layer].red = color;
}

void GLMain::setGreen(int layer, int color) {
	layers[layer].green = color;
}

void GLMain::setBlue(int layer, int color) {
	layers[layer].blue = color;
}

void GLMain::setAlpha(int layer, int color) {
	layers[layer].alpha = color;
}

// ******************************************************************

void GLMain::setColor(int layer, QRgb color) {
	layers[layer].red = qRed(color);
	layers[layer].green = qGreen(color);
	layers[layer].blue = qBlue(color);
	layers[layer].alpha = qAlpha(color);
}

QRgb GLMain::getColor(int layer) {
	return qRgba(	layers[layer].red,
					layers[layer].green,
					layers[layer].blue,
					layers[layer].alpha);
}

// ******************************************************************

void GLMain::setEffectMode(int layer, int mode) {
	layers[layer].effectMode = mode;
}

int GLMain::getEffectMode(int layer) {
	return layers[layer].effectMode;
}

// ******************************************************************

void GLMain::setRenderMode(int layer, int mode) {
	layers[layer].renderMode = mode;
}

int GLMain::getRenderMode(int layer) {
	return layers[layer].renderMode;
}

void GLMain::setWidth(int layer, int width) {
	layers[layer].width = (GLfloat) (width) / 10.f;
}

int GLMain::getWidth(int layer) {
	return (int) (layers[layer].width * 10.0f);
}

void GLMain::setSmooth(int layer, bool flag) {
	layers[layer].smooth = flag;
}

bool GLMain::getSmooth(int layer) {
	return layers[layer].smooth;
}

void GLMain::setCull(int layer, int mode) {
	layers[layer].cull = mode;
}

int GLMain::getCull(int layer) {
	return layers[layer].cull;
}

void GLMain::loadTexture(int layer, QImage tex, const QString &file) {
	layers[layer].image = tex;
	layers[layer].textureFile = file.section('/', -1);
	layers[layer].texture = uploadTexture(tex);
}

QImage GLMain::getTexture(int layer) {
	return layers[layer].image;
}

// ******************************************************************

void GLMain::setFilterMode(int layer, int mode) {
	layers[layer].filterMode = mode;
}

int GLMain::getFilterMode(int layer) {
	return layers[layer].filterMode;
}

void GLMain::setRadius(int layer, int radius) {
	layers[layer].radius = (float) radius;
}

int GLMain::getRadius(int layer) {
	return (int) layers[layer].radius;
}

void GLMain::setAccum(int layer, int accum) {
	layers[layer].accum = accum;
}

int GLMain::getAccum(int layer) {
	return layers[layer].accum;
}

void GLMain::setAccum2(int layer, int accum) {
	layers[layer].accum2 = accum;
}

int GLMain::getAccum2(int layer) {
	return layers[layer].accum2;
}

void GLMain::setRecursive(int layer, bool flag) {
	layers[layer].recursive = flag;
}

bool GLMain::getRecursive(int layer) {
	return layers[layer].recursive;
}
