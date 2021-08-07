#ifndef v1beta2_deployment_spec_TEST
#define v1beta2_deployment_spec_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta2_deployment_spec_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta2_deployment_spec.h"
v1beta2_deployment_spec_t* instantiate_v1beta2_deployment_spec(int include_optional);

#include "test_v1_label_selector.c"
#include "test_v1beta2_deployment_strategy.c"
#include "test_v1_pod_template_spec.c"


v1beta2_deployment_spec_t* instantiate_v1beta2_deployment_spec(int include_optional) {
  v1beta2_deployment_spec_t* v1beta2_deployment_spec = NULL;
  if (include_optional) {
    v1beta2_deployment_spec = v1beta2_deployment_spec_create(
      56,
      1,
      56,
      56,
      56,
       // false, not to have infinite recursion
      instantiate_v1_label_selector(0),
       // false, not to have infinite recursion
      instantiate_v1beta2_deployment_strategy(0),
       // false, not to have infinite recursion
      instantiate_v1_pod_template_spec(0)
    );
  } else {
    v1beta2_deployment_spec = v1beta2_deployment_spec_create(
      56,
      1,
      56,
      56,
      56,
      NULL,
      NULL,
      NULL
    );
  }

  return v1beta2_deployment_spec;
}


#ifdef v1beta2_deployment_spec_MAIN

void test_v1beta2_deployment_spec(int include_optional) {
    v1beta2_deployment_spec_t* v1beta2_deployment_spec_1 = instantiate_v1beta2_deployment_spec(include_optional);

	cJSON* jsonv1beta2_deployment_spec_1 = v1beta2_deployment_spec_convertToJSON(v1beta2_deployment_spec_1);
	printf("v1beta2_deployment_spec :\n%s\n", cJSON_Print(jsonv1beta2_deployment_spec_1));
	v1beta2_deployment_spec_t* v1beta2_deployment_spec_2 = v1beta2_deployment_spec_parseFromJSON(jsonv1beta2_deployment_spec_1);
	cJSON* jsonv1beta2_deployment_spec_2 = v1beta2_deployment_spec_convertToJSON(v1beta2_deployment_spec_2);
	printf("repeating v1beta2_deployment_spec:\n%s\n", cJSON_Print(jsonv1beta2_deployment_spec_2));
}

int main() {
  test_v1beta2_deployment_spec(1);
  test_v1beta2_deployment_spec(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta2_deployment_spec_MAIN
#endif // v1beta2_deployment_spec_TEST
