#ifndef core_v1_event_TEST
#define core_v1_event_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define core_v1_event_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/core_v1_event.h"
core_v1_event_t* instantiate_core_v1_event(int include_optional);

#include "test_v1_object_reference.c"
#include "test_v1_object_meta.c"
#include "test_v1_object_reference.c"
#include "test_core_v1_event_series.c"
#include "test_v1_event_source.c"


core_v1_event_t* instantiate_core_v1_event(int include_optional) {
  core_v1_event_t* core_v1_event = NULL;
  if (include_optional) {
    core_v1_event = core_v1_event_create(
      "0",
      "0",
      56,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
       // false, not to have infinite recursion
      instantiate_v1_object_reference(0),
      "0",
      "2013-10-20T19:20:30+01:00",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_reference(0),
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_core_v1_event_series(0),
       // false, not to have infinite recursion
      instantiate_v1_event_source(0),
      "0"
    );
  } else {
    core_v1_event = core_v1_event_create(
      "0",
      "0",
      56,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      NULL,
      "0",
      "2013-10-20T19:20:30+01:00",
      "0",
      NULL,
      "0",
      NULL,
      "0",
      "0",
      NULL,
      NULL,
      "0"
    );
  }

  return core_v1_event;
}


#ifdef core_v1_event_MAIN

void test_core_v1_event(int include_optional) {
    core_v1_event_t* core_v1_event_1 = instantiate_core_v1_event(include_optional);

	cJSON* jsoncore_v1_event_1 = core_v1_event_convertToJSON(core_v1_event_1);
	printf("core_v1_event :\n%s\n", cJSON_Print(jsoncore_v1_event_1));
	core_v1_event_t* core_v1_event_2 = core_v1_event_parseFromJSON(jsoncore_v1_event_1);
	cJSON* jsoncore_v1_event_2 = core_v1_event_convertToJSON(core_v1_event_2);
	printf("repeating core_v1_event:\n%s\n", cJSON_Print(jsoncore_v1_event_2));
}

int main() {
  test_core_v1_event(1);
  test_core_v1_event(0);

  printf("Hello world \n");
  return 0;
}

#endif // core_v1_event_MAIN
#endif // core_v1_event_TEST
