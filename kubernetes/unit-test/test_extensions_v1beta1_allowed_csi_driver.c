#ifndef extensions_v1beta1_allowed_csi_driver_TEST
#define extensions_v1beta1_allowed_csi_driver_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define extensions_v1beta1_allowed_csi_driver_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/extensions_v1beta1_allowed_csi_driver.h"
extensions_v1beta1_allowed_csi_driver_t* instantiate_extensions_v1beta1_allowed_csi_driver(int include_optional);



extensions_v1beta1_allowed_csi_driver_t* instantiate_extensions_v1beta1_allowed_csi_driver(int include_optional) {
  extensions_v1beta1_allowed_csi_driver_t* extensions_v1beta1_allowed_csi_driver = NULL;
  if (include_optional) {
    extensions_v1beta1_allowed_csi_driver = extensions_v1beta1_allowed_csi_driver_create(
      "0"
    );
  } else {
    extensions_v1beta1_allowed_csi_driver = extensions_v1beta1_allowed_csi_driver_create(
      "0"
    );
  }

  return extensions_v1beta1_allowed_csi_driver;
}


#ifdef extensions_v1beta1_allowed_csi_driver_MAIN

void test_extensions_v1beta1_allowed_csi_driver(int include_optional) {
    extensions_v1beta1_allowed_csi_driver_t* extensions_v1beta1_allowed_csi_driver_1 = instantiate_extensions_v1beta1_allowed_csi_driver(include_optional);

	cJSON* jsonextensions_v1beta1_allowed_csi_driver_1 = extensions_v1beta1_allowed_csi_driver_convertToJSON(extensions_v1beta1_allowed_csi_driver_1);
	printf("extensions_v1beta1_allowed_csi_driver :\n%s\n", cJSON_Print(jsonextensions_v1beta1_allowed_csi_driver_1));
	extensions_v1beta1_allowed_csi_driver_t* extensions_v1beta1_allowed_csi_driver_2 = extensions_v1beta1_allowed_csi_driver_parseFromJSON(jsonextensions_v1beta1_allowed_csi_driver_1);
	cJSON* jsonextensions_v1beta1_allowed_csi_driver_2 = extensions_v1beta1_allowed_csi_driver_convertToJSON(extensions_v1beta1_allowed_csi_driver_2);
	printf("repeating extensions_v1beta1_allowed_csi_driver:\n%s\n", cJSON_Print(jsonextensions_v1beta1_allowed_csi_driver_2));
}

int main() {
  test_extensions_v1beta1_allowed_csi_driver(1);
  test_extensions_v1beta1_allowed_csi_driver(0);

  printf("Hello world \n");
  return 0;
}

#endif // extensions_v1beta1_allowed_csi_driver_MAIN
#endif // extensions_v1beta1_allowed_csi_driver_TEST
