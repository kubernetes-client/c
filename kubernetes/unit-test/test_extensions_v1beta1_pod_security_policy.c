#ifndef extensions_v1beta1_pod_security_policy_TEST
#define extensions_v1beta1_pod_security_policy_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define extensions_v1beta1_pod_security_policy_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/extensions_v1beta1_pod_security_policy.h"
extensions_v1beta1_pod_security_policy_t* instantiate_extensions_v1beta1_pod_security_policy(int include_optional);

#include "test_v1_object_meta.c"
#include "test_extensions_v1beta1_pod_security_policy_spec.c"


extensions_v1beta1_pod_security_policy_t* instantiate_extensions_v1beta1_pod_security_policy(int include_optional) {
  extensions_v1beta1_pod_security_policy_t* extensions_v1beta1_pod_security_policy = NULL;
  if (include_optional) {
    extensions_v1beta1_pod_security_policy = extensions_v1beta1_pod_security_policy_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
       // false, not to have infinite recursion
      instantiate_extensions_v1beta1_pod_security_policy_spec(0)
    );
  } else {
    extensions_v1beta1_pod_security_policy = extensions_v1beta1_pod_security_policy_create(
      "0",
      "0",
      NULL,
      NULL
    );
  }

  return extensions_v1beta1_pod_security_policy;
}


#ifdef extensions_v1beta1_pod_security_policy_MAIN

void test_extensions_v1beta1_pod_security_policy(int include_optional) {
    extensions_v1beta1_pod_security_policy_t* extensions_v1beta1_pod_security_policy_1 = instantiate_extensions_v1beta1_pod_security_policy(include_optional);

	cJSON* jsonextensions_v1beta1_pod_security_policy_1 = extensions_v1beta1_pod_security_policy_convertToJSON(extensions_v1beta1_pod_security_policy_1);
	printf("extensions_v1beta1_pod_security_policy :\n%s\n", cJSON_Print(jsonextensions_v1beta1_pod_security_policy_1));
	extensions_v1beta1_pod_security_policy_t* extensions_v1beta1_pod_security_policy_2 = extensions_v1beta1_pod_security_policy_parseFromJSON(jsonextensions_v1beta1_pod_security_policy_1);
	cJSON* jsonextensions_v1beta1_pod_security_policy_2 = extensions_v1beta1_pod_security_policy_convertToJSON(extensions_v1beta1_pod_security_policy_2);
	printf("repeating extensions_v1beta1_pod_security_policy:\n%s\n", cJSON_Print(jsonextensions_v1beta1_pod_security_policy_2));
}

int main() {
  test_extensions_v1beta1_pod_security_policy(1);
  test_extensions_v1beta1_pod_security_policy(0);

  printf("Hello world \n");
  return 0;
}

#endif // extensions_v1beta1_pod_security_policy_MAIN
#endif // extensions_v1beta1_pod_security_policy_TEST
