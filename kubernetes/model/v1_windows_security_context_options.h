/*
 * v1_windows_security_context_options.h
 *
 * WindowsSecurityContextOptions contain Windows-specific options and credentials.
 */

#ifndef _v1_windows_security_context_options_H_
#define _v1_windows_security_context_options_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_windows_security_context_options_t v1_windows_security_context_options_t;




typedef struct v1_windows_security_context_options_t {
    char *gmsa_credential_spec; // string
    char *gmsa_credential_spec_name; // string
    int host_process; //boolean
    char *run_as_user_name; // string

} v1_windows_security_context_options_t;

v1_windows_security_context_options_t *v1_windows_security_context_options_create(
    char *gmsa_credential_spec,
    char *gmsa_credential_spec_name,
    int host_process,
    char *run_as_user_name
);

void v1_windows_security_context_options_free(v1_windows_security_context_options_t *v1_windows_security_context_options);

v1_windows_security_context_options_t *v1_windows_security_context_options_parseFromJSON(cJSON *v1_windows_security_context_optionsJSON);

cJSON *v1_windows_security_context_options_convertToJSON(v1_windows_security_context_options_t *v1_windows_security_context_options);

#endif /* _v1_windows_security_context_options_H_ */

