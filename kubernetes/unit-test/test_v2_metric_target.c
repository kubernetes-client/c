#ifndef v2_metric_target_TEST
#define v2_metric_target_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v2_metric_target_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v2_metric_target.h"
v2_metric_target_t* instantiate_v2_metric_target(int include_optional);



v2_metric_target_t* instantiate_v2_metric_target(int include_optional) {
  v2_metric_target_t* v2_metric_target = NULL;
  if (include_optional) {
    v2_metric_target = v2_metric_target_create(
      56,
      "0",
      "0",
      "0"
    );
  } else {
    v2_metric_target = v2_metric_target_create(
      56,
      "0",
      "0",
      "0"
    );
  }

  return v2_metric_target;
}


#ifdef v2_metric_target_MAIN

void test_v2_metric_target(int include_optional) {
    v2_metric_target_t* v2_metric_target_1 = instantiate_v2_metric_target(include_optional);

	cJSON* jsonv2_metric_target_1 = v2_metric_target_convertToJSON(v2_metric_target_1);
	printf("v2_metric_target :\n%s\n", cJSON_Print(jsonv2_metric_target_1));
	v2_metric_target_t* v2_metric_target_2 = v2_metric_target_parseFromJSON(jsonv2_metric_target_1);
	cJSON* jsonv2_metric_target_2 = v2_metric_target_convertToJSON(v2_metric_target_2);
	printf("repeating v2_metric_target:\n%s\n", cJSON_Print(jsonv2_metric_target_2));
}

int main() {
  test_v2_metric_target(1);
  test_v2_metric_target(0);

  printf("Hello world \n");
  return 0;
}

#endif // v2_metric_target_MAIN
#endif // v2_metric_target_TEST
