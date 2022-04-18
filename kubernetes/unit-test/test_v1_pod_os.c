#ifndef v1_pod_os_TEST
#define v1_pod_os_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_pod_os_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_pod_os.h"
v1_pod_os_t* instantiate_v1_pod_os(int include_optional);



v1_pod_os_t* instantiate_v1_pod_os(int include_optional) {
  v1_pod_os_t* v1_pod_os = NULL;
  if (include_optional) {
    v1_pod_os = v1_pod_os_create(
      "0"
    );
  } else {
    v1_pod_os = v1_pod_os_create(
      "0"
    );
  }

  return v1_pod_os;
}


#ifdef v1_pod_os_MAIN

void test_v1_pod_os(int include_optional) {
    v1_pod_os_t* v1_pod_os_1 = instantiate_v1_pod_os(include_optional);

	cJSON* jsonv1_pod_os_1 = v1_pod_os_convertToJSON(v1_pod_os_1);
	printf("v1_pod_os :\n%s\n", cJSON_Print(jsonv1_pod_os_1));
	v1_pod_os_t* v1_pod_os_2 = v1_pod_os_parseFromJSON(jsonv1_pod_os_1);
	cJSON* jsonv1_pod_os_2 = v1_pod_os_convertToJSON(v1_pod_os_2);
	printf("repeating v1_pod_os:\n%s\n", cJSON_Print(jsonv1_pod_os_2));
}

int main() {
  test_v1_pod_os(1);
  test_v1_pod_os(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_pod_os_MAIN
#endif // v1_pod_os_TEST
