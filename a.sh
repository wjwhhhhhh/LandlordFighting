#!/bin/bash

mkdir -p build  # 创建 build 目录，如果不存在的话
cd build        # 进入 build 目录

D:/newqt/5.15.2/mingw81_32/bin/qmake.exe D:\\qtproject\\game\\game.pro -spec win32-g++ "CONFIG+=debug" "CONFIG+=qml_debug"win32-g++ "CONFIG+=debug" "CONFIG+=qml_debug"
D:/newqt/Tools/mingw810_32/bin/mingw32-make.exe qmake_all
D:/newqt/Tools/mingw810_32/bin/mingw32-make.exe  -j16 -f Makefile.Debug
./debug/game.exe