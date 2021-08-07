#ifndef v1_preferred_scheduling_term_TEST
#define v1_preferred_scheduling_term_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_preferred_scheduling_term_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_preferred_scheduling_term.h"
v1_preferred_scheduling_term_t* instantiate_v1_preferred_scheduling_term(int include_optional);

#include "test_v1_node_selector_term.c"


v1_preferred_scheduling_term_t* instantiate_v1_preferred_scheduling_term(int include_optional) {
  v1_preferred_scheduling_term_t* v1_preferred_scheduling_term = NULL;
  if (include_optional) {
    v1_preferred_scheduling_term = v1_preferred_scheduling_term_create(
       // false, not to have infinite recursion
      instantiate_v1_node_selector_term(0),
      56
    );
  } else {
    v1_preferred_scheduling_term = v1_preferred_scheduling_term_create(
      NULL,
      56
    );
  }

  return v1_preferred_scheduling_term;
}


#ifdef v1_preferred_scheduling_term_MAIN

void test_v1_preferred_scheduling_term(int include_optional) {
    v1_preferred_scheduling_term_t* v1_preferred_scheduling_term_1 = instantiate_v1_preferred_scheduling_term(include_optional);

	cJSON* jsonv1_preferred_scheduling_term_1 = v1_preferred_scheduling_term_convertToJSON(v1_preferred_scheduling_term_1);
	printf("v1_preferred_scheduling_term :\n%s\n", cJSON_Print(jsonv1_preferred_scheduling_term_1));
	v1_preferred_scheduling_term_t* v1_preferred_scheduling_term_2 = v1_preferred_scheduling_term_parseFromJSON(jsonv1_preferred_scheduling_term_1);
	cJSON* jsonv1_preferred_scheduling_term_2 = v1_preferred_scheduling_term_convertToJSON(v1_preferred_scheduling_term_2);
	printf("repeating v1_preferred_scheduling_term:\n%s\n", cJSON_Print(jsonv1_preferred_scheduling_term_2));
}

int main() {
  test_v1_preferred_scheduling_term(1);
  test_v1_preferred_scheduling_term(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_preferred_scheduling_term_MAIN
#endif // v1_preferred_scheduling_term_TEST
