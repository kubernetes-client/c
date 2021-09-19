#ifndef events_v1_event_series_TEST
#define events_v1_event_series_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define events_v1_event_series_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/events_v1_event_series.h"
events_v1_event_series_t* instantiate_events_v1_event_series(int include_optional);



events_v1_event_series_t* instantiate_events_v1_event_series(int include_optional) {
  events_v1_event_series_t* events_v1_event_series = NULL;
  if (include_optional) {
    events_v1_event_series = events_v1_event_series_create(
      56,
      "2013-10-20T19:20:30+01:00"
    );
  } else {
    events_v1_event_series = events_v1_event_series_create(
      56,
      "2013-10-20T19:20:30+01:00"
    );
  }

  return events_v1_event_series;
}


#ifdef events_v1_event_series_MAIN

void test_events_v1_event_series(int include_optional) {
    events_v1_event_series_t* events_v1_event_series_1 = instantiate_events_v1_event_series(include_optional);

	cJSON* jsonevents_v1_event_series_1 = events_v1_event_series_convertToJSON(events_v1_event_series_1);
	printf("events_v1_event_series :\n%s\n", cJSON_Print(jsonevents_v1_event_series_1));
	events_v1_event_series_t* events_v1_event_series_2 = events_v1_event_series_parseFromJSON(jsonevents_v1_event_series_1);
	cJSON* jsonevents_v1_event_series_2 = events_v1_event_series_convertToJSON(events_v1_event_series_2);
	printf("repeating events_v1_event_series:\n%s\n", cJSON_Print(jsonevents_v1_event_series_2));
}

int main() {
  test_events_v1_event_series(1);
  test_events_v1_event_series(0);

  printf("Hello world \n");
  return 0;
}

#endif // events_v1_event_series_MAIN
#endif // events_v1_event_series_TEST
