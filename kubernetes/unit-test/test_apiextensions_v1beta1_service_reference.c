#ifndef apiextensions_v1beta1_service_reference_TEST
#define apiextensions_v1beta1_service_reference_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define apiextensions_v1beta1_service_reference_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/apiextensions_v1beta1_service_reference.h"
apiextensions_v1beta1_service_reference_t* instantiate_apiextensions_v1beta1_service_reference(int include_optional);



apiextensions_v1beta1_service_reference_t* instantiate_apiextensions_v1beta1_service_reference(int include_optional) {
  apiextensions_v1beta1_service_reference_t* apiextensions_v1beta1_service_reference = NULL;
  if (include_optional) {
    apiextensions_v1beta1_service_reference = apiextensions_v1beta1_service_reference_create(
      "0",
      "0",
      "0",
      56
    );
  } else {
    apiextensions_v1beta1_service_reference = apiextensions_v1beta1_service_reference_create(
      "0",
      "0",
      "0",
      56
    );
  }

  return apiextensions_v1beta1_service_reference;
}


#ifdef apiextensions_v1beta1_service_reference_MAIN

void test_apiextensions_v1beta1_service_reference(int include_optional) {
    apiextensions_v1beta1_service_reference_t* apiextensions_v1beta1_service_reference_1 = instantiate_apiextensions_v1beta1_service_reference(include_optional);

	cJSON* jsonapiextensions_v1beta1_service_reference_1 = apiextensions_v1beta1_service_reference_convertToJSON(apiextensions_v1beta1_service_reference_1);
	printf("apiextensions_v1beta1_service_reference :\n%s\n", cJSON_Print(jsonapiextensions_v1beta1_service_reference_1));
	apiextensions_v1beta1_service_reference_t* apiextensions_v1beta1_service_reference_2 = apiextensions_v1beta1_service_reference_parseFromJSON(jsonapiextensions_v1beta1_service_reference_1);
	cJSON* jsonapiextensions_v1beta1_service_reference_2 = apiextensions_v1beta1_service_reference_convertToJSON(apiextensions_v1beta1_service_reference_2);
	printf("repeating apiextensions_v1beta1_service_reference:\n%s\n", cJSON_Print(jsonapiextensions_v1beta1_service_reference_2));
}

int main() {
  test_apiextensions_v1beta1_service_reference(1);
  test_apiextensions_v1beta1_service_reference(0);

  printf("Hello world \n");
  return 0;
}

#endif // apiextensions_v1beta1_service_reference_MAIN
#endif // apiextensions_v1beta1_service_reference_TEST
