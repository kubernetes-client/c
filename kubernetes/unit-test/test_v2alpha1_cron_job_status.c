#ifndef v2alpha1_cron_job_status_TEST
#define v2alpha1_cron_job_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v2alpha1_cron_job_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v2alpha1_cron_job_status.h"
v2alpha1_cron_job_status_t* instantiate_v2alpha1_cron_job_status(int include_optional);



v2alpha1_cron_job_status_t* instantiate_v2alpha1_cron_job_status(int include_optional) {
  v2alpha1_cron_job_status_t* v2alpha1_cron_job_status = NULL;
  if (include_optional) {
    v2alpha1_cron_job_status = v2alpha1_cron_job_status_create(
      list_create(),
      "2013-10-20T19:20:30+01:00"
    );
  } else {
    v2alpha1_cron_job_status = v2alpha1_cron_job_status_create(
      list_create(),
      "2013-10-20T19:20:30+01:00"
    );
  }

  return v2alpha1_cron_job_status;
}


#ifdef v2alpha1_cron_job_status_MAIN

void test_v2alpha1_cron_job_status(int include_optional) {
    v2alpha1_cron_job_status_t* v2alpha1_cron_job_status_1 = instantiate_v2alpha1_cron_job_status(include_optional);

	cJSON* jsonv2alpha1_cron_job_status_1 = v2alpha1_cron_job_status_convertToJSON(v2alpha1_cron_job_status_1);
	printf("v2alpha1_cron_job_status :\n%s\n", cJSON_Print(jsonv2alpha1_cron_job_status_1));
	v2alpha1_cron_job_status_t* v2alpha1_cron_job_status_2 = v2alpha1_cron_job_status_parseFromJSON(jsonv2alpha1_cron_job_status_1);
	cJSON* jsonv2alpha1_cron_job_status_2 = v2alpha1_cron_job_status_convertToJSON(v2alpha1_cron_job_status_2);
	printf("repeating v2alpha1_cron_job_status:\n%s\n", cJSON_Print(jsonv2alpha1_cron_job_status_2));
}

int main() {
  test_v2alpha1_cron_job_status(1);
  test_v2alpha1_cron_job_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // v2alpha1_cron_job_status_MAIN
#endif // v2alpha1_cron_job_status_TEST
