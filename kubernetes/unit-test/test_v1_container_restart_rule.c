#ifndef v1_container_restart_rule_TEST
#define v1_container_restart_rule_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_container_restart_rule_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_container_restart_rule.h"
v1_container_restart_rule_t* instantiate_v1_container_restart_rule(int include_optional);

#include "test_v1_container_restart_rule_on_exit_codes.c"


v1_container_restart_rule_t* instantiate_v1_container_restart_rule(int include_optional) {
  v1_container_restart_rule_t* v1_container_restart_rule = NULL;
  if (include_optional) {
    v1_container_restart_rule = v1_container_restart_rule_create(
      "0",
       // false, not to have infinite recursion
      instantiate_v1_container_restart_rule_on_exit_codes(0)
    );
  } else {
    v1_container_restart_rule = v1_container_restart_rule_create(
      "0",
      NULL
    );
  }

  return v1_container_restart_rule;
}


#ifdef v1_container_restart_rule_MAIN

void test_v1_container_restart_rule(int include_optional) {
    v1_container_restart_rule_t* v1_container_restart_rule_1 = instantiate_v1_container_restart_rule(include_optional);

	cJSON* jsonv1_container_restart_rule_1 = v1_container_restart_rule_convertToJSON(v1_container_restart_rule_1);
	printf("v1_container_restart_rule :\n%s\n", cJSON_Print(jsonv1_container_restart_rule_1));
	v1_container_restart_rule_t* v1_container_restart_rule_2 = v1_container_restart_rule_parseFromJSON(jsonv1_container_restart_rule_1);
	cJSON* jsonv1_container_restart_rule_2 = v1_container_restart_rule_convertToJSON(v1_container_restart_rule_2);
	printf("repeating v1_container_restart_rule:\n%s\n", cJSON_Print(jsonv1_container_restart_rule_2));
}

int main() {
  test_v1_container_restart_rule(1);
  test_v1_container_restart_rule(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_container_restart_rule_MAIN
#endif // v1_container_restart_rule_TEST
