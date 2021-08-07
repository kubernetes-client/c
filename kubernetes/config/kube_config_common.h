#ifndef _KUBE_CONFIG_COMMON_H
#define _KUBE_CONFIG_COMMON_H

#ifdef  __cplusplus
extern "C" {
#endif

#define AUTH_TOKEN_KEY "Authorization"
#define BEARER_TOKEN_TEMPLATE "Bearer %s"
#define BEARER_TOKEN_BUFFER_SIZE 2048
#define BASIC_TOKEN_TEMPLATE "Basic %s"
#define BASIC_TOKEN_BUFFER_SIZE 1024

#ifdef  __cplusplus
}
#endif
#endif                          /* _KUBE_CONFIG_COMMON_H */
