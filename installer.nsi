
Name "Spöntz Layers Editor"
OutFile "Spontz Layers Editor 0.1.11.exe"

; Some default compiler settings (uncomment and change at will):
; SetCompress auto ; (can be off or force)
; SetDatablockOptimize on ; (can be off)
; CRCCheck on ; (can be off)
; AutoCloseWindow false ; (can be true for the window go away automatically at end)
; ShowInstDetails hide ; (can be show to have them shown, or nevershow to disable)
; SetDateSave off ; (can be on to have files restored to their orginal date)

InstallDir "$PROGRAMFILES\Spöntz\Layers Editor"
InstallDirRegKey HKEY_LOCAL_MACHINE "SOFTWARE\Spöntz\Layers Editor" ""
DirText "Select the directory to install Spöntz Layers Editor in:"

; *************************************************************************************************

Section "" ; (default section)
SetOutPath "$INSTDIR"

; copy application files
File "Layers Editor.exe"
File "readme.txt"
File /r "examples"

; write out registry
WriteRegStr HKEY_LOCAL_MACHINE "SOFTWARE\Spöntz\Layers Editor" "" "$INSTDIR"
WriteRegStr HKEY_LOCAL_MACHINE "Software\Microsoft\Windows\CurrentVersion\Uninstall\Spöntz Layers Editor" "DisplayName" "Spöntz Layers Editor"
WriteRegStr HKEY_LOCAL_MACHINE "Software\Microsoft\Windows\CurrentVersion\Uninstall\Spöntz Layers Editor" "UninstallString" '"$INSTDIR\uninst.exe"'

; write out uninstaller
WriteUninstaller "$INSTDIR\uninst.exe"

; create shortcuts
CreateDirectory "$SMPROGRAMS\Spöntz"
CreateDirectory "$SMPROGRAMS\Spöntz\Layers Editor"
CreateShortCut "$SMPROGRAMS\Spöntz\Layers Editor\Uninstall.lnk" "$INSTDIR\uninst.exe" "" "$INSTDIR\uninst.exe" 0
CreateShortCut "$SMPROGRAMS\Spöntz\Layers Editor\Layers Editor.lnk" "$INSTDIR\Layers Editor.exe" "" "$INSTDIR\Layers Editor.exe" 0
CreateShortCut "$SMPROGRAMS\Spöntz\Layers Editor\Readme.lnk" "$INSTDIR\readme.txt" ""
CreateShortCut "$DESKTOP\Spöntz Layers Editor.lnk" "$INSTDIR\Layers Editor.exe" "" "$INSTDIR\Layers Editor.exe" 0

SectionEnd ; end of default section

; *************************************************************************************************

; begin uninstall settings/section
UninstallText "This will uninstall Spöntz Layers Editor from your system"

; *************************************************************************************************

Section Uninstall

; delete application files
SetOutPath "..\"
RMDir /r "$INSTDIR"

; delete registry keys
DeleteRegKey HKEY_LOCAL_MACHINE "SOFTWARE\Spöntz\Layers Editor"
DeleteRegKey HKEY_LOCAL_MACHINE "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\Spöntz Layers Editor"

; delete shortcuts
Delete "$SMPROGRAMS\Spöntz\Layers Editor\*.*"
RMDir "$SMPROGRAMS\Spöntz\Layers Editor"
RMDir "$SMPROGRAMS\Spöntz"
Delete "$DESKTOP\Spöntz Layers Editor.lnk"

SectionEnd ; end of uninstall section

; eof
