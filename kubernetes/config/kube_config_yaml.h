#ifndef _KUBE_CONFIG_YAML_H
#define _KUBE_CONFIG_YAML_H

#include "kube_config_model.h"

#ifdef  __cplusplus
extern "C" {

#endif                          /* __cplusplus */

/*
 * kubeyaml_load_kubeconfig
 *
 * Description:
 *
 * Load the kubeconfig file specified by kubeconfig->fileName
 * and get the kuberntes configuration for other fields of kubeconfig.
 *
 * Return:
 *
 *   0     Success
 *  -1     Failed
 *
 * Parameter:
 *
 * IN:
 * kubeconfig->fileName: kubernetes cluster configuration file name
 *
 * OUT:
 * kubeconfig: kubernetes cluster configuration
 */
int kubeyaml_load_kubeconfig(kubeconfig_t * kubeconfig);

#ifdef  __cplusplus
}
#endif                          /* __cplusplus  */
#endif                          /* _KUBE_CONFIG_YAML_H */
