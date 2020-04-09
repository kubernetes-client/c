#ifndef _INCLUSTER_CONFIG_H
#define _INCLUSTER_CONFIG_H

#include "../include/apiClient.h"

#ifdef  __cplusplus
extern "C" {
#endif

/*
 * load_incluster_config
 *
 *
 * Description:
 *
 *
 * Load kubernetes cluster configuration from service account 
 * files inside a pod
 *
 *
 * Return:
 *
 *   0     Success
 *  -1     Failed
 *
 *
 * Parameter:
 *
 *
 * IN:

 * None
 *
 *
 * OUT:
 *
 * pBasePath: The pointer to API server address
 * pSslConfig: The pointer to SSL configuration for client
 * pApiKeys: The pointer to API tokens for client
 *
 * The memory will be allocated inside this function. User
 * should call free_client_config to free the memory after
 * these parameters are not used.
 *
 */

    int load_incluster_config(char **pBasePath, sslConfig_t ** pSslConfig, list_t ** pApiKeys);

#ifdef  __cplusplus
}
#endif
#endif                          /* _INCLUSTER_CONFIG_H */
