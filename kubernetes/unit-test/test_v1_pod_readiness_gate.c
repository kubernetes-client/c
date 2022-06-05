#ifndef v1_pod_readiness_gate_TEST
#define v1_pod_readiness_gate_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_pod_readiness_gate_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_pod_readiness_gate.h"
v1_pod_readiness_gate_t* instantiate_v1_pod_readiness_gate(int include_optional);



v1_pod_readiness_gate_t* instantiate_v1_pod_readiness_gate(int include_optional) {
  v1_pod_readiness_gate_t* v1_pod_readiness_gate = NULL;
  if (include_optional) {
    v1_pod_readiness_gate = v1_pod_readiness_gate_create(
      "0"
    );
  } else {
    v1_pod_readiness_gate = v1_pod_readiness_gate_create(
      "0"
    );
  }

  return v1_pod_readiness_gate;
}


#ifdef v1_pod_readiness_gate_MAIN

void test_v1_pod_readiness_gate(int include_optional) {
    v1_pod_readiness_gate_t* v1_pod_readiness_gate_1 = instantiate_v1_pod_readiness_gate(include_optional);

	cJSON* jsonv1_pod_readiness_gate_1 = v1_pod_readiness_gate_convertToJSON(v1_pod_readiness_gate_1);
	printf("v1_pod_readiness_gate :\n%s\n", cJSON_Print(jsonv1_pod_readiness_gate_1));
	v1_pod_readiness_gate_t* v1_pod_readiness_gate_2 = v1_pod_readiness_gate_parseFromJSON(jsonv1_pod_readiness_gate_1);
	cJSON* jsonv1_pod_readiness_gate_2 = v1_pod_readiness_gate_convertToJSON(v1_pod_readiness_gate_2);
	printf("repeating v1_pod_readiness_gate:\n%s\n", cJSON_Print(jsonv1_pod_readiness_gate_2));
}

int main() {
  test_v1_pod_readiness_gate(1);
  test_v1_pod_readiness_gate(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_pod_readiness_gate_MAIN
#endif // v1_pod_readiness_gate_TEST
