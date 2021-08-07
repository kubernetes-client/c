#ifndef extensions_v1beta1_allowed_flex_volume_TEST
#define extensions_v1beta1_allowed_flex_volume_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define extensions_v1beta1_allowed_flex_volume_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/extensions_v1beta1_allowed_flex_volume.h"
extensions_v1beta1_allowed_flex_volume_t* instantiate_extensions_v1beta1_allowed_flex_volume(int include_optional);



extensions_v1beta1_allowed_flex_volume_t* instantiate_extensions_v1beta1_allowed_flex_volume(int include_optional) {
  extensions_v1beta1_allowed_flex_volume_t* extensions_v1beta1_allowed_flex_volume = NULL;
  if (include_optional) {
    extensions_v1beta1_allowed_flex_volume = extensions_v1beta1_allowed_flex_volume_create(
      "0"
    );
  } else {
    extensions_v1beta1_allowed_flex_volume = extensions_v1beta1_allowed_flex_volume_create(
      "0"
    );
  }

  return extensions_v1beta1_allowed_flex_volume;
}


#ifdef extensions_v1beta1_allowed_flex_volume_MAIN

void test_extensions_v1beta1_allowed_flex_volume(int include_optional) {
    extensions_v1beta1_allowed_flex_volume_t* extensions_v1beta1_allowed_flex_volume_1 = instantiate_extensions_v1beta1_allowed_flex_volume(include_optional);

	cJSON* jsonextensions_v1beta1_allowed_flex_volume_1 = extensions_v1beta1_allowed_flex_volume_convertToJSON(extensions_v1beta1_allowed_flex_volume_1);
	printf("extensions_v1beta1_allowed_flex_volume :\n%s\n", cJSON_Print(jsonextensions_v1beta1_allowed_flex_volume_1));
	extensions_v1beta1_allowed_flex_volume_t* extensions_v1beta1_allowed_flex_volume_2 = extensions_v1beta1_allowed_flex_volume_parseFromJSON(jsonextensions_v1beta1_allowed_flex_volume_1);
	cJSON* jsonextensions_v1beta1_allowed_flex_volume_2 = extensions_v1beta1_allowed_flex_volume_convertToJSON(extensions_v1beta1_allowed_flex_volume_2);
	printf("repeating extensions_v1beta1_allowed_flex_volume:\n%s\n", cJSON_Print(jsonextensions_v1beta1_allowed_flex_volume_2));
}

int main() {
  test_extensions_v1beta1_allowed_flex_volume(1);
  test_extensions_v1beta1_allowed_flex_volume(0);

  printf("Hello world \n");
  return 0;
}

#endif // extensions_v1beta1_allowed_flex_volume_MAIN
#endif // extensions_v1beta1_allowed_flex_volume_TEST
