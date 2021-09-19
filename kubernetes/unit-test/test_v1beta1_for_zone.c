#ifndef v1beta1_for_zone_TEST
#define v1beta1_for_zone_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_for_zone_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_for_zone.h"
v1beta1_for_zone_t* instantiate_v1beta1_for_zone(int include_optional);



v1beta1_for_zone_t* instantiate_v1beta1_for_zone(int include_optional) {
  v1beta1_for_zone_t* v1beta1_for_zone = NULL;
  if (include_optional) {
    v1beta1_for_zone = v1beta1_for_zone_create(
      "0"
    );
  } else {
    v1beta1_for_zone = v1beta1_for_zone_create(
      "0"
    );
  }

  return v1beta1_for_zone;
}


#ifdef v1beta1_for_zone_MAIN

void test_v1beta1_for_zone(int include_optional) {
    v1beta1_for_zone_t* v1beta1_for_zone_1 = instantiate_v1beta1_for_zone(include_optional);

	cJSON* jsonv1beta1_for_zone_1 = v1beta1_for_zone_convertToJSON(v1beta1_for_zone_1);
	printf("v1beta1_for_zone :\n%s\n", cJSON_Print(jsonv1beta1_for_zone_1));
	v1beta1_for_zone_t* v1beta1_for_zone_2 = v1beta1_for_zone_parseFromJSON(jsonv1beta1_for_zone_1);
	cJSON* jsonv1beta1_for_zone_2 = v1beta1_for_zone_convertToJSON(v1beta1_for_zone_2);
	printf("repeating v1beta1_for_zone:\n%s\n", cJSON_Print(jsonv1beta1_for_zone_2));
}

int main() {
  test_v1beta1_for_zone(1);
  test_v1beta1_for_zone(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_for_zone_MAIN
#endif // v1beta1_for_zone_TEST
