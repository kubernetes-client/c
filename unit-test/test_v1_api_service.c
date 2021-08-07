#ifndef v1_api_service_TEST
#define v1_api_service_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_api_service_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_api_service.h"
v1_api_service_t* instantiate_v1_api_service(int include_optional);

#include "test_v1_object_meta.c"
#include "test_v1_api_service_spec.c"
#include "test_v1_api_service_status.c"


v1_api_service_t* instantiate_v1_api_service(int include_optional) {
  v1_api_service_t* v1_api_service = NULL;
  if (include_optional) {
    v1_api_service = v1_api_service_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
       // false, not to have infinite recursion
      instantiate_v1_api_service_spec(0),
       // false, not to have infinite recursion
      instantiate_v1_api_service_status(0)
    );
  } else {
    v1_api_service = v1_api_service_create(
      "0",
      "0",
      NULL,
      NULL,
      NULL
    );
  }

  return v1_api_service;
}


#ifdef v1_api_service_MAIN

void test_v1_api_service(int include_optional) {
    v1_api_service_t* v1_api_service_1 = instantiate_v1_api_service(include_optional);

	cJSON* jsonv1_api_service_1 = v1_api_service_convertToJSON(v1_api_service_1);
	printf("v1_api_service :\n%s\n", cJSON_Print(jsonv1_api_service_1));
	v1_api_service_t* v1_api_service_2 = v1_api_service_parseFromJSON(jsonv1_api_service_1);
	cJSON* jsonv1_api_service_2 = v1_api_service_convertToJSON(v1_api_service_2);
	printf("repeating v1_api_service:\n%s\n", cJSON_Print(jsonv1_api_service_2));
}

int main() {
  test_v1_api_service(1);
  test_v1_api_service(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_api_service_MAIN
#endif // v1_api_service_TEST
