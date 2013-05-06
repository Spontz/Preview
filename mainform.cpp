/****************************************************************************
** Form implementation generated from reading ui file 'mainform.ui'
**
** Created: Mon Jul 10 10:23:03 2006
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.6   edited Aug 31 2005 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "mainform.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qframe.h>
#include <qlistbox.h>
#include <qgroupbox.h>
#include <qlineedit.h>
#include <qcombobox.h>
#include <qtabwidget.h>
#include <qwidget.h>
#include <qcheckbox.h>
#include <qlabel.h>
#include <qslider.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qaction.h>
#include <qmenubar.h>
#include <qpopupmenu.h>
#include <qtoolbar.h>
#include <qimage.h>
#include <qpixmap.h>

#include "glmain.h"
#include "mainform.ui.h"
/*
 *  Constructs a MainForm as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 */
MainForm::MainForm( QWidget* parent, const char* name, WFlags fl )
    : QMainWindow( parent, name, fl )
{
    (void)statusBar();
    if ( !name )
	setName( "MainForm" );
    setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)1, (QSizePolicy::SizeType)1, 0, 0, sizePolicy().hasHeightForWidth() ) );
    setCentralWidget( new QWidget( this, "qt_central_widget" ) );
    MainFormLayout = new QGridLayout( centralWidget(), 1, 1, 11, 6, "MainFormLayout"); 

    layerFrame = new QFrame( centralWidget(), "layerFrame" );
    layerFrame->setEnabled( TRUE );
    layerFrame->setFrameShape( QFrame::StyledPanel );
    layerFrame->setFrameShadow( QFrame::Raised );
    layerFrameLayout = new QGridLayout( layerFrame, 1, 1, 11, 6, "layerFrameLayout"); 

    layerList = new QListBox( layerFrame, "layerList" );

    layerFrameLayout->addMultiCellWidget( layerList, 0, 2, 0, 0 );

    layout77 = new QVBoxLayout( 0, 0, 0, "layout77"); 

    addLayerButton = new QPushButton( layerFrame, "addLayerButton" );
    layout77->addWidget( addLayerButton );

    removeLayerButton = new QPushButton( layerFrame, "removeLayerButton" );
    layout77->addWidget( removeLayerButton );

    layerFrameLayout->addLayout( layout77, 0, 1 );
    spacer3 = new QSpacerItem( 21, 21, QSizePolicy::Minimum, QSizePolicy::Expanding );
    layerFrameLayout->addItem( spacer3, 1, 1 );

    layout78 = new QVBoxLayout( 0, 0, 0, "layout78"); 

    upLayerButton = new QPushButton( layerFrame, "upLayerButton" );
    layout78->addWidget( upLayerButton );

    downLayerButton = new QPushButton( layerFrame, "downLayerButton" );
    layout78->addWidget( downLayerButton );

    layerFrameLayout->addLayout( layout78, 2, 1 );

    MainFormLayout->addWidget( layerFrame, 0, 3 );

    currentGroup = new QGroupBox( centralWidget(), "currentGroup" );
    currentGroup->setEnabled( TRUE );
    currentGroup->setColumnLayout(0, Qt::Vertical );
    currentGroup->layout()->setSpacing( 6 );
    currentGroup->layout()->setMargin( 11 );
    currentGroupLayout = new QGridLayout( currentGroup->layout() );
    currentGroupLayout->setAlignment( Qt::AlignTop );

    layerName = new QLineEdit( currentGroup, "layerName" );
    layerName->setFrameShape( QLineEdit::LineEditPanel );
    layerName->setFrameShadow( QLineEdit::Sunken );

    currentGroupLayout->addMultiCellWidget( layerName, 0, 0, 0, 1 );

    srcBlend = new QComboBox( FALSE, currentGroup, "srcBlend" );

    currentGroupLayout->addMultiCellWidget( srcBlend, 0, 0, 2, 3 );

    dstBlend = new QComboBox( FALSE, currentGroup, "dstBlend" );

    currentGroupLayout->addMultiCellWidget( dstBlend, 1, 1, 2, 3 );

    effectWidget = new QTabWidget( currentGroup, "effectWidget" );

    tab = new QWidget( effectWidget, "tab" );
    tabLayout = new QGridLayout( tab, 1, 1, 11, 6, "tabLayout"); 

    renderMode = new QComboBox( FALSE, tab, "renderMode" );
    renderMode->setSizeLimit( 20 );

    tabLayout->addMultiCellWidget( renderMode, 0, 0, 0, 1 );

    smooth = new QCheckBox( tab, "smooth" );

    tabLayout->addWidget( smooth, 2, 0 );

    layoutWidth = new QHBoxLayout( 0, 0, 6, "layoutWidth"); 

    widthLabel = new QLabel( tab, "widthLabel" );
    layoutWidth->addWidget( widthLabel );

    width = new QSlider( tab, "width" );
    width->setMinValue( 10 );
    width->setMaxValue( 100 );
    width->setOrientation( QSlider::Horizontal );
    layoutWidth->addWidget( width );

    tabLayout->addMultiCellLayout( layoutWidth, 1, 1, 0, 1 );

    texturePixmap = new QLabel( tab, "texturePixmap" );
    texturePixmap->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, texturePixmap->sizePolicy().hasHeightForWidth() ) );
    texturePixmap->setMinimumSize( QSize( 70, 70 ) );
    texturePixmap->setMaximumSize( QSize( 70, 70 ) );
    texturePixmap->setFrameShape( QLabel::Box );
    texturePixmap->setScaledContents( TRUE );

    tabLayout->addWidget( texturePixmap, 3, 0 );

    layoutCull = new QHBoxLayout( 0, 0, 6, "layoutCull"); 

    cullLabel = new QLabel( tab, "cullLabel" );
    cullLabel->setFrameShape( QLabel::NoFrame );
    cullLabel->setScaledContents( FALSE );
    cullLabel->setAlignment( int( QLabel::AlignVCenter | QLabel::AlignRight ) );
    layoutCull->addWidget( cullLabel );

    cull = new QComboBox( FALSE, tab, "cull" );
    layoutCull->addWidget( cull );

    tabLayout->addLayout( layoutCull, 2, 1 );

    textureButton = new QPushButton( tab, "textureButton" );

    tabLayout->addWidget( textureButton, 3, 1 );
    effectWidget->insertTab( tab, QString::fromLatin1("") );

    tab_2 = new QWidget( effectWidget, "tab_2" );
    tabLayout_2 = new QVBoxLayout( tab_2, 11, 6, "tabLayout_2"); 

    filterMode = new QComboBox( FALSE, tab_2, "filterMode" );
    tabLayout_2->addWidget( filterMode );

    layoutRadius = new QHBoxLayout( 0, 0, 6, "layoutRadius"); 

    radiusLabel = new QLabel( tab_2, "radiusLabel" );
    layoutRadius->addWidget( radiusLabel );

    radius = new QSlider( tab_2, "radius" );
    radius->setMaxValue( 64 );
    radius->setOrientation( QSlider::Horizontal );
    layoutRadius->addWidget( radius );
    tabLayout_2->addLayout( layoutRadius );

    layoutAccum = new QHBoxLayout( 0, 0, 6, "layoutAccum"); 

    accumLabel = new QLabel( tab_2, "accumLabel" );
    layoutAccum->addWidget( accumLabel );

    accum = new QSlider( tab_2, "accum" );
    accum->setMaxValue( 50 );
    accum->setOrientation( QSlider::Horizontal );
    layoutAccum->addWidget( accum );
    tabLayout_2->addLayout( layoutAccum );

    layoutAccum2 = new QHBoxLayout( 0, 0, 6, "layoutAccum2"); 

    accum2Label = new QLabel( tab_2, "accum2Label" );
    layoutAccum2->addWidget( accum2Label );

    accum2 = new QSlider( tab_2, "accum2" );
    accum2->setMaxValue( 50 );
    accum2->setOrientation( QSlider::Horizontal );
    layoutAccum2->addWidget( accum2 );
    tabLayout_2->addLayout( layoutAccum2 );

    recursive = new QCheckBox( tab_2, "recursive" );
    tabLayout_2->addWidget( recursive );
    effectWidget->insertTab( tab_2, QString::fromLatin1("") );

    currentGroupLayout->addMultiCellWidget( effectWidget, 4, 4, 0, 3 );

    layoutColorSliders = new QVBoxLayout( 0, 0, 6, "layoutColorSliders"); 

    red = new QSlider( currentGroup, "red" );
    red->setMaxValue( 255 );
    red->setValue( 191 );
    red->setOrientation( QSlider::Horizontal );
    layoutColorSliders->addWidget( red );

    green = new QSlider( currentGroup, "green" );
    green->setMaxValue( 255 );
    green->setValue( 191 );
    green->setOrientation( QSlider::Horizontal );
    layoutColorSliders->addWidget( green );

    blue = new QSlider( currentGroup, "blue" );
    blue->setMaxValue( 255 );
    blue->setValue( 191 );
    blue->setOrientation( QSlider::Horizontal );
    layoutColorSliders->addWidget( blue );

    currentGroupLayout->addMultiCellLayout( layoutColorSliders, 2, 2, 1, 3 );

    colorPixmap = new QLabel( currentGroup, "colorPixmap" );
    colorPixmap->setFrameShape( QLabel::Box );
    colorPixmap->setScaledContents( TRUE );

    currentGroupLayout->addWidget( colorPixmap, 2, 0 );

    alphaPixmap = new QLabel( currentGroup, "alphaPixmap" );
    alphaPixmap->setPaletteBackgroundColor( QColor( 255, 255, 255 ) );
    alphaPixmap->setFrameShape( QLabel::Box );

    currentGroupLayout->addWidget( alphaPixmap, 3, 0 );

    alpha = new QSlider( currentGroup, "alpha" );
    alpha->setMaxValue( 255 );
    alpha->setValue( 255 );
    alpha->setOrientation( QSlider::Horizontal );

    currentGroupLayout->addMultiCellWidget( alpha, 3, 3, 1, 2 );

    colorButton = new QPushButton( currentGroup, "colorButton" );

    currentGroupLayout->addWidget( colorButton, 3, 3 );

    disabledCheck = new QCheckBox( currentGroup, "disabledCheck" );

    currentGroupLayout->addMultiCellWidget( disabledCheck, 1, 1, 0, 1 );

    MainFormLayout->addWidget( currentGroup, 1, 3 );

    Viewport = new GLMain( centralWidget(), "Viewport" );
    Viewport->setSizePolicy( QSizePolicy( (QSizePolicy::SizeType)0, (QSizePolicy::SizeType)0, 0, 0, Viewport->sizePolicy().hasHeightForWidth() ) );
    Viewport->setMinimumSize( QSize( 512, 512 ) );
    Viewport->setMaximumSize( QSize( 512, 512 ) );
    Viewport->setCursor( QCursor( 2 ) );

    MainFormLayout->addMultiCellWidget( Viewport, 0, 1, 1, 1 );
    spacer1 = new QSpacerItem( 0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum );
    MainFormLayout->addItem( spacer1, 1, 0 );
    spacer2 = new QSpacerItem( 0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum );
    MainFormLayout->addItem( spacer2, 1, 2 );

    // actions
    fileOpenAction = new QAction( this, "fileOpenAction" );
    fileOpenLayersAction = new QAction( this, "fileOpenLayersAction" );
    fileSaveLayersAction = new QAction( this, "fileSaveLayersAction" );
    fileExportAction = new QAction( this, "fileExportAction" );
    fileExitAction = new QAction( this, "fileExitAction" );
    toolsChoose_Clear_ColorAction = new QAction( this, "toolsChoose_Clear_ColorAction" );
    toolsOpengl_InformationAction = new QAction( this, "toolsOpengl_InformationAction" );
    toolsObject_InformationAction = new QAction( this, "toolsObject_InformationAction" );
    toolsView_InformationAction = new QAction( this, "toolsView_InformationAction" );
    toolsOrigin_DisplayAction = new QAction( this, "toolsOrigin_DisplayAction" );
    toolsOrigin_RotateAction = new QAction( this, "toolsOrigin_RotateAction" );
    toolsBench_Action = new QAction( this, "toolsBench_Action" );
    aboutAboutAction = new QAction( this, "aboutAboutAction" );


    // toolbars


    // menubar
    MenuBarEditor = new QMenuBar( this, "MenuBarEditor" );


    File = new QPopupMenu( this );
    fileOpenAction->addTo( File );
    File->insertSeparator();
    fileOpenLayersAction->addTo( File );
    fileSaveLayersAction->addTo( File );
    File->insertSeparator();
    fileExportAction->addTo( File );
    File->insertSeparator();
    fileExitAction->addTo( File );
    MenuBarEditor->insertItem( QString(""), File, 1 );

    Tools = new QPopupMenu( this );
    toolsChoose_Clear_ColorAction->addTo( Tools );
    toolsOpengl_InformationAction->addTo( Tools );
    Tools->insertSeparator();
    toolsObject_InformationAction->addTo( Tools );
    toolsView_InformationAction->addTo( Tools );
    Tools->insertSeparator();
    toolsOrigin_DisplayAction->addTo( Tools );
    toolsOrigin_RotateAction->addTo( Tools );
    Tools->insertSeparator();
    toolsBench_Action->addTo( Tools );
    MenuBarEditor->insertItem( QString(""), Tools, 2 );

    About = new QPopupMenu( this );
    aboutAboutAction->addTo( About );
    MenuBarEditor->insertItem( QString(""), About, 3 );

    languageChange();

    // signals and slots connections
    connect( fileOpenAction, SIGNAL( activated() ), this, SLOT( openObject() ) );
    connect( toolsChoose_Clear_ColorAction, SIGNAL( activated() ), this, SLOT( setBackgroundColor() ) );
    connect( addLayerButton, SIGNAL( clicked() ), this, SLOT( addLayer() ) );
    connect( removeLayerButton, SIGNAL( clicked() ), this, SLOT( removeLayer() ) );
    connect( layerList, SIGNAL( highlighted(int) ), this, SLOT( changeLayer() ) );
    connect( upLayerButton, SIGNAL( clicked() ), this, SLOT( upLayer() ) );
    connect( downLayerButton, SIGNAL( clicked() ), this, SLOT( downLayer() ) );
    connect( filterMode, SIGNAL( activated(int) ), this, SLOT( setFilterMode(int) ) );
    connect( accum, SIGNAL( valueChanged(int) ), this, SLOT( setAccum(int) ) );
    connect( radius, SIGNAL( valueChanged(int) ), this, SLOT( setRadius(int) ) );
    connect( blue, SIGNAL( valueChanged(int) ), this, SLOT( setBlue(int) ) );
    connect( red, SIGNAL( valueChanged(int) ), this, SLOT( setRed(int) ) );
    connect( renderMode, SIGNAL( activated(int) ), this, SLOT( setRenderMode(int) ) );
    connect( width, SIGNAL( valueChanged(int) ), this, SLOT( setWidth(int) ) );
    connect( textureButton, SIGNAL( clicked() ), this, SLOT( openTexture() ) );
    connect( cull, SIGNAL( activated(int) ), this, SLOT( setCull(int) ) );
    connect( effectWidget, SIGNAL( currentChanged(QWidget*) ), this, SLOT( setEffectMode() ) );
    connect( dstBlend, SIGNAL( activated(int) ), this, SLOT( setDstBlend(int) ) );
    connect( srcBlend, SIGNAL( activated(int) ), this, SLOT( setSrcBlend(int) ) );
    connect( layerName, SIGNAL( lostFocus() ), this, SLOT( setLayerName() ) );
    connect( disabledCheck, SIGNAL( toggled(bool) ), this, SLOT( setLayerDisabled(bool) ) );
    connect( layerName, SIGNAL( returnPressed() ), this, SLOT( setLayerName() ) );
    connect( toolsObject_InformationAction, SIGNAL( activated() ), this, SLOT( objectInfo() ) );
    connect( aboutAboutAction, SIGNAL( activated() ), this, SLOT( aboutDialog() ) );
    connect( fileOpenLayersAction, SIGNAL( activated() ), this, SLOT( loadLayers() ) );
    connect( fileSaveLayersAction, SIGNAL( activated() ), this, SLOT( saveLayers() ) );
    connect( fileExportAction, SIGNAL( activated() ), this, SLOT( exportLayers() ) );
    connect( Viewport, SIGNAL( newDraggedFile() ), this, SLOT( enableControls() ) );
    connect( fileExitAction, SIGNAL( activated() ), this, SLOT( close() ) );
    connect( smooth, SIGNAL( toggled(bool) ), this, SLOT( setSmooth(bool) ) );
    connect( recursive, SIGNAL( toggled(bool) ), this, SLOT( setRecursive(bool) ) );
    connect( green, SIGNAL( valueChanged(int) ), this, SLOT( setGreen(int) ) );
    connect( alpha, SIGNAL( valueChanged(int) ), this, SLOT( setAlpha(int) ) );
    connect( colorButton, SIGNAL( clicked() ), this, SLOT( setColor() ) );
    connect( accum2, SIGNAL( valueChanged(int) ), this, SLOT( setAccum2(int) ) );
    connect( toolsOpengl_InformationAction, SIGNAL( activated() ), this, SLOT( openglInfo() ) );
    connect( toolsView_InformationAction, SIGNAL( activated() ), this, SLOT( viewInfo() ) );
    connect( toolsOrigin_DisplayAction, SIGNAL( toggled(bool) ), this, SLOT( toggleDisplayOrigins(bool) ) );
    connect( toolsOrigin_RotateAction, SIGNAL( toggled(bool) ), this, SLOT( toggleRotateOrigin(bool) ) );
    connect( toolsBench_Action, SIGNAL( activated() ), this, SLOT( benchmark() ) );

    // tab order
    setTabOrder( layerList, addLayerButton );
    setTabOrder( addLayerButton, removeLayerButton );
    setTabOrder( removeLayerButton, upLayerButton );
    setTabOrder( upLayerButton, downLayerButton );
    setTabOrder( downLayerButton, layerName );
    setTabOrder( layerName, disabledCheck );
    setTabOrder( disabledCheck, srcBlend );
    setTabOrder( srcBlend, dstBlend );
    setTabOrder( dstBlend, red );
    setTabOrder( red, green );
    setTabOrder( green, blue );
    setTabOrder( blue, alpha );
    setTabOrder( alpha, colorButton );
    setTabOrder( colorButton, effectWidget );
    setTabOrder( effectWidget, renderMode );
    setTabOrder( renderMode, width );
    setTabOrder( width, smooth );
    setTabOrder( smooth, cull );
    setTabOrder( cull, textureButton );
    setTabOrder( textureButton, filterMode );
    setTabOrder( filterMode, radius );
    setTabOrder( radius, accum );
    setTabOrder( accum, accum2 );
    setTabOrder( accum2, recursive );
    setTabOrder( recursive, MenuBarEditor );
    init();
}

