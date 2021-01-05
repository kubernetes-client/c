#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "AppsV1API.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define intToStr(dst, src) \
    do {\
    char dst[256];\
    snprintf(dst, 256, "%ld", (long int)(src));\
}while(0)


// create a ControllerRevision
//
v1_controller_revision_t*
AppsV1API_createNamespacedControllerRevision(apiClient_t *apiClient, char * _namespace , v1_controller_revision_t * body , char * pretty , char * dryRun , char * fieldManager )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/controllerrevisions")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/controllerrevisions");


    // Path Params
    long sizeOfPathParams__namespace = strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_controller_revision_convertToJSON(body);
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
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_controller_revision_t *elementToReturn = v1_controller_revision_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    free(localVarToReplace__namespace);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// create a DaemonSet
//
v1_daemon_set_t*
AppsV1API_createNamespacedDaemonSet(apiClient_t *apiClient, char * _namespace , v1_daemon_set_t * body , char * pretty , char * dryRun , char * fieldManager )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/daemonsets")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/daemonsets");


    // Path Params
    long sizeOfPathParams__namespace = strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_daemon_set_convertToJSON(body);
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
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_daemon_set_t *elementToReturn = v1_daemon_set_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    free(localVarToReplace__namespace);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// create a Deployment
//
v1_deployment_t*
AppsV1API_createNamespacedDeployment(apiClient_t *apiClient, char * _namespace , v1_deployment_t * body , char * pretty , char * dryRun , char * fieldManager )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/deployments")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/deployments");


    // Path Params
    long sizeOfPathParams__namespace = strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_deployment_convertToJSON(body);
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
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_deployment_t *elementToReturn = v1_deployment_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    free(localVarToReplace__namespace);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// create a ReplicaSet
//
v1_replica_set_t*
AppsV1API_createNamespacedReplicaSet(apiClient_t *apiClient, char * _namespace , v1_replica_set_t * body , char * pretty , char * dryRun , char * fieldManager )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/replicasets")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/replicasets");


    // Path Params
    long sizeOfPathParams__namespace = strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_replica_set_convertToJSON(body);
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
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_replica_set_t *elementToReturn = v1_replica_set_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    free(localVarToReplace__namespace);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// create a StatefulSet
//
v1_stateful_set_t*
AppsV1API_createNamespacedStatefulSet(apiClient_t *apiClient, char * _namespace , v1_stateful_set_t * body , char * pretty , char * dryRun , char * fieldManager )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/statefulsets")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/statefulsets");


    // Path Params
    long sizeOfPathParams__namespace = strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_stateful_set_convertToJSON(body);
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
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_stateful_set_t *elementToReturn = v1_stateful_set_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    free(localVarToReplace__namespace);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// delete collection of ControllerRevision
//
v1_status_t*
AppsV1API_deleteCollectionNamespacedControllerRevision(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , v1_delete_options_t * body )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/controllerrevisions")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/controllerrevisions");


    // Path Params
    long sizeOfPathParams__namespace = strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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

    // query parameters
    char *keyQuery__continue = NULL;
    char * valueQuery__continue = NULL;
    keyValuePair_t *keyPairQuery__continue = 0;
    if (_continue)
    {
        keyQuery__continue = strdup("continue");
        valueQuery__continue = strdup((_continue));
        keyPairQuery__continue = keyValuePair_create(keyQuery__continue, valueQuery__continue);
        list_addElement(localVarQueryParameters,keyPairQuery__continue);
    }

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
    char *keyQuery_fieldSelector = NULL;
    char * valueQuery_fieldSelector = NULL;
    keyValuePair_t *keyPairQuery_fieldSelector = 0;
    if (fieldSelector)
    {
        keyQuery_fieldSelector = strdup("fieldSelector");
        valueQuery_fieldSelector = strdup((fieldSelector));
        keyPairQuery_fieldSelector = keyValuePair_create(keyQuery_fieldSelector, valueQuery_fieldSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldSelector);
    }

    // query parameters
    char *keyQuery_gracePeriodSeconds = NULL;
    char * valueQuery_gracePeriodSeconds = NULL;
    keyValuePair_t *keyPairQuery_gracePeriodSeconds = 0;
    if (gracePeriodSeconds)
    {
        keyQuery_gracePeriodSeconds = strdup("gracePeriodSeconds");
        valueQuery_gracePeriodSeconds = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_gracePeriodSeconds, MAX_NUMBER_LENGTH, "%d", gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = keyValuePair_create(keyQuery_gracePeriodSeconds, valueQuery_gracePeriodSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_gracePeriodSeconds);
    }

    // query parameters
    char *keyQuery_labelSelector = NULL;
    char * valueQuery_labelSelector = NULL;
    keyValuePair_t *keyPairQuery_labelSelector = 0;
    if (labelSelector)
    {
        keyQuery_labelSelector = strdup("labelSelector");
        valueQuery_labelSelector = strdup((labelSelector));
        keyPairQuery_labelSelector = keyValuePair_create(keyQuery_labelSelector, valueQuery_labelSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_labelSelector);
    }

    // query parameters
    char *keyQuery_limit = NULL;
    char * valueQuery_limit = NULL;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_limit, MAX_NUMBER_LENGTH, "%d", limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, valueQuery_limit);
        list_addElement(localVarQueryParameters,keyPairQuery_limit);
    }

    // query parameters
    char *keyQuery_orphanDependents = NULL;
    char * valueQuery_orphanDependents = NULL;
    keyValuePair_t *keyPairQuery_orphanDependents = 0;
    if (orphanDependents)
    {
        keyQuery_orphanDependents = strdup("orphanDependents");
        valueQuery_orphanDependents = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_orphanDependents, MAX_NUMBER_LENGTH, "%d", orphanDependents);
        keyPairQuery_orphanDependents = keyValuePair_create(keyQuery_orphanDependents, valueQuery_orphanDependents);
        list_addElement(localVarQueryParameters,keyPairQuery_orphanDependents);
    }

    // query parameters
    char *keyQuery_propagationPolicy = NULL;
    char * valueQuery_propagationPolicy = NULL;
    keyValuePair_t *keyPairQuery_propagationPolicy = 0;
    if (propagationPolicy)
    {
        keyQuery_propagationPolicy = strdup("propagationPolicy");
        valueQuery_propagationPolicy = strdup((propagationPolicy));
        keyPairQuery_propagationPolicy = keyValuePair_create(keyQuery_propagationPolicy, valueQuery_propagationPolicy);
        list_addElement(localVarQueryParameters,keyPairQuery_propagationPolicy);
    }

    // query parameters
    char *keyQuery_resourceVersion = NULL;
    char * valueQuery_resourceVersion = NULL;
    keyValuePair_t *keyPairQuery_resourceVersion = 0;
    if (resourceVersion)
    {
        keyQuery_resourceVersion = strdup("resourceVersion");
        valueQuery_resourceVersion = strdup((resourceVersion));
        keyPairQuery_resourceVersion = keyValuePair_create(keyQuery_resourceVersion, valueQuery_resourceVersion);
        list_addElement(localVarQueryParameters,keyPairQuery_resourceVersion);
    }

    // query parameters
    char *keyQuery_timeoutSeconds = NULL;
    char * valueQuery_timeoutSeconds = NULL;
    keyValuePair_t *keyPairQuery_timeoutSeconds = 0;
    if (timeoutSeconds)
    {
        keyQuery_timeoutSeconds = strdup("timeoutSeconds");
        valueQuery_timeoutSeconds = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_timeoutSeconds, MAX_NUMBER_LENGTH, "%d", timeoutSeconds);
        keyPairQuery_timeoutSeconds = keyValuePair_create(keyQuery_timeoutSeconds, valueQuery_timeoutSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_timeoutSeconds);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_delete_options_convertToJSON(body);
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
                    "DELETE");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_status_t *elementToReturn = v1_status_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    free(localVarToReplace__namespace);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
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
    if(keyQuery__continue){
        free(keyQuery__continue);
        keyQuery__continue = NULL;
    }
    if(valueQuery__continue){
        free(valueQuery__continue);
        valueQuery__continue = NULL;
    }
    if(keyPairQuery__continue){
        keyValuePair_free(keyPairQuery__continue);
        keyPairQuery__continue = NULL;
    }
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
    if(keyQuery_fieldSelector){
        free(keyQuery_fieldSelector);
        keyQuery_fieldSelector = NULL;
    }
    if(valueQuery_fieldSelector){
        free(valueQuery_fieldSelector);
        valueQuery_fieldSelector = NULL;
    }
    if(keyPairQuery_fieldSelector){
        keyValuePair_free(keyPairQuery_fieldSelector);
        keyPairQuery_fieldSelector = NULL;
    }
    if(keyQuery_gracePeriodSeconds){
        free(keyQuery_gracePeriodSeconds);
        keyQuery_gracePeriodSeconds = NULL;
    }
    if(valueQuery_gracePeriodSeconds){
        free(valueQuery_gracePeriodSeconds);
        valueQuery_gracePeriodSeconds = NULL;
    }
    if(keyPairQuery_gracePeriodSeconds){
        keyValuePair_free(keyPairQuery_gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = NULL;
    }
    if(keyQuery_labelSelector){
        free(keyQuery_labelSelector);
        keyQuery_labelSelector = NULL;
    }
    if(valueQuery_labelSelector){
        free(valueQuery_labelSelector);
        valueQuery_labelSelector = NULL;
    }
    if(keyPairQuery_labelSelector){
        keyValuePair_free(keyPairQuery_labelSelector);
        keyPairQuery_labelSelector = NULL;
    }
    if(keyQuery_limit){
        free(keyQuery_limit);
        keyQuery_limit = NULL;
    }
    if(valueQuery_limit){
        free(valueQuery_limit);
        valueQuery_limit = NULL;
    }
    if(keyPairQuery_limit){
        keyValuePair_free(keyPairQuery_limit);
        keyPairQuery_limit = NULL;
    }
    if(keyQuery_orphanDependents){
        free(keyQuery_orphanDependents);
        keyQuery_orphanDependents = NULL;
    }
    if(valueQuery_orphanDependents){
        free(valueQuery_orphanDependents);
        valueQuery_orphanDependents = NULL;
    }
    if(keyPairQuery_orphanDependents){
        keyValuePair_free(keyPairQuery_orphanDependents);
        keyPairQuery_orphanDependents = NULL;
    }
    if(keyQuery_propagationPolicy){
        free(keyQuery_propagationPolicy);
        keyQuery_propagationPolicy = NULL;
    }
    if(valueQuery_propagationPolicy){
        free(valueQuery_propagationPolicy);
        valueQuery_propagationPolicy = NULL;
    }
    if(keyPairQuery_propagationPolicy){
        keyValuePair_free(keyPairQuery_propagationPolicy);
        keyPairQuery_propagationPolicy = NULL;
    }
    if(keyQuery_resourceVersion){
        free(keyQuery_resourceVersion);
        keyQuery_resourceVersion = NULL;
    }
    if(valueQuery_resourceVersion){
        free(valueQuery_resourceVersion);
        valueQuery_resourceVersion = NULL;
    }
    if(keyPairQuery_resourceVersion){
        keyValuePair_free(keyPairQuery_resourceVersion);
        keyPairQuery_resourceVersion = NULL;
    }
    if(keyQuery_timeoutSeconds){
        free(keyQuery_timeoutSeconds);
        keyQuery_timeoutSeconds = NULL;
    }
    if(valueQuery_timeoutSeconds){
        free(valueQuery_timeoutSeconds);
        valueQuery_timeoutSeconds = NULL;
    }
    if(keyPairQuery_timeoutSeconds){
        keyValuePair_free(keyPairQuery_timeoutSeconds);
        keyPairQuery_timeoutSeconds = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// delete collection of DaemonSet
//
v1_status_t*
AppsV1API_deleteCollectionNamespacedDaemonSet(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , v1_delete_options_t * body )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/daemonsets")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/daemonsets");


    // Path Params
    long sizeOfPathParams__namespace = strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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

    // query parameters
    char *keyQuery__continue = NULL;
    char * valueQuery__continue = NULL;
    keyValuePair_t *keyPairQuery__continue = 0;
    if (_continue)
    {
        keyQuery__continue = strdup("continue");
        valueQuery__continue = strdup((_continue));
        keyPairQuery__continue = keyValuePair_create(keyQuery__continue, valueQuery__continue);
        list_addElement(localVarQueryParameters,keyPairQuery__continue);
    }

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
    char *keyQuery_fieldSelector = NULL;
    char * valueQuery_fieldSelector = NULL;
    keyValuePair_t *keyPairQuery_fieldSelector = 0;
    if (fieldSelector)
    {
        keyQuery_fieldSelector = strdup("fieldSelector");
        valueQuery_fieldSelector = strdup((fieldSelector));
        keyPairQuery_fieldSelector = keyValuePair_create(keyQuery_fieldSelector, valueQuery_fieldSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldSelector);
    }

    // query parameters
    char *keyQuery_gracePeriodSeconds = NULL;
    char * valueQuery_gracePeriodSeconds = NULL;
    keyValuePair_t *keyPairQuery_gracePeriodSeconds = 0;
    if (gracePeriodSeconds)
    {
        keyQuery_gracePeriodSeconds = strdup("gracePeriodSeconds");
        valueQuery_gracePeriodSeconds = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_gracePeriodSeconds, MAX_NUMBER_LENGTH, "%d", gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = keyValuePair_create(keyQuery_gracePeriodSeconds, valueQuery_gracePeriodSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_gracePeriodSeconds);
    }

    // query parameters
    char *keyQuery_labelSelector = NULL;
    char * valueQuery_labelSelector = NULL;
    keyValuePair_t *keyPairQuery_labelSelector = 0;
    if (labelSelector)
    {
        keyQuery_labelSelector = strdup("labelSelector");
        valueQuery_labelSelector = strdup((labelSelector));
        keyPairQuery_labelSelector = keyValuePair_create(keyQuery_labelSelector, valueQuery_labelSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_labelSelector);
    }

    // query parameters
    char *keyQuery_limit = NULL;
    char * valueQuery_limit = NULL;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_limit, MAX_NUMBER_LENGTH, "%d", limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, valueQuery_limit);
        list_addElement(localVarQueryParameters,keyPairQuery_limit);
    }

    // query parameters
    char *keyQuery_orphanDependents = NULL;
    char * valueQuery_orphanDependents = NULL;
    keyValuePair_t *keyPairQuery_orphanDependents = 0;
    if (orphanDependents)
    {
        keyQuery_orphanDependents = strdup("orphanDependents");
        valueQuery_orphanDependents = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_orphanDependents, MAX_NUMBER_LENGTH, "%d", orphanDependents);
        keyPairQuery_orphanDependents = keyValuePair_create(keyQuery_orphanDependents, valueQuery_orphanDependents);
        list_addElement(localVarQueryParameters,keyPairQuery_orphanDependents);
    }

    // query parameters
    char *keyQuery_propagationPolicy = NULL;
    char * valueQuery_propagationPolicy = NULL;
    keyValuePair_t *keyPairQuery_propagationPolicy = 0;
    if (propagationPolicy)
    {
        keyQuery_propagationPolicy = strdup("propagationPolicy");
        valueQuery_propagationPolicy = strdup((propagationPolicy));
        keyPairQuery_propagationPolicy = keyValuePair_create(keyQuery_propagationPolicy, valueQuery_propagationPolicy);
        list_addElement(localVarQueryParameters,keyPairQuery_propagationPolicy);
    }

    // query parameters
    char *keyQuery_resourceVersion = NULL;
    char * valueQuery_resourceVersion = NULL;
    keyValuePair_t *keyPairQuery_resourceVersion = 0;
    if (resourceVersion)
    {
        keyQuery_resourceVersion = strdup("resourceVersion");
        valueQuery_resourceVersion = strdup((resourceVersion));
        keyPairQuery_resourceVersion = keyValuePair_create(keyQuery_resourceVersion, valueQuery_resourceVersion);
        list_addElement(localVarQueryParameters,keyPairQuery_resourceVersion);
    }

    // query parameters
    char *keyQuery_timeoutSeconds = NULL;
    char * valueQuery_timeoutSeconds = NULL;
    keyValuePair_t *keyPairQuery_timeoutSeconds = 0;
    if (timeoutSeconds)
    {
        keyQuery_timeoutSeconds = strdup("timeoutSeconds");
        valueQuery_timeoutSeconds = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_timeoutSeconds, MAX_NUMBER_LENGTH, "%d", timeoutSeconds);
        keyPairQuery_timeoutSeconds = keyValuePair_create(keyQuery_timeoutSeconds, valueQuery_timeoutSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_timeoutSeconds);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_delete_options_convertToJSON(body);
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
                    "DELETE");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_status_t *elementToReturn = v1_status_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    free(localVarToReplace__namespace);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
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
    if(keyQuery__continue){
        free(keyQuery__continue);
        keyQuery__continue = NULL;
    }
    if(valueQuery__continue){
        free(valueQuery__continue);
        valueQuery__continue = NULL;
    }
    if(keyPairQuery__continue){
        keyValuePair_free(keyPairQuery__continue);
        keyPairQuery__continue = NULL;
    }
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
    if(keyQuery_fieldSelector){
        free(keyQuery_fieldSelector);
        keyQuery_fieldSelector = NULL;
    }
    if(valueQuery_fieldSelector){
        free(valueQuery_fieldSelector);
        valueQuery_fieldSelector = NULL;
    }
    if(keyPairQuery_fieldSelector){
        keyValuePair_free(keyPairQuery_fieldSelector);
        keyPairQuery_fieldSelector = NULL;
    }
    if(keyQuery_gracePeriodSeconds){
        free(keyQuery_gracePeriodSeconds);
        keyQuery_gracePeriodSeconds = NULL;
    }
    if(valueQuery_gracePeriodSeconds){
        free(valueQuery_gracePeriodSeconds);
        valueQuery_gracePeriodSeconds = NULL;
    }
    if(keyPairQuery_gracePeriodSeconds){
        keyValuePair_free(keyPairQuery_gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = NULL;
    }
    if(keyQuery_labelSelector){
        free(keyQuery_labelSelector);
        keyQuery_labelSelector = NULL;
    }
    if(valueQuery_labelSelector){
        free(valueQuery_labelSelector);
        valueQuery_labelSelector = NULL;
    }
    if(keyPairQuery_labelSelector){
        keyValuePair_free(keyPairQuery_labelSelector);
        keyPairQuery_labelSelector = NULL;
    }
    if(keyQuery_limit){
        free(keyQuery_limit);
        keyQuery_limit = NULL;
    }
    if(valueQuery_limit){
        free(valueQuery_limit);
        valueQuery_limit = NULL;
    }
    if(keyPairQuery_limit){
        keyValuePair_free(keyPairQuery_limit);
        keyPairQuery_limit = NULL;
    }
    if(keyQuery_orphanDependents){
        free(keyQuery_orphanDependents);
        keyQuery_orphanDependents = NULL;
    }
    if(valueQuery_orphanDependents){
        free(valueQuery_orphanDependents);
        valueQuery_orphanDependents = NULL;
    }
    if(keyPairQuery_orphanDependents){
        keyValuePair_free(keyPairQuery_orphanDependents);
        keyPairQuery_orphanDependents = NULL;
    }
    if(keyQuery_propagationPolicy){
        free(keyQuery_propagationPolicy);
        keyQuery_propagationPolicy = NULL;
    }
    if(valueQuery_propagationPolicy){
        free(valueQuery_propagationPolicy);
        valueQuery_propagationPolicy = NULL;
    }
    if(keyPairQuery_propagationPolicy){
        keyValuePair_free(keyPairQuery_propagationPolicy);
        keyPairQuery_propagationPolicy = NULL;
    }
    if(keyQuery_resourceVersion){
        free(keyQuery_resourceVersion);
        keyQuery_resourceVersion = NULL;
    }
    if(valueQuery_resourceVersion){
        free(valueQuery_resourceVersion);
        valueQuery_resourceVersion = NULL;
    }
    if(keyPairQuery_resourceVersion){
        keyValuePair_free(keyPairQuery_resourceVersion);
        keyPairQuery_resourceVersion = NULL;
    }
    if(keyQuery_timeoutSeconds){
        free(keyQuery_timeoutSeconds);
        keyQuery_timeoutSeconds = NULL;
    }
    if(valueQuery_timeoutSeconds){
        free(valueQuery_timeoutSeconds);
        valueQuery_timeoutSeconds = NULL;
    }
    if(keyPairQuery_timeoutSeconds){
        keyValuePair_free(keyPairQuery_timeoutSeconds);
        keyPairQuery_timeoutSeconds = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// delete collection of Deployment
//
v1_status_t*
AppsV1API_deleteCollectionNamespacedDeployment(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , v1_delete_options_t * body )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/deployments")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/deployments");


    // Path Params
    long sizeOfPathParams__namespace = strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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

    // query parameters
    char *keyQuery__continue = NULL;
    char * valueQuery__continue = NULL;
    keyValuePair_t *keyPairQuery__continue = 0;
    if (_continue)
    {
        keyQuery__continue = strdup("continue");
        valueQuery__continue = strdup((_continue));
        keyPairQuery__continue = keyValuePair_create(keyQuery__continue, valueQuery__continue);
        list_addElement(localVarQueryParameters,keyPairQuery__continue);
    }

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
    char *keyQuery_fieldSelector = NULL;
    char * valueQuery_fieldSelector = NULL;
    keyValuePair_t *keyPairQuery_fieldSelector = 0;
    if (fieldSelector)
    {
        keyQuery_fieldSelector = strdup("fieldSelector");
        valueQuery_fieldSelector = strdup((fieldSelector));
        keyPairQuery_fieldSelector = keyValuePair_create(keyQuery_fieldSelector, valueQuery_fieldSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldSelector);
    }

    // query parameters
    char *keyQuery_gracePeriodSeconds = NULL;
    char * valueQuery_gracePeriodSeconds = NULL;
    keyValuePair_t *keyPairQuery_gracePeriodSeconds = 0;
    if (gracePeriodSeconds)
    {
        keyQuery_gracePeriodSeconds = strdup("gracePeriodSeconds");
        valueQuery_gracePeriodSeconds = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_gracePeriodSeconds, MAX_NUMBER_LENGTH, "%d", gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = keyValuePair_create(keyQuery_gracePeriodSeconds, valueQuery_gracePeriodSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_gracePeriodSeconds);
    }

    // query parameters
    char *keyQuery_labelSelector = NULL;
    char * valueQuery_labelSelector = NULL;
    keyValuePair_t *keyPairQuery_labelSelector = 0;
    if (labelSelector)
    {
        keyQuery_labelSelector = strdup("labelSelector");
        valueQuery_labelSelector = strdup((labelSelector));
        keyPairQuery_labelSelector = keyValuePair_create(keyQuery_labelSelector, valueQuery_labelSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_labelSelector);
    }

    // query parameters
    char *keyQuery_limit = NULL;
    char * valueQuery_limit = NULL;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_limit, MAX_NUMBER_LENGTH, "%d", limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, valueQuery_limit);
        list_addElement(localVarQueryParameters,keyPairQuery_limit);
    }

    // query parameters
    char *keyQuery_orphanDependents = NULL;
    char * valueQuery_orphanDependents = NULL;
    keyValuePair_t *keyPairQuery_orphanDependents = 0;
    if (orphanDependents)
    {
        keyQuery_orphanDependents = strdup("orphanDependents");
        valueQuery_orphanDependents = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_orphanDependents, MAX_NUMBER_LENGTH, "%d", orphanDependents);
        keyPairQuery_orphanDependents = keyValuePair_create(keyQuery_orphanDependents, valueQuery_orphanDependents);
        list_addElement(localVarQueryParameters,keyPairQuery_orphanDependents);
    }

    // query parameters
    char *keyQuery_propagationPolicy = NULL;
    char * valueQuery_propagationPolicy = NULL;
    keyValuePair_t *keyPairQuery_propagationPolicy = 0;
    if (propagationPolicy)
    {
        keyQuery_propagationPolicy = strdup("propagationPolicy");
        valueQuery_propagationPolicy = strdup((propagationPolicy));
        keyPairQuery_propagationPolicy = keyValuePair_create(keyQuery_propagationPolicy, valueQuery_propagationPolicy);
        list_addElement(localVarQueryParameters,keyPairQuery_propagationPolicy);
    }

    // query parameters
    char *keyQuery_resourceVersion = NULL;
    char * valueQuery_resourceVersion = NULL;
    keyValuePair_t *keyPairQuery_resourceVersion = 0;
    if (resourceVersion)
    {
        keyQuery_resourceVersion = strdup("resourceVersion");
        valueQuery_resourceVersion = strdup((resourceVersion));
        keyPairQuery_resourceVersion = keyValuePair_create(keyQuery_resourceVersion, valueQuery_resourceVersion);
        list_addElement(localVarQueryParameters,keyPairQuery_resourceVersion);
    }

    // query parameters
    char *keyQuery_timeoutSeconds = NULL;
    char * valueQuery_timeoutSeconds = NULL;
    keyValuePair_t *keyPairQuery_timeoutSeconds = 0;
    if (timeoutSeconds)
    {
        keyQuery_timeoutSeconds = strdup("timeoutSeconds");
        valueQuery_timeoutSeconds = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_timeoutSeconds, MAX_NUMBER_LENGTH, "%d", timeoutSeconds);
        keyPairQuery_timeoutSeconds = keyValuePair_create(keyQuery_timeoutSeconds, valueQuery_timeoutSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_timeoutSeconds);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_delete_options_convertToJSON(body);
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
                    "DELETE");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_status_t *elementToReturn = v1_status_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    free(localVarToReplace__namespace);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
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
    if(keyQuery__continue){
        free(keyQuery__continue);
        keyQuery__continue = NULL;
    }
    if(valueQuery__continue){
        free(valueQuery__continue);
        valueQuery__continue = NULL;
    }
    if(keyPairQuery__continue){
        keyValuePair_free(keyPairQuery__continue);
        keyPairQuery__continue = NULL;
    }
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
    if(keyQuery_fieldSelector){
        free(keyQuery_fieldSelector);
        keyQuery_fieldSelector = NULL;
    }
    if(valueQuery_fieldSelector){
        free(valueQuery_fieldSelector);
        valueQuery_fieldSelector = NULL;
    }
    if(keyPairQuery_fieldSelector){
        keyValuePair_free(keyPairQuery_fieldSelector);
        keyPairQuery_fieldSelector = NULL;
    }
    if(keyQuery_gracePeriodSeconds){
        free(keyQuery_gracePeriodSeconds);
        keyQuery_gracePeriodSeconds = NULL;
    }
    if(valueQuery_gracePeriodSeconds){
        free(valueQuery_gracePeriodSeconds);
        valueQuery_gracePeriodSeconds = NULL;
    }
    if(keyPairQuery_gracePeriodSeconds){
        keyValuePair_free(keyPairQuery_gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = NULL;
    }
    if(keyQuery_labelSelector){
        free(keyQuery_labelSelector);
        keyQuery_labelSelector = NULL;
    }
    if(valueQuery_labelSelector){
        free(valueQuery_labelSelector);
        valueQuery_labelSelector = NULL;
    }
    if(keyPairQuery_labelSelector){
        keyValuePair_free(keyPairQuery_labelSelector);
        keyPairQuery_labelSelector = NULL;
    }
    if(keyQuery_limit){
        free(keyQuery_limit);
        keyQuery_limit = NULL;
    }
    if(valueQuery_limit){
        free(valueQuery_limit);
        valueQuery_limit = NULL;
    }
    if(keyPairQuery_limit){
        keyValuePair_free(keyPairQuery_limit);
        keyPairQuery_limit = NULL;
    }
    if(keyQuery_orphanDependents){
        free(keyQuery_orphanDependents);
        keyQuery_orphanDependents = NULL;
    }
    if(valueQuery_orphanDependents){
        free(valueQuery_orphanDependents);
        valueQuery_orphanDependents = NULL;
    }
    if(keyPairQuery_orphanDependents){
        keyValuePair_free(keyPairQuery_orphanDependents);
        keyPairQuery_orphanDependents = NULL;
    }
    if(keyQuery_propagationPolicy){
        free(keyQuery_propagationPolicy);
        keyQuery_propagationPolicy = NULL;
    }
    if(valueQuery_propagationPolicy){
        free(valueQuery_propagationPolicy);
        valueQuery_propagationPolicy = NULL;
    }
    if(keyPairQuery_propagationPolicy){
        keyValuePair_free(keyPairQuery_propagationPolicy);
        keyPairQuery_propagationPolicy = NULL;
    }
    if(keyQuery_resourceVersion){
        free(keyQuery_resourceVersion);
        keyQuery_resourceVersion = NULL;
    }
    if(valueQuery_resourceVersion){
        free(valueQuery_resourceVersion);
        valueQuery_resourceVersion = NULL;
    }
    if(keyPairQuery_resourceVersion){
        keyValuePair_free(keyPairQuery_resourceVersion);
        keyPairQuery_resourceVersion = NULL;
    }
    if(keyQuery_timeoutSeconds){
        free(keyQuery_timeoutSeconds);
        keyQuery_timeoutSeconds = NULL;
    }
    if(valueQuery_timeoutSeconds){
        free(valueQuery_timeoutSeconds);
        valueQuery_timeoutSeconds = NULL;
    }
    if(keyPairQuery_timeoutSeconds){
        keyValuePair_free(keyPairQuery_timeoutSeconds);
        keyPairQuery_timeoutSeconds = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// delete collection of ReplicaSet
//
v1_status_t*
AppsV1API_deleteCollectionNamespacedReplicaSet(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , v1_delete_options_t * body )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/replicasets")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/replicasets");


    // Path Params
    long sizeOfPathParams__namespace = strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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

    // query parameters
    char *keyQuery__continue = NULL;
    char * valueQuery__continue = NULL;
    keyValuePair_t *keyPairQuery__continue = 0;
    if (_continue)
    {
        keyQuery__continue = strdup("continue");
        valueQuery__continue = strdup((_continue));
        keyPairQuery__continue = keyValuePair_create(keyQuery__continue, valueQuery__continue);
        list_addElement(localVarQueryParameters,keyPairQuery__continue);
    }

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
    char *keyQuery_fieldSelector = NULL;
    char * valueQuery_fieldSelector = NULL;
    keyValuePair_t *keyPairQuery_fieldSelector = 0;
    if (fieldSelector)
    {
        keyQuery_fieldSelector = strdup("fieldSelector");
        valueQuery_fieldSelector = strdup((fieldSelector));
        keyPairQuery_fieldSelector = keyValuePair_create(keyQuery_fieldSelector, valueQuery_fieldSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldSelector);
    }

    // query parameters
    char *keyQuery_gracePeriodSeconds = NULL;
    char * valueQuery_gracePeriodSeconds = NULL;
    keyValuePair_t *keyPairQuery_gracePeriodSeconds = 0;
    if (gracePeriodSeconds)
    {
        keyQuery_gracePeriodSeconds = strdup("gracePeriodSeconds");
        valueQuery_gracePeriodSeconds = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_gracePeriodSeconds, MAX_NUMBER_LENGTH, "%d", gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = keyValuePair_create(keyQuery_gracePeriodSeconds, valueQuery_gracePeriodSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_gracePeriodSeconds);
    }

    // query parameters
    char *keyQuery_labelSelector = NULL;
    char * valueQuery_labelSelector = NULL;
    keyValuePair_t *keyPairQuery_labelSelector = 0;
    if (labelSelector)
    {
        keyQuery_labelSelector = strdup("labelSelector");
        valueQuery_labelSelector = strdup((labelSelector));
        keyPairQuery_labelSelector = keyValuePair_create(keyQuery_labelSelector, valueQuery_labelSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_labelSelector);
    }

    // query parameters
    char *keyQuery_limit = NULL;
    char * valueQuery_limit = NULL;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_limit, MAX_NUMBER_LENGTH, "%d", limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, valueQuery_limit);
        list_addElement(localVarQueryParameters,keyPairQuery_limit);
    }

    // query parameters
    char *keyQuery_orphanDependents = NULL;
    char * valueQuery_orphanDependents = NULL;
    keyValuePair_t *keyPairQuery_orphanDependents = 0;
    if (orphanDependents)
    {
        keyQuery_orphanDependents = strdup("orphanDependents");
        valueQuery_orphanDependents = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_orphanDependents, MAX_NUMBER_LENGTH, "%d", orphanDependents);
        keyPairQuery_orphanDependents = keyValuePair_create(keyQuery_orphanDependents, valueQuery_orphanDependents);
        list_addElement(localVarQueryParameters,keyPairQuery_orphanDependents);
    }

    // query parameters
    char *keyQuery_propagationPolicy = NULL;
    char * valueQuery_propagationPolicy = NULL;
    keyValuePair_t *keyPairQuery_propagationPolicy = 0;
    if (propagationPolicy)
    {
        keyQuery_propagationPolicy = strdup("propagationPolicy");
        valueQuery_propagationPolicy = strdup((propagationPolicy));
        keyPairQuery_propagationPolicy = keyValuePair_create(keyQuery_propagationPolicy, valueQuery_propagationPolicy);
        list_addElement(localVarQueryParameters,keyPairQuery_propagationPolicy);
    }

    // query parameters
    char *keyQuery_resourceVersion = NULL;
    char * valueQuery_resourceVersion = NULL;
    keyValuePair_t *keyPairQuery_resourceVersion = 0;
    if (resourceVersion)
    {
        keyQuery_resourceVersion = strdup("resourceVersion");
        valueQuery_resourceVersion = strdup((resourceVersion));
        keyPairQuery_resourceVersion = keyValuePair_create(keyQuery_resourceVersion, valueQuery_resourceVersion);
        list_addElement(localVarQueryParameters,keyPairQuery_resourceVersion);
    }

    // query parameters
    char *keyQuery_timeoutSeconds = NULL;
    char * valueQuery_timeoutSeconds = NULL;
    keyValuePair_t *keyPairQuery_timeoutSeconds = 0;
    if (timeoutSeconds)
    {
        keyQuery_timeoutSeconds = strdup("timeoutSeconds");
        valueQuery_timeoutSeconds = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_timeoutSeconds, MAX_NUMBER_LENGTH, "%d", timeoutSeconds);
        keyPairQuery_timeoutSeconds = keyValuePair_create(keyQuery_timeoutSeconds, valueQuery_timeoutSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_timeoutSeconds);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_delete_options_convertToJSON(body);
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
                    "DELETE");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_status_t *elementToReturn = v1_status_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    free(localVarToReplace__namespace);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
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
    if(keyQuery__continue){
        free(keyQuery__continue);
        keyQuery__continue = NULL;
    }
    if(valueQuery__continue){
        free(valueQuery__continue);
        valueQuery__continue = NULL;
    }
    if(keyPairQuery__continue){
        keyValuePair_free(keyPairQuery__continue);
        keyPairQuery__continue = NULL;
    }
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
    if(keyQuery_fieldSelector){
        free(keyQuery_fieldSelector);
        keyQuery_fieldSelector = NULL;
    }
    if(valueQuery_fieldSelector){
        free(valueQuery_fieldSelector);
        valueQuery_fieldSelector = NULL;
    }
    if(keyPairQuery_fieldSelector){
        keyValuePair_free(keyPairQuery_fieldSelector);
        keyPairQuery_fieldSelector = NULL;
    }
    if(keyQuery_gracePeriodSeconds){
        free(keyQuery_gracePeriodSeconds);
        keyQuery_gracePeriodSeconds = NULL;
    }
    if(valueQuery_gracePeriodSeconds){
        free(valueQuery_gracePeriodSeconds);
        valueQuery_gracePeriodSeconds = NULL;
    }
    if(keyPairQuery_gracePeriodSeconds){
        keyValuePair_free(keyPairQuery_gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = NULL;
    }
    if(keyQuery_labelSelector){
        free(keyQuery_labelSelector);
        keyQuery_labelSelector = NULL;
    }
    if(valueQuery_labelSelector){
        free(valueQuery_labelSelector);
        valueQuery_labelSelector = NULL;
    }
    if(keyPairQuery_labelSelector){
        keyValuePair_free(keyPairQuery_labelSelector);
        keyPairQuery_labelSelector = NULL;
    }
    if(keyQuery_limit){
        free(keyQuery_limit);
        keyQuery_limit = NULL;
    }
    if(valueQuery_limit){
        free(valueQuery_limit);
        valueQuery_limit = NULL;
    }
    if(keyPairQuery_limit){
        keyValuePair_free(keyPairQuery_limit);
        keyPairQuery_limit = NULL;
    }
    if(keyQuery_orphanDependents){
        free(keyQuery_orphanDependents);
        keyQuery_orphanDependents = NULL;
    }
    if(valueQuery_orphanDependents){
        free(valueQuery_orphanDependents);
        valueQuery_orphanDependents = NULL;
    }
    if(keyPairQuery_orphanDependents){
        keyValuePair_free(keyPairQuery_orphanDependents);
        keyPairQuery_orphanDependents = NULL;
    }
    if(keyQuery_propagationPolicy){
        free(keyQuery_propagationPolicy);
        keyQuery_propagationPolicy = NULL;
    }
    if(valueQuery_propagationPolicy){
        free(valueQuery_propagationPolicy);
        valueQuery_propagationPolicy = NULL;
    }
    if(keyPairQuery_propagationPolicy){
        keyValuePair_free(keyPairQuery_propagationPolicy);
        keyPairQuery_propagationPolicy = NULL;
    }
    if(keyQuery_resourceVersion){
        free(keyQuery_resourceVersion);
        keyQuery_resourceVersion = NULL;
    }
    if(valueQuery_resourceVersion){
        free(valueQuery_resourceVersion);
        valueQuery_resourceVersion = NULL;
    }
    if(keyPairQuery_resourceVersion){
        keyValuePair_free(keyPairQuery_resourceVersion);
        keyPairQuery_resourceVersion = NULL;
    }
    if(keyQuery_timeoutSeconds){
        free(keyQuery_timeoutSeconds);
        keyQuery_timeoutSeconds = NULL;
    }
    if(valueQuery_timeoutSeconds){
        free(valueQuery_timeoutSeconds);
        valueQuery_timeoutSeconds = NULL;
    }
    if(keyPairQuery_timeoutSeconds){
        keyValuePair_free(keyPairQuery_timeoutSeconds);
        keyPairQuery_timeoutSeconds = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// delete collection of StatefulSet
//
v1_status_t*
AppsV1API_deleteCollectionNamespacedStatefulSet(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , v1_delete_options_t * body )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/statefulsets")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/statefulsets");


    // Path Params
    long sizeOfPathParams__namespace = strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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

    // query parameters
    char *keyQuery__continue = NULL;
    char * valueQuery__continue = NULL;
    keyValuePair_t *keyPairQuery__continue = 0;
    if (_continue)
    {
        keyQuery__continue = strdup("continue");
        valueQuery__continue = strdup((_continue));
        keyPairQuery__continue = keyValuePair_create(keyQuery__continue, valueQuery__continue);
        list_addElement(localVarQueryParameters,keyPairQuery__continue);
    }

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
    char *keyQuery_fieldSelector = NULL;
    char * valueQuery_fieldSelector = NULL;
    keyValuePair_t *keyPairQuery_fieldSelector = 0;
    if (fieldSelector)
    {
        keyQuery_fieldSelector = strdup("fieldSelector");
        valueQuery_fieldSelector = strdup((fieldSelector));
        keyPairQuery_fieldSelector = keyValuePair_create(keyQuery_fieldSelector, valueQuery_fieldSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldSelector);
    }

    // query parameters
    char *keyQuery_gracePeriodSeconds = NULL;
    char * valueQuery_gracePeriodSeconds = NULL;
    keyValuePair_t *keyPairQuery_gracePeriodSeconds = 0;
    if (gracePeriodSeconds)
    {
        keyQuery_gracePeriodSeconds = strdup("gracePeriodSeconds");
        valueQuery_gracePeriodSeconds = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_gracePeriodSeconds, MAX_NUMBER_LENGTH, "%d", gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = keyValuePair_create(keyQuery_gracePeriodSeconds, valueQuery_gracePeriodSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_gracePeriodSeconds);
    }

    // query parameters
    char *keyQuery_labelSelector = NULL;
    char * valueQuery_labelSelector = NULL;
    keyValuePair_t *keyPairQuery_labelSelector = 0;
    if (labelSelector)
    {
        keyQuery_labelSelector = strdup("labelSelector");
        valueQuery_labelSelector = strdup((labelSelector));
        keyPairQuery_labelSelector = keyValuePair_create(keyQuery_labelSelector, valueQuery_labelSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_labelSelector);
    }

    // query parameters
    char *keyQuery_limit = NULL;
    char * valueQuery_limit = NULL;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_limit, MAX_NUMBER_LENGTH, "%d", limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, valueQuery_limit);
        list_addElement(localVarQueryParameters,keyPairQuery_limit);
    }

    // query parameters
    char *keyQuery_orphanDependents = NULL;
    char * valueQuery_orphanDependents = NULL;
    keyValuePair_t *keyPairQuery_orphanDependents = 0;
    if (orphanDependents)
    {
        keyQuery_orphanDependents = strdup("orphanDependents");
        valueQuery_orphanDependents = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_orphanDependents, MAX_NUMBER_LENGTH, "%d", orphanDependents);
        keyPairQuery_orphanDependents = keyValuePair_create(keyQuery_orphanDependents, valueQuery_orphanDependents);
        list_addElement(localVarQueryParameters,keyPairQuery_orphanDependents);
    }

    // query parameters
    char *keyQuery_propagationPolicy = NULL;
    char * valueQuery_propagationPolicy = NULL;
    keyValuePair_t *keyPairQuery_propagationPolicy = 0;
    if (propagationPolicy)
    {
        keyQuery_propagationPolicy = strdup("propagationPolicy");
        valueQuery_propagationPolicy = strdup((propagationPolicy));
        keyPairQuery_propagationPolicy = keyValuePair_create(keyQuery_propagationPolicy, valueQuery_propagationPolicy);
        list_addElement(localVarQueryParameters,keyPairQuery_propagationPolicy);
    }

    // query parameters
    char *keyQuery_resourceVersion = NULL;
    char * valueQuery_resourceVersion = NULL;
    keyValuePair_t *keyPairQuery_resourceVersion = 0;
    if (resourceVersion)
    {
        keyQuery_resourceVersion = strdup("resourceVersion");
        valueQuery_resourceVersion = strdup((resourceVersion));
        keyPairQuery_resourceVersion = keyValuePair_create(keyQuery_resourceVersion, valueQuery_resourceVersion);
        list_addElement(localVarQueryParameters,keyPairQuery_resourceVersion);
    }

    // query parameters
    char *keyQuery_timeoutSeconds = NULL;
    char * valueQuery_timeoutSeconds = NULL;
    keyValuePair_t *keyPairQuery_timeoutSeconds = 0;
    if (timeoutSeconds)
    {
        keyQuery_timeoutSeconds = strdup("timeoutSeconds");
        valueQuery_timeoutSeconds = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_timeoutSeconds, MAX_NUMBER_LENGTH, "%d", timeoutSeconds);
        keyPairQuery_timeoutSeconds = keyValuePair_create(keyQuery_timeoutSeconds, valueQuery_timeoutSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_timeoutSeconds);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_delete_options_convertToJSON(body);
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
                    "DELETE");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_status_t *elementToReturn = v1_status_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    free(localVarToReplace__namespace);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
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
    if(keyQuery__continue){
        free(keyQuery__continue);
        keyQuery__continue = NULL;
    }
    if(valueQuery__continue){
        free(valueQuery__continue);
        valueQuery__continue = NULL;
    }
    if(keyPairQuery__continue){
        keyValuePair_free(keyPairQuery__continue);
        keyPairQuery__continue = NULL;
    }
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
    if(keyQuery_fieldSelector){
        free(keyQuery_fieldSelector);
        keyQuery_fieldSelector = NULL;
    }
    if(valueQuery_fieldSelector){
        free(valueQuery_fieldSelector);
        valueQuery_fieldSelector = NULL;
    }
    if(keyPairQuery_fieldSelector){
        keyValuePair_free(keyPairQuery_fieldSelector);
        keyPairQuery_fieldSelector = NULL;
    }
    if(keyQuery_gracePeriodSeconds){
        free(keyQuery_gracePeriodSeconds);
        keyQuery_gracePeriodSeconds = NULL;
    }
    if(valueQuery_gracePeriodSeconds){
        free(valueQuery_gracePeriodSeconds);
        valueQuery_gracePeriodSeconds = NULL;
    }
    if(keyPairQuery_gracePeriodSeconds){
        keyValuePair_free(keyPairQuery_gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = NULL;
    }
    if(keyQuery_labelSelector){
        free(keyQuery_labelSelector);
        keyQuery_labelSelector = NULL;
    }
    if(valueQuery_labelSelector){
        free(valueQuery_labelSelector);
        valueQuery_labelSelector = NULL;
    }
    if(keyPairQuery_labelSelector){
        keyValuePair_free(keyPairQuery_labelSelector);
        keyPairQuery_labelSelector = NULL;
    }
    if(keyQuery_limit){
        free(keyQuery_limit);
        keyQuery_limit = NULL;
    }
    if(valueQuery_limit){
        free(valueQuery_limit);
        valueQuery_limit = NULL;
    }
    if(keyPairQuery_limit){
        keyValuePair_free(keyPairQuery_limit);
        keyPairQuery_limit = NULL;
    }
    if(keyQuery_orphanDependents){
        free(keyQuery_orphanDependents);
        keyQuery_orphanDependents = NULL;
    }
    if(valueQuery_orphanDependents){
        free(valueQuery_orphanDependents);
        valueQuery_orphanDependents = NULL;
    }
    if(keyPairQuery_orphanDependents){
        keyValuePair_free(keyPairQuery_orphanDependents);
        keyPairQuery_orphanDependents = NULL;
    }
    if(keyQuery_propagationPolicy){
        free(keyQuery_propagationPolicy);
        keyQuery_propagationPolicy = NULL;
    }
    if(valueQuery_propagationPolicy){
        free(valueQuery_propagationPolicy);
        valueQuery_propagationPolicy = NULL;
    }
    if(keyPairQuery_propagationPolicy){
        keyValuePair_free(keyPairQuery_propagationPolicy);
        keyPairQuery_propagationPolicy = NULL;
    }
    if(keyQuery_resourceVersion){
        free(keyQuery_resourceVersion);
        keyQuery_resourceVersion = NULL;
    }
    if(valueQuery_resourceVersion){
        free(valueQuery_resourceVersion);
        valueQuery_resourceVersion = NULL;
    }
    if(keyPairQuery_resourceVersion){
        keyValuePair_free(keyPairQuery_resourceVersion);
        keyPairQuery_resourceVersion = NULL;
    }
    if(keyQuery_timeoutSeconds){
        free(keyQuery_timeoutSeconds);
        keyQuery_timeoutSeconds = NULL;
    }
    if(valueQuery_timeoutSeconds){
        free(valueQuery_timeoutSeconds);
        valueQuery_timeoutSeconds = NULL;
    }
    if(keyPairQuery_timeoutSeconds){
        keyValuePair_free(keyPairQuery_timeoutSeconds);
        keyPairQuery_timeoutSeconds = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// delete a ControllerRevision
//
v1_status_t*
AppsV1API_deleteNamespacedControllerRevision(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/controllerrevisions/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/controllerrevisions/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams__namespace = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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
    char *keyQuery_gracePeriodSeconds = NULL;
    char * valueQuery_gracePeriodSeconds = NULL;
    keyValuePair_t *keyPairQuery_gracePeriodSeconds = 0;
    if (gracePeriodSeconds)
    {
        keyQuery_gracePeriodSeconds = strdup("gracePeriodSeconds");
        valueQuery_gracePeriodSeconds = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_gracePeriodSeconds, MAX_NUMBER_LENGTH, "%d", gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = keyValuePair_create(keyQuery_gracePeriodSeconds, valueQuery_gracePeriodSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_gracePeriodSeconds);
    }

    // query parameters
    char *keyQuery_orphanDependents = NULL;
    char * valueQuery_orphanDependents = NULL;
    keyValuePair_t *keyPairQuery_orphanDependents = 0;
    if (orphanDependents)
    {
        keyQuery_orphanDependents = strdup("orphanDependents");
        valueQuery_orphanDependents = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_orphanDependents, MAX_NUMBER_LENGTH, "%d", orphanDependents);
        keyPairQuery_orphanDependents = keyValuePair_create(keyQuery_orphanDependents, valueQuery_orphanDependents);
        list_addElement(localVarQueryParameters,keyPairQuery_orphanDependents);
    }

    // query parameters
    char *keyQuery_propagationPolicy = NULL;
    char * valueQuery_propagationPolicy = NULL;
    keyValuePair_t *keyPairQuery_propagationPolicy = 0;
    if (propagationPolicy)
    {
        keyQuery_propagationPolicy = strdup("propagationPolicy");
        valueQuery_propagationPolicy = strdup((propagationPolicy));
        keyPairQuery_propagationPolicy = keyValuePair_create(keyQuery_propagationPolicy, valueQuery_propagationPolicy);
        list_addElement(localVarQueryParameters,keyPairQuery_propagationPolicy);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_delete_options_convertToJSON(body);
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
                    "DELETE");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 202) {
        printf("%s\n","Accepted");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_status_t *elementToReturn = v1_status_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    free(localVarToReplace_name);
    free(localVarToReplace__namespace);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
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
    if(keyQuery_gracePeriodSeconds){
        free(keyQuery_gracePeriodSeconds);
        keyQuery_gracePeriodSeconds = NULL;
    }
    if(valueQuery_gracePeriodSeconds){
        free(valueQuery_gracePeriodSeconds);
        valueQuery_gracePeriodSeconds = NULL;
    }
    if(keyPairQuery_gracePeriodSeconds){
        keyValuePair_free(keyPairQuery_gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = NULL;
    }
    if(keyQuery_orphanDependents){
        free(keyQuery_orphanDependents);
        keyQuery_orphanDependents = NULL;
    }
    if(valueQuery_orphanDependents){
        free(valueQuery_orphanDependents);
        valueQuery_orphanDependents = NULL;
    }
    if(keyPairQuery_orphanDependents){
        keyValuePair_free(keyPairQuery_orphanDependents);
        keyPairQuery_orphanDependents = NULL;
    }
    if(keyQuery_propagationPolicy){
        free(keyQuery_propagationPolicy);
        keyQuery_propagationPolicy = NULL;
    }
    if(valueQuery_propagationPolicy){
        free(valueQuery_propagationPolicy);
        valueQuery_propagationPolicy = NULL;
    }
    if(keyPairQuery_propagationPolicy){
        keyValuePair_free(keyPairQuery_propagationPolicy);
        keyPairQuery_propagationPolicy = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// delete a DaemonSet
//
v1_status_t*
AppsV1API_deleteNamespacedDaemonSet(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/daemonsets/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/daemonsets/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams__namespace = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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
    char *keyQuery_gracePeriodSeconds = NULL;
    char * valueQuery_gracePeriodSeconds = NULL;
    keyValuePair_t *keyPairQuery_gracePeriodSeconds = 0;
    if (gracePeriodSeconds)
    {
        keyQuery_gracePeriodSeconds = strdup("gracePeriodSeconds");
        valueQuery_gracePeriodSeconds = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_gracePeriodSeconds, MAX_NUMBER_LENGTH, "%d", gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = keyValuePair_create(keyQuery_gracePeriodSeconds, valueQuery_gracePeriodSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_gracePeriodSeconds);
    }

    // query parameters
    char *keyQuery_orphanDependents = NULL;
    char * valueQuery_orphanDependents = NULL;
    keyValuePair_t *keyPairQuery_orphanDependents = 0;
    if (orphanDependents)
    {
        keyQuery_orphanDependents = strdup("orphanDependents");
        valueQuery_orphanDependents = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_orphanDependents, MAX_NUMBER_LENGTH, "%d", orphanDependents);
        keyPairQuery_orphanDependents = keyValuePair_create(keyQuery_orphanDependents, valueQuery_orphanDependents);
        list_addElement(localVarQueryParameters,keyPairQuery_orphanDependents);
    }

    // query parameters
    char *keyQuery_propagationPolicy = NULL;
    char * valueQuery_propagationPolicy = NULL;
    keyValuePair_t *keyPairQuery_propagationPolicy = 0;
    if (propagationPolicy)
    {
        keyQuery_propagationPolicy = strdup("propagationPolicy");
        valueQuery_propagationPolicy = strdup((propagationPolicy));
        keyPairQuery_propagationPolicy = keyValuePair_create(keyQuery_propagationPolicy, valueQuery_propagationPolicy);
        list_addElement(localVarQueryParameters,keyPairQuery_propagationPolicy);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_delete_options_convertToJSON(body);
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
                    "DELETE");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 202) {
        printf("%s\n","Accepted");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_status_t *elementToReturn = v1_status_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    free(localVarToReplace_name);
    free(localVarToReplace__namespace);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
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
    if(keyQuery_gracePeriodSeconds){
        free(keyQuery_gracePeriodSeconds);
        keyQuery_gracePeriodSeconds = NULL;
    }
    if(valueQuery_gracePeriodSeconds){
        free(valueQuery_gracePeriodSeconds);
        valueQuery_gracePeriodSeconds = NULL;
    }
    if(keyPairQuery_gracePeriodSeconds){
        keyValuePair_free(keyPairQuery_gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = NULL;
    }
    if(keyQuery_orphanDependents){
        free(keyQuery_orphanDependents);
        keyQuery_orphanDependents = NULL;
    }
    if(valueQuery_orphanDependents){
        free(valueQuery_orphanDependents);
        valueQuery_orphanDependents = NULL;
    }
    if(keyPairQuery_orphanDependents){
        keyValuePair_free(keyPairQuery_orphanDependents);
        keyPairQuery_orphanDependents = NULL;
    }
    if(keyQuery_propagationPolicy){
        free(keyQuery_propagationPolicy);
        keyQuery_propagationPolicy = NULL;
    }
    if(valueQuery_propagationPolicy){
        free(valueQuery_propagationPolicy);
        valueQuery_propagationPolicy = NULL;
    }
    if(keyPairQuery_propagationPolicy){
        keyValuePair_free(keyPairQuery_propagationPolicy);
        keyPairQuery_propagationPolicy = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// delete a Deployment
//
v1_status_t*
AppsV1API_deleteNamespacedDeployment(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/deployments/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/deployments/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams__namespace = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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
    char *keyQuery_gracePeriodSeconds = NULL;
    char * valueQuery_gracePeriodSeconds = NULL;
    keyValuePair_t *keyPairQuery_gracePeriodSeconds = 0;
    if (gracePeriodSeconds)
    {
        keyQuery_gracePeriodSeconds = strdup("gracePeriodSeconds");
        valueQuery_gracePeriodSeconds = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_gracePeriodSeconds, MAX_NUMBER_LENGTH, "%d", gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = keyValuePair_create(keyQuery_gracePeriodSeconds, valueQuery_gracePeriodSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_gracePeriodSeconds);
    }

    // query parameters
    char *keyQuery_orphanDependents = NULL;
    char * valueQuery_orphanDependents = NULL;
    keyValuePair_t *keyPairQuery_orphanDependents = 0;
    if (orphanDependents)
    {
        keyQuery_orphanDependents = strdup("orphanDependents");
        valueQuery_orphanDependents = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_orphanDependents, MAX_NUMBER_LENGTH, "%d", orphanDependents);
        keyPairQuery_orphanDependents = keyValuePair_create(keyQuery_orphanDependents, valueQuery_orphanDependents);
        list_addElement(localVarQueryParameters,keyPairQuery_orphanDependents);
    }

    // query parameters
    char *keyQuery_propagationPolicy = NULL;
    char * valueQuery_propagationPolicy = NULL;
    keyValuePair_t *keyPairQuery_propagationPolicy = 0;
    if (propagationPolicy)
    {
        keyQuery_propagationPolicy = strdup("propagationPolicy");
        valueQuery_propagationPolicy = strdup((propagationPolicy));
        keyPairQuery_propagationPolicy = keyValuePair_create(keyQuery_propagationPolicy, valueQuery_propagationPolicy);
        list_addElement(localVarQueryParameters,keyPairQuery_propagationPolicy);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_delete_options_convertToJSON(body);
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
                    "DELETE");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 202) {
        printf("%s\n","Accepted");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_status_t *elementToReturn = v1_status_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    free(localVarToReplace_name);
    free(localVarToReplace__namespace);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
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
    if(keyQuery_gracePeriodSeconds){
        free(keyQuery_gracePeriodSeconds);
        keyQuery_gracePeriodSeconds = NULL;
    }
    if(valueQuery_gracePeriodSeconds){
        free(valueQuery_gracePeriodSeconds);
        valueQuery_gracePeriodSeconds = NULL;
    }
    if(keyPairQuery_gracePeriodSeconds){
        keyValuePair_free(keyPairQuery_gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = NULL;
    }
    if(keyQuery_orphanDependents){
        free(keyQuery_orphanDependents);
        keyQuery_orphanDependents = NULL;
    }
    if(valueQuery_orphanDependents){
        free(valueQuery_orphanDependents);
        valueQuery_orphanDependents = NULL;
    }
    if(keyPairQuery_orphanDependents){
        keyValuePair_free(keyPairQuery_orphanDependents);
        keyPairQuery_orphanDependents = NULL;
    }
    if(keyQuery_propagationPolicy){
        free(keyQuery_propagationPolicy);
        keyQuery_propagationPolicy = NULL;
    }
    if(valueQuery_propagationPolicy){
        free(valueQuery_propagationPolicy);
        valueQuery_propagationPolicy = NULL;
    }
    if(keyPairQuery_propagationPolicy){
        keyValuePair_free(keyPairQuery_propagationPolicy);
        keyPairQuery_propagationPolicy = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// delete a ReplicaSet
//
v1_status_t*
AppsV1API_deleteNamespacedReplicaSet(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/replicasets/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/replicasets/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams__namespace = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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
    char *keyQuery_gracePeriodSeconds = NULL;
    char * valueQuery_gracePeriodSeconds = NULL;
    keyValuePair_t *keyPairQuery_gracePeriodSeconds = 0;
    if (gracePeriodSeconds)
    {
        keyQuery_gracePeriodSeconds = strdup("gracePeriodSeconds");
        valueQuery_gracePeriodSeconds = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_gracePeriodSeconds, MAX_NUMBER_LENGTH, "%d", gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = keyValuePair_create(keyQuery_gracePeriodSeconds, valueQuery_gracePeriodSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_gracePeriodSeconds);
    }

    // query parameters
    char *keyQuery_orphanDependents = NULL;
    char * valueQuery_orphanDependents = NULL;
    keyValuePair_t *keyPairQuery_orphanDependents = 0;
    if (orphanDependents)
    {
        keyQuery_orphanDependents = strdup("orphanDependents");
        valueQuery_orphanDependents = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_orphanDependents, MAX_NUMBER_LENGTH, "%d", orphanDependents);
        keyPairQuery_orphanDependents = keyValuePair_create(keyQuery_orphanDependents, valueQuery_orphanDependents);
        list_addElement(localVarQueryParameters,keyPairQuery_orphanDependents);
    }

    // query parameters
    char *keyQuery_propagationPolicy = NULL;
    char * valueQuery_propagationPolicy = NULL;
    keyValuePair_t *keyPairQuery_propagationPolicy = 0;
    if (propagationPolicy)
    {
        keyQuery_propagationPolicy = strdup("propagationPolicy");
        valueQuery_propagationPolicy = strdup((propagationPolicy));
        keyPairQuery_propagationPolicy = keyValuePair_create(keyQuery_propagationPolicy, valueQuery_propagationPolicy);
        list_addElement(localVarQueryParameters,keyPairQuery_propagationPolicy);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_delete_options_convertToJSON(body);
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
                    "DELETE");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 202) {
        printf("%s\n","Accepted");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_status_t *elementToReturn = v1_status_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    free(localVarToReplace_name);
    free(localVarToReplace__namespace);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
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
    if(keyQuery_gracePeriodSeconds){
        free(keyQuery_gracePeriodSeconds);
        keyQuery_gracePeriodSeconds = NULL;
    }
    if(valueQuery_gracePeriodSeconds){
        free(valueQuery_gracePeriodSeconds);
        valueQuery_gracePeriodSeconds = NULL;
    }
    if(keyPairQuery_gracePeriodSeconds){
        keyValuePair_free(keyPairQuery_gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = NULL;
    }
    if(keyQuery_orphanDependents){
        free(keyQuery_orphanDependents);
        keyQuery_orphanDependents = NULL;
    }
    if(valueQuery_orphanDependents){
        free(valueQuery_orphanDependents);
        valueQuery_orphanDependents = NULL;
    }
    if(keyPairQuery_orphanDependents){
        keyValuePair_free(keyPairQuery_orphanDependents);
        keyPairQuery_orphanDependents = NULL;
    }
    if(keyQuery_propagationPolicy){
        free(keyQuery_propagationPolicy);
        keyQuery_propagationPolicy = NULL;
    }
    if(valueQuery_propagationPolicy){
        free(valueQuery_propagationPolicy);
        valueQuery_propagationPolicy = NULL;
    }
    if(keyPairQuery_propagationPolicy){
        keyValuePair_free(keyPairQuery_propagationPolicy);
        keyPairQuery_propagationPolicy = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// delete a StatefulSet
//
v1_status_t*
AppsV1API_deleteNamespacedStatefulSet(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/statefulsets/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/statefulsets/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams__namespace = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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
    char *keyQuery_gracePeriodSeconds = NULL;
    char * valueQuery_gracePeriodSeconds = NULL;
    keyValuePair_t *keyPairQuery_gracePeriodSeconds = 0;
    if (gracePeriodSeconds)
    {
        keyQuery_gracePeriodSeconds = strdup("gracePeriodSeconds");
        valueQuery_gracePeriodSeconds = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_gracePeriodSeconds, MAX_NUMBER_LENGTH, "%d", gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = keyValuePair_create(keyQuery_gracePeriodSeconds, valueQuery_gracePeriodSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_gracePeriodSeconds);
    }

    // query parameters
    char *keyQuery_orphanDependents = NULL;
    char * valueQuery_orphanDependents = NULL;
    keyValuePair_t *keyPairQuery_orphanDependents = 0;
    if (orphanDependents)
    {
        keyQuery_orphanDependents = strdup("orphanDependents");
        valueQuery_orphanDependents = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_orphanDependents, MAX_NUMBER_LENGTH, "%d", orphanDependents);
        keyPairQuery_orphanDependents = keyValuePair_create(keyQuery_orphanDependents, valueQuery_orphanDependents);
        list_addElement(localVarQueryParameters,keyPairQuery_orphanDependents);
    }

    // query parameters
    char *keyQuery_propagationPolicy = NULL;
    char * valueQuery_propagationPolicy = NULL;
    keyValuePair_t *keyPairQuery_propagationPolicy = 0;
    if (propagationPolicy)
    {
        keyQuery_propagationPolicy = strdup("propagationPolicy");
        valueQuery_propagationPolicy = strdup((propagationPolicy));
        keyPairQuery_propagationPolicy = keyValuePair_create(keyQuery_propagationPolicy, valueQuery_propagationPolicy);
        list_addElement(localVarQueryParameters,keyPairQuery_propagationPolicy);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_delete_options_convertToJSON(body);
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
                    "DELETE");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 202) {
        printf("%s\n","Accepted");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_status_t *elementToReturn = v1_status_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    free(localVarToReplace_name);
    free(localVarToReplace__namespace);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
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
    if(keyQuery_gracePeriodSeconds){
        free(keyQuery_gracePeriodSeconds);
        keyQuery_gracePeriodSeconds = NULL;
    }
    if(valueQuery_gracePeriodSeconds){
        free(valueQuery_gracePeriodSeconds);
        valueQuery_gracePeriodSeconds = NULL;
    }
    if(keyPairQuery_gracePeriodSeconds){
        keyValuePair_free(keyPairQuery_gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = NULL;
    }
    if(keyQuery_orphanDependents){
        free(keyQuery_orphanDependents);
        keyQuery_orphanDependents = NULL;
    }
    if(valueQuery_orphanDependents){
        free(valueQuery_orphanDependents);
        valueQuery_orphanDependents = NULL;
    }
    if(keyPairQuery_orphanDependents){
        keyValuePair_free(keyPairQuery_orphanDependents);
        keyPairQuery_orphanDependents = NULL;
    }
    if(keyQuery_propagationPolicy){
        free(keyQuery_propagationPolicy);
        keyQuery_propagationPolicy = NULL;
    }
    if(valueQuery_propagationPolicy){
        free(valueQuery_propagationPolicy);
        valueQuery_propagationPolicy = NULL;
    }
    if(keyPairQuery_propagationPolicy){
        keyValuePair_free(keyPairQuery_propagationPolicy);
        keyPairQuery_propagationPolicy = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// get available resources
//
v1_api_resource_list_t*
AppsV1API_getAPIResources(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/");



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
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_api_resource_list_t *elementToReturn = v1_api_resource_list_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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

// list or watch objects of kind ControllerRevision
//
v1_controller_revision_list_t*
AppsV1API_listControllerRevisionForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , int timeoutSeconds , int watch )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/controllerrevisions")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/controllerrevisions");




    // query parameters
    char *keyQuery_allowWatchBookmarks = NULL;
    char * valueQuery_allowWatchBookmarks = NULL;
    keyValuePair_t *keyPairQuery_allowWatchBookmarks = 0;
    if (allowWatchBookmarks)
    {
        keyQuery_allowWatchBookmarks = strdup("allowWatchBookmarks");
        valueQuery_allowWatchBookmarks = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_allowWatchBookmarks, MAX_NUMBER_LENGTH, "%d", allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = keyValuePair_create(keyQuery_allowWatchBookmarks, valueQuery_allowWatchBookmarks);
        list_addElement(localVarQueryParameters,keyPairQuery_allowWatchBookmarks);
    }

    // query parameters
    char *keyQuery__continue = NULL;
    char * valueQuery__continue = NULL;
    keyValuePair_t *keyPairQuery__continue = 0;
    if (_continue)
    {
        keyQuery__continue = strdup("continue");
        valueQuery__continue = strdup((_continue));
        keyPairQuery__continue = keyValuePair_create(keyQuery__continue, valueQuery__continue);
        list_addElement(localVarQueryParameters,keyPairQuery__continue);
    }

    // query parameters
    char *keyQuery_fieldSelector = NULL;
    char * valueQuery_fieldSelector = NULL;
    keyValuePair_t *keyPairQuery_fieldSelector = 0;
    if (fieldSelector)
    {
        keyQuery_fieldSelector = strdup("fieldSelector");
        valueQuery_fieldSelector = strdup((fieldSelector));
        keyPairQuery_fieldSelector = keyValuePair_create(keyQuery_fieldSelector, valueQuery_fieldSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldSelector);
    }

    // query parameters
    char *keyQuery_labelSelector = NULL;
    char * valueQuery_labelSelector = NULL;
    keyValuePair_t *keyPairQuery_labelSelector = 0;
    if (labelSelector)
    {
        keyQuery_labelSelector = strdup("labelSelector");
        valueQuery_labelSelector = strdup((labelSelector));
        keyPairQuery_labelSelector = keyValuePair_create(keyQuery_labelSelector, valueQuery_labelSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_labelSelector);
    }

    // query parameters
    char *keyQuery_limit = NULL;
    char * valueQuery_limit = NULL;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_limit, MAX_NUMBER_LENGTH, "%d", limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, valueQuery_limit);
        list_addElement(localVarQueryParameters,keyPairQuery_limit);
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

    // query parameters
    char *keyQuery_resourceVersion = NULL;
    char * valueQuery_resourceVersion = NULL;
    keyValuePair_t *keyPairQuery_resourceVersion = 0;
    if (resourceVersion)
    {
        keyQuery_resourceVersion = strdup("resourceVersion");
        valueQuery_resourceVersion = strdup((resourceVersion));
        keyPairQuery_resourceVersion = keyValuePair_create(keyQuery_resourceVersion, valueQuery_resourceVersion);
        list_addElement(localVarQueryParameters,keyPairQuery_resourceVersion);
    }

    // query parameters
    char *keyQuery_timeoutSeconds = NULL;
    char * valueQuery_timeoutSeconds = NULL;
    keyValuePair_t *keyPairQuery_timeoutSeconds = 0;
    if (timeoutSeconds)
    {
        keyQuery_timeoutSeconds = strdup("timeoutSeconds");
        valueQuery_timeoutSeconds = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_timeoutSeconds, MAX_NUMBER_LENGTH, "%d", timeoutSeconds);
        keyPairQuery_timeoutSeconds = keyValuePair_create(keyQuery_timeoutSeconds, valueQuery_timeoutSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_timeoutSeconds);
    }

    // query parameters
    char *keyQuery_watch = NULL;
    char * valueQuery_watch = NULL;
    keyValuePair_t *keyPairQuery_watch = 0;
    if (watch)
    {
        keyQuery_watch = strdup("watch");
        valueQuery_watch = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_watch, MAX_NUMBER_LENGTH, "%d", watch);
        keyPairQuery_watch = keyValuePair_create(keyQuery_watch, valueQuery_watch);
        list_addElement(localVarQueryParameters,keyPairQuery_watch);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarHeaderType,"application/json;stream=watch"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf;stream=watch"); //produces
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
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_controller_revision_list_t *elementToReturn = v1_controller_revision_list_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    if(keyQuery_allowWatchBookmarks){
        free(keyQuery_allowWatchBookmarks);
        keyQuery_allowWatchBookmarks = NULL;
    }
    if(valueQuery_allowWatchBookmarks){
        free(valueQuery_allowWatchBookmarks);
        valueQuery_allowWatchBookmarks = NULL;
    }
    if(keyPairQuery_allowWatchBookmarks){
        keyValuePair_free(keyPairQuery_allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = NULL;
    }
    if(keyQuery__continue){
        free(keyQuery__continue);
        keyQuery__continue = NULL;
    }
    if(valueQuery__continue){
        free(valueQuery__continue);
        valueQuery__continue = NULL;
    }
    if(keyPairQuery__continue){
        keyValuePair_free(keyPairQuery__continue);
        keyPairQuery__continue = NULL;
    }
    if(keyQuery_fieldSelector){
        free(keyQuery_fieldSelector);
        keyQuery_fieldSelector = NULL;
    }
    if(valueQuery_fieldSelector){
        free(valueQuery_fieldSelector);
        valueQuery_fieldSelector = NULL;
    }
    if(keyPairQuery_fieldSelector){
        keyValuePair_free(keyPairQuery_fieldSelector);
        keyPairQuery_fieldSelector = NULL;
    }
    if(keyQuery_labelSelector){
        free(keyQuery_labelSelector);
        keyQuery_labelSelector = NULL;
    }
    if(valueQuery_labelSelector){
        free(valueQuery_labelSelector);
        valueQuery_labelSelector = NULL;
    }
    if(keyPairQuery_labelSelector){
        keyValuePair_free(keyPairQuery_labelSelector);
        keyPairQuery_labelSelector = NULL;
    }
    if(keyQuery_limit){
        free(keyQuery_limit);
        keyQuery_limit = NULL;
    }
    if(valueQuery_limit){
        free(valueQuery_limit);
        valueQuery_limit = NULL;
    }
    if(keyPairQuery_limit){
        keyValuePair_free(keyPairQuery_limit);
        keyPairQuery_limit = NULL;
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
    if(keyQuery_resourceVersion){
        free(keyQuery_resourceVersion);
        keyQuery_resourceVersion = NULL;
    }
    if(valueQuery_resourceVersion){
        free(valueQuery_resourceVersion);
        valueQuery_resourceVersion = NULL;
    }
    if(keyPairQuery_resourceVersion){
        keyValuePair_free(keyPairQuery_resourceVersion);
        keyPairQuery_resourceVersion = NULL;
    }
    if(keyQuery_timeoutSeconds){
        free(keyQuery_timeoutSeconds);
        keyQuery_timeoutSeconds = NULL;
    }
    if(valueQuery_timeoutSeconds){
        free(valueQuery_timeoutSeconds);
        valueQuery_timeoutSeconds = NULL;
    }
    if(keyPairQuery_timeoutSeconds){
        keyValuePair_free(keyPairQuery_timeoutSeconds);
        keyPairQuery_timeoutSeconds = NULL;
    }
    if(keyQuery_watch){
        free(keyQuery_watch);
        keyQuery_watch = NULL;
    }
    if(valueQuery_watch){
        free(valueQuery_watch);
        valueQuery_watch = NULL;
    }
    if(keyPairQuery_watch){
        keyValuePair_free(keyPairQuery_watch);
        keyPairQuery_watch = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// list or watch objects of kind DaemonSet
//
v1_daemon_set_list_t*
AppsV1API_listDaemonSetForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , int timeoutSeconds , int watch )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/daemonsets")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/daemonsets");




    // query parameters
    char *keyQuery_allowWatchBookmarks = NULL;
    char * valueQuery_allowWatchBookmarks = NULL;
    keyValuePair_t *keyPairQuery_allowWatchBookmarks = 0;
    if (allowWatchBookmarks)
    {
        keyQuery_allowWatchBookmarks = strdup("allowWatchBookmarks");
        valueQuery_allowWatchBookmarks = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_allowWatchBookmarks, MAX_NUMBER_LENGTH, "%d", allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = keyValuePair_create(keyQuery_allowWatchBookmarks, valueQuery_allowWatchBookmarks);
        list_addElement(localVarQueryParameters,keyPairQuery_allowWatchBookmarks);
    }

    // query parameters
    char *keyQuery__continue = NULL;
    char * valueQuery__continue = NULL;
    keyValuePair_t *keyPairQuery__continue = 0;
    if (_continue)
    {
        keyQuery__continue = strdup("continue");
        valueQuery__continue = strdup((_continue));
        keyPairQuery__continue = keyValuePair_create(keyQuery__continue, valueQuery__continue);
        list_addElement(localVarQueryParameters,keyPairQuery__continue);
    }

    // query parameters
    char *keyQuery_fieldSelector = NULL;
    char * valueQuery_fieldSelector = NULL;
    keyValuePair_t *keyPairQuery_fieldSelector = 0;
    if (fieldSelector)
    {
        keyQuery_fieldSelector = strdup("fieldSelector");
        valueQuery_fieldSelector = strdup((fieldSelector));
        keyPairQuery_fieldSelector = keyValuePair_create(keyQuery_fieldSelector, valueQuery_fieldSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldSelector);
    }

    // query parameters
    char *keyQuery_labelSelector = NULL;
    char * valueQuery_labelSelector = NULL;
    keyValuePair_t *keyPairQuery_labelSelector = 0;
    if (labelSelector)
    {
        keyQuery_labelSelector = strdup("labelSelector");
        valueQuery_labelSelector = strdup((labelSelector));
        keyPairQuery_labelSelector = keyValuePair_create(keyQuery_labelSelector, valueQuery_labelSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_labelSelector);
    }

    // query parameters
    char *keyQuery_limit = NULL;
    char * valueQuery_limit = NULL;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_limit, MAX_NUMBER_LENGTH, "%d", limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, valueQuery_limit);
        list_addElement(localVarQueryParameters,keyPairQuery_limit);
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

    // query parameters
    char *keyQuery_resourceVersion = NULL;
    char * valueQuery_resourceVersion = NULL;
    keyValuePair_t *keyPairQuery_resourceVersion = 0;
    if (resourceVersion)
    {
        keyQuery_resourceVersion = strdup("resourceVersion");
        valueQuery_resourceVersion = strdup((resourceVersion));
        keyPairQuery_resourceVersion = keyValuePair_create(keyQuery_resourceVersion, valueQuery_resourceVersion);
        list_addElement(localVarQueryParameters,keyPairQuery_resourceVersion);
    }

    // query parameters
    char *keyQuery_timeoutSeconds = NULL;
    char * valueQuery_timeoutSeconds = NULL;
    keyValuePair_t *keyPairQuery_timeoutSeconds = 0;
    if (timeoutSeconds)
    {
        keyQuery_timeoutSeconds = strdup("timeoutSeconds");
        valueQuery_timeoutSeconds = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_timeoutSeconds, MAX_NUMBER_LENGTH, "%d", timeoutSeconds);
        keyPairQuery_timeoutSeconds = keyValuePair_create(keyQuery_timeoutSeconds, valueQuery_timeoutSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_timeoutSeconds);
    }

    // query parameters
    char *keyQuery_watch = NULL;
    char * valueQuery_watch = NULL;
    keyValuePair_t *keyPairQuery_watch = 0;
    if (watch)
    {
        keyQuery_watch = strdup("watch");
        valueQuery_watch = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_watch, MAX_NUMBER_LENGTH, "%d", watch);
        keyPairQuery_watch = keyValuePair_create(keyQuery_watch, valueQuery_watch);
        list_addElement(localVarQueryParameters,keyPairQuery_watch);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarHeaderType,"application/json;stream=watch"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf;stream=watch"); //produces
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
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_daemon_set_list_t *elementToReturn = v1_daemon_set_list_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    if(keyQuery_allowWatchBookmarks){
        free(keyQuery_allowWatchBookmarks);
        keyQuery_allowWatchBookmarks = NULL;
    }
    if(valueQuery_allowWatchBookmarks){
        free(valueQuery_allowWatchBookmarks);
        valueQuery_allowWatchBookmarks = NULL;
    }
    if(keyPairQuery_allowWatchBookmarks){
        keyValuePair_free(keyPairQuery_allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = NULL;
    }
    if(keyQuery__continue){
        free(keyQuery__continue);
        keyQuery__continue = NULL;
    }
    if(valueQuery__continue){
        free(valueQuery__continue);
        valueQuery__continue = NULL;
    }
    if(keyPairQuery__continue){
        keyValuePair_free(keyPairQuery__continue);
        keyPairQuery__continue = NULL;
    }
    if(keyQuery_fieldSelector){
        free(keyQuery_fieldSelector);
        keyQuery_fieldSelector = NULL;
    }
    if(valueQuery_fieldSelector){
        free(valueQuery_fieldSelector);
        valueQuery_fieldSelector = NULL;
    }
    if(keyPairQuery_fieldSelector){
        keyValuePair_free(keyPairQuery_fieldSelector);
        keyPairQuery_fieldSelector = NULL;
    }
    if(keyQuery_labelSelector){
        free(keyQuery_labelSelector);
        keyQuery_labelSelector = NULL;
    }
    if(valueQuery_labelSelector){
        free(valueQuery_labelSelector);
        valueQuery_labelSelector = NULL;
    }
    if(keyPairQuery_labelSelector){
        keyValuePair_free(keyPairQuery_labelSelector);
        keyPairQuery_labelSelector = NULL;
    }
    if(keyQuery_limit){
        free(keyQuery_limit);
        keyQuery_limit = NULL;
    }
    if(valueQuery_limit){
        free(valueQuery_limit);
        valueQuery_limit = NULL;
    }
    if(keyPairQuery_limit){
        keyValuePair_free(keyPairQuery_limit);
        keyPairQuery_limit = NULL;
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
    if(keyQuery_resourceVersion){
        free(keyQuery_resourceVersion);
        keyQuery_resourceVersion = NULL;
    }
    if(valueQuery_resourceVersion){
        free(valueQuery_resourceVersion);
        valueQuery_resourceVersion = NULL;
    }
    if(keyPairQuery_resourceVersion){
        keyValuePair_free(keyPairQuery_resourceVersion);
        keyPairQuery_resourceVersion = NULL;
    }
    if(keyQuery_timeoutSeconds){
        free(keyQuery_timeoutSeconds);
        keyQuery_timeoutSeconds = NULL;
    }
    if(valueQuery_timeoutSeconds){
        free(valueQuery_timeoutSeconds);
        valueQuery_timeoutSeconds = NULL;
    }
    if(keyPairQuery_timeoutSeconds){
        keyValuePair_free(keyPairQuery_timeoutSeconds);
        keyPairQuery_timeoutSeconds = NULL;
    }
    if(keyQuery_watch){
        free(keyQuery_watch);
        keyQuery_watch = NULL;
    }
    if(valueQuery_watch){
        free(valueQuery_watch);
        valueQuery_watch = NULL;
    }
    if(keyPairQuery_watch){
        keyValuePair_free(keyPairQuery_watch);
        keyPairQuery_watch = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// list or watch objects of kind Deployment
//
v1_deployment_list_t*
AppsV1API_listDeploymentForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , int timeoutSeconds , int watch )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/deployments")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/deployments");




    // query parameters
    char *keyQuery_allowWatchBookmarks = NULL;
    char * valueQuery_allowWatchBookmarks = NULL;
    keyValuePair_t *keyPairQuery_allowWatchBookmarks = 0;
    if (allowWatchBookmarks)
    {
        keyQuery_allowWatchBookmarks = strdup("allowWatchBookmarks");
        valueQuery_allowWatchBookmarks = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_allowWatchBookmarks, MAX_NUMBER_LENGTH, "%d", allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = keyValuePair_create(keyQuery_allowWatchBookmarks, valueQuery_allowWatchBookmarks);
        list_addElement(localVarQueryParameters,keyPairQuery_allowWatchBookmarks);
    }

    // query parameters
    char *keyQuery__continue = NULL;
    char * valueQuery__continue = NULL;
    keyValuePair_t *keyPairQuery__continue = 0;
    if (_continue)
    {
        keyQuery__continue = strdup("continue");
        valueQuery__continue = strdup((_continue));
        keyPairQuery__continue = keyValuePair_create(keyQuery__continue, valueQuery__continue);
        list_addElement(localVarQueryParameters,keyPairQuery__continue);
    }

    // query parameters
    char *keyQuery_fieldSelector = NULL;
    char * valueQuery_fieldSelector = NULL;
    keyValuePair_t *keyPairQuery_fieldSelector = 0;
    if (fieldSelector)
    {
        keyQuery_fieldSelector = strdup("fieldSelector");
        valueQuery_fieldSelector = strdup((fieldSelector));
        keyPairQuery_fieldSelector = keyValuePair_create(keyQuery_fieldSelector, valueQuery_fieldSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldSelector);
    }

    // query parameters
    char *keyQuery_labelSelector = NULL;
    char * valueQuery_labelSelector = NULL;
    keyValuePair_t *keyPairQuery_labelSelector = 0;
    if (labelSelector)
    {
        keyQuery_labelSelector = strdup("labelSelector");
        valueQuery_labelSelector = strdup((labelSelector));
        keyPairQuery_labelSelector = keyValuePair_create(keyQuery_labelSelector, valueQuery_labelSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_labelSelector);
    }

    // query parameters
    char *keyQuery_limit = NULL;
    char * valueQuery_limit = NULL;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_limit, MAX_NUMBER_LENGTH, "%d", limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, valueQuery_limit);
        list_addElement(localVarQueryParameters,keyPairQuery_limit);
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

    // query parameters
    char *keyQuery_resourceVersion = NULL;
    char * valueQuery_resourceVersion = NULL;
    keyValuePair_t *keyPairQuery_resourceVersion = 0;
    if (resourceVersion)
    {
        keyQuery_resourceVersion = strdup("resourceVersion");
        valueQuery_resourceVersion = strdup((resourceVersion));
        keyPairQuery_resourceVersion = keyValuePair_create(keyQuery_resourceVersion, valueQuery_resourceVersion);
        list_addElement(localVarQueryParameters,keyPairQuery_resourceVersion);
    }

    // query parameters
    char *keyQuery_timeoutSeconds = NULL;
    char * valueQuery_timeoutSeconds = NULL;
    keyValuePair_t *keyPairQuery_timeoutSeconds = 0;
    if (timeoutSeconds)
    {
        keyQuery_timeoutSeconds = strdup("timeoutSeconds");
        valueQuery_timeoutSeconds = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_timeoutSeconds, MAX_NUMBER_LENGTH, "%d", timeoutSeconds);
        keyPairQuery_timeoutSeconds = keyValuePair_create(keyQuery_timeoutSeconds, valueQuery_timeoutSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_timeoutSeconds);
    }

    // query parameters
    char *keyQuery_watch = NULL;
    char * valueQuery_watch = NULL;
    keyValuePair_t *keyPairQuery_watch = 0;
    if (watch)
    {
        keyQuery_watch = strdup("watch");
        valueQuery_watch = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_watch, MAX_NUMBER_LENGTH, "%d", watch);
        keyPairQuery_watch = keyValuePair_create(keyQuery_watch, valueQuery_watch);
        list_addElement(localVarQueryParameters,keyPairQuery_watch);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarHeaderType,"application/json;stream=watch"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf;stream=watch"); //produces
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
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_deployment_list_t *elementToReturn = v1_deployment_list_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    if(keyQuery_allowWatchBookmarks){
        free(keyQuery_allowWatchBookmarks);
        keyQuery_allowWatchBookmarks = NULL;
    }
    if(valueQuery_allowWatchBookmarks){
        free(valueQuery_allowWatchBookmarks);
        valueQuery_allowWatchBookmarks = NULL;
    }
    if(keyPairQuery_allowWatchBookmarks){
        keyValuePair_free(keyPairQuery_allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = NULL;
    }
    if(keyQuery__continue){
        free(keyQuery__continue);
        keyQuery__continue = NULL;
    }
    if(valueQuery__continue){
        free(valueQuery__continue);
        valueQuery__continue = NULL;
    }
    if(keyPairQuery__continue){
        keyValuePair_free(keyPairQuery__continue);
        keyPairQuery__continue = NULL;
    }
    if(keyQuery_fieldSelector){
        free(keyQuery_fieldSelector);
        keyQuery_fieldSelector = NULL;
    }
    if(valueQuery_fieldSelector){
        free(valueQuery_fieldSelector);
        valueQuery_fieldSelector = NULL;
    }
    if(keyPairQuery_fieldSelector){
        keyValuePair_free(keyPairQuery_fieldSelector);
        keyPairQuery_fieldSelector = NULL;
    }
    if(keyQuery_labelSelector){
        free(keyQuery_labelSelector);
        keyQuery_labelSelector = NULL;
    }
    if(valueQuery_labelSelector){
        free(valueQuery_labelSelector);
        valueQuery_labelSelector = NULL;
    }
    if(keyPairQuery_labelSelector){
        keyValuePair_free(keyPairQuery_labelSelector);
        keyPairQuery_labelSelector = NULL;
    }
    if(keyQuery_limit){
        free(keyQuery_limit);
        keyQuery_limit = NULL;
    }
    if(valueQuery_limit){
        free(valueQuery_limit);
        valueQuery_limit = NULL;
    }
    if(keyPairQuery_limit){
        keyValuePair_free(keyPairQuery_limit);
        keyPairQuery_limit = NULL;
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
    if(keyQuery_resourceVersion){
        free(keyQuery_resourceVersion);
        keyQuery_resourceVersion = NULL;
    }
    if(valueQuery_resourceVersion){
        free(valueQuery_resourceVersion);
        valueQuery_resourceVersion = NULL;
    }
    if(keyPairQuery_resourceVersion){
        keyValuePair_free(keyPairQuery_resourceVersion);
        keyPairQuery_resourceVersion = NULL;
    }
    if(keyQuery_timeoutSeconds){
        free(keyQuery_timeoutSeconds);
        keyQuery_timeoutSeconds = NULL;
    }
    if(valueQuery_timeoutSeconds){
        free(valueQuery_timeoutSeconds);
        valueQuery_timeoutSeconds = NULL;
    }
    if(keyPairQuery_timeoutSeconds){
        keyValuePair_free(keyPairQuery_timeoutSeconds);
        keyPairQuery_timeoutSeconds = NULL;
    }
    if(keyQuery_watch){
        free(keyQuery_watch);
        keyQuery_watch = NULL;
    }
    if(valueQuery_watch){
        free(valueQuery_watch);
        valueQuery_watch = NULL;
    }
    if(keyPairQuery_watch){
        keyValuePair_free(keyPairQuery_watch);
        keyPairQuery_watch = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// list or watch objects of kind ControllerRevision
//
v1_controller_revision_list_t*
AppsV1API_listNamespacedControllerRevision(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/controllerrevisions")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/controllerrevisions");


    // Path Params
    long sizeOfPathParams__namespace = strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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

    // query parameters
    char *keyQuery_allowWatchBookmarks = NULL;
    char * valueQuery_allowWatchBookmarks = NULL;
    keyValuePair_t *keyPairQuery_allowWatchBookmarks = 0;
    if (allowWatchBookmarks)
    {
        keyQuery_allowWatchBookmarks = strdup("allowWatchBookmarks");
        valueQuery_allowWatchBookmarks = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_allowWatchBookmarks, MAX_NUMBER_LENGTH, "%d", allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = keyValuePair_create(keyQuery_allowWatchBookmarks, valueQuery_allowWatchBookmarks);
        list_addElement(localVarQueryParameters,keyPairQuery_allowWatchBookmarks);
    }

    // query parameters
    char *keyQuery__continue = NULL;
    char * valueQuery__continue = NULL;
    keyValuePair_t *keyPairQuery__continue = 0;
    if (_continue)
    {
        keyQuery__continue = strdup("continue");
        valueQuery__continue = strdup((_continue));
        keyPairQuery__continue = keyValuePair_create(keyQuery__continue, valueQuery__continue);
        list_addElement(localVarQueryParameters,keyPairQuery__continue);
    }

    // query parameters
    char *keyQuery_fieldSelector = NULL;
    char * valueQuery_fieldSelector = NULL;
    keyValuePair_t *keyPairQuery_fieldSelector = 0;
    if (fieldSelector)
    {
        keyQuery_fieldSelector = strdup("fieldSelector");
        valueQuery_fieldSelector = strdup((fieldSelector));
        keyPairQuery_fieldSelector = keyValuePair_create(keyQuery_fieldSelector, valueQuery_fieldSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldSelector);
    }

    // query parameters
    char *keyQuery_labelSelector = NULL;
    char * valueQuery_labelSelector = NULL;
    keyValuePair_t *keyPairQuery_labelSelector = 0;
    if (labelSelector)
    {
        keyQuery_labelSelector = strdup("labelSelector");
        valueQuery_labelSelector = strdup((labelSelector));
        keyPairQuery_labelSelector = keyValuePair_create(keyQuery_labelSelector, valueQuery_labelSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_labelSelector);
    }

    // query parameters
    char *keyQuery_limit = NULL;
    char * valueQuery_limit = NULL;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_limit, MAX_NUMBER_LENGTH, "%d", limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, valueQuery_limit);
        list_addElement(localVarQueryParameters,keyPairQuery_limit);
    }

    // query parameters
    char *keyQuery_resourceVersion = NULL;
    char * valueQuery_resourceVersion = NULL;
    keyValuePair_t *keyPairQuery_resourceVersion = 0;
    if (resourceVersion)
    {
        keyQuery_resourceVersion = strdup("resourceVersion");
        valueQuery_resourceVersion = strdup((resourceVersion));
        keyPairQuery_resourceVersion = keyValuePair_create(keyQuery_resourceVersion, valueQuery_resourceVersion);
        list_addElement(localVarQueryParameters,keyPairQuery_resourceVersion);
    }

    // query parameters
    char *keyQuery_timeoutSeconds = NULL;
    char * valueQuery_timeoutSeconds = NULL;
    keyValuePair_t *keyPairQuery_timeoutSeconds = 0;
    if (timeoutSeconds)
    {
        keyQuery_timeoutSeconds = strdup("timeoutSeconds");
        valueQuery_timeoutSeconds = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_timeoutSeconds, MAX_NUMBER_LENGTH, "%d", timeoutSeconds);
        keyPairQuery_timeoutSeconds = keyValuePair_create(keyQuery_timeoutSeconds, valueQuery_timeoutSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_timeoutSeconds);
    }

    // query parameters
    char *keyQuery_watch = NULL;
    char * valueQuery_watch = NULL;
    keyValuePair_t *keyPairQuery_watch = 0;
    if (watch)
    {
        keyQuery_watch = strdup("watch");
        valueQuery_watch = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_watch, MAX_NUMBER_LENGTH, "%d", watch);
        keyPairQuery_watch = keyValuePair_create(keyQuery_watch, valueQuery_watch);
        list_addElement(localVarQueryParameters,keyPairQuery_watch);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarHeaderType,"application/json;stream=watch"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf;stream=watch"); //produces
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
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_controller_revision_list_t *elementToReturn = v1_controller_revision_list_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    free(localVarToReplace__namespace);
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
    if(keyQuery_allowWatchBookmarks){
        free(keyQuery_allowWatchBookmarks);
        keyQuery_allowWatchBookmarks = NULL;
    }
    if(valueQuery_allowWatchBookmarks){
        free(valueQuery_allowWatchBookmarks);
        valueQuery_allowWatchBookmarks = NULL;
    }
    if(keyPairQuery_allowWatchBookmarks){
        keyValuePair_free(keyPairQuery_allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = NULL;
    }
    if(keyQuery__continue){
        free(keyQuery__continue);
        keyQuery__continue = NULL;
    }
    if(valueQuery__continue){
        free(valueQuery__continue);
        valueQuery__continue = NULL;
    }
    if(keyPairQuery__continue){
        keyValuePair_free(keyPairQuery__continue);
        keyPairQuery__continue = NULL;
    }
    if(keyQuery_fieldSelector){
        free(keyQuery_fieldSelector);
        keyQuery_fieldSelector = NULL;
    }
    if(valueQuery_fieldSelector){
        free(valueQuery_fieldSelector);
        valueQuery_fieldSelector = NULL;
    }
    if(keyPairQuery_fieldSelector){
        keyValuePair_free(keyPairQuery_fieldSelector);
        keyPairQuery_fieldSelector = NULL;
    }
    if(keyQuery_labelSelector){
        free(keyQuery_labelSelector);
        keyQuery_labelSelector = NULL;
    }
    if(valueQuery_labelSelector){
        free(valueQuery_labelSelector);
        valueQuery_labelSelector = NULL;
    }
    if(keyPairQuery_labelSelector){
        keyValuePair_free(keyPairQuery_labelSelector);
        keyPairQuery_labelSelector = NULL;
    }
    if(keyQuery_limit){
        free(keyQuery_limit);
        keyQuery_limit = NULL;
    }
    if(valueQuery_limit){
        free(valueQuery_limit);
        valueQuery_limit = NULL;
    }
    if(keyPairQuery_limit){
        keyValuePair_free(keyPairQuery_limit);
        keyPairQuery_limit = NULL;
    }
    if(keyQuery_resourceVersion){
        free(keyQuery_resourceVersion);
        keyQuery_resourceVersion = NULL;
    }
    if(valueQuery_resourceVersion){
        free(valueQuery_resourceVersion);
        valueQuery_resourceVersion = NULL;
    }
    if(keyPairQuery_resourceVersion){
        keyValuePair_free(keyPairQuery_resourceVersion);
        keyPairQuery_resourceVersion = NULL;
    }
    if(keyQuery_timeoutSeconds){
        free(keyQuery_timeoutSeconds);
        keyQuery_timeoutSeconds = NULL;
    }
    if(valueQuery_timeoutSeconds){
        free(valueQuery_timeoutSeconds);
        valueQuery_timeoutSeconds = NULL;
    }
    if(keyPairQuery_timeoutSeconds){
        keyValuePair_free(keyPairQuery_timeoutSeconds);
        keyPairQuery_timeoutSeconds = NULL;
    }
    if(keyQuery_watch){
        free(keyQuery_watch);
        keyQuery_watch = NULL;
    }
    if(valueQuery_watch){
        free(valueQuery_watch);
        valueQuery_watch = NULL;
    }
    if(keyPairQuery_watch){
        keyValuePair_free(keyPairQuery_watch);
        keyPairQuery_watch = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// list or watch objects of kind DaemonSet
//
v1_daemon_set_list_t*
AppsV1API_listNamespacedDaemonSet(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/daemonsets")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/daemonsets");


    // Path Params
    long sizeOfPathParams__namespace = strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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

    // query parameters
    char *keyQuery_allowWatchBookmarks = NULL;
    char * valueQuery_allowWatchBookmarks = NULL;
    keyValuePair_t *keyPairQuery_allowWatchBookmarks = 0;
    if (allowWatchBookmarks)
    {
        keyQuery_allowWatchBookmarks = strdup("allowWatchBookmarks");
        valueQuery_allowWatchBookmarks = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_allowWatchBookmarks, MAX_NUMBER_LENGTH, "%d", allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = keyValuePair_create(keyQuery_allowWatchBookmarks, valueQuery_allowWatchBookmarks);
        list_addElement(localVarQueryParameters,keyPairQuery_allowWatchBookmarks);
    }

    // query parameters
    char *keyQuery__continue = NULL;
    char * valueQuery__continue = NULL;
    keyValuePair_t *keyPairQuery__continue = 0;
    if (_continue)
    {
        keyQuery__continue = strdup("continue");
        valueQuery__continue = strdup((_continue));
        keyPairQuery__continue = keyValuePair_create(keyQuery__continue, valueQuery__continue);
        list_addElement(localVarQueryParameters,keyPairQuery__continue);
    }

    // query parameters
    char *keyQuery_fieldSelector = NULL;
    char * valueQuery_fieldSelector = NULL;
    keyValuePair_t *keyPairQuery_fieldSelector = 0;
    if (fieldSelector)
    {
        keyQuery_fieldSelector = strdup("fieldSelector");
        valueQuery_fieldSelector = strdup((fieldSelector));
        keyPairQuery_fieldSelector = keyValuePair_create(keyQuery_fieldSelector, valueQuery_fieldSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldSelector);
    }

    // query parameters
    char *keyQuery_labelSelector = NULL;
    char * valueQuery_labelSelector = NULL;
    keyValuePair_t *keyPairQuery_labelSelector = 0;
    if (labelSelector)
    {
        keyQuery_labelSelector = strdup("labelSelector");
        valueQuery_labelSelector = strdup((labelSelector));
        keyPairQuery_labelSelector = keyValuePair_create(keyQuery_labelSelector, valueQuery_labelSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_labelSelector);
    }

    // query parameters
    char *keyQuery_limit = NULL;
    char * valueQuery_limit = NULL;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_limit, MAX_NUMBER_LENGTH, "%d", limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, valueQuery_limit);
        list_addElement(localVarQueryParameters,keyPairQuery_limit);
    }

    // query parameters
    char *keyQuery_resourceVersion = NULL;
    char * valueQuery_resourceVersion = NULL;
    keyValuePair_t *keyPairQuery_resourceVersion = 0;
    if (resourceVersion)
    {
        keyQuery_resourceVersion = strdup("resourceVersion");
        valueQuery_resourceVersion = strdup((resourceVersion));
        keyPairQuery_resourceVersion = keyValuePair_create(keyQuery_resourceVersion, valueQuery_resourceVersion);
        list_addElement(localVarQueryParameters,keyPairQuery_resourceVersion);
    }

    // query parameters
    char *keyQuery_timeoutSeconds = NULL;
    char * valueQuery_timeoutSeconds = NULL;
    keyValuePair_t *keyPairQuery_timeoutSeconds = 0;
    if (timeoutSeconds)
    {
        keyQuery_timeoutSeconds = strdup("timeoutSeconds");
        valueQuery_timeoutSeconds = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_timeoutSeconds, MAX_NUMBER_LENGTH, "%d", timeoutSeconds);
        keyPairQuery_timeoutSeconds = keyValuePair_create(keyQuery_timeoutSeconds, valueQuery_timeoutSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_timeoutSeconds);
    }

    // query parameters
    char *keyQuery_watch = NULL;
    char * valueQuery_watch = NULL;
    keyValuePair_t *keyPairQuery_watch = 0;
    if (watch)
    {
        keyQuery_watch = strdup("watch");
        valueQuery_watch = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_watch, MAX_NUMBER_LENGTH, "%d", watch);
        keyPairQuery_watch = keyValuePair_create(keyQuery_watch, valueQuery_watch);
        list_addElement(localVarQueryParameters,keyPairQuery_watch);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarHeaderType,"application/json;stream=watch"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf;stream=watch"); //produces
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
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_daemon_set_list_t *elementToReturn = v1_daemon_set_list_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    free(localVarToReplace__namespace);
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
    if(keyQuery_allowWatchBookmarks){
        free(keyQuery_allowWatchBookmarks);
        keyQuery_allowWatchBookmarks = NULL;
    }
    if(valueQuery_allowWatchBookmarks){
        free(valueQuery_allowWatchBookmarks);
        valueQuery_allowWatchBookmarks = NULL;
    }
    if(keyPairQuery_allowWatchBookmarks){
        keyValuePair_free(keyPairQuery_allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = NULL;
    }
    if(keyQuery__continue){
        free(keyQuery__continue);
        keyQuery__continue = NULL;
    }
    if(valueQuery__continue){
        free(valueQuery__continue);
        valueQuery__continue = NULL;
    }
    if(keyPairQuery__continue){
        keyValuePair_free(keyPairQuery__continue);
        keyPairQuery__continue = NULL;
    }
    if(keyQuery_fieldSelector){
        free(keyQuery_fieldSelector);
        keyQuery_fieldSelector = NULL;
    }
    if(valueQuery_fieldSelector){
        free(valueQuery_fieldSelector);
        valueQuery_fieldSelector = NULL;
    }
    if(keyPairQuery_fieldSelector){
        keyValuePair_free(keyPairQuery_fieldSelector);
        keyPairQuery_fieldSelector = NULL;
    }
    if(keyQuery_labelSelector){
        free(keyQuery_labelSelector);
        keyQuery_labelSelector = NULL;
    }
    if(valueQuery_labelSelector){
        free(valueQuery_labelSelector);
        valueQuery_labelSelector = NULL;
    }
    if(keyPairQuery_labelSelector){
        keyValuePair_free(keyPairQuery_labelSelector);
        keyPairQuery_labelSelector = NULL;
    }
    if(keyQuery_limit){
        free(keyQuery_limit);
        keyQuery_limit = NULL;
    }
    if(valueQuery_limit){
        free(valueQuery_limit);
        valueQuery_limit = NULL;
    }
    if(keyPairQuery_limit){
        keyValuePair_free(keyPairQuery_limit);
        keyPairQuery_limit = NULL;
    }
    if(keyQuery_resourceVersion){
        free(keyQuery_resourceVersion);
        keyQuery_resourceVersion = NULL;
    }
    if(valueQuery_resourceVersion){
        free(valueQuery_resourceVersion);
        valueQuery_resourceVersion = NULL;
    }
    if(keyPairQuery_resourceVersion){
        keyValuePair_free(keyPairQuery_resourceVersion);
        keyPairQuery_resourceVersion = NULL;
    }
    if(keyQuery_timeoutSeconds){
        free(keyQuery_timeoutSeconds);
        keyQuery_timeoutSeconds = NULL;
    }
    if(valueQuery_timeoutSeconds){
        free(valueQuery_timeoutSeconds);
        valueQuery_timeoutSeconds = NULL;
    }
    if(keyPairQuery_timeoutSeconds){
        keyValuePair_free(keyPairQuery_timeoutSeconds);
        keyPairQuery_timeoutSeconds = NULL;
    }
    if(keyQuery_watch){
        free(keyQuery_watch);
        keyQuery_watch = NULL;
    }
    if(valueQuery_watch){
        free(valueQuery_watch);
        valueQuery_watch = NULL;
    }
    if(keyPairQuery_watch){
        keyValuePair_free(keyPairQuery_watch);
        keyPairQuery_watch = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// list or watch objects of kind Deployment
//
v1_deployment_list_t*
AppsV1API_listNamespacedDeployment(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/deployments")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/deployments");


    // Path Params
    long sizeOfPathParams__namespace = strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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

    // query parameters
    char *keyQuery_allowWatchBookmarks = NULL;
    char * valueQuery_allowWatchBookmarks = NULL;
    keyValuePair_t *keyPairQuery_allowWatchBookmarks = 0;
    if (allowWatchBookmarks)
    {
        keyQuery_allowWatchBookmarks = strdup("allowWatchBookmarks");
        valueQuery_allowWatchBookmarks = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_allowWatchBookmarks, MAX_NUMBER_LENGTH, "%d", allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = keyValuePair_create(keyQuery_allowWatchBookmarks, valueQuery_allowWatchBookmarks);
        list_addElement(localVarQueryParameters,keyPairQuery_allowWatchBookmarks);
    }

    // query parameters
    char *keyQuery__continue = NULL;
    char * valueQuery__continue = NULL;
    keyValuePair_t *keyPairQuery__continue = 0;
    if (_continue)
    {
        keyQuery__continue = strdup("continue");
        valueQuery__continue = strdup((_continue));
        keyPairQuery__continue = keyValuePair_create(keyQuery__continue, valueQuery__continue);
        list_addElement(localVarQueryParameters,keyPairQuery__continue);
    }

    // query parameters
    char *keyQuery_fieldSelector = NULL;
    char * valueQuery_fieldSelector = NULL;
    keyValuePair_t *keyPairQuery_fieldSelector = 0;
    if (fieldSelector)
    {
        keyQuery_fieldSelector = strdup("fieldSelector");
        valueQuery_fieldSelector = strdup((fieldSelector));
        keyPairQuery_fieldSelector = keyValuePair_create(keyQuery_fieldSelector, valueQuery_fieldSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldSelector);
    }

    // query parameters
    char *keyQuery_labelSelector = NULL;
    char * valueQuery_labelSelector = NULL;
    keyValuePair_t *keyPairQuery_labelSelector = 0;
    if (labelSelector)
    {
        keyQuery_labelSelector = strdup("labelSelector");
        valueQuery_labelSelector = strdup((labelSelector));
        keyPairQuery_labelSelector = keyValuePair_create(keyQuery_labelSelector, valueQuery_labelSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_labelSelector);
    }

    // query parameters
    char *keyQuery_limit = NULL;
    char * valueQuery_limit = NULL;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_limit, MAX_NUMBER_LENGTH, "%d", limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, valueQuery_limit);
        list_addElement(localVarQueryParameters,keyPairQuery_limit);
    }

    // query parameters
    char *keyQuery_resourceVersion = NULL;
    char * valueQuery_resourceVersion = NULL;
    keyValuePair_t *keyPairQuery_resourceVersion = 0;
    if (resourceVersion)
    {
        keyQuery_resourceVersion = strdup("resourceVersion");
        valueQuery_resourceVersion = strdup((resourceVersion));
        keyPairQuery_resourceVersion = keyValuePair_create(keyQuery_resourceVersion, valueQuery_resourceVersion);
        list_addElement(localVarQueryParameters,keyPairQuery_resourceVersion);
    }

    // query parameters
    char *keyQuery_timeoutSeconds = NULL;
    char * valueQuery_timeoutSeconds = NULL;
    keyValuePair_t *keyPairQuery_timeoutSeconds = 0;
    if (timeoutSeconds)
    {
        keyQuery_timeoutSeconds = strdup("timeoutSeconds");
        valueQuery_timeoutSeconds = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_timeoutSeconds, MAX_NUMBER_LENGTH, "%d", timeoutSeconds);
        keyPairQuery_timeoutSeconds = keyValuePair_create(keyQuery_timeoutSeconds, valueQuery_timeoutSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_timeoutSeconds);
    }

    // query parameters
    char *keyQuery_watch = NULL;
    char * valueQuery_watch = NULL;
    keyValuePair_t *keyPairQuery_watch = 0;
    if (watch)
    {
        keyQuery_watch = strdup("watch");
        valueQuery_watch = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_watch, MAX_NUMBER_LENGTH, "%d", watch);
        keyPairQuery_watch = keyValuePair_create(keyQuery_watch, valueQuery_watch);
        list_addElement(localVarQueryParameters,keyPairQuery_watch);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarHeaderType,"application/json;stream=watch"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf;stream=watch"); //produces
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
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_deployment_list_t *elementToReturn = v1_deployment_list_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    free(localVarToReplace__namespace);
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
    if(keyQuery_allowWatchBookmarks){
        free(keyQuery_allowWatchBookmarks);
        keyQuery_allowWatchBookmarks = NULL;
    }
    if(valueQuery_allowWatchBookmarks){
        free(valueQuery_allowWatchBookmarks);
        valueQuery_allowWatchBookmarks = NULL;
    }
    if(keyPairQuery_allowWatchBookmarks){
        keyValuePair_free(keyPairQuery_allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = NULL;
    }
    if(keyQuery__continue){
        free(keyQuery__continue);
        keyQuery__continue = NULL;
    }
    if(valueQuery__continue){
        free(valueQuery__continue);
        valueQuery__continue = NULL;
    }
    if(keyPairQuery__continue){
        keyValuePair_free(keyPairQuery__continue);
        keyPairQuery__continue = NULL;
    }
    if(keyQuery_fieldSelector){
        free(keyQuery_fieldSelector);
        keyQuery_fieldSelector = NULL;
    }
    if(valueQuery_fieldSelector){
        free(valueQuery_fieldSelector);
        valueQuery_fieldSelector = NULL;
    }
    if(keyPairQuery_fieldSelector){
        keyValuePair_free(keyPairQuery_fieldSelector);
        keyPairQuery_fieldSelector = NULL;
    }
    if(keyQuery_labelSelector){
        free(keyQuery_labelSelector);
        keyQuery_labelSelector = NULL;
    }
    if(valueQuery_labelSelector){
        free(valueQuery_labelSelector);
        valueQuery_labelSelector = NULL;
    }
    if(keyPairQuery_labelSelector){
        keyValuePair_free(keyPairQuery_labelSelector);
        keyPairQuery_labelSelector = NULL;
    }
    if(keyQuery_limit){
        free(keyQuery_limit);
        keyQuery_limit = NULL;
    }
    if(valueQuery_limit){
        free(valueQuery_limit);
        valueQuery_limit = NULL;
    }
    if(keyPairQuery_limit){
        keyValuePair_free(keyPairQuery_limit);
        keyPairQuery_limit = NULL;
    }
    if(keyQuery_resourceVersion){
        free(keyQuery_resourceVersion);
        keyQuery_resourceVersion = NULL;
    }
    if(valueQuery_resourceVersion){
        free(valueQuery_resourceVersion);
        valueQuery_resourceVersion = NULL;
    }
    if(keyPairQuery_resourceVersion){
        keyValuePair_free(keyPairQuery_resourceVersion);
        keyPairQuery_resourceVersion = NULL;
    }
    if(keyQuery_timeoutSeconds){
        free(keyQuery_timeoutSeconds);
        keyQuery_timeoutSeconds = NULL;
    }
    if(valueQuery_timeoutSeconds){
        free(valueQuery_timeoutSeconds);
        valueQuery_timeoutSeconds = NULL;
    }
    if(keyPairQuery_timeoutSeconds){
        keyValuePair_free(keyPairQuery_timeoutSeconds);
        keyPairQuery_timeoutSeconds = NULL;
    }
    if(keyQuery_watch){
        free(keyQuery_watch);
        keyQuery_watch = NULL;
    }
    if(valueQuery_watch){
        free(valueQuery_watch);
        valueQuery_watch = NULL;
    }
    if(keyPairQuery_watch){
        keyValuePair_free(keyPairQuery_watch);
        keyPairQuery_watch = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// list or watch objects of kind ReplicaSet
//
v1_replica_set_list_t*
AppsV1API_listNamespacedReplicaSet(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/replicasets")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/replicasets");


    // Path Params
    long sizeOfPathParams__namespace = strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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

    // query parameters
    char *keyQuery_allowWatchBookmarks = NULL;
    char * valueQuery_allowWatchBookmarks = NULL;
    keyValuePair_t *keyPairQuery_allowWatchBookmarks = 0;
    if (allowWatchBookmarks)
    {
        keyQuery_allowWatchBookmarks = strdup("allowWatchBookmarks");
        valueQuery_allowWatchBookmarks = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_allowWatchBookmarks, MAX_NUMBER_LENGTH, "%d", allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = keyValuePair_create(keyQuery_allowWatchBookmarks, valueQuery_allowWatchBookmarks);
        list_addElement(localVarQueryParameters,keyPairQuery_allowWatchBookmarks);
    }

    // query parameters
    char *keyQuery__continue = NULL;
    char * valueQuery__continue = NULL;
    keyValuePair_t *keyPairQuery__continue = 0;
    if (_continue)
    {
        keyQuery__continue = strdup("continue");
        valueQuery__continue = strdup((_continue));
        keyPairQuery__continue = keyValuePair_create(keyQuery__continue, valueQuery__continue);
        list_addElement(localVarQueryParameters,keyPairQuery__continue);
    }

    // query parameters
    char *keyQuery_fieldSelector = NULL;
    char * valueQuery_fieldSelector = NULL;
    keyValuePair_t *keyPairQuery_fieldSelector = 0;
    if (fieldSelector)
    {
        keyQuery_fieldSelector = strdup("fieldSelector");
        valueQuery_fieldSelector = strdup((fieldSelector));
        keyPairQuery_fieldSelector = keyValuePair_create(keyQuery_fieldSelector, valueQuery_fieldSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldSelector);
    }

    // query parameters
    char *keyQuery_labelSelector = NULL;
    char * valueQuery_labelSelector = NULL;
    keyValuePair_t *keyPairQuery_labelSelector = 0;
    if (labelSelector)
    {
        keyQuery_labelSelector = strdup("labelSelector");
        valueQuery_labelSelector = strdup((labelSelector));
        keyPairQuery_labelSelector = keyValuePair_create(keyQuery_labelSelector, valueQuery_labelSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_labelSelector);
    }

    // query parameters
    char *keyQuery_limit = NULL;
    char * valueQuery_limit = NULL;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_limit, MAX_NUMBER_LENGTH, "%d", limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, valueQuery_limit);
        list_addElement(localVarQueryParameters,keyPairQuery_limit);
    }

    // query parameters
    char *keyQuery_resourceVersion = NULL;
    char * valueQuery_resourceVersion = NULL;
    keyValuePair_t *keyPairQuery_resourceVersion = 0;
    if (resourceVersion)
    {
        keyQuery_resourceVersion = strdup("resourceVersion");
        valueQuery_resourceVersion = strdup((resourceVersion));
        keyPairQuery_resourceVersion = keyValuePair_create(keyQuery_resourceVersion, valueQuery_resourceVersion);
        list_addElement(localVarQueryParameters,keyPairQuery_resourceVersion);
    }

    // query parameters
    char *keyQuery_timeoutSeconds = NULL;
    char * valueQuery_timeoutSeconds = NULL;
    keyValuePair_t *keyPairQuery_timeoutSeconds = 0;
    if (timeoutSeconds)
    {
        keyQuery_timeoutSeconds = strdup("timeoutSeconds");
        valueQuery_timeoutSeconds = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_timeoutSeconds, MAX_NUMBER_LENGTH, "%d", timeoutSeconds);
        keyPairQuery_timeoutSeconds = keyValuePair_create(keyQuery_timeoutSeconds, valueQuery_timeoutSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_timeoutSeconds);
    }

    // query parameters
    char *keyQuery_watch = NULL;
    char * valueQuery_watch = NULL;
    keyValuePair_t *keyPairQuery_watch = 0;
    if (watch)
    {
        keyQuery_watch = strdup("watch");
        valueQuery_watch = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_watch, MAX_NUMBER_LENGTH, "%d", watch);
        keyPairQuery_watch = keyValuePair_create(keyQuery_watch, valueQuery_watch);
        list_addElement(localVarQueryParameters,keyPairQuery_watch);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarHeaderType,"application/json;stream=watch"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf;stream=watch"); //produces
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
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_replica_set_list_t *elementToReturn = v1_replica_set_list_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    free(localVarToReplace__namespace);
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
    if(keyQuery_allowWatchBookmarks){
        free(keyQuery_allowWatchBookmarks);
        keyQuery_allowWatchBookmarks = NULL;
    }
    if(valueQuery_allowWatchBookmarks){
        free(valueQuery_allowWatchBookmarks);
        valueQuery_allowWatchBookmarks = NULL;
    }
    if(keyPairQuery_allowWatchBookmarks){
        keyValuePair_free(keyPairQuery_allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = NULL;
    }
    if(keyQuery__continue){
        free(keyQuery__continue);
        keyQuery__continue = NULL;
    }
    if(valueQuery__continue){
        free(valueQuery__continue);
        valueQuery__continue = NULL;
    }
    if(keyPairQuery__continue){
        keyValuePair_free(keyPairQuery__continue);
        keyPairQuery__continue = NULL;
    }
    if(keyQuery_fieldSelector){
        free(keyQuery_fieldSelector);
        keyQuery_fieldSelector = NULL;
    }
    if(valueQuery_fieldSelector){
        free(valueQuery_fieldSelector);
        valueQuery_fieldSelector = NULL;
    }
    if(keyPairQuery_fieldSelector){
        keyValuePair_free(keyPairQuery_fieldSelector);
        keyPairQuery_fieldSelector = NULL;
    }
    if(keyQuery_labelSelector){
        free(keyQuery_labelSelector);
        keyQuery_labelSelector = NULL;
    }
    if(valueQuery_labelSelector){
        free(valueQuery_labelSelector);
        valueQuery_labelSelector = NULL;
    }
    if(keyPairQuery_labelSelector){
        keyValuePair_free(keyPairQuery_labelSelector);
        keyPairQuery_labelSelector = NULL;
    }
    if(keyQuery_limit){
        free(keyQuery_limit);
        keyQuery_limit = NULL;
    }
    if(valueQuery_limit){
        free(valueQuery_limit);
        valueQuery_limit = NULL;
    }
    if(keyPairQuery_limit){
        keyValuePair_free(keyPairQuery_limit);
        keyPairQuery_limit = NULL;
    }
    if(keyQuery_resourceVersion){
        free(keyQuery_resourceVersion);
        keyQuery_resourceVersion = NULL;
    }
    if(valueQuery_resourceVersion){
        free(valueQuery_resourceVersion);
        valueQuery_resourceVersion = NULL;
    }
    if(keyPairQuery_resourceVersion){
        keyValuePair_free(keyPairQuery_resourceVersion);
        keyPairQuery_resourceVersion = NULL;
    }
    if(keyQuery_timeoutSeconds){
        free(keyQuery_timeoutSeconds);
        keyQuery_timeoutSeconds = NULL;
    }
    if(valueQuery_timeoutSeconds){
        free(valueQuery_timeoutSeconds);
        valueQuery_timeoutSeconds = NULL;
    }
    if(keyPairQuery_timeoutSeconds){
        keyValuePair_free(keyPairQuery_timeoutSeconds);
        keyPairQuery_timeoutSeconds = NULL;
    }
    if(keyQuery_watch){
        free(keyQuery_watch);
        keyQuery_watch = NULL;
    }
    if(valueQuery_watch){
        free(valueQuery_watch);
        valueQuery_watch = NULL;
    }
    if(keyPairQuery_watch){
        keyValuePair_free(keyPairQuery_watch);
        keyPairQuery_watch = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// list or watch objects of kind StatefulSet
//
v1_stateful_set_list_t*
AppsV1API_listNamespacedStatefulSet(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/statefulsets")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/statefulsets");


    // Path Params
    long sizeOfPathParams__namespace = strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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

    // query parameters
    char *keyQuery_allowWatchBookmarks = NULL;
    char * valueQuery_allowWatchBookmarks = NULL;
    keyValuePair_t *keyPairQuery_allowWatchBookmarks = 0;
    if (allowWatchBookmarks)
    {
        keyQuery_allowWatchBookmarks = strdup("allowWatchBookmarks");
        valueQuery_allowWatchBookmarks = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_allowWatchBookmarks, MAX_NUMBER_LENGTH, "%d", allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = keyValuePair_create(keyQuery_allowWatchBookmarks, valueQuery_allowWatchBookmarks);
        list_addElement(localVarQueryParameters,keyPairQuery_allowWatchBookmarks);
    }

    // query parameters
    char *keyQuery__continue = NULL;
    char * valueQuery__continue = NULL;
    keyValuePair_t *keyPairQuery__continue = 0;
    if (_continue)
    {
        keyQuery__continue = strdup("continue");
        valueQuery__continue = strdup((_continue));
        keyPairQuery__continue = keyValuePair_create(keyQuery__continue, valueQuery__continue);
        list_addElement(localVarQueryParameters,keyPairQuery__continue);
    }

    // query parameters
    char *keyQuery_fieldSelector = NULL;
    char * valueQuery_fieldSelector = NULL;
    keyValuePair_t *keyPairQuery_fieldSelector = 0;
    if (fieldSelector)
    {
        keyQuery_fieldSelector = strdup("fieldSelector");
        valueQuery_fieldSelector = strdup((fieldSelector));
        keyPairQuery_fieldSelector = keyValuePair_create(keyQuery_fieldSelector, valueQuery_fieldSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldSelector);
    }

    // query parameters
    char *keyQuery_labelSelector = NULL;
    char * valueQuery_labelSelector = NULL;
    keyValuePair_t *keyPairQuery_labelSelector = 0;
    if (labelSelector)
    {
        keyQuery_labelSelector = strdup("labelSelector");
        valueQuery_labelSelector = strdup((labelSelector));
        keyPairQuery_labelSelector = keyValuePair_create(keyQuery_labelSelector, valueQuery_labelSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_labelSelector);
    }

    // query parameters
    char *keyQuery_limit = NULL;
    char * valueQuery_limit = NULL;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_limit, MAX_NUMBER_LENGTH, "%d", limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, valueQuery_limit);
        list_addElement(localVarQueryParameters,keyPairQuery_limit);
    }

    // query parameters
    char *keyQuery_resourceVersion = NULL;
    char * valueQuery_resourceVersion = NULL;
    keyValuePair_t *keyPairQuery_resourceVersion = 0;
    if (resourceVersion)
    {
        keyQuery_resourceVersion = strdup("resourceVersion");
        valueQuery_resourceVersion = strdup((resourceVersion));
        keyPairQuery_resourceVersion = keyValuePair_create(keyQuery_resourceVersion, valueQuery_resourceVersion);
        list_addElement(localVarQueryParameters,keyPairQuery_resourceVersion);
    }

    // query parameters
    char *keyQuery_timeoutSeconds = NULL;
    char * valueQuery_timeoutSeconds = NULL;
    keyValuePair_t *keyPairQuery_timeoutSeconds = 0;
    if (timeoutSeconds)
    {
        keyQuery_timeoutSeconds = strdup("timeoutSeconds");
        valueQuery_timeoutSeconds = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_timeoutSeconds, MAX_NUMBER_LENGTH, "%d", timeoutSeconds);
        keyPairQuery_timeoutSeconds = keyValuePair_create(keyQuery_timeoutSeconds, valueQuery_timeoutSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_timeoutSeconds);
    }

    // query parameters
    char *keyQuery_watch = NULL;
    char * valueQuery_watch = NULL;
    keyValuePair_t *keyPairQuery_watch = 0;
    if (watch)
    {
        keyQuery_watch = strdup("watch");
        valueQuery_watch = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_watch, MAX_NUMBER_LENGTH, "%d", watch);
        keyPairQuery_watch = keyValuePair_create(keyQuery_watch, valueQuery_watch);
        list_addElement(localVarQueryParameters,keyPairQuery_watch);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarHeaderType,"application/json;stream=watch"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf;stream=watch"); //produces
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
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_stateful_set_list_t *elementToReturn = v1_stateful_set_list_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    free(localVarToReplace__namespace);
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
    if(keyQuery_allowWatchBookmarks){
        free(keyQuery_allowWatchBookmarks);
        keyQuery_allowWatchBookmarks = NULL;
    }
    if(valueQuery_allowWatchBookmarks){
        free(valueQuery_allowWatchBookmarks);
        valueQuery_allowWatchBookmarks = NULL;
    }
    if(keyPairQuery_allowWatchBookmarks){
        keyValuePair_free(keyPairQuery_allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = NULL;
    }
    if(keyQuery__continue){
        free(keyQuery__continue);
        keyQuery__continue = NULL;
    }
    if(valueQuery__continue){
        free(valueQuery__continue);
        valueQuery__continue = NULL;
    }
    if(keyPairQuery__continue){
        keyValuePair_free(keyPairQuery__continue);
        keyPairQuery__continue = NULL;
    }
    if(keyQuery_fieldSelector){
        free(keyQuery_fieldSelector);
        keyQuery_fieldSelector = NULL;
    }
    if(valueQuery_fieldSelector){
        free(valueQuery_fieldSelector);
        valueQuery_fieldSelector = NULL;
    }
    if(keyPairQuery_fieldSelector){
        keyValuePair_free(keyPairQuery_fieldSelector);
        keyPairQuery_fieldSelector = NULL;
    }
    if(keyQuery_labelSelector){
        free(keyQuery_labelSelector);
        keyQuery_labelSelector = NULL;
    }
    if(valueQuery_labelSelector){
        free(valueQuery_labelSelector);
        valueQuery_labelSelector = NULL;
    }
    if(keyPairQuery_labelSelector){
        keyValuePair_free(keyPairQuery_labelSelector);
        keyPairQuery_labelSelector = NULL;
    }
    if(keyQuery_limit){
        free(keyQuery_limit);
        keyQuery_limit = NULL;
    }
    if(valueQuery_limit){
        free(valueQuery_limit);
        valueQuery_limit = NULL;
    }
    if(keyPairQuery_limit){
        keyValuePair_free(keyPairQuery_limit);
        keyPairQuery_limit = NULL;
    }
    if(keyQuery_resourceVersion){
        free(keyQuery_resourceVersion);
        keyQuery_resourceVersion = NULL;
    }
    if(valueQuery_resourceVersion){
        free(valueQuery_resourceVersion);
        valueQuery_resourceVersion = NULL;
    }
    if(keyPairQuery_resourceVersion){
        keyValuePair_free(keyPairQuery_resourceVersion);
        keyPairQuery_resourceVersion = NULL;
    }
    if(keyQuery_timeoutSeconds){
        free(keyQuery_timeoutSeconds);
        keyQuery_timeoutSeconds = NULL;
    }
    if(valueQuery_timeoutSeconds){
        free(valueQuery_timeoutSeconds);
        valueQuery_timeoutSeconds = NULL;
    }
    if(keyPairQuery_timeoutSeconds){
        keyValuePair_free(keyPairQuery_timeoutSeconds);
        keyPairQuery_timeoutSeconds = NULL;
    }
    if(keyQuery_watch){
        free(keyQuery_watch);
        keyQuery_watch = NULL;
    }
    if(valueQuery_watch){
        free(valueQuery_watch);
        valueQuery_watch = NULL;
    }
    if(keyPairQuery_watch){
        keyValuePair_free(keyPairQuery_watch);
        keyPairQuery_watch = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// list or watch objects of kind ReplicaSet
//
v1_replica_set_list_t*
AppsV1API_listReplicaSetForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , int timeoutSeconds , int watch )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/replicasets")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/replicasets");




    // query parameters
    char *keyQuery_allowWatchBookmarks = NULL;
    char * valueQuery_allowWatchBookmarks = NULL;
    keyValuePair_t *keyPairQuery_allowWatchBookmarks = 0;
    if (allowWatchBookmarks)
    {
        keyQuery_allowWatchBookmarks = strdup("allowWatchBookmarks");
        valueQuery_allowWatchBookmarks = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_allowWatchBookmarks, MAX_NUMBER_LENGTH, "%d", allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = keyValuePair_create(keyQuery_allowWatchBookmarks, valueQuery_allowWatchBookmarks);
        list_addElement(localVarQueryParameters,keyPairQuery_allowWatchBookmarks);
    }

    // query parameters
    char *keyQuery__continue = NULL;
    char * valueQuery__continue = NULL;
    keyValuePair_t *keyPairQuery__continue = 0;
    if (_continue)
    {
        keyQuery__continue = strdup("continue");
        valueQuery__continue = strdup((_continue));
        keyPairQuery__continue = keyValuePair_create(keyQuery__continue, valueQuery__continue);
        list_addElement(localVarQueryParameters,keyPairQuery__continue);
    }

    // query parameters
    char *keyQuery_fieldSelector = NULL;
    char * valueQuery_fieldSelector = NULL;
    keyValuePair_t *keyPairQuery_fieldSelector = 0;
    if (fieldSelector)
    {
        keyQuery_fieldSelector = strdup("fieldSelector");
        valueQuery_fieldSelector = strdup((fieldSelector));
        keyPairQuery_fieldSelector = keyValuePair_create(keyQuery_fieldSelector, valueQuery_fieldSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldSelector);
    }

    // query parameters
    char *keyQuery_labelSelector = NULL;
    char * valueQuery_labelSelector = NULL;
    keyValuePair_t *keyPairQuery_labelSelector = 0;
    if (labelSelector)
    {
        keyQuery_labelSelector = strdup("labelSelector");
        valueQuery_labelSelector = strdup((labelSelector));
        keyPairQuery_labelSelector = keyValuePair_create(keyQuery_labelSelector, valueQuery_labelSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_labelSelector);
    }

    // query parameters
    char *keyQuery_limit = NULL;
    char * valueQuery_limit = NULL;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_limit, MAX_NUMBER_LENGTH, "%d", limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, valueQuery_limit);
        list_addElement(localVarQueryParameters,keyPairQuery_limit);
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

    // query parameters
    char *keyQuery_resourceVersion = NULL;
    char * valueQuery_resourceVersion = NULL;
    keyValuePair_t *keyPairQuery_resourceVersion = 0;
    if (resourceVersion)
    {
        keyQuery_resourceVersion = strdup("resourceVersion");
        valueQuery_resourceVersion = strdup((resourceVersion));
        keyPairQuery_resourceVersion = keyValuePair_create(keyQuery_resourceVersion, valueQuery_resourceVersion);
        list_addElement(localVarQueryParameters,keyPairQuery_resourceVersion);
    }

    // query parameters
    char *keyQuery_timeoutSeconds = NULL;
    char * valueQuery_timeoutSeconds = NULL;
    keyValuePair_t *keyPairQuery_timeoutSeconds = 0;
    if (timeoutSeconds)
    {
        keyQuery_timeoutSeconds = strdup("timeoutSeconds");
        valueQuery_timeoutSeconds = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_timeoutSeconds, MAX_NUMBER_LENGTH, "%d", timeoutSeconds);
        keyPairQuery_timeoutSeconds = keyValuePair_create(keyQuery_timeoutSeconds, valueQuery_timeoutSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_timeoutSeconds);
    }

    // query parameters
    char *keyQuery_watch = NULL;
    char * valueQuery_watch = NULL;
    keyValuePair_t *keyPairQuery_watch = 0;
    if (watch)
    {
        keyQuery_watch = strdup("watch");
        valueQuery_watch = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_watch, MAX_NUMBER_LENGTH, "%d", watch);
        keyPairQuery_watch = keyValuePair_create(keyQuery_watch, valueQuery_watch);
        list_addElement(localVarQueryParameters,keyPairQuery_watch);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarHeaderType,"application/json;stream=watch"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf;stream=watch"); //produces
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
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_replica_set_list_t *elementToReturn = v1_replica_set_list_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    if(keyQuery_allowWatchBookmarks){
        free(keyQuery_allowWatchBookmarks);
        keyQuery_allowWatchBookmarks = NULL;
    }
    if(valueQuery_allowWatchBookmarks){
        free(valueQuery_allowWatchBookmarks);
        valueQuery_allowWatchBookmarks = NULL;
    }
    if(keyPairQuery_allowWatchBookmarks){
        keyValuePair_free(keyPairQuery_allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = NULL;
    }
    if(keyQuery__continue){
        free(keyQuery__continue);
        keyQuery__continue = NULL;
    }
    if(valueQuery__continue){
        free(valueQuery__continue);
        valueQuery__continue = NULL;
    }
    if(keyPairQuery__continue){
        keyValuePair_free(keyPairQuery__continue);
        keyPairQuery__continue = NULL;
    }
    if(keyQuery_fieldSelector){
        free(keyQuery_fieldSelector);
        keyQuery_fieldSelector = NULL;
    }
    if(valueQuery_fieldSelector){
        free(valueQuery_fieldSelector);
        valueQuery_fieldSelector = NULL;
    }
    if(keyPairQuery_fieldSelector){
        keyValuePair_free(keyPairQuery_fieldSelector);
        keyPairQuery_fieldSelector = NULL;
    }
    if(keyQuery_labelSelector){
        free(keyQuery_labelSelector);
        keyQuery_labelSelector = NULL;
    }
    if(valueQuery_labelSelector){
        free(valueQuery_labelSelector);
        valueQuery_labelSelector = NULL;
    }
    if(keyPairQuery_labelSelector){
        keyValuePair_free(keyPairQuery_labelSelector);
        keyPairQuery_labelSelector = NULL;
    }
    if(keyQuery_limit){
        free(keyQuery_limit);
        keyQuery_limit = NULL;
    }
    if(valueQuery_limit){
        free(valueQuery_limit);
        valueQuery_limit = NULL;
    }
    if(keyPairQuery_limit){
        keyValuePair_free(keyPairQuery_limit);
        keyPairQuery_limit = NULL;
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
    if(keyQuery_resourceVersion){
        free(keyQuery_resourceVersion);
        keyQuery_resourceVersion = NULL;
    }
    if(valueQuery_resourceVersion){
        free(valueQuery_resourceVersion);
        valueQuery_resourceVersion = NULL;
    }
    if(keyPairQuery_resourceVersion){
        keyValuePair_free(keyPairQuery_resourceVersion);
        keyPairQuery_resourceVersion = NULL;
    }
    if(keyQuery_timeoutSeconds){
        free(keyQuery_timeoutSeconds);
        keyQuery_timeoutSeconds = NULL;
    }
    if(valueQuery_timeoutSeconds){
        free(valueQuery_timeoutSeconds);
        valueQuery_timeoutSeconds = NULL;
    }
    if(keyPairQuery_timeoutSeconds){
        keyValuePair_free(keyPairQuery_timeoutSeconds);
        keyPairQuery_timeoutSeconds = NULL;
    }
    if(keyQuery_watch){
        free(keyQuery_watch);
        keyQuery_watch = NULL;
    }
    if(valueQuery_watch){
        free(valueQuery_watch);
        valueQuery_watch = NULL;
    }
    if(keyPairQuery_watch){
        keyValuePair_free(keyPairQuery_watch);
        keyPairQuery_watch = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// list or watch objects of kind StatefulSet
//
v1_stateful_set_list_t*
AppsV1API_listStatefulSetForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , int timeoutSeconds , int watch )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/statefulsets")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/statefulsets");




    // query parameters
    char *keyQuery_allowWatchBookmarks = NULL;
    char * valueQuery_allowWatchBookmarks = NULL;
    keyValuePair_t *keyPairQuery_allowWatchBookmarks = 0;
    if (allowWatchBookmarks)
    {
        keyQuery_allowWatchBookmarks = strdup("allowWatchBookmarks");
        valueQuery_allowWatchBookmarks = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_allowWatchBookmarks, MAX_NUMBER_LENGTH, "%d", allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = keyValuePair_create(keyQuery_allowWatchBookmarks, valueQuery_allowWatchBookmarks);
        list_addElement(localVarQueryParameters,keyPairQuery_allowWatchBookmarks);
    }

    // query parameters
    char *keyQuery__continue = NULL;
    char * valueQuery__continue = NULL;
    keyValuePair_t *keyPairQuery__continue = 0;
    if (_continue)
    {
        keyQuery__continue = strdup("continue");
        valueQuery__continue = strdup((_continue));
        keyPairQuery__continue = keyValuePair_create(keyQuery__continue, valueQuery__continue);
        list_addElement(localVarQueryParameters,keyPairQuery__continue);
    }

    // query parameters
    char *keyQuery_fieldSelector = NULL;
    char * valueQuery_fieldSelector = NULL;
    keyValuePair_t *keyPairQuery_fieldSelector = 0;
    if (fieldSelector)
    {
        keyQuery_fieldSelector = strdup("fieldSelector");
        valueQuery_fieldSelector = strdup((fieldSelector));
        keyPairQuery_fieldSelector = keyValuePair_create(keyQuery_fieldSelector, valueQuery_fieldSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_fieldSelector);
    }

    // query parameters
    char *keyQuery_labelSelector = NULL;
    char * valueQuery_labelSelector = NULL;
    keyValuePair_t *keyPairQuery_labelSelector = 0;
    if (labelSelector)
    {
        keyQuery_labelSelector = strdup("labelSelector");
        valueQuery_labelSelector = strdup((labelSelector));
        keyPairQuery_labelSelector = keyValuePair_create(keyQuery_labelSelector, valueQuery_labelSelector);
        list_addElement(localVarQueryParameters,keyPairQuery_labelSelector);
    }

    // query parameters
    char *keyQuery_limit = NULL;
    char * valueQuery_limit = NULL;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_limit, MAX_NUMBER_LENGTH, "%d", limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, valueQuery_limit);
        list_addElement(localVarQueryParameters,keyPairQuery_limit);
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

    // query parameters
    char *keyQuery_resourceVersion = NULL;
    char * valueQuery_resourceVersion = NULL;
    keyValuePair_t *keyPairQuery_resourceVersion = 0;
    if (resourceVersion)
    {
        keyQuery_resourceVersion = strdup("resourceVersion");
        valueQuery_resourceVersion = strdup((resourceVersion));
        keyPairQuery_resourceVersion = keyValuePair_create(keyQuery_resourceVersion, valueQuery_resourceVersion);
        list_addElement(localVarQueryParameters,keyPairQuery_resourceVersion);
    }

    // query parameters
    char *keyQuery_timeoutSeconds = NULL;
    char * valueQuery_timeoutSeconds = NULL;
    keyValuePair_t *keyPairQuery_timeoutSeconds = 0;
    if (timeoutSeconds)
    {
        keyQuery_timeoutSeconds = strdup("timeoutSeconds");
        valueQuery_timeoutSeconds = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_timeoutSeconds, MAX_NUMBER_LENGTH, "%d", timeoutSeconds);
        keyPairQuery_timeoutSeconds = keyValuePair_create(keyQuery_timeoutSeconds, valueQuery_timeoutSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_timeoutSeconds);
    }

    // query parameters
    char *keyQuery_watch = NULL;
    char * valueQuery_watch = NULL;
    keyValuePair_t *keyPairQuery_watch = 0;
    if (watch)
    {
        keyQuery_watch = strdup("watch");
        valueQuery_watch = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_watch, MAX_NUMBER_LENGTH, "%d", watch);
        keyPairQuery_watch = keyValuePair_create(keyQuery_watch, valueQuery_watch);
        list_addElement(localVarQueryParameters,keyPairQuery_watch);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarHeaderType,"application/json;stream=watch"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf;stream=watch"); //produces
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
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_stateful_set_list_t *elementToReturn = v1_stateful_set_list_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    if(keyQuery_allowWatchBookmarks){
        free(keyQuery_allowWatchBookmarks);
        keyQuery_allowWatchBookmarks = NULL;
    }
    if(valueQuery_allowWatchBookmarks){
        free(valueQuery_allowWatchBookmarks);
        valueQuery_allowWatchBookmarks = NULL;
    }
    if(keyPairQuery_allowWatchBookmarks){
        keyValuePair_free(keyPairQuery_allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = NULL;
    }
    if(keyQuery__continue){
        free(keyQuery__continue);
        keyQuery__continue = NULL;
    }
    if(valueQuery__continue){
        free(valueQuery__continue);
        valueQuery__continue = NULL;
    }
    if(keyPairQuery__continue){
        keyValuePair_free(keyPairQuery__continue);
        keyPairQuery__continue = NULL;
    }
    if(keyQuery_fieldSelector){
        free(keyQuery_fieldSelector);
        keyQuery_fieldSelector = NULL;
    }
    if(valueQuery_fieldSelector){
        free(valueQuery_fieldSelector);
        valueQuery_fieldSelector = NULL;
    }
    if(keyPairQuery_fieldSelector){
        keyValuePair_free(keyPairQuery_fieldSelector);
        keyPairQuery_fieldSelector = NULL;
    }
    if(keyQuery_labelSelector){
        free(keyQuery_labelSelector);
        keyQuery_labelSelector = NULL;
    }
    if(valueQuery_labelSelector){
        free(valueQuery_labelSelector);
        valueQuery_labelSelector = NULL;
    }
    if(keyPairQuery_labelSelector){
        keyValuePair_free(keyPairQuery_labelSelector);
        keyPairQuery_labelSelector = NULL;
    }
    if(keyQuery_limit){
        free(keyQuery_limit);
        keyQuery_limit = NULL;
    }
    if(valueQuery_limit){
        free(valueQuery_limit);
        valueQuery_limit = NULL;
    }
    if(keyPairQuery_limit){
        keyValuePair_free(keyPairQuery_limit);
        keyPairQuery_limit = NULL;
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
    if(keyQuery_resourceVersion){
        free(keyQuery_resourceVersion);
        keyQuery_resourceVersion = NULL;
    }
    if(valueQuery_resourceVersion){
        free(valueQuery_resourceVersion);
        valueQuery_resourceVersion = NULL;
    }
    if(keyPairQuery_resourceVersion){
        keyValuePair_free(keyPairQuery_resourceVersion);
        keyPairQuery_resourceVersion = NULL;
    }
    if(keyQuery_timeoutSeconds){
        free(keyQuery_timeoutSeconds);
        keyQuery_timeoutSeconds = NULL;
    }
    if(valueQuery_timeoutSeconds){
        free(valueQuery_timeoutSeconds);
        valueQuery_timeoutSeconds = NULL;
    }
    if(keyPairQuery_timeoutSeconds){
        keyValuePair_free(keyPairQuery_timeoutSeconds);
        keyPairQuery_timeoutSeconds = NULL;
    }
    if(keyQuery_watch){
        free(keyQuery_watch);
        keyQuery_watch = NULL;
    }
    if(valueQuery_watch){
        free(valueQuery_watch);
        valueQuery_watch = NULL;
    }
    if(keyPairQuery_watch){
        keyValuePair_free(keyPairQuery_watch);
        keyPairQuery_watch = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// partially update the specified ControllerRevision
//
v1_controller_revision_t*
AppsV1API_patchNamespacedControllerRevision(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/controllerrevisions/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/controllerrevisions/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams__namespace = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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
    char *keyQuery_force = NULL;
    char * valueQuery_force = NULL;
    keyValuePair_t *keyPairQuery_force = 0;
    if (force)
    {
        keyQuery_force = strdup("force");
        valueQuery_force = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_force, MAX_NUMBER_LENGTH, "%d", force);
        keyPairQuery_force = keyValuePair_create(keyQuery_force, valueQuery_force);
        list_addElement(localVarQueryParameters,keyPairQuery_force);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = object_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarContentType,"application/json-patch+json"); //consumes
    list_addElement(localVarContentType,"application/merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/strategic-merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/apply-patch+yaml"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "PATCH");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_controller_revision_t *elementToReturn = v1_controller_revision_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    list_free(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace__namespace);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
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
    if(keyQuery_force){
        free(keyQuery_force);
        keyQuery_force = NULL;
    }
    if(valueQuery_force){
        free(valueQuery_force);
        valueQuery_force = NULL;
    }
    if(keyPairQuery_force){
        keyValuePair_free(keyPairQuery_force);
        keyPairQuery_force = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// partially update the specified DaemonSet
//
v1_daemon_set_t*
AppsV1API_patchNamespacedDaemonSet(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/daemonsets/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/daemonsets/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams__namespace = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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
    char *keyQuery_force = NULL;
    char * valueQuery_force = NULL;
    keyValuePair_t *keyPairQuery_force = 0;
    if (force)
    {
        keyQuery_force = strdup("force");
        valueQuery_force = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_force, MAX_NUMBER_LENGTH, "%d", force);
        keyPairQuery_force = keyValuePair_create(keyQuery_force, valueQuery_force);
        list_addElement(localVarQueryParameters,keyPairQuery_force);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = object_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarContentType,"application/json-patch+json"); //consumes
    list_addElement(localVarContentType,"application/merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/strategic-merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/apply-patch+yaml"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "PATCH");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_daemon_set_t *elementToReturn = v1_daemon_set_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    list_free(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace__namespace);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
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
    if(keyQuery_force){
        free(keyQuery_force);
        keyQuery_force = NULL;
    }
    if(valueQuery_force){
        free(valueQuery_force);
        valueQuery_force = NULL;
    }
    if(keyPairQuery_force){
        keyValuePair_free(keyPairQuery_force);
        keyPairQuery_force = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// partially update status of the specified DaemonSet
//
v1_daemon_set_t*
AppsV1API_patchNamespacedDaemonSetStatus(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/daemonsets/{name}/status")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/daemonsets/{name}/status");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams__namespace = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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
    char *keyQuery_force = NULL;
    char * valueQuery_force = NULL;
    keyValuePair_t *keyPairQuery_force = 0;
    if (force)
    {
        keyQuery_force = strdup("force");
        valueQuery_force = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_force, MAX_NUMBER_LENGTH, "%d", force);
        keyPairQuery_force = keyValuePair_create(keyQuery_force, valueQuery_force);
        list_addElement(localVarQueryParameters,keyPairQuery_force);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = object_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarContentType,"application/json-patch+json"); //consumes
    list_addElement(localVarContentType,"application/merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/strategic-merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/apply-patch+yaml"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "PATCH");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_daemon_set_t *elementToReturn = v1_daemon_set_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    list_free(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace__namespace);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
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
    if(keyQuery_force){
        free(keyQuery_force);
        keyQuery_force = NULL;
    }
    if(valueQuery_force){
        free(valueQuery_force);
        valueQuery_force = NULL;
    }
    if(keyPairQuery_force){
        keyValuePair_free(keyPairQuery_force);
        keyPairQuery_force = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// partially update the specified Deployment
//
v1_deployment_t*
AppsV1API_patchNamespacedDeployment(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/deployments/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/deployments/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams__namespace = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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
    char *keyQuery_force = NULL;
    char * valueQuery_force = NULL;
    keyValuePair_t *keyPairQuery_force = 0;
    if (force)
    {
        keyQuery_force = strdup("force");
        valueQuery_force = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_force, MAX_NUMBER_LENGTH, "%d", force);
        keyPairQuery_force = keyValuePair_create(keyQuery_force, valueQuery_force);
        list_addElement(localVarQueryParameters,keyPairQuery_force);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = object_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarContentType,"application/json-patch+json"); //consumes
    list_addElement(localVarContentType,"application/merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/strategic-merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/apply-patch+yaml"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "PATCH");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_deployment_t *elementToReturn = v1_deployment_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    list_free(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace__namespace);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
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
    if(keyQuery_force){
        free(keyQuery_force);
        keyQuery_force = NULL;
    }
    if(valueQuery_force){
        free(valueQuery_force);
        valueQuery_force = NULL;
    }
    if(keyPairQuery_force){
        keyValuePair_free(keyPairQuery_force);
        keyPairQuery_force = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// partially update scale of the specified Deployment
//
v1_scale_t*
AppsV1API_patchNamespacedDeploymentScale(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/deployments/{name}/scale")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/deployments/{name}/scale");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams__namespace = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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
    char *keyQuery_force = NULL;
    char * valueQuery_force = NULL;
    keyValuePair_t *keyPairQuery_force = 0;
    if (force)
    {
        keyQuery_force = strdup("force");
        valueQuery_force = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_force, MAX_NUMBER_LENGTH, "%d", force);
        keyPairQuery_force = keyValuePair_create(keyQuery_force, valueQuery_force);
        list_addElement(localVarQueryParameters,keyPairQuery_force);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = object_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarContentType,"application/json-patch+json"); //consumes
    list_addElement(localVarContentType,"application/merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/strategic-merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/apply-patch+yaml"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "PATCH");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_scale_t *elementToReturn = v1_scale_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    list_free(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace__namespace);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
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
    if(keyQuery_force){
        free(keyQuery_force);
        keyQuery_force = NULL;
    }
    if(valueQuery_force){
        free(valueQuery_force);
        valueQuery_force = NULL;
    }
    if(keyPairQuery_force){
        keyValuePair_free(keyPairQuery_force);
        keyPairQuery_force = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// partially update status of the specified Deployment
//
v1_deployment_t*
AppsV1API_patchNamespacedDeploymentStatus(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/deployments/{name}/status")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/deployments/{name}/status");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams__namespace = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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
    char *keyQuery_force = NULL;
    char * valueQuery_force = NULL;
    keyValuePair_t *keyPairQuery_force = 0;
    if (force)
    {
        keyQuery_force = strdup("force");
        valueQuery_force = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_force, MAX_NUMBER_LENGTH, "%d", force);
        keyPairQuery_force = keyValuePair_create(keyQuery_force, valueQuery_force);
        list_addElement(localVarQueryParameters,keyPairQuery_force);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = object_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarContentType,"application/json-patch+json"); //consumes
    list_addElement(localVarContentType,"application/merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/strategic-merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/apply-patch+yaml"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "PATCH");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_deployment_t *elementToReturn = v1_deployment_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    list_free(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace__namespace);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
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
    if(keyQuery_force){
        free(keyQuery_force);
        keyQuery_force = NULL;
    }
    if(valueQuery_force){
        free(valueQuery_force);
        valueQuery_force = NULL;
    }
    if(keyPairQuery_force){
        keyValuePair_free(keyPairQuery_force);
        keyPairQuery_force = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// partially update the specified ReplicaSet
//
v1_replica_set_t*
AppsV1API_patchNamespacedReplicaSet(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/replicasets/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/replicasets/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams__namespace = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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
    char *keyQuery_force = NULL;
    char * valueQuery_force = NULL;
    keyValuePair_t *keyPairQuery_force = 0;
    if (force)
    {
        keyQuery_force = strdup("force");
        valueQuery_force = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_force, MAX_NUMBER_LENGTH, "%d", force);
        keyPairQuery_force = keyValuePair_create(keyQuery_force, valueQuery_force);
        list_addElement(localVarQueryParameters,keyPairQuery_force);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = object_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarContentType,"application/json-patch+json"); //consumes
    list_addElement(localVarContentType,"application/merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/strategic-merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/apply-patch+yaml"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "PATCH");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_replica_set_t *elementToReturn = v1_replica_set_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    list_free(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace__namespace);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
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
    if(keyQuery_force){
        free(keyQuery_force);
        keyQuery_force = NULL;
    }
    if(valueQuery_force){
        free(valueQuery_force);
        valueQuery_force = NULL;
    }
    if(keyPairQuery_force){
        keyValuePair_free(keyPairQuery_force);
        keyPairQuery_force = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// partially update scale of the specified ReplicaSet
//
v1_scale_t*
AppsV1API_patchNamespacedReplicaSetScale(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/replicasets/{name}/scale")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/replicasets/{name}/scale");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams__namespace = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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
    char *keyQuery_force = NULL;
    char * valueQuery_force = NULL;
    keyValuePair_t *keyPairQuery_force = 0;
    if (force)
    {
        keyQuery_force = strdup("force");
        valueQuery_force = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_force, MAX_NUMBER_LENGTH, "%d", force);
        keyPairQuery_force = keyValuePair_create(keyQuery_force, valueQuery_force);
        list_addElement(localVarQueryParameters,keyPairQuery_force);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = object_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarContentType,"application/json-patch+json"); //consumes
    list_addElement(localVarContentType,"application/merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/strategic-merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/apply-patch+yaml"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "PATCH");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_scale_t *elementToReturn = v1_scale_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    list_free(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace__namespace);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
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
    if(keyQuery_force){
        free(keyQuery_force);
        keyQuery_force = NULL;
    }
    if(valueQuery_force){
        free(valueQuery_force);
        valueQuery_force = NULL;
    }
    if(keyPairQuery_force){
        keyValuePair_free(keyPairQuery_force);
        keyPairQuery_force = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// partially update status of the specified ReplicaSet
//
v1_replica_set_t*
AppsV1API_patchNamespacedReplicaSetStatus(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/replicasets/{name}/status")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/replicasets/{name}/status");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams__namespace = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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
    char *keyQuery_force = NULL;
    char * valueQuery_force = NULL;
    keyValuePair_t *keyPairQuery_force = 0;
    if (force)
    {
        keyQuery_force = strdup("force");
        valueQuery_force = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_force, MAX_NUMBER_LENGTH, "%d", force);
        keyPairQuery_force = keyValuePair_create(keyQuery_force, valueQuery_force);
        list_addElement(localVarQueryParameters,keyPairQuery_force);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = object_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarContentType,"application/json-patch+json"); //consumes
    list_addElement(localVarContentType,"application/merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/strategic-merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/apply-patch+yaml"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "PATCH");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_replica_set_t *elementToReturn = v1_replica_set_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    list_free(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace__namespace);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
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
    if(keyQuery_force){
        free(keyQuery_force);
        keyQuery_force = NULL;
    }
    if(valueQuery_force){
        free(valueQuery_force);
        valueQuery_force = NULL;
    }
    if(keyPairQuery_force){
        keyValuePair_free(keyPairQuery_force);
        keyPairQuery_force = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// partially update the specified StatefulSet
//
v1_stateful_set_t*
AppsV1API_patchNamespacedStatefulSet(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/statefulsets/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/statefulsets/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams__namespace = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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
    char *keyQuery_force = NULL;
    char * valueQuery_force = NULL;
    keyValuePair_t *keyPairQuery_force = 0;
    if (force)
    {
        keyQuery_force = strdup("force");
        valueQuery_force = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_force, MAX_NUMBER_LENGTH, "%d", force);
        keyPairQuery_force = keyValuePair_create(keyQuery_force, valueQuery_force);
        list_addElement(localVarQueryParameters,keyPairQuery_force);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = object_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarContentType,"application/json-patch+json"); //consumes
    list_addElement(localVarContentType,"application/merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/strategic-merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/apply-patch+yaml"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "PATCH");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_stateful_set_t *elementToReturn = v1_stateful_set_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    list_free(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace__namespace);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
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
    if(keyQuery_force){
        free(keyQuery_force);
        keyQuery_force = NULL;
    }
    if(valueQuery_force){
        free(valueQuery_force);
        valueQuery_force = NULL;
    }
    if(keyPairQuery_force){
        keyValuePair_free(keyPairQuery_force);
        keyPairQuery_force = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// partially update scale of the specified StatefulSet
//
v1_scale_t*
AppsV1API_patchNamespacedStatefulSetScale(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/statefulsets/{name}/scale")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/statefulsets/{name}/scale");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams__namespace = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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
    char *keyQuery_force = NULL;
    char * valueQuery_force = NULL;
    keyValuePair_t *keyPairQuery_force = 0;
    if (force)
    {
        keyQuery_force = strdup("force");
        valueQuery_force = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_force, MAX_NUMBER_LENGTH, "%d", force);
        keyPairQuery_force = keyValuePair_create(keyQuery_force, valueQuery_force);
        list_addElement(localVarQueryParameters,keyPairQuery_force);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = object_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarContentType,"application/json-patch+json"); //consumes
    list_addElement(localVarContentType,"application/merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/strategic-merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/apply-patch+yaml"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "PATCH");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_scale_t *elementToReturn = v1_scale_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    list_free(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace__namespace);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
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
    if(keyQuery_force){
        free(keyQuery_force);
        keyQuery_force = NULL;
    }
    if(valueQuery_force){
        free(valueQuery_force);
        valueQuery_force = NULL;
    }
    if(keyPairQuery_force){
        keyValuePair_free(keyPairQuery_force);
        keyPairQuery_force = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// partially update status of the specified StatefulSet
//
v1_stateful_set_t*
AppsV1API_patchNamespacedStatefulSetStatus(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/statefulsets/{name}/status")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/statefulsets/{name}/status");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams__namespace = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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
    char *keyQuery_force = NULL;
    char * valueQuery_force = NULL;
    keyValuePair_t *keyPairQuery_force = 0;
    if (force)
    {
        keyQuery_force = strdup("force");
        valueQuery_force = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_force, MAX_NUMBER_LENGTH, "%d", force);
        keyPairQuery_force = keyValuePair_create(keyQuery_force, valueQuery_force);
        list_addElement(localVarQueryParameters,keyPairQuery_force);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = object_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/yaml"); //produces
    list_addElement(localVarHeaderType,"application/vnd.kubernetes.protobuf"); //produces
    list_addElement(localVarContentType,"application/json-patch+json"); //consumes
    list_addElement(localVarContentType,"application/merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/strategic-merge-patch+json"); //consumes
    list_addElement(localVarContentType,"application/apply-patch+yaml"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "PATCH");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_stateful_set_t *elementToReturn = v1_stateful_set_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    list_free(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace__namespace);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
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
    if(keyQuery_force){
        free(keyQuery_force);
        keyQuery_force = NULL;
    }
    if(valueQuery_force){
        free(valueQuery_force);
        valueQuery_force = NULL;
    }
    if(keyPairQuery_force){
        keyValuePair_free(keyPairQuery_force);
        keyPairQuery_force = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// read the specified ControllerRevision
//
v1_controller_revision_t*
AppsV1API_readNamespacedControllerRevision(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , int exact , int _export )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/controllerrevisions/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/controllerrevisions/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams__namespace = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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

    // query parameters
    char *keyQuery_exact = NULL;
    char * valueQuery_exact = NULL;
    keyValuePair_t *keyPairQuery_exact = 0;
    if (exact)
    {
        keyQuery_exact = strdup("exact");
        valueQuery_exact = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_exact, MAX_NUMBER_LENGTH, "%d", exact);
        keyPairQuery_exact = keyValuePair_create(keyQuery_exact, valueQuery_exact);
        list_addElement(localVarQueryParameters,keyPairQuery_exact);
    }

    // query parameters
    char *keyQuery__export = NULL;
    char * valueQuery__export = NULL;
    keyValuePair_t *keyPairQuery__export = 0;
    if (_export)
    {
        keyQuery__export = strdup("export");
        valueQuery__export = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery__export, MAX_NUMBER_LENGTH, "%d", _export);
        keyPairQuery__export = keyValuePair_create(keyQuery__export, valueQuery__export);
        list_addElement(localVarQueryParameters,keyPairQuery__export);
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
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_controller_revision_t *elementToReturn = v1_controller_revision_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    free(localVarToReplace_name);
    free(localVarToReplace__namespace);
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
    if(keyQuery_exact){
        free(keyQuery_exact);
        keyQuery_exact = NULL;
    }
    if(valueQuery_exact){
        free(valueQuery_exact);
        valueQuery_exact = NULL;
    }
    if(keyPairQuery_exact){
        keyValuePair_free(keyPairQuery_exact);
        keyPairQuery_exact = NULL;
    }
    if(keyQuery__export){
        free(keyQuery__export);
        keyQuery__export = NULL;
    }
    if(valueQuery__export){
        free(valueQuery__export);
        valueQuery__export = NULL;
    }
    if(keyPairQuery__export){
        keyValuePair_free(keyPairQuery__export);
        keyPairQuery__export = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// read the specified DaemonSet
//
v1_daemon_set_t*
AppsV1API_readNamespacedDaemonSet(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , int exact , int _export )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/daemonsets/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/daemonsets/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams__namespace = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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

    // query parameters
    char *keyQuery_exact = NULL;
    char * valueQuery_exact = NULL;
    keyValuePair_t *keyPairQuery_exact = 0;
    if (exact)
    {
        keyQuery_exact = strdup("exact");
        valueQuery_exact = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_exact, MAX_NUMBER_LENGTH, "%d", exact);
        keyPairQuery_exact = keyValuePair_create(keyQuery_exact, valueQuery_exact);
        list_addElement(localVarQueryParameters,keyPairQuery_exact);
    }

    // query parameters
    char *keyQuery__export = NULL;
    char * valueQuery__export = NULL;
    keyValuePair_t *keyPairQuery__export = 0;
    if (_export)
    {
        keyQuery__export = strdup("export");
        valueQuery__export = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery__export, MAX_NUMBER_LENGTH, "%d", _export);
        keyPairQuery__export = keyValuePair_create(keyQuery__export, valueQuery__export);
        list_addElement(localVarQueryParameters,keyPairQuery__export);
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
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_daemon_set_t *elementToReturn = v1_daemon_set_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    free(localVarToReplace_name);
    free(localVarToReplace__namespace);
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
    if(keyQuery_exact){
        free(keyQuery_exact);
        keyQuery_exact = NULL;
    }
    if(valueQuery_exact){
        free(valueQuery_exact);
        valueQuery_exact = NULL;
    }
    if(keyPairQuery_exact){
        keyValuePair_free(keyPairQuery_exact);
        keyPairQuery_exact = NULL;
    }
    if(keyQuery__export){
        free(keyQuery__export);
        keyQuery__export = NULL;
    }
    if(valueQuery__export){
        free(valueQuery__export);
        valueQuery__export = NULL;
    }
    if(keyPairQuery__export){
        keyValuePair_free(keyPairQuery__export);
        keyPairQuery__export = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// read status of the specified DaemonSet
//
v1_daemon_set_t*
AppsV1API_readNamespacedDaemonSetStatus(apiClient_t *apiClient, char * name , char * _namespace , char * pretty )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/daemonsets/{name}/status")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/daemonsets/{name}/status");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams__namespace = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_daemon_set_t *elementToReturn = v1_daemon_set_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    free(localVarToReplace_name);
    free(localVarToReplace__namespace);
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

// read the specified Deployment
//
v1_deployment_t*
AppsV1API_readNamespacedDeployment(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , int exact , int _export )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/deployments/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/deployments/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams__namespace = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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

    // query parameters
    char *keyQuery_exact = NULL;
    char * valueQuery_exact = NULL;
    keyValuePair_t *keyPairQuery_exact = 0;
    if (exact)
    {
        keyQuery_exact = strdup("exact");
        valueQuery_exact = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_exact, MAX_NUMBER_LENGTH, "%d", exact);
        keyPairQuery_exact = keyValuePair_create(keyQuery_exact, valueQuery_exact);
        list_addElement(localVarQueryParameters,keyPairQuery_exact);
    }

    // query parameters
    char *keyQuery__export = NULL;
    char * valueQuery__export = NULL;
    keyValuePair_t *keyPairQuery__export = 0;
    if (_export)
    {
        keyQuery__export = strdup("export");
        valueQuery__export = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery__export, MAX_NUMBER_LENGTH, "%d", _export);
        keyPairQuery__export = keyValuePair_create(keyQuery__export, valueQuery__export);
        list_addElement(localVarQueryParameters,keyPairQuery__export);
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
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_deployment_t *elementToReturn = v1_deployment_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    free(localVarToReplace_name);
    free(localVarToReplace__namespace);
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
    if(keyQuery_exact){
        free(keyQuery_exact);
        keyQuery_exact = NULL;
    }
    if(valueQuery_exact){
        free(valueQuery_exact);
        valueQuery_exact = NULL;
    }
    if(keyPairQuery_exact){
        keyValuePair_free(keyPairQuery_exact);
        keyPairQuery_exact = NULL;
    }
    if(keyQuery__export){
        free(keyQuery__export);
        keyQuery__export = NULL;
    }
    if(valueQuery__export){
        free(valueQuery__export);
        valueQuery__export = NULL;
    }
    if(keyPairQuery__export){
        keyValuePair_free(keyPairQuery__export);
        keyPairQuery__export = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// read scale of the specified Deployment
//
v1_scale_t*
AppsV1API_readNamespacedDeploymentScale(apiClient_t *apiClient, char * name , char * _namespace , char * pretty )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/deployments/{name}/scale")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/deployments/{name}/scale");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams__namespace = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_scale_t *elementToReturn = v1_scale_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    free(localVarToReplace_name);
    free(localVarToReplace__namespace);
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

// read status of the specified Deployment
//
v1_deployment_t*
AppsV1API_readNamespacedDeploymentStatus(apiClient_t *apiClient, char * name , char * _namespace , char * pretty )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/deployments/{name}/status")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/deployments/{name}/status");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams__namespace = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_deployment_t *elementToReturn = v1_deployment_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    free(localVarToReplace_name);
    free(localVarToReplace__namespace);
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

// read the specified ReplicaSet
//
v1_replica_set_t*
AppsV1API_readNamespacedReplicaSet(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , int exact , int _export )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/replicasets/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/replicasets/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams__namespace = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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

    // query parameters
    char *keyQuery_exact = NULL;
    char * valueQuery_exact = NULL;
    keyValuePair_t *keyPairQuery_exact = 0;
    if (exact)
    {
        keyQuery_exact = strdup("exact");
        valueQuery_exact = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_exact, MAX_NUMBER_LENGTH, "%d", exact);
        keyPairQuery_exact = keyValuePair_create(keyQuery_exact, valueQuery_exact);
        list_addElement(localVarQueryParameters,keyPairQuery_exact);
    }

    // query parameters
    char *keyQuery__export = NULL;
    char * valueQuery__export = NULL;
    keyValuePair_t *keyPairQuery__export = 0;
    if (_export)
    {
        keyQuery__export = strdup("export");
        valueQuery__export = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery__export, MAX_NUMBER_LENGTH, "%d", _export);
        keyPairQuery__export = keyValuePair_create(keyQuery__export, valueQuery__export);
        list_addElement(localVarQueryParameters,keyPairQuery__export);
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
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_replica_set_t *elementToReturn = v1_replica_set_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    free(localVarToReplace_name);
    free(localVarToReplace__namespace);
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
    if(keyQuery_exact){
        free(keyQuery_exact);
        keyQuery_exact = NULL;
    }
    if(valueQuery_exact){
        free(valueQuery_exact);
        valueQuery_exact = NULL;
    }
    if(keyPairQuery_exact){
        keyValuePair_free(keyPairQuery_exact);
        keyPairQuery_exact = NULL;
    }
    if(keyQuery__export){
        free(keyQuery__export);
        keyQuery__export = NULL;
    }
    if(valueQuery__export){
        free(valueQuery__export);
        valueQuery__export = NULL;
    }
    if(keyPairQuery__export){
        keyValuePair_free(keyPairQuery__export);
        keyPairQuery__export = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// read scale of the specified ReplicaSet
//
v1_scale_t*
AppsV1API_readNamespacedReplicaSetScale(apiClient_t *apiClient, char * name , char * _namespace , char * pretty )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/replicasets/{name}/scale")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/replicasets/{name}/scale");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams__namespace = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_scale_t *elementToReturn = v1_scale_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    free(localVarToReplace_name);
    free(localVarToReplace__namespace);
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

// read status of the specified ReplicaSet
//
v1_replica_set_t*
AppsV1API_readNamespacedReplicaSetStatus(apiClient_t *apiClient, char * name , char * _namespace , char * pretty )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/replicasets/{name}/status")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/replicasets/{name}/status");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams__namespace = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_replica_set_t *elementToReturn = v1_replica_set_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    free(localVarToReplace_name);
    free(localVarToReplace__namespace);
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

// read the specified StatefulSet
//
v1_stateful_set_t*
AppsV1API_readNamespacedStatefulSet(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , int exact , int _export )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/statefulsets/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/statefulsets/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams__namespace = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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

    // query parameters
    char *keyQuery_exact = NULL;
    char * valueQuery_exact = NULL;
    keyValuePair_t *keyPairQuery_exact = 0;
    if (exact)
    {
        keyQuery_exact = strdup("exact");
        valueQuery_exact = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_exact, MAX_NUMBER_LENGTH, "%d", exact);
        keyPairQuery_exact = keyValuePair_create(keyQuery_exact, valueQuery_exact);
        list_addElement(localVarQueryParameters,keyPairQuery_exact);
    }

    // query parameters
    char *keyQuery__export = NULL;
    char * valueQuery__export = NULL;
    keyValuePair_t *keyPairQuery__export = 0;
    if (_export)
    {
        keyQuery__export = strdup("export");
        valueQuery__export = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery__export, MAX_NUMBER_LENGTH, "%d", _export);
        keyPairQuery__export = keyValuePair_create(keyQuery__export, valueQuery__export);
        list_addElement(localVarQueryParameters,keyPairQuery__export);
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
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_stateful_set_t *elementToReturn = v1_stateful_set_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    free(localVarToReplace_name);
    free(localVarToReplace__namespace);
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
    if(keyQuery_exact){
        free(keyQuery_exact);
        keyQuery_exact = NULL;
    }
    if(valueQuery_exact){
        free(valueQuery_exact);
        valueQuery_exact = NULL;
    }
    if(keyPairQuery_exact){
        keyValuePair_free(keyPairQuery_exact);
        keyPairQuery_exact = NULL;
    }
    if(keyQuery__export){
        free(keyQuery__export);
        keyQuery__export = NULL;
    }
    if(valueQuery__export){
        free(valueQuery__export);
        valueQuery__export = NULL;
    }
    if(keyPairQuery__export){
        keyValuePair_free(keyPairQuery__export);
        keyPairQuery__export = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// read scale of the specified StatefulSet
//
v1_scale_t*
AppsV1API_readNamespacedStatefulSetScale(apiClient_t *apiClient, char * name , char * _namespace , char * pretty )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/statefulsets/{name}/scale")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/statefulsets/{name}/scale");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams__namespace = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_scale_t *elementToReturn = v1_scale_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    free(localVarToReplace_name);
    free(localVarToReplace__namespace);
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

// read status of the specified StatefulSet
//
v1_stateful_set_t*
AppsV1API_readNamespacedStatefulSetStatus(apiClient_t *apiClient, char * name , char * _namespace , char * pretty )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/statefulsets/{name}/status")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/statefulsets/{name}/status");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams__namespace = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_stateful_set_t *elementToReturn = v1_stateful_set_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    free(localVarToReplace_name);
    free(localVarToReplace__namespace);
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

// replace the specified ControllerRevision
//
v1_controller_revision_t*
AppsV1API_replaceNamespacedControllerRevision(apiClient_t *apiClient, char * name , char * _namespace , v1_controller_revision_t * body , char * pretty , char * dryRun , char * fieldManager )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/controllerrevisions/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/controllerrevisions/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams__namespace = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_controller_revision_convertToJSON(body);
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
                    "PUT");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 201) {
        printf("%s\n","Created");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_controller_revision_t *elementToReturn = v1_controller_revision_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    free(localVarToReplace_name);
    free(localVarToReplace__namespace);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// replace the specified DaemonSet
//
v1_daemon_set_t*
AppsV1API_replaceNamespacedDaemonSet(apiClient_t *apiClient, char * name , char * _namespace , v1_daemon_set_t * body , char * pretty , char * dryRun , char * fieldManager )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/daemonsets/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/daemonsets/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams__namespace = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_daemon_set_convertToJSON(body);
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
                    "PUT");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 201) {
        printf("%s\n","Created");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_daemon_set_t *elementToReturn = v1_daemon_set_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    free(localVarToReplace_name);
    free(localVarToReplace__namespace);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// replace status of the specified DaemonSet
//
v1_daemon_set_t*
AppsV1API_replaceNamespacedDaemonSetStatus(apiClient_t *apiClient, char * name , char * _namespace , v1_daemon_set_t * body , char * pretty , char * dryRun , char * fieldManager )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/daemonsets/{name}/status")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/daemonsets/{name}/status");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams__namespace = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_daemon_set_convertToJSON(body);
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
                    "PUT");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 201) {
        printf("%s\n","Created");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_daemon_set_t *elementToReturn = v1_daemon_set_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    free(localVarToReplace_name);
    free(localVarToReplace__namespace);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// replace the specified Deployment
//
v1_deployment_t*
AppsV1API_replaceNamespacedDeployment(apiClient_t *apiClient, char * name , char * _namespace , v1_deployment_t * body , char * pretty , char * dryRun , char * fieldManager )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/deployments/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/deployments/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams__namespace = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_deployment_convertToJSON(body);
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
                    "PUT");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 201) {
        printf("%s\n","Created");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_deployment_t *elementToReturn = v1_deployment_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    free(localVarToReplace_name);
    free(localVarToReplace__namespace);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// replace scale of the specified Deployment
//
v1_scale_t*
AppsV1API_replaceNamespacedDeploymentScale(apiClient_t *apiClient, char * name , char * _namespace , v1_scale_t * body , char * pretty , char * dryRun , char * fieldManager )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/deployments/{name}/scale")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/deployments/{name}/scale");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams__namespace = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_scale_convertToJSON(body);
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
                    "PUT");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 201) {
        printf("%s\n","Created");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_scale_t *elementToReturn = v1_scale_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    free(localVarToReplace_name);
    free(localVarToReplace__namespace);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// replace status of the specified Deployment
//
v1_deployment_t*
AppsV1API_replaceNamespacedDeploymentStatus(apiClient_t *apiClient, char * name , char * _namespace , v1_deployment_t * body , char * pretty , char * dryRun , char * fieldManager )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/deployments/{name}/status")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/deployments/{name}/status");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams__namespace = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_deployment_convertToJSON(body);
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
                    "PUT");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 201) {
        printf("%s\n","Created");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_deployment_t *elementToReturn = v1_deployment_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    free(localVarToReplace_name);
    free(localVarToReplace__namespace);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// replace the specified ReplicaSet
//
v1_replica_set_t*
AppsV1API_replaceNamespacedReplicaSet(apiClient_t *apiClient, char * name , char * _namespace , v1_replica_set_t * body , char * pretty , char * dryRun , char * fieldManager )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/replicasets/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/replicasets/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams__namespace = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_replica_set_convertToJSON(body);
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
                    "PUT");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 201) {
        printf("%s\n","Created");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_replica_set_t *elementToReturn = v1_replica_set_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    free(localVarToReplace_name);
    free(localVarToReplace__namespace);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// replace scale of the specified ReplicaSet
//
v1_scale_t*
AppsV1API_replaceNamespacedReplicaSetScale(apiClient_t *apiClient, char * name , char * _namespace , v1_scale_t * body , char * pretty , char * dryRun , char * fieldManager )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/replicasets/{name}/scale")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/replicasets/{name}/scale");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams__namespace = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_scale_convertToJSON(body);
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
                    "PUT");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 201) {
        printf("%s\n","Created");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_scale_t *elementToReturn = v1_scale_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    free(localVarToReplace_name);
    free(localVarToReplace__namespace);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// replace status of the specified ReplicaSet
//
v1_replica_set_t*
AppsV1API_replaceNamespacedReplicaSetStatus(apiClient_t *apiClient, char * name , char * _namespace , v1_replica_set_t * body , char * pretty , char * dryRun , char * fieldManager )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/replicasets/{name}/status")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/replicasets/{name}/status");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams__namespace = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_replica_set_convertToJSON(body);
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
                    "PUT");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 201) {
        printf("%s\n","Created");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_replica_set_t *elementToReturn = v1_replica_set_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    free(localVarToReplace_name);
    free(localVarToReplace__namespace);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// replace the specified StatefulSet
//
v1_stateful_set_t*
AppsV1API_replaceNamespacedStatefulSet(apiClient_t *apiClient, char * name , char * _namespace , v1_stateful_set_t * body , char * pretty , char * dryRun , char * fieldManager )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/statefulsets/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/statefulsets/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams__namespace = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_stateful_set_convertToJSON(body);
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
                    "PUT");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 201) {
        printf("%s\n","Created");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_stateful_set_t *elementToReturn = v1_stateful_set_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    free(localVarToReplace_name);
    free(localVarToReplace__namespace);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// replace scale of the specified StatefulSet
//
v1_scale_t*
AppsV1API_replaceNamespacedStatefulSetScale(apiClient_t *apiClient, char * name , char * _namespace , v1_scale_t * body , char * pretty , char * dryRun , char * fieldManager )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/statefulsets/{name}/scale")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/statefulsets/{name}/scale");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams__namespace = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_scale_convertToJSON(body);
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
                    "PUT");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 201) {
        printf("%s\n","Created");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_scale_t *elementToReturn = v1_scale_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    free(localVarToReplace_name);
    free(localVarToReplace__namespace);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// replace status of the specified StatefulSet
//
v1_stateful_set_t*
AppsV1API_replaceNamespacedStatefulSetStatus(apiClient_t *apiClient, char * name , char * _namespace , v1_stateful_set_t * body , char * pretty , char * dryRun , char * fieldManager )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/apps/v1/namespaces/{namespace}/statefulsets/{name}/status")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/apps/v1/namespaces/{namespace}/statefulsets/{name}/status");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams__namespace = strlen(name)+3 + strlen(_namespace)+3 + strlen("{ namespace }");
    if(_namespace == NULL) {
        goto end;
    }
    char* localVarToReplace__namespace = malloc(sizeOfPathParams__namespace);
    sprintf(localVarToReplace__namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace__namespace, _namespace);



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

    // Body Param
    cJSON *localVarSingleItemJSON_body = NULL;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_stateful_set_convertToJSON(body);
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
                    "PUT");

    if (apiClient->response_code == 200) {
        printf("%s\n","OK");
    }
    if (apiClient->response_code == 201) {
        printf("%s\n","Created");
    }
    if (apiClient->response_code == 401) {
        printf("%s\n","Unauthorized");
    }
    //nonprimitive not container
    cJSON *AppsV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_stateful_set_t *elementToReturn = v1_stateful_set_parseFromJSON(AppsV1APIlocalVarJSON);
    cJSON_Delete(AppsV1APIlocalVarJSON);
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
    free(localVarToReplace_name);
    free(localVarToReplace__namespace);
    if (localVarSingleItemJSON_body) {
        cJSON_Delete(localVarSingleItemJSON_body);
        localVarSingleItemJSON_body = NULL;
    }
    free(localVarBodyParameters);
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
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

