cmake_minimum_required(VERSION 3.10)
project(cdb)

get_cmake_property(_variableNames VARIABLES)
list (SORT _variableNames)
foreach (_variableName ${_variableNames})
    list(APPEND vars "${_variableName}=${${_variableName}}")
    message(STATUS "${_variableName}=${${_variableName}}")
endforeach()
execute_process(COMMAND bash "-c" "./cdb '${vars}'")

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} readline)

