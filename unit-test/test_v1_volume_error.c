#ifndef v1_volume_error_TEST
#define v1_volume_error_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_volume_error_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_volume_error.h"
v1_volume_error_t* instantiate_v1_volume_error(int include_optional);



v1_volume_error_t* instantiate_v1_volume_error(int include_optional) {
  v1_volume_error_t* v1_volume_error = NULL;
  if (include_optional) {
    v1_volume_error = v1_volume_error_create(
      "0",
      "2013-10-20T19:20:30+01:00"
    );
  } else {
    v1_volume_error = v1_volume_error_create(
      "0",
      "2013-10-20T19:20:30+01:00"
    );
  }

  return v1_volume_error;
}


#ifdef v1_volume_error_MAIN

void test_v1_volume_error(int include_optional) {
    v1_volume_error_t* v1_volume_error_1 = instantiate_v1_volume_error(include_optional);

	cJSON* jsonv1_volume_error_1 = v1_volume_error_convertToJSON(v1_volume_error_1);
	printf("v1_volume_error :\n%s\n", cJSON_Print(jsonv1_volume_error_1));
	v1_volume_error_t* v1_volume_error_2 = v1_volume_error_parseFromJSON(jsonv1_volume_error_1);
	cJSON* jsonv1_volume_error_2 = v1_volume_error_convertToJSON(v1_volume_error_2);
	printf("repeating v1_volume_error:\n%s\n", cJSON_Print(jsonv1_volume_error_2));
}

int main() {
  test_v1_volume_error(1);
  test_v1_volume_error(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_volume_error_MAIN
#endif // v1_volume_error_TEST
