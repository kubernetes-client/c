#ifndef core_v1_event_list_TEST
#define core_v1_event_list_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define core_v1_event_list_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/core_v1_event_list.h"
core_v1_event_list_t* instantiate_core_v1_event_list(int include_optional);

#include "test_v1_list_meta.c"


core_v1_event_list_t* instantiate_core_v1_event_list(int include_optional) {
  core_v1_event_list_t* core_v1_event_list = NULL;
  if (include_optional) {
    core_v1_event_list = core_v1_event_list_create(
      "0",
      list_createList(),
      "0",
       // false, not to have infinite recursion
      instantiate_v1_list_meta(0)
    );
  } else {
    core_v1_event_list = core_v1_event_list_create(
      "0",
      list_createList(),
      "0",
      NULL
    );
  }

  return core_v1_event_list;
}


#ifdef core_v1_event_list_MAIN

void test_core_v1_event_list(int include_optional) {
    core_v1_event_list_t* core_v1_event_list_1 = instantiate_core_v1_event_list(include_optional);

	cJSON* jsoncore_v1_event_list_1 = core_v1_event_list_convertToJSON(core_v1_event_list_1);
	printf("core_v1_event_list :\n%s\n", cJSON_Print(jsoncore_v1_event_list_1));
	core_v1_event_list_t* core_v1_event_list_2 = core_v1_event_list_parseFromJSON(jsoncore_v1_event_list_1);
	cJSON* jsoncore_v1_event_list_2 = core_v1_event_list_convertToJSON(core_v1_event_list_2);
	printf("repeating core_v1_event_list:\n%s\n", cJSON_Print(jsoncore_v1_event_list_2));
}

int main() {
  test_core_v1_event_list(1);
  test_core_v1_event_list(0);

  printf("Hello world \n");
  return 0;
}

#endif // core_v1_event_list_MAIN
#endif // core_v1_event_list_TEST
