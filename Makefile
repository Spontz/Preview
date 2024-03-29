#############################################################################
# Makefile for building: Editor.app/Contents/MacOS/Editor
# Generated by qmake (1.07a) (Qt 3.3.6) on: Mon Jul 10 10:32:59 2006
# Project:  Editor.pro
# Template: app
# Command: $(QMAKE) -o Makefile Editor.pro
#############################################################################

####### Compiler, tools and options

CC       = cc
CXX      = c++
LEX      = flex
YACC     = yacc
CFLAGS   = -pipe -Wall -W -Os  -DQT_NO_DEBUG -DQT_SHARED -DQT_ACCESSIBILITY_SUPPORT -DQT_TABLET_SUPPORT
CXXFLAGS = -pipe -Wall -W -Os  -DQT_NO_DEBUG -DQT_SHARED -DQT_ACCESSIBILITY_SUPPORT -DQT_TABLET_SUPPORT
LEXFLAGS = 
YACCFLAGS= -d
INCPATH  = -I/Developer/qt/mkspecs/default -I. -I. -I$(QTDIR)/include -I/System/Library/Frameworks/OpenGL.framework/Versions/A/Headers -I/System/Library/Frameworks/AGL.framework/Versions/A/Headers
LINK     = c++
LFLAGS   = -headerpad_max_install_names -prebind
LIBS     = $(SUBLIBS) -L$(QTDIR)/lib -lqt -framework OpenGL -framework AGL
AR       = ar cq
RANLIB   = ranlib -s
MOC      = $(QTDIR)/bin/moc
UIC      = $(QTDIR)/bin/uic
QMAKE    = qmake
TAR      = tar -cf
GZIP     = gzip -9f
COPY     = cp -f
COPY_FILE= cp -f
COPY_DIR = cp -f -r
INSTALL_FILE= $(COPY_FILE)
INSTALL_DIR = $(COPY_DIR)
DEL_FILE = rm -f
SYMLINK  = ln -sf
DEL_DIR  = rmdir
MOVE     = mv -f
CHK_DIR_EXISTS= test -d
MKDIR    = mkdir -p

####### Output directory

OBJECTS_DIR = ./

####### Files

HEADERS = 3dsdraw.h \
		3dsload.h \
		extensions.h \
		filters.h \
		glext.h \
		glmain.h \
		mainform.ui.h \
		math3d.h \
		utils.h \
		wglext.h
SOURCES = 3dsdraw.cpp \
		3dsload.cpp \
		accumulate.cpp \
		blackwhite.cpp \
		boxblur.cpp \
		color.cpp \
		extensions.cpp \
		glmain.cpp \
		glow.cpp \
		highpassfilter.cpp \
		invert.cpp \
		lwoload.cpp \
		main.cpp \
		math3d.cpp \
		radialblur.cpp \
		radialglow.cpp \
		utils.cpp
OBJECTS = 3dsdraw.o \
		3dsload.o \
		accumulate.o \
		blackwhite.o \
		boxblur.o \
		color.o \
		extensions.o \
		glmain.o \
		glow.o \
		highpassfilter.o \
		invert.o \
		lwoload.o \
		main.o \
		math3d.o \
		radialblur.o \
		radialglow.o \
		utils.o \
		mainform.o
FORMS = mainform.ui
UICDECLS = mainform.h
UICIMPLS = mainform.cpp
SRCMOC   = moc_glmain.cpp \
		moc_mainform.cpp
OBJMOC = moc_glmain.o \
		moc_mainform.o
DIST	   = Editor.pro
QMAKE_TARGET = Editor
DESTDIR  = Editor.app/Contents/MacOS/
TARGET   = Editor.app/Contents/MacOS/Editor

first: all
####### Implicit rules

.SUFFIXES: .c .o .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o $@ $<

####### Build rules

all: Makefile Editor.app/Contents/MacOS/../PkgInfo Editor.app/Contents/MacOS/../Info.plist Editor.app/Contents/MacOS/../Resources/application.icns $(TARGET)

$(TARGET):  $(UICDECLS) $(OBJECTS) $(OBJMOC)  
	test -d Editor.app/Contents/MacOS/ || mkdir -p Editor.app/Contents/MacOS/
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJMOC) $(OBJCOMP) $(LIBS)

mocables: $(SRCMOC)
uicables: $(UICDECLS) $(UICIMPLS)

$(MOC): 
	( cd $(QTDIR)/src/moc && $(MAKE) )

Makefile: Editor.pro  /Developer/qt/mkspecs/default/qmake.conf /Developer/qt/lib/libqt.prl
	$(QMAKE) -o Makefile Editor.pro
qmake: 
	@$(QMAKE) -o Makefile Editor.pro

Editor.app/Contents/MacOS/../PkgInfo: 
	@test -d Editor.app/Contents/MacOS/ || mkdir -p Editor.app/Contents/MacOS/
	@$(DEL_FILE) Editor.app/Contents/MacOS/../PkgInfo
	@echo "APPL????" >Editor.app/Contents/MacOS/../PkgInfo
