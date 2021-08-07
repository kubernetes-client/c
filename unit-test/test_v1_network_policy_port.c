#ifndef v1_network_policy_port_TEST
#define v1_network_policy_port_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_network_policy_port_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_network_policy_port.h"
v1_network_policy_port_t* instantiate_v1_network_policy_port(int include_optional);



v1_network_policy_port_t* instantiate_v1_network_policy_port(int include_optional) {
  v1_network_policy_port_t* v1_network_policy_port = NULL;
  if (include_optional) {
    v1_network_policy_port = v1_network_policy_port_create(
      0,
      "0"
    );
  } else {
    v1_network_policy_port = v1_network_policy_port_create(
      0,
      "0"
    );
  }

  return v1_network_policy_port;
}


#ifdef v1_network_policy_port_MAIN

void test_v1_network_policy_port(int include_optional) {
    v1_network_policy_port_t* v1_network_policy_port_1 = instantiate_v1_network_policy_port(include_optional);

	cJSON* jsonv1_network_policy_port_1 = v1_network_policy_port_convertToJSON(v1_network_policy_port_1);
	printf("v1_network_policy_port :\n%s\n", cJSON_Print(jsonv1_network_policy_port_1));
	v1_network_policy_port_t* v1_network_policy_port_2 = v1_network_policy_port_parseFromJSON(jsonv1_network_policy_port_1);
	cJSON* jsonv1_network_policy_port_2 = v1_network_policy_port_convertToJSON(v1_network_policy_port_2);
	printf("repeating v1_network_policy_port:\n%s\n", cJSON_Print(jsonv1_network_policy_port_2));
}

int main() {
  test_v1_network_policy_port(1);
  test_v1_network_policy_port(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_network_policy_port_MAIN
#endif // v1_network_policy_port_TEST
