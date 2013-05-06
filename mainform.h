/****************************************************************************
** Form interface generated from reading ui file 'mainform.ui'
**
** Created: Mon Jul 10 10:22:14 2006
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.6   edited Aug 31 2005 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef MAINFORM_H
#define MAINFORM_H

#include <qvariant.h>
#include <qpixmap.h>
#include <qmainwindow.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QAction;
class QActionGroup;
class QToolBar;
class QPopupMenu;
class GLMain;
class QFrame;
class QListBox;
class QListBoxItem;
class QPushButton;
class QGroupBox;
class QLineEdit;
class QComboBox;
class QTabWidget;
class QWidget;
class QCheckBox;
class QLabel;
class QSlider;

class MainForm : public QMainWindow
{
    Q_OBJECT

public:
    MainForm( QWidget* parent = 0, const char* name = 0, WFlags fl = WType_TopLevel );
    ~MainForm();

    QFrame* layerFrame;
    QListBox* layerList;
    QPushButton* addLayerButton;
    QPushButton* removeLayerButton;
    QPushButton* upLayerButton;
    QPushButton* downLayerButton;
    QGroupBox* currentGroup;
    QLineEdit* layerName;
    QComboBox* srcBlend;
    QComboBox* dstBlend;
    QTabWidget* effectWidget;
    QWidget* tab;
    QComboBox* renderMode;
    QCheckBox* smooth;
    QLabel* widthLabel;
    QSlider* width;
    QLabel* texturePixmap;
    QLabel* cullLabel;
    QComboBox* cull;
    QPushButton* textureButton;
    QWidget* tab_2;
    QComboBox* filterMode;
    QLabel* radiusLabel;
    QSlider* radius;
    QLabel* accumLabel;
    QSlider* accum;
    QLabel* accum2Label;
    QSlider* accum2;
    QCheckBox* recursive;
    QSlider* red;
    QSlider* green;
    QSlider* blue;
    QLabel* colorPixmap;
    QLabel* alphaPixmap;
    QSlider* alpha;
    QPushButton* colorButton;
    QCheckBox* disabledCheck;
    GLMain* Viewport;
    QMenuBar *MenuBarEditor;
    QPopupMenu *File;
    QPopupMenu *Tools;
    QPopupMenu *About;
    QAction* fileOpenAction;
    QAction* fileOpenLayersAction;
    QAction* fileSaveLayersAction;
    QAction* fileExportAction;
    QAction* fileExitAction;
    QAction* toolsChoose_Clear_ColorAction;
    QAction* toolsOpengl_InformationAction;
    QAction* toolsObject_InformationAction;
    QAction* toolsView_InformationAction;
    QAction* toolsOrigin_DisplayAction;
    QAction* toolsOrigin_RotateAction;
    QAction* toolsBench_Action;
    QAction* aboutAboutAction;

public slots:
    virtual void openObject();
    virtual void setBackgroundColor();
    virtual void changeLayer();
    virtual void addLayer();
    virtual void removeLayer();
    virtual void upLayer();
    virtual void downLayer();
    virtual void setSrcBlend( int mode );
    virtual void setDstBlend( int mode );
    virtual void setEffectMode();
    virtual void setRenderMode( int mode );
    virtual void setWidth( int width );
    virtual void setCull( int mode );
    virtual void setColor();
    virtual void openTexture();
    virtual void setFilterMode( int mode );
    virtual void setRadius( int radius );
    virtual void setRed( int color );
    virtual void setGreen( int color );
    virtual void setBlue( int color );
    virtual void setAccum( int accum );
    virtual void setLayerDisabled( bool flag );
    virtual void setLayerName();
    virtual void objectInfo();
    virtual void aboutDialog();
    virtual void loadLayers();
    virtual void saveLayers();
    virtual void exportLayers();
    virtual void enableControls();
    virtual void setSmooth( bool flag );
    virtual void setRecursive( bool flag );
    virtual void setAlpha( int color );
    virtual void setAccum2( int accum );
    virtual void openglInfo();
    virtual void viewInfo();
    virtual void toggleDisplayOrigins( bool value );
    virtual void toggleRotateOrigin( bool value );
    virtual void benchmark();

protected:
    QGridLayout* MainFormLayout;
    QSpacerItem* spacer1;
    QSpacerItem* spacer2;
    QGridLayout* layerFrameLayout;
    QSpacerItem* spacer3;
    QVBoxLayout* layout77;
    QVBoxLayout* layout78;
    QGridLayout* currentGroupLayout;
    QGridLayout* tabLayout;
    QHBoxLayout* layoutWidth;
    QHBoxLayout* layoutCull;
    QVBoxLayout* tabLayout_2;
    QHBoxLayout* layoutRadius;
    QHBoxLayout* layoutAccum;
    QHBoxLayout* layoutAccum2;
    QVBoxLayout* layoutColorSliders;

protected slots:
    virtual void languageChange();

private:
    QPixmap image0;

    void init();

};

#endif // MAINFORM_H
