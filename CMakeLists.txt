cmake_minimum_required(VERSION 2.8)

SET( CMAKE_CXX_FLAGS "-O2 -Wall -std=c++14" )
#SET( CMAKE_EXE_LINKER_FLAGS "--coverage")

project(strong)

if(EXISTS unittests)
  add_subdirectory(unittests)
endif(EXISTS unittests)

if(EXISTS benchmark)
  add_subdirectory(benchmark)
endif(EXISTS benchmark)

SET(headers "quick_type/strong_type.h" "quick_type/namedtype.h" "quick_type/skills.h" "quick_type/operators.h" "quick_type/operators_withconvert.h" "quick_type/operators_witharithmetictypes.h" "quick_type/conjunction.h")




