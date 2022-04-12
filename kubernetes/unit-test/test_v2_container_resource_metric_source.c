#ifndef v2_container_resource_metric_source_TEST
#define v2_container_resource_metric_source_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v2_container_resource_metric_source_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v2_container_resource_metric_source.h"
v2_container_resource_metric_source_t* instantiate_v2_container_resource_metric_source(int include_optional);

#include "test_v2_metric_target.c"


v2_container_resource_metric_source_t* instantiate_v2_container_resource_metric_source(int include_optional) {
  v2_container_resource_metric_source_t* v2_container_resource_metric_source = NULL;
  if (include_optional) {
    v2_container_resource_metric_source = v2_container_resource_metric_source_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v2_metric_target(0)
    );
  } else {
    v2_container_resource_metric_source = v2_container_resource_metric_source_create(
      "0",
      "0",
      NULL
    );
  }

  return v2_container_resource_metric_source;
}


#ifdef v2_container_resource_metric_source_MAIN

void test_v2_container_resource_metric_source(int include_optional) {
    v2_container_resource_metric_source_t* v2_container_resource_metric_source_1 = instantiate_v2_container_resource_metric_source(include_optional);

	cJSON* jsonv2_container_resource_metric_source_1 = v2_container_resource_metric_source_convertToJSON(v2_container_resource_metric_source_1);
	printf("v2_container_resource_metric_source :\n%s\n", cJSON_Print(jsonv2_container_resource_metric_source_1));
	v2_container_resource_metric_source_t* v2_container_resource_metric_source_2 = v2_container_resource_metric_source_parseFromJSON(jsonv2_container_resource_metric_source_1);
	cJSON* jsonv2_container_resource_metric_source_2 = v2_container_resource_metric_source_convertToJSON(v2_container_resource_metric_source_2);
	printf("repeating v2_container_resource_metric_source:\n%s\n", cJSON_Print(jsonv2_container_resource_metric_source_2));
}

int main() {
  test_v2_container_resource_metric_source(1);
  test_v2_container_resource_metric_source(0);

  printf("Hello world \n");
  return 0;
}

#endif // v2_container_resource_metric_source_MAIN
#endif // v2_container_resource_metric_source_TEST
