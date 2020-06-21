#ifndef v1_key_to_path_TEST
#define v1_key_to_path_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_key_to_path_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_key_to_path.h"
v1_key_to_path_t* instantiate_v1_key_to_path(int include_optional);



v1_key_to_path_t* instantiate_v1_key_to_path(int include_optional) {
  v1_key_to_path_t* v1_key_to_path = NULL;
  if (include_optional) {
    v1_key_to_path = v1_key_to_path_create(
      "0",
      56,
      "0"
    );
  } else {
    v1_key_to_path = v1_key_to_path_create(
      "0",
      56,
      "0"
    );
  }

  return v1_key_to_path;
}


#ifdef v1_key_to_path_MAIN

void test_v1_key_to_path(int include_optional) {
    v1_key_to_path_t* v1_key_to_path_1 = instantiate_v1_key_to_path(include_optional);

	cJSON* jsonv1_key_to_path_1 = v1_key_to_path_convertToJSON(v1_key_to_path_1);
	printf("v1_key_to_path :\n%s\n", cJSON_Print(jsonv1_key_to_path_1));
	v1_key_to_path_t* v1_key_to_path_2 = v1_key_to_path_parseFromJSON(jsonv1_key_to_path_1);
	cJSON* jsonv1_key_to_path_2 = v1_key_to_path_convertToJSON(v1_key_to_path_2);
	printf("repeating v1_key_to_path:\n%s\n", cJSON_Print(jsonv1_key_to_path_2));
}

int main() {
  test_v1_key_to_path(1);
  test_v1_key_to_path(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_key_to_path_MAIN
#endif // v1_key_to_path_TEST
