@REM .\compare-script 100

@echo off
SETLOCAL ENABLEDELAYEDEXPANSION


set arg1=%1


for /l %%i in (1, 1, %arg1%) do (
    echo i=%%i
    
    call:rand 2 20

    echo rand=!RAND_NUM!

    @REM array.exe  !RAND_NUM! 1 100 > input.txt
    @REM string.exe !RAND_NUM! 0 > input.txt
    @REM tree.exe !RAND_NUM! > input.txt


    @REM ferris.exe < input.txt > output.txt
    @REM ferris_bf.exe < input.txt > answer.txt

    @REM fc output.txt answer.txt || goto :out    
)


:rand
SET /A RAND_NUM=%RANDOM% * (%2 - %1 + 1) / 32768 + %1


:out