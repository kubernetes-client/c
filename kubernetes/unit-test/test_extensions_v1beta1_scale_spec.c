#ifndef extensions_v1beta1_scale_spec_TEST
#define extensions_v1beta1_scale_spec_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define extensions_v1beta1_scale_spec_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/extensions_v1beta1_scale_spec.h"
extensions_v1beta1_scale_spec_t* instantiate_extensions_v1beta1_scale_spec(int include_optional);



extensions_v1beta1_scale_spec_t* instantiate_extensions_v1beta1_scale_spec(int include_optional) {
  extensions_v1beta1_scale_spec_t* extensions_v1beta1_scale_spec = NULL;
  if (include_optional) {
    extensions_v1beta1_scale_spec = extensions_v1beta1_scale_spec_create(
      56
    );
  } else {
    extensions_v1beta1_scale_spec = extensions_v1beta1_scale_spec_create(
      56
    );
  }

  return extensions_v1beta1_scale_spec;
}


#ifdef extensions_v1beta1_scale_spec_MAIN

void test_extensions_v1beta1_scale_spec(int include_optional) {
    extensions_v1beta1_scale_spec_t* extensions_v1beta1_scale_spec_1 = instantiate_extensions_v1beta1_scale_spec(include_optional);

	cJSON* jsonextensions_v1beta1_scale_spec_1 = extensions_v1beta1_scale_spec_convertToJSON(extensions_v1beta1_scale_spec_1);
	printf("extensions_v1beta1_scale_spec :\n%s\n", cJSON_Print(jsonextensions_v1beta1_scale_spec_1));
	extensions_v1beta1_scale_spec_t* extensions_v1beta1_scale_spec_2 = extensions_v1beta1_scale_spec_parseFromJSON(jsonextensions_v1beta1_scale_spec_1);
	cJSON* jsonextensions_v1beta1_scale_spec_2 = extensions_v1beta1_scale_spec_convertToJSON(extensions_v1beta1_scale_spec_2);
	printf("repeating extensions_v1beta1_scale_spec:\n%s\n", cJSON_Print(jsonextensions_v1beta1_scale_spec_2));
}

int main() {
  test_extensions_v1beta1_scale_spec(1);
  test_extensions_v1beta1_scale_spec(0);

  printf("Hello world \n");
  return 0;
}

#endif // extensions_v1beta1_scale_spec_MAIN
#endif // extensions_v1beta1_scale_spec_TEST
