#ifndef core_v1_resource_claim_TEST
#define core_v1_resource_claim_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define core_v1_resource_claim_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/core_v1_resource_claim.h"
core_v1_resource_claim_t* instantiate_core_v1_resource_claim(int include_optional);



core_v1_resource_claim_t* instantiate_core_v1_resource_claim(int include_optional) {
  core_v1_resource_claim_t* core_v1_resource_claim = NULL;
  if (include_optional) {
    core_v1_resource_claim = core_v1_resource_claim_create(
      "0",
      "0"
    );
  } else {
    core_v1_resource_claim = core_v1_resource_claim_create(
      "0",
      "0"
    );
  }

  return core_v1_resource_claim;
}


#ifdef core_v1_resource_claim_MAIN

void test_core_v1_resource_claim(int include_optional) {
    core_v1_resource_claim_t* core_v1_resource_claim_1 = instantiate_core_v1_resource_claim(include_optional);

	cJSON* jsoncore_v1_resource_claim_1 = core_v1_resource_claim_convertToJSON(core_v1_resource_claim_1);
	printf("core_v1_resource_claim :\n%s\n", cJSON_Print(jsoncore_v1_resource_claim_1));
	core_v1_resource_claim_t* core_v1_resource_claim_2 = core_v1_resource_claim_parseFromJSON(jsoncore_v1_resource_claim_1);
	cJSON* jsoncore_v1_resource_claim_2 = core_v1_resource_claim_convertToJSON(core_v1_resource_claim_2);
	printf("repeating core_v1_resource_claim:\n%s\n", cJSON_Print(jsoncore_v1_resource_claim_2));
}

int main() {
  test_core_v1_resource_claim(1);
  test_core_v1_resource_claim(0);

  printf("Hello world \n");
  return 0;
}

#endif // core_v1_resource_claim_MAIN
#endif // core_v1_resource_claim_TEST
