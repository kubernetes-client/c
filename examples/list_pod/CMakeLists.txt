add_executable(list_pod main.c)

find_package(${pkgName})

target_link_libraries(list_pod PRIVATE ${pkgName})
target_include_directories(list_pod PRIVATE
        ${CMAKE_SOURCE_DIR}/config
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/api
        )
