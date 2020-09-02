#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "CoordinationAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define intToStr(dst, src) \
    do {\
    char dst[256];\
    snprintf(dst, 256, "%ld", (long int)(src));\
}while(0)


// get information of a group
//
v1_api_group_t*
CoordinationAPI_getAPIGroup(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/coordination.k8s.io/")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/coordination.k8s.io/");



    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not container
    cJSON *CoordinationAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_api_group_t *elementToReturn = v1_api_group_parseFromJSON(CoordinationAPIlocalVarJSON);
    cJSON_Delete(CoordinationAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

