if (websockets_shared)
    target_link_libraries(${WEBSOCKETS} websockets_shared)
else()
    target_link_libraries(${WEBSOCKETS} websockets)
endif()

target_link_libraries(${pkgName} PRIVATE yaml ${WEBSOCKETS})
set_target_properties(${pkgName} PROPERTIES LINKER_LANGUAGE C)