#ifndef v1_user_info_TEST
#define v1_user_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_user_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_user_info.h"
v1_user_info_t* instantiate_v1_user_info(int include_optional);



v1_user_info_t* instantiate_v1_user_info(int include_optional) {
  v1_user_info_t* v1_user_info = NULL;
  if (include_optional) {
    v1_user_info = v1_user_info_create(
      list_create(),
      list_create(),
      "0",
      "0"
    );
  } else {
    v1_user_info = v1_user_info_create(
      list_create(),
      list_create(),
      "0",
      "0"
    );
  }

  return v1_user_info;
}


#ifdef v1_user_info_MAIN

void test_v1_user_info(int include_optional) {
    v1_user_info_t* v1_user_info_1 = instantiate_v1_user_info(include_optional);

	cJSON* jsonv1_user_info_1 = v1_user_info_convertToJSON(v1_user_info_1);
	printf("v1_user_info :\n%s\n", cJSON_Print(jsonv1_user_info_1));
	v1_user_info_t* v1_user_info_2 = v1_user_info_parseFromJSON(jsonv1_user_info_1);
	cJSON* jsonv1_user_info_2 = v1_user_info_convertToJSON(v1_user_info_2);
	printf("repeating v1_user_info:\n%s\n", cJSON_Print(jsonv1_user_info_2));
}

int main() {
  test_v1_user_info(1);
  test_v1_user_info(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_user_info_MAIN
#endif // v1_user_info_TEST
