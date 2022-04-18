#ifndef v2_metric_identifier_TEST
#define v2_metric_identifier_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v2_metric_identifier_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v2_metric_identifier.h"
v2_metric_identifier_t* instantiate_v2_metric_identifier(int include_optional);

#include "test_v1_label_selector.c"


v2_metric_identifier_t* instantiate_v2_metric_identifier(int include_optional) {
  v2_metric_identifier_t* v2_metric_identifier = NULL;
  if (include_optional) {
    v2_metric_identifier = v2_metric_identifier_create(
      "0",
       // false, not to have infinite recursion
      instantiate_v1_label_selector(0)
    );
  } else {
    v2_metric_identifier = v2_metric_identifier_create(
      "0",
      NULL
    );
  }

  return v2_metric_identifier;
}


#ifdef v2_metric_identifier_MAIN

void test_v2_metric_identifier(int include_optional) {
    v2_metric_identifier_t* v2_metric_identifier_1 = instantiate_v2_metric_identifier(include_optional);

	cJSON* jsonv2_metric_identifier_1 = v2_metric_identifier_convertToJSON(v2_metric_identifier_1);
	printf("v2_metric_identifier :\n%s\n", cJSON_Print(jsonv2_metric_identifier_1));
	v2_metric_identifier_t* v2_metric_identifier_2 = v2_metric_identifier_parseFromJSON(jsonv2_metric_identifier_1);
	cJSON* jsonv2_metric_identifier_2 = v2_metric_identifier_convertToJSON(v2_metric_identifier_2);
	printf("repeating v2_metric_identifier:\n%s\n", cJSON_Print(jsonv2_metric_identifier_2));
}

int main() {
  test_v2_metric_identifier(1);
  test_v2_metric_identifier(0);

  printf("Hello world \n");
  return 0;
}

#endif // v2_metric_identifier_MAIN
#endif // v2_metric_identifier_TEST
