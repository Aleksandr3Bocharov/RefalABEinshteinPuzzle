@echo off

rem Copyright 2026 Aleksandr Bocharov
rem Distributed under the Boost Software License, Version 1.0.
rem See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt
rem 2026-07-17
rem https://github.com/Aleksandr3Bocharov/refalabeinsteinpuzzle

set RAYLIB=F:\Programming\raylib-5.5_win64_mingw-w64
set RAYLIBCFLAGS=-Wall -O2 -I%RAYLIB%\include
set RAYLIBLFLAGS=-L%RAYLIB%\lib -lraylib -lgdi32 -lwinmm

if not exist bin mkdir bin
%REFALABBIN%\refalabc src\refalabeinsteinpuzzle_gui -l,"-o src\refalabeinsteinpuzzle_gui.o -O2 -Wno-override-module" > refalabeinsteinpuzzle_gui.log
%REFALABBIN%\refalabc src\solver -l,"-o src\solver.o -O2 -Wno-override-module" >> refalabeinsteinpuzzle_gui.log
clang %REFALABCFLAGS% -I%REFALABINCLUDE% -c src\refalabeinsteinpuzzlec_gui.c -o src\refalabeinsteinpuzzlec_gui.o >> refalabeinsteinpuzzle_gui.log
clang %RAYLIBCFLAGS% -c src\gui.c -o src\gui.o >> refalabeinsteinpuzzle_gui.log
clang -o bin\refalabeinsteinpuzzle_gui.exe src\refalabeinsteinpuzzle_gui.o src\refalabeinsteinpuzzlec_gui.o src\solver.o %REFALABLFLAGS% src\gui.o -static %RAYLIBLFLAGS% >> refalabeinsteinpuzzle_gui.log
bin\refalabeinsteinpuzzle_gui
