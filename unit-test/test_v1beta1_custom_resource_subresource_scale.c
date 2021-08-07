#ifndef v1beta1_custom_resource_subresource_scale_TEST
#define v1beta1_custom_resource_subresource_scale_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_custom_resource_subresource_scale_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_custom_resource_subresource_scale.h"
v1beta1_custom_resource_subresource_scale_t* instantiate_v1beta1_custom_resource_subresource_scale(int include_optional);



v1beta1_custom_resource_subresource_scale_t* instantiate_v1beta1_custom_resource_subresource_scale(int include_optional) {
  v1beta1_custom_resource_subresource_scale_t* v1beta1_custom_resource_subresource_scale = NULL;
  if (include_optional) {
    v1beta1_custom_resource_subresource_scale = v1beta1_custom_resource_subresource_scale_create(
      "0",
      "0",
      "0"
    );
  } else {
    v1beta1_custom_resource_subresource_scale = v1beta1_custom_resource_subresource_scale_create(
      "0",
      "0",
      "0"
    );
  }

  return v1beta1_custom_resource_subresource_scale;
}


#ifdef v1beta1_custom_resource_subresource_scale_MAIN

void test_v1beta1_custom_resource_subresource_scale(int include_optional) {
    v1beta1_custom_resource_subresource_scale_t* v1beta1_custom_resource_subresource_scale_1 = instantiate_v1beta1_custom_resource_subresource_scale(include_optional);

	cJSON* jsonv1beta1_custom_resource_subresource_scale_1 = v1beta1_custom_resource_subresource_scale_convertToJSON(v1beta1_custom_resource_subresource_scale_1);
	printf("v1beta1_custom_resource_subresource_scale :\n%s\n", cJSON_Print(jsonv1beta1_custom_resource_subresource_scale_1));
	v1beta1_custom_resource_subresource_scale_t* v1beta1_custom_resource_subresource_scale_2 = v1beta1_custom_resource_subresource_scale_parseFromJSON(jsonv1beta1_custom_resource_subresource_scale_1);
	cJSON* jsonv1beta1_custom_resource_subresource_scale_2 = v1beta1_custom_resource_subresource_scale_convertToJSON(v1beta1_custom_resource_subresource_scale_2);
	printf("repeating v1beta1_custom_resource_subresource_scale:\n%s\n", cJSON_Print(jsonv1beta1_custom_resource_subresource_scale_2));
}

int main() {
  test_v1beta1_custom_resource_subresource_scale(1);
  test_v1beta1_custom_resource_subresource_scale(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_custom_resource_subresource_scale_MAIN
#endif // v1beta1_custom_resource_subresource_scale_TEST
