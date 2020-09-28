cmake_minimum_required(VERSION 3.17)
project(SO_Lab1_20201 C)

set(CMAKE_C_STANDARD 11)

add_executable(SO_Lab1_20201
        ejemplos/ejemplos_argc_argv/edad.c
        ejemplos/miselanea/ejemplo1_sol.c
        ejemplos/miselanea/ejemplo2_sol.c
        ejemplos/miselanea/ejemplo3_sol.c
        ejemplos/miselanea/ejemplo4_sol.c
        ejemplos/miselanea/ejemplo5_sol.c
        enunciado/wcat/wcat.c
        enunciado/wget/wgrep.c
        enunciado/wunzip/wunzip.c)
