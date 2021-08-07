#ifndef v1beta1_cron_job_spec_TEST
#define v1beta1_cron_job_spec_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_cron_job_spec_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_cron_job_spec.h"
v1beta1_cron_job_spec_t* instantiate_v1beta1_cron_job_spec(int include_optional);

#include "test_v1beta1_job_template_spec.c"


v1beta1_cron_job_spec_t* instantiate_v1beta1_cron_job_spec(int include_optional) {
  v1beta1_cron_job_spec_t* v1beta1_cron_job_spec = NULL;
  if (include_optional) {
    v1beta1_cron_job_spec = v1beta1_cron_job_spec_create(
      "0",
      56,
       // false, not to have infinite recursion
      instantiate_v1beta1_job_template_spec(0),
      "0",
      56,
      56,
      1
    );
  } else {
    v1beta1_cron_job_spec = v1beta1_cron_job_spec_create(
      "0",
      56,
      NULL,
      "0",
      56,
      56,
      1
    );
  }

  return v1beta1_cron_job_spec;
}


#ifdef v1beta1_cron_job_spec_MAIN

void test_v1beta1_cron_job_spec(int include_optional) {
    v1beta1_cron_job_spec_t* v1beta1_cron_job_spec_1 = instantiate_v1beta1_cron_job_spec(include_optional);

	cJSON* jsonv1beta1_cron_job_spec_1 = v1beta1_cron_job_spec_convertToJSON(v1beta1_cron_job_spec_1);
	printf("v1beta1_cron_job_spec :\n%s\n", cJSON_Print(jsonv1beta1_cron_job_spec_1));
	v1beta1_cron_job_spec_t* v1beta1_cron_job_spec_2 = v1beta1_cron_job_spec_parseFromJSON(jsonv1beta1_cron_job_spec_1);
	cJSON* jsonv1beta1_cron_job_spec_2 = v1beta1_cron_job_spec_convertToJSON(v1beta1_cron_job_spec_2);
	printf("repeating v1beta1_cron_job_spec:\n%s\n", cJSON_Print(jsonv1beta1_cron_job_spec_2));
}

int main() {
  test_v1beta1_cron_job_spec(1);
  test_v1beta1_cron_job_spec(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_cron_job_spec_MAIN
#endif // v1beta1_cron_job_spec_TEST
