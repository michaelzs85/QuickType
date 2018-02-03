cmake_minimum_required(VERSION 2.8)

SET( CMAKE_CXX_FLAGS "-O2 -Wall -std=c++11" )

project(strong)
add_executable(${PROJECT_NAME} "main.cpp" namedtype.h skills.h operators.h)
