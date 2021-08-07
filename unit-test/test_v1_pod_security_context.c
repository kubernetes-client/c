#ifndef v1_pod_security_context_TEST
#define v1_pod_security_context_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_pod_security_context_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_pod_security_context.h"
v1_pod_security_context_t* instantiate_v1_pod_security_context(int include_optional);

#include "test_v1_se_linux_options.c"
#include "test_v1_windows_security_context_options.c"


v1_pod_security_context_t* instantiate_v1_pod_security_context(int include_optional) {
  v1_pod_security_context_t* v1_pod_security_context = NULL;
  if (include_optional) {
    v1_pod_security_context = v1_pod_security_context_create(
      56,
      56,
      1,
      56,
       // false, not to have infinite recursion
      instantiate_v1_se_linux_options(0),
      list_create(),
      list_create(),
       // false, not to have infinite recursion
      instantiate_v1_windows_security_context_options(0)
    );
  } else {
    v1_pod_security_context = v1_pod_security_context_create(
      56,
      56,
      1,
      56,
      NULL,
      list_create(),
      list_create(),
      NULL
    );
  }

  return v1_pod_security_context;
}


#ifdef v1_pod_security_context_MAIN

void test_v1_pod_security_context(int include_optional) {
    v1_pod_security_context_t* v1_pod_security_context_1 = instantiate_v1_pod_security_context(include_optional);

	cJSON* jsonv1_pod_security_context_1 = v1_pod_security_context_convertToJSON(v1_pod_security_context_1);
	printf("v1_pod_security_context :\n%s\n", cJSON_Print(jsonv1_pod_security_context_1));
	v1_pod_security_context_t* v1_pod_security_context_2 = v1_pod_security_context_parseFromJSON(jsonv1_pod_security_context_1);
	cJSON* jsonv1_pod_security_context_2 = v1_pod_security_context_convertToJSON(v1_pod_security_context_2);
	printf("repeating v1_pod_security_context:\n%s\n", cJSON_Print(jsonv1_pod_security_context_2));
}

int main() {
  test_v1_pod_security_context(1);
  test_v1_pod_security_context(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_pod_security_context_MAIN
#endif // v1_pod_security_context_TEST
