/****************************************************************************
** MainForm meta object code from reading C++ file 'mainform.h'
**
** Created: Mon Jul 10 10:23:17 2006
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.6   edited Mar 8 17:43 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "mainform.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *MainForm::className() const
{
    return "MainForm";
}

QMetaObject *MainForm::metaObj = 0;
static QMetaObjectCleanUp cleanUp_MainForm( "MainForm", &MainForm::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString MainForm::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "MainForm", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString MainForm::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "MainForm", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* MainForm::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QMainWindow::staticMetaObject();
    static const QUMethod slot_0 = {"openObject", 0, 0 };
    static const QUMethod slot_1 = {"setBackgroundColor", 0, 0 };
    static const QUMethod slot_2 = {"changeLayer", 0, 0 };
    static const QUMethod slot_3 = {"addLayer", 0, 0 };
    static const QUMethod slot_4 = {"removeLayer", 0, 0 };
    static const QUMethod slot_5 = {"upLayer", 0, 0 };
    static const QUMethod slot_6 = {"downLayer", 0, 0 };
    static const QUParameter param_slot_7[] = {
	{ "mode", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_7 = {"setSrcBlend", 1, param_slot_7 };
    static const QUParameter param_slot_8[] = {
	{ "mode", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_8 = {"setDstBlend", 1, param_slot_8 };
    static const QUMethod slot_9 = {"setEffectMode", 0, 0 };
    static const QUParameter param_slot_10[] = {
	{ "mode", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_10 = {"setRenderMode", 1, param_slot_10 };
    static const QUParameter param_slot_11[] = {
	{ "width", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_11 = {"setWidth", 1, param_slot_11 };
    static const QUParameter param_slot_12[] = {
	{ "mode", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_12 = {"setCull", 1, param_slot_12 };
    static const QUMethod slot_13 = {"setColor", 0, 0 };
    static const QUMethod slot_14 = {"openTexture", 0, 0 };
    static const QUParameter param_slot_15[] = {
	{ "mode", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_15 = {"setFilterMode", 1, param_slot_15 };
    static const QUParameter param_slot_16[] = {
	{ "radius", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_16 = {"setRadius", 1, param_slot_16 };
    static const QUParameter param_slot_17[] = {
	{ "color", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_17 = {"setRed", 1, param_slot_17 };
    static const QUParameter param_slot_18[] = {
	{ "color", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_18 = {"setGreen", 1, param_slot_18 };
    static const QUParameter param_slot_19[] = {
	{ "color", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_19 = {"setBlue", 1, param_slot_19 };
    static const QUParameter param_slot_20[] = {
	{ "accum", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_20 = {"setAccum", 1, param_slot_20 };
    static const QUParameter param_slot_21[] = {
	{ "flag", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_21 = {"setLayerDisabled", 1, param_slot_21 };
    static const QUMethod slot_22 = {"setLayerName", 0, 0 };
    static const QUMethod slot_23 = {"objectInfo", 0, 0 };
    static const QUMethod slot_24 = {"aboutDialog", 0, 0 };
    static const QUMethod slot_25 = {"loadLayers", 0, 0 };
    static const QUMethod slot_26 = {"saveLayers", 0, 0 };
    static const QUMethod slot_27 = {"exportLayers", 0, 0 };
    static const QUMethod slot_28 = {"enableControls", 0, 0 };
    static const QUParameter param_slot_29[] = {
	{ "flag", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_29 = {"setSmooth", 1, param_slot_29 };
    static const QUParameter param_slot_30[] = {
	{ "flag", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_30 = {"setRecursive", 1, param_slot_30 };
    static const QUParameter param_slot_31[] = {
	{ "color", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_31 = {"setAlpha", 1, param_slot_31 };
    static const QUParameter param_slot_32[] = {
	{ "accum", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_32 = {"setAccum2", 1, param_slot_32 };
    static const QUMethod slot_33 = {"openglInfo", 0, 0 };
    static const QUMethod slot_34 = {"viewInfo", 0, 0 };
    static const QUParameter param_slot_35[] = {
	{ "value", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_35 = {"toggleDisplayOrigins", 1, param_slot_35 };
    static const QUParameter param_slot_36[] = {
	{ "value", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_36 = {"toggleRotateOrigin", 1, param_slot_36 };
    static const QUMethod slot_37 = {"benchmark", 0, 0 };
    static const QUMethod slot_38 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "openObject()", &slot_0, QMetaData::Public },
	{ "setBackgroundColor()", &slot_1, QMetaData::Public },
	{ "changeLayer()", &slot_2, QMetaData::Public },
	{ "addLayer()", &slot_3, QMetaData::Public },
	{ "removeLayer()", &slot_4, QMetaData::Public },
	{ "upLayer()", &slot_5, QMetaData::Public },
	{ "downLayer()", &slot_6, QMetaData::Public },
	{ "setSrcBlend(int)", &slot_7, QMetaData::Public },
	{ "setDstBlend(int)", &slot_8, QMetaData::Public },
	{ "setEffectMode()", &slot_9, QMetaData::Public },
	{ "setRenderMode(int)", &slot_10, QMetaData::Public },
	{ "setWidth(int)", &slot_11, QMetaData::Public },
	{ "setCull(int)", &slot_12, QMetaData::Public },
	{ "setColor()", &slot_13, QMetaData::Public },
	{ "openTexture()", &slot_14, QMetaData::Public },
	{ "setFilterMode(int)", &slot_15, QMetaData::Public },
	{ "setRadius(int)", &slot_16, QMetaData::Public },
	{ "setRed(int)", &slot_17, QMetaData::Public },
	{ "setGreen(int)", &slot_18, QMetaData::Public },
	{ "setBlue(int)", &slot_19, QMetaData::Public },
	{ "setAccum(int)", &slot_20, QMetaData::Public },
	{ "setLayerDisabled(bool)", &slot_21, QMetaData::Public },
	{ "setLayerName()", &slot_22, QMetaData::Public },
	{ "objectInfo()", &slot_23, QMetaData::Public },
	{ "aboutDialog()", &slot_24, QMetaData::Public },
	{ "loadLayers()", &slot_25, QMetaData::Public },
	{ "saveLayers()", &slot_26, QMetaData::Public },
	{ "exportLayers()", &slot_27, QMetaData::Public },
	{ "enableControls()", &slot_28, QMetaData::Public },
	{ "setSmooth(bool)", &slot_29, QMetaData::Public },
	{ "setRecursive(bool)", &slot_30, QMetaData::Public },
	{ "setAlpha(int)", &slot_31, QMetaData::Public },
	{ "setAccum2(int)", &slot_32, QMetaData::Public },
	{ "openglInfo()", &slot_33, QMetaData::Public },
	{ "viewInfo()", &slot_34, QMetaData::Public },
	{ "toggleDisplayOrigins(bool)", &slot_35, QMetaData::Public },
	{ "toggleRotateOrigin(bool)", &slot_36, QMetaData::Public },
	{ "benchmark()", &slot_37, QMetaData::Public },
	{ "languageChange()", &slot_38, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"MainForm", parentObject,
	slot_tbl, 39,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_MainForm.setMetaObject( metaObj );
    return metaObj;
}

void* MainForm::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "MainForm" ) )
	return this;
    return QMainWindow::qt_cast( clname );
}

bool MainForm::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: openObject(); break;
    case 1: setBackgroundColor(); break;
    case 2: changeLayer(); break;
    case 3: addLayer(); break;
    case 4: removeLayer(); break;
    case 5: upLayer(); break;
    case 6: downLayer(); break;
    case 7: setSrcBlend((int)static_QUType_int.get(_o+1)); break;
    case 8: setDstBlend((int)static_QUType_int.get(_o+1)); break;
    case 9: setEffectMode(); break;
    case 10: setRenderMode((int)static_QUType_int.get(_o+1)); break;
    case 11: setWidth((int)static_QUType_int.get(_o+1)); break;
    case 12: setCull((int)static_QUType_int.get(_o+1)); break;
    case 13: setColor(); break;
    case 14: openTexture(); break;
    case 15: setFilterMode((int)static_QUType_int.get(_o+1)); break;
    case 16: setRadius((int)static_QUType_int.get(_o+1)); break;
    case 17: setRed((int)static_QUType_int.get(_o+1)); break;
    case 18: setGreen((int)static_QUType_int.get(_o+1)); break;
    case 19: setBlue((int)static_QUType_int.get(_o+1)); break;
    case 20: setAccum((int)static_QUType_int.get(_o+1)); break;
    case 21: setLayerDisabled((bool)static_QUType_bool.get(_o+1)); break;
    case 22: setLayerName(); break;
    case 23: objectInfo(); break;
    case 24: aboutDialog(); break;
    case 25: loadLayers(); break;
    case 26: saveLayers(); break;
    case 27: exportLayers(); break;
    case 28: enableControls(); break;
    case 29: setSmooth((bool)static_QUType_bool.get(_o+1)); break;
    case 30: setRecursive((bool)static_QUType_bool.get(_o+1)); break;
    case 31: setAlpha((int)static_QUType_int.get(_o+1)); break;
    case 32: setAccum2((int)static_QUType_int.get(_o+1)); break;
    case 33: openglInfo(); break;
    case 34: viewInfo(); break;
    case 35: toggleDisplayOrigins((bool)static_QUType_bool.get(_o+1)); break;
    case 36: toggleRotateOrigin((bool)static_QUType_bool.get(_o+1)); break;
    case 37: benchmark(); break;
    case 38: languageChange(); break;
    default:
	return QMainWindow::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool MainForm::qt_emit( int _id, QUObject* _o )
{
    return QMainWindow::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool MainForm::qt_property( int id, int f, QVariant* v)
{
    return QMainWindow::qt_property( id, f, v);
}

bool MainForm::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
