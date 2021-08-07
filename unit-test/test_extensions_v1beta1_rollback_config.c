#ifndef extensions_v1beta1_rollback_config_TEST
#define extensions_v1beta1_rollback_config_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define extensions_v1beta1_rollback_config_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/extensions_v1beta1_rollback_config.h"
extensions_v1beta1_rollback_config_t* instantiate_extensions_v1beta1_rollback_config(int include_optional);



extensions_v1beta1_rollback_config_t* instantiate_extensions_v1beta1_rollback_config(int include_optional) {
  extensions_v1beta1_rollback_config_t* extensions_v1beta1_rollback_config = NULL;
  if (include_optional) {
    extensions_v1beta1_rollback_config = extensions_v1beta1_rollback_config_create(
      56
    );
  } else {
    extensions_v1beta1_rollback_config = extensions_v1beta1_rollback_config_create(
      56
    );
  }

  return extensions_v1beta1_rollback_config;
}


#ifdef extensions_v1beta1_rollback_config_MAIN

void test_extensions_v1beta1_rollback_config(int include_optional) {
    extensions_v1beta1_rollback_config_t* extensions_v1beta1_rollback_config_1 = instantiate_extensions_v1beta1_rollback_config(include_optional);

	cJSON* jsonextensions_v1beta1_rollback_config_1 = extensions_v1beta1_rollback_config_convertToJSON(extensions_v1beta1_rollback_config_1);
	printf("extensions_v1beta1_rollback_config :\n%s\n", cJSON_Print(jsonextensions_v1beta1_rollback_config_1));
	extensions_v1beta1_rollback_config_t* extensions_v1beta1_rollback_config_2 = extensions_v1beta1_rollback_config_parseFromJSON(jsonextensions_v1beta1_rollback_config_1);
	cJSON* jsonextensions_v1beta1_rollback_config_2 = extensions_v1beta1_rollback_config_convertToJSON(extensions_v1beta1_rollback_config_2);
	printf("repeating extensions_v1beta1_rollback_config:\n%s\n", cJSON_Print(jsonextensions_v1beta1_rollback_config_2));
}

int main() {
  test_extensions_v1beta1_rollback_config(1);
  test_extensions_v1beta1_rollback_config(0);

  printf("Hello world \n");
  return 0;
}

#endif // extensions_v1beta1_rollback_config_MAIN
#endif // extensions_v1beta1_rollback_config_TEST
