#ifndef v1alpha3_device_taint_rule_spec_TEST
#define v1alpha3_device_taint_rule_spec_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha3_device_taint_rule_spec_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha3_device_taint_rule_spec.h"
v1alpha3_device_taint_rule_spec_t* instantiate_v1alpha3_device_taint_rule_spec(int include_optional);

#include "test_v1alpha3_device_taint_selector.c"
#include "test_v1alpha3_device_taint.c"


v1alpha3_device_taint_rule_spec_t* instantiate_v1alpha3_device_taint_rule_spec(int include_optional) {
  v1alpha3_device_taint_rule_spec_t* v1alpha3_device_taint_rule_spec = NULL;
  if (include_optional) {
    v1alpha3_device_taint_rule_spec = v1alpha3_device_taint_rule_spec_create(
       // false, not to have infinite recursion
      instantiate_v1alpha3_device_taint_selector(0),
       // false, not to have infinite recursion
      instantiate_v1alpha3_device_taint(0)
    );
  } else {
    v1alpha3_device_taint_rule_spec = v1alpha3_device_taint_rule_spec_create(
      NULL,
      NULL
    );
  }

  return v1alpha3_device_taint_rule_spec;
}


#ifdef v1alpha3_device_taint_rule_spec_MAIN

void test_v1alpha3_device_taint_rule_spec(int include_optional) {
    v1alpha3_device_taint_rule_spec_t* v1alpha3_device_taint_rule_spec_1 = instantiate_v1alpha3_device_taint_rule_spec(include_optional);

	cJSON* jsonv1alpha3_device_taint_rule_spec_1 = v1alpha3_device_taint_rule_spec_convertToJSON(v1alpha3_device_taint_rule_spec_1);
	printf("v1alpha3_device_taint_rule_spec :\n%s\n", cJSON_Print(jsonv1alpha3_device_taint_rule_spec_1));
	v1alpha3_device_taint_rule_spec_t* v1alpha3_device_taint_rule_spec_2 = v1alpha3_device_taint_rule_spec_parseFromJSON(jsonv1alpha3_device_taint_rule_spec_1);
	cJSON* jsonv1alpha3_device_taint_rule_spec_2 = v1alpha3_device_taint_rule_spec_convertToJSON(v1alpha3_device_taint_rule_spec_2);
	printf("repeating v1alpha3_device_taint_rule_spec:\n%s\n", cJSON_Print(jsonv1alpha3_device_taint_rule_spec_2));
}

int main() {
  test_v1alpha3_device_taint_rule_spec(1);
  test_v1alpha3_device_taint_rule_spec(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha3_device_taint_rule_spec_MAIN
#endif // v1alpha3_device_taint_rule_spec_TEST
