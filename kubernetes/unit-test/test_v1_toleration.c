#ifndef v1_toleration_TEST
#define v1_toleration_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_toleration_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_toleration.h"
v1_toleration_t* instantiate_v1_toleration(int include_optional);



v1_toleration_t* instantiate_v1_toleration(int include_optional) {
  v1_toleration_t* v1_toleration = NULL;
  if (include_optional) {
    v1_toleration = v1_toleration_create(
      "0",
      "0",
      "0",
      56,
      "0"
    );
  } else {
    v1_toleration = v1_toleration_create(
      "0",
      "0",
      "0",
      56,
      "0"
    );
  }

  return v1_toleration;
}


#ifdef v1_toleration_MAIN

void test_v1_toleration(int include_optional) {
    v1_toleration_t* v1_toleration_1 = instantiate_v1_toleration(include_optional);

	cJSON* jsonv1_toleration_1 = v1_toleration_convertToJSON(v1_toleration_1);
	printf("v1_toleration :\n%s\n", cJSON_Print(jsonv1_toleration_1));
	v1_toleration_t* v1_toleration_2 = v1_toleration_parseFromJSON(jsonv1_toleration_1);
	cJSON* jsonv1_toleration_2 = v1_toleration_convertToJSON(v1_toleration_2);
	printf("repeating v1_toleration:\n%s\n", cJSON_Print(jsonv1_toleration_2));
}

int main() {
  test_v1_toleration(1);
  test_v1_toleration(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_toleration_MAIN
#endif // v1_toleration_TEST
