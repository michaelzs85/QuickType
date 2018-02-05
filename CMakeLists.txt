cmake_minimum_required(VERSION 2.8)

SET( CMAKE_CXX_FLAGS "-O2 -Wall -std=c++11" )

project(strong)

SET(headers "strong_type.h" "namedtype.h" "skills.h" "operators.h" "operators_withconvert.h" "operators_witharithmetictypes.h" "conjunction.h")

add_executable(${PROJECT_NAME}_benchmark benchmark.cpp ${headers})
target_link_libraries(${PROJECT_NAME}_benchmark benchmark pthread)

add_executable(${PROJECT_NAME}_unittest "strong_type_unittest.cpp" ${headers})
target_link_libraries(${PROJECT_NAME}_unittest gtest pthread)
