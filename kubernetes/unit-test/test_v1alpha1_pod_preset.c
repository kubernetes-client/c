#ifndef v1alpha1_pod_preset_TEST
#define v1alpha1_pod_preset_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha1_pod_preset_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha1_pod_preset.h"
v1alpha1_pod_preset_t* instantiate_v1alpha1_pod_preset(int include_optional);

#include "test_v1_object_meta.c"
#include "test_v1alpha1_pod_preset_spec.c"


v1alpha1_pod_preset_t* instantiate_v1alpha1_pod_preset(int include_optional) {
  v1alpha1_pod_preset_t* v1alpha1_pod_preset = NULL;
  if (include_optional) {
    v1alpha1_pod_preset = v1alpha1_pod_preset_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
       // false, not to have infinite recursion
      instantiate_v1alpha1_pod_preset_spec(0)
    );
  } else {
    v1alpha1_pod_preset = v1alpha1_pod_preset_create(
      "0",
      "0",
      NULL,
      NULL
    );
  }

  return v1alpha1_pod_preset;
}


#ifdef v1alpha1_pod_preset_MAIN

void test_v1alpha1_pod_preset(int include_optional) {
    v1alpha1_pod_preset_t* v1alpha1_pod_preset_1 = instantiate_v1alpha1_pod_preset(include_optional);

	cJSON* jsonv1alpha1_pod_preset_1 = v1alpha1_pod_preset_convertToJSON(v1alpha1_pod_preset_1);
	printf("v1alpha1_pod_preset :\n%s\n", cJSON_Print(jsonv1alpha1_pod_preset_1));
	v1alpha1_pod_preset_t* v1alpha1_pod_preset_2 = v1alpha1_pod_preset_parseFromJSON(jsonv1alpha1_pod_preset_1);
	cJSON* jsonv1alpha1_pod_preset_2 = v1alpha1_pod_preset_convertToJSON(v1alpha1_pod_preset_2);
	printf("repeating v1alpha1_pod_preset:\n%s\n", cJSON_Print(jsonv1alpha1_pod_preset_2));
}

int main() {
  test_v1alpha1_pod_preset(1);
  test_v1alpha1_pod_preset(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha1_pod_preset_MAIN
#endif // v1alpha1_pod_preset_TEST
