#ifndef v1beta2_node_allocatable_resource_TEST
#define v1beta2_node_allocatable_resource_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta2_node_allocatable_resource_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta2_node_allocatable_resource.h"
v1beta2_node_allocatable_resource_t* instantiate_v1beta2_node_allocatable_resource(int include_optional);

#include "test_v1beta2_node_allocatable_mapping.c"
#include "test_v1beta2_node_allocatable_overhead.c"


v1beta2_node_allocatable_resource_t* instantiate_v1beta2_node_allocatable_resource(int include_optional) {
  v1beta2_node_allocatable_resource_t* v1beta2_node_allocatable_resource = NULL;
  if (include_optional) {
    v1beta2_node_allocatable_resource = v1beta2_node_allocatable_resource_create(
       // false, not to have infinite recursion
      instantiate_v1beta2_node_allocatable_mapping(0),
       // false, not to have infinite recursion
      instantiate_v1beta2_node_allocatable_overhead(0)
    );
  } else {
    v1beta2_node_allocatable_resource = v1beta2_node_allocatable_resource_create(
      NULL,
      NULL
    );
  }

  return v1beta2_node_allocatable_resource;
}


#ifdef v1beta2_node_allocatable_resource_MAIN

void test_v1beta2_node_allocatable_resource(int include_optional) {
    v1beta2_node_allocatable_resource_t* v1beta2_node_allocatable_resource_1 = instantiate_v1beta2_node_allocatable_resource(include_optional);

	cJSON* jsonv1beta2_node_allocatable_resource_1 = v1beta2_node_allocatable_resource_convertToJSON(v1beta2_node_allocatable_resource_1);
	printf("v1beta2_node_allocatable_resource :\n%s\n", cJSON_Print(jsonv1beta2_node_allocatable_resource_1));
	v1beta2_node_allocatable_resource_t* v1beta2_node_allocatable_resource_2 = v1beta2_node_allocatable_resource_parseFromJSON(jsonv1beta2_node_allocatable_resource_1);
	cJSON* jsonv1beta2_node_allocatable_resource_2 = v1beta2_node_allocatable_resource_convertToJSON(v1beta2_node_allocatable_resource_2);
	printf("repeating v1beta2_node_allocatable_resource:\n%s\n", cJSON_Print(jsonv1beta2_node_allocatable_resource_2));
}

int main() {
  test_v1beta2_node_allocatable_resource(1);
  test_v1beta2_node_allocatable_resource(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta2_node_allocatable_resource_MAIN
#endif // v1beta2_node_allocatable_resource_TEST
