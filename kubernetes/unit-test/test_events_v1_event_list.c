#ifndef events_v1_event_list_TEST
#define events_v1_event_list_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define events_v1_event_list_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/events_v1_event_list.h"
events_v1_event_list_t* instantiate_events_v1_event_list(int include_optional);

#include "test_v1_list_meta.c"


events_v1_event_list_t* instantiate_events_v1_event_list(int include_optional) {
  events_v1_event_list_t* events_v1_event_list = NULL;
  if (include_optional) {
    events_v1_event_list = events_v1_event_list_create(
      "0",
      list_create(),
      "0",
       // false, not to have infinite recursion
      instantiate_v1_list_meta(0)
    );
  } else {
    events_v1_event_list = events_v1_event_list_create(
      "0",
      list_create(),
      "0",
      NULL
    );
  }

  return events_v1_event_list;
}


#ifdef events_v1_event_list_MAIN

void test_events_v1_event_list(int include_optional) {
    events_v1_event_list_t* events_v1_event_list_1 = instantiate_events_v1_event_list(include_optional);

	cJSON* jsonevents_v1_event_list_1 = events_v1_event_list_convertToJSON(events_v1_event_list_1);
	printf("events_v1_event_list :\n%s\n", cJSON_Print(jsonevents_v1_event_list_1));
	events_v1_event_list_t* events_v1_event_list_2 = events_v1_event_list_parseFromJSON(jsonevents_v1_event_list_1);
	cJSON* jsonevents_v1_event_list_2 = events_v1_event_list_convertToJSON(events_v1_event_list_2);
	printf("repeating events_v1_event_list:\n%s\n", cJSON_Print(jsonevents_v1_event_list_2));
}

int main() {
  test_events_v1_event_list(1);
  test_events_v1_event_list(0);

  printf("Hello world \n");
  return 0;
}

#endif // events_v1_event_list_MAIN
#endif // events_v1_event_list_TEST
