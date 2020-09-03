#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "AuthenticationV1beta1API.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define intToStr(dst, src) \
    do {\
    char dst[256];\
    snprintf(dst, 256, "%ld", (long int)(src));\
}while(0)


// create a TokenReview
//
v1beta1_token_review_t*
AuthenticationV1beta1API_createTokenReview(apiClient_t *apiClient, v1beta1_token_review_t * body , char * dryRun , char * fieldManager , char * pretty )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/authentication.k8s.io/v1beta1/tokenreviews")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/authentication.k8s.io/v1beta1/tokenreviews");




    // query parameters
    char *keyQuery_dryRun = NULL;
    char * valueQuery_dryRun = NULL;
    keyValuePair_t *keyPairQuery_dryRun = 0;
    if (dryRun)
    {
        keyQuery_dryRun = strdup("dryRun");
        valueQuery_dryRun = strdup((dryRun));
        keyPairQuery_dryRun = keyValuePair_create(keyQuery_dryRun, valueQuery_dryRun);
        list_addElement(localVarQueryParameters,keyPairQuery_dryRun);
    }

    // query parameters
    char *keyQuery_fieldManager = NULL;
    char * valueQuery_fieldManager = NULL;
    keyValuePair_t *keyPairQuery_fieldManager = 0;
    if (fieldManager)
    {
        keyQuery_fieldManager = strdup("fieldManager");
        valueQuery_fieldManager = strdup((fieldManager));
        keyPairQuery_fieldManager = keyValuePair_create(keyQuery_fieldManager, valueQuery_fieldManager);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldManager);
    }

    // query parameters
    char *keyQuery_pretty = NULL;
    char * valueQuery_pretty = NULL;
    keyValuePair_t *keyPairQuery_pretty = 0;
    if (pretty)
    {
        keyQuery_pretty = strdup("pretty");
        valueQuery_pretty = strdup((pretty));
        keyPairQuery_pretty = keyValuePair_create(keyQuery_pretty, valueQuery_pretty);
        list_addElement(localVarQueryParameters,keyPairQuery_pretty);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1beta1_token_review_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
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
                    "POST");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 201) {
        printf("%s\n","Created");
    }
    if (apiClient->response_code == 202) {
        printf("%s\n","Accepted");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not container
    cJSON *AuthenticationV1beta1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1beta1_token_review_t *elementToReturn = v1beta1_token_review_parseFromJSON(AuthenticationV1beta1APIlocalVarJSON);
    cJSON_Delete(AuthenticationV1beta1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
    if(keyQuery_dryRun){
        free(keyQuery_dryRun);
        keyQuery_dryRun = NULL;
    }
    if(valueQuery_dryRun){
        free(valueQuery_dryRun);
        valueQuery_dryRun = NULL;
    }
    if(keyPairQuery_dryRun){
        keyValuePair_free(keyPairQuery_dryRun);
        keyPairQuery_dryRun = NULL;
    }
    if(keyQuery_fieldManager){
        free(keyQuery_fieldManager);
        keyQuery_fieldManager = NULL;
    }
    if(valueQuery_fieldManager){
        free(valueQuery_fieldManager);
        valueQuery_fieldManager = NULL;
    }
    if(keyPairQuery_fieldManager){
        keyValuePair_free(keyPairQuery_fieldManager);
        keyPairQuery_fieldManager = NULL;
    }
    if(keyQuery_pretty){
        free(keyQuery_pretty);
        keyQuery_pretty = NULL;
    }
    if(valueQuery_pretty){
        free(valueQuery_pretty);
        valueQuery_pretty = NULL;
    }
    if(keyPairQuery_pretty){
        keyValuePair_free(keyPairQuery_pretty);
        keyPairQuery_pretty = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// get available resources
//
v1_api_resource_list_t*
AuthenticationV1beta1API_getAPIResources(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/authentication.k8s.io/v1beta1/")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/authentication.k8s.io/v1beta1/");



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
    cJSON *AuthenticationV1beta1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_api_resource_list_t *elementToReturn = v1_api_resource_list_parseFromJSON(AuthenticationV1beta1APIlocalVarJSON);
    cJSON_Delete(AuthenticationV1beta1APIlocalVarJSON);
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

