#ifndef v1_deployment_TEST
#define v1_deployment_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_deployment_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_deployment.h"
v1_deployment_t* instantiate_v1_deployment(int include_optional);

#include "test_v1_object_meta.c"
#include "test_v1_deployment_spec.c"
#include "test_v1_deployment_status.c"


v1_deployment_t* instantiate_v1_deployment(int include_optional) {
  v1_deployment_t* v1_deployment = NULL;
  if (include_optional) {
    v1_deployment = v1_deployment_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
       // false, not to have infinite recursion
      instantiate_v1_deployment_spec(0),
       // false, not to have infinite recursion
      instantiate_v1_deployment_status(0)
    );
  } else {
    v1_deployment = v1_deployment_create(
      "0",
      "0",
      NULL,
      NULL,
      NULL
    );
  }

  return v1_deployment;
}


#ifdef v1_deployment_MAIN

void test_v1_deployment(int include_optional) {
    v1_deployment_t* v1_deployment_1 = instantiate_v1_deployment(include_optional);

	cJSON* jsonv1_deployment_1 = v1_deployment_convertToJSON(v1_deployment_1);
	printf("v1_deployment :\n%s\n", cJSON_Print(jsonv1_deployment_1));
	v1_deployment_t* v1_deployment_2 = v1_deployment_parseFromJSON(jsonv1_deployment_1);
	cJSON* jsonv1_deployment_2 = v1_deployment_convertToJSON(v1_deployment_2);
	printf("repeating v1_deployment:\n%s\n", cJSON_Print(jsonv1_deployment_2));
}

int main() {
  test_v1_deployment(1);
  test_v1_deployment(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_deployment_MAIN
#endif // v1_deployment_TEST
