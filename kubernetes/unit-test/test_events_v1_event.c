#ifndef events_v1_event_TEST
#define events_v1_event_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define events_v1_event_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/events_v1_event.h"
events_v1_event_t* instantiate_events_v1_event(int include_optional);

#include "test_v1_event_source.c"
#include "test_v1_object_meta.c"
#include "test_v1_object_reference.c"
#include "test_v1_object_reference.c"
#include "test_events_v1_event_series.c"


events_v1_event_t* instantiate_events_v1_event(int include_optional) {
  events_v1_event_t* events_v1_event = NULL;
  if (include_optional) {
    events_v1_event = events_v1_event_create(
      "0",
      "0",
      56,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
       // false, not to have infinite recursion
      instantiate_v1_event_source(0),
      "2013-10-20T19:20:30+01:00",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_reference(0),
       // false, not to have infinite recursion
      instantiate_v1_object_reference(0),
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_events_v1_event_series(0),
      "0"
    );
  } else {
    events_v1_event = events_v1_event_create(
      "0",
      "0",
      56,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      NULL,
      "2013-10-20T19:20:30+01:00",
      "0",
      NULL,
      "0",
      "0",
      NULL,
      NULL,
      "0",
      "0",
      NULL,
      "0"
    );
  }

  return events_v1_event;
}


#ifdef events_v1_event_MAIN

void test_events_v1_event(int include_optional) {
    events_v1_event_t* events_v1_event_1 = instantiate_events_v1_event(include_optional);

	cJSON* jsonevents_v1_event_1 = events_v1_event_convertToJSON(events_v1_event_1);
	printf("events_v1_event :\n%s\n", cJSON_Print(jsonevents_v1_event_1));
	events_v1_event_t* events_v1_event_2 = events_v1_event_parseFromJSON(jsonevents_v1_event_1);
	cJSON* jsonevents_v1_event_2 = events_v1_event_convertToJSON(events_v1_event_2);
	printf("repeating events_v1_event:\n%s\n", cJSON_Print(jsonevents_v1_event_2));
}

int main() {
  test_events_v1_event(1);
  test_events_v1_event(0);

  printf("Hello world \n");
  return 0;
}

#endif // events_v1_event_MAIN
#endif // events_v1_event_TEST
