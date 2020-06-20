#ifndef v1_event_series_TEST
#define v1_event_series_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_event_series_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_event_series.h"
v1_event_series_t* instantiate_v1_event_series(int include_optional);



v1_event_series_t* instantiate_v1_event_series(int include_optional) {
  v1_event_series_t* v1_event_series = NULL;
  if (include_optional) {
    v1_event_series = v1_event_series_create(
      56,
      "2013-10-20T19:20:30+01:00",
      "0"
    );
  } else {
    v1_event_series = v1_event_series_create(
      56,
      "2013-10-20T19:20:30+01:00",
      "0"
    );
  }

  return v1_event_series;
}


#ifdef v1_event_series_MAIN

void test_v1_event_series(int include_optional) {
    v1_event_series_t* v1_event_series_1 = instantiate_v1_event_series(include_optional);

	cJSON* jsonv1_event_series_1 = v1_event_series_convertToJSON(v1_event_series_1);
	printf("v1_event_series :\n%s\n", cJSON_Print(jsonv1_event_series_1));
	v1_event_series_t* v1_event_series_2 = v1_event_series_parseFromJSON(jsonv1_event_series_1);
	cJSON* jsonv1_event_series_2 = v1_event_series_convertToJSON(v1_event_series_2);
	printf("repeating v1_event_series:\n%s\n", cJSON_Print(jsonv1_event_series_2));
}

int main() {
  test_v1_event_series(1);
  test_v1_event_series(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_event_series_MAIN
#endif // v1_event_series_TEST