/*
 *  Destroys the object and frees any allocated resources
 */
MainForm::~MainForm()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void MainForm::languageChange()
{
    setCaption( trUtf8( "\x53\x70\xc3\xb6\x6e\x74\x7a\x20\x4c\x61\x79\x65\x72\x73\x20\x45\x64\x69\x74\x6f\x72"
    "\x20\x2d\x20\x30\x2e\x31\x2e\x31\x32\x64\x65\x76" ) );
    layerList->clear();
    layerList->insertItem( tr( "Layer 1" ) );
    addLayerButton->setText( tr( "Add" ) );
    removeLayerButton->setText( tr( "Remove" ) );
    upLayerButton->setText( tr( "Up" ) );
    downLayerButton->setText( tr( "Down" ) );
    currentGroup->setTitle( tr( "Layer properties" ) );
    srcBlend->clear();
    srcBlend->insertItem( tr( "Zero" ) );
    srcBlend->insertItem( tr( "One" ) );
    srcBlend->insertItem( tr( "Dst Color" ) );
    srcBlend->insertItem( tr( "1 - Dst Color" ) );
    srcBlend->insertItem( tr( "Src Alpha" ) );
    srcBlend->insertItem( tr( "1 - Src Alpha" ) );
    srcBlend->insertItem( tr( "Dst Alpha" ) );
    srcBlend->insertItem( tr( "1 - Dst Alpha" ) );
    srcBlend->insertItem( tr( "Src Color" ) );
    srcBlend->insertItem( tr( "1 - Src Color" ) );
    srcBlend->setCurrentItem( 1 );
    dstBlend->clear();
    dstBlend->insertItem( tr( "Zero" ) );
    dstBlend->insertItem( tr( "One" ) );
    dstBlend->insertItem( tr( "Dst Color" ) );
    dstBlend->insertItem( tr( "1 - Dst Color" ) );
    dstBlend->insertItem( tr( "Src Alpha" ) );
    dstBlend->insertItem( tr( "1 - Src Alpha" ) );
    dstBlend->insertItem( tr( "Dst Alpha" ) );
    dstBlend->insertItem( tr( "1 - Dst Alpha" ) );
    dstBlend->insertItem( tr( "Src Color" ) );
    dstBlend->insertItem( tr( "1 - Src Color" ) );
    renderMode->clear();
    renderMode->insertItem( tr( "Vertexes" ) );
    renderMode->insertItem( tr( "Wireframe" ) );
    renderMode->insertItem( tr( "Bounding boxes" ) );
    renderMode->insertItem( tr( "Bounding spheres" ) );
    renderMode->insertItem( tr( "Color" ) );
    renderMode->insertItem( tr( "Flat" ) );
    renderMode->insertItem( tr( "Shaded" ) );
    renderMode->insertItem( tr( "Face normals" ) );
    renderMode->insertItem( tr( "Vertex normals" ) );
    renderMode->insertItem( tr( "All vertex normals" ) );
    renderMode->insertItem( tr( "Texture" ) );
    renderMode->insertItem( tr( "Environment" ) );
    renderMode->insertItem( tr( "Bump" ) );
    smooth->setText( tr( "Smooth" ) );
    widthLabel->setText( tr( "Width" ) );
    cullLabel->setText( tr( "Cull" ) );
    cull->clear();
    cull->insertItem( QString::null );
    cull->insertItem( tr( "Back" ) );
    cull->insertItem( tr( "Front" ) );
    textureButton->setText( tr( "Texture" ) );
    effectWidget->changeTab( tab, tr( "Render" ) );
    filterMode->clear();
    filterMode->insertItem( tr( "Black and white" ) );
    filterMode->insertItem( tr( "Invert" ) );
    filterMode->insertItem( tr( "Color" ) );
    filterMode->insertItem( tr( "Accumulate" ) );
    filterMode->insertItem( tr( "High pass filter" ) );
    filterMode->insertItem( tr( "Box blur" ) );
    filterMode->insertItem( tr( "Glow" ) );
    filterMode->insertItem( tr( "Radial blur" ) );
    filterMode->insertItem( tr( "Radial glow" ) );
    radiusLabel->setText( tr( "Radius" ) );
    accumLabel->setText( tr( "Accum 1" ) );
    accum2Label->setText( tr( "Accum 2" ) );
    recursive->setText( tr( "Recursive" ) );
    effectWidget->changeTab( tab_2, tr( "Filter" ) );
    colorButton->setText( tr( "Color" ) );
    disabledCheck->setText( tr( "Disabled" ) );
    fileOpenAction->setText( tr( "Open Object" ) );
    fileOpenAction->setMenuText( tr( "Open Object" ) );
    fileOpenAction->setAccel( tr( "Ctrl+O" ) );
    fileOpenLayersAction->setText( tr( "Open Layers" ) );
    fileOpenLayersAction->setMenuText( tr( "Open Layers" ) );
    fileOpenLayersAction->setAccel( tr( "Ctrl+L" ) );
    fileSaveLayersAction->setText( tr( "Save Layers" ) );
    fileSaveLayersAction->setMenuText( tr( "Save Layers" ) );
    fileSaveLayersAction->setAccel( tr( "Ctrl+S" ) );
    fileExportAction->setText( tr( "Export To Engine" ) );
    fileExportAction->setMenuText( tr( "Export To Engine" ) );
    fileExportAction->setAccel( tr( "Ctrl+E" ) );
    fileExitAction->setText( tr( "Exit" ) );
    fileExitAction->setMenuText( tr( "Exit" ) );
    fileExitAction->setAccel( tr( "Ctrl+Q" ) );
    toolsChoose_Clear_ColorAction->setText( tr( "Choose Clear Color" ) );
    toolsChoose_Clear_ColorAction->setMenuText( tr( "Choose Clear Color" ) );
    toolsChoose_Clear_ColorAction->setAccel( tr( "Ctrl+C" ) );
    toolsOpengl_InformationAction->setText( tr( "OpenGL Information" ) );
    toolsOpengl_InformationAction->setMenuText( tr( "OpenGL Information" ) );
    toolsOpengl_InformationAction->setAccel( tr( "Ctrl+G" ) );
    toolsObject_InformationAction->setText( tr( "Object Information" ) );
    toolsObject_InformationAction->setMenuText( tr( "Object Information" ) );
    toolsObject_InformationAction->setAccel( tr( "Ctrl+I" ) );
    toolsView_InformationAction->setText( tr( "View Information" ) );
    toolsView_InformationAction->setMenuText( tr( "View Information" ) );
    toolsView_InformationAction->setAccel( tr( "Ctrl+V" ) );
    toolsOrigin_DisplayAction->setText( tr( "Display Origins" ) );
    toolsOrigin_DisplayAction->setMenuText( tr( "Display Origins" ) );
    toolsOrigin_DisplayAction->setAccel( tr( "Ctrl+D" ) );
    toolsOrigin_RotateAction->setText( tr( "Rotate Over Object Origin" ) );
    toolsOrigin_RotateAction->setMenuText( tr( "Rotate Over Object Origin" ) );
    toolsOrigin_RotateAction->setAccel( tr( "Ctrl+R" ) );
    toolsBench_Action->setText( tr( "Benchmark" ) );
    toolsBench_Action->setMenuText( tr( "Benchmark" ) );
    toolsBench_Action->setAccel( tr( "Ctrl+B" ) );
    aboutAboutAction->setText( tr( "About" ) );
    aboutAboutAction->setMenuText( tr( "About" ) );
    if (MenuBarEditor->findItem(1))
        MenuBarEditor->findItem(1)->setText( tr( "File" ) );
    if (MenuBarEditor->findItem(2))
        MenuBarEditor->findItem(2)->setText( tr( "Tools" ) );
    if (MenuBarEditor->findItem(3))
        MenuBarEditor->findItem(3)->setText( tr( "About" ) );
}

