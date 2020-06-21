#ifndef v1_role_binding_TEST
#define v1_role_binding_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_role_binding_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_role_binding.h"
v1_role_binding_t* instantiate_v1_role_binding(int include_optional);

#include "test_v1_object_meta.c"
#include "test_v1_role_ref.c"


v1_role_binding_t* instantiate_v1_role_binding(int include_optional) {
  v1_role_binding_t* v1_role_binding = NULL;
  if (include_optional) {
    v1_role_binding = v1_role_binding_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
       // false, not to have infinite recursion
      instantiate_v1_role_ref(0),
      list_create()
    );
  } else {
    v1_role_binding = v1_role_binding_create(
      "0",
      "0",
      NULL,
      NULL,
      list_create()
    );
  }

  return v1_role_binding;
}


#ifdef v1_role_binding_MAIN

void test_v1_role_binding(int include_optional) {
    v1_role_binding_t* v1_role_binding_1 = instantiate_v1_role_binding(include_optional);

	cJSON* jsonv1_role_binding_1 = v1_role_binding_convertToJSON(v1_role_binding_1);
	printf("v1_role_binding :\n%s\n", cJSON_Print(jsonv1_role_binding_1));
	v1_role_binding_t* v1_role_binding_2 = v1_role_binding_parseFromJSON(jsonv1_role_binding_1);
	cJSON* jsonv1_role_binding_2 = v1_role_binding_convertToJSON(v1_role_binding_2);
	printf("repeating v1_role_binding:\n%s\n", cJSON_Print(jsonv1_role_binding_2));
}

int main() {
  test_v1_role_binding(1);
  test_v1_role_binding(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_role_binding_MAIN
#endif // v1_role_binding_TEST
