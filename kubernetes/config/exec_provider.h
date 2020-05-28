#ifndef _EXEC_PROVIDER_H
#define _EXEC_PROVIDER_H

#include "kube_config_model.h"

#ifdef  __cplusplus
extern "C" {
#endif

    /*
     * kube_exec_and_get_result
     *
     *
     * Description:
     *
     *
     * run exec command and get result of authentication 
     *
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
     * 
     * exec: kubeconfig exec configuration
     *
     * OUT:
     *
     * exec_credential: result of exec
     *
     *
     */

    int kube_exec_and_get_result(ExecCredential_t * exec_credential, const kubeconfig_property_t * exec);

#ifdef  __cplusplus
}
#endif
#endif                          /* _EXEC_PROVIDER_H */
