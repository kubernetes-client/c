#ifndef v1_pod_volume_health_TEST
#define v1_pod_volume_health_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_pod_volume_health_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_pod_volume_health.h"
v1_pod_volume_health_t* instantiate_v1_pod_volume_health(int include_optional);



v1_pod_volume_health_t* instantiate_v1_pod_volume_health(int include_optional) {
  v1_pod_volume_health_t* v1_pod_volume_health = NULL;
  if (include_optional) {
    v1_pod_volume_health = v1_pod_volume_health_create(
      list_createList(),
      "2013-10-20T19:20:30+01:00",
      "0"
    );
  } else {
    v1_pod_volume_health = v1_pod_volume_health_create(
      list_createList(),
      "2013-10-20T19:20:30+01:00",
      "0"
    );
  }

  return v1_pod_volume_health;
}


#ifdef v1_pod_volume_health_MAIN

void test_v1_pod_volume_health(int include_optional) {
    v1_pod_volume_health_t* v1_pod_volume_health_1 = instantiate_v1_pod_volume_health(include_optional);

	cJSON* jsonv1_pod_volume_health_1 = v1_pod_volume_health_convertToJSON(v1_pod_volume_health_1);
	printf("v1_pod_volume_health :\n%s\n", cJSON_Print(jsonv1_pod_volume_health_1));
	v1_pod_volume_health_t* v1_pod_volume_health_2 = v1_pod_volume_health_parseFromJSON(jsonv1_pod_volume_health_1);
	cJSON* jsonv1_pod_volume_health_2 = v1_pod_volume_health_convertToJSON(v1_pod_volume_health_2);
	printf("repeating v1_pod_volume_health:\n%s\n", cJSON_Print(jsonv1_pod_volume_health_2));
}

int main() {
  test_v1_pod_volume_health(1);
  test_v1_pod_volume_health(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_pod_volume_health_MAIN
#endif // v1_pod_volume_health_TEST
