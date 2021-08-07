#ifndef v1_container_state_terminated_TEST
#define v1_container_state_terminated_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_container_state_terminated_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_container_state_terminated.h"
v1_container_state_terminated_t* instantiate_v1_container_state_terminated(int include_optional);



v1_container_state_terminated_t* instantiate_v1_container_state_terminated(int include_optional) {
  v1_container_state_terminated_t* v1_container_state_terminated = NULL;
  if (include_optional) {
    v1_container_state_terminated = v1_container_state_terminated_create(
      "0",
      56,
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      56,
      "2013-10-20T19:20:30+01:00"
    );
  } else {
    v1_container_state_terminated = v1_container_state_terminated_create(
      "0",
      56,
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      56,
      "2013-10-20T19:20:30+01:00"
    );
  }

  return v1_container_state_terminated;
}


#ifdef v1_container_state_terminated_MAIN

void test_v1_container_state_terminated(int include_optional) {
    v1_container_state_terminated_t* v1_container_state_terminated_1 = instantiate_v1_container_state_terminated(include_optional);

	cJSON* jsonv1_container_state_terminated_1 = v1_container_state_terminated_convertToJSON(v1_container_state_terminated_1);
	printf("v1_container_state_terminated :\n%s\n", cJSON_Print(jsonv1_container_state_terminated_1));
	v1_container_state_terminated_t* v1_container_state_terminated_2 = v1_container_state_terminated_parseFromJSON(jsonv1_container_state_terminated_1);
	cJSON* jsonv1_container_state_terminated_2 = v1_container_state_terminated_convertToJSON(v1_container_state_terminated_2);
	printf("repeating v1_container_state_terminated:\n%s\n", cJSON_Print(jsonv1_container_state_terminated_2));
}

int main() {
  test_v1_container_state_terminated(1);
  test_v1_container_state_terminated(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_container_state_terminated_MAIN
#endif // v1_container_state_terminated_TEST
