cmake_minimum_required(VERSION 3.10)
project(parallel_computing C)

set(CMAKE_C_STANDARD 99)

add_executable(parallel_computing "4. project/gayss_omp.c" "4. project/gauss_cuda.c" "4. project/gauss_mpi.c" "1.omp/#01/hello_world.c")