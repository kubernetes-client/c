target_link_libraries(${pkgName} PRIVATE yaml websockets_shared)
set_target_properties(${pkgName} PROPERTIES LINKER_LANGUAGE C)