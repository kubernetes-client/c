#ifndef v1_status_details_TEST
#define v1_status_details_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_status_details_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_status_details.h"
v1_status_details_t* instantiate_v1_status_details(int include_optional);



v1_status_details_t* instantiate_v1_status_details(int include_optional) {
  v1_status_details_t* v1_status_details = NULL;
  if (include_optional) {
    v1_status_details = v1_status_details_create(
      list_create(),
      "0",
      "0",
      "0",
      56,
      "0"
    );
  } else {
    v1_status_details = v1_status_details_create(
      list_create(),
      "0",
      "0",
      "0",
      56,
      "0"
    );
  }

  return v1_status_details;
}


#ifdef v1_status_details_MAIN

void test_v1_status_details(int include_optional) {
    v1_status_details_t* v1_status_details_1 = instantiate_v1_status_details(include_optional);

	cJSON* jsonv1_status_details_1 = v1_status_details_convertToJSON(v1_status_details_1);
	printf("v1_status_details :\n%s\n", cJSON_Print(jsonv1_status_details_1));
	v1_status_details_t* v1_status_details_2 = v1_status_details_parseFromJSON(jsonv1_status_details_1);
	cJSON* jsonv1_status_details_2 = v1_status_details_convertToJSON(v1_status_details_2);
	printf("repeating v1_status_details:\n%s\n", cJSON_Print(jsonv1_status_details_2));
}

int main() {
  test_v1_status_details(1);
  test_v1_status_details(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_status_details_MAIN
#endif // v1_status_details_TEST
