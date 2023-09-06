#ifndef v1_host_ip_TEST
#define v1_host_ip_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_host_ip_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_host_ip.h"
v1_host_ip_t* instantiate_v1_host_ip(int include_optional);



v1_host_ip_t* instantiate_v1_host_ip(int include_optional) {
  v1_host_ip_t* v1_host_ip = NULL;
  if (include_optional) {
    v1_host_ip = v1_host_ip_create(
      "0"
    );
  } else {
    v1_host_ip = v1_host_ip_create(
      "0"
    );
  }

  return v1_host_ip;
}


#ifdef v1_host_ip_MAIN

void test_v1_host_ip(int include_optional) {
    v1_host_ip_t* v1_host_ip_1 = instantiate_v1_host_ip(include_optional);

	cJSON* jsonv1_host_ip_1 = v1_host_ip_convertToJSON(v1_host_ip_1);
	printf("v1_host_ip :\n%s\n", cJSON_Print(jsonv1_host_ip_1));
	v1_host_ip_t* v1_host_ip_2 = v1_host_ip_parseFromJSON(jsonv1_host_ip_1);
	cJSON* jsonv1_host_ip_2 = v1_host_ip_convertToJSON(v1_host_ip_2);
	printf("repeating v1_host_ip:\n%s\n", cJSON_Print(jsonv1_host_ip_2));
}

int main() {
  test_v1_host_ip(1);
  test_v1_host_ip(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_host_ip_MAIN
#endif // v1_host_ip_TEST
