#ifndef v1alpha1_target_responder_TEST
#define v1alpha1_target_responder_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha1_target_responder_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha1_target_responder.h"
v1alpha1_target_responder_t* instantiate_v1alpha1_target_responder(int include_optional);



v1alpha1_target_responder_t* instantiate_v1alpha1_target_responder(int include_optional) {
  v1alpha1_target_responder_t* v1alpha1_target_responder = NULL;
  if (include_optional) {
    v1alpha1_target_responder = v1alpha1_target_responder_create(
      "0",
      56,
      "0"
    );
  } else {
    v1alpha1_target_responder = v1alpha1_target_responder_create(
      "0",
      56,
      "0"
    );
  }

  return v1alpha1_target_responder;
}


#ifdef v1alpha1_target_responder_MAIN

void test_v1alpha1_target_responder(int include_optional) {
    v1alpha1_target_responder_t* v1alpha1_target_responder_1 = instantiate_v1alpha1_target_responder(include_optional);

	cJSON* jsonv1alpha1_target_responder_1 = v1alpha1_target_responder_convertToJSON(v1alpha1_target_responder_1);
	printf("v1alpha1_target_responder :\n%s\n", cJSON_Print(jsonv1alpha1_target_responder_1));
	v1alpha1_target_responder_t* v1alpha1_target_responder_2 = v1alpha1_target_responder_parseFromJSON(jsonv1alpha1_target_responder_1);
	cJSON* jsonv1alpha1_target_responder_2 = v1alpha1_target_responder_convertToJSON(v1alpha1_target_responder_2);
	printf("repeating v1alpha1_target_responder:\n%s\n", cJSON_Print(jsonv1alpha1_target_responder_2));
}

int main() {
  test_v1alpha1_target_responder(1);
  test_v1alpha1_target_responder(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha1_target_responder_MAIN
#endif // v1alpha1_target_responder_TEST
