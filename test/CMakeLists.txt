cmake_minimum_required(VERSION 3.10)
project(test)

set(cdb_DIR ${CMAKE_CURRENT_SOURCE_DIR}/..)
# find cdb program before the find_package call
# while this means we don't test the find_program part, it also means we don't need sudo access on a machine
# in order to test
find_program(cdb cdb ${CMAKE_CURRENT_SOURCE_DIR}/../build)
find_package(cdb)

break()

