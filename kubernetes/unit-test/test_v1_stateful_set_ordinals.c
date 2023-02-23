#ifndef v1_stateful_set_ordinals_TEST
#define v1_stateful_set_ordinals_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_stateful_set_ordinals_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_stateful_set_ordinals.h"
v1_stateful_set_ordinals_t* instantiate_v1_stateful_set_ordinals(int include_optional);



v1_stateful_set_ordinals_t* instantiate_v1_stateful_set_ordinals(int include_optional) {
  v1_stateful_set_ordinals_t* v1_stateful_set_ordinals = NULL;
  if (include_optional) {
    v1_stateful_set_ordinals = v1_stateful_set_ordinals_create(
      56
    );
  } else {
    v1_stateful_set_ordinals = v1_stateful_set_ordinals_create(
      56
    );
  }

  return v1_stateful_set_ordinals;
}


#ifdef v1_stateful_set_ordinals_MAIN

void test_v1_stateful_set_ordinals(int include_optional) {
    v1_stateful_set_ordinals_t* v1_stateful_set_ordinals_1 = instantiate_v1_stateful_set_ordinals(include_optional);

	cJSON* jsonv1_stateful_set_ordinals_1 = v1_stateful_set_ordinals_convertToJSON(v1_stateful_set_ordinals_1);
	printf("v1_stateful_set_ordinals :\n%s\n", cJSON_Print(jsonv1_stateful_set_ordinals_1));
	v1_stateful_set_ordinals_t* v1_stateful_set_ordinals_2 = v1_stateful_set_ordinals_parseFromJSON(jsonv1_stateful_set_ordinals_1);
	cJSON* jsonv1_stateful_set_ordinals_2 = v1_stateful_set_ordinals_convertToJSON(v1_stateful_set_ordinals_2);
	printf("repeating v1_stateful_set_ordinals:\n%s\n", cJSON_Print(jsonv1_stateful_set_ordinals_2));
}

int main() {
  test_v1_stateful_set_ordinals(1);
  test_v1_stateful_set_ordinals(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_stateful_set_ordinals_MAIN
#endif // v1_stateful_set_ordinals_TEST
