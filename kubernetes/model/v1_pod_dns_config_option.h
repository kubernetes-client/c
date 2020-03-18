/*
 * v1_pod_dns_config_option.h
 *
 * PodDNSConfigOption defines DNS resolver options of a pod.
 */

#ifndef _v1_pod_dns_config_option_H_
#define _v1_pod_dns_config_option_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_pod_dns_config_option_t {
    char *name; // string
    char *value; // string

} v1_pod_dns_config_option_t;

v1_pod_dns_config_option_t *v1_pod_dns_config_option_create(
    char *name,
    char *value
);

void v1_pod_dns_config_option_free(v1_pod_dns_config_option_t *v1_pod_dns_config_option);

v1_pod_dns_config_option_t *v1_pod_dns_config_option_parseFromJSON(cJSON *v1_pod_dns_config_optionJSON);

cJSON *v1_pod_dns_config_option_convertToJSON(v1_pod_dns_config_option_t *v1_pod_dns_config_option);

#endif /* _v1_pod_dns_config_option_H_ */

