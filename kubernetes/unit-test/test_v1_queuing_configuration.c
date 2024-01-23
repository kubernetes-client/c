#ifndef v1_queuing_configuration_TEST
#define v1_queuing_configuration_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_queuing_configuration_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_queuing_configuration.h"
v1_queuing_configuration_t* instantiate_v1_queuing_configuration(int include_optional);



v1_queuing_configuration_t* instantiate_v1_queuing_configuration(int include_optional) {
  v1_queuing_configuration_t* v1_queuing_configuration = NULL;
  if (include_optional) {
    v1_queuing_configuration = v1_queuing_configuration_create(
      56,
      56,
      56
    );
  } else {
    v1_queuing_configuration = v1_queuing_configuration_create(
      56,
      56,
      56
    );
  }

  return v1_queuing_configuration;
}


#ifdef v1_queuing_configuration_MAIN

void test_v1_queuing_configuration(int include_optional) {
    v1_queuing_configuration_t* v1_queuing_configuration_1 = instantiate_v1_queuing_configuration(include_optional);

	cJSON* jsonv1_queuing_configuration_1 = v1_queuing_configuration_convertToJSON(v1_queuing_configuration_1);
	printf("v1_queuing_configuration :\n%s\n", cJSON_Print(jsonv1_queuing_configuration_1));
	v1_queuing_configuration_t* v1_queuing_configuration_2 = v1_queuing_configuration_parseFromJSON(jsonv1_queuing_configuration_1);
	cJSON* jsonv1_queuing_configuration_2 = v1_queuing_configuration_convertToJSON(v1_queuing_configuration_2);
	printf("repeating v1_queuing_configuration:\n%s\n", cJSON_Print(jsonv1_queuing_configuration_2));
}

int main() {
  test_v1_queuing_configuration(1);
  test_v1_queuing_configuration(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_queuing_configuration_MAIN
#endif // v1_queuing_configuration_TEST
