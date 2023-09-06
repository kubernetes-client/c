#ifndef v1beta1_match_resources_TEST
#define v1beta1_match_resources_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_match_resources_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_match_resources.h"
v1beta1_match_resources_t* instantiate_v1beta1_match_resources(int include_optional);

#include "test_v1_label_selector.c"
#include "test_v1_label_selector.c"


v1beta1_match_resources_t* instantiate_v1beta1_match_resources(int include_optional) {
  v1beta1_match_resources_t* v1beta1_match_resources = NULL;
  if (include_optional) {
    v1beta1_match_resources = v1beta1_match_resources_create(
      list_createList(),
      "0",
       // false, not to have infinite recursion
      instantiate_v1_label_selector(0),
       // false, not to have infinite recursion
      instantiate_v1_label_selector(0),
      list_createList()
    );
  } else {
    v1beta1_match_resources = v1beta1_match_resources_create(
      list_createList(),
      "0",
      NULL,
      NULL,
      list_createList()
    );
  }

  return v1beta1_match_resources;
}


#ifdef v1beta1_match_resources_MAIN

void test_v1beta1_match_resources(int include_optional) {
    v1beta1_match_resources_t* v1beta1_match_resources_1 = instantiate_v1beta1_match_resources(include_optional);

	cJSON* jsonv1beta1_match_resources_1 = v1beta1_match_resources_convertToJSON(v1beta1_match_resources_1);
	printf("v1beta1_match_resources :\n%s\n", cJSON_Print(jsonv1beta1_match_resources_1));
	v1beta1_match_resources_t* v1beta1_match_resources_2 = v1beta1_match_resources_parseFromJSON(jsonv1beta1_match_resources_1);
	cJSON* jsonv1beta1_match_resources_2 = v1beta1_match_resources_convertToJSON(v1beta1_match_resources_2);
	printf("repeating v1beta1_match_resources:\n%s\n", cJSON_Print(jsonv1beta1_match_resources_2));
}

int main() {
  test_v1beta1_match_resources(1);
  test_v1beta1_match_resources(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_match_resources_MAIN
#endif // v1beta1_match_resources_TEST
