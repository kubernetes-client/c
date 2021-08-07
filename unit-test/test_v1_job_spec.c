#ifndef v1_job_spec_TEST
#define v1_job_spec_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_job_spec_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_job_spec.h"
v1_job_spec_t* instantiate_v1_job_spec(int include_optional);

#include "test_v1_label_selector.c"
#include "test_v1_pod_template_spec.c"


v1_job_spec_t* instantiate_v1_job_spec(int include_optional) {
  v1_job_spec_t* v1_job_spec = NULL;
  if (include_optional) {
    v1_job_spec = v1_job_spec_create(
      56,
      56,
      56,
      1,
      56,
       // false, not to have infinite recursion
      instantiate_v1_label_selector(0),
       // false, not to have infinite recursion
      instantiate_v1_pod_template_spec(0),
      56
    );
  } else {
    v1_job_spec = v1_job_spec_create(
      56,
      56,
      56,
      1,
      56,
      NULL,
      NULL,
      56
    );
  }

  return v1_job_spec;
}


#ifdef v1_job_spec_MAIN

void test_v1_job_spec(int include_optional) {
    v1_job_spec_t* v1_job_spec_1 = instantiate_v1_job_spec(include_optional);

	cJSON* jsonv1_job_spec_1 = v1_job_spec_convertToJSON(v1_job_spec_1);
	printf("v1_job_spec :\n%s\n", cJSON_Print(jsonv1_job_spec_1));
	v1_job_spec_t* v1_job_spec_2 = v1_job_spec_parseFromJSON(jsonv1_job_spec_1);
	cJSON* jsonv1_job_spec_2 = v1_job_spec_convertToJSON(v1_job_spec_2);
	printf("repeating v1_job_spec:\n%s\n", cJSON_Print(jsonv1_job_spec_2));
}

int main() {
  test_v1_job_spec(1);
  test_v1_job_spec(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_job_spec_MAIN
#endif // v1_job_spec_TEST
