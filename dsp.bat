@echo off
del *.bak
del Editor.dsp
del Editor.dsw
del Editor.ncb
del Editor.opt
del Editor.plg
del Editor.aps
qmake -tp vc
