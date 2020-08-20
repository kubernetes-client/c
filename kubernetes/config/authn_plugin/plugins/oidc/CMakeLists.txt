cmake_minimum_required (VERSION 2.6)
project (KubernetesClientAuthnPluginOIDC)

set(CMAKE_BUILD_TYPE Debug)

set(BIN_NAME "kubernetes_oidc")

include_directories(../../)
include_directories(../../../)
include_directories(../../../../include/)
include_directories(../../../../external/)

aux_source_directory(. DIR_SRCS)

add_library(${BIN_NAME} SHARED ${DIR_SRCS})