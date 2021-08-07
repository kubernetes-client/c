#ifndef v1beta1_json_schema_props_TEST
#define v1beta1_json_schema_props_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_json_schema_props_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_json_schema_props.h"
v1beta1_json_schema_props_t* instantiate_v1beta1_json_schema_props(int include_optional);

#include "test_v1beta1_external_documentation.c"
#include "test_v1beta1_json_schema_props.c"


v1beta1_json_schema_props_t* instantiate_v1beta1_json_schema_props(int include_optional) {
  v1beta1_json_schema_props_t* v1beta1_json_schema_props = NULL;
  if (include_optional) {
    v1beta1_json_schema_props = v1beta1_json_schema_props_create(
      "0",
      "0",
      0,
      0,
      list_create(),
      list_create(),
      0,
      list_create(),
      list_create(),
      "0",
      list_create(),
      0,
      1,
      1,
       // false, not to have infinite recursion
      instantiate_v1beta1_external_documentation(0),
      "0",
      "0",
      0,
      56,
      56,
      56,
      1.337,
      56,
      56,
      56,
      1.337,
      1.337,
       // false, not to have infinite recursion
      instantiate_v1beta1_json_schema_props(0),
      1,
      list_create(),
      "0",
      list_create(),
      list_create(),
      list_create(),
      "0",
      "0",
      1,
      1,
      1,
      list_create(),
      "0",
      "0",
      1
    );
  } else {
    v1beta1_json_schema_props = v1beta1_json_schema_props_create(
      "0",
      "0",
      0,
      0,
      list_create(),
      list_create(),
      0,
      list_create(),
      list_create(),
      "0",
      list_create(),
      0,
      1,
      1,
      NULL,
      "0",
      "0",
      0,
      56,
      56,
      56,
      1.337,
      56,
      56,
      56,
      1.337,
      1.337,
      NULL,
      1,
      list_create(),
      "0",
      list_create(),
      list_create(),
      list_create(),
      "0",
      "0",
      1,
      1,
      1,
      list_create(),
      "0",
      "0",
      1
    );
  }

  return v1beta1_json_schema_props;
}


#ifdef v1beta1_json_schema_props_MAIN

void test_v1beta1_json_schema_props(int include_optional) {
    v1beta1_json_schema_props_t* v1beta1_json_schema_props_1 = instantiate_v1beta1_json_schema_props(include_optional);

	cJSON* jsonv1beta1_json_schema_props_1 = v1beta1_json_schema_props_convertToJSON(v1beta1_json_schema_props_1);
	printf("v1beta1_json_schema_props :\n%s\n", cJSON_Print(jsonv1beta1_json_schema_props_1));
	v1beta1_json_schema_props_t* v1beta1_json_schema_props_2 = v1beta1_json_schema_props_parseFromJSON(jsonv1beta1_json_schema_props_1);
	cJSON* jsonv1beta1_json_schema_props_2 = v1beta1_json_schema_props_convertToJSON(v1beta1_json_schema_props_2);
	printf("repeating v1beta1_json_schema_props:\n%s\n", cJSON_Print(jsonv1beta1_json_schema_props_2));
}

int main() {
  test_v1beta1_json_schema_props(1);
  test_v1beta1_json_schema_props(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_json_schema_props_MAIN
#endif // v1beta1_json_schema_props_TEST
