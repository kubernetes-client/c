#ifndef v2_metric_spec_TEST
#define v2_metric_spec_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v2_metric_spec_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v2_metric_spec.h"
v2_metric_spec_t* instantiate_v2_metric_spec(int include_optional);

#include "test_v2_container_resource_metric_source.c"
#include "test_v2_external_metric_source.c"
#include "test_v2_object_metric_source.c"
#include "test_v2_pods_metric_source.c"
#include "test_v2_resource_metric_source.c"


v2_metric_spec_t* instantiate_v2_metric_spec(int include_optional) {
  v2_metric_spec_t* v2_metric_spec = NULL;
  if (include_optional) {
    v2_metric_spec = v2_metric_spec_create(
       // false, not to have infinite recursion
      instantiate_v2_container_resource_metric_source(0),
       // false, not to have infinite recursion
      instantiate_v2_external_metric_source(0),
       // false, not to have infinite recursion
      instantiate_v2_object_metric_source(0),
       // false, not to have infinite recursion
      instantiate_v2_pods_metric_source(0),
       // false, not to have infinite recursion
      instantiate_v2_resource_metric_source(0),
      "0"
    );
  } else {
    v2_metric_spec = v2_metric_spec_create(
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      "0"
    );
  }

  return v2_metric_spec;
}


#ifdef v2_metric_spec_MAIN

void test_v2_metric_spec(int include_optional) {
    v2_metric_spec_t* v2_metric_spec_1 = instantiate_v2_metric_spec(include_optional);

	cJSON* jsonv2_metric_spec_1 = v2_metric_spec_convertToJSON(v2_metric_spec_1);
	printf("v2_metric_spec :\n%s\n", cJSON_Print(jsonv2_metric_spec_1));
	v2_metric_spec_t* v2_metric_spec_2 = v2_metric_spec_parseFromJSON(jsonv2_metric_spec_1);
	cJSON* jsonv2_metric_spec_2 = v2_metric_spec_convertToJSON(v2_metric_spec_2);
	printf("repeating v2_metric_spec:\n%s\n", cJSON_Print(jsonv2_metric_spec_2));
}

int main() {
  test_v2_metric_spec(1);
  test_v2_metric_spec(0);

  printf("Hello world \n");
  return 0;
}

#endif // v2_metric_spec_MAIN
#endif // v2_metric_spec_TEST
