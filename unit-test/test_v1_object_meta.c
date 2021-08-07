#ifndef v1_object_meta_TEST
#define v1_object_meta_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_object_meta_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_object_meta.h"
v1_object_meta_t* instantiate_v1_object_meta(int include_optional);



v1_object_meta_t* instantiate_v1_object_meta(int include_optional) {
  v1_object_meta_t* v1_object_meta = NULL;
  if (include_optional) {
    v1_object_meta = v1_object_meta_create(
      list_create(),
      "0",
      "2013-10-20T19:20:30+01:00",
      56,
      "2013-10-20T19:20:30+01:00",
      list_create(),
      "0",
      56,
      list_create(),
      list_create(),
      "0",
      "0",
      list_create(),
      "0",
      "0",
      "0"
    );
  } else {
    v1_object_meta = v1_object_meta_create(
      list_create(),
      "0",
      "2013-10-20T19:20:30+01:00",
      56,
      "2013-10-20T19:20:30+01:00",
      list_create(),
      "0",
      56,
      list_create(),
      list_create(),
      "0",
      "0",
      list_create(),
      "0",
      "0",
      "0"
    );
  }

  return v1_object_meta;
}


#ifdef v1_object_meta_MAIN

void test_v1_object_meta(int include_optional) {
    v1_object_meta_t* v1_object_meta_1 = instantiate_v1_object_meta(include_optional);

	cJSON* jsonv1_object_meta_1 = v1_object_meta_convertToJSON(v1_object_meta_1);
	printf("v1_object_meta :\n%s\n", cJSON_Print(jsonv1_object_meta_1));
	v1_object_meta_t* v1_object_meta_2 = v1_object_meta_parseFromJSON(jsonv1_object_meta_1);
	cJSON* jsonv1_object_meta_2 = v1_object_meta_convertToJSON(v1_object_meta_2);
	printf("repeating v1_object_meta:\n%s\n", cJSON_Print(jsonv1_object_meta_2));
}

int main() {
  test_v1_object_meta(1);
  test_v1_object_meta(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_object_meta_MAIN
#endif // v1_object_meta_TEST
