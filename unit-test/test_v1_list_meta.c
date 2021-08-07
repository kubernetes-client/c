#ifndef v1_list_meta_TEST
#define v1_list_meta_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_list_meta_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_list_meta.h"
v1_list_meta_t* instantiate_v1_list_meta(int include_optional);



v1_list_meta_t* instantiate_v1_list_meta(int include_optional) {
  v1_list_meta_t* v1_list_meta = NULL;
  if (include_optional) {
    v1_list_meta = v1_list_meta_create(
      "0",
      56,
      "0",
      "0"
    );
  } else {
    v1_list_meta = v1_list_meta_create(
      "0",
      56,
      "0",
      "0"
    );
  }

  return v1_list_meta;
}


#ifdef v1_list_meta_MAIN

void test_v1_list_meta(int include_optional) {
    v1_list_meta_t* v1_list_meta_1 = instantiate_v1_list_meta(include_optional);

	cJSON* jsonv1_list_meta_1 = v1_list_meta_convertToJSON(v1_list_meta_1);
	printf("v1_list_meta :\n%s\n", cJSON_Print(jsonv1_list_meta_1));
	v1_list_meta_t* v1_list_meta_2 = v1_list_meta_parseFromJSON(jsonv1_list_meta_1);
	cJSON* jsonv1_list_meta_2 = v1_list_meta_convertToJSON(v1_list_meta_2);
	printf("repeating v1_list_meta:\n%s\n", cJSON_Print(jsonv1_list_meta_2));
}

int main() {
  test_v1_list_meta(1);
  test_v1_list_meta(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_list_meta_MAIN
#endif // v1_list_meta_TEST
