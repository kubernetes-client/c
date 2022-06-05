#ifndef v1_job_condition_TEST
#define v1_job_condition_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_job_condition_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_job_condition.h"
v1_job_condition_t* instantiate_v1_job_condition(int include_optional);



v1_job_condition_t* instantiate_v1_job_condition(int include_optional) {
  v1_job_condition_t* v1_job_condition = NULL;
  if (include_optional) {
    v1_job_condition = v1_job_condition_create(
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    v1_job_condition = v1_job_condition_create(
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return v1_job_condition;
}


#ifdef v1_job_condition_MAIN

void test_v1_job_condition(int include_optional) {
    v1_job_condition_t* v1_job_condition_1 = instantiate_v1_job_condition(include_optional);

	cJSON* jsonv1_job_condition_1 = v1_job_condition_convertToJSON(v1_job_condition_1);
	printf("v1_job_condition :\n%s\n", cJSON_Print(jsonv1_job_condition_1));
	v1_job_condition_t* v1_job_condition_2 = v1_job_condition_parseFromJSON(jsonv1_job_condition_1);
	cJSON* jsonv1_job_condition_2 = v1_job_condition_convertToJSON(v1_job_condition_2);
	printf("repeating v1_job_condition:\n%s\n", cJSON_Print(jsonv1_job_condition_2));
}

int main() {
  test_v1_job_condition(1);
  test_v1_job_condition(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_job_condition_MAIN
#endif // v1_job_condition_TEST
