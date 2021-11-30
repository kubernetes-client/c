#ifndef v1_service_port_TEST
#define v1_service_port_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_service_port_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_service_port.h"
#include "../model/int_or_string.h"
v1_service_port_t* instantiate_v1_service_port();

v1_service_port_t* instantiate_v1_service_port() {
  v1_service_port_t* v1_service_port = NULL;
  int_or_string_t *ios = int_or_string_create();
  ios->type = IOS_DATA_TYPE_STRING;
  ios->s = strdup("port_name");

  v1_service_port = v1_service_port_create(
      strdup("0"),
      strdup("0"),
      56,
      56,
      strdup("0"),
      ios
  );

  return v1_service_port;
}


#ifdef v1_service_port_MAIN

void test_v1_service_port() {
  v1_service_port_t* v1_service_port_1 = instantiate_v1_service_port();

	cJSON* jsonv1_service_port_1 = v1_service_port_convertToJSON(v1_service_port_1);
  char *service_port_1_string = cJSON_Print(jsonv1_service_port_1);
	printf("v1_service_port :\n%s\n", service_port_1_string);
  free(service_port_1_string);

	v1_service_port_t* v1_service_port_2 = v1_service_port_parseFromJSON(jsonv1_service_port_1);
	cJSON* jsonv1_service_port_2 = v1_service_port_convertToJSON(v1_service_port_2);
  char *service_port_2_string = cJSON_Print(jsonv1_service_port_2);
	printf("repeating v1_service_port:\n%s\n", service_port_2_string);
  free(service_port_2_string);

  cJSON_Delete(jsonv1_service_port_2);
  cJSON_Delete(jsonv1_service_port_1);
  v1_service_port_free(v1_service_port_2);
  v1_service_port_free(v1_service_port_1);
}

int main() {
  test_v1_service_port();
  printf("Hello world \n");
  return 0;
}

#endif // v1_service_port_MAIN
#endif // v1_service_port_TEST
