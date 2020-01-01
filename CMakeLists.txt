cmake_minimum_required(VERSION 3.10)
project(cdb)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} readline)

enable_testing()
add_test(NAME ${PROJECT_NAME}_test COMMAND "${CMAKE_CURRENT_SOURCE_DIR}/test.sh")
