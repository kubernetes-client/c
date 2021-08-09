cmake_minimum_required (VERSION 3.14.0)
project (CGenerator)

cmake_policy(SET CMP0063 NEW)

set(CMAKE_C_VISIBILITY_PRESET default)
set(CMAKE_CXX_VISIBILITY_PRESET default)
set(CMAKE_VISIBILITY_INLINES_HIDDEN OFF)

option(BUILD_EXAMPLES "Build examples" OFF)
option(ENABLE_INSTALL "Generate the install target" ON)

set(pkgName "kubernetes")

file(GLOB_RECURSE SRCS *.c)

file(GLOB_RECURSE HDRS *.h)

# Add library with project file with projectname as library name
add_library(${pkgName} ${SRCS} ${HDRS})

target_include_directories(${pkgName} PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/kubernetes>
		$<INSTALL_INTERFACE:include>
		)

find_package(OpenSSL)

if (OPENSSL_FOUND)
	message (STATUS "OPENSSL found")
	target_link_libraries(${pkgName} OpenSSL::SSL OpenSSL::Crypto)
	add_compile_definitions(OPENSSL)
	message(STATUS "Using OpenSSL ${OPENSSL_VERSION}")
else() 
	message (STATUS "OpenSSL Not found.")
endif()

find_package(CURL 7.58.0 REQUIRED)
if(CURL_FOUND)
	include_directories(${CURL_INCLUDE_DIR})
	set(PLATFORM_LIBRARIES ${PLATFORM_LIBRARIES} ${CURL_LIBRARIES} )
else(CURL_FOUND)
	message(FATAL_ERROR "Could not find the CURL library and development files.")
endif()

find_package(libwebsockets REQUIRED)
find_package(yaml CONFIG REQUIRED)

# Link dependent libraries
target_link_libraries(${pkgName} ${CURL_LIBRARIES} yaml)

if (ENABLE_INSTALL)
	include(GNUInstallDirs)
	install(TARGETS ${pkgName}
			EXPORT ${pkgName}Targets
			)

	foreach(HDR_FILE ${HDRS})
		get_filename_component(HDR_DIRECTORY ${HDR_FILE} DIRECTORY)
		get_filename_component(ABSOLUTE_HDR_DIRECTORY ${HDR_DIRECTORY} ABSOLUTE)
		file(RELATIVE_PATH RELATIVE_HDR_PATH ${CMAKE_CURRENT_SOURCE_DIR} ${ABSOLUTE_HDR_DIRECTORY})
		install(FILES ${HDR_FILE} DESTINATION include/${RELATIVE_HDR_PATH})
	endforeach()

	include(CMakePackageConfigHelpers)
	write_basic_package_version_file(
			"${CMAKE_CURRENT_BINARY_DIR}/${pkgName}/${pkgName}ConfigVersion.cmake"
			VERSION 0.0.1
			COMPATIBILITY AnyNewerVersion
	)

	export(EXPORT ${pkgName}Targets
			FILE "${CMAKE_CURRENT_BINARY_DIR}/${pkgName}/${pkgName}Targets.cmake"
			NAMESPACE ${pkgName}::
			)

	configure_file(../cmake/${pkgName}Config.cmake.in
			"${CMAKE_CURRENT_BINARY_DIR}/${pkgName}/${pkgName}Config.cmake"
			@ONLY
			)

	set(ConfigPackageLocation lib/cmake/${pkgName})
	install(EXPORT ${pkgName}Targets
			FILE
			${pkgName}Targets.cmake
			NAMESPACE
			${pkgName}::
			DESTINATION
			${ConfigPackageLocation}
			)
	install(
			FILES
			"${CMAKE_CURRENT_BINARY_DIR}/${pkgName}/${pkgName}Config.cmake"
			"${CMAKE_CURRENT_BINARY_DIR}/${pkgName}/${pkgName}ConfigVersion.cmake"
			DESTINATION
			${ConfigPackageLocation}
	)
endif()


if(BUILD_EXAMPLES)
	message("Include examples")
	add_subdirectory(../examples examples)
endif()

