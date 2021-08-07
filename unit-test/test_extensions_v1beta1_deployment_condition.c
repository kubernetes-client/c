#ifndef extensions_v1beta1_deployment_condition_TEST
#define extensions_v1beta1_deployment_condition_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define extensions_v1beta1_deployment_condition_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/extensions_v1beta1_deployment_condition.h"
extensions_v1beta1_deployment_condition_t* instantiate_extensions_v1beta1_deployment_condition(int include_optional);



extensions_v1beta1_deployment_condition_t* instantiate_extensions_v1beta1_deployment_condition(int include_optional) {
  extensions_v1beta1_deployment_condition_t* extensions_v1beta1_deployment_condition = NULL;
  if (include_optional) {
    extensions_v1beta1_deployment_condition = extensions_v1beta1_deployment_condition_create(
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    extensions_v1beta1_deployment_condition = extensions_v1beta1_deployment_condition_create(
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return extensions_v1beta1_deployment_condition;
}


#ifdef extensions_v1beta1_deployment_condition_MAIN

void test_extensions_v1beta1_deployment_condition(int include_optional) {
    extensions_v1beta1_deployment_condition_t* extensions_v1beta1_deployment_condition_1 = instantiate_extensions_v1beta1_deployment_condition(include_optional);

	cJSON* jsonextensions_v1beta1_deployment_condition_1 = extensions_v1beta1_deployment_condition_convertToJSON(extensions_v1beta1_deployment_condition_1);
	printf("extensions_v1beta1_deployment_condition :\n%s\n", cJSON_Print(jsonextensions_v1beta1_deployment_condition_1));
	extensions_v1beta1_deployment_condition_t* extensions_v1beta1_deployment_condition_2 = extensions_v1beta1_deployment_condition_parseFromJSON(jsonextensions_v1beta1_deployment_condition_1);
	cJSON* jsonextensions_v1beta1_deployment_condition_2 = extensions_v1beta1_deployment_condition_convertToJSON(extensions_v1beta1_deployment_condition_2);
	printf("repeating extensions_v1beta1_deployment_condition:\n%s\n", cJSON_Print(jsonextensions_v1beta1_deployment_condition_2));
}

int main() {
  test_extensions_v1beta1_deployment_condition(1);
  test_extensions_v1beta1_deployment_condition(0);

  printf("Hello world \n");
  return 0;
}

#endif // extensions_v1beta1_deployment_condition_MAIN
#endif // extensions_v1beta1_deployment_condition_TEST
