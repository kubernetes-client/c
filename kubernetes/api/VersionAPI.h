#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/version_info.h"


// get the code version
//
version_info_t*
VersionAPI_getCode(apiClient_t *apiClient);


