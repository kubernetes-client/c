#ifndef v1_container_state_running_TEST
#define v1_container_state_running_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_container_state_running_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_container_state_running.h"
v1_container_state_running_t* instantiate_v1_container_state_running(int include_optional);



v1_container_state_running_t* instantiate_v1_container_state_running(int include_optional) {
  v1_container_state_running_t* v1_container_state_running = NULL;
  if (include_optional) {
    v1_container_state_running = v1_container_state_running_create(
      "2013-10-20T19:20:30+01:00"
    );
  } else {
    v1_container_state_running = v1_container_state_running_create(
      "2013-10-20T19:20:30+01:00"
    );
  }

  return v1_container_state_running;
}


#ifdef v1_container_state_running_MAIN

void test_v1_container_state_running(int include_optional) {
    v1_container_state_running_t* v1_container_state_running_1 = instantiate_v1_container_state_running(include_optional);

	cJSON* jsonv1_container_state_running_1 = v1_container_state_running_convertToJSON(v1_container_state_running_1);
	printf("v1_container_state_running :\n%s\n", cJSON_Print(jsonv1_container_state_running_1));
	v1_container_state_running_t* v1_container_state_running_2 = v1_container_state_running_parseFromJSON(jsonv1_container_state_running_1);
	cJSON* jsonv1_container_state_running_2 = v1_container_state_running_convertToJSON(v1_container_state_running_2);
	printf("repeating v1_container_state_running:\n%s\n", cJSON_Print(jsonv1_container_state_running_2));
}

int main() {
  test_v1_container_state_running(1);
  test_v1_container_state_running(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_container_state_running_MAIN
#endif // v1_container_state_running_TEST
