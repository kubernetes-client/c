#ifndef v1_persistent_volume_TEST
#define v1_persistent_volume_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_persistent_volume_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_persistent_volume.h"
v1_persistent_volume_t* instantiate_v1_persistent_volume(int include_optional);

#include "test_v1_object_meta.c"
#include "test_v1_persistent_volume_spec.c"
#include "test_v1_persistent_volume_status.c"


v1_persistent_volume_t* instantiate_v1_persistent_volume(int include_optional) {
  v1_persistent_volume_t* v1_persistent_volume = NULL;
  if (include_optional) {
    v1_persistent_volume = v1_persistent_volume_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
       // false, not to have infinite recursion
      instantiate_v1_persistent_volume_spec(0),
       // false, not to have infinite recursion
      instantiate_v1_persistent_volume_status(0)
    );
  } else {
    v1_persistent_volume = v1_persistent_volume_create(
      "0",
      "0",
      NULL,
      NULL,
      NULL
    );
  }

  return v1_persistent_volume;
}


#ifdef v1_persistent_volume_MAIN

void test_v1_persistent_volume(int include_optional) {
    v1_persistent_volume_t* v1_persistent_volume_1 = instantiate_v1_persistent_volume(include_optional);

	cJSON* jsonv1_persistent_volume_1 = v1_persistent_volume_convertToJSON(v1_persistent_volume_1);
	printf("v1_persistent_volume :\n%s\n", cJSON_Print(jsonv1_persistent_volume_1));
	v1_persistent_volume_t* v1_persistent_volume_2 = v1_persistent_volume_parseFromJSON(jsonv1_persistent_volume_1);
	cJSON* jsonv1_persistent_volume_2 = v1_persistent_volume_convertToJSON(v1_persistent_volume_2);
	printf("repeating v1_persistent_volume:\n%s\n", cJSON_Print(jsonv1_persistent_volume_2));
}

int main() {
  test_v1_persistent_volume(1);
  test_v1_persistent_volume(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_persistent_volume_MAIN
#endif // v1_persistent_volume_TEST
