#ifndef v1_device_claim_configuration_TEST
#define v1_device_claim_configuration_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_device_claim_configuration_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_device_claim_configuration.h"
v1_device_claim_configuration_t* instantiate_v1_device_claim_configuration(int include_optional);

#include "test_v1_opaque_device_configuration.c"


v1_device_claim_configuration_t* instantiate_v1_device_claim_configuration(int include_optional) {
  v1_device_claim_configuration_t* v1_device_claim_configuration = NULL;
  if (include_optional) {
    v1_device_claim_configuration = v1_device_claim_configuration_create(
       // false, not to have infinite recursion
      instantiate_v1_opaque_device_configuration(0),
      list_createList()
    );
  } else {
    v1_device_claim_configuration = v1_device_claim_configuration_create(
      NULL,
      list_createList()
    );
  }

  return v1_device_claim_configuration;
}


#ifdef v1_device_claim_configuration_MAIN

void test_v1_device_claim_configuration(int include_optional) {
    v1_device_claim_configuration_t* v1_device_claim_configuration_1 = instantiate_v1_device_claim_configuration(include_optional);

	cJSON* jsonv1_device_claim_configuration_1 = v1_device_claim_configuration_convertToJSON(v1_device_claim_configuration_1);
	printf("v1_device_claim_configuration :\n%s\n", cJSON_Print(jsonv1_device_claim_configuration_1));
	v1_device_claim_configuration_t* v1_device_claim_configuration_2 = v1_device_claim_configuration_parseFromJSON(jsonv1_device_claim_configuration_1);
	cJSON* jsonv1_device_claim_configuration_2 = v1_device_claim_configuration_convertToJSON(v1_device_claim_configuration_2);
	printf("repeating v1_device_claim_configuration:\n%s\n", cJSON_Print(jsonv1_device_claim_configuration_2));
}

int main() {
  test_v1_device_claim_configuration(1);
  test_v1_device_claim_configuration(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_device_claim_configuration_MAIN
#endif // v1_device_claim_configuration_TEST
