#ifndef v2alpha1_cron_job_list_TEST
#define v2alpha1_cron_job_list_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v2alpha1_cron_job_list_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v2alpha1_cron_job_list.h"
v2alpha1_cron_job_list_t* instantiate_v2alpha1_cron_job_list(int include_optional);

#include "test_v1_list_meta.c"


v2alpha1_cron_job_list_t* instantiate_v2alpha1_cron_job_list(int include_optional) {
  v2alpha1_cron_job_list_t* v2alpha1_cron_job_list = NULL;
  if (include_optional) {
    v2alpha1_cron_job_list = v2alpha1_cron_job_list_create(
      "0",
      list_create(),
      "0",
       // false, not to have infinite recursion
      instantiate_v1_list_meta(0)
    );
  } else {
    v2alpha1_cron_job_list = v2alpha1_cron_job_list_create(
      "0",
      list_create(),
      "0",
      NULL
    );
  }

  return v2alpha1_cron_job_list;
}


#ifdef v2alpha1_cron_job_list_MAIN

void test_v2alpha1_cron_job_list(int include_optional) {
    v2alpha1_cron_job_list_t* v2alpha1_cron_job_list_1 = instantiate_v2alpha1_cron_job_list(include_optional);

	cJSON* jsonv2alpha1_cron_job_list_1 = v2alpha1_cron_job_list_convertToJSON(v2alpha1_cron_job_list_1);
	printf("v2alpha1_cron_job_list :\n%s\n", cJSON_Print(jsonv2alpha1_cron_job_list_1));
	v2alpha1_cron_job_list_t* v2alpha1_cron_job_list_2 = v2alpha1_cron_job_list_parseFromJSON(jsonv2alpha1_cron_job_list_1);
	cJSON* jsonv2alpha1_cron_job_list_2 = v2alpha1_cron_job_list_convertToJSON(v2alpha1_cron_job_list_2);
	printf("repeating v2alpha1_cron_job_list:\n%s\n", cJSON_Print(jsonv2alpha1_cron_job_list_2));
}

int main() {
  test_v2alpha1_cron_job_list(1);
  test_v2alpha1_cron_job_list(0);

  printf("Hello world \n");
  return 0;
}

#endif // v2alpha1_cron_job_list_MAIN
#endif // v2alpha1_cron_job_list_TEST
