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

#ifndef GLMAIN_H
#define GLMAIN_H

// ******************************************************************

#include <qgl.h>
#include <qimage.h>
#include <qmessagebox.h>
#include <qdragobject.h>
#include <qdatetime.h>

#include <math.h>

#include "extensions.h"
#include "utils.h"

#include "3dsdraw.h"
#include "filters.h"

// ******************************************************************

#define RM_VERTEXES			0
#define RM_WIREFRAME		1
#define RM_BOUNDINGBOX		2
#define RM_BOUNDINGSPHERE	3
#define RM_COLOR			4
#define RM_FLAT				5
#define RM_SHADED			6
#define RM_FACENORMALS		7
#define RM_VERTEXNORMALS	8
#define RM_ALLVERTEXNORMALS	9
#define RM_TEXTURE			10
#define RM_ENVIRONMENT		11
#define RM_BUMP				12

// ******************************************************************

#define FM_BLACKWHITE		0
#define FM_INVERT			1
#define FM_HIGHPASSFILTER	2
#define FM_BOXBLUR			3
#define FM_GLOW				4
#define FM_RADIALBLUR		5
#define FM_RADIALGLOW		6
#define FM_COLOR			7
#define FM_ACCUMULATE		8

// ******************************************************************

#define MAX_LAYERS 32

typedef struct {

	QString name;
	bool disabled;

	// blending func mode
	int srcBlend, dstBlend;

	// color and alpha
	int red, green, blue, alpha;

	// kind of layer
	int effectMode;

	// for render mode
	int renderMode;
	GLfloat width;
	bool smooth;
	int cull;
	QImage image;
	GLuint texture;
	QString textureFile;

	// for filter mode
	int filterMode;
	float radius;
	int accum, accum2;
	bool recursive;

} t_layer;

// ******************************************************************

class GLMain:public QGLWidget {

	Q_OBJECT

public:
	GLMain(QWidget* parent, const char* name);
	~GLMain();

	void dragEnterEvent(QDragEnterEvent *event);
	void dropEvent(QDropEvent *event);

public slots:
	// general
	int loadObject(QString s);
	QString getInfo(bool *warn);

	bool getExtensions();
	QString getExtensionsInfo();

	QString getViewInfo();

	void setBackgroundColor(QColor color);
	QColor getBackgroundColor();

	void toggleDisplayOrigins(bool value);
	void toggleRotateOrigin(bool value);

	float benchmark();

	void loadLayers(const QString &file);
	void saveLayers(const QString &file);
	void exportLayers();

	void mousePressEvent(QMouseEvent *e);
	void mouseReleaseEvent(QMouseEvent *e);
	void mouseMoveEvent(QMouseEvent *e);

	// layers
	int addLayer(const QString &text);
	void removeLayer(int layer);
	int getLayerCount();
	void upLayer(int layer);
	void downLayer(int layer);
	void resetLayer(int layer, const QString &text);

	// render viewport
	void setUpdates(bool update);
	void update();

	void setName(int layer, const QString &text);
	QString getName(int layer);

	void setDisabled(int layer, bool flag);
	bool getDisabled(int layer);

	void setSrcBlend(int layer, int mode);
	int getSrcBlend(int layer);
	void setDstBlend(int layer, int mode);
	int getDstBlend(int layer);

	void setRed(int layer, int color);
	void setGreen(int layer, int color);
	void setBlue(int layer, int color);
	void setAlpha(int layer, int color);

	void setColor(int layer, QRgb color);
	QRgb getColor(int layer);

	void setEffectMode(int layer, int mode);
	int getEffectMode(int layer);

	// render mode
	void setRenderMode(int layer, int mode);
	int getRenderMode(int layer);

	void setSmooth(int layer, bool flag);
	bool getSmooth(int layer);

	void setWidth(int layer, int width);
	int getWidth(int layer);

	void setCull(int layer, int mode);
	int getCull(int layer);

	void loadTexture(int layer, QImage tex, const QString &file);
	QImage getTexture(int layer);

	// filter mode
	void setFilterMode(int layer, int mode);
	int getFilterMode(int layer);

	void setRadius(int layer, int radius);
	int getRadius(int layer);

	void setAccum(int layer, int accum);
	int getAccum(int layer);

	void setAccum2(int layer, int accum);
	int getAccum2(int layer);

	void setRecursive(int layer, bool flag);
	bool getRecursive(int layer);

signals:
	void newDraggedFile();

protected:
	void initializeGL();
	void paintGL();
	void resizeGL(int w, int h);
	void getKeyValue(char *line, char *key, char *value);
	void drawAxes();
	void setTextureParameters(GLint min_filter);
	GLuint uploadTexture(QImage tex);

private:
	// object
	QString file;
	H3dsScene *scene;

	// widget width and height
	int width, height;

	// internal textures
	GLuint cube_map, rtt, rtt_tmp, luminance;

	// object rotation
	GLfloat xRot, yRot, zRot;

	// origin of the rotation
	GLfloat xPos, yPos, zPos;
	bool displayOrigins, rotateOrigin;

	// distance in Z and clip planes
	GLfloat zDist, zNear, zFar;

	// field of vision
	GLfloat fovy;

	// constant to translate the object in Z
	float zSensivity;

	// scale drawing normals
	float scaleNormal;

	// background color
	int bkRed, bkGreen, bkBlue;

	// layer list
	t_layer layers[MAX_LAYERS];
	int numLayers;
	int layerCount;

	// update render on change?
	bool updates;

	// mouse status
	QPoint mouse;
	bool leftButton, rightButton;
};

// ******************************************************************

#endif
