@echo off
rem memory of data < 5GB
copy %1 prog.exe
del results*.txt
cls

set  OMP_NUM_THREADS=1
call test_.bat 1000000 NT1
call test_.bat 2000000 NT1
call test_.bat 3000000 NT1
call test_.bat 4000000 NT1
call test_.bat 5000000 NT1
call test_.bat 6000000 NT1
call test_.bat 7000000 NT1
call test_.bat 8000000 NT1
call test_.bat 9000000 NT1
call test_.bat 10000000 NT1
call test_.bat 20000000 NT1
call test_.bat 30000000 NT1
call test_.bat 40000000 NT1
call test_.bat 50000000 NT1
call test_.bat 60000000 NT1

set  OMP_NUM_THREADS=2
call test_.bat 1000000 NT2
call test_.bat 2000000 NT2
call test_.bat 3000000 NT2
call test_.bat 4000000 NT2
call test_.bat 5000000 NT2
call test_.bat 6000000 NT2
call test_.bat 7000000 NT2
call test_.bat 8000000 NT2
call test_.bat 9000000 NT2
call test_.bat 10000000 NT2
call test_.bat 20000000 NT2
call test_.bat 30000000 NT2
call test_.bat 40000000 NT2
call test_.bat 50000000 NT2
call test_.bat 60000000 NT2

set  OMP_NUM_THREADS=3
call test_.bat 1000000 NT3
call test_.bat 2000000 NT3
call test_.bat 3000000 NT3
call test_.bat 4000000 NT3
call test_.bat 5000000 NT3
call test_.bat 6000000 NT3
call test_.bat 7000000 NT3
call test_.bat 8000000 NT3
call test_.bat 9000000 NT3
call test_.bat 10000000 NT3
call test_.bat 20000000 NT3
call test_.bat 30000000 NT3
call test_.bat 40000000 NT3
call test_.bat 50000000 NT3
call test_.bat 60000000 NT3

set  OMP_NUM_THREADS=4
call test_.bat 1000000 NT4
call test_.bat 2000000 NT4
call test_.bat 3000000 NT4
call test_.bat 4000000 NT4
call test_.bat 5000000 NT4
call test_.bat 6000000 NT4
call test_.bat 7000000 NT4
call test_.bat 8000000 NT4
call test_.bat 9000000 NT4
call test_.bat 10000000 NT4
call test_.bat 20000000 NT4
call test_.bat 30000000 NT4
call test_.bat 40000000 NT4
call test_.bat 50000000 NT4
call test_.bat 60000000 NT4

del prog.exe