#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"


// get service account issuer OpenID configuration, also known as the 'OIDC discovery doc'
//
char*
WellKnownAPI_getServiceAccountIssuerOpenIDConfiguration(apiClient_t *apiClient);


