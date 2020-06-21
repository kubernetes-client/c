#ifndef flowcontrol_v1alpha1_subject_TEST
#define flowcontrol_v1alpha1_subject_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define flowcontrol_v1alpha1_subject_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/flowcontrol_v1alpha1_subject.h"
flowcontrol_v1alpha1_subject_t* instantiate_flowcontrol_v1alpha1_subject(int include_optional);

#include "test_v1alpha1_group_subject.c"
#include "test_v1alpha1_service_account_subject.c"
#include "test_v1alpha1_user_subject.c"


flowcontrol_v1alpha1_subject_t* instantiate_flowcontrol_v1alpha1_subject(int include_optional) {
  flowcontrol_v1alpha1_subject_t* flowcontrol_v1alpha1_subject = NULL;
  if (include_optional) {
    flowcontrol_v1alpha1_subject = flowcontrol_v1alpha1_subject_create(
       // false, not to have infinite recursion
      instantiate_v1alpha1_group_subject(0),
      "0",
       // false, not to have infinite recursion
      instantiate_v1alpha1_service_account_subject(0),
       // false, not to have infinite recursion
      instantiate_v1alpha1_user_subject(0)
    );
  } else {
    flowcontrol_v1alpha1_subject = flowcontrol_v1alpha1_subject_create(
      NULL,
      "0",
      NULL,
      NULL
    );
  }

  return flowcontrol_v1alpha1_subject;
}


#ifdef flowcontrol_v1alpha1_subject_MAIN

void test_flowcontrol_v1alpha1_subject(int include_optional) {
    flowcontrol_v1alpha1_subject_t* flowcontrol_v1alpha1_subject_1 = instantiate_flowcontrol_v1alpha1_subject(include_optional);

	cJSON* jsonflowcontrol_v1alpha1_subject_1 = flowcontrol_v1alpha1_subject_convertToJSON(flowcontrol_v1alpha1_subject_1);
	printf("flowcontrol_v1alpha1_subject :\n%s\n", cJSON_Print(jsonflowcontrol_v1alpha1_subject_1));
	flowcontrol_v1alpha1_subject_t* flowcontrol_v1alpha1_subject_2 = flowcontrol_v1alpha1_subject_parseFromJSON(jsonflowcontrol_v1alpha1_subject_1);
	cJSON* jsonflowcontrol_v1alpha1_subject_2 = flowcontrol_v1alpha1_subject_convertToJSON(flowcontrol_v1alpha1_subject_2);
	printf("repeating flowcontrol_v1alpha1_subject:\n%s\n", cJSON_Print(jsonflowcontrol_v1alpha1_subject_2));
}

int main() {
  test_flowcontrol_v1alpha1_subject(1);
  test_flowcontrol_v1alpha1_subject(0);

  printf("Hello world \n");
  return 0;
}

#endif // flowcontrol_v1alpha1_subject_MAIN
#endif // flowcontrol_v1alpha1_subject_TEST
