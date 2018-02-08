include_directories(../quick_type)

add_executable(${PROJECT_NAME}_benchmark benchmark.cpp ${headers})
target_link_libraries(${PROJECT_NAME}_benchmark benchmark pthread)
