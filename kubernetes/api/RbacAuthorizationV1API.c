#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "RbacAuthorizationV1API.h"


#define MAX_BUFFER_LENGTH 4096
#define intToStr(dst, src) \
    do {\
    char dst[256];\
    snprintf(dst, 256, "%ld", (long int)(src));\
}while(0)


// create a ClusterRole
//
v1_cluster_role_t*
RbacAuthorizationV1API_createClusterRole(apiClient_t *apiClient, v1_cluster_role_t * body , char * pretty , char * dryRun , char * fieldManager )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/clusterroles")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/clusterroles");




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
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_cluster_role_convertToJSON(body);
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
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_cluster_role_t *elementToReturn = v1_cluster_role_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    cJSON_Delete(localVarSingleItemJSON_body);
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
    return NULL;

}

// create a ClusterRoleBinding
//
v1_cluster_role_binding_t*
RbacAuthorizationV1API_createClusterRoleBinding(apiClient_t *apiClient, v1_cluster_role_binding_t * body , char * pretty , char * dryRun , char * fieldManager )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/clusterrolebindings")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/clusterrolebindings");




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
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_cluster_role_binding_convertToJSON(body);
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
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_cluster_role_binding_t *elementToReturn = v1_cluster_role_binding_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    cJSON_Delete(localVarSingleItemJSON_body);
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
    return NULL;

}

// create a Role
//
v1_role_t*
RbacAuthorizationV1API_createNamespacedRole(apiClient_t *apiClient, char * namespace , v1_role_t * body , char * pretty , char * dryRun , char * fieldManager )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/roles")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/roles");


    // Path Params
    long sizeOfPathParams_namespace = strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



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
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_role_convertToJSON(body);
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
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_role_t *elementToReturn = v1_role_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
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
    return NULL;

}

// create a RoleBinding
//
v1_role_binding_t*
RbacAuthorizationV1API_createNamespacedRoleBinding(apiClient_t *apiClient, char * namespace , v1_role_binding_t * body , char * pretty , char * dryRun , char * fieldManager )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/rolebindings")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/rolebindings");


    // Path Params
    long sizeOfPathParams_namespace = strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



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
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_role_binding_convertToJSON(body);
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
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_role_binding_t *elementToReturn = v1_role_binding_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
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
    return NULL;

}

