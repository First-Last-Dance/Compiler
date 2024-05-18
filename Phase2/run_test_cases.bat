@echo off
setlocal

set program=project.exe
set input_dir=test_cases
set output_dir=output
set symbol_dir=symbol
set correct_output_dir=correct_output

mkdir %output_dir%
mkdir %symbol_dir%

set total_tests=0
set successful_tests=0

for %%f in (%input_dir%\*.txt) do (
    echo Running test case: %%~nxf
    %program% "%%~ff" "%output_dir%\%%~nf.txt" "%symbol_dir%\%%~nf.txt"
    fc /W "%output_dir%\%%~nf.txt" "%correct_output_dir%\%%~nf.txt" > nul
    set /a total_tests+=1
    if errorlevel 1 (
        echo Output for %%~nf is not correct.
    ) else (
        echo Output for %%~nf is correct.
        set /a successful_tests+=1
    )
)

echo %successful_tests% out of %total_tests% test cases were successful.

endlocal