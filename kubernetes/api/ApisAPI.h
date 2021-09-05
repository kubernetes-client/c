#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/v1_api_group_list.h"

#undef stdin
#undef stderr
#undef stdout


// get available API versions
//
v1_api_group_list_t*
ApisAPI_getAPIVersions(apiClient_t *apiClient);


