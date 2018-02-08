 
include_directories(../quick_type)

add_executable(operators_unittest "operators_unittest.cpp" ${headers})
target_link_libraries(operators_unittest gtest pthread)

add_executable(operators_withconvert_unittest "operators_withconvert_unittest.cpp" ${headers})
target_link_libraries(operators_withconvert_unittest gtest pthread)

add_executable(operators_witharithmetictypes_unittest "operators_witharithmetictypes_unittest.cpp" ${headers})
target_link_libraries(operators_witharithmetictypes_unittest gtest pthread)
