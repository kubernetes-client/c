#ifndef v1_weighted_pod_affinity_term_TEST
#define v1_weighted_pod_affinity_term_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_weighted_pod_affinity_term_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_weighted_pod_affinity_term.h"
v1_weighted_pod_affinity_term_t* instantiate_v1_weighted_pod_affinity_term(int include_optional);

#include "test_v1_pod_affinity_term.c"


v1_weighted_pod_affinity_term_t* instantiate_v1_weighted_pod_affinity_term(int include_optional) {
  v1_weighted_pod_affinity_term_t* v1_weighted_pod_affinity_term = NULL;
  if (include_optional) {
    v1_weighted_pod_affinity_term = v1_weighted_pod_affinity_term_create(
       // false, not to have infinite recursion
      instantiate_v1_pod_affinity_term(0),
      56
    );
  } else {
    v1_weighted_pod_affinity_term = v1_weighted_pod_affinity_term_create(
      NULL,
      56
    );
  }

  return v1_weighted_pod_affinity_term;
}


#ifdef v1_weighted_pod_affinity_term_MAIN

void test_v1_weighted_pod_affinity_term(int include_optional) {
    v1_weighted_pod_affinity_term_t* v1_weighted_pod_affinity_term_1 = instantiate_v1_weighted_pod_affinity_term(include_optional);

	cJSON* jsonv1_weighted_pod_affinity_term_1 = v1_weighted_pod_affinity_term_convertToJSON(v1_weighted_pod_affinity_term_1);
	printf("v1_weighted_pod_affinity_term :\n%s\n", cJSON_Print(jsonv1_weighted_pod_affinity_term_1));
	v1_weighted_pod_affinity_term_t* v1_weighted_pod_affinity_term_2 = v1_weighted_pod_affinity_term_parseFromJSON(jsonv1_weighted_pod_affinity_term_1);
	cJSON* jsonv1_weighted_pod_affinity_term_2 = v1_weighted_pod_affinity_term_convertToJSON(v1_weighted_pod_affinity_term_2);
	printf("repeating v1_weighted_pod_affinity_term:\n%s\n", cJSON_Print(jsonv1_weighted_pod_affinity_term_2));
}

int main() {
  test_v1_weighted_pod_affinity_term(1);
  test_v1_weighted_pod_affinity_term(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_weighted_pod_affinity_term_MAIN
#endif // v1_weighted_pod_affinity_term_TEST
