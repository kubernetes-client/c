#ifndef v1alpha3_device_taint_rule_TEST
#define v1alpha3_device_taint_rule_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha3_device_taint_rule_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha3_device_taint_rule.h"
v1alpha3_device_taint_rule_t* instantiate_v1alpha3_device_taint_rule(int include_optional);

#include "test_v1_object_meta.c"
#include "test_v1alpha3_device_taint_rule_spec.c"


v1alpha3_device_taint_rule_t* instantiate_v1alpha3_device_taint_rule(int include_optional) {
  v1alpha3_device_taint_rule_t* v1alpha3_device_taint_rule = NULL;
  if (include_optional) {
    v1alpha3_device_taint_rule = v1alpha3_device_taint_rule_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
       // false, not to have infinite recursion
      instantiate_v1alpha3_device_taint_rule_spec(0)
    );
  } else {
    v1alpha3_device_taint_rule = v1alpha3_device_taint_rule_create(
      "0",
      "0",
      NULL,
      NULL
    );
  }

  return v1alpha3_device_taint_rule;
}


#ifdef v1alpha3_device_taint_rule_MAIN

void test_v1alpha3_device_taint_rule(int include_optional) {
    v1alpha3_device_taint_rule_t* v1alpha3_device_taint_rule_1 = instantiate_v1alpha3_device_taint_rule(include_optional);

	cJSON* jsonv1alpha3_device_taint_rule_1 = v1alpha3_device_taint_rule_convertToJSON(v1alpha3_device_taint_rule_1);
	printf("v1alpha3_device_taint_rule :\n%s\n", cJSON_Print(jsonv1alpha3_device_taint_rule_1));
	v1alpha3_device_taint_rule_t* v1alpha3_device_taint_rule_2 = v1alpha3_device_taint_rule_parseFromJSON(jsonv1alpha3_device_taint_rule_1);
	cJSON* jsonv1alpha3_device_taint_rule_2 = v1alpha3_device_taint_rule_convertToJSON(v1alpha3_device_taint_rule_2);
	printf("repeating v1alpha3_device_taint_rule:\n%s\n", cJSON_Print(jsonv1alpha3_device_taint_rule_2));
}

int main() {
  test_v1alpha3_device_taint_rule(1);
  test_v1alpha3_device_taint_rule(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha3_device_taint_rule_MAIN
#endif // v1alpha3_device_taint_rule_TEST
