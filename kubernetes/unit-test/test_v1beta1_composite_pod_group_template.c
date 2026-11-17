#ifndef v1beta1_composite_pod_group_template_TEST
#define v1beta1_composite_pod_group_template_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_composite_pod_group_template_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_composite_pod_group_template.h"
v1beta1_composite_pod_group_template_t* instantiate_v1beta1_composite_pod_group_template(int include_optional);

#include "test_v1beta1_composite_disruption_mode.c"
#include "test_v1beta1_composite_pod_group_scheduling_constraints.c"
#include "test_v1beta1_composite_pod_group_scheduling_policy.c"


v1beta1_composite_pod_group_template_t* instantiate_v1beta1_composite_pod_group_template(int include_optional) {
  v1beta1_composite_pod_group_template_t* v1beta1_composite_pod_group_template = NULL;
  if (include_optional) {
    v1beta1_composite_pod_group_template = v1beta1_composite_pod_group_template_create(
      list_createList(),
       // false, not to have infinite recursion
      instantiate_v1beta1_composite_disruption_mode(0),
      "0",
      list_createList(),
      "0",
      56,
      "0",
       // false, not to have infinite recursion
      instantiate_v1beta1_composite_pod_group_scheduling_constraints(0),
       // false, not to have infinite recursion
      instantiate_v1beta1_composite_pod_group_scheduling_policy(0)
    );
  } else {
    v1beta1_composite_pod_group_template = v1beta1_composite_pod_group_template_create(
      list_createList(),
      NULL,
      "0",
      list_createList(),
      "0",
      56,
      "0",
      NULL,
      NULL
    );
  }

  return v1beta1_composite_pod_group_template;
}


#ifdef v1beta1_composite_pod_group_template_MAIN

void test_v1beta1_composite_pod_group_template(int include_optional) {
    v1beta1_composite_pod_group_template_t* v1beta1_composite_pod_group_template_1 = instantiate_v1beta1_composite_pod_group_template(include_optional);

	cJSON* jsonv1beta1_composite_pod_group_template_1 = v1beta1_composite_pod_group_template_convertToJSON(v1beta1_composite_pod_group_template_1);
	printf("v1beta1_composite_pod_group_template :\n%s\n", cJSON_Print(jsonv1beta1_composite_pod_group_template_1));
	v1beta1_composite_pod_group_template_t* v1beta1_composite_pod_group_template_2 = v1beta1_composite_pod_group_template_parseFromJSON(jsonv1beta1_composite_pod_group_template_1);
	cJSON* jsonv1beta1_composite_pod_group_template_2 = v1beta1_composite_pod_group_template_convertToJSON(v1beta1_composite_pod_group_template_2);
	printf("repeating v1beta1_composite_pod_group_template:\n%s\n", cJSON_Print(jsonv1beta1_composite_pod_group_template_2));
}

int main() {
  test_v1beta1_composite_pod_group_template(1);
  test_v1beta1_composite_pod_group_template(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_composite_pod_group_template_MAIN
#endif // v1beta1_composite_pod_group_template_TEST
