#ifndef v1_topology_spread_constraint_TEST
#define v1_topology_spread_constraint_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_topology_spread_constraint_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_topology_spread_constraint.h"
v1_topology_spread_constraint_t* instantiate_v1_topology_spread_constraint(int include_optional);

#include "test_v1_label_selector.c"


v1_topology_spread_constraint_t* instantiate_v1_topology_spread_constraint(int include_optional) {
  v1_topology_spread_constraint_t* v1_topology_spread_constraint = NULL;
  if (include_optional) {
    v1_topology_spread_constraint = v1_topology_spread_constraint_create(
       // false, not to have infinite recursion
      instantiate_v1_label_selector(0),
      56,
      "0",
      "0"
    );
  } else {
    v1_topology_spread_constraint = v1_topology_spread_constraint_create(
      NULL,
      56,
      "0",
      "0"
    );
  }

  return v1_topology_spread_constraint;
}


#ifdef v1_topology_spread_constraint_MAIN

void test_v1_topology_spread_constraint(int include_optional) {
    v1_topology_spread_constraint_t* v1_topology_spread_constraint_1 = instantiate_v1_topology_spread_constraint(include_optional);

	cJSON* jsonv1_topology_spread_constraint_1 = v1_topology_spread_constraint_convertToJSON(v1_topology_spread_constraint_1);
	printf("v1_topology_spread_constraint :\n%s\n", cJSON_Print(jsonv1_topology_spread_constraint_1));
	v1_topology_spread_constraint_t* v1_topology_spread_constraint_2 = v1_topology_spread_constraint_parseFromJSON(jsonv1_topology_spread_constraint_1);
	cJSON* jsonv1_topology_spread_constraint_2 = v1_topology_spread_constraint_convertToJSON(v1_topology_spread_constraint_2);
	printf("repeating v1_topology_spread_constraint:\n%s\n", cJSON_Print(jsonv1_topology_spread_constraint_2));
}

int main() {
  test_v1_topology_spread_constraint(1);
  test_v1_topology_spread_constraint(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_topology_spread_constraint_MAIN
#endif // v1_topology_spread_constraint_TEST
