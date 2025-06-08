#ifndef v1beta2_resource_pool_TEST
#define v1beta2_resource_pool_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta2_resource_pool_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta2_resource_pool.h"
v1beta2_resource_pool_t* instantiate_v1beta2_resource_pool(int include_optional);



v1beta2_resource_pool_t* instantiate_v1beta2_resource_pool(int include_optional) {
  v1beta2_resource_pool_t* v1beta2_resource_pool = NULL;
  if (include_optional) {
    v1beta2_resource_pool = v1beta2_resource_pool_create(
      56,
      "0",
      56
    );
  } else {
    v1beta2_resource_pool = v1beta2_resource_pool_create(
      56,
      "0",
      56
    );
  }

  return v1beta2_resource_pool;
}


#ifdef v1beta2_resource_pool_MAIN

void test_v1beta2_resource_pool(int include_optional) {
    v1beta2_resource_pool_t* v1beta2_resource_pool_1 = instantiate_v1beta2_resource_pool(include_optional);

	cJSON* jsonv1beta2_resource_pool_1 = v1beta2_resource_pool_convertToJSON(v1beta2_resource_pool_1);
	printf("v1beta2_resource_pool :\n%s\n", cJSON_Print(jsonv1beta2_resource_pool_1));
	v1beta2_resource_pool_t* v1beta2_resource_pool_2 = v1beta2_resource_pool_parseFromJSON(jsonv1beta2_resource_pool_1);
	cJSON* jsonv1beta2_resource_pool_2 = v1beta2_resource_pool_convertToJSON(v1beta2_resource_pool_2);
	printf("repeating v1beta2_resource_pool:\n%s\n", cJSON_Print(jsonv1beta2_resource_pool_2));
}

int main() {
  test_v1beta2_resource_pool(1);
  test_v1beta2_resource_pool(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta2_resource_pool_MAIN
#endif // v1beta2_resource_pool_TEST
