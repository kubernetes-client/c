#ifndef v1_storage_health_TEST
#define v1_storage_health_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_storage_health_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_storage_health.h"
v1_storage_health_t* instantiate_v1_storage_health(int include_optional);



v1_storage_health_t* instantiate_v1_storage_health(int include_optional) {
  v1_storage_health_t* v1_storage_health = NULL;
  if (include_optional) {
    v1_storage_health = v1_storage_health_create(
      list_createList(),
      "0"
    );
  } else {
    v1_storage_health = v1_storage_health_create(
      list_createList(),
      "0"
    );
  }

  return v1_storage_health;
}


#ifdef v1_storage_health_MAIN

void test_v1_storage_health(int include_optional) {
    v1_storage_health_t* v1_storage_health_1 = instantiate_v1_storage_health(include_optional);

	cJSON* jsonv1_storage_health_1 = v1_storage_health_convertToJSON(v1_storage_health_1);
	printf("v1_storage_health :\n%s\n", cJSON_Print(jsonv1_storage_health_1));
	v1_storage_health_t* v1_storage_health_2 = v1_storage_health_parseFromJSON(jsonv1_storage_health_1);
	cJSON* jsonv1_storage_health_2 = v1_storage_health_convertToJSON(v1_storage_health_2);
	printf("repeating v1_storage_health:\n%s\n", cJSON_Print(jsonv1_storage_health_2));
}

int main() {
  test_v1_storage_health(1);
  test_v1_storage_health(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_storage_health_MAIN
#endif // v1_storage_health_TEST
