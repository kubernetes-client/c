#ifndef v1alpha3_resource_pool_TEST
#define v1alpha3_resource_pool_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha3_resource_pool_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha3_resource_pool.h"
v1alpha3_resource_pool_t* instantiate_v1alpha3_resource_pool(int include_optional);



v1alpha3_resource_pool_t* instantiate_v1alpha3_resource_pool(int include_optional) {
  v1alpha3_resource_pool_t* v1alpha3_resource_pool = NULL;
  if (include_optional) {
    v1alpha3_resource_pool = v1alpha3_resource_pool_create(
      56,
      "0",
      56
    );
  } else {
    v1alpha3_resource_pool = v1alpha3_resource_pool_create(
      56,
      "0",
      56
    );
  }

  return v1alpha3_resource_pool;
}


#ifdef v1alpha3_resource_pool_MAIN

void test_v1alpha3_resource_pool(int include_optional) {
    v1alpha3_resource_pool_t* v1alpha3_resource_pool_1 = instantiate_v1alpha3_resource_pool(include_optional);

	cJSON* jsonv1alpha3_resource_pool_1 = v1alpha3_resource_pool_convertToJSON(v1alpha3_resource_pool_1);
	printf("v1alpha3_resource_pool :\n%s\n", cJSON_Print(jsonv1alpha3_resource_pool_1));
	v1alpha3_resource_pool_t* v1alpha3_resource_pool_2 = v1alpha3_resource_pool_parseFromJSON(jsonv1alpha3_resource_pool_1);
	cJSON* jsonv1alpha3_resource_pool_2 = v1alpha3_resource_pool_convertToJSON(v1alpha3_resource_pool_2);
	printf("repeating v1alpha3_resource_pool:\n%s\n", cJSON_Print(jsonv1alpha3_resource_pool_2));
}

int main() {
  test_v1alpha3_resource_pool(1);
  test_v1alpha3_resource_pool(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha3_resource_pool_MAIN
#endif // v1alpha3_resource_pool_TEST
