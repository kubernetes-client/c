#ifndef v1alpha3_resource_claim_template_TEST
#define v1alpha3_resource_claim_template_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha3_resource_claim_template_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha3_resource_claim_template.h"
v1alpha3_resource_claim_template_t* instantiate_v1alpha3_resource_claim_template(int include_optional);

#include "test_v1_object_meta.c"
#include "test_v1alpha3_resource_claim_template_spec.c"


v1alpha3_resource_claim_template_t* instantiate_v1alpha3_resource_claim_template(int include_optional) {
  v1alpha3_resource_claim_template_t* v1alpha3_resource_claim_template = NULL;
  if (include_optional) {
    v1alpha3_resource_claim_template = v1alpha3_resource_claim_template_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
       // false, not to have infinite recursion
      instantiate_v1alpha3_resource_claim_template_spec(0)
    );
  } else {
    v1alpha3_resource_claim_template = v1alpha3_resource_claim_template_create(
      "0",
      "0",
      NULL,
      NULL
    );
  }

  return v1alpha3_resource_claim_template;
}


#ifdef v1alpha3_resource_claim_template_MAIN

void test_v1alpha3_resource_claim_template(int include_optional) {
    v1alpha3_resource_claim_template_t* v1alpha3_resource_claim_template_1 = instantiate_v1alpha3_resource_claim_template(include_optional);

	cJSON* jsonv1alpha3_resource_claim_template_1 = v1alpha3_resource_claim_template_convertToJSON(v1alpha3_resource_claim_template_1);
	printf("v1alpha3_resource_claim_template :\n%s\n", cJSON_Print(jsonv1alpha3_resource_claim_template_1));
	v1alpha3_resource_claim_template_t* v1alpha3_resource_claim_template_2 = v1alpha3_resource_claim_template_parseFromJSON(jsonv1alpha3_resource_claim_template_1);
	cJSON* jsonv1alpha3_resource_claim_template_2 = v1alpha3_resource_claim_template_convertToJSON(v1alpha3_resource_claim_template_2);
	printf("repeating v1alpha3_resource_claim_template:\n%s\n", cJSON_Print(jsonv1alpha3_resource_claim_template_2));
}

int main() {
  test_v1alpha3_resource_claim_template(1);
  test_v1alpha3_resource_claim_template(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha3_resource_claim_template_MAIN
#endif // v1alpha3_resource_claim_template_TEST
