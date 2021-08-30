target_link_libraries(${pkgName} yaml websockets)
set_target_properties(${pkgName} PROPERTIES LINKER_LANGUAGE C)

option(BUILD_EXAMPLES "Build examples" OFF)

if(BUILD_EXAMPLES)
    message("Include examples")
    add_subdirectory(../examples examples)
endif()