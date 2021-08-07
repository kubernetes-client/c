#ifndef v1_session_affinity_config_TEST
#define v1_session_affinity_config_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_session_affinity_config_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_session_affinity_config.h"
v1_session_affinity_config_t* instantiate_v1_session_affinity_config(int include_optional);

#include "test_v1_client_ip_config.c"


v1_session_affinity_config_t* instantiate_v1_session_affinity_config(int include_optional) {
  v1_session_affinity_config_t* v1_session_affinity_config = NULL;
  if (include_optional) {
    v1_session_affinity_config = v1_session_affinity_config_create(
       // false, not to have infinite recursion
      instantiate_v1_client_ip_config(0)
    );
  } else {
    v1_session_affinity_config = v1_session_affinity_config_create(
      NULL
    );
  }

  return v1_session_affinity_config;
}


#ifdef v1_session_affinity_config_MAIN

void test_v1_session_affinity_config(int include_optional) {
    v1_session_affinity_config_t* v1_session_affinity_config_1 = instantiate_v1_session_affinity_config(include_optional);

	cJSON* jsonv1_session_affinity_config_1 = v1_session_affinity_config_convertToJSON(v1_session_affinity_config_1);
	printf("v1_session_affinity_config :\n%s\n", cJSON_Print(jsonv1_session_affinity_config_1));
	v1_session_affinity_config_t* v1_session_affinity_config_2 = v1_session_affinity_config_parseFromJSON(jsonv1_session_affinity_config_1);
	cJSON* jsonv1_session_affinity_config_2 = v1_session_affinity_config_convertToJSON(v1_session_affinity_config_2);
	printf("repeating v1_session_affinity_config:\n%s\n", cJSON_Print(jsonv1_session_affinity_config_2));
}

int main() {
  test_v1_session_affinity_config(1);
  test_v1_session_affinity_config(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_session_affinity_config_MAIN
#endif // v1_session_affinity_config_TEST
