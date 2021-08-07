#ifndef admissionregistration_v1_service_reference_TEST
#define admissionregistration_v1_service_reference_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define admissionregistration_v1_service_reference_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/admissionregistration_v1_service_reference.h"
admissionregistration_v1_service_reference_t* instantiate_admissionregistration_v1_service_reference(int include_optional);



admissionregistration_v1_service_reference_t* instantiate_admissionregistration_v1_service_reference(int include_optional) {
  admissionregistration_v1_service_reference_t* admissionregistration_v1_service_reference = NULL;
  if (include_optional) {
    admissionregistration_v1_service_reference = admissionregistration_v1_service_reference_create(
      "0",
      "0",
      "0",
      56
    );
  } else {
    admissionregistration_v1_service_reference = admissionregistration_v1_service_reference_create(
      "0",
      "0",
      "0",
      56
    );
  }

  return admissionregistration_v1_service_reference;
}


#ifdef admissionregistration_v1_service_reference_MAIN

void test_admissionregistration_v1_service_reference(int include_optional) {
    admissionregistration_v1_service_reference_t* admissionregistration_v1_service_reference_1 = instantiate_admissionregistration_v1_service_reference(include_optional);

	cJSON* jsonadmissionregistration_v1_service_reference_1 = admissionregistration_v1_service_reference_convertToJSON(admissionregistration_v1_service_reference_1);
	printf("admissionregistration_v1_service_reference :\n%s\n", cJSON_Print(jsonadmissionregistration_v1_service_reference_1));
	admissionregistration_v1_service_reference_t* admissionregistration_v1_service_reference_2 = admissionregistration_v1_service_reference_parseFromJSON(jsonadmissionregistration_v1_service_reference_1);
	cJSON* jsonadmissionregistration_v1_service_reference_2 = admissionregistration_v1_service_reference_convertToJSON(admissionregistration_v1_service_reference_2);
	printf("repeating admissionregistration_v1_service_reference:\n%s\n", cJSON_Print(jsonadmissionregistration_v1_service_reference_2));
}

int main() {
  test_admissionregistration_v1_service_reference(1);
  test_admissionregistration_v1_service_reference(0);

  printf("Hello world \n");
  return 0;
}

#endif // admissionregistration_v1_service_reference_MAIN
#endif // admissionregistration_v1_service_reference_TEST
