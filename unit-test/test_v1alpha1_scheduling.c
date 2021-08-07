#ifndef v1alpha1_scheduling_TEST
#define v1alpha1_scheduling_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha1_scheduling_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha1_scheduling.h"
v1alpha1_scheduling_t* instantiate_v1alpha1_scheduling(int include_optional);



v1alpha1_scheduling_t* instantiate_v1alpha1_scheduling(int include_optional) {
  v1alpha1_scheduling_t* v1alpha1_scheduling = NULL;
  if (include_optional) {
    v1alpha1_scheduling = v1alpha1_scheduling_create(
      list_create(),
      list_create()
    );
  } else {
    v1alpha1_scheduling = v1alpha1_scheduling_create(
      list_create(),
      list_create()
    );
  }

  return v1alpha1_scheduling;
}


#ifdef v1alpha1_scheduling_MAIN

void test_v1alpha1_scheduling(int include_optional) {
    v1alpha1_scheduling_t* v1alpha1_scheduling_1 = instantiate_v1alpha1_scheduling(include_optional);

	cJSON* jsonv1alpha1_scheduling_1 = v1alpha1_scheduling_convertToJSON(v1alpha1_scheduling_1);
	printf("v1alpha1_scheduling :\n%s\n", cJSON_Print(jsonv1alpha1_scheduling_1));
	v1alpha1_scheduling_t* v1alpha1_scheduling_2 = v1alpha1_scheduling_parseFromJSON(jsonv1alpha1_scheduling_1);
	cJSON* jsonv1alpha1_scheduling_2 = v1alpha1_scheduling_convertToJSON(v1alpha1_scheduling_2);
	printf("repeating v1alpha1_scheduling:\n%s\n", cJSON_Print(jsonv1alpha1_scheduling_2));
}

int main() {
  test_v1alpha1_scheduling(1);
  test_v1alpha1_scheduling(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha1_scheduling_MAIN
#endif // v1alpha1_scheduling_TEST
