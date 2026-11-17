#ifndef v1beta1_pod_group_TEST
#define v1beta1_pod_group_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_pod_group_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_pod_group.h"
v1beta1_pod_group_t* instantiate_v1beta1_pod_group(int include_optional);

#include "test_v1_object_meta.c"
#include "test_v1beta1_pod_group_spec.c"
#include "test_v1beta1_pod_group_status.c"


v1beta1_pod_group_t* instantiate_v1beta1_pod_group(int include_optional) {
  v1beta1_pod_group_t* v1beta1_pod_group = NULL;
  if (include_optional) {
    v1beta1_pod_group = v1beta1_pod_group_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
       // false, not to have infinite recursion
      instantiate_v1beta1_pod_group_spec(0),
       // false, not to have infinite recursion
      instantiate_v1beta1_pod_group_status(0)
    );
  } else {
    v1beta1_pod_group = v1beta1_pod_group_create(
      "0",
      "0",
      NULL,
      NULL,
      NULL
    );
  }

  return v1beta1_pod_group;
}


#ifdef v1beta1_pod_group_MAIN

void test_v1beta1_pod_group(int include_optional) {
    v1beta1_pod_group_t* v1beta1_pod_group_1 = instantiate_v1beta1_pod_group(include_optional);

	cJSON* jsonv1beta1_pod_group_1 = v1beta1_pod_group_convertToJSON(v1beta1_pod_group_1);
	printf("v1beta1_pod_group :\n%s\n", cJSON_Print(jsonv1beta1_pod_group_1));
	v1beta1_pod_group_t* v1beta1_pod_group_2 = v1beta1_pod_group_parseFromJSON(jsonv1beta1_pod_group_1);
	cJSON* jsonv1beta1_pod_group_2 = v1beta1_pod_group_convertToJSON(v1beta1_pod_group_2);
	printf("repeating v1beta1_pod_group:\n%s\n", cJSON_Print(jsonv1beta1_pod_group_2));
}

int main() {
  test_v1beta1_pod_group(1);
  test_v1beta1_pod_group(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_pod_group_MAIN
#endif // v1beta1_pod_group_TEST
