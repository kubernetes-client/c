#ifndef v1alpha1_flow_distinguisher_method_TEST
#define v1alpha1_flow_distinguisher_method_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha1_flow_distinguisher_method_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha1_flow_distinguisher_method.h"
v1alpha1_flow_distinguisher_method_t* instantiate_v1alpha1_flow_distinguisher_method(int include_optional);



v1alpha1_flow_distinguisher_method_t* instantiate_v1alpha1_flow_distinguisher_method(int include_optional) {
  v1alpha1_flow_distinguisher_method_t* v1alpha1_flow_distinguisher_method = NULL;
  if (include_optional) {
    v1alpha1_flow_distinguisher_method = v1alpha1_flow_distinguisher_method_create(
      "0"
    );
  } else {
    v1alpha1_flow_distinguisher_method = v1alpha1_flow_distinguisher_method_create(
      "0"
    );
  }

  return v1alpha1_flow_distinguisher_method;
}


#ifdef v1alpha1_flow_distinguisher_method_MAIN

void test_v1alpha1_flow_distinguisher_method(int include_optional) {
    v1alpha1_flow_distinguisher_method_t* v1alpha1_flow_distinguisher_method_1 = instantiate_v1alpha1_flow_distinguisher_method(include_optional);

	cJSON* jsonv1alpha1_flow_distinguisher_method_1 = v1alpha1_flow_distinguisher_method_convertToJSON(v1alpha1_flow_distinguisher_method_1);
	printf("v1alpha1_flow_distinguisher_method :\n%s\n", cJSON_Print(jsonv1alpha1_flow_distinguisher_method_1));
	v1alpha1_flow_distinguisher_method_t* v1alpha1_flow_distinguisher_method_2 = v1alpha1_flow_distinguisher_method_parseFromJSON(jsonv1alpha1_flow_distinguisher_method_1);
	cJSON* jsonv1alpha1_flow_distinguisher_method_2 = v1alpha1_flow_distinguisher_method_convertToJSON(v1alpha1_flow_distinguisher_method_2);
	printf("repeating v1alpha1_flow_distinguisher_method:\n%s\n", cJSON_Print(jsonv1alpha1_flow_distinguisher_method_2));
}

int main() {
  test_v1alpha1_flow_distinguisher_method(1);
  test_v1alpha1_flow_distinguisher_method(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha1_flow_distinguisher_method_MAIN
#endif // v1alpha1_flow_distinguisher_method_TEST
