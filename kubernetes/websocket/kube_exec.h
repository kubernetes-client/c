#ifndef _KUBE_EXEC_H
#define _KUBE_EXEC_H

#include "wsclient.h"

#ifdef  __cplusplus
extern "C" {
#endif

#undef stdin
#undef stdout

int kube_exec(wsclient_t * wsc, const char *namespace_, const char *pod_name, const char *container_name, int stdin, int stdout, int tty, const char *command);

#ifdef  __cplusplus
}
#endif
#endif                          /* _EXEC_H */
