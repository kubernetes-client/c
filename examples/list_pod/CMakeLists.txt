add_executable(list_pod main.c)

find_package(${pkgName})

target_link_libraries(list_pod PRIVATE ${pkgName})
