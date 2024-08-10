@echo off
setlocal

if "%~1"=="" (
    echo Please provide the C++ file name as a command line argument.
    exit /b 1
)

@REM set FILENAME=%~1
set FILENAME=%~n1
set EXE_NAME=%~n1

echo Compile: g++ %FILENAME%.cpp -o %EXE_NAME% -Wall -std=c++11

g++ %FILENAME%.cpp -o %EXE_NAME% -Wall -std=c++11

if %errorlevel% neq 0 (
    echo Compilation failed.
    exit /b 1
)

echo Run: %EXE_NAME%.exe ^< %EXE_NAME%.in ^> %EXE_NAME%.out

.\%EXE_NAME%.exe < %EXE_NAME%.in > %EXE_NAME%.out

endlocal
