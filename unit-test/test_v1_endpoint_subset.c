#ifndef v1_endpoint_subset_TEST
#define v1_endpoint_subset_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_endpoint_subset_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_endpoint_subset.h"
v1_endpoint_subset_t* instantiate_v1_endpoint_subset(int include_optional);



v1_endpoint_subset_t* instantiate_v1_endpoint_subset(int include_optional) {
  v1_endpoint_subset_t* v1_endpoint_subset = NULL;
  if (include_optional) {
    v1_endpoint_subset = v1_endpoint_subset_create(
      list_create(),
      list_create(),
      list_create()
    );
  } else {
    v1_endpoint_subset = v1_endpoint_subset_create(
      list_create(),
      list_create(),
      list_create()
    );
  }

  return v1_endpoint_subset;
}


#ifdef v1_endpoint_subset_MAIN

void test_v1_endpoint_subset(int include_optional) {
    v1_endpoint_subset_t* v1_endpoint_subset_1 = instantiate_v1_endpoint_subset(include_optional);

	cJSON* jsonv1_endpoint_subset_1 = v1_endpoint_subset_convertToJSON(v1_endpoint_subset_1);
	printf("v1_endpoint_subset :\n%s\n", cJSON_Print(jsonv1_endpoint_subset_1));
	v1_endpoint_subset_t* v1_endpoint_subset_2 = v1_endpoint_subset_parseFromJSON(jsonv1_endpoint_subset_1);
	cJSON* jsonv1_endpoint_subset_2 = v1_endpoint_subset_convertToJSON(v1_endpoint_subset_2);
	printf("repeating v1_endpoint_subset:\n%s\n", cJSON_Print(jsonv1_endpoint_subset_2));
}

int main() {
  test_v1_endpoint_subset(1);
  test_v1_endpoint_subset(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_endpoint_subset_MAIN
#endif // v1_endpoint_subset_TEST
