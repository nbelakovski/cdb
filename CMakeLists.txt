cmake_minimum_required(VERSION 3.10)
project(cdb)

set(cdb_DIR /home/nickolai/develop/cdb)
find_package(cdb)



add_executable(${PROJECT_NAME} main.cpp)

break()

target_link_libraries(${PROJECT_NAME} readline)

