#ifndef _AUTHN_PLUGIN_H
#define _AUTHN_PLUGIN_H

#include <stdbool.h>
#include "../kube_config_model.h"

#ifdef  __cplusplus
extern "C" {
#endif

    typedef struct authn_plugin_t {
        char *name;
        void *dlhandler;
        char *(*get_token) (kubeconfig_property_t *);
        bool (*is_expired) (kubeconfig_property_t *);
        int (*refresh) (kubeconfig_property_t *);
    } authn_plugin_t;

    authn_plugin_t *create_authn_plugin(const char *);
    void free_authn_plugin(authn_plugin_t *);

#ifdef  __cplusplus
}
#endif
#endif                          /* _AUTHN_PLUGIN_H */
