#ifndef v1_mutating_webhook_configuration_TEST
#define v1_mutating_webhook_configuration_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_mutating_webhook_configuration_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_mutating_webhook_configuration.h"
v1_mutating_webhook_configuration_t* instantiate_v1_mutating_webhook_configuration(int include_optional);

#include "test_v1_object_meta.c"


v1_mutating_webhook_configuration_t* instantiate_v1_mutating_webhook_configuration(int include_optional) {
  v1_mutating_webhook_configuration_t* v1_mutating_webhook_configuration = NULL;
  if (include_optional) {
    v1_mutating_webhook_configuration = v1_mutating_webhook_configuration_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
      list_create()
    );
  } else {
    v1_mutating_webhook_configuration = v1_mutating_webhook_configuration_create(
      "0",
      "0",
      NULL,
      list_create()
    );
  }

  return v1_mutating_webhook_configuration;
}


#ifdef v1_mutating_webhook_configuration_MAIN

void test_v1_mutating_webhook_configuration(int include_optional) {
    v1_mutating_webhook_configuration_t* v1_mutating_webhook_configuration_1 = instantiate_v1_mutating_webhook_configuration(include_optional);

	cJSON* jsonv1_mutating_webhook_configuration_1 = v1_mutating_webhook_configuration_convertToJSON(v1_mutating_webhook_configuration_1);
	printf("v1_mutating_webhook_configuration :\n%s\n", cJSON_Print(jsonv1_mutating_webhook_configuration_1));
	v1_mutating_webhook_configuration_t* v1_mutating_webhook_configuration_2 = v1_mutating_webhook_configuration_parseFromJSON(jsonv1_mutating_webhook_configuration_1);
	cJSON* jsonv1_mutating_webhook_configuration_2 = v1_mutating_webhook_configuration_convertToJSON(v1_mutating_webhook_configuration_2);
	printf("repeating v1_mutating_webhook_configuration:\n%s\n", cJSON_Print(jsonv1_mutating_webhook_configuration_2));
}

int main() {
  test_v1_mutating_webhook_configuration(1);
  test_v1_mutating_webhook_configuration(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_mutating_webhook_configuration_MAIN
#endif // v1_mutating_webhook_configuration_TEST
