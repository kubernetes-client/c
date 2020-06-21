#ifndef v1alpha1_flow_schema_TEST
#define v1alpha1_flow_schema_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha1_flow_schema_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha1_flow_schema.h"
v1alpha1_flow_schema_t* instantiate_v1alpha1_flow_schema(int include_optional);

#include "test_v1_object_meta.c"
#include "test_v1alpha1_flow_schema_spec.c"
#include "test_v1alpha1_flow_schema_status.c"


v1alpha1_flow_schema_t* instantiate_v1alpha1_flow_schema(int include_optional) {
  v1alpha1_flow_schema_t* v1alpha1_flow_schema = NULL;
  if (include_optional) {
    v1alpha1_flow_schema = v1alpha1_flow_schema_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
       // false, not to have infinite recursion
      instantiate_v1alpha1_flow_schema_spec(0),
       // false, not to have infinite recursion
      instantiate_v1alpha1_flow_schema_status(0)
    );
  } else {
    v1alpha1_flow_schema = v1alpha1_flow_schema_create(
      "0",
      "0",
      NULL,
      NULL,
      NULL
    );
  }

  return v1alpha1_flow_schema;
}


#ifdef v1alpha1_flow_schema_MAIN

void test_v1alpha1_flow_schema(int include_optional) {
    v1alpha1_flow_schema_t* v1alpha1_flow_schema_1 = instantiate_v1alpha1_flow_schema(include_optional);

	cJSON* jsonv1alpha1_flow_schema_1 = v1alpha1_flow_schema_convertToJSON(v1alpha1_flow_schema_1);
	printf("v1alpha1_flow_schema :\n%s\n", cJSON_Print(jsonv1alpha1_flow_schema_1));
	v1alpha1_flow_schema_t* v1alpha1_flow_schema_2 = v1alpha1_flow_schema_parseFromJSON(jsonv1alpha1_flow_schema_1);
	cJSON* jsonv1alpha1_flow_schema_2 = v1alpha1_flow_schema_convertToJSON(v1alpha1_flow_schema_2);
	printf("repeating v1alpha1_flow_schema:\n%s\n", cJSON_Print(jsonv1alpha1_flow_schema_2));
}

int main() {
  test_v1alpha1_flow_schema(1);
  test_v1alpha1_flow_schema(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha1_flow_schema_MAIN
#endif // v1alpha1_flow_schema_TEST
