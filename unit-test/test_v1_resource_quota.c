#ifndef v1_resource_quota_TEST
#define v1_resource_quota_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_resource_quota_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_resource_quota.h"
v1_resource_quota_t* instantiate_v1_resource_quota(int include_optional);

#include "test_v1_object_meta.c"
#include "test_v1_resource_quota_spec.c"
#include "test_v1_resource_quota_status.c"


v1_resource_quota_t* instantiate_v1_resource_quota(int include_optional) {
  v1_resource_quota_t* v1_resource_quota = NULL;
  if (include_optional) {
    v1_resource_quota = v1_resource_quota_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
       // false, not to have infinite recursion
      instantiate_v1_resource_quota_spec(0),
       // false, not to have infinite recursion
      instantiate_v1_resource_quota_status(0)
    );
  } else {
    v1_resource_quota = v1_resource_quota_create(
      "0",
      "0",
      NULL,
      NULL,
      NULL
    );
  }

  return v1_resource_quota;
}


#ifdef v1_resource_quota_MAIN

void test_v1_resource_quota(int include_optional) {
    v1_resource_quota_t* v1_resource_quota_1 = instantiate_v1_resource_quota(include_optional);

	cJSON* jsonv1_resource_quota_1 = v1_resource_quota_convertToJSON(v1_resource_quota_1);
	printf("v1_resource_quota :\n%s\n", cJSON_Print(jsonv1_resource_quota_1));
	v1_resource_quota_t* v1_resource_quota_2 = v1_resource_quota_parseFromJSON(jsonv1_resource_quota_1);
	cJSON* jsonv1_resource_quota_2 = v1_resource_quota_convertToJSON(v1_resource_quota_2);
	printf("repeating v1_resource_quota:\n%s\n", cJSON_Print(jsonv1_resource_quota_2));
}

int main() {
  test_v1_resource_quota(1);
  test_v1_resource_quota(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_resource_quota_MAIN
#endif // v1_resource_quota_TEST
