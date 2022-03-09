#ifndef v1beta1_supplemental_groups_strategy_options_TEST
#define v1beta1_supplemental_groups_strategy_options_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_supplemental_groups_strategy_options_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_supplemental_groups_strategy_options.h"
v1beta1_supplemental_groups_strategy_options_t* instantiate_v1beta1_supplemental_groups_strategy_options(int include_optional);



v1beta1_supplemental_groups_strategy_options_t* instantiate_v1beta1_supplemental_groups_strategy_options(int include_optional) {
  v1beta1_supplemental_groups_strategy_options_t* v1beta1_supplemental_groups_strategy_options = NULL;
  if (include_optional) {
    v1beta1_supplemental_groups_strategy_options = v1beta1_supplemental_groups_strategy_options_create(
      list_createList(),
      "0"
    );
  } else {
    v1beta1_supplemental_groups_strategy_options = v1beta1_supplemental_groups_strategy_options_create(
      list_createList(),
      "0"
    );
  }

  return v1beta1_supplemental_groups_strategy_options;
}


#ifdef v1beta1_supplemental_groups_strategy_options_MAIN

void test_v1beta1_supplemental_groups_strategy_options(int include_optional) {
    v1beta1_supplemental_groups_strategy_options_t* v1beta1_supplemental_groups_strategy_options_1 = instantiate_v1beta1_supplemental_groups_strategy_options(include_optional);

	cJSON* jsonv1beta1_supplemental_groups_strategy_options_1 = v1beta1_supplemental_groups_strategy_options_convertToJSON(v1beta1_supplemental_groups_strategy_options_1);
	printf("v1beta1_supplemental_groups_strategy_options :\n%s\n", cJSON_Print(jsonv1beta1_supplemental_groups_strategy_options_1));
	v1beta1_supplemental_groups_strategy_options_t* v1beta1_supplemental_groups_strategy_options_2 = v1beta1_supplemental_groups_strategy_options_parseFromJSON(jsonv1beta1_supplemental_groups_strategy_options_1);
	cJSON* jsonv1beta1_supplemental_groups_strategy_options_2 = v1beta1_supplemental_groups_strategy_options_convertToJSON(v1beta1_supplemental_groups_strategy_options_2);
	printf("repeating v1beta1_supplemental_groups_strategy_options:\n%s\n", cJSON_Print(jsonv1beta1_supplemental_groups_strategy_options_2));
}

int main() {
  test_v1beta1_supplemental_groups_strategy_options(1);
  test_v1beta1_supplemental_groups_strategy_options(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_supplemental_groups_strategy_options_MAIN
#endif // v1beta1_supplemental_groups_strategy_options_TEST
