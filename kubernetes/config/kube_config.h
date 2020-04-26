#ifndef _KUBE_CONFIG_H
#define _KUBE_CONFIG_H

#include "../include/apiClient.h"

#ifdef  __cplusplus
extern "C" {
#endif

/*
 * load_kube_config
 *
 *
 * Description:
 *
 *
 * Load kubernetes cluster configuration from the file specified 
 * by parameter or default location: $HOME/.kube/config
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

 * configFileName : kubernetes cluster configuration file name
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

    int load_kube_config(char **pBasePath, sslConfig_t ** pSslConfig, list_t ** pApiKeys, const char *configFileName);

/*
 * free_client_config
 *
 *
 * Description:
 *
 * Help function to free the memory for the client configuration
 *
 *
 * Return:
 *
 * None
 * 
 *
 * Parameter:
 *
 * IN:
 *
 * basePath: API server address
 * sslConfig: SSL configuration for client
 * apiKeys: API tokens for client
 *
 * OUT:
 *
 * None
 *
 */

    void free_client_config(char *basePath, sslConfig_t * sslConfig, list_t * apiKeys);

#ifdef  __cplusplus
}
#endif
#endif                          /* _KUBE_CONFIG_H */
