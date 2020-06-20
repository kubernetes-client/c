#ifndef v1_scale_status_TEST
#define v1_scale_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_scale_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_scale_status.h"
v1_scale_status_t* instantiate_v1_scale_status(int include_optional);



v1_scale_status_t* instantiate_v1_scale_status(int include_optional) {
  v1_scale_status_t* v1_scale_status = NULL;
  if (include_optional) {
    v1_scale_status = v1_scale_status_create(
      56,
      "0"
    );
  } else {
    v1_scale_status = v1_scale_status_create(
      56,
      "0"
    );
  }

  return v1_scale_status;
}


#ifdef v1_scale_status_MAIN

void test_v1_scale_status(int include_optional) {
    v1_scale_status_t* v1_scale_status_1 = instantiate_v1_scale_status(include_optional);

	cJSON* jsonv1_scale_status_1 = v1_scale_status_convertToJSON(v1_scale_status_1);
	printf("v1_scale_status :\n%s\n", cJSON_Print(jsonv1_scale_status_1));
	v1_scale_status_t* v1_scale_status_2 = v1_scale_status_parseFromJSON(jsonv1_scale_status_1);
	cJSON* jsonv1_scale_status_2 = v1_scale_status_convertToJSON(v1_scale_status_2);
	printf("repeating v1_scale_status:\n%s\n", cJSON_Print(jsonv1_scale_status_2));
}

int main() {
  test_v1_scale_status(1);
  test_v1_scale_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_scale_status_MAIN
#endif // v1_scale_status_TEST
