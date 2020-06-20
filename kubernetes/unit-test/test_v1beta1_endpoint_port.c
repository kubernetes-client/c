#ifndef v1beta1_endpoint_port_TEST
#define v1beta1_endpoint_port_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_endpoint_port_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_endpoint_port.h"
v1beta1_endpoint_port_t* instantiate_v1beta1_endpoint_port(int include_optional);



v1beta1_endpoint_port_t* instantiate_v1beta1_endpoint_port(int include_optional) {
  v1beta1_endpoint_port_t* v1beta1_endpoint_port = NULL;
  if (include_optional) {
    v1beta1_endpoint_port = v1beta1_endpoint_port_create(
      "0",
      "0",
      56,
      "0"
    );
  } else {
    v1beta1_endpoint_port = v1beta1_endpoint_port_create(
      "0",
      "0",
      56,
      "0"
    );
  }

  return v1beta1_endpoint_port;
}


#ifdef v1beta1_endpoint_port_MAIN

void test_v1beta1_endpoint_port(int include_optional) {
    v1beta1_endpoint_port_t* v1beta1_endpoint_port_1 = instantiate_v1beta1_endpoint_port(include_optional);

	cJSON* jsonv1beta1_endpoint_port_1 = v1beta1_endpoint_port_convertToJSON(v1beta1_endpoint_port_1);
	printf("v1beta1_endpoint_port :\n%s\n", cJSON_Print(jsonv1beta1_endpoint_port_1));
	v1beta1_endpoint_port_t* v1beta1_endpoint_port_2 = v1beta1_endpoint_port_parseFromJSON(jsonv1beta1_endpoint_port_1);
	cJSON* jsonv1beta1_endpoint_port_2 = v1beta1_endpoint_port_convertToJSON(v1beta1_endpoint_port_2);
	printf("repeating v1beta1_endpoint_port:\n%s\n", cJSON_Print(jsonv1beta1_endpoint_port_2));
}

int main() {
  test_v1beta1_endpoint_port(1);
  test_v1beta1_endpoint_port(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_endpoint_port_MAIN
#endif // v1beta1_endpoint_port_TEST
