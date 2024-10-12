#ifndef v1_resource_health_TEST
#define v1_resource_health_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_resource_health_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_resource_health.h"
v1_resource_health_t* instantiate_v1_resource_health(int include_optional);



v1_resource_health_t* instantiate_v1_resource_health(int include_optional) {
  v1_resource_health_t* v1_resource_health = NULL;
  if (include_optional) {
    v1_resource_health = v1_resource_health_create(
      "0",
      "0"
    );
  } else {
    v1_resource_health = v1_resource_health_create(
      "0",
      "0"
    );
  }

  return v1_resource_health;
}


#ifdef v1_resource_health_MAIN

void test_v1_resource_health(int include_optional) {
    v1_resource_health_t* v1_resource_health_1 = instantiate_v1_resource_health(include_optional);

	cJSON* jsonv1_resource_health_1 = v1_resource_health_convertToJSON(v1_resource_health_1);
	printf("v1_resource_health :\n%s\n", cJSON_Print(jsonv1_resource_health_1));
	v1_resource_health_t* v1_resource_health_2 = v1_resource_health_parseFromJSON(jsonv1_resource_health_1);
	cJSON* jsonv1_resource_health_2 = v1_resource_health_convertToJSON(v1_resource_health_2);
	printf("repeating v1_resource_health:\n%s\n", cJSON_Print(jsonv1_resource_health_2));
}

int main() {
  test_v1_resource_health(1);
  test_v1_resource_health(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_resource_health_MAIN
#endif // v1_resource_health_TEST
