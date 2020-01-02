cmake_minimum_required(VERSION 3.10)
project(cdb)

add_library(${PROJECT_NAME}_lib src/cdb.cpp)
target_include_directories(${PROJECT_NAME}_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features(${PROJECT_NAME}_lib PUBLIC cxx_std_11)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC ${PROJECT_NAME}_lib readline)

## Installation
install(TARGETS ${PROJECT_NAME} DESTINATION /usr/bin/)
install(FILES cdbConfig.cmake DESTINATION /usr/share/cmake/cdb/)

## Testing
enable_testing()
add_test(NAME ${PROJECT_NAME}_test COMMAND "${CMAKE_CURRENT_SOURCE_DIR}/test.sh")

## Packaging
# SET(CPACK_GENERATOR "DEB")
# set(CPACK_PACKAGE_NAME cdb)
# SET(CPACK_PACKAGE_CONTACT "Nickolai Belakovski")
# SET(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "amd64")
# SET(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6, libgcc1, libreadline7, libstdc++6")
# set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "A debugger for CMake files")

# SET(CPACK_PACKAGE_VERSION_MAJOR "0")
# SET(CPACK_PACKAGE_VERSION_MINOR "1")
# SET(CPACK_PACKAGE_VERSION_PATCH "0")

# INCLUDE(CPack)
