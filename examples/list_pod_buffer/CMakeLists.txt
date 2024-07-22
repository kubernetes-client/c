find_package(${pkgName} CONFIG REQUIRED COMPONENTS ${pkgName})

add_executable(list_pod_buffer main.c)
target_link_libraries(list_pod_buffer PRIVATE ${pkgName}::${pkgName})