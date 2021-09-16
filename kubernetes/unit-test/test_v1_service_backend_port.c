#ifndef v1_service_backend_port_TEST
#define v1_service_backend_port_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_service_backend_port_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_service_backend_port.h"
v1_service_backend_port_t* instantiate_v1_service_backend_port(int include_optional);



v1_service_backend_port_t* instantiate_v1_service_backend_port(int include_optional) {
  v1_service_backend_port_t* v1_service_backend_port = NULL;
  if (include_optional) {
    v1_service_backend_port = v1_service_backend_port_create(
      "0",
      56
    );
  } else {
    v1_service_backend_port = v1_service_backend_port_create(
      "0",
      56
    );
  }

  return v1_service_backend_port;
}


#ifdef v1_service_backend_port_MAIN

void test_v1_service_backend_port(int include_optional) {
    v1_service_backend_port_t* v1_service_backend_port_1 = instantiate_v1_service_backend_port(include_optional);

	cJSON* jsonv1_service_backend_port_1 = v1_service_backend_port_convertToJSON(v1_service_backend_port_1);
	printf("v1_service_backend_port :\n%s\n", cJSON_Print(jsonv1_service_backend_port_1));
	v1_service_backend_port_t* v1_service_backend_port_2 = v1_service_backend_port_parseFromJSON(jsonv1_service_backend_port_1);
	cJSON* jsonv1_service_backend_port_2 = v1_service_backend_port_convertToJSON(v1_service_backend_port_2);
	printf("repeating v1_service_backend_port:\n%s\n", cJSON_Print(jsonv1_service_backend_port_2));
}

int main() {
  test_v1_service_backend_port(1);
  test_v1_service_backend_port(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_service_backend_port_MAIN
#endif // v1_service_backend_port_TEST
