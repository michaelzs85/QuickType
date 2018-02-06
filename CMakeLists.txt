cmake_minimum_required(VERSION 2.8)

SET( CMAKE_CXX_FLAGS "-O2 -Wall -std=c++14" )
#SET( CMAKE_EXE_LINKER_FLAGS "--coverage")

project(strong)

SET(headers "strong_type.h" "namedtype.h" "skills.h" "operators.h" "operators_withconvert.h" "operators_witharithmetictypes.h" "conjunction.h")

add_executable(${PROJECT_NAME}_benchmark benchmark.cpp ${headers})
target_link_libraries(${PROJECT_NAME}_benchmark benchmark pthread)

add_executable(${PROJECT_NAME}_unittest "strong_type_unittest.cpp" ${headers})
target_link_libraries(${PROJECT_NAME}_unittest gtest pthread)

add_executable(${PROJECT_NAME}_convert_unittest "strong_type_convert_unittest.cpp" ${headers})
target_link_libraries(${PROJECT_NAME}_convert_unittest gtest pthread)
