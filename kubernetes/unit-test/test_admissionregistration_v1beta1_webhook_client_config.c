#ifndef admissionregistration_v1beta1_webhook_client_config_TEST
#define admissionregistration_v1beta1_webhook_client_config_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define admissionregistration_v1beta1_webhook_client_config_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/admissionregistration_v1beta1_webhook_client_config.h"
admissionregistration_v1beta1_webhook_client_config_t* instantiate_admissionregistration_v1beta1_webhook_client_config(int include_optional);

#include "test_admissionregistration_v1beta1_service_reference.c"


admissionregistration_v1beta1_webhook_client_config_t* instantiate_admissionregistration_v1beta1_webhook_client_config(int include_optional) {
  admissionregistration_v1beta1_webhook_client_config_t* admissionregistration_v1beta1_webhook_client_config = NULL;
  if (include_optional) {
    admissionregistration_v1beta1_webhook_client_config = admissionregistration_v1beta1_webhook_client_config_create(
      "YQ==",
       // false, not to have infinite recursion
      instantiate_admissionregistration_v1beta1_service_reference(0),
      "0"
    );
  } else {
    admissionregistration_v1beta1_webhook_client_config = admissionregistration_v1beta1_webhook_client_config_create(
      "YQ==",
      NULL,
      "0"
    );
  }

  return admissionregistration_v1beta1_webhook_client_config;
}


#ifdef admissionregistration_v1beta1_webhook_client_config_MAIN

void test_admissionregistration_v1beta1_webhook_client_config(int include_optional) {
    admissionregistration_v1beta1_webhook_client_config_t* admissionregistration_v1beta1_webhook_client_config_1 = instantiate_admissionregistration_v1beta1_webhook_client_config(include_optional);

	cJSON* jsonadmissionregistration_v1beta1_webhook_client_config_1 = admissionregistration_v1beta1_webhook_client_config_convertToJSON(admissionregistration_v1beta1_webhook_client_config_1);
	printf("admissionregistration_v1beta1_webhook_client_config :\n%s\n", cJSON_Print(jsonadmissionregistration_v1beta1_webhook_client_config_1));
	admissionregistration_v1beta1_webhook_client_config_t* admissionregistration_v1beta1_webhook_client_config_2 = admissionregistration_v1beta1_webhook_client_config_parseFromJSON(jsonadmissionregistration_v1beta1_webhook_client_config_1);
	cJSON* jsonadmissionregistration_v1beta1_webhook_client_config_2 = admissionregistration_v1beta1_webhook_client_config_convertToJSON(admissionregistration_v1beta1_webhook_client_config_2);
	printf("repeating admissionregistration_v1beta1_webhook_client_config:\n%s\n", cJSON_Print(jsonadmissionregistration_v1beta1_webhook_client_config_2));
}

int main() {
  test_admissionregistration_v1beta1_webhook_client_config(1);
  test_admissionregistration_v1beta1_webhook_client_config(0);

  printf("Hello world \n");
  return 0;
}

#endif // admissionregistration_v1beta1_webhook_client_config_MAIN
#endif // admissionregistration_v1beta1_webhook_client_config_TEST
