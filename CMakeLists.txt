cmake_minimum_required(VERSION 3.1)

SET( CMAKE_CXX_FLAGS "-O2 -Wall -std=c++14" )
#SET( CMAKE_EXE_LINKER_FLAGS "--coverage")

project(strong)
add_subdirectory(unittests)
add_subdirectory(benchmark)




