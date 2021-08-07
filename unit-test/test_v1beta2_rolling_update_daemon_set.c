#ifndef v1beta2_rolling_update_daemon_set_TEST
#define v1beta2_rolling_update_daemon_set_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta2_rolling_update_daemon_set_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta2_rolling_update_daemon_set.h"
v1beta2_rolling_update_daemon_set_t* instantiate_v1beta2_rolling_update_daemon_set(int include_optional);



v1beta2_rolling_update_daemon_set_t* instantiate_v1beta2_rolling_update_daemon_set(int include_optional) {
  v1beta2_rolling_update_daemon_set_t* v1beta2_rolling_update_daemon_set = NULL;
  if (include_optional) {
    v1beta2_rolling_update_daemon_set = v1beta2_rolling_update_daemon_set_create(
      0
    );
  } else {
    v1beta2_rolling_update_daemon_set = v1beta2_rolling_update_daemon_set_create(
      0
    );
  }

  return v1beta2_rolling_update_daemon_set;
}


#ifdef v1beta2_rolling_update_daemon_set_MAIN

void test_v1beta2_rolling_update_daemon_set(int include_optional) {
    v1beta2_rolling_update_daemon_set_t* v1beta2_rolling_update_daemon_set_1 = instantiate_v1beta2_rolling_update_daemon_set(include_optional);

	cJSON* jsonv1beta2_rolling_update_daemon_set_1 = v1beta2_rolling_update_daemon_set_convertToJSON(v1beta2_rolling_update_daemon_set_1);
	printf("v1beta2_rolling_update_daemon_set :\n%s\n", cJSON_Print(jsonv1beta2_rolling_update_daemon_set_1));
	v1beta2_rolling_update_daemon_set_t* v1beta2_rolling_update_daemon_set_2 = v1beta2_rolling_update_daemon_set_parseFromJSON(jsonv1beta2_rolling_update_daemon_set_1);
	cJSON* jsonv1beta2_rolling_update_daemon_set_2 = v1beta2_rolling_update_daemon_set_convertToJSON(v1beta2_rolling_update_daemon_set_2);
	printf("repeating v1beta2_rolling_update_daemon_set:\n%s\n", cJSON_Print(jsonv1beta2_rolling_update_daemon_set_2));
}

int main() {
  test_v1beta2_rolling_update_daemon_set(1);
  test_v1beta2_rolling_update_daemon_set(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta2_rolling_update_daemon_set_MAIN
#endif // v1beta2_rolling_update_daemon_set_TEST
