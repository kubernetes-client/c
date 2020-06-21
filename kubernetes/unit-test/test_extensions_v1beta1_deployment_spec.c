#ifndef extensions_v1beta1_deployment_spec_TEST
#define extensions_v1beta1_deployment_spec_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define extensions_v1beta1_deployment_spec_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/extensions_v1beta1_deployment_spec.h"
extensions_v1beta1_deployment_spec_t* instantiate_extensions_v1beta1_deployment_spec(int include_optional);

#include "test_extensions_v1beta1_rollback_config.c"
#include "test_v1_label_selector.c"
#include "test_extensions_v1beta1_deployment_strategy.c"
#include "test_v1_pod_template_spec.c"


extensions_v1beta1_deployment_spec_t* instantiate_extensions_v1beta1_deployment_spec(int include_optional) {
  extensions_v1beta1_deployment_spec_t* extensions_v1beta1_deployment_spec = NULL;
  if (include_optional) {
    extensions_v1beta1_deployment_spec = extensions_v1beta1_deployment_spec_create(
      56,
      1,
      56,
      56,
      56,
       // false, not to have infinite recursion
      instantiate_extensions_v1beta1_rollback_config(0),
       // false, not to have infinite recursion
      instantiate_v1_label_selector(0),
       // false, not to have infinite recursion
      instantiate_extensions_v1beta1_deployment_strategy(0),
       // false, not to have infinite recursion
      instantiate_v1_pod_template_spec(0)
    );
  } else {
    extensions_v1beta1_deployment_spec = extensions_v1beta1_deployment_spec_create(
      56,
      1,
      56,
      56,
      56,
      NULL,
      NULL,
      NULL,
      NULL
    );
  }

  return extensions_v1beta1_deployment_spec;
}


#ifdef extensions_v1beta1_deployment_spec_MAIN

void test_extensions_v1beta1_deployment_spec(int include_optional) {
    extensions_v1beta1_deployment_spec_t* extensions_v1beta1_deployment_spec_1 = instantiate_extensions_v1beta1_deployment_spec(include_optional);

	cJSON* jsonextensions_v1beta1_deployment_spec_1 = extensions_v1beta1_deployment_spec_convertToJSON(extensions_v1beta1_deployment_spec_1);
	printf("extensions_v1beta1_deployment_spec :\n%s\n", cJSON_Print(jsonextensions_v1beta1_deployment_spec_1));
	extensions_v1beta1_deployment_spec_t* extensions_v1beta1_deployment_spec_2 = extensions_v1beta1_deployment_spec_parseFromJSON(jsonextensions_v1beta1_deployment_spec_1);
	cJSON* jsonextensions_v1beta1_deployment_spec_2 = extensions_v1beta1_deployment_spec_convertToJSON(extensions_v1beta1_deployment_spec_2);
	printf("repeating extensions_v1beta1_deployment_spec:\n%s\n", cJSON_Print(jsonextensions_v1beta1_deployment_spec_2));
}

int main() {
  test_extensions_v1beta1_deployment_spec(1);
  test_extensions_v1beta1_deployment_spec(0);

  printf("Hello world \n");
  return 0;
}

#endif // extensions_v1beta1_deployment_spec_MAIN
#endif // extensions_v1beta1_deployment_spec_TEST
