#ifndef v1_container_state_TEST
#define v1_container_state_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_container_state_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_container_state.h"
v1_container_state_t* instantiate_v1_container_state(int include_optional);

#include "test_v1_container_state_running.c"
#include "test_v1_container_state_terminated.c"
#include "test_v1_container_state_waiting.c"


v1_container_state_t* instantiate_v1_container_state(int include_optional) {
  v1_container_state_t* v1_container_state = NULL;
  if (include_optional) {
    v1_container_state = v1_container_state_create(
       // false, not to have infinite recursion
      instantiate_v1_container_state_running(0),
       // false, not to have infinite recursion
      instantiate_v1_container_state_terminated(0),
       // false, not to have infinite recursion
      instantiate_v1_container_state_waiting(0)
    );
  } else {
    v1_container_state = v1_container_state_create(
      NULL,
      NULL,
      NULL
    );
  }

  return v1_container_state;
}


#ifdef v1_container_state_MAIN

void test_v1_container_state(int include_optional) {
    v1_container_state_t* v1_container_state_1 = instantiate_v1_container_state(include_optional);

	cJSON* jsonv1_container_state_1 = v1_container_state_convertToJSON(v1_container_state_1);
	printf("v1_container_state :\n%s\n", cJSON_Print(jsonv1_container_state_1));
	v1_container_state_t* v1_container_state_2 = v1_container_state_parseFromJSON(jsonv1_container_state_1);
	cJSON* jsonv1_container_state_2 = v1_container_state_convertToJSON(v1_container_state_2);
	printf("repeating v1_container_state:\n%s\n", cJSON_Print(jsonv1_container_state_2));
}

int main() {
  test_v1_container_state(1);
  test_v1_container_state(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_container_state_MAIN
#endif // v1_container_state_TEST
