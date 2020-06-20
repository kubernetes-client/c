#ifndef v1beta1_daemon_set_spec_TEST
#define v1beta1_daemon_set_spec_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_daemon_set_spec_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_daemon_set_spec.h"
v1beta1_daemon_set_spec_t* instantiate_v1beta1_daemon_set_spec(int include_optional);

#include "test_v1_label_selector.c"
#include "test_v1_pod_template_spec.c"
#include "test_v1beta1_daemon_set_update_strategy.c"


v1beta1_daemon_set_spec_t* instantiate_v1beta1_daemon_set_spec(int include_optional) {
  v1beta1_daemon_set_spec_t* v1beta1_daemon_set_spec = NULL;
  if (include_optional) {
    v1beta1_daemon_set_spec = v1beta1_daemon_set_spec_create(
      56,
      56,
       // false, not to have infinite recursion
      instantiate_v1_label_selector(0),
       // false, not to have infinite recursion
      instantiate_v1_pod_template_spec(0),
      56,
       // false, not to have infinite recursion
      instantiate_v1beta1_daemon_set_update_strategy(0)
    );
  } else {
    v1beta1_daemon_set_spec = v1beta1_daemon_set_spec_create(
      56,
      56,
      NULL,
      NULL,
      56,
      NULL
    );
  }

  return v1beta1_daemon_set_spec;
}


#ifdef v1beta1_daemon_set_spec_MAIN

void test_v1beta1_daemon_set_spec(int include_optional) {
    v1beta1_daemon_set_spec_t* v1beta1_daemon_set_spec_1 = instantiate_v1beta1_daemon_set_spec(include_optional);

	cJSON* jsonv1beta1_daemon_set_spec_1 = v1beta1_daemon_set_spec_convertToJSON(v1beta1_daemon_set_spec_1);
	printf("v1beta1_daemon_set_spec :\n%s\n", cJSON_Print(jsonv1beta1_daemon_set_spec_1));
	v1beta1_daemon_set_spec_t* v1beta1_daemon_set_spec_2 = v1beta1_daemon_set_spec_parseFromJSON(jsonv1beta1_daemon_set_spec_1);
	cJSON* jsonv1beta1_daemon_set_spec_2 = v1beta1_daemon_set_spec_convertToJSON(v1beta1_daemon_set_spec_2);
	printf("repeating v1beta1_daemon_set_spec:\n%s\n", cJSON_Print(jsonv1beta1_daemon_set_spec_2));
}

int main() {
  test_v1beta1_daemon_set_spec(1);
  test_v1beta1_daemon_set_spec(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_daemon_set_spec_MAIN
#endif // v1beta1_daemon_set_spec_TEST
