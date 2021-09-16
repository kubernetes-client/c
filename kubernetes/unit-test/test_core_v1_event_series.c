#ifndef core_v1_event_series_TEST
#define core_v1_event_series_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define core_v1_event_series_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/core_v1_event_series.h"
core_v1_event_series_t* instantiate_core_v1_event_series(int include_optional);



core_v1_event_series_t* instantiate_core_v1_event_series(int include_optional) {
  core_v1_event_series_t* core_v1_event_series = NULL;
  if (include_optional) {
    core_v1_event_series = core_v1_event_series_create(
      56,
      "2013-10-20T19:20:30+01:00"
    );
  } else {
    core_v1_event_series = core_v1_event_series_create(
      56,
      "2013-10-20T19:20:30+01:00"
    );
  }

  return core_v1_event_series;
}


#ifdef core_v1_event_series_MAIN

void test_core_v1_event_series(int include_optional) {
    core_v1_event_series_t* core_v1_event_series_1 = instantiate_core_v1_event_series(include_optional);

	cJSON* jsoncore_v1_event_series_1 = core_v1_event_series_convertToJSON(core_v1_event_series_1);
	printf("core_v1_event_series :\n%s\n", cJSON_Print(jsoncore_v1_event_series_1));
	core_v1_event_series_t* core_v1_event_series_2 = core_v1_event_series_parseFromJSON(jsoncore_v1_event_series_1);
	cJSON* jsoncore_v1_event_series_2 = core_v1_event_series_convertToJSON(core_v1_event_series_2);
	printf("repeating core_v1_event_series:\n%s\n", cJSON_Print(jsoncore_v1_event_series_2));
}

int main() {
  test_core_v1_event_series(1);
  test_core_v1_event_series(0);

  printf("Hello world \n");
  return 0;
}

#endif // core_v1_event_series_MAIN
#endif // core_v1_event_series_TEST
