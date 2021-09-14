#ifndef v1_pod_disruption_budget_TEST
#define v1_pod_disruption_budget_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_pod_disruption_budget_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_pod_disruption_budget.h"
v1_pod_disruption_budget_t* instantiate_v1_pod_disruption_budget(int include_optional);

#include "test_v1_object_meta.c"
#include "test_v1_pod_disruption_budget_spec.c"
#include "test_v1_pod_disruption_budget_status.c"


v1_pod_disruption_budget_t* instantiate_v1_pod_disruption_budget(int include_optional) {
  v1_pod_disruption_budget_t* v1_pod_disruption_budget = NULL;
  if (include_optional) {
    v1_pod_disruption_budget = v1_pod_disruption_budget_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
       // false, not to have infinite recursion
      instantiate_v1_pod_disruption_budget_spec(0),
       // false, not to have infinite recursion
      instantiate_v1_pod_disruption_budget_status(0)
    );
  } else {
    v1_pod_disruption_budget = v1_pod_disruption_budget_create(
      "0",
      "0",
      NULL,
      NULL,
      NULL
    );
  }

  return v1_pod_disruption_budget;
}


#ifdef v1_pod_disruption_budget_MAIN

void test_v1_pod_disruption_budget(int include_optional) {
    v1_pod_disruption_budget_t* v1_pod_disruption_budget_1 = instantiate_v1_pod_disruption_budget(include_optional);

	cJSON* jsonv1_pod_disruption_budget_1 = v1_pod_disruption_budget_convertToJSON(v1_pod_disruption_budget_1);
	printf("v1_pod_disruption_budget :\n%s\n", cJSON_Print(jsonv1_pod_disruption_budget_1));
	v1_pod_disruption_budget_t* v1_pod_disruption_budget_2 = v1_pod_disruption_budget_parseFromJSON(jsonv1_pod_disruption_budget_1);
	cJSON* jsonv1_pod_disruption_budget_2 = v1_pod_disruption_budget_convertToJSON(v1_pod_disruption_budget_2);
	printf("repeating v1_pod_disruption_budget:\n%s\n", cJSON_Print(jsonv1_pod_disruption_budget_2));
}

int main() {
  test_v1_pod_disruption_budget(1);
  test_v1_pod_disruption_budget(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_pod_disruption_budget_MAIN
#endif // v1_pod_disruption_budget_TEST
