if (TARGET websockets_shared)
    set(${WEBSOCKETS} websockets_shared)
else()
    set(${WEBSOCKETS} websockets)
endif()

target_link_libraries(${pkgName} PRIVATE yaml ${WEBSOCKETS})
set_target_properties(${pkgName} PROPERTIES LINKER_LANGUAGE C)