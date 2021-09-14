find_package(${pkgName} CONFIG REQUIRED COMPONENTS ${pkgName})

add_executable(list_pod main.c)
target_link_libraries(list_pod PRIVATE ${pkgName}::${pkgName})