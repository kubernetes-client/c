cmake_minimum_required (VERSION 2.6)
project (KubernetesClientAuthnPluginOIDC)

set(BIN_NAME "kubernetes_oidc")

include_directories(../../kubernetes/config)
include_directories(../../kubernetes/config/authn_plugin)
include_directories(../../kubernetes/include/)
include_directories(../../kubernetes/external/)

aux_source_directory(. DIR_SRCS)

add_library(${BIN_NAME} SHARED ${DIR_SRCS})