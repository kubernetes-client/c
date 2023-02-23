#ifndef v1_pod_disruption_budget_spec_TEST
#define v1_pod_disruption_budget_spec_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_pod_disruption_budget_spec_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_pod_disruption_budget_spec.h"
v1_pod_disruption_budget_spec_t* instantiate_v1_pod_disruption_budget_spec(int include_optional);

#include "test_v1_label_selector.c"


v1_pod_disruption_budget_spec_t* instantiate_v1_pod_disruption_budget_spec(int include_optional) {
  v1_pod_disruption_budget_spec_t* v1_pod_disruption_budget_spec = NULL;
  if (include_optional) {
    v1_pod_disruption_budget_spec = v1_pod_disruption_budget_spec_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_label_selector(0),
      "0"
    );
  } else {
    v1_pod_disruption_budget_spec = v1_pod_disruption_budget_spec_create(
      "0",
      "0",
      NULL,
      "0"
    );
  }

  return v1_pod_disruption_budget_spec;
}


#ifdef v1_pod_disruption_budget_spec_MAIN

void test_v1_pod_disruption_budget_spec(int include_optional) {
    v1_pod_disruption_budget_spec_t* v1_pod_disruption_budget_spec_1 = instantiate_v1_pod_disruption_budget_spec(include_optional);

	cJSON* jsonv1_pod_disruption_budget_spec_1 = v1_pod_disruption_budget_spec_convertToJSON(v1_pod_disruption_budget_spec_1);
	printf("v1_pod_disruption_budget_spec :\n%s\n", cJSON_Print(jsonv1_pod_disruption_budget_spec_1));
	v1_pod_disruption_budget_spec_t* v1_pod_disruption_budget_spec_2 = v1_pod_disruption_budget_spec_parseFromJSON(jsonv1_pod_disruption_budget_spec_1);
	cJSON* jsonv1_pod_disruption_budget_spec_2 = v1_pod_disruption_budget_spec_convertToJSON(v1_pod_disruption_budget_spec_2);
	printf("repeating v1_pod_disruption_budget_spec:\n%s\n", cJSON_Print(jsonv1_pod_disruption_budget_spec_2));
}

int main() {
  test_v1_pod_disruption_budget_spec(1);
  test_v1_pod_disruption_budget_spec(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_pod_disruption_budget_spec_MAIN
#endif // v1_pod_disruption_budget_spec_TEST
