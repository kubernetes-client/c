#ifndef v1_stateful_set_update_strategy_TEST
#define v1_stateful_set_update_strategy_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_stateful_set_update_strategy_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_stateful_set_update_strategy.h"
v1_stateful_set_update_strategy_t* instantiate_v1_stateful_set_update_strategy(int include_optional);

#include "test_v1_rolling_update_stateful_set_strategy.c"


v1_stateful_set_update_strategy_t* instantiate_v1_stateful_set_update_strategy(int include_optional) {
  v1_stateful_set_update_strategy_t* v1_stateful_set_update_strategy = NULL;
  if (include_optional) {
    v1_stateful_set_update_strategy = v1_stateful_set_update_strategy_create(
       // false, not to have infinite recursion
      instantiate_v1_rolling_update_stateful_set_strategy(0),
      "0"
    );
  } else {
    v1_stateful_set_update_strategy = v1_stateful_set_update_strategy_create(
      NULL,
      "0"
    );
  }

  return v1_stateful_set_update_strategy;
}


#ifdef v1_stateful_set_update_strategy_MAIN

void test_v1_stateful_set_update_strategy(int include_optional) {
    v1_stateful_set_update_strategy_t* v1_stateful_set_update_strategy_1 = instantiate_v1_stateful_set_update_strategy(include_optional);

	cJSON* jsonv1_stateful_set_update_strategy_1 = v1_stateful_set_update_strategy_convertToJSON(v1_stateful_set_update_strategy_1);
	printf("v1_stateful_set_update_strategy :\n%s\n", cJSON_Print(jsonv1_stateful_set_update_strategy_1));
	v1_stateful_set_update_strategy_t* v1_stateful_set_update_strategy_2 = v1_stateful_set_update_strategy_parseFromJSON(jsonv1_stateful_set_update_strategy_1);
	cJSON* jsonv1_stateful_set_update_strategy_2 = v1_stateful_set_update_strategy_convertToJSON(v1_stateful_set_update_strategy_2);
	printf("repeating v1_stateful_set_update_strategy:\n%s\n", cJSON_Print(jsonv1_stateful_set_update_strategy_2));
}

int main() {
  test_v1_stateful_set_update_strategy(1);
  test_v1_stateful_set_update_strategy(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_stateful_set_update_strategy_MAIN
#endif // v1_stateful_set_update_strategy_TEST
