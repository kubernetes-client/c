#ifndef v1_scale_TEST
#define v1_scale_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_scale_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_scale.h"
v1_scale_t* instantiate_v1_scale(int include_optional);

#include "test_v1_object_meta.c"
#include "test_v1_scale_spec.c"
#include "test_v1_scale_status.c"


v1_scale_t* instantiate_v1_scale(int include_optional) {
  v1_scale_t* v1_scale = NULL;
  if (include_optional) {
    v1_scale = v1_scale_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
       // false, not to have infinite recursion
      instantiate_v1_scale_spec(0),
       // false, not to have infinite recursion
      instantiate_v1_scale_status(0)
    );
  } else {
    v1_scale = v1_scale_create(
      "0",
      "0",
      NULL,
      NULL,
      NULL
    );
  }

  return v1_scale;
}


#ifdef v1_scale_MAIN

void test_v1_scale(int include_optional) {
    v1_scale_t* v1_scale_1 = instantiate_v1_scale(include_optional);

	cJSON* jsonv1_scale_1 = v1_scale_convertToJSON(v1_scale_1);
	printf("v1_scale :\n%s\n", cJSON_Print(jsonv1_scale_1));
	v1_scale_t* v1_scale_2 = v1_scale_parseFromJSON(jsonv1_scale_1);
	cJSON* jsonv1_scale_2 = v1_scale_convertToJSON(v1_scale_2);
	printf("repeating v1_scale:\n%s\n", cJSON_Print(jsonv1_scale_2));
}

int main() {
  test_v1_scale(1);
  test_v1_scale(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_scale_MAIN
#endif // v1_scale_TEST
