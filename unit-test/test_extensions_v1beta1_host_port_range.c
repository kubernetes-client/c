#ifndef extensions_v1beta1_host_port_range_TEST
#define extensions_v1beta1_host_port_range_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define extensions_v1beta1_host_port_range_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/extensions_v1beta1_host_port_range.h"
extensions_v1beta1_host_port_range_t* instantiate_extensions_v1beta1_host_port_range(int include_optional);



extensions_v1beta1_host_port_range_t* instantiate_extensions_v1beta1_host_port_range(int include_optional) {
  extensions_v1beta1_host_port_range_t* extensions_v1beta1_host_port_range = NULL;
  if (include_optional) {
    extensions_v1beta1_host_port_range = extensions_v1beta1_host_port_range_create(
      56,
      56
    );
  } else {
    extensions_v1beta1_host_port_range = extensions_v1beta1_host_port_range_create(
      56,
      56
    );
  }

  return extensions_v1beta1_host_port_range;
}


#ifdef extensions_v1beta1_host_port_range_MAIN

void test_extensions_v1beta1_host_port_range(int include_optional) {
    extensions_v1beta1_host_port_range_t* extensions_v1beta1_host_port_range_1 = instantiate_extensions_v1beta1_host_port_range(include_optional);

	cJSON* jsonextensions_v1beta1_host_port_range_1 = extensions_v1beta1_host_port_range_convertToJSON(extensions_v1beta1_host_port_range_1);
	printf("extensions_v1beta1_host_port_range :\n%s\n", cJSON_Print(jsonextensions_v1beta1_host_port_range_1));
	extensions_v1beta1_host_port_range_t* extensions_v1beta1_host_port_range_2 = extensions_v1beta1_host_port_range_parseFromJSON(jsonextensions_v1beta1_host_port_range_1);
	cJSON* jsonextensions_v1beta1_host_port_range_2 = extensions_v1beta1_host_port_range_convertToJSON(extensions_v1beta1_host_port_range_2);
	printf("repeating extensions_v1beta1_host_port_range:\n%s\n", cJSON_Print(jsonextensions_v1beta1_host_port_range_2));
}

int main() {
  test_extensions_v1beta1_host_port_range(1);
  test_extensions_v1beta1_host_port_range(0);

  printf("Hello world \n");
  return 0;
}

#endif // extensions_v1beta1_host_port_range_MAIN
#endif // extensions_v1beta1_host_port_range_TEST
