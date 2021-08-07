#ifndef v1beta2_scale_spec_TEST
#define v1beta2_scale_spec_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta2_scale_spec_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta2_scale_spec.h"
v1beta2_scale_spec_t* instantiate_v1beta2_scale_spec(int include_optional);



v1beta2_scale_spec_t* instantiate_v1beta2_scale_spec(int include_optional) {
  v1beta2_scale_spec_t* v1beta2_scale_spec = NULL;
  if (include_optional) {
    v1beta2_scale_spec = v1beta2_scale_spec_create(
      56
    );
  } else {
    v1beta2_scale_spec = v1beta2_scale_spec_create(
      56
    );
  }

  return v1beta2_scale_spec;
}


#ifdef v1beta2_scale_spec_MAIN

void test_v1beta2_scale_spec(int include_optional) {
    v1beta2_scale_spec_t* v1beta2_scale_spec_1 = instantiate_v1beta2_scale_spec(include_optional);

	cJSON* jsonv1beta2_scale_spec_1 = v1beta2_scale_spec_convertToJSON(v1beta2_scale_spec_1);
	printf("v1beta2_scale_spec :\n%s\n", cJSON_Print(jsonv1beta2_scale_spec_1));
	v1beta2_scale_spec_t* v1beta2_scale_spec_2 = v1beta2_scale_spec_parseFromJSON(jsonv1beta2_scale_spec_1);
	cJSON* jsonv1beta2_scale_spec_2 = v1beta2_scale_spec_convertToJSON(v1beta2_scale_spec_2);
	printf("repeating v1beta2_scale_spec:\n%s\n", cJSON_Print(jsonv1beta2_scale_spec_2));
}

int main() {
  test_v1beta2_scale_spec(1);
  test_v1beta2_scale_spec(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta2_scale_spec_MAIN
#endif // v1beta2_scale_spec_TEST
