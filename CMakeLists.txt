cmake_minimum_required(VERSION 3.10)
project(parallel_computing C)

set(CMAKE_C_STANDARD 99)

add_executable(parallel_computing
        "4.project/gayss_omp.c"
        "4.project/gauss_mpi.c"
        "1.omp/#01/hello_world.c"
        "1.omp/#02/parallel_vector_addition.c"
        "1.omp/#03/number_of_threds.c"
        "1.omp/#05/matrix_vector_product.c"
        "1.omp/#06/matrix_vector_product.c"
        "1.omp/#07/vector_plus_vector.c"
        "1.omp/#08/merge_sort.c"
        "1.omp/#09/matrix_vector_product.c"
        "1.omp/#10/matrix_matrix_product.c"
        "1.omp/#11/scalar_product.c"
        "1.omp/#12/search_max_element_array.c"
        "1.omp/#13/fibonacci_numbers.c"
        "1.omp/#13/vector_addition.c"
        "1.omp/#14/quick_sort.c"
        "2.mpi/#15/hello_world.c"
        "2.mpi/#16/calculate_pi.c"
        "2.mpi/#17/mpi_helloBsend.c"
        "2.mpi/#19/vector_addition.c"
        "2.mpi/#20/dot_product_send_recv.c"
        "2.mpi/#21/collective_communications.c"
        "2.mpi/#22/matrix_vector_product.c")