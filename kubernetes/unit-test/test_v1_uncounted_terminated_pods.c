#ifndef v1_uncounted_terminated_pods_TEST
#define v1_uncounted_terminated_pods_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_uncounted_terminated_pods_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_uncounted_terminated_pods.h"
v1_uncounted_terminated_pods_t* instantiate_v1_uncounted_terminated_pods(int include_optional);



v1_uncounted_terminated_pods_t* instantiate_v1_uncounted_terminated_pods(int include_optional) {
  v1_uncounted_terminated_pods_t* v1_uncounted_terminated_pods = NULL;
  if (include_optional) {
    v1_uncounted_terminated_pods = v1_uncounted_terminated_pods_create(
      list_create(),
      list_create()
    );
  } else {
    v1_uncounted_terminated_pods = v1_uncounted_terminated_pods_create(
      list_create(),
      list_create()
    );
  }

  return v1_uncounted_terminated_pods;
}


#ifdef v1_uncounted_terminated_pods_MAIN

void test_v1_uncounted_terminated_pods(int include_optional) {
    v1_uncounted_terminated_pods_t* v1_uncounted_terminated_pods_1 = instantiate_v1_uncounted_terminated_pods(include_optional);

	cJSON* jsonv1_uncounted_terminated_pods_1 = v1_uncounted_terminated_pods_convertToJSON(v1_uncounted_terminated_pods_1);
	printf("v1_uncounted_terminated_pods :\n%s\n", cJSON_Print(jsonv1_uncounted_terminated_pods_1));
	v1_uncounted_terminated_pods_t* v1_uncounted_terminated_pods_2 = v1_uncounted_terminated_pods_parseFromJSON(jsonv1_uncounted_terminated_pods_1);
	cJSON* jsonv1_uncounted_terminated_pods_2 = v1_uncounted_terminated_pods_convertToJSON(v1_uncounted_terminated_pods_2);
	printf("repeating v1_uncounted_terminated_pods:\n%s\n", cJSON_Print(jsonv1_uncounted_terminated_pods_2));
}

int main() {
  test_v1_uncounted_terminated_pods(1);
  test_v1_uncounted_terminated_pods(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_uncounted_terminated_pods_MAIN
#endif // v1_uncounted_terminated_pods_TEST
