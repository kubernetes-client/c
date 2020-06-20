#ifndef extensions_v1beta1_ingress_tls_TEST
#define extensions_v1beta1_ingress_tls_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define extensions_v1beta1_ingress_tls_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/extensions_v1beta1_ingress_tls.h"
extensions_v1beta1_ingress_tls_t* instantiate_extensions_v1beta1_ingress_tls(int include_optional);



extensions_v1beta1_ingress_tls_t* instantiate_extensions_v1beta1_ingress_tls(int include_optional) {
  extensions_v1beta1_ingress_tls_t* extensions_v1beta1_ingress_tls = NULL;
  if (include_optional) {
    extensions_v1beta1_ingress_tls = extensions_v1beta1_ingress_tls_create(
      list_create(),
      "0"
    );
  } else {
    extensions_v1beta1_ingress_tls = extensions_v1beta1_ingress_tls_create(
      list_create(),
      "0"
    );
  }

  return extensions_v1beta1_ingress_tls;
}


#ifdef extensions_v1beta1_ingress_tls_MAIN

void test_extensions_v1beta1_ingress_tls(int include_optional) {
    extensions_v1beta1_ingress_tls_t* extensions_v1beta1_ingress_tls_1 = instantiate_extensions_v1beta1_ingress_tls(include_optional);

	cJSON* jsonextensions_v1beta1_ingress_tls_1 = extensions_v1beta1_ingress_tls_convertToJSON(extensions_v1beta1_ingress_tls_1);
	printf("extensions_v1beta1_ingress_tls :\n%s\n", cJSON_Print(jsonextensions_v1beta1_ingress_tls_1));
	extensions_v1beta1_ingress_tls_t* extensions_v1beta1_ingress_tls_2 = extensions_v1beta1_ingress_tls_parseFromJSON(jsonextensions_v1beta1_ingress_tls_1);
	cJSON* jsonextensions_v1beta1_ingress_tls_2 = extensions_v1beta1_ingress_tls_convertToJSON(extensions_v1beta1_ingress_tls_2);
	printf("repeating extensions_v1beta1_ingress_tls:\n%s\n", cJSON_Print(jsonextensions_v1beta1_ingress_tls_2));
}

int main() {
  test_extensions_v1beta1_ingress_tls(1);
  test_extensions_v1beta1_ingress_tls(0);

  printf("Hello world \n");
  return 0;
}

#endif // extensions_v1beta1_ingress_tls_MAIN
#endif // extensions_v1beta1_ingress_tls_TEST