Editor.app/Contents/MacOS/../Info.plist: 
	@test -d Editor.app/Contents/MacOS/ || mkdir -p Editor.app/Contents/MacOS/
	@$(DEL_FILE) Editor.app/Contents/MacOS/../Info.plist
	@sed -e "s,@ICON@,application.icns,g" -e "s,@EXECUTABLE@,Editor,g" "/Developer/qt/mkspecs/default/Info.plist.app" >"Editor.app/Contents/MacOS/../Info.plist"
Editor.app/Contents/MacOS/../Resources/application.icns: icon.icns
	@test -d Editor.app/Contents/MacOS/../Resources/ || mkdir -p Editor.app/Contents/MacOS/../Resources/
	@$(DEL_FILE) Editor.app/Contents/MacOS/../Resources/application.icns
	@$(COPY_FILE) icon.icns Editor.app/Contents/MacOS/../Resources/application.icns
dist: 
	@mkdir -p .tmp/Editor && $(COPY_FILE) --parents $(SOURCES) $(HEADERS) $(FORMS) $(DIST) .tmp/Editor/ && $(COPY_FILE) --parents mainform.ui.h .tmp/Editor/ && ( cd `dirname .tmp/Editor` && $(TAR) Editor.tar Editor && $(GZIP) Editor.tar ) && $(MOVE) `dirname .tmp/Editor`/Editor.tar.gz . && $(DEL_FILE) -r .tmp/Editor

mocclean:
	-$(DEL_FILE) $(OBJMOC)
	-$(DEL_FILE) $(SRCMOC)

uiclean:
	-$(DEL_FILE) $(UICIMPLS) $(UICDECLS)

yaccclean:
lexclean:
clean: mocclean uiclean
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) -r Editor.app


FORCE:

####### Compile

3dsdraw.o: 3dsdraw.cpp extensions.h \
		3dsdraw.h \
		glext.h \
		wglext.h \
		3dsload.h

3dsload.o: 3dsload.cpp utils.h \
		3dsload.h

accumulate.o: accumulate.cpp extensions.h \
		utils.h \
		filters.h \
		glext.h \
		wglext.h

blackwhite.o: blackwhite.cpp extensions.h \
		utils.h \
		filters.h \
		glext.h \
		wglext.h

boxblur.o: boxblur.cpp extensions.h \
		utils.h \
		filters.h \
		glext.h \
		wglext.h

color.o: color.cpp extensions.h \
		utils.h \
		filters.h \
		glext.h \
		wglext.h

extensions.o: extensions.cpp extensions.h \
		math3d.h \
		glext.h \
		wglext.h

glmain.o: glmain.cpp glmain.h \
		extensions.h \
		utils.h \
		3dsdraw.h \
		filters.h \
		glext.h \
		wglext.h \
		3dsload.h

glow.o: glow.cpp extensions.h \
		utils.h \
		filters.h \
		glext.h \
		wglext.h

highpassfilter.o: highpassfilter.cpp extensions.h \
		utils.h \
		filters.h \
		glext.h \
		wglext.h

invert.o: invert.cpp extensions.h \
		utils.h \
		filters.h \
		glext.h \
		wglext.h

lwoload.o: lwoload.cpp utils.h \
		3dsload.h

main.o: main.cpp mainform.h

math3d.o: math3d.cpp math3d.h

radialblur.o: radialblur.cpp extensions.h \
		utils.h \
		filters.h \
		glext.h \
		wglext.h

radialglow.o: radialglow.cpp extensions.h \
		utils.h \
		filters.h \
		glext.h \
		wglext.h

utils.o: utils.cpp extensions.h \
		utils.h \
		glext.h \
		wglext.h

mainform.h: mainform.ui glmain.h \
		extensions.h \
		utils.h \
		3dsdraw.h \
		filters.h \
		glext.h \
		wglext.h \
		3dsload.h
	$(UIC) mainform.ui -o mainform.h

mainform.cpp: mainform.h mainform.ui mainform.ui.h glmain.h \
		extensions.h \
		utils.h \
		3dsdraw.h \
		filters.h \
		glext.h \
		wglext.h \
		3dsload.h
	$(UIC) mainform.ui -i mainform.h -o mainform.cpp

mainform.o: mainform.cpp mainform.h

moc_glmain.o: moc_glmain.cpp  glmain.h extensions.h \
		utils.h \
		3dsdraw.h \
		filters.h \
		glext.h \
		wglext.h \
		3dsload.h

moc_mainform.o: moc_mainform.cpp  mainform.h 

moc_glmain.cpp: $(MOC) glmain.h
	$(MOC) glmain.h -o moc_glmain.cpp

moc_mainform.cpp: $(MOC) mainform.h
	$(MOC) mainform.h -o moc_mainform.cpp

####### Install

install:  

uninstall:  

