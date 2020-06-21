#ifndef v2alpha1_cron_job_spec_TEST
#define v2alpha1_cron_job_spec_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v2alpha1_cron_job_spec_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v2alpha1_cron_job_spec.h"
v2alpha1_cron_job_spec_t* instantiate_v2alpha1_cron_job_spec(int include_optional);

#include "test_v2alpha1_job_template_spec.c"


v2alpha1_cron_job_spec_t* instantiate_v2alpha1_cron_job_spec(int include_optional) {
  v2alpha1_cron_job_spec_t* v2alpha1_cron_job_spec = NULL;
  if (include_optional) {
    v2alpha1_cron_job_spec = v2alpha1_cron_job_spec_create(
      "0",
      56,
       // false, not to have infinite recursion
      instantiate_v2alpha1_job_template_spec(0),
      "0",
      56,
      56,
      1
    );
  } else {
    v2alpha1_cron_job_spec = v2alpha1_cron_job_spec_create(
      "0",
      56,
      NULL,
      "0",
      56,
      56,
      1
    );
  }

  return v2alpha1_cron_job_spec;
}


#ifdef v2alpha1_cron_job_spec_MAIN

void test_v2alpha1_cron_job_spec(int include_optional) {
    v2alpha1_cron_job_spec_t* v2alpha1_cron_job_spec_1 = instantiate_v2alpha1_cron_job_spec(include_optional);

	cJSON* jsonv2alpha1_cron_job_spec_1 = v2alpha1_cron_job_spec_convertToJSON(v2alpha1_cron_job_spec_1);
	printf("v2alpha1_cron_job_spec :\n%s\n", cJSON_Print(jsonv2alpha1_cron_job_spec_1));
	v2alpha1_cron_job_spec_t* v2alpha1_cron_job_spec_2 = v2alpha1_cron_job_spec_parseFromJSON(jsonv2alpha1_cron_job_spec_1);
	cJSON* jsonv2alpha1_cron_job_spec_2 = v2alpha1_cron_job_spec_convertToJSON(v2alpha1_cron_job_spec_2);
	printf("repeating v2alpha1_cron_job_spec:\n%s\n", cJSON_Print(jsonv2alpha1_cron_job_spec_2));
}

int main() {
  test_v2alpha1_cron_job_spec(1);
  test_v2alpha1_cron_job_spec(0);

  printf("Hello world \n");
  return 0;
}

#endif // v2alpha1_cron_job_spec_MAIN
#endif // v2alpha1_cron_job_spec_TEST
