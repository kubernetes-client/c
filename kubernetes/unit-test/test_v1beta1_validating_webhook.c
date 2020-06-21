#ifndef v1beta1_validating_webhook_TEST
#define v1beta1_validating_webhook_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_validating_webhook_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_validating_webhook.h"
v1beta1_validating_webhook_t* instantiate_v1beta1_validating_webhook(int include_optional);

#include "test_admissionregistration_v1beta1_webhook_client_config.c"
#include "test_v1_label_selector.c"
#include "test_v1_label_selector.c"


v1beta1_validating_webhook_t* instantiate_v1beta1_validating_webhook(int include_optional) {
  v1beta1_validating_webhook_t* v1beta1_validating_webhook = NULL;
  if (include_optional) {
    v1beta1_validating_webhook = v1beta1_validating_webhook_create(
      list_create(),
       // false, not to have infinite recursion
      instantiate_admissionregistration_v1beta1_webhook_client_config(0),
      "0",
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_label_selector(0),
       // false, not to have infinite recursion
      instantiate_v1_label_selector(0),
      list_create(),
      "0",
      56
    );
  } else {
    v1beta1_validating_webhook = v1beta1_validating_webhook_create(
      list_create(),
      NULL,
      "0",
      "0",
      "0",
      NULL,
      NULL,
      list_create(),
      "0",
      56
    );
  }

  return v1beta1_validating_webhook;
}


#ifdef v1beta1_validating_webhook_MAIN

void test_v1beta1_validating_webhook(int include_optional) {
    v1beta1_validating_webhook_t* v1beta1_validating_webhook_1 = instantiate_v1beta1_validating_webhook(include_optional);

	cJSON* jsonv1beta1_validating_webhook_1 = v1beta1_validating_webhook_convertToJSON(v1beta1_validating_webhook_1);
	printf("v1beta1_validating_webhook :\n%s\n", cJSON_Print(jsonv1beta1_validating_webhook_1));
	v1beta1_validating_webhook_t* v1beta1_validating_webhook_2 = v1beta1_validating_webhook_parseFromJSON(jsonv1beta1_validating_webhook_1);
	cJSON* jsonv1beta1_validating_webhook_2 = v1beta1_validating_webhook_convertToJSON(v1beta1_validating_webhook_2);
	printf("repeating v1beta1_validating_webhook:\n%s\n", cJSON_Print(jsonv1beta1_validating_webhook_2));
}

int main() {
  test_v1beta1_validating_webhook(1);
  test_v1beta1_validating_webhook(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_validating_webhook_MAIN
#endif // v1beta1_validating_webhook_TEST
