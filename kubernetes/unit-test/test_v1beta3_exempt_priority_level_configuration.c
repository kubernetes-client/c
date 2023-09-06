#ifndef v1beta3_exempt_priority_level_configuration_TEST
#define v1beta3_exempt_priority_level_configuration_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta3_exempt_priority_level_configuration_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta3_exempt_priority_level_configuration.h"
v1beta3_exempt_priority_level_configuration_t* instantiate_v1beta3_exempt_priority_level_configuration(int include_optional);



v1beta3_exempt_priority_level_configuration_t* instantiate_v1beta3_exempt_priority_level_configuration(int include_optional) {
  v1beta3_exempt_priority_level_configuration_t* v1beta3_exempt_priority_level_configuration = NULL;
  if (include_optional) {
    v1beta3_exempt_priority_level_configuration = v1beta3_exempt_priority_level_configuration_create(
      56,
      56
    );
  } else {
    v1beta3_exempt_priority_level_configuration = v1beta3_exempt_priority_level_configuration_create(
      56,
      56
    );
  }

  return v1beta3_exempt_priority_level_configuration;
}


#ifdef v1beta3_exempt_priority_level_configuration_MAIN

void test_v1beta3_exempt_priority_level_configuration(int include_optional) {
    v1beta3_exempt_priority_level_configuration_t* v1beta3_exempt_priority_level_configuration_1 = instantiate_v1beta3_exempt_priority_level_configuration(include_optional);

	cJSON* jsonv1beta3_exempt_priority_level_configuration_1 = v1beta3_exempt_priority_level_configuration_convertToJSON(v1beta3_exempt_priority_level_configuration_1);
	printf("v1beta3_exempt_priority_level_configuration :\n%s\n", cJSON_Print(jsonv1beta3_exempt_priority_level_configuration_1));
	v1beta3_exempt_priority_level_configuration_t* v1beta3_exempt_priority_level_configuration_2 = v1beta3_exempt_priority_level_configuration_parseFromJSON(jsonv1beta3_exempt_priority_level_configuration_1);
	cJSON* jsonv1beta3_exempt_priority_level_configuration_2 = v1beta3_exempt_priority_level_configuration_convertToJSON(v1beta3_exempt_priority_level_configuration_2);
	printf("repeating v1beta3_exempt_priority_level_configuration:\n%s\n", cJSON_Print(jsonv1beta3_exempt_priority_level_configuration_2));
}

int main() {
  test_v1beta3_exempt_priority_level_configuration(1);
  test_v1beta3_exempt_priority_level_configuration(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta3_exempt_priority_level_configuration_MAIN
#endif // v1beta3_exempt_priority_level_configuration_TEST
