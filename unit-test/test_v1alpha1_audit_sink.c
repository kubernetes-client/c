#ifndef v1alpha1_audit_sink_TEST
#define v1alpha1_audit_sink_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha1_audit_sink_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha1_audit_sink.h"
v1alpha1_audit_sink_t* instantiate_v1alpha1_audit_sink(int include_optional);

#include "test_v1_object_meta.c"
#include "test_v1alpha1_audit_sink_spec.c"


v1alpha1_audit_sink_t* instantiate_v1alpha1_audit_sink(int include_optional) {
  v1alpha1_audit_sink_t* v1alpha1_audit_sink = NULL;
  if (include_optional) {
    v1alpha1_audit_sink = v1alpha1_audit_sink_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
       // false, not to have infinite recursion
      instantiate_v1alpha1_audit_sink_spec(0)
    );
  } else {
    v1alpha1_audit_sink = v1alpha1_audit_sink_create(
      "0",
      "0",
      NULL,
      NULL
    );
  }

  return v1alpha1_audit_sink;
}


#ifdef v1alpha1_audit_sink_MAIN

void test_v1alpha1_audit_sink(int include_optional) {
    v1alpha1_audit_sink_t* v1alpha1_audit_sink_1 = instantiate_v1alpha1_audit_sink(include_optional);

	cJSON* jsonv1alpha1_audit_sink_1 = v1alpha1_audit_sink_convertToJSON(v1alpha1_audit_sink_1);
	printf("v1alpha1_audit_sink :\n%s\n", cJSON_Print(jsonv1alpha1_audit_sink_1));
	v1alpha1_audit_sink_t* v1alpha1_audit_sink_2 = v1alpha1_audit_sink_parseFromJSON(jsonv1alpha1_audit_sink_1);
	cJSON* jsonv1alpha1_audit_sink_2 = v1alpha1_audit_sink_convertToJSON(v1alpha1_audit_sink_2);
	printf("repeating v1alpha1_audit_sink:\n%s\n", cJSON_Print(jsonv1alpha1_audit_sink_2));
}

int main() {
  test_v1alpha1_audit_sink(1);
  test_v1alpha1_audit_sink(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha1_audit_sink_MAIN
#endif // v1alpha1_audit_sink_TEST
