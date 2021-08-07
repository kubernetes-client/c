#ifndef v1_node_selector_term_TEST
#define v1_node_selector_term_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_node_selector_term_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_node_selector_term.h"
v1_node_selector_term_t* instantiate_v1_node_selector_term(int include_optional);



v1_node_selector_term_t* instantiate_v1_node_selector_term(int include_optional) {
  v1_node_selector_term_t* v1_node_selector_term = NULL;
  if (include_optional) {
    v1_node_selector_term = v1_node_selector_term_create(
      list_create(),
      list_create()
    );
  } else {
    v1_node_selector_term = v1_node_selector_term_create(
      list_create(),
      list_create()
    );
  }

  return v1_node_selector_term;
}


#ifdef v1_node_selector_term_MAIN

void test_v1_node_selector_term(int include_optional) {
    v1_node_selector_term_t* v1_node_selector_term_1 = instantiate_v1_node_selector_term(include_optional);

	cJSON* jsonv1_node_selector_term_1 = v1_node_selector_term_convertToJSON(v1_node_selector_term_1);
	printf("v1_node_selector_term :\n%s\n", cJSON_Print(jsonv1_node_selector_term_1));
	v1_node_selector_term_t* v1_node_selector_term_2 = v1_node_selector_term_parseFromJSON(jsonv1_node_selector_term_1);
	cJSON* jsonv1_node_selector_term_2 = v1_node_selector_term_convertToJSON(v1_node_selector_term_2);
	printf("repeating v1_node_selector_term:\n%s\n", cJSON_Print(jsonv1_node_selector_term_2));
}

int main() {
  test_v1_node_selector_term(1);
  test_v1_node_selector_term(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_node_selector_term_MAIN
#endif // v1_node_selector_term_TEST
