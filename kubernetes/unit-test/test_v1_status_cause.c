#ifndef v1_status_cause_TEST
#define v1_status_cause_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_status_cause_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_status_cause.h"
v1_status_cause_t* instantiate_v1_status_cause(int include_optional);



v1_status_cause_t* instantiate_v1_status_cause(int include_optional) {
  v1_status_cause_t* v1_status_cause = NULL;
  if (include_optional) {
    v1_status_cause = v1_status_cause_create(
      "0",
      "0",
      "0"
    );
  } else {
    v1_status_cause = v1_status_cause_create(
      "0",
      "0",
      "0"
    );
  }

  return v1_status_cause;
}


#ifdef v1_status_cause_MAIN

void test_v1_status_cause(int include_optional) {
    v1_status_cause_t* v1_status_cause_1 = instantiate_v1_status_cause(include_optional);

	cJSON* jsonv1_status_cause_1 = v1_status_cause_convertToJSON(v1_status_cause_1);
	printf("v1_status_cause :\n%s\n", cJSON_Print(jsonv1_status_cause_1));
	v1_status_cause_t* v1_status_cause_2 = v1_status_cause_parseFromJSON(jsonv1_status_cause_1);
	cJSON* jsonv1_status_cause_2 = v1_status_cause_convertToJSON(v1_status_cause_2);
	printf("repeating v1_status_cause:\n%s\n", cJSON_Print(jsonv1_status_cause_2));
}

int main() {
  test_v1_status_cause(1);
  test_v1_status_cause(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_status_cause_MAIN
#endif // v1_status_cause_TEST
