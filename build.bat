@echo off
SETLOCAL EnableDelayedExpansion

REM A script to compile main.c with gcc and include all header and source files

REM Initialize the variables
SET headers=
SET sources=

REM Find all the header files in the current directory and store them in a variable
FOR /R %%i IN (*.h) DO SET headers=!headers! "%%i"

REM Find all the source files in the current directory and store them in a variable
FOR /R %%i IN (*.c) DO (
    IF /I NOT "%%~nxi"=="main.c" SET sources=!sources! "%%i"
)

REM Compile main.c with gcc and include all the header and source files
gcc -w -o Build\main %headers% %sources% main.c -lm

ENDLOCAL
