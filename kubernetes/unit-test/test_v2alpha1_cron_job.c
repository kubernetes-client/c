#ifndef v2alpha1_cron_job_TEST
#define v2alpha1_cron_job_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v2alpha1_cron_job_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v2alpha1_cron_job.h"
v2alpha1_cron_job_t* instantiate_v2alpha1_cron_job(int include_optional);

#include "test_v1_object_meta.c"
#include "test_v2alpha1_cron_job_spec.c"
#include "test_v2alpha1_cron_job_status.c"


v2alpha1_cron_job_t* instantiate_v2alpha1_cron_job(int include_optional) {
  v2alpha1_cron_job_t* v2alpha1_cron_job = NULL;
  if (include_optional) {
    v2alpha1_cron_job = v2alpha1_cron_job_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
       // false, not to have infinite recursion
      instantiate_v2alpha1_cron_job_spec(0),
       // false, not to have infinite recursion
      instantiate_v2alpha1_cron_job_status(0)
    );
  } else {
    v2alpha1_cron_job = v2alpha1_cron_job_create(
      "0",
      "0",
      NULL,
      NULL,
      NULL
    );
  }

  return v2alpha1_cron_job;
}


#ifdef v2alpha1_cron_job_MAIN

void test_v2alpha1_cron_job(int include_optional) {
    v2alpha1_cron_job_t* v2alpha1_cron_job_1 = instantiate_v2alpha1_cron_job(include_optional);

	cJSON* jsonv2alpha1_cron_job_1 = v2alpha1_cron_job_convertToJSON(v2alpha1_cron_job_1);
	printf("v2alpha1_cron_job :\n%s\n", cJSON_Print(jsonv2alpha1_cron_job_1));
	v2alpha1_cron_job_t* v2alpha1_cron_job_2 = v2alpha1_cron_job_parseFromJSON(jsonv2alpha1_cron_job_1);
	cJSON* jsonv2alpha1_cron_job_2 = v2alpha1_cron_job_convertToJSON(v2alpha1_cron_job_2);
	printf("repeating v2alpha1_cron_job:\n%s\n", cJSON_Print(jsonv2alpha1_cron_job_2));
}

int main() {
  test_v2alpha1_cron_job(1);
  test_v2alpha1_cron_job(0);

  printf("Hello world \n");
  return 0;
}

#endif // v2alpha1_cron_job_MAIN
#endif // v2alpha1_cron_job_TEST
