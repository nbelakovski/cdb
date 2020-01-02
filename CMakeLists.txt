cmake_minimum_required(VERSION 3.10)
project(cdb)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} readline)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_11)

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
