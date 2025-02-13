#ifndef v1alpha1_json_patch_TEST
#define v1alpha1_json_patch_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha1_json_patch_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha1_json_patch.h"
v1alpha1_json_patch_t* instantiate_v1alpha1_json_patch(int include_optional);



v1alpha1_json_patch_t* instantiate_v1alpha1_json_patch(int include_optional) {
  v1alpha1_json_patch_t* v1alpha1_json_patch = NULL;
  if (include_optional) {
    v1alpha1_json_patch = v1alpha1_json_patch_create(
      "0"
    );
  } else {
    v1alpha1_json_patch = v1alpha1_json_patch_create(
      "0"
    );
  }

  return v1alpha1_json_patch;
}


#ifdef v1alpha1_json_patch_MAIN

void test_v1alpha1_json_patch(int include_optional) {
    v1alpha1_json_patch_t* v1alpha1_json_patch_1 = instantiate_v1alpha1_json_patch(include_optional);

	cJSON* jsonv1alpha1_json_patch_1 = v1alpha1_json_patch_convertToJSON(v1alpha1_json_patch_1);
	printf("v1alpha1_json_patch :\n%s\n", cJSON_Print(jsonv1alpha1_json_patch_1));
	v1alpha1_json_patch_t* v1alpha1_json_patch_2 = v1alpha1_json_patch_parseFromJSON(jsonv1alpha1_json_patch_1);
	cJSON* jsonv1alpha1_json_patch_2 = v1alpha1_json_patch_convertToJSON(v1alpha1_json_patch_2);
	printf("repeating v1alpha1_json_patch:\n%s\n", cJSON_Print(jsonv1alpha1_json_patch_2));
}

int main() {
  test_v1alpha1_json_patch(1);
  test_v1alpha1_json_patch(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha1_json_patch_MAIN
#endif // v1alpha1_json_patch_TEST
