#ifndef v1alpha1_requester_TEST
#define v1alpha1_requester_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha1_requester_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha1_requester.h"
v1alpha1_requester_t* instantiate_v1alpha1_requester(int include_optional);



v1alpha1_requester_t* instantiate_v1alpha1_requester(int include_optional) {
  v1alpha1_requester_t* v1alpha1_requester = NULL;
  if (include_optional) {
    v1alpha1_requester = v1alpha1_requester_create(
      "0",
      "0"
    );
  } else {
    v1alpha1_requester = v1alpha1_requester_create(
      "0",
      "0"
    );
  }

  return v1alpha1_requester;
}


#ifdef v1alpha1_requester_MAIN

void test_v1alpha1_requester(int include_optional) {
    v1alpha1_requester_t* v1alpha1_requester_1 = instantiate_v1alpha1_requester(include_optional);

	cJSON* jsonv1alpha1_requester_1 = v1alpha1_requester_convertToJSON(v1alpha1_requester_1);
	printf("v1alpha1_requester :\n%s\n", cJSON_Print(jsonv1alpha1_requester_1));
	v1alpha1_requester_t* v1alpha1_requester_2 = v1alpha1_requester_parseFromJSON(jsonv1alpha1_requester_1);
	cJSON* jsonv1alpha1_requester_2 = v1alpha1_requester_convertToJSON(v1alpha1_requester_2);
	printf("repeating v1alpha1_requester:\n%s\n", cJSON_Print(jsonv1alpha1_requester_2));
}

int main() {
  test_v1alpha1_requester(1);
  test_v1alpha1_requester(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha1_requester_MAIN
#endif // v1alpha1_requester_TEST
