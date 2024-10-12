#ifndef v1alpha3_resource_claim_status_TEST
#define v1alpha3_resource_claim_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha3_resource_claim_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha3_resource_claim_status.h"
v1alpha3_resource_claim_status_t* instantiate_v1alpha3_resource_claim_status(int include_optional);

#include "test_v1alpha3_allocation_result.c"


v1alpha3_resource_claim_status_t* instantiate_v1alpha3_resource_claim_status(int include_optional) {
  v1alpha3_resource_claim_status_t* v1alpha3_resource_claim_status = NULL;
  if (include_optional) {
    v1alpha3_resource_claim_status = v1alpha3_resource_claim_status_create(
       // false, not to have infinite recursion
      instantiate_v1alpha3_allocation_result(0),
      1,
      list_createList()
    );
  } else {
    v1alpha3_resource_claim_status = v1alpha3_resource_claim_status_create(
      NULL,
      1,
      list_createList()
    );
  }

  return v1alpha3_resource_claim_status;
}


#ifdef v1alpha3_resource_claim_status_MAIN

void test_v1alpha3_resource_claim_status(int include_optional) {
    v1alpha3_resource_claim_status_t* v1alpha3_resource_claim_status_1 = instantiate_v1alpha3_resource_claim_status(include_optional);

	cJSON* jsonv1alpha3_resource_claim_status_1 = v1alpha3_resource_claim_status_convertToJSON(v1alpha3_resource_claim_status_1);
	printf("v1alpha3_resource_claim_status :\n%s\n", cJSON_Print(jsonv1alpha3_resource_claim_status_1));
	v1alpha3_resource_claim_status_t* v1alpha3_resource_claim_status_2 = v1alpha3_resource_claim_status_parseFromJSON(jsonv1alpha3_resource_claim_status_1);
	cJSON* jsonv1alpha3_resource_claim_status_2 = v1alpha3_resource_claim_status_convertToJSON(v1alpha3_resource_claim_status_2);
	printf("repeating v1alpha3_resource_claim_status:\n%s\n", cJSON_Print(jsonv1alpha3_resource_claim_status_2));
}

int main() {
  test_v1alpha3_resource_claim_status(1);
  test_v1alpha3_resource_claim_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha3_resource_claim_status_MAIN
#endif // v1alpha3_resource_claim_status_TEST
