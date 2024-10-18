@echo off
setlocal

echo Deleting all .exe files in "%cd%" and subdirectories...

@REM /s：Recursively delete .exe files in subdirectories.
@REM /q：No prompt for confirmation when deleting files, quiet mode.
del /s /q *.exe


if %errorlevel% equ 0 (
    echo All .exe files deleted successfully.
) else (
    echo An error occurred while deleting .exe files.
)

echo Deleting all .exe files in "%cd%" and subdirectories...

del /s /q *.out

if %errorlevel% equ 0 (
    echo All .out files deleted successfully.
) else (
    echo An error occurred while deleting .out files.
)

endlocal
