#ifndef v1beta1_allowed_flex_volume_TEST
#define v1beta1_allowed_flex_volume_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_allowed_flex_volume_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_allowed_flex_volume.h"
v1beta1_allowed_flex_volume_t* instantiate_v1beta1_allowed_flex_volume(int include_optional);



v1beta1_allowed_flex_volume_t* instantiate_v1beta1_allowed_flex_volume(int include_optional) {
  v1beta1_allowed_flex_volume_t* v1beta1_allowed_flex_volume = NULL;
  if (include_optional) {
    v1beta1_allowed_flex_volume = v1beta1_allowed_flex_volume_create(
      "0"
    );
  } else {
    v1beta1_allowed_flex_volume = v1beta1_allowed_flex_volume_create(
      "0"
    );
  }

  return v1beta1_allowed_flex_volume;
}


#ifdef v1beta1_allowed_flex_volume_MAIN

void test_v1beta1_allowed_flex_volume(int include_optional) {
    v1beta1_allowed_flex_volume_t* v1beta1_allowed_flex_volume_1 = instantiate_v1beta1_allowed_flex_volume(include_optional);

	cJSON* jsonv1beta1_allowed_flex_volume_1 = v1beta1_allowed_flex_volume_convertToJSON(v1beta1_allowed_flex_volume_1);
	printf("v1beta1_allowed_flex_volume :\n%s\n", cJSON_Print(jsonv1beta1_allowed_flex_volume_1));
	v1beta1_allowed_flex_volume_t* v1beta1_allowed_flex_volume_2 = v1beta1_allowed_flex_volume_parseFromJSON(jsonv1beta1_allowed_flex_volume_1);
	cJSON* jsonv1beta1_allowed_flex_volume_2 = v1beta1_allowed_flex_volume_convertToJSON(v1beta1_allowed_flex_volume_2);
	printf("repeating v1beta1_allowed_flex_volume:\n%s\n", cJSON_Print(jsonv1beta1_allowed_flex_volume_2));
}

int main() {
  test_v1beta1_allowed_flex_volume(1);
  test_v1beta1_allowed_flex_volume(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_allowed_flex_volume_MAIN
#endif // v1beta1_allowed_flex_volume_TEST
