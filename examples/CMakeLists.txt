cmake_minimum_required (VERSION 2.6...3.10.2)
project(examples)

enable_language(C)
enable_language(CXX)

set(pkgName "kubernetes")

add_subdirectory(list_pod)
