@echo off
rem memory of data < 5GB
copy %1 prog.exe
del results*.txt
cls

set  OMP_NUM_THREADS=1
call test_.bat  1024 NT1
call test_.bat  2048 NT1
call test_.bat  3072 NT1
call test_.bat  4096 NT1
call test_.bat  5120 NT1
call test_.bat  6144 NT1
call test_.bat  7168 NT1
call test_.bat  8192 NT1
call test_.bat  9216 NT1
call test_.bat 10240 NT1
call test_.bat 11264 NT1
call test_.bat 12288 NT1
call test_.bat 13312 NT1

set  OMP_NUM_THREADS=2
call test_.bat  1024 NT2
call test_.bat  2048 NT2
call test_.bat  3072 NT2
call test_.bat  4096 NT2
call test_.bat  5120 NT2
call test_.bat  6144 NT2
call test_.bat  7168 NT2
call test_.bat  8192 NT2
call test_.bat  9216 NT2
call test_.bat 10240 NT2
call test_.bat 11264 NT2
call test_.bat 12288 NT2
call test_.bat 13312 NT2

set  OMP_NUM_THREADS=3
call test_.bat  1024 NT3
call test_.bat  2048 NT3
call test_.bat  3072 NT3
call test_.bat  4096 NT3
call test_.bat  5120 NT3
call test_.bat  6144 NT3
call test_.bat  7168 NT3
call test_.bat  8192 NT3
call test_.bat  9216 NT3
call test_.bat 10240 NT3
call test_.bat 11264 NT3
call test_.bat 12288 NT3
call test_.bat 13312 NT3

set  OMP_NUM_THREADS=4
call test_.bat  1024 NT4
call test_.bat  2048 NT4
call test_.bat  3072 NT4
call test_.bat  4096 NT4
call test_.bat  5120 NT4
call test_.bat  6144 NT4
call test_.bat  7168 NT4
call test_.bat  8192 NT4
call test_.bat  9216 NT4
call test_.bat 10240 NT4
call test_.bat 11264 NT4
call test_.bat 12288 NT4
call test_.bat 13312 NT4

del prog.exe