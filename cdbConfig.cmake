
find_program(cdb cdb /usr/bin ${CMAKE_CURRENT_SOURCE_DIR}/build)

function(break)
    get_cmake_property(_variableNames VARIABLES)
    list (SORT _variableNames)
    foreach (_variableName ${_variableNames})
        list(APPEND vars "${_variableName}=${${_variableName}}")
    endforeach()
    execute_process(COMMAND bash "-c" "${cdb} '${vars}'")
endfunction()
