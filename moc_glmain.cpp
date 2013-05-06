/****************************************************************************
** GLMain meta object code from reading C++ file 'glmain.h'
**
** Created: Mon Jul 10 10:23:13 2006
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.6   edited Mar 8 17:43 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "glmain.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#include <qvariant.h>
const char *GLMain::className() const
{
    return "GLMain";
}

QMetaObject *GLMain::metaObj = 0;
static QMetaObjectCleanUp cleanUp_GLMain( "GLMain", &GLMain::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString GLMain::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "GLMain", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString GLMain::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "GLMain", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* GLMain::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QGLWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::Out },
	{ "s", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"loadObject", 2, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::Out },
	{ "warn", &static_QUType_varptr, "\x12", QUParameter::In }
    };
    static const QUMethod slot_1 = {"getInfo", 2, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::Out }
    };
    static const QUMethod slot_2 = {"getExtensions", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::Out }
    };
    static const QUMethod slot_3 = {"getExtensionsInfo", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::Out }
    };
    static const QUMethod slot_4 = {"getViewInfo", 1, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ "color", &static_QUType_varptr, "\x0a", QUParameter::In }
    };
    static const QUMethod slot_5 = {"setBackgroundColor", 1, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ 0, &static_QUType_QVariant, "\x0a", QUParameter::Out }
    };
    static const QUMethod slot_6 = {"getBackgroundColor", 1, param_slot_6 };
    static const QUParameter param_slot_7[] = {
	{ "value", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_7 = {"toggleDisplayOrigins", 1, param_slot_7 };
    static const QUParameter param_slot_8[] = {
	{ "value", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_8 = {"toggleRotateOrigin", 1, param_slot_8 };
    static const QUMethod slot_9 = {"benchmark", 0, 0 };
    static const QUParameter param_slot_10[] = {
	{ "file", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_10 = {"loadLayers", 1, param_slot_10 };
    static const QUParameter param_slot_11[] = {
	{ "file", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_11 = {"saveLayers", 1, param_slot_11 };
    static const QUMethod slot_12 = {"exportLayers", 0, 0 };
    static const QUParameter param_slot_13[] = {
	{ "e", &static_QUType_ptr, "QMouseEvent", QUParameter::In }
    };
    static const QUMethod slot_13 = {"mousePressEvent", 1, param_slot_13 };
    static const QUParameter param_slot_14[] = {
	{ "e", &static_QUType_ptr, "QMouseEvent", QUParameter::In }
    };
    static const QUMethod slot_14 = {"mouseReleaseEvent", 1, param_slot_14 };
    static const QUParameter param_slot_15[] = {
	{ "e", &static_QUType_ptr, "QMouseEvent", QUParameter::In }
    };
    static const QUMethod slot_15 = {"mouseMoveEvent", 1, param_slot_15 };
    static const QUParameter param_slot_16[] = {
	{ 0, &static_QUType_int, 0, QUParameter::Out },
	{ "text", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_16 = {"addLayer", 2, param_slot_16 };
    static const QUParameter param_slot_17[] = {
	{ "layer", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_17 = {"removeLayer", 1, param_slot_17 };
    static const QUParameter param_slot_18[] = {
	{ 0, &static_QUType_int, 0, QUParameter::Out }
    };
    static const QUMethod slot_18 = {"getLayerCount", 1, param_slot_18 };
    static const QUParameter param_slot_19[] = {
	{ "layer", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_19 = {"upLayer", 1, param_slot_19 };
    static const QUParameter param_slot_20[] = {
	{ "layer", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_20 = {"downLayer", 1, param_slot_20 };
    static const QUParameter param_slot_21[] = {
	{ "layer", &static_QUType_int, 0, QUParameter::In },
	{ "text", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_21 = {"resetLayer", 2, param_slot_21 };
    static const QUParameter param_slot_22[] = {
	{ "update", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_22 = {"setUpdates", 1, param_slot_22 };
    static const QUMethod slot_23 = {"update", 0, 0 };
    static const QUParameter param_slot_24[] = {
	{ "layer", &static_QUType_int, 0, QUParameter::In },
	{ "text", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_24 = {"setName", 2, param_slot_24 };
    static const QUParameter param_slot_25[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::Out },
	{ "layer", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_25 = {"getName", 2, param_slot_25 };
    static const QUParameter param_slot_26[] = {
	{ "layer", &static_QUType_int, 0, QUParameter::In },
	{ "flag", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_26 = {"setDisabled", 2, param_slot_26 };
    static const QUParameter param_slot_27[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::Out },
	{ "layer", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_27 = {"getDisabled", 2, param_slot_27 };
    static const QUParameter param_slot_28[] = {
	{ "layer", &static_QUType_int, 0, QUParameter::In },
	{ "mode", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_28 = {"setSrcBlend", 2, param_slot_28 };
    static const QUParameter param_slot_29[] = {
	{ 0, &static_QUType_int, 0, QUParameter::Out },
	{ "layer", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_29 = {"getSrcBlend", 2, param_slot_29 };
    static const QUParameter param_slot_30[] = {
	{ "layer", &static_QUType_int, 0, QUParameter::In },
	{ "mode", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_30 = {"setDstBlend", 2, param_slot_30 };
    static const QUParameter param_slot_31[] = {
	{ 0, &static_QUType_int, 0, QUParameter::Out },
	{ "layer", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_31 = {"getDstBlend", 2, param_slot_31 };
    static const QUParameter param_slot_32[] = {
	{ "layer", &static_QUType_int, 0, QUParameter::In },
	{ "color", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_32 = {"setRed", 2, param_slot_32 };
    static const QUParameter param_slot_33[] = {
	{ "layer", &static_QUType_int, 0, QUParameter::In },
	{ "color", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_33 = {"setGreen", 2, param_slot_33 };
    static const QUParameter param_slot_34[] = {
	{ "layer", &static_QUType_int, 0, QUParameter::In },
	{ "color", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_34 = {"setBlue", 2, param_slot_34 };
    static const QUParameter param_slot_35[] = {
	{ "layer", &static_QUType_int, 0, QUParameter::In },
	{ "color", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_35 = {"setAlpha", 2, param_slot_35 };
    static const QUParameter param_slot_36[] = {
	{ "layer", &static_QUType_int, 0, QUParameter::In },
	{ "color", &static_QUType_ptr, "QRgb", QUParameter::In }
    };
    static const QUMethod slot_36 = {"setColor", 2, param_slot_36 };
    static const QUParameter param_slot_37[] = {
	{ "layer", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_37 = {"getColor", 1, param_slot_37 };
    static const QUParameter param_slot_38[] = {
	{ "layer", &static_QUType_int, 0, QUParameter::In },
	{ "mode", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_38 = {"setEffectMode", 2, param_slot_38 };
    static const QUParameter param_slot_39[] = {
	{ 0, &static_QUType_int, 0, QUParameter::Out },
	{ "layer", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_39 = {"getEffectMode", 2, param_slot_39 };
    static const QUParameter param_slot_40[] = {
	{ "layer", &static_QUType_int, 0, QUParameter::In },
	{ "mode", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_40 = {"setRenderMode", 2, param_slot_40 };
    static const QUParameter param_slot_41[] = {
	{ 0, &static_QUType_int, 0, QUParameter::Out },
	{ "layer", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_41 = {"getRenderMode", 2, param_slot_41 };
    static const QUParameter param_slot_42[] = {
	{ "layer", &static_QUType_int, 0, QUParameter::In },
	{ "flag", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_42 = {"setSmooth", 2, param_slot_42 };
    static const QUParameter param_slot_43[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::Out },
	{ "layer", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_43 = {"getSmooth", 2, param_slot_43 };
    static const QUParameter param_slot_44[] = {
	{ "layer", &static_QUType_int, 0, QUParameter::In },
	{ "width", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_44 = {"setWidth", 2, param_slot_44 };
    static const QUParameter param_slot_45[] = {
	{ 0, &static_QUType_int, 0, QUParameter::Out },
	{ "layer", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_45 = {"getWidth", 2, param_slot_45 };
    static const QUParameter param_slot_46[] = {
	{ "layer", &static_QUType_int, 0, QUParameter::In },
	{ "mode", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_46 = {"setCull", 2, param_slot_46 };
    static const QUParameter param_slot_47[] = {
	{ 0, &static_QUType_int, 0, QUParameter::Out },
	{ "layer", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_47 = {"getCull", 2, param_slot_47 };
    static const QUParameter param_slot_48[] = {
	{ "layer", &static_QUType_int, 0, QUParameter::In },
	{ "tex", &static_QUType_varptr, "\x0f", QUParameter::In },
	{ "file", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_48 = {"loadTexture", 3, param_slot_48 };
    static const QUParameter param_slot_49[] = {
	{ 0, &static_QUType_QVariant, "\x0f", QUParameter::Out },
	{ "layer", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_49 = {"getTexture", 2, param_slot_49 };
    static const QUParameter param_slot_50[] = {
	{ "layer", &static_QUType_int, 0, QUParameter::In },
	{ "mode", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_50 = {"setFilterMode", 2, param_slot_50 };
    static const QUParameter param_slot_51[] = {
	{ 0, &static_QUType_int, 0, QUParameter::Out },
	{ "layer", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_51 = {"getFilterMode", 2, param_slot_51 };
    static const QUParameter param_slot_52[] = {
	{ "layer", &static_QUType_int, 0, QUParameter::In },
	{ "radius", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_52 = {"setRadius", 2, param_slot_52 };
    static const QUParameter param_slot_53[] = {
	{ 0, &static_QUType_int, 0, QUParameter::Out },
	{ "layer", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_53 = {"getRadius", 2, param_slot_53 };
    static const QUParameter param_slot_54[] = {
	{ "layer", &static_QUType_int, 0, QUParameter::In },
	{ "accum", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_54 = {"setAccum", 2, param_slot_54 };
    static const QUParameter param_slot_55[] = {
	{ 0, &static_QUType_int, 0, QUParameter::Out },
	{ "layer", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_55 = {"getAccum", 2, param_slot_55 };
    static const QUParameter param_slot_56[] = {
	{ "layer", &static_QUType_int, 0, QUParameter::In },
	{ "accum", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_56 = {"setAccum2", 2, param_slot_56 };
    static const QUParameter param_slot_57[] = {
	{ 0, &static_QUType_int, 0, QUParameter::Out },
	{ "layer", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_57 = {"getAccum2", 2, param_slot_57 };
    static const QUParameter param_slot_58[] = {
	{ "layer", &static_QUType_int, 0, QUParameter::In },
	{ "flag", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_58 = {"setRecursive", 2, param_slot_58 };
    static const QUParameter param_slot_59[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::Out },
	{ "layer", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_59 = {"getRecursive", 2, param_slot_59 };
    static const QMetaData slot_tbl[] = {
	{ "loadObject(QString)", &slot_0, QMetaData::Public },
	{ "getInfo(bool*)", &slot_1, QMetaData::Public },
	{ "getExtensions()", &slot_2, QMetaData::Public },
	{ "getExtensionsInfo()", &slot_3, QMetaData::Public },
	{ "getViewInfo()", &slot_4, QMetaData::Public },
	{ "setBackgroundColor(QColor)", &slot_5, QMetaData::Public },
	{ "getBackgroundColor()", &slot_6, QMetaData::Public },
	{ "toggleDisplayOrigins(bool)", &slot_7, QMetaData::Public },
	{ "toggleRotateOrigin(bool)", &slot_8, QMetaData::Public },
	{ "benchmark()", &slot_9, QMetaData::Public },
	{ "loadLayers(const QString&)", &slot_10, QMetaData::Public },
	{ "saveLayers(const QString&)", &slot_11, QMetaData::Public },
	{ "exportLayers()", &slot_12, QMetaData::Public },
	{ "mousePressEvent(QMouseEvent*)", &slot_13, QMetaData::Public },
	{ "mouseReleaseEvent(QMouseEvent*)", &slot_14, QMetaData::Public },
	{ "mouseMoveEvent(QMouseEvent*)", &slot_15, QMetaData::Public },
	{ "addLayer(const QString&)", &slot_16, QMetaData::Public },
	{ "removeLayer(int)", &slot_17, QMetaData::Public },
	{ "getLayerCount()", &slot_18, QMetaData::Public },
	{ "upLayer(int)", &slot_19, QMetaData::Public },
	{ "downLayer(int)", &slot_20, QMetaData::Public },
	{ "resetLayer(int,const QString&)", &slot_21, QMetaData::Public },
	{ "setUpdates(bool)", &slot_22, QMetaData::Public },
	{ "update()", &slot_23, QMetaData::Public },
	{ "setName(int,const QString&)", &slot_24, QMetaData::Public },
	{ "getName(int)", &slot_25, QMetaData::Public },
	{ "setDisabled(int,bool)", &slot_26, QMetaData::Public },
	{ "getDisabled(int)", &slot_27, QMetaData::Public },
	{ "setSrcBlend(int,int)", &slot_28, QMetaData::Public },
	{ "getSrcBlend(int)", &slot_29, QMetaData::Public },
	{ "setDstBlend(int,int)", &slot_30, QMetaData::Public },
	{ "getDstBlend(int)", &slot_31, QMetaData::Public },
	{ "setRed(int,int)", &slot_32, QMetaData::Public },
	{ "setGreen(int,int)", &slot_33, QMetaData::Public },
	{ "setBlue(int,int)", &slot_34, QMetaData::Public },
	{ "setAlpha(int,int)", &slot_35, QMetaData::Public },
	{ "setColor(int,QRgb)", &slot_36, QMetaData::Public },
	{ "getColor(int)", &slot_37, QMetaData::Public },
	{ "setEffectMode(int,int)", &slot_38, QMetaData::Public },
	{ "getEffectMode(int)", &slot_39, QMetaData::Public },
	{ "setRenderMode(int,int)", &slot_40, QMetaData::Public },
	{ "getRenderMode(int)", &slot_41, QMetaData::Public },
	{ "setSmooth(int,bool)", &slot_42, QMetaData::Public },
	{ "getSmooth(int)", &slot_43, QMetaData::Public },
	{ "setWidth(int,int)", &slot_44, QMetaData::Public },
	{ "getWidth(int)", &slot_45, QMetaData::Public },
	{ "setCull(int,int)", &slot_46, QMetaData::Public },
	{ "getCull(int)", &slot_47, QMetaData::Public },
	{ "loadTexture(int,QImage,const QString&)", &slot_48, QMetaData::Public },
	{ "getTexture(int)", &slot_49, QMetaData::Public },
	{ "setFilterMode(int,int)", &slot_50, QMetaData::Public },
	{ "getFilterMode(int)", &slot_51, QMetaData::Public },
	{ "setRadius(int,int)", &slot_52, QMetaData::Public },
	{ "getRadius(int)", &slot_53, QMetaData::Public },
	{ "setAccum(int,int)", &slot_54, QMetaData::Public },
	{ "getAccum(int)", &slot_55, QMetaData::Public },
	{ "setAccum2(int,int)", &slot_56, QMetaData::Public },
	{ "getAccum2(int)", &slot_57, QMetaData::Public },
	{ "setRecursive(int,bool)", &slot_58, QMetaData::Public },
	{ "getRecursive(int)", &slot_59, QMetaData::Public }
    };
    static const QUMethod signal_0 = {"newDraggedFile", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "newDraggedFile()", &signal_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"GLMain", parentObject,
	slot_tbl, 60,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_GLMain.setMetaObject( metaObj );
    return metaObj;
}

void* GLMain::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "GLMain" ) )
	return this;
    return QGLWidget::qt_cast( clname );
}

// SIGNAL newDraggedFile
void GLMain::newDraggedFile()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

bool GLMain::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: static_QUType_int.set(_o,loadObject((QString)static_QUType_QString.get(_o+1))); break;
    case 1: static_QUType_QString.set(_o,getInfo((bool*)static_QUType_varptr.get(_o+1))); break;
    case 2: static_QUType_bool.set(_o,getExtensions()); break;
    case 3: static_QUType_QString.set(_o,getExtensionsInfo()); break;
    case 4: static_QUType_QString.set(_o,getViewInfo()); break;
    case 5: setBackgroundColor((QColor)(*((QColor*)static_QUType_ptr.get(_o+1)))); break;
    case 6: static_QUType_QVariant.set(_o,QVariant(getBackgroundColor())); break;
    case 7: toggleDisplayOrigins((bool)static_QUType_bool.get(_o+1)); break;
    case 8: toggleRotateOrigin((bool)static_QUType_bool.get(_o+1)); break;
    case 9: benchmark(); break;
    case 10: loadLayers((const QString&)static_QUType_QString.get(_o+1)); break;
    case 11: saveLayers((const QString&)static_QUType_QString.get(_o+1)); break;
    case 12: exportLayers(); break;
    case 13: mousePressEvent((QMouseEvent*)static_QUType_ptr.get(_o+1)); break;
    case 14: mouseReleaseEvent((QMouseEvent*)static_QUType_ptr.get(_o+1)); break;
    case 15: mouseMoveEvent((QMouseEvent*)static_QUType_ptr.get(_o+1)); break;
    case 16: static_QUType_int.set(_o,addLayer((const QString&)static_QUType_QString.get(_o+1))); break;
    case 17: removeLayer((int)static_QUType_int.get(_o+1)); break;
    case 18: static_QUType_int.set(_o,getLayerCount()); break;
    case 19: upLayer((int)static_QUType_int.get(_o+1)); break;
    case 20: downLayer((int)static_QUType_int.get(_o+1)); break;
    case 21: resetLayer((int)static_QUType_int.get(_o+1),(const QString&)static_QUType_QString.get(_o+2)); break;
    case 22: setUpdates((bool)static_QUType_bool.get(_o+1)); break;
    case 23: update(); break;
    case 24: setName((int)static_QUType_int.get(_o+1),(const QString&)static_QUType_QString.get(_o+2)); break;
    case 25: static_QUType_QString.set(_o,getName((int)static_QUType_int.get(_o+1))); break;
    case 26: setDisabled((int)static_QUType_int.get(_o+1),(bool)static_QUType_bool.get(_o+2)); break;
    case 27: static_QUType_bool.set(_o,getDisabled((int)static_QUType_int.get(_o+1))); break;
    case 28: setSrcBlend((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 29: static_QUType_int.set(_o,getSrcBlend((int)static_QUType_int.get(_o+1))); break;
    case 30: setDstBlend((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 31: static_QUType_int.set(_o,getDstBlend((int)static_QUType_int.get(_o+1))); break;
    case 32: setRed((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 33: setGreen((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 34: setBlue((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 35: setAlpha((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 36: setColor((int)static_QUType_int.get(_o+1),(QRgb)(*((QRgb*)static_QUType_ptr.get(_o+2)))); break;
    case 37: getColor((int)static_QUType_int.get(_o+1)); break;
    case 38: setEffectMode((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 39: static_QUType_int.set(_o,getEffectMode((int)static_QUType_int.get(_o+1))); break;
    case 40: setRenderMode((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 41: static_QUType_int.set(_o,getRenderMode((int)static_QUType_int.get(_o+1))); break;
    case 42: setSmooth((int)static_QUType_int.get(_o+1),(bool)static_QUType_bool.get(_o+2)); break;
    case 43: static_QUType_bool.set(_o,getSmooth((int)static_QUType_int.get(_o+1))); break;
    case 44: setWidth((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 45: static_QUType_int.set(_o,getWidth((int)static_QUType_int.get(_o+1))); break;
    case 46: setCull((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 47: static_QUType_int.set(_o,getCull((int)static_QUType_int.get(_o+1))); break;
    case 48: loadTexture((int)static_QUType_int.get(_o+1),(QImage)(*((QImage*)static_QUType_ptr.get(_o+2))),(const QString&)static_QUType_QString.get(_o+3)); break;
    case 49: static_QUType_QVariant.set(_o,QVariant(getTexture((int)static_QUType_int.get(_o+1)))); break;
    case 50: setFilterMode((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 51: static_QUType_int.set(_o,getFilterMode((int)static_QUType_int.get(_o+1))); break;
    case 52: setRadius((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 53: static_QUType_int.set(_o,getRadius((int)static_QUType_int.get(_o+1))); break;
    case 54: setAccum((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 55: static_QUType_int.set(_o,getAccum((int)static_QUType_int.get(_o+1))); break;
    case 56: setAccum2((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 57: static_QUType_int.set(_o,getAccum2((int)static_QUType_int.get(_o+1))); break;
    case 58: setRecursive((int)static_QUType_int.get(_o+1),(bool)static_QUType_bool.get(_o+2)); break;
    case 59: static_QUType_bool.set(_o,getRecursive((int)static_QUType_int.get(_o+1))); break;
    default:
	return QGLWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool GLMain::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: newDraggedFile(); break;
    default:
	return QGLWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool GLMain::qt_property( int id, int f, QVariant* v)
{
    return QGLWidget::qt_property( id, f, v);
}

bool GLMain::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
