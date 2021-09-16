#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"


// get service account issuer OpenID JSON Web Key Set (contains public token verification keys)
//
char*
OpenidAPI_getServiceAccountIssuerOpenIDKeyset(apiClient_t *apiClient);


