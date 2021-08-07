#ifndef apiregistration_v1_service_reference_TEST
#define apiregistration_v1_service_reference_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define apiregistration_v1_service_reference_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/apiregistration_v1_service_reference.h"
apiregistration_v1_service_reference_t* instantiate_apiregistration_v1_service_reference(int include_optional);



apiregistration_v1_service_reference_t* instantiate_apiregistration_v1_service_reference(int include_optional) {
  apiregistration_v1_service_reference_t* apiregistration_v1_service_reference = NULL;
  if (include_optional) {
    apiregistration_v1_service_reference = apiregistration_v1_service_reference_create(
      "0",
      "0",
      56
    );
  } else {
    apiregistration_v1_service_reference = apiregistration_v1_service_reference_create(
      "0",
      "0",
      56
    );
  }

  return apiregistration_v1_service_reference;
}


#ifdef apiregistration_v1_service_reference_MAIN

void test_apiregistration_v1_service_reference(int include_optional) {
    apiregistration_v1_service_reference_t* apiregistration_v1_service_reference_1 = instantiate_apiregistration_v1_service_reference(include_optional);

	cJSON* jsonapiregistration_v1_service_reference_1 = apiregistration_v1_service_reference_convertToJSON(apiregistration_v1_service_reference_1);
	printf("apiregistration_v1_service_reference :\n%s\n", cJSON_Print(jsonapiregistration_v1_service_reference_1));
	apiregistration_v1_service_reference_t* apiregistration_v1_service_reference_2 = apiregistration_v1_service_reference_parseFromJSON(jsonapiregistration_v1_service_reference_1);
	cJSON* jsonapiregistration_v1_service_reference_2 = apiregistration_v1_service_reference_convertToJSON(apiregistration_v1_service_reference_2);
	printf("repeating apiregistration_v1_service_reference:\n%s\n", cJSON_Print(jsonapiregistration_v1_service_reference_2));
}

int main() {
  test_apiregistration_v1_service_reference(1);
  test_apiregistration_v1_service_reference(0);

  printf("Hello world \n");
  return 0;
}

#endif // apiregistration_v1_service_reference_MAIN
#endif // apiregistration_v1_service_reference_TEST
