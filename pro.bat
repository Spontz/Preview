@echo off
qmake -project
echo Remind to add this to the generated PRO file:
echo.
echo CONFIG += qt opengl warn_on release
echo REQUIRED = opengl
echo.
echo win32:RC_FILE = Editor.rc
echo mac:RC_FILE = icon.icns
