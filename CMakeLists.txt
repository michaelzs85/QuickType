cmake_minimum_required(VERSION 2.8)

SET( CMAKE_CXX_FLAGS "-O2 -Wall -std=c++14" )
#SET( CMAKE_EXE_LINKER_FLAGS "--coverage")

project(strong)

SET(headers "strong_type.h" "namedtype.h" "skills.h" "operators.h" "operators_withconvert.h" "operators_witharithmetictypes.h" "conjunction.h")

add_executable(${PROJECT_NAME}_benchmark benchmark.cpp ${headers})
target_link_libraries(${PROJECT_NAME}_benchmark benchmark pthread)

add_executable(operators_unittest "operators_unittest.cpp" ${headers})
target_link_libraries(operators_unittest gtest pthread)

add_executable(operators_withconvert_unittest "operators_withconvert_unittest.cpp" ${headers})
target_link_libraries(operators_withconvert_unittest gtest pthread)

add_executable(operators_witharithmetictypes_unittest "operators_witharithmetictypes_unittest.cpp" ${headers})
target_link_libraries(operators_witharithmetictypes_unittest gtest pthread)
