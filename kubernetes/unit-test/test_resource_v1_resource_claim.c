#ifndef resource_v1_resource_claim_TEST
#define resource_v1_resource_claim_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define resource_v1_resource_claim_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/resource_v1_resource_claim.h"
resource_v1_resource_claim_t* instantiate_resource_v1_resource_claim(int include_optional);

#include "test_v1_object_meta.c"
#include "test_v1_resource_claim_spec.c"
#include "test_v1_resource_claim_status.c"


resource_v1_resource_claim_t* instantiate_resource_v1_resource_claim(int include_optional) {
  resource_v1_resource_claim_t* resource_v1_resource_claim = NULL;
  if (include_optional) {
    resource_v1_resource_claim = resource_v1_resource_claim_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
       // false, not to have infinite recursion
      instantiate_v1_resource_claim_spec(0),
       // false, not to have infinite recursion
      instantiate_v1_resource_claim_status(0)
    );
  } else {
    resource_v1_resource_claim = resource_v1_resource_claim_create(
      "0",
      "0",
      NULL,
      NULL,
      NULL
    );
  }

  return resource_v1_resource_claim;
}


#ifdef resource_v1_resource_claim_MAIN

void test_resource_v1_resource_claim(int include_optional) {
    resource_v1_resource_claim_t* resource_v1_resource_claim_1 = instantiate_resource_v1_resource_claim(include_optional);

	cJSON* jsonresource_v1_resource_claim_1 = resource_v1_resource_claim_convertToJSON(resource_v1_resource_claim_1);
	printf("resource_v1_resource_claim :\n%s\n", cJSON_Print(jsonresource_v1_resource_claim_1));
	resource_v1_resource_claim_t* resource_v1_resource_claim_2 = resource_v1_resource_claim_parseFromJSON(jsonresource_v1_resource_claim_1);
	cJSON* jsonresource_v1_resource_claim_2 = resource_v1_resource_claim_convertToJSON(resource_v1_resource_claim_2);
	printf("repeating resource_v1_resource_claim:\n%s\n", cJSON_Print(jsonresource_v1_resource_claim_2));
}

int main() {
  test_resource_v1_resource_claim(1);
  test_resource_v1_resource_claim(0);

  printf("Hello world \n");
  return 0;
}

#endif // resource_v1_resource_claim_MAIN
#endif // resource_v1_resource_claim_TEST
