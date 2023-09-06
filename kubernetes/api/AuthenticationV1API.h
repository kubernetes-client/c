#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1_self_subject_review.h"
#include "../model/v1_token_review.h"


// create a SelfSubjectReview
//
v1_self_subject_review_t*
AuthenticationV1API_createSelfSubjectReview(apiClient_t *apiClient, v1_self_subject_review_t * body , char * dryRun , char * fieldManager , char * fieldValidation , char * pretty );


// create a TokenReview
//
v1_token_review_t*
AuthenticationV1API_createTokenReview(apiClient_t *apiClient, v1_token_review_t * body , char * dryRun , char * fieldManager , char * fieldValidation , char * pretty );


// get available resources
//
v1_api_resource_list_t*
AuthenticationV1API_getAPIResources(apiClient_t *apiClient);


