#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/v1_api_group_list.h"


// get available API versions
//
v1_api_group_list_t*
ApisAPI_getAPIVersions_0(apiClient_t *apiClient);


