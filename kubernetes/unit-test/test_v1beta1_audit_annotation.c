#ifndef v1beta1_audit_annotation_TEST
#define v1beta1_audit_annotation_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_audit_annotation_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_audit_annotation.h"
v1beta1_audit_annotation_t* instantiate_v1beta1_audit_annotation(int include_optional);



v1beta1_audit_annotation_t* instantiate_v1beta1_audit_annotation(int include_optional) {
  v1beta1_audit_annotation_t* v1beta1_audit_annotation = NULL;
  if (include_optional) {
    v1beta1_audit_annotation = v1beta1_audit_annotation_create(
      "0",
      "0"
    );
  } else {
    v1beta1_audit_annotation = v1beta1_audit_annotation_create(
      "0",
      "0"
    );
  }

  return v1beta1_audit_annotation;
}


#ifdef v1beta1_audit_annotation_MAIN

void test_v1beta1_audit_annotation(int include_optional) {
    v1beta1_audit_annotation_t* v1beta1_audit_annotation_1 = instantiate_v1beta1_audit_annotation(include_optional);

	cJSON* jsonv1beta1_audit_annotation_1 = v1beta1_audit_annotation_convertToJSON(v1beta1_audit_annotation_1);
	printf("v1beta1_audit_annotation :\n%s\n", cJSON_Print(jsonv1beta1_audit_annotation_1));
	v1beta1_audit_annotation_t* v1beta1_audit_annotation_2 = v1beta1_audit_annotation_parseFromJSON(jsonv1beta1_audit_annotation_1);
	cJSON* jsonv1beta1_audit_annotation_2 = v1beta1_audit_annotation_convertToJSON(v1beta1_audit_annotation_2);
	printf("repeating v1beta1_audit_annotation:\n%s\n", cJSON_Print(jsonv1beta1_audit_annotation_2));
}

int main() {
  test_v1beta1_audit_annotation(1);
  test_v1beta1_audit_annotation(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_audit_annotation_MAIN
#endif // v1beta1_audit_annotation_TEST
