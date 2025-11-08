#ifndef v1_container_restart_rule_on_exit_codes_TEST
#define v1_container_restart_rule_on_exit_codes_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_container_restart_rule_on_exit_codes_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_container_restart_rule_on_exit_codes.h"
v1_container_restart_rule_on_exit_codes_t* instantiate_v1_container_restart_rule_on_exit_codes(int include_optional);



v1_container_restart_rule_on_exit_codes_t* instantiate_v1_container_restart_rule_on_exit_codes(int include_optional) {
  v1_container_restart_rule_on_exit_codes_t* v1_container_restart_rule_on_exit_codes = NULL;
  if (include_optional) {
    v1_container_restart_rule_on_exit_codes = v1_container_restart_rule_on_exit_codes_create(
      "0",
      list_createList()
    );
  } else {
    v1_container_restart_rule_on_exit_codes = v1_container_restart_rule_on_exit_codes_create(
      "0",
      list_createList()
    );
  }

  return v1_container_restart_rule_on_exit_codes;
}


#ifdef v1_container_restart_rule_on_exit_codes_MAIN

void test_v1_container_restart_rule_on_exit_codes(int include_optional) {
    v1_container_restart_rule_on_exit_codes_t* v1_container_restart_rule_on_exit_codes_1 = instantiate_v1_container_restart_rule_on_exit_codes(include_optional);

	cJSON* jsonv1_container_restart_rule_on_exit_codes_1 = v1_container_restart_rule_on_exit_codes_convertToJSON(v1_container_restart_rule_on_exit_codes_1);
	printf("v1_container_restart_rule_on_exit_codes :\n%s\n", cJSON_Print(jsonv1_container_restart_rule_on_exit_codes_1));
	v1_container_restart_rule_on_exit_codes_t* v1_container_restart_rule_on_exit_codes_2 = v1_container_restart_rule_on_exit_codes_parseFromJSON(jsonv1_container_restart_rule_on_exit_codes_1);
	cJSON* jsonv1_container_restart_rule_on_exit_codes_2 = v1_container_restart_rule_on_exit_codes_convertToJSON(v1_container_restart_rule_on_exit_codes_2);
	printf("repeating v1_container_restart_rule_on_exit_codes:\n%s\n", cJSON_Print(jsonv1_container_restart_rule_on_exit_codes_2));
}

int main() {
  test_v1_container_restart_rule_on_exit_codes(1);
  test_v1_container_restart_rule_on_exit_codes(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_container_restart_rule_on_exit_codes_MAIN
#endif // v1_container_restart_rule_on_exit_codes_TEST
