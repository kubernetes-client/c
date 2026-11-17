#ifndef v1_node_allocatable_mapping_TEST
#define v1_node_allocatable_mapping_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_node_allocatable_mapping_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_node_allocatable_mapping.h"
v1_node_allocatable_mapping_t* instantiate_v1_node_allocatable_mapping(int include_optional);



v1_node_allocatable_mapping_t* instantiate_v1_node_allocatable_mapping(int include_optional) {
  v1_node_allocatable_mapping_t* v1_node_allocatable_mapping = NULL;
  if (include_optional) {
    v1_node_allocatable_mapping = v1_node_allocatable_mapping_create(
      "0",
      "0",
      "0"
    );
  } else {
    v1_node_allocatable_mapping = v1_node_allocatable_mapping_create(
      "0",
      "0",
      "0"
    );
  }

  return v1_node_allocatable_mapping;
}


#ifdef v1_node_allocatable_mapping_MAIN

void test_v1_node_allocatable_mapping(int include_optional) {
    v1_node_allocatable_mapping_t* v1_node_allocatable_mapping_1 = instantiate_v1_node_allocatable_mapping(include_optional);

	cJSON* jsonv1_node_allocatable_mapping_1 = v1_node_allocatable_mapping_convertToJSON(v1_node_allocatable_mapping_1);
	printf("v1_node_allocatable_mapping :\n%s\n", cJSON_Print(jsonv1_node_allocatable_mapping_1));
	v1_node_allocatable_mapping_t* v1_node_allocatable_mapping_2 = v1_node_allocatable_mapping_parseFromJSON(jsonv1_node_allocatable_mapping_1);
	cJSON* jsonv1_node_allocatable_mapping_2 = v1_node_allocatable_mapping_convertToJSON(v1_node_allocatable_mapping_2);
	printf("repeating v1_node_allocatable_mapping:\n%s\n", cJSON_Print(jsonv1_node_allocatable_mapping_2));
}

int main() {
  test_v1_node_allocatable_mapping(1);
  test_v1_node_allocatable_mapping(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_node_allocatable_mapping_MAIN
#endif // v1_node_allocatable_mapping_TEST
