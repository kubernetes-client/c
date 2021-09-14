#ifndef v1_ingress_tls_TEST
#define v1_ingress_tls_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_ingress_tls_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_ingress_tls.h"
v1_ingress_tls_t* instantiate_v1_ingress_tls(int include_optional);



v1_ingress_tls_t* instantiate_v1_ingress_tls(int include_optional) {
  v1_ingress_tls_t* v1_ingress_tls = NULL;
  if (include_optional) {
    v1_ingress_tls = v1_ingress_tls_create(
      list_create(),
      "0"
    );
  } else {
    v1_ingress_tls = v1_ingress_tls_create(
      list_create(),
      "0"
    );
  }

  return v1_ingress_tls;
}


#ifdef v1_ingress_tls_MAIN

void test_v1_ingress_tls(int include_optional) {
    v1_ingress_tls_t* v1_ingress_tls_1 = instantiate_v1_ingress_tls(include_optional);

	cJSON* jsonv1_ingress_tls_1 = v1_ingress_tls_convertToJSON(v1_ingress_tls_1);
	printf("v1_ingress_tls :\n%s\n", cJSON_Print(jsonv1_ingress_tls_1));
	v1_ingress_tls_t* v1_ingress_tls_2 = v1_ingress_tls_parseFromJSON(jsonv1_ingress_tls_1);
	cJSON* jsonv1_ingress_tls_2 = v1_ingress_tls_convertToJSON(v1_ingress_tls_2);
	printf("repeating v1_ingress_tls:\n%s\n", cJSON_Print(jsonv1_ingress_tls_2));
}

int main() {
  test_v1_ingress_tls(1);
  test_v1_ingress_tls(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_ingress_tls_MAIN
#endif // v1_ingress_tls_TEST
