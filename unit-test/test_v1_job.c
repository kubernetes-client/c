#ifndef v1_job_TEST
#define v1_job_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_job_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_job.h"
v1_job_t* instantiate_v1_job(int include_optional);

#include "test_v1_object_meta.c"
#include "test_v1_job_spec.c"
#include "test_v1_job_status.c"


v1_job_t* instantiate_v1_job(int include_optional) {
  v1_job_t* v1_job = NULL;
  if (include_optional) {
    v1_job = v1_job_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
       // false, not to have infinite recursion
      instantiate_v1_job_spec(0),
       // false, not to have infinite recursion
      instantiate_v1_job_status(0)
    );
  } else {
    v1_job = v1_job_create(
      "0",
      "0",
      NULL,
      NULL,
      NULL
    );
  }

  return v1_job;
}


#ifdef v1_job_MAIN

void test_v1_job(int include_optional) {
    v1_job_t* v1_job_1 = instantiate_v1_job(include_optional);

	cJSON* jsonv1_job_1 = v1_job_convertToJSON(v1_job_1);
	printf("v1_job :\n%s\n", cJSON_Print(jsonv1_job_1));
	v1_job_t* v1_job_2 = v1_job_parseFromJSON(jsonv1_job_1);
	cJSON* jsonv1_job_2 = v1_job_convertToJSON(v1_job_2);
	printf("repeating v1_job:\n%s\n", cJSON_Print(jsonv1_job_2));
}

int main() {
  test_v1_job(1);
  test_v1_job(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_job_MAIN
#endif // v1_job_TEST
