mkdir Editor.app/Contents/Frameworks
cp $QTDIR/lib/libqt.3.dylib Editor.app/Contents/Frameworks
install_name_tool -id @executable_path/../Frameworks/libqt.3.dylib Editor.app/Contents/Frameworks/libqt.3.dylib
install_name_tool -change libqt.3.dylib @executable_path/../Frameworks/libqt.3.dylib Editor.app/Contents/MacOS/Editor
# Build the zip file with the application
# tar cf Editor.tar Editor.app
# gzip -9 Editor.tar
