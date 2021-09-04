#ifndef __MT_H__
#define __MT_H__

#include "../include/apiClient.h"

#ifdef  __cplusplus
extern "C" {
#endif

#include <malloc.h>
#include <stdio.h>
#include <errno.h>
#ifndef _WIN32
#include <unistd.h>
#endif
#include <pthread.h>
#include <apiClient.h>
#include <CoreV1API.h>

typedef struct kube_params_t {
    char *basePath;
    sslConfig_t *sslConfig;
    list_t *apiKeys;
} kube_params_t;

extern void *watch_pod_thread_func(void *);
extern void *create_pod_thread_func(void *);

extern bool g_exit_watch;
extern pthread_mutex_t exit_watch_mutex;

#ifdef  __cplusplus
}
#endif
#endif                          // __MT_H__