// delete a ClusterRole
//
v1_status_t*
RbacAuthorizationV1API_deleteClusterRole(apiClient_t *apiClient, char * name , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/clusterroles/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/clusterroles/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



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
    int valueQuery_gracePeriodSeconds ;
    keyValuePair_t *keyPairQuery_gracePeriodSeconds = 0;
    if (gracePeriodSeconds)
    {
        keyQuery_gracePeriodSeconds = strdup("gracePeriodSeconds");
        valueQuery_gracePeriodSeconds = (gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = keyValuePair_create(keyQuery_gracePeriodSeconds, &valueQuery_gracePeriodSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_gracePeriodSeconds);
    }

    // query parameters
    char *keyQuery_orphanDependents = NULL;
    int valueQuery_orphanDependents ;
    keyValuePair_t *keyPairQuery_orphanDependents = 0;
    if (orphanDependents)
    {
        keyQuery_orphanDependents = strdup("orphanDependents");
        valueQuery_orphanDependents = (orphanDependents);
        keyPairQuery_orphanDependents = keyValuePair_create(keyQuery_orphanDependents, &valueQuery_orphanDependents);
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
    cJSON *localVarSingleItemJSON_body;
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
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_status_t *elementToReturn = v1_status_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_name);
    cJSON_Delete(localVarSingleItemJSON_body);
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
    if(keyPairQuery_gracePeriodSeconds){
        keyValuePair_free(keyPairQuery_gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = NULL;
    }
    if(keyQuery_orphanDependents){
        free(keyQuery_orphanDependents);
        keyQuery_orphanDependents = NULL;
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
    return NULL;

}

// delete a ClusterRoleBinding
//
v1_status_t*
RbacAuthorizationV1API_deleteClusterRoleBinding(apiClient_t *apiClient, char * name , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/clusterrolebindings/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/clusterrolebindings/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



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
    int valueQuery_gracePeriodSeconds ;
    keyValuePair_t *keyPairQuery_gracePeriodSeconds = 0;
    if (gracePeriodSeconds)
    {
        keyQuery_gracePeriodSeconds = strdup("gracePeriodSeconds");
        valueQuery_gracePeriodSeconds = (gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = keyValuePair_create(keyQuery_gracePeriodSeconds, &valueQuery_gracePeriodSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_gracePeriodSeconds);
    }

    // query parameters
    char *keyQuery_orphanDependents = NULL;
    int valueQuery_orphanDependents ;
    keyValuePair_t *keyPairQuery_orphanDependents = 0;
    if (orphanDependents)
    {
        keyQuery_orphanDependents = strdup("orphanDependents");
        valueQuery_orphanDependents = (orphanDependents);
        keyPairQuery_orphanDependents = keyValuePair_create(keyQuery_orphanDependents, &valueQuery_orphanDependents);
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
    cJSON *localVarSingleItemJSON_body;
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
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_status_t *elementToReturn = v1_status_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_name);
    cJSON_Delete(localVarSingleItemJSON_body);
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
    if(keyPairQuery_gracePeriodSeconds){
        keyValuePair_free(keyPairQuery_gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = NULL;
    }
    if(keyQuery_orphanDependents){
        free(keyQuery_orphanDependents);
        keyQuery_orphanDependents = NULL;
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
    return NULL;

}

// delete collection of ClusterRole
//
v1_status_t*
RbacAuthorizationV1API_deleteCollectionClusterRole(apiClient_t *apiClient, char * pretty , int allowWatchBookmarks , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , int watch , v1_delete_options_t * body )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/clusterroles")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/clusterroles");




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
    int valueQuery_allowWatchBookmarks ;
    keyValuePair_t *keyPairQuery_allowWatchBookmarks = 0;
    if (allowWatchBookmarks)
    {
        keyQuery_allowWatchBookmarks = strdup("allowWatchBookmarks");
        valueQuery_allowWatchBookmarks = (allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = keyValuePair_create(keyQuery_allowWatchBookmarks, &valueQuery_allowWatchBookmarks);
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
    int valueQuery_gracePeriodSeconds ;
    keyValuePair_t *keyPairQuery_gracePeriodSeconds = 0;
    if (gracePeriodSeconds)
    {
        keyQuery_gracePeriodSeconds = strdup("gracePeriodSeconds");
        valueQuery_gracePeriodSeconds = (gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = keyValuePair_create(keyQuery_gracePeriodSeconds, &valueQuery_gracePeriodSeconds);
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
    int valueQuery_limit ;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = (limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, &valueQuery_limit);
        list_addElement(localVarQueryParameters,keyPairQuery_limit);
    }

    // query parameters
    char *keyQuery_orphanDependents = NULL;
    int valueQuery_orphanDependents ;
    keyValuePair_t *keyPairQuery_orphanDependents = 0;
    if (orphanDependents)
    {
        keyQuery_orphanDependents = strdup("orphanDependents");
        valueQuery_orphanDependents = (orphanDependents);
        keyPairQuery_orphanDependents = keyValuePair_create(keyQuery_orphanDependents, &valueQuery_orphanDependents);
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
    int valueQuery_timeoutSeconds ;
    keyValuePair_t *keyPairQuery_timeoutSeconds = 0;
    if (timeoutSeconds)
    {
        keyQuery_timeoutSeconds = strdup("timeoutSeconds");
        valueQuery_timeoutSeconds = (timeoutSeconds);
        keyPairQuery_timeoutSeconds = keyValuePair_create(keyQuery_timeoutSeconds, &valueQuery_timeoutSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_timeoutSeconds);
    }

    // query parameters
    char *keyQuery_watch = NULL;
    int valueQuery_watch ;
    keyValuePair_t *keyPairQuery_watch = 0;
    if (watch)
    {
        keyQuery_watch = strdup("watch");
        valueQuery_watch = (watch);
        keyPairQuery_watch = keyValuePair_create(keyQuery_watch, &valueQuery_watch);
        list_addElement(localVarQueryParameters,keyPairQuery_watch);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
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
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_status_t *elementToReturn = v1_status_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    cJSON_Delete(localVarSingleItemJSON_body);
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
    if(keyQuery_allowWatchBookmarks){
        free(keyQuery_allowWatchBookmarks);
        keyQuery_allowWatchBookmarks = NULL;
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
    if(keyPairQuery_limit){
        keyValuePair_free(keyPairQuery_limit);
        keyPairQuery_limit = NULL;
    }
    if(keyQuery_orphanDependents){
        free(keyQuery_orphanDependents);
        keyQuery_orphanDependents = NULL;
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
    if(keyPairQuery_timeoutSeconds){
        keyValuePair_free(keyPairQuery_timeoutSeconds);
        keyPairQuery_timeoutSeconds = NULL;
    }
    if(keyQuery_watch){
        free(keyQuery_watch);
        keyQuery_watch = NULL;
    }
    if(keyPairQuery_watch){
        keyValuePair_free(keyPairQuery_watch);
        keyPairQuery_watch = NULL;
    }
    return elementToReturn;
end:
    return NULL;

}

// delete collection of ClusterRoleBinding
//
v1_status_t*
RbacAuthorizationV1API_deleteCollectionClusterRoleBinding(apiClient_t *apiClient, char * pretty , int allowWatchBookmarks , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , int watch , v1_delete_options_t * body )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/clusterrolebindings")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/clusterrolebindings");




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
    int valueQuery_allowWatchBookmarks ;
    keyValuePair_t *keyPairQuery_allowWatchBookmarks = 0;
    if (allowWatchBookmarks)
    {
        keyQuery_allowWatchBookmarks = strdup("allowWatchBookmarks");
        valueQuery_allowWatchBookmarks = (allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = keyValuePair_create(keyQuery_allowWatchBookmarks, &valueQuery_allowWatchBookmarks);
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
    int valueQuery_gracePeriodSeconds ;
    keyValuePair_t *keyPairQuery_gracePeriodSeconds = 0;
    if (gracePeriodSeconds)
    {
        keyQuery_gracePeriodSeconds = strdup("gracePeriodSeconds");
        valueQuery_gracePeriodSeconds = (gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = keyValuePair_create(keyQuery_gracePeriodSeconds, &valueQuery_gracePeriodSeconds);
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
    int valueQuery_limit ;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = (limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, &valueQuery_limit);
        list_addElement(localVarQueryParameters,keyPairQuery_limit);
    }

    // query parameters
    char *keyQuery_orphanDependents = NULL;
    int valueQuery_orphanDependents ;
    keyValuePair_t *keyPairQuery_orphanDependents = 0;
    if (orphanDependents)
    {
        keyQuery_orphanDependents = strdup("orphanDependents");
        valueQuery_orphanDependents = (orphanDependents);
        keyPairQuery_orphanDependents = keyValuePair_create(keyQuery_orphanDependents, &valueQuery_orphanDependents);
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
    int valueQuery_timeoutSeconds ;
    keyValuePair_t *keyPairQuery_timeoutSeconds = 0;
    if (timeoutSeconds)
    {
        keyQuery_timeoutSeconds = strdup("timeoutSeconds");
        valueQuery_timeoutSeconds = (timeoutSeconds);
        keyPairQuery_timeoutSeconds = keyValuePair_create(keyQuery_timeoutSeconds, &valueQuery_timeoutSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_timeoutSeconds);
    }

    // query parameters
    char *keyQuery_watch = NULL;
    int valueQuery_watch ;
    keyValuePair_t *keyPairQuery_watch = 0;
    if (watch)
    {
        keyQuery_watch = strdup("watch");
        valueQuery_watch = (watch);
        keyPairQuery_watch = keyValuePair_create(keyQuery_watch, &valueQuery_watch);
        list_addElement(localVarQueryParameters,keyPairQuery_watch);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
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
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_status_t *elementToReturn = v1_status_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    cJSON_Delete(localVarSingleItemJSON_body);
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
    if(keyQuery_allowWatchBookmarks){
        free(keyQuery_allowWatchBookmarks);
        keyQuery_allowWatchBookmarks = NULL;
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
    if(keyPairQuery_limit){
        keyValuePair_free(keyPairQuery_limit);
        keyPairQuery_limit = NULL;
    }
    if(keyQuery_orphanDependents){
        free(keyQuery_orphanDependents);
        keyQuery_orphanDependents = NULL;
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
    if(keyPairQuery_timeoutSeconds){
        keyValuePair_free(keyPairQuery_timeoutSeconds);
        keyPairQuery_timeoutSeconds = NULL;
    }
    if(keyQuery_watch){
        free(keyQuery_watch);
        keyQuery_watch = NULL;
    }
    if(keyPairQuery_watch){
        keyValuePair_free(keyPairQuery_watch);
        keyPairQuery_watch = NULL;
    }
    return elementToReturn;
end:
    return NULL;

}

// delete collection of Role
//
v1_status_t*
RbacAuthorizationV1API_deleteCollectionNamespacedRole(apiClient_t *apiClient, char * namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , int watch , v1_delete_options_t * body )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/roles")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/roles");


    // Path Params
    long sizeOfPathParams_namespace = strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



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
    int valueQuery_allowWatchBookmarks ;
    keyValuePair_t *keyPairQuery_allowWatchBookmarks = 0;
    if (allowWatchBookmarks)
    {
        keyQuery_allowWatchBookmarks = strdup("allowWatchBookmarks");
        valueQuery_allowWatchBookmarks = (allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = keyValuePair_create(keyQuery_allowWatchBookmarks, &valueQuery_allowWatchBookmarks);
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
    int valueQuery_gracePeriodSeconds ;
    keyValuePair_t *keyPairQuery_gracePeriodSeconds = 0;
    if (gracePeriodSeconds)
    {
        keyQuery_gracePeriodSeconds = strdup("gracePeriodSeconds");
        valueQuery_gracePeriodSeconds = (gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = keyValuePair_create(keyQuery_gracePeriodSeconds, &valueQuery_gracePeriodSeconds);
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
    int valueQuery_limit ;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = (limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, &valueQuery_limit);
        list_addElement(localVarQueryParameters,keyPairQuery_limit);
    }

    // query parameters
    char *keyQuery_orphanDependents = NULL;
    int valueQuery_orphanDependents ;
    keyValuePair_t *keyPairQuery_orphanDependents = 0;
    if (orphanDependents)
    {
        keyQuery_orphanDependents = strdup("orphanDependents");
        valueQuery_orphanDependents = (orphanDependents);
        keyPairQuery_orphanDependents = keyValuePair_create(keyQuery_orphanDependents, &valueQuery_orphanDependents);
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
    int valueQuery_timeoutSeconds ;
    keyValuePair_t *keyPairQuery_timeoutSeconds = 0;
    if (timeoutSeconds)
    {
        keyQuery_timeoutSeconds = strdup("timeoutSeconds");
        valueQuery_timeoutSeconds = (timeoutSeconds);
        keyPairQuery_timeoutSeconds = keyValuePair_create(keyQuery_timeoutSeconds, &valueQuery_timeoutSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_timeoutSeconds);
    }

    // query parameters
    char *keyQuery_watch = NULL;
    int valueQuery_watch ;
    keyValuePair_t *keyPairQuery_watch = 0;
    if (watch)
    {
        keyQuery_watch = strdup("watch");
        valueQuery_watch = (watch);
        keyPairQuery_watch = keyValuePair_create(keyQuery_watch, &valueQuery_watch);
        list_addElement(localVarQueryParameters,keyPairQuery_watch);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
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
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_status_t *elementToReturn = v1_status_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
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
    if(keyQuery_allowWatchBookmarks){
        free(keyQuery_allowWatchBookmarks);
        keyQuery_allowWatchBookmarks = NULL;
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
    if(keyPairQuery_limit){
        keyValuePair_free(keyPairQuery_limit);
        keyPairQuery_limit = NULL;
    }
    if(keyQuery_orphanDependents){
        free(keyQuery_orphanDependents);
        keyQuery_orphanDependents = NULL;
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
    if(keyPairQuery_timeoutSeconds){
        keyValuePair_free(keyPairQuery_timeoutSeconds);
        keyPairQuery_timeoutSeconds = NULL;
    }
    if(keyQuery_watch){
        free(keyQuery_watch);
        keyQuery_watch = NULL;
    }
    if(keyPairQuery_watch){
        keyValuePair_free(keyPairQuery_watch);
        keyPairQuery_watch = NULL;
    }
    return elementToReturn;
end:
    return NULL;

}

// delete collection of RoleBinding
//
v1_status_t*
RbacAuthorizationV1API_deleteCollectionNamespacedRoleBinding(apiClient_t *apiClient, char * namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , int watch , v1_delete_options_t * body )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/rolebindings")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/rolebindings");


    // Path Params
    long sizeOfPathParams_namespace = strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



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
    int valueQuery_allowWatchBookmarks ;
    keyValuePair_t *keyPairQuery_allowWatchBookmarks = 0;
    if (allowWatchBookmarks)
    {
        keyQuery_allowWatchBookmarks = strdup("allowWatchBookmarks");
        valueQuery_allowWatchBookmarks = (allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = keyValuePair_create(keyQuery_allowWatchBookmarks, &valueQuery_allowWatchBookmarks);
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
    int valueQuery_gracePeriodSeconds ;
    keyValuePair_t *keyPairQuery_gracePeriodSeconds = 0;
    if (gracePeriodSeconds)
    {
        keyQuery_gracePeriodSeconds = strdup("gracePeriodSeconds");
        valueQuery_gracePeriodSeconds = (gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = keyValuePair_create(keyQuery_gracePeriodSeconds, &valueQuery_gracePeriodSeconds);
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
    int valueQuery_limit ;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = (limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, &valueQuery_limit);
        list_addElement(localVarQueryParameters,keyPairQuery_limit);
    }

    // query parameters
    char *keyQuery_orphanDependents = NULL;
    int valueQuery_orphanDependents ;
    keyValuePair_t *keyPairQuery_orphanDependents = 0;
    if (orphanDependents)
    {
        keyQuery_orphanDependents = strdup("orphanDependents");
        valueQuery_orphanDependents = (orphanDependents);
        keyPairQuery_orphanDependents = keyValuePair_create(keyQuery_orphanDependents, &valueQuery_orphanDependents);
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
    int valueQuery_timeoutSeconds ;
    keyValuePair_t *keyPairQuery_timeoutSeconds = 0;
    if (timeoutSeconds)
    {
        keyQuery_timeoutSeconds = strdup("timeoutSeconds");
        valueQuery_timeoutSeconds = (timeoutSeconds);
        keyPairQuery_timeoutSeconds = keyValuePair_create(keyQuery_timeoutSeconds, &valueQuery_timeoutSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_timeoutSeconds);
    }

    // query parameters
    char *keyQuery_watch = NULL;
    int valueQuery_watch ;
    keyValuePair_t *keyPairQuery_watch = 0;
    if (watch)
    {
        keyQuery_watch = strdup("watch");
        valueQuery_watch = (watch);
        keyPairQuery_watch = keyValuePair_create(keyQuery_watch, &valueQuery_watch);
        list_addElement(localVarQueryParameters,keyPairQuery_watch);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
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
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_status_t *elementToReturn = v1_status_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
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
    if(keyQuery_allowWatchBookmarks){
        free(keyQuery_allowWatchBookmarks);
        keyQuery_allowWatchBookmarks = NULL;
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
    if(keyPairQuery_limit){
        keyValuePair_free(keyPairQuery_limit);
        keyPairQuery_limit = NULL;
    }
    if(keyQuery_orphanDependents){
        free(keyQuery_orphanDependents);
        keyQuery_orphanDependents = NULL;
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
    if(keyPairQuery_timeoutSeconds){
        keyValuePair_free(keyPairQuery_timeoutSeconds);
        keyPairQuery_timeoutSeconds = NULL;
    }
    if(keyQuery_watch){
        free(keyQuery_watch);
        keyQuery_watch = NULL;
    }
    if(keyPairQuery_watch){
        keyValuePair_free(keyPairQuery_watch);
        keyPairQuery_watch = NULL;
    }
    return elementToReturn;
end:
    return NULL;

}

// delete a Role
//
v1_status_t*
RbacAuthorizationV1API_deleteNamespacedRole(apiClient_t *apiClient, char * name , char * namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/roles/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/roles/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



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
    int valueQuery_gracePeriodSeconds ;
    keyValuePair_t *keyPairQuery_gracePeriodSeconds = 0;
    if (gracePeriodSeconds)
    {
        keyQuery_gracePeriodSeconds = strdup("gracePeriodSeconds");
        valueQuery_gracePeriodSeconds = (gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = keyValuePair_create(keyQuery_gracePeriodSeconds, &valueQuery_gracePeriodSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_gracePeriodSeconds);
    }

    // query parameters
    char *keyQuery_orphanDependents = NULL;
    int valueQuery_orphanDependents ;
    keyValuePair_t *keyPairQuery_orphanDependents = 0;
    if (orphanDependents)
    {
        keyQuery_orphanDependents = strdup("orphanDependents");
        valueQuery_orphanDependents = (orphanDependents);
        keyPairQuery_orphanDependents = keyValuePair_create(keyQuery_orphanDependents, &valueQuery_orphanDependents);
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
    cJSON *localVarSingleItemJSON_body;
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
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_status_t *elementToReturn = v1_status_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
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
    if(keyPairQuery_gracePeriodSeconds){
        keyValuePair_free(keyPairQuery_gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = NULL;
    }
    if(keyQuery_orphanDependents){
        free(keyQuery_orphanDependents);
        keyQuery_orphanDependents = NULL;
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
    return NULL;

}

// delete a RoleBinding
//
v1_status_t*
RbacAuthorizationV1API_deleteNamespacedRoleBinding(apiClient_t *apiClient, char * name , char * namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/rolebindings/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/rolebindings/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



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
    int valueQuery_gracePeriodSeconds ;
    keyValuePair_t *keyPairQuery_gracePeriodSeconds = 0;
    if (gracePeriodSeconds)
    {
        keyQuery_gracePeriodSeconds = strdup("gracePeriodSeconds");
        valueQuery_gracePeriodSeconds = (gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = keyValuePair_create(keyQuery_gracePeriodSeconds, &valueQuery_gracePeriodSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_gracePeriodSeconds);
    }

    // query parameters
    char *keyQuery_orphanDependents = NULL;
    int valueQuery_orphanDependents ;
    keyValuePair_t *keyPairQuery_orphanDependents = 0;
    if (orphanDependents)
    {
        keyQuery_orphanDependents = strdup("orphanDependents");
        valueQuery_orphanDependents = (orphanDependents);
        keyPairQuery_orphanDependents = keyValuePair_create(keyQuery_orphanDependents, &valueQuery_orphanDependents);
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
    cJSON *localVarSingleItemJSON_body;
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
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_status_t *elementToReturn = v1_status_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
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
    if(keyPairQuery_gracePeriodSeconds){
        keyValuePair_free(keyPairQuery_gracePeriodSeconds);
        keyPairQuery_gracePeriodSeconds = NULL;
    }
    if(keyQuery_orphanDependents){
        free(keyQuery_orphanDependents);
        keyQuery_orphanDependents = NULL;
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
    return NULL;

}

// get available resources
//
v1_api_resource_list_t*
RbacAuthorizationV1API_getAPIResources(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/");



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
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_api_resource_list_t *elementToReturn = v1_api_resource_list_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    return elementToReturn;
end:
    return NULL;

}

// list or watch objects of kind ClusterRole
//
v1_cluster_role_list_t*
RbacAuthorizationV1API_listClusterRole(apiClient_t *apiClient, char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/clusterroles")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/clusterroles");




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
    int valueQuery_allowWatchBookmarks ;
    keyValuePair_t *keyPairQuery_allowWatchBookmarks = 0;
    if (allowWatchBookmarks)
    {
        keyQuery_allowWatchBookmarks = strdup("allowWatchBookmarks");
        valueQuery_allowWatchBookmarks = (allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = keyValuePair_create(keyQuery_allowWatchBookmarks, &valueQuery_allowWatchBookmarks);
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
    int valueQuery_limit ;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = (limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, &valueQuery_limit);
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
    int valueQuery_timeoutSeconds ;
    keyValuePair_t *keyPairQuery_timeoutSeconds = 0;
    if (timeoutSeconds)
    {
        keyQuery_timeoutSeconds = strdup("timeoutSeconds");
        valueQuery_timeoutSeconds = (timeoutSeconds);
        keyPairQuery_timeoutSeconds = keyValuePair_create(keyQuery_timeoutSeconds, &valueQuery_timeoutSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_timeoutSeconds);
    }

    // query parameters
    char *keyQuery_watch = NULL;
    int valueQuery_watch ;
    keyValuePair_t *keyPairQuery_watch = 0;
    if (watch)
    {
        keyQuery_watch = strdup("watch");
        valueQuery_watch = (watch);
        keyPairQuery_watch = keyValuePair_create(keyQuery_watch, &valueQuery_watch);
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
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_cluster_role_list_t *elementToReturn = v1_cluster_role_list_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
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
    if(keyPairQuery_timeoutSeconds){
        keyValuePair_free(keyPairQuery_timeoutSeconds);
        keyPairQuery_timeoutSeconds = NULL;
    }
    if(keyQuery_watch){
        free(keyQuery_watch);
        keyQuery_watch = NULL;
    }
    if(keyPairQuery_watch){
        keyValuePair_free(keyPairQuery_watch);
        keyPairQuery_watch = NULL;
    }
    return elementToReturn;
end:
    return NULL;

}

// list or watch objects of kind ClusterRoleBinding
//
v1_cluster_role_binding_list_t*
RbacAuthorizationV1API_listClusterRoleBinding(apiClient_t *apiClient, char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/clusterrolebindings")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/clusterrolebindings");




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
    int valueQuery_allowWatchBookmarks ;
    keyValuePair_t *keyPairQuery_allowWatchBookmarks = 0;
    if (allowWatchBookmarks)
    {
        keyQuery_allowWatchBookmarks = strdup("allowWatchBookmarks");
        valueQuery_allowWatchBookmarks = (allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = keyValuePair_create(keyQuery_allowWatchBookmarks, &valueQuery_allowWatchBookmarks);
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
    int valueQuery_limit ;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = (limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, &valueQuery_limit);
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
    int valueQuery_timeoutSeconds ;
    keyValuePair_t *keyPairQuery_timeoutSeconds = 0;
    if (timeoutSeconds)
    {
        keyQuery_timeoutSeconds = strdup("timeoutSeconds");
        valueQuery_timeoutSeconds = (timeoutSeconds);
        keyPairQuery_timeoutSeconds = keyValuePair_create(keyQuery_timeoutSeconds, &valueQuery_timeoutSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_timeoutSeconds);
    }

    // query parameters
    char *keyQuery_watch = NULL;
    int valueQuery_watch ;
    keyValuePair_t *keyPairQuery_watch = 0;
    if (watch)
    {
        keyQuery_watch = strdup("watch");
        valueQuery_watch = (watch);
        keyPairQuery_watch = keyValuePair_create(keyQuery_watch, &valueQuery_watch);
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
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_cluster_role_binding_list_t *elementToReturn = v1_cluster_role_binding_list_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
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
    if(keyPairQuery_timeoutSeconds){
        keyValuePair_free(keyPairQuery_timeoutSeconds);
        keyPairQuery_timeoutSeconds = NULL;
    }
    if(keyQuery_watch){
        free(keyQuery_watch);
        keyQuery_watch = NULL;
    }
    if(keyPairQuery_watch){
        keyValuePair_free(keyPairQuery_watch);
        keyPairQuery_watch = NULL;
    }
    return elementToReturn;
end:
    return NULL;

}

// list or watch objects of kind Role
//
v1_role_list_t*
RbacAuthorizationV1API_listNamespacedRole(apiClient_t *apiClient, char * namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/roles")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/roles");


    // Path Params
    long sizeOfPathParams_namespace = strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



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
    int valueQuery_allowWatchBookmarks ;
    keyValuePair_t *keyPairQuery_allowWatchBookmarks = 0;
    if (allowWatchBookmarks)
    {
        keyQuery_allowWatchBookmarks = strdup("allowWatchBookmarks");
        valueQuery_allowWatchBookmarks = (allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = keyValuePair_create(keyQuery_allowWatchBookmarks, &valueQuery_allowWatchBookmarks);
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
    int valueQuery_limit ;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = (limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, &valueQuery_limit);
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
    int valueQuery_timeoutSeconds ;
    keyValuePair_t *keyPairQuery_timeoutSeconds = 0;
    if (timeoutSeconds)
    {
        keyQuery_timeoutSeconds = strdup("timeoutSeconds");
        valueQuery_timeoutSeconds = (timeoutSeconds);
        keyPairQuery_timeoutSeconds = keyValuePair_create(keyQuery_timeoutSeconds, &valueQuery_timeoutSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_timeoutSeconds);
    }

    // query parameters
    char *keyQuery_watch = NULL;
    int valueQuery_watch ;
    keyValuePair_t *keyPairQuery_watch = 0;
    if (watch)
    {
        keyQuery_watch = strdup("watch");
        valueQuery_watch = (watch);
        keyPairQuery_watch = keyValuePair_create(keyQuery_watch, &valueQuery_watch);
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
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_role_list_t *elementToReturn = v1_role_list_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_namespace);
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
    if(keyPairQuery_timeoutSeconds){
        keyValuePair_free(keyPairQuery_timeoutSeconds);
        keyPairQuery_timeoutSeconds = NULL;
    }
    if(keyQuery_watch){
        free(keyQuery_watch);
        keyQuery_watch = NULL;
    }
    if(keyPairQuery_watch){
        keyValuePair_free(keyPairQuery_watch);
        keyPairQuery_watch = NULL;
    }
    return elementToReturn;
end:
    return NULL;

}

// list or watch objects of kind RoleBinding
//
v1_role_binding_list_t*
RbacAuthorizationV1API_listNamespacedRoleBinding(apiClient_t *apiClient, char * namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/rolebindings")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/rolebindings");


    // Path Params
    long sizeOfPathParams_namespace = strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



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
    int valueQuery_allowWatchBookmarks ;
    keyValuePair_t *keyPairQuery_allowWatchBookmarks = 0;
    if (allowWatchBookmarks)
    {
        keyQuery_allowWatchBookmarks = strdup("allowWatchBookmarks");
        valueQuery_allowWatchBookmarks = (allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = keyValuePair_create(keyQuery_allowWatchBookmarks, &valueQuery_allowWatchBookmarks);
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
    int valueQuery_limit ;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = (limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, &valueQuery_limit);
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
    int valueQuery_timeoutSeconds ;
    keyValuePair_t *keyPairQuery_timeoutSeconds = 0;
    if (timeoutSeconds)
    {
        keyQuery_timeoutSeconds = strdup("timeoutSeconds");
        valueQuery_timeoutSeconds = (timeoutSeconds);
        keyPairQuery_timeoutSeconds = keyValuePair_create(keyQuery_timeoutSeconds, &valueQuery_timeoutSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_timeoutSeconds);
    }

    // query parameters
    char *keyQuery_watch = NULL;
    int valueQuery_watch ;
    keyValuePair_t *keyPairQuery_watch = 0;
    if (watch)
    {
        keyQuery_watch = strdup("watch");
        valueQuery_watch = (watch);
        keyPairQuery_watch = keyValuePair_create(keyQuery_watch, &valueQuery_watch);
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
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_role_binding_list_t *elementToReturn = v1_role_binding_list_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_namespace);
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
    if(keyPairQuery_timeoutSeconds){
        keyValuePair_free(keyPairQuery_timeoutSeconds);
        keyPairQuery_timeoutSeconds = NULL;
    }
    if(keyQuery_watch){
        free(keyQuery_watch);
        keyQuery_watch = NULL;
    }
    if(keyPairQuery_watch){
        keyValuePair_free(keyPairQuery_watch);
        keyPairQuery_watch = NULL;
    }
    return elementToReturn;
end:
    return NULL;

}

// list or watch objects of kind RoleBinding
//
v1_role_binding_list_t*
RbacAuthorizationV1API_listRoleBindingForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , int timeoutSeconds , int watch )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/rolebindings")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/rolebindings");




    // query parameters
    char *keyQuery_allowWatchBookmarks = NULL;
    int valueQuery_allowWatchBookmarks ;
    keyValuePair_t *keyPairQuery_allowWatchBookmarks = 0;
    if (allowWatchBookmarks)
    {
        keyQuery_allowWatchBookmarks = strdup("allowWatchBookmarks");
        valueQuery_allowWatchBookmarks = (allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = keyValuePair_create(keyQuery_allowWatchBookmarks, &valueQuery_allowWatchBookmarks);
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
    int valueQuery_limit ;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = (limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, &valueQuery_limit);
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
    int valueQuery_timeoutSeconds ;
    keyValuePair_t *keyPairQuery_timeoutSeconds = 0;
    if (timeoutSeconds)
    {
        keyQuery_timeoutSeconds = strdup("timeoutSeconds");
        valueQuery_timeoutSeconds = (timeoutSeconds);
        keyPairQuery_timeoutSeconds = keyValuePair_create(keyQuery_timeoutSeconds, &valueQuery_timeoutSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_timeoutSeconds);
    }

    // query parameters
    char *keyQuery_watch = NULL;
    int valueQuery_watch ;
    keyValuePair_t *keyPairQuery_watch = 0;
    if (watch)
    {
        keyQuery_watch = strdup("watch");
        valueQuery_watch = (watch);
        keyPairQuery_watch = keyValuePair_create(keyQuery_watch, &valueQuery_watch);
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
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_role_binding_list_t *elementToReturn = v1_role_binding_list_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    if(keyQuery_allowWatchBookmarks){
        free(keyQuery_allowWatchBookmarks);
        keyQuery_allowWatchBookmarks = NULL;
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
    if(keyPairQuery_timeoutSeconds){
        keyValuePair_free(keyPairQuery_timeoutSeconds);
        keyPairQuery_timeoutSeconds = NULL;
    }
    if(keyQuery_watch){
        free(keyQuery_watch);
        keyQuery_watch = NULL;
    }
    if(keyPairQuery_watch){
        keyValuePair_free(keyPairQuery_watch);
        keyPairQuery_watch = NULL;
    }
    return elementToReturn;
end:
    return NULL;

}

// list or watch objects of kind Role
//
v1_role_list_t*
RbacAuthorizationV1API_listRoleForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , int timeoutSeconds , int watch )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/roles")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/roles");




    // query parameters
    char *keyQuery_allowWatchBookmarks = NULL;
    int valueQuery_allowWatchBookmarks ;
    keyValuePair_t *keyPairQuery_allowWatchBookmarks = 0;
    if (allowWatchBookmarks)
    {
        keyQuery_allowWatchBookmarks = strdup("allowWatchBookmarks");
        valueQuery_allowWatchBookmarks = (allowWatchBookmarks);
        keyPairQuery_allowWatchBookmarks = keyValuePair_create(keyQuery_allowWatchBookmarks, &valueQuery_allowWatchBookmarks);
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
    int valueQuery_limit ;
    keyValuePair_t *keyPairQuery_limit = 0;
    if (limit)
    {
        keyQuery_limit = strdup("limit");
        valueQuery_limit = (limit);
        keyPairQuery_limit = keyValuePair_create(keyQuery_limit, &valueQuery_limit);
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
    int valueQuery_timeoutSeconds ;
    keyValuePair_t *keyPairQuery_timeoutSeconds = 0;
    if (timeoutSeconds)
    {
        keyQuery_timeoutSeconds = strdup("timeoutSeconds");
        valueQuery_timeoutSeconds = (timeoutSeconds);
        keyPairQuery_timeoutSeconds = keyValuePair_create(keyQuery_timeoutSeconds, &valueQuery_timeoutSeconds);
        list_addElement(localVarQueryParameters,keyPairQuery_timeoutSeconds);
    }

    // query parameters
    char *keyQuery_watch = NULL;
    int valueQuery_watch ;
    keyValuePair_t *keyPairQuery_watch = 0;
    if (watch)
    {
        keyQuery_watch = strdup("watch");
        valueQuery_watch = (watch);
        keyPairQuery_watch = keyValuePair_create(keyQuery_watch, &valueQuery_watch);
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
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_role_list_t *elementToReturn = v1_role_list_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    if(keyQuery_allowWatchBookmarks){
        free(keyQuery_allowWatchBookmarks);
        keyQuery_allowWatchBookmarks = NULL;
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
    if(keyPairQuery_timeoutSeconds){
        keyValuePair_free(keyPairQuery_timeoutSeconds);
        keyPairQuery_timeoutSeconds = NULL;
    }
    if(keyQuery_watch){
        free(keyQuery_watch);
        keyQuery_watch = NULL;
    }
    if(keyPairQuery_watch){
        keyValuePair_free(keyPairQuery_watch);
        keyPairQuery_watch = NULL;
    }
    return elementToReturn;
end:
    return NULL;

}

// partially update the specified ClusterRole
//
v1_cluster_role_t*
RbacAuthorizationV1API_patchClusterRole(apiClient_t *apiClient, char * name , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/clusterroles/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/clusterroles/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



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
    int valueQuery_force ;
    keyValuePair_t *keyPairQuery_force = 0;
    if (force)
    {
        keyQuery_force = strdup("force");
        valueQuery_force = (force);
        keyPairQuery_force = keyValuePair_create(keyQuery_force, &valueQuery_force);
        list_addElement(localVarQueryParameters,keyPairQuery_force);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
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
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_cluster_role_t *elementToReturn = v1_cluster_role_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    list_free(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_name);
    cJSON_Delete(localVarSingleItemJSON_body);
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
    if(keyPairQuery_force){
        keyValuePair_free(keyPairQuery_force);
        keyPairQuery_force = NULL;
    }
    return elementToReturn;
end:
    return NULL;

}

// partially update the specified ClusterRoleBinding
//
v1_cluster_role_binding_t*
RbacAuthorizationV1API_patchClusterRoleBinding(apiClient_t *apiClient, char * name , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/clusterrolebindings/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/clusterrolebindings/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



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
    int valueQuery_force ;
    keyValuePair_t *keyPairQuery_force = 0;
    if (force)
    {
        keyQuery_force = strdup("force");
        valueQuery_force = (force);
        keyPairQuery_force = keyValuePair_create(keyQuery_force, &valueQuery_force);
        list_addElement(localVarQueryParameters,keyPairQuery_force);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
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
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_cluster_role_binding_t *elementToReturn = v1_cluster_role_binding_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    list_free(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_name);
    cJSON_Delete(localVarSingleItemJSON_body);
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
    if(keyPairQuery_force){
        keyValuePair_free(keyPairQuery_force);
        keyPairQuery_force = NULL;
    }
    return elementToReturn;
end:
    return NULL;

}

// partially update the specified Role
//
v1_role_t*
RbacAuthorizationV1API_patchNamespacedRole(apiClient_t *apiClient, char * name , char * namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/roles/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/roles/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



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
    int valueQuery_force ;
    keyValuePair_t *keyPairQuery_force = 0;
    if (force)
    {
        keyQuery_force = strdup("force");
        valueQuery_force = (force);
        keyPairQuery_force = keyValuePair_create(keyQuery_force, &valueQuery_force);
        list_addElement(localVarQueryParameters,keyPairQuery_force);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
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
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_role_t *elementToReturn = v1_role_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    list_free(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
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
    if(keyPairQuery_force){
        keyValuePair_free(keyPairQuery_force);
        keyPairQuery_force = NULL;
    }
    return elementToReturn;
end:
    return NULL;

}

// partially update the specified RoleBinding
//
v1_role_binding_t*
RbacAuthorizationV1API_patchNamespacedRoleBinding(apiClient_t *apiClient, char * name , char * namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/rolebindings/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/rolebindings/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



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
    int valueQuery_force ;
    keyValuePair_t *keyPairQuery_force = 0;
    if (force)
    {
        keyQuery_force = strdup("force");
        valueQuery_force = (force);
        keyPairQuery_force = keyValuePair_create(keyQuery_force, &valueQuery_force);
        list_addElement(localVarQueryParameters,keyPairQuery_force);
    }

    // Body Param
    cJSON *localVarSingleItemJSON_body;
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
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_role_binding_t *elementToReturn = v1_role_binding_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    list_free(localVarContentType);
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
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
    if(keyPairQuery_force){
        keyValuePair_free(keyPairQuery_force);
        keyPairQuery_force = NULL;
    }
    return elementToReturn;
end:
    return NULL;

}

// read the specified ClusterRole
//
v1_cluster_role_t*
RbacAuthorizationV1API_readClusterRole(apiClient_t *apiClient, char * name , char * pretty )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/clusterroles/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/clusterroles/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



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
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_cluster_role_t *elementToReturn = v1_cluster_role_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_name);
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
    return NULL;

}

// read the specified ClusterRoleBinding
//
v1_cluster_role_binding_t*
RbacAuthorizationV1API_readClusterRoleBinding(apiClient_t *apiClient, char * name , char * pretty )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/clusterrolebindings/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/clusterrolebindings/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



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
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_cluster_role_binding_t *elementToReturn = v1_cluster_role_binding_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_name);
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
    return NULL;

}

// read the specified Role
//
v1_role_t*
RbacAuthorizationV1API_readNamespacedRole(apiClient_t *apiClient, char * name , char * namespace , char * pretty )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/roles/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/roles/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



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
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_role_t *elementToReturn = v1_role_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
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
    return NULL;

}

// read the specified RoleBinding
//
v1_role_binding_t*
RbacAuthorizationV1API_readNamespacedRoleBinding(apiClient_t *apiClient, char * name , char * namespace , char * pretty )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/rolebindings/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/rolebindings/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



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
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_role_binding_t *elementToReturn = v1_role_binding_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
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
    return NULL;

}

// replace the specified ClusterRole
//
v1_cluster_role_t*
RbacAuthorizationV1API_replaceClusterRole(apiClient_t *apiClient, char * name , v1_cluster_role_t * body , char * pretty , char * dryRun , char * fieldManager )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/clusterroles/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/clusterroles/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



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
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_cluster_role_convertToJSON(body);
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
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_cluster_role_t *elementToReturn = v1_cluster_role_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_name);
    cJSON_Delete(localVarSingleItemJSON_body);
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
    return NULL;

}

// replace the specified ClusterRoleBinding
//
v1_cluster_role_binding_t*
RbacAuthorizationV1API_replaceClusterRoleBinding(apiClient_t *apiClient, char * name , v1_cluster_role_binding_t * body , char * pretty , char * dryRun , char * fieldManager )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/clusterrolebindings/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/clusterrolebindings/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);



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
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_cluster_role_binding_convertToJSON(body);
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
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_cluster_role_binding_t *elementToReturn = v1_cluster_role_binding_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_name);
    cJSON_Delete(localVarSingleItemJSON_body);
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
    return NULL;

}

// replace the specified Role
//
v1_role_t*
RbacAuthorizationV1API_replaceNamespacedRole(apiClient_t *apiClient, char * name , char * namespace , v1_role_t * body , char * pretty , char * dryRun , char * fieldManager )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/roles/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/roles/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



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
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_role_convertToJSON(body);
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
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_role_t *elementToReturn = v1_role_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
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
    return NULL;

}

// replace the specified RoleBinding
//
v1_role_binding_t*
RbacAuthorizationV1API_replaceNamespacedRoleBinding(apiClient_t *apiClient, char * name , char * namespace , v1_role_binding_t * body , char * pretty , char * dryRun , char * fieldManager )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/rolebindings/{name}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apis/rbac.authorization.k8s.io/v1/namespaces/{namespace}/rolebindings/{name}");


    // Path Params
    long sizeOfPathParams_name = strlen(name)+3 + strlen(namespace)+3 + strlen("{ name }");
    if(name == NULL) {
        goto end;
    }
    char* localVarToReplace_name = malloc(sizeOfPathParams_name);
    sprintf(localVarToReplace_name, "{%s}", "name");

    localVarPath = strReplace(localVarPath, localVarToReplace_name, name);

    // Path Params
    long sizeOfPathParams_namespace = strlen(name)+3 + strlen(namespace)+3 + strlen("{ namespace }");
    if(namespace == NULL) {
        goto end;
    }
    char* localVarToReplace_namespace = malloc(sizeOfPathParams_namespace);
    sprintf(localVarToReplace_namespace, "{%s}", "namespace");

    localVarPath = strReplace(localVarPath, localVarToReplace_namespace, namespace);



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
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = v1_role_binding_convertToJSON(body);
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
    cJSON *RbacAuthorizationV1APIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    v1_role_binding_t *elementToReturn = v1_role_binding_parseFromJSON(RbacAuthorizationV1APIlocalVarJSON);
    cJSON_Delete(RbacAuthorizationV1APIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_name);
    free(localVarToReplace_namespace);
    cJSON_Delete(localVarSingleItemJSON_body);
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
    return NULL;

}

