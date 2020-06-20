#ifndef v2beta2_metric_value_status_TEST
#define v2beta2_metric_value_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v2beta2_metric_value_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v2beta2_metric_value_status.h"
v2beta2_metric_value_status_t* instantiate_v2beta2_metric_value_status(int include_optional);



v2beta2_metric_value_status_t* instantiate_v2beta2_metric_value_status(int include_optional) {
  v2beta2_metric_value_status_t* v2beta2_metric_value_status = NULL;
  if (include_optional) {
    v2beta2_metric_value_status = v2beta2_metric_value_status_create(
      56,
      "0",
      "0"
    );
  } else {
    v2beta2_metric_value_status = v2beta2_metric_value_status_create(
      56,
      "0",
      "0"
    );
  }

  return v2beta2_metric_value_status;
}


#ifdef v2beta2_metric_value_status_MAIN

void test_v2beta2_metric_value_status(int include_optional) {
    v2beta2_metric_value_status_t* v2beta2_metric_value_status_1 = instantiate_v2beta2_metric_value_status(include_optional);

	cJSON* jsonv2beta2_metric_value_status_1 = v2beta2_metric_value_status_convertToJSON(v2beta2_metric_value_status_1);
	printf("v2beta2_metric_value_status :\n%s\n", cJSON_Print(jsonv2beta2_metric_value_status_1));
	v2beta2_metric_value_status_t* v2beta2_metric_value_status_2 = v2beta2_metric_value_status_parseFromJSON(jsonv2beta2_metric_value_status_1);
	cJSON* jsonv2beta2_metric_value_status_2 = v2beta2_metric_value_status_convertToJSON(v2beta2_metric_value_status_2);
	printf("repeating v2beta2_metric_value_status:\n%s\n", cJSON_Print(jsonv2beta2_metric_value_status_2));
}

int main() {
  test_v2beta2_metric_value_status(1);
  test_v2beta2_metric_value_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // v2beta2_metric_value_status_MAIN
#endif // v2beta2_metric_value_status_TEST
