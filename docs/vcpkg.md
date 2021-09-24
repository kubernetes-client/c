# Installing using vcpkg
1- Download vcpkg from https://github.com/microsoft/vcpkg/

2- Run bootstrap-vcpkg script to prepare the repo

3- Install the library using the command:
```
./vcpkg install kubernetes[:triplet]
```
To get a complete list of available triplets, run the command:
```
vcpkg help triplet
```
4- Add vcpkg integration to your project by using the toolchain parameter for cmake:
```
-DCMAKE_TOOLCHAIN_FILE=VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake
```
Or using the parameter in more recent CMake versions:
```
--toolchain VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake
```
5- Add the library to your project using the following CMake commands:
```
find_package(kubernetes CONFIG REQUIRED)
target_link_libraries(PROJECT PRIVATE kubernetes::kubernetes)
```