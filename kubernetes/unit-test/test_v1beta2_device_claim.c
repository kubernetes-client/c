#ifndef v1beta2_device_claim_TEST
#define v1beta2_device_claim_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta2_device_claim_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta2_device_claim.h"
v1beta2_device_claim_t* instantiate_v1beta2_device_claim(int include_optional);



v1beta2_device_claim_t* instantiate_v1beta2_device_claim(int include_optional) {
  v1beta2_device_claim_t* v1beta2_device_claim = NULL;
  if (include_optional) {
    v1beta2_device_claim = v1beta2_device_claim_create(
      list_createList(),
      list_createList(),
      list_createList()
    );
  } else {
    v1beta2_device_claim = v1beta2_device_claim_create(
      list_createList(),
      list_createList(),
      list_createList()
    );
  }

  return v1beta2_device_claim;
}


#ifdef v1beta2_device_claim_MAIN

void test_v1beta2_device_claim(int include_optional) {
    v1beta2_device_claim_t* v1beta2_device_claim_1 = instantiate_v1beta2_device_claim(include_optional);

	cJSON* jsonv1beta2_device_claim_1 = v1beta2_device_claim_convertToJSON(v1beta2_device_claim_1);
	printf("v1beta2_device_claim :\n%s\n", cJSON_Print(jsonv1beta2_device_claim_1));
	v1beta2_device_claim_t* v1beta2_device_claim_2 = v1beta2_device_claim_parseFromJSON(jsonv1beta2_device_claim_1);
	cJSON* jsonv1beta2_device_claim_2 = v1beta2_device_claim_convertToJSON(v1beta2_device_claim_2);
	printf("repeating v1beta2_device_claim:\n%s\n", cJSON_Print(jsonv1beta2_device_claim_2));
}

int main() {
  test_v1beta2_device_claim(1);
  test_v1beta2_device_claim(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta2_device_claim_MAIN
#endif // v1beta2_device_claim_TEST
