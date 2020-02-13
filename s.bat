@echo off
for /l %%x in (1,1,100000000) do (
    echo %%x
    gen %%x > in
    abc < in > out1 
    ass < in > out2
    fc out1 out2 > diagnostics || exit /b
)
echo all tests passed
