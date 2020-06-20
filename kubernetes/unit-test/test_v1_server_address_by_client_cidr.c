#ifndef v1_server_address_by_client_cidr_TEST
#define v1_server_address_by_client_cidr_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_server_address_by_client_cidr_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_server_address_by_client_cidr.h"
v1_server_address_by_client_cidr_t* instantiate_v1_server_address_by_client_cidr(int include_optional);



v1_server_address_by_client_cidr_t* instantiate_v1_server_address_by_client_cidr(int include_optional) {
  v1_server_address_by_client_cidr_t* v1_server_address_by_client_cidr = NULL;
  if (include_optional) {
    v1_server_address_by_client_cidr = v1_server_address_by_client_cidr_create(
      "0",
      "0"
    );
  } else {
    v1_server_address_by_client_cidr = v1_server_address_by_client_cidr_create(
      "0",
      "0"
    );
  }

  return v1_server_address_by_client_cidr;
}


#ifdef v1_server_address_by_client_cidr_MAIN

void test_v1_server_address_by_client_cidr(int include_optional) {
    v1_server_address_by_client_cidr_t* v1_server_address_by_client_cidr_1 = instantiate_v1_server_address_by_client_cidr(include_optional);

	cJSON* jsonv1_server_address_by_client_cidr_1 = v1_server_address_by_client_cidr_convertToJSON(v1_server_address_by_client_cidr_1);
	printf("v1_server_address_by_client_cidr :\n%s\n", cJSON_Print(jsonv1_server_address_by_client_cidr_1));
	v1_server_address_by_client_cidr_t* v1_server_address_by_client_cidr_2 = v1_server_address_by_client_cidr_parseFromJSON(jsonv1_server_address_by_client_cidr_1);
	cJSON* jsonv1_server_address_by_client_cidr_2 = v1_server_address_by_client_cidr_convertToJSON(v1_server_address_by_client_cidr_2);
	printf("repeating v1_server_address_by_client_cidr:\n%s\n", cJSON_Print(jsonv1_server_address_by_client_cidr_2));
}

int main() {
  test_v1_server_address_by_client_cidr(1);
  test_v1_server_address_by_client_cidr(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_server_address_by_client_cidr_MAIN
#endif // v1_server_address_by_client_cidr_TEST
