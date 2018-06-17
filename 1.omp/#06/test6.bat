@echo off
rem memory of data < 5GB
copy %1 prog.exe
del results*.txt
cls

set  OMP_NUM_THREADS=1
call test_.bat  100 100 100 NT1
call test_.bat  200 200 200 NT1
call test_.bat  300 300 300 NT1
call test_.bat  400 400 400 NT1
call test_.bat  500 500 500 NT1
call test_.bat  600 600 600 NT1
call test_.bat  700 700 700 NT1
call test_.bat  800 800 800 NT1
call test_.bat  900 900 900 NT1
call test_.bat  1000 1000 1000 NT1

set  OMP_NUM_THREADS=2
call test_.bat  100 100 100 NT2
call test_.bat  200 200 200 NT2
call test_.bat  300 300 300 NT2
call test_.bat  400 400 400 NT2
call test_.bat  500 500 500 NT2
call test_.bat  600 600 600 NT2
call test_.bat  700 700 700 NT2
call test_.bat  800 800 800 NT2
call test_.bat  900 900 900 NT2
call test_.bat  1000 1000 1000 NT2

set  OMP_NUM_THREADS=3
call test_.bat  100 100 100 NT3
call test_.bat  200 200 200 NT3
call test_.bat  300 300 300 NT3
call test_.bat  400 400 400 NT3
call test_.bat  500 500 500 NT3
call test_.bat  600 600 600 NT3
call test_.bat  700 700 700 NT3
call test_.bat  800 800 800 NT3
call test_.bat  900 900 900 NT3
call test_.bat  1000 1000 1000 NT3

set  OMP_NUM_THREADS=4
call test_.bat  100 100 100 NT4
call test_.bat  200 200 200 NT4
call test_.bat  300 300 300 NT4
call test_.bat  400 400 400 NT4
call test_.bat  500 500 500 NT4
call test_.bat  600 600 600 NT4
call test_.bat  700 700 700 NT4
call test_.bat  800 800 800 NT4
call test_.bat  900 900 900 NT4
call test_.bat  1000 1000 1000 NT4