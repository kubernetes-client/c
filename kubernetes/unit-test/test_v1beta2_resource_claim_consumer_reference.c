#ifndef v1beta2_resource_claim_consumer_reference_TEST
#define v1beta2_resource_claim_consumer_reference_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta2_resource_claim_consumer_reference_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta2_resource_claim_consumer_reference.h"
v1beta2_resource_claim_consumer_reference_t* instantiate_v1beta2_resource_claim_consumer_reference(int include_optional);



v1beta2_resource_claim_consumer_reference_t* instantiate_v1beta2_resource_claim_consumer_reference(int include_optional) {
  v1beta2_resource_claim_consumer_reference_t* v1beta2_resource_claim_consumer_reference = NULL;
  if (include_optional) {
    v1beta2_resource_claim_consumer_reference = v1beta2_resource_claim_consumer_reference_create(
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    v1beta2_resource_claim_consumer_reference = v1beta2_resource_claim_consumer_reference_create(
      "0",
      "0",
      "0",
      "0"
    );
  }

  return v1beta2_resource_claim_consumer_reference;
}


#ifdef v1beta2_resource_claim_consumer_reference_MAIN

void test_v1beta2_resource_claim_consumer_reference(int include_optional) {
    v1beta2_resource_claim_consumer_reference_t* v1beta2_resource_claim_consumer_reference_1 = instantiate_v1beta2_resource_claim_consumer_reference(include_optional);

	cJSON* jsonv1beta2_resource_claim_consumer_reference_1 = v1beta2_resource_claim_consumer_reference_convertToJSON(v1beta2_resource_claim_consumer_reference_1);
	printf("v1beta2_resource_claim_consumer_reference :\n%s\n", cJSON_Print(jsonv1beta2_resource_claim_consumer_reference_1));
	v1beta2_resource_claim_consumer_reference_t* v1beta2_resource_claim_consumer_reference_2 = v1beta2_resource_claim_consumer_reference_parseFromJSON(jsonv1beta2_resource_claim_consumer_reference_1);
	cJSON* jsonv1beta2_resource_claim_consumer_reference_2 = v1beta2_resource_claim_consumer_reference_convertToJSON(v1beta2_resource_claim_consumer_reference_2);
	printf("repeating v1beta2_resource_claim_consumer_reference:\n%s\n", cJSON_Print(jsonv1beta2_resource_claim_consumer_reference_2));
}

int main() {
  test_v1beta2_resource_claim_consumer_reference(1);
  test_v1beta2_resource_claim_consumer_reference(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta2_resource_claim_consumer_reference_MAIN
#endif // v1beta2_resource_claim_consumer_reference_TEST
