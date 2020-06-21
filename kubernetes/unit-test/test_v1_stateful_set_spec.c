#ifndef v1_stateful_set_spec_TEST
#define v1_stateful_set_spec_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_stateful_set_spec_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_stateful_set_spec.h"
v1_stateful_set_spec_t* instantiate_v1_stateful_set_spec(int include_optional);

#include "test_v1_label_selector.c"
#include "test_v1_pod_template_spec.c"
#include "test_v1_stateful_set_update_strategy.c"


v1_stateful_set_spec_t* instantiate_v1_stateful_set_spec(int include_optional) {
  v1_stateful_set_spec_t* v1_stateful_set_spec = NULL;
  if (include_optional) {
    v1_stateful_set_spec = v1_stateful_set_spec_create(
      "0",
      56,
      56,
       // false, not to have infinite recursion
      instantiate_v1_label_selector(0),
      "0",
       // false, not to have infinite recursion
      instantiate_v1_pod_template_spec(0),
       // false, not to have infinite recursion
      instantiate_v1_stateful_set_update_strategy(0),
      list_create()
    );
  } else {
    v1_stateful_set_spec = v1_stateful_set_spec_create(
      "0",
      56,
      56,
      NULL,
      "0",
      NULL,
      NULL,
      list_create()
    );
  }

  return v1_stateful_set_spec;
}


#ifdef v1_stateful_set_spec_MAIN

void test_v1_stateful_set_spec(int include_optional) {
    v1_stateful_set_spec_t* v1_stateful_set_spec_1 = instantiate_v1_stateful_set_spec(include_optional);

	cJSON* jsonv1_stateful_set_spec_1 = v1_stateful_set_spec_convertToJSON(v1_stateful_set_spec_1);
	printf("v1_stateful_set_spec :\n%s\n", cJSON_Print(jsonv1_stateful_set_spec_1));
	v1_stateful_set_spec_t* v1_stateful_set_spec_2 = v1_stateful_set_spec_parseFromJSON(jsonv1_stateful_set_spec_1);
	cJSON* jsonv1_stateful_set_spec_2 = v1_stateful_set_spec_convertToJSON(v1_stateful_set_spec_2);
	printf("repeating v1_stateful_set_spec:\n%s\n", cJSON_Print(jsonv1_stateful_set_spec_2));
}

int main() {
  test_v1_stateful_set_spec(1);
  test_v1_stateful_set_spec(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_stateful_set_spec_MAIN
#endif // v1_stateful_set_spec_TEST
