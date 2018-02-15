cmake_minimum_required(VERSION 3.1)

SET(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_EXTENSIONS OFF)
SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)

SET( CMAKE_CXX_FLAGS "-O2 -Wall" )
#SET( CMAKE_EXE_LINKER_FLAGS "--coverage")

project(quick_type)
add_subdirectory(unittests)
add_subdirectory(benchmark)




