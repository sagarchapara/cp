@REM .\compare-script 100

@echo off
SETLOCAL ENABLEDELAYEDEXPANSION


set arg1=%1


for /l %%i in (1, 1, %arg1%) do (
    echo i=%%i
    
    call:rand 1 100

    echo rand=!RAND_NUM!

    array.exe  !RAND_NUM! 1 100 > input.txt
    @REM string.exe !RAND_NUM! 0 > input.txt
    @REM tree.exe !RAND_NUM! > input.txt


    d.exe < input.txt > output.txt
    d_org.exe < input.txt > answer.txt

    fc output.txt answer.txt || goto :out    
)


:rand
SET /A RAND_NUM=%RANDOM% * (%2 - %1 + 1) / 32768 + %1


:out