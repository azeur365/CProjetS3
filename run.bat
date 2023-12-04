@echo off
REM A script to run the build script and execute the main program

REM Run the build script
call build.bat

REM Check if the build was successful
if %ERRORLEVEL% == 0 (
    REM Run the main program
    Build\main.exe
) else (
    REM Print an error message
    echo Build failed
)

pause
