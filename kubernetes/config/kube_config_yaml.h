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
 *
 */
    int kubeyaml_load_kubeconfig(kubeconfig_t * kubeconfig);

/*
 * kubeyaml_parse_exec_crendential
 *
 * Description:
 *
 * Parse the exec result string to get the kubeconfig exec credential.
 *
 * Return:
 *
 *   0     Success
 *  -1     Failed
 *
 * Parameter:
 *
 * IN:
 * exec_credential_string: text string of kubeconfig exec result
 *
 * OUT:
 * exec_credential: data structure of kubeconfig exec credential
 *
 */
    int kubeyaml_parse_exec_crendential(ExecCredential_t * exec_credential, const char *exec_credential_string);

/*
 * kubeyaml_save_kubeconfig
 *
 * Description:
 *
 * Save the kubeconfig to the file specified by kubeconfig->fileName
 *
 * Return:
 *
 *   0     Success
 *  -1     Failed
 *
 * Parameter:
 *
 * INT:
 * kubeconfig: kubernetes cluster configuration including kubeconfig->fileName: kubernetes cluster configuration file name
 *
 */
    int kubeyaml_save_kubeconfig(const kubeconfig_t * kubeconfig);

#ifdef  __cplusplus
}
#endif                          /* __cplusplus  */
#endif                          /* _KUBE_CONFIG_YAML_H */
