
Name "Sp�ntz Layers Editor"
OutFile "Spontz Layers Editor 0.1.11.exe"

; Some default compiler settings (uncomment and change at will):
; SetCompress auto ; (can be off or force)
; SetDatablockOptimize on ; (can be off)
; CRCCheck on ; (can be off)
; AutoCloseWindow false ; (can be true for the window go away automatically at end)
; ShowInstDetails hide ; (can be show to have them shown, or nevershow to disable)
; SetDateSave off ; (can be on to have files restored to their orginal date)

InstallDir "$PROGRAMFILES\Sp�ntz\Layers Editor"
InstallDirRegKey HKEY_LOCAL_MACHINE "SOFTWARE\Sp�ntz\Layers Editor" ""
DirText "Select the directory to install Sp�ntz Layers Editor in:"

; *************************************************************************************************

Section "" ; (default section)
SetOutPath "$INSTDIR"

; copy application files
File "Layers Editor.exe"
File "readme.txt"
File /r "examples"

; write out registry
WriteRegStr HKEY_LOCAL_MACHINE "SOFTWARE\Sp�ntz\Layers Editor" "" "$INSTDIR"
WriteRegStr HKEY_LOCAL_MACHINE "Software\Microsoft\Windows\CurrentVersion\Uninstall\Sp�ntz Layers Editor" "DisplayName" "Sp�ntz Layers Editor"
WriteRegStr HKEY_LOCAL_MACHINE "Software\Microsoft\Windows\CurrentVersion\Uninstall\Sp�ntz Layers Editor" "UninstallString" '"$INSTDIR\uninst.exe"'

; write out uninstaller
WriteUninstaller "$INSTDIR\uninst.exe"

; create shortcuts
CreateDirectory "$SMPROGRAMS\Sp�ntz"
CreateDirectory "$SMPROGRAMS\Sp�ntz\Layers Editor"
CreateShortCut "$SMPROGRAMS\Sp�ntz\Layers Editor\Uninstall.lnk" "$INSTDIR\uninst.exe" "" "$INSTDIR\uninst.exe" 0
CreateShortCut "$SMPROGRAMS\Sp�ntz\Layers Editor\Layers Editor.lnk" "$INSTDIR\Layers Editor.exe" "" "$INSTDIR\Layers Editor.exe" 0
CreateShortCut "$SMPROGRAMS\Sp�ntz\Layers Editor\Readme.lnk" "$INSTDIR\readme.txt" ""
CreateShortCut "$DESKTOP\Sp�ntz Layers Editor.lnk" "$INSTDIR\Layers Editor.exe" "" "$INSTDIR\Layers Editor.exe" 0

SectionEnd ; end of default section

; *************************************************************************************************

; begin uninstall settings/section
UninstallText "This will uninstall Sp�ntz Layers Editor from your system"

; *************************************************************************************************

Section Uninstall

; delete application files
SetOutPath "..\"
RMDir /r "$INSTDIR"

; delete registry keys
DeleteRegKey HKEY_LOCAL_MACHINE "SOFTWARE\Sp�ntz\Layers Editor"
DeleteRegKey HKEY_LOCAL_MACHINE "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\Sp�ntz Layers Editor"

; delete shortcuts
Delete "$SMPROGRAMS\Sp�ntz\Layers Editor\*.*"
RMDir "$SMPROGRAMS\Sp�ntz\Layers Editor"
RMDir "$SMPROGRAMS\Sp�ntz"
Delete "$DESKTOP\Sp�ntz Layers Editor.lnk"

SectionEnd ; end of uninstall section

; eof
