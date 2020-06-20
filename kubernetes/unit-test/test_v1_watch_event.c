#ifndef v1_watch_event_TEST
#define v1_watch_event_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_watch_event_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_watch_event.h"
v1_watch_event_t* instantiate_v1_watch_event(int include_optional);



v1_watch_event_t* instantiate_v1_watch_event(int include_optional) {
  v1_watch_event_t* v1_watch_event = NULL;
  if (include_optional) {
    v1_watch_event = v1_watch_event_create(
      0,
      "0"
    );
  } else {
    v1_watch_event = v1_watch_event_create(
      0,
      "0"
    );
  }

  return v1_watch_event;
}


#ifdef v1_watch_event_MAIN

void test_v1_watch_event(int include_optional) {
    v1_watch_event_t* v1_watch_event_1 = instantiate_v1_watch_event(include_optional);

	cJSON* jsonv1_watch_event_1 = v1_watch_event_convertToJSON(v1_watch_event_1);
	printf("v1_watch_event :\n%s\n", cJSON_Print(jsonv1_watch_event_1));
	v1_watch_event_t* v1_watch_event_2 = v1_watch_event_parseFromJSON(jsonv1_watch_event_1);
	cJSON* jsonv1_watch_event_2 = v1_watch_event_convertToJSON(v1_watch_event_2);
	printf("repeating v1_watch_event:\n%s\n", cJSON_Print(jsonv1_watch_event_2));
}

int main() {
  test_v1_watch_event(1);
  test_v1_watch_event(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_watch_event_MAIN
#endif // v1_watch_event_TEST