## This section shows how to use the above compiled libary to compile the source files
## set source files
#set(SRCS
#    unit-tests/manual-AdmissionregistrationAPI.c
#    unit-tests/manual-AdmissionregistrationV1API.c
#    unit-tests/manual-AdmissionregistrationV1beta1API.c
#    unit-tests/manual-ApiextensionsAPI.c
#    unit-tests/manual-ApiextensionsV1API.c
#    unit-tests/manual-ApiextensionsV1beta1API.c
#    unit-tests/manual-ApiregistrationAPI.c
#    unit-tests/manual-ApiregistrationV1API.c
#    unit-tests/manual-ApiregistrationV1beta1API.c
#    unit-tests/manual-ApisAPI.c
#    unit-tests/manual-AppsAPI.c
#    unit-tests/manual-AppsV1API.c
#    unit-tests/manual-AppsV1beta1API.c
#    unit-tests/manual-AppsV1beta2API.c
#    unit-tests/manual-AuditregistrationAPI.c
#    unit-tests/manual-AuditregistrationV1alpha1API.c
#    unit-tests/manual-AuthenticationAPI.c
#    unit-tests/manual-AuthenticationV1API.c
#    unit-tests/manual-AuthenticationV1beta1API.c
#    unit-tests/manual-AuthorizationAPI.c
#    unit-tests/manual-AuthorizationV1API.c
#    unit-tests/manual-AuthorizationV1beta1API.c
#    unit-tests/manual-AutoscalingAPI.c
#    unit-tests/manual-AutoscalingV1API.c
#    unit-tests/manual-AutoscalingV2beta1API.c
#    unit-tests/manual-AutoscalingV2beta2API.c
#    unit-tests/manual-BatchAPI.c
#    unit-tests/manual-BatchV1API.c
#    unit-tests/manual-BatchV1beta1API.c
#    unit-tests/manual-BatchV2alpha1API.c
#    unit-tests/manual-CertificatesAPI.c
#    unit-tests/manual-CertificatesV1beta1API.c
#    unit-tests/manual-CoordinationAPI.c
#    unit-tests/manual-CoordinationV1API.c
#    unit-tests/manual-CoordinationV1beta1API.c
#    unit-tests/manual-CoreAPI.c
#    unit-tests/manual-CoreV1API.c
#    unit-tests/manual-CustomObjectsAPI.c
#    unit-tests/manual-DiscoveryAPI.c
#    unit-tests/manual-DiscoveryV1beta1API.c
#    unit-tests/manual-EventsAPI.c
#    unit-tests/manual-EventsV1beta1API.c
#    unit-tests/manual-ExtensionsAPI.c
#    unit-tests/manual-ExtensionsV1beta1API.c
#    unit-tests/manual-FlowcontrolApiserverAPI.c
#    unit-tests/manual-FlowcontrolApiserverV1alpha1API.c
#    unit-tests/manual-LogsAPI.c
#    unit-tests/manual-NetworkingAPI.c
#    unit-tests/manual-NetworkingV1API.c
#    unit-tests/manual-NetworkingV1beta1API.c
#    unit-tests/manual-NodeAPI.c
#    unit-tests/manual-NodeV1alpha1API.c
#    unit-tests/manual-NodeV1beta1API.c
#    unit-tests/manual-PolicyAPI.c
#    unit-tests/manual-PolicyV1beta1API.c
#    unit-tests/manual-RbacAuthorizationAPI.c
#    unit-tests/manual-RbacAuthorizationV1API.c
#    unit-tests/manual-RbacAuthorizationV1alpha1API.c
#    unit-tests/manual-RbacAuthorizationV1beta1API.c
#    unit-tests/manual-SchedulingAPI.c
#    unit-tests/manual-SchedulingV1API.c
#    unit-tests/manual-SchedulingV1alpha1API.c
#    unit-tests/manual-SchedulingV1beta1API.c
#    unit-tests/manual-SettingsAPI.c
#    unit-tests/manual-SettingsV1alpha1API.c
#    unit-tests/manual-StorageAPI.c
#    unit-tests/manual-StorageV1API.c
#    unit-tests/manual-StorageV1alpha1API.c
#    unit-tests/manual-StorageV1beta1API.c
#    unit-tests/manual-VersionAPI.c
#)

##set header files
#set(HDRS
#)

## loop over all files in SRCS variable
#foreach(SOURCE_FILE ${SRCS})
#    # Get only the file name from the file as add_executable doesnot support executable with slash("/")
#    get_filename_component(FILE_NAME_ONLY ${SOURCE_FILE} NAME_WE)
#    # Remove .c from the file name and set it as executable name
#    string( REPLACE ".c" "" EXECUTABLE_FILE ${FILE_NAME_ONLY})
#    # Add executable for every source file in  SRCS
#    add_executable(unit-${EXECUTABLE_FILE} ${SOURCE_FILE})
#    # Link above created libary to executable and dependent libary curl
#    target_link_libraries(unit-${EXECUTABLE_FILE} ${CURL_LIBRARIES} ${pkgName} )
#endforeach(SOURCE_FILE ${SRCS})
