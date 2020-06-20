#ifndef v1_sysctl_TEST
#define v1_sysctl_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_sysctl_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_sysctl.h"
v1_sysctl_t* instantiate_v1_sysctl(int include_optional);



v1_sysctl_t* instantiate_v1_sysctl(int include_optional) {
  v1_sysctl_t* v1_sysctl = NULL;
  if (include_optional) {
    v1_sysctl = v1_sysctl_create(
      "0",
      "0"
    );
  } else {
    v1_sysctl = v1_sysctl_create(
      "0",
      "0"
    );
  }

  return v1_sysctl;
}


#ifdef v1_sysctl_MAIN

void test_v1_sysctl(int include_optional) {
    v1_sysctl_t* v1_sysctl_1 = instantiate_v1_sysctl(include_optional);

	cJSON* jsonv1_sysctl_1 = v1_sysctl_convertToJSON(v1_sysctl_1);
	printf("v1_sysctl :\n%s\n", cJSON_Print(jsonv1_sysctl_1));
	v1_sysctl_t* v1_sysctl_2 = v1_sysctl_parseFromJSON(jsonv1_sysctl_1);
	cJSON* jsonv1_sysctl_2 = v1_sysctl_convertToJSON(v1_sysctl_2);
	printf("repeating v1_sysctl:\n%s\n", cJSON_Print(jsonv1_sysctl_2));
}

int main() {
  test_v1_sysctl(1);
  test_v1_sysctl(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_sysctl_MAIN
#endif // v1_sysctl_TEST
