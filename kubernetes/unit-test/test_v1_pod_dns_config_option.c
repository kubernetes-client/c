#ifndef v1_pod_dns_config_option_TEST
#define v1_pod_dns_config_option_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_pod_dns_config_option_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_pod_dns_config_option.h"
v1_pod_dns_config_option_t* instantiate_v1_pod_dns_config_option(int include_optional);



v1_pod_dns_config_option_t* instantiate_v1_pod_dns_config_option(int include_optional) {
  v1_pod_dns_config_option_t* v1_pod_dns_config_option = NULL;
  if (include_optional) {
    v1_pod_dns_config_option = v1_pod_dns_config_option_create(
      "0",
      "0"
    );
  } else {
    v1_pod_dns_config_option = v1_pod_dns_config_option_create(
      "0",
      "0"
    );
  }

  return v1_pod_dns_config_option;
}


#ifdef v1_pod_dns_config_option_MAIN

void test_v1_pod_dns_config_option(int include_optional) {
    v1_pod_dns_config_option_t* v1_pod_dns_config_option_1 = instantiate_v1_pod_dns_config_option(include_optional);

	cJSON* jsonv1_pod_dns_config_option_1 = v1_pod_dns_config_option_convertToJSON(v1_pod_dns_config_option_1);
	printf("v1_pod_dns_config_option :\n%s\n", cJSON_Print(jsonv1_pod_dns_config_option_1));
	v1_pod_dns_config_option_t* v1_pod_dns_config_option_2 = v1_pod_dns_config_option_parseFromJSON(jsonv1_pod_dns_config_option_1);
	cJSON* jsonv1_pod_dns_config_option_2 = v1_pod_dns_config_option_convertToJSON(v1_pod_dns_config_option_2);
	printf("repeating v1_pod_dns_config_option:\n%s\n", cJSON_Print(jsonv1_pod_dns_config_option_2));
}

int main() {
  test_v1_pod_dns_config_option(1);
  test_v1_pod_dns_config_option(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_pod_dns_config_option_MAIN
#endif // v1_pod_dns_config_option_TEST
