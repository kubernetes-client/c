#ifndef apiextensions_v1beta1_webhook_client_config_TEST
#define apiextensions_v1beta1_webhook_client_config_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define apiextensions_v1beta1_webhook_client_config_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/apiextensions_v1beta1_webhook_client_config.h"
apiextensions_v1beta1_webhook_client_config_t* instantiate_apiextensions_v1beta1_webhook_client_config(int include_optional);

#include "test_apiextensions_v1beta1_service_reference.c"


apiextensions_v1beta1_webhook_client_config_t* instantiate_apiextensions_v1beta1_webhook_client_config(int include_optional) {
  apiextensions_v1beta1_webhook_client_config_t* apiextensions_v1beta1_webhook_client_config = NULL;
  if (include_optional) {
    apiextensions_v1beta1_webhook_client_config = apiextensions_v1beta1_webhook_client_config_create(
      "YQ==",
       // false, not to have infinite recursion
      instantiate_apiextensions_v1beta1_service_reference(0),
      "0"
    );
  } else {
    apiextensions_v1beta1_webhook_client_config = apiextensions_v1beta1_webhook_client_config_create(
      "YQ==",
      NULL,
      "0"
    );
  }

  return apiextensions_v1beta1_webhook_client_config;
}


#ifdef apiextensions_v1beta1_webhook_client_config_MAIN

void test_apiextensions_v1beta1_webhook_client_config(int include_optional) {
    apiextensions_v1beta1_webhook_client_config_t* apiextensions_v1beta1_webhook_client_config_1 = instantiate_apiextensions_v1beta1_webhook_client_config(include_optional);

	cJSON* jsonapiextensions_v1beta1_webhook_client_config_1 = apiextensions_v1beta1_webhook_client_config_convertToJSON(apiextensions_v1beta1_webhook_client_config_1);
	printf("apiextensions_v1beta1_webhook_client_config :\n%s\n", cJSON_Print(jsonapiextensions_v1beta1_webhook_client_config_1));
	apiextensions_v1beta1_webhook_client_config_t* apiextensions_v1beta1_webhook_client_config_2 = apiextensions_v1beta1_webhook_client_config_parseFromJSON(jsonapiextensions_v1beta1_webhook_client_config_1);
	cJSON* jsonapiextensions_v1beta1_webhook_client_config_2 = apiextensions_v1beta1_webhook_client_config_convertToJSON(apiextensions_v1beta1_webhook_client_config_2);
	printf("repeating apiextensions_v1beta1_webhook_client_config:\n%s\n", cJSON_Print(jsonapiextensions_v1beta1_webhook_client_config_2));
}

int main() {
  test_apiextensions_v1beta1_webhook_client_config(1);
  test_apiextensions_v1beta1_webhook_client_config(0);

  printf("Hello world \n");
  return 0;
}

#endif // apiextensions_v1beta1_webhook_client_config_MAIN
#endif // apiextensions_v1beta1_webhook_client_config_TEST
