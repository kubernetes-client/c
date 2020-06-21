#ifndef v1_volume_node_affinity_TEST
#define v1_volume_node_affinity_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_volume_node_affinity_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_volume_node_affinity.h"
v1_volume_node_affinity_t* instantiate_v1_volume_node_affinity(int include_optional);

#include "test_v1_node_selector.c"


v1_volume_node_affinity_t* instantiate_v1_volume_node_affinity(int include_optional) {
  v1_volume_node_affinity_t* v1_volume_node_affinity = NULL;
  if (include_optional) {
    v1_volume_node_affinity = v1_volume_node_affinity_create(
       // false, not to have infinite recursion
      instantiate_v1_node_selector(0)
    );
  } else {
    v1_volume_node_affinity = v1_volume_node_affinity_create(
      NULL
    );
  }

  return v1_volume_node_affinity;
}


#ifdef v1_volume_node_affinity_MAIN

void test_v1_volume_node_affinity(int include_optional) {
    v1_volume_node_affinity_t* v1_volume_node_affinity_1 = instantiate_v1_volume_node_affinity(include_optional);

	cJSON* jsonv1_volume_node_affinity_1 = v1_volume_node_affinity_convertToJSON(v1_volume_node_affinity_1);
	printf("v1_volume_node_affinity :\n%s\n", cJSON_Print(jsonv1_volume_node_affinity_1));
	v1_volume_node_affinity_t* v1_volume_node_affinity_2 = v1_volume_node_affinity_parseFromJSON(jsonv1_volume_node_affinity_1);
	cJSON* jsonv1_volume_node_affinity_2 = v1_volume_node_affinity_convertToJSON(v1_volume_node_affinity_2);
	printf("repeating v1_volume_node_affinity:\n%s\n", cJSON_Print(jsonv1_volume_node_affinity_2));
}

int main() {
  test_v1_volume_node_affinity(1);
  test_v1_volume_node_affinity(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_volume_node_affinity_MAIN
#endif // v1_volume_node_affinity_TEST
