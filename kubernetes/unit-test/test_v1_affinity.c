#ifndef v1_affinity_TEST
#define v1_affinity_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_affinity_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_affinity.h"
v1_affinity_t* instantiate_v1_affinity(int include_optional);

#include "test_v1_node_affinity.c"
#include "test_v1_pod_affinity.c"
#include "test_v1_pod_anti_affinity.c"


v1_affinity_t* instantiate_v1_affinity(int include_optional) {
  v1_affinity_t* v1_affinity = NULL;
  if (include_optional) {
    v1_affinity = v1_affinity_create(
       // false, not to have infinite recursion
      instantiate_v1_node_affinity(0),
       // false, not to have infinite recursion
      instantiate_v1_pod_affinity(0),
       // false, not to have infinite recursion
      instantiate_v1_pod_anti_affinity(0)
    );
  } else {
    v1_affinity = v1_affinity_create(
      NULL,
      NULL,
      NULL
    );
  }

  return v1_affinity;
}


#ifdef v1_affinity_MAIN

void test_v1_affinity(int include_optional) {
    v1_affinity_t* v1_affinity_1 = instantiate_v1_affinity(include_optional);

	cJSON* jsonv1_affinity_1 = v1_affinity_convertToJSON(v1_affinity_1);
	printf("v1_affinity :\n%s\n", cJSON_Print(jsonv1_affinity_1));
	v1_affinity_t* v1_affinity_2 = v1_affinity_parseFromJSON(jsonv1_affinity_1);
	cJSON* jsonv1_affinity_2 = v1_affinity_convertToJSON(v1_affinity_2);
	printf("repeating v1_affinity:\n%s\n", cJSON_Print(jsonv1_affinity_2));
}

int main() {
  test_v1_affinity(1);
  test_v1_affinity(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_affinity_MAIN
#endif // v1_affinity_TEST
