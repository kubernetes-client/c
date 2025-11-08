#ifndef v1beta1_mutation_TEST
#define v1beta1_mutation_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_mutation_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_mutation.h"
v1beta1_mutation_t* instantiate_v1beta1_mutation(int include_optional);

#include "test_v1beta1_apply_configuration.c"
#include "test_v1beta1_json_patch.c"


v1beta1_mutation_t* instantiate_v1beta1_mutation(int include_optional) {
  v1beta1_mutation_t* v1beta1_mutation = NULL;
  if (include_optional) {
    v1beta1_mutation = v1beta1_mutation_create(
       // false, not to have infinite recursion
      instantiate_v1beta1_apply_configuration(0),
       // false, not to have infinite recursion
      instantiate_v1beta1_json_patch(0),
      "0"
    );
  } else {
    v1beta1_mutation = v1beta1_mutation_create(
      NULL,
      NULL,
      "0"
    );
  }

  return v1beta1_mutation;
}


#ifdef v1beta1_mutation_MAIN

void test_v1beta1_mutation(int include_optional) {
    v1beta1_mutation_t* v1beta1_mutation_1 = instantiate_v1beta1_mutation(include_optional);

	cJSON* jsonv1beta1_mutation_1 = v1beta1_mutation_convertToJSON(v1beta1_mutation_1);
	printf("v1beta1_mutation :\n%s\n", cJSON_Print(jsonv1beta1_mutation_1));
	v1beta1_mutation_t* v1beta1_mutation_2 = v1beta1_mutation_parseFromJSON(jsonv1beta1_mutation_1);
	cJSON* jsonv1beta1_mutation_2 = v1beta1_mutation_convertToJSON(v1beta1_mutation_2);
	printf("repeating v1beta1_mutation:\n%s\n", cJSON_Print(jsonv1beta1_mutation_2));
}

int main() {
  test_v1beta1_mutation(1);
  test_v1beta1_mutation(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_mutation_MAIN
#endif // v1beta1_mutation_TEST
