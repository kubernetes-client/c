#ifndef v2beta1_object_metric_source_TEST
#define v2beta1_object_metric_source_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v2beta1_object_metric_source_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v2beta1_object_metric_source.h"
v2beta1_object_metric_source_t* instantiate_v2beta1_object_metric_source(int include_optional);

#include "test_v1_label_selector.c"
#include "test_v2beta1_cross_version_object_reference.c"


v2beta1_object_metric_source_t* instantiate_v2beta1_object_metric_source(int include_optional) {
  v2beta1_object_metric_source_t* v2beta1_object_metric_source = NULL;
  if (include_optional) {
    v2beta1_object_metric_source = v2beta1_object_metric_source_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_label_selector(0),
       // false, not to have infinite recursion
      instantiate_v2beta1_cross_version_object_reference(0),
      "0"
    );
  } else {
    v2beta1_object_metric_source = v2beta1_object_metric_source_create(
      "0",
      "0",
      NULL,
      NULL,
      "0"
    );
  }

  return v2beta1_object_metric_source;
}


#ifdef v2beta1_object_metric_source_MAIN

void test_v2beta1_object_metric_source(int include_optional) {
    v2beta1_object_metric_source_t* v2beta1_object_metric_source_1 = instantiate_v2beta1_object_metric_source(include_optional);

	cJSON* jsonv2beta1_object_metric_source_1 = v2beta1_object_metric_source_convertToJSON(v2beta1_object_metric_source_1);
	printf("v2beta1_object_metric_source :\n%s\n", cJSON_Print(jsonv2beta1_object_metric_source_1));
	v2beta1_object_metric_source_t* v2beta1_object_metric_source_2 = v2beta1_object_metric_source_parseFromJSON(jsonv2beta1_object_metric_source_1);
	cJSON* jsonv2beta1_object_metric_source_2 = v2beta1_object_metric_source_convertToJSON(v2beta1_object_metric_source_2);
	printf("repeating v2beta1_object_metric_source:\n%s\n", cJSON_Print(jsonv2beta1_object_metric_source_2));
}

int main() {
  test_v2beta1_object_metric_source(1);
  test_v2beta1_object_metric_source(0);

  printf("Hello world \n");
  return 0;
}

#endif // v2beta1_object_metric_source_MAIN
#endif // v2beta1_object_metric_source_TEST
