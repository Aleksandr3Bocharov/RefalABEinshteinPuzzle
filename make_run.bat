@echo off

rem Copyright 2026 Aleksandr Bocharov
rem Distributed under the Boost Software License, Version 1.0.
rem See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt
rem 2026-07-17
rem https://github.com/Aleksandr3Bocharov/refalabeinsteinpuzzle

if not exist bin mkdir bin
%REFALABBIN%\refalabc src\refalabeinsteinpuzzle -l,"-o src\refalabeinsteinpuzzle.o -O2 -Wno-override-module" > refalabeinsteinpuzzle.log
%REFALABBIN%\refalabc src\solver -l,"-o src\solver.o -O2 -Wno-override-module" >> refalabeinsteinpuzzle.log
clang -o bin\refalabeinsteinpuzzle.exe src\refalabeinsteinpuzzle.o src\solver.o %REFALABLFLAGS% -static >> refalabeinsteinpuzzle.log
bin\refalabeinsteinpuzzle
