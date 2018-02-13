enable_testing()
#find_package(GTest REQUIRED)

#cmake_policy(SET CMP0054 OLD)
#include(GoogleTest)
include_directories(../quick_type)

add_executable(operators_unittest "operators_unittest.cpp")
target_link_libraries(operators_unittest gtest pthread)
add_test(OperatorTests operators_unittest)


add_executable(operators_withconvert_unittest "operators_withconvert_unittest.cpp")
target_link_libraries(operators_withconvert_unittest gtest pthread)
add_test(OperatorConvertTests operators_withconvert_unittest)

add_executable(operators_witharithmetictypes_unittest "operators_witharithmetictypes_unittest.cpp")
target_link_libraries(operators_witharithmetictypes_unittest gtest pthread)
add_test(OperatorArithmeticTests operators_witharithmetictypes_unittest)
