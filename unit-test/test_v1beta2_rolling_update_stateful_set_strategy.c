#ifndef v1beta2_rolling_update_stateful_set_strategy_TEST
#define v1beta2_rolling_update_stateful_set_strategy_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta2_rolling_update_stateful_set_strategy_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta2_rolling_update_stateful_set_strategy.h"
v1beta2_rolling_update_stateful_set_strategy_t* instantiate_v1beta2_rolling_update_stateful_set_strategy(int include_optional);



v1beta2_rolling_update_stateful_set_strategy_t* instantiate_v1beta2_rolling_update_stateful_set_strategy(int include_optional) {
  v1beta2_rolling_update_stateful_set_strategy_t* v1beta2_rolling_update_stateful_set_strategy = NULL;
  if (include_optional) {
    v1beta2_rolling_update_stateful_set_strategy = v1beta2_rolling_update_stateful_set_strategy_create(
      56
    );
  } else {
    v1beta2_rolling_update_stateful_set_strategy = v1beta2_rolling_update_stateful_set_strategy_create(
      56
    );
  }

  return v1beta2_rolling_update_stateful_set_strategy;
}


#ifdef v1beta2_rolling_update_stateful_set_strategy_MAIN

void test_v1beta2_rolling_update_stateful_set_strategy(int include_optional) {
    v1beta2_rolling_update_stateful_set_strategy_t* v1beta2_rolling_update_stateful_set_strategy_1 = instantiate_v1beta2_rolling_update_stateful_set_strategy(include_optional);

	cJSON* jsonv1beta2_rolling_update_stateful_set_strategy_1 = v1beta2_rolling_update_stateful_set_strategy_convertToJSON(v1beta2_rolling_update_stateful_set_strategy_1);
	printf("v1beta2_rolling_update_stateful_set_strategy :\n%s\n", cJSON_Print(jsonv1beta2_rolling_update_stateful_set_strategy_1));
	v1beta2_rolling_update_stateful_set_strategy_t* v1beta2_rolling_update_stateful_set_strategy_2 = v1beta2_rolling_update_stateful_set_strategy_parseFromJSON(jsonv1beta2_rolling_update_stateful_set_strategy_1);
	cJSON* jsonv1beta2_rolling_update_stateful_set_strategy_2 = v1beta2_rolling_update_stateful_set_strategy_convertToJSON(v1beta2_rolling_update_stateful_set_strategy_2);
	printf("repeating v1beta2_rolling_update_stateful_set_strategy:\n%s\n", cJSON_Print(jsonv1beta2_rolling_update_stateful_set_strategy_2));
}

int main() {
  test_v1beta2_rolling_update_stateful_set_strategy(1);
  test_v1beta2_rolling_update_stateful_set_strategy(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta2_rolling_update_stateful_set_strategy_MAIN
#endif // v1beta2_rolling_update_stateful_set_strategy_TEST
