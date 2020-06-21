#ifndef v1_pod_spec_TEST
#define v1_pod_spec_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_pod_spec_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_pod_spec.h"
v1_pod_spec_t* instantiate_v1_pod_spec(int include_optional);

#include "test_v1_affinity.c"
#include "test_v1_pod_dns_config.c"
#include "test_v1_pod_security_context.c"


v1_pod_spec_t* instantiate_v1_pod_spec(int include_optional) {
  v1_pod_spec_t* v1_pod_spec = NULL;
  if (include_optional) {
    v1_pod_spec = v1_pod_spec_create(
      56,
       // false, not to have infinite recursion
      instantiate_v1_affinity(0),
      1,
      list_create(),
       // false, not to have infinite recursion
      instantiate_v1_pod_dns_config(0),
      "0",
      1,
      list_create(),
      list_create(),
      1,
      1,
      1,
      "0",
      list_create(),
      list_create(),
      "0",
      list_create(),
      list_create(),
      "0",
      56,
      "0",
      list_create(),
      "0",
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_pod_security_context(0),
      "0",
      "0",
      1,
      "0",
      56,
      list_create(),
      list_create(),
      list_create()
    );
  } else {
    v1_pod_spec = v1_pod_spec_create(
      56,
      NULL,
      1,
      list_create(),
      NULL,
      "0",
      1,
      list_create(),
      list_create(),
      1,
      1,
      1,
      "0",
      list_create(),
      list_create(),
      "0",
      list_create(),
      list_create(),
      "0",
      56,
      "0",
      list_create(),
      "0",
      "0",
      "0",
      NULL,
      "0",
      "0",
      1,
      "0",
      56,
      list_create(),
      list_create(),
      list_create()
    );
  }

  return v1_pod_spec;
}


#ifdef v1_pod_spec_MAIN

void test_v1_pod_spec(int include_optional) {
    v1_pod_spec_t* v1_pod_spec_1 = instantiate_v1_pod_spec(include_optional);

	cJSON* jsonv1_pod_spec_1 = v1_pod_spec_convertToJSON(v1_pod_spec_1);
	printf("v1_pod_spec :\n%s\n", cJSON_Print(jsonv1_pod_spec_1));
	v1_pod_spec_t* v1_pod_spec_2 = v1_pod_spec_parseFromJSON(jsonv1_pod_spec_1);
	cJSON* jsonv1_pod_spec_2 = v1_pod_spec_convertToJSON(v1_pod_spec_2);
	printf("repeating v1_pod_spec:\n%s\n", cJSON_Print(jsonv1_pod_spec_2));
}

int main() {
  test_v1_pod_spec(1);
  test_v1_pod_spec(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_pod_spec_MAIN
#endif // v1_pod_spec_TEST
