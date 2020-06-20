#ifndef v1alpha1_role_ref_TEST
#define v1alpha1_role_ref_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha1_role_ref_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha1_role_ref.h"
v1alpha1_role_ref_t* instantiate_v1alpha1_role_ref(int include_optional);



v1alpha1_role_ref_t* instantiate_v1alpha1_role_ref(int include_optional) {
  v1alpha1_role_ref_t* v1alpha1_role_ref = NULL;
  if (include_optional) {
    v1alpha1_role_ref = v1alpha1_role_ref_create(
      "0",
      "0",
      "0"
    );
  } else {
    v1alpha1_role_ref = v1alpha1_role_ref_create(
      "0",
      "0",
      "0"
    );
  }

  return v1alpha1_role_ref;
}


#ifdef v1alpha1_role_ref_MAIN

void test_v1alpha1_role_ref(int include_optional) {
    v1alpha1_role_ref_t* v1alpha1_role_ref_1 = instantiate_v1alpha1_role_ref(include_optional);

	cJSON* jsonv1alpha1_role_ref_1 = v1alpha1_role_ref_convertToJSON(v1alpha1_role_ref_1);
	printf("v1alpha1_role_ref :\n%s\n", cJSON_Print(jsonv1alpha1_role_ref_1));
	v1alpha1_role_ref_t* v1alpha1_role_ref_2 = v1alpha1_role_ref_parseFromJSON(jsonv1alpha1_role_ref_1);
	cJSON* jsonv1alpha1_role_ref_2 = v1alpha1_role_ref_convertToJSON(v1alpha1_role_ref_2);
	printf("repeating v1alpha1_role_ref:\n%s\n", cJSON_Print(jsonv1alpha1_role_ref_2));
}

int main() {
  test_v1alpha1_role_ref(1);
  test_v1alpha1_role_ref(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha1_role_ref_MAIN
#endif // v1alpha1_role_ref_TEST
