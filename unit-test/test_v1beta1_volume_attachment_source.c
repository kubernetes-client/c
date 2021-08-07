#ifndef v1beta1_volume_attachment_source_TEST
#define v1beta1_volume_attachment_source_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_volume_attachment_source_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_volume_attachment_source.h"
v1beta1_volume_attachment_source_t* instantiate_v1beta1_volume_attachment_source(int include_optional);

#include "test_v1_persistent_volume_spec.c"


v1beta1_volume_attachment_source_t* instantiate_v1beta1_volume_attachment_source(int include_optional) {
  v1beta1_volume_attachment_source_t* v1beta1_volume_attachment_source = NULL;
  if (include_optional) {
    v1beta1_volume_attachment_source = v1beta1_volume_attachment_source_create(
       // false, not to have infinite recursion
      instantiate_v1_persistent_volume_spec(0),
      "0"
    );
  } else {
    v1beta1_volume_attachment_source = v1beta1_volume_attachment_source_create(
      NULL,
      "0"
    );
  }

  return v1beta1_volume_attachment_source;
}


#ifdef v1beta1_volume_attachment_source_MAIN

void test_v1beta1_volume_attachment_source(int include_optional) {
    v1beta1_volume_attachment_source_t* v1beta1_volume_attachment_source_1 = instantiate_v1beta1_volume_attachment_source(include_optional);

	cJSON* jsonv1beta1_volume_attachment_source_1 = v1beta1_volume_attachment_source_convertToJSON(v1beta1_volume_attachment_source_1);
	printf("v1beta1_volume_attachment_source :\n%s\n", cJSON_Print(jsonv1beta1_volume_attachment_source_1));
	v1beta1_volume_attachment_source_t* v1beta1_volume_attachment_source_2 = v1beta1_volume_attachment_source_parseFromJSON(jsonv1beta1_volume_attachment_source_1);
	cJSON* jsonv1beta1_volume_attachment_source_2 = v1beta1_volume_attachment_source_convertToJSON(v1beta1_volume_attachment_source_2);
	printf("repeating v1beta1_volume_attachment_source:\n%s\n", cJSON_Print(jsonv1beta1_volume_attachment_source_2));
}

int main() {
  test_v1beta1_volume_attachment_source(1);
  test_v1beta1_volume_attachment_source(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_volume_attachment_source_MAIN
#endif // v1beta1_volume_attachment_source_TEST
