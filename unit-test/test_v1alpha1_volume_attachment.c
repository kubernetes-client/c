#ifndef v1alpha1_volume_attachment_TEST
#define v1alpha1_volume_attachment_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha1_volume_attachment_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha1_volume_attachment.h"
v1alpha1_volume_attachment_t* instantiate_v1alpha1_volume_attachment(int include_optional);

#include "test_v1_object_meta.c"
#include "test_v1alpha1_volume_attachment_spec.c"
#include "test_v1alpha1_volume_attachment_status.c"


v1alpha1_volume_attachment_t* instantiate_v1alpha1_volume_attachment(int include_optional) {
  v1alpha1_volume_attachment_t* v1alpha1_volume_attachment = NULL;
  if (include_optional) {
    v1alpha1_volume_attachment = v1alpha1_volume_attachment_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
       // false, not to have infinite recursion
      instantiate_v1alpha1_volume_attachment_spec(0),
       // false, not to have infinite recursion
      instantiate_v1alpha1_volume_attachment_status(0)
    );
  } else {
    v1alpha1_volume_attachment = v1alpha1_volume_attachment_create(
      "0",
      "0",
      NULL,
      NULL,
      NULL
    );
  }

  return v1alpha1_volume_attachment;
}


#ifdef v1alpha1_volume_attachment_MAIN

void test_v1alpha1_volume_attachment(int include_optional) {
    v1alpha1_volume_attachment_t* v1alpha1_volume_attachment_1 = instantiate_v1alpha1_volume_attachment(include_optional);

	cJSON* jsonv1alpha1_volume_attachment_1 = v1alpha1_volume_attachment_convertToJSON(v1alpha1_volume_attachment_1);
	printf("v1alpha1_volume_attachment :\n%s\n", cJSON_Print(jsonv1alpha1_volume_attachment_1));
	v1alpha1_volume_attachment_t* v1alpha1_volume_attachment_2 = v1alpha1_volume_attachment_parseFromJSON(jsonv1alpha1_volume_attachment_1);
	cJSON* jsonv1alpha1_volume_attachment_2 = v1alpha1_volume_attachment_convertToJSON(v1alpha1_volume_attachment_2);
	printf("repeating v1alpha1_volume_attachment:\n%s\n", cJSON_Print(jsonv1alpha1_volume_attachment_2));
}

int main() {
  test_v1alpha1_volume_attachment(1);
  test_v1alpha1_volume_attachment(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha1_volume_attachment_MAIN
#endif // v1alpha1_volume_attachment_TEST
