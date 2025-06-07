#ifndef v1beta1_cluster_trust_bundle_TEST
#define v1beta1_cluster_trust_bundle_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_cluster_trust_bundle_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_cluster_trust_bundle.h"
v1beta1_cluster_trust_bundle_t* instantiate_v1beta1_cluster_trust_bundle(int include_optional);

#include "test_v1_object_meta.c"
#include "test_v1beta1_cluster_trust_bundle_spec.c"


v1beta1_cluster_trust_bundle_t* instantiate_v1beta1_cluster_trust_bundle(int include_optional) {
  v1beta1_cluster_trust_bundle_t* v1beta1_cluster_trust_bundle = NULL;
  if (include_optional) {
    v1beta1_cluster_trust_bundle = v1beta1_cluster_trust_bundle_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
       // false, not to have infinite recursion
      instantiate_v1beta1_cluster_trust_bundle_spec(0)
    );
  } else {
    v1beta1_cluster_trust_bundle = v1beta1_cluster_trust_bundle_create(
      "0",
      "0",
      NULL,
      NULL
    );
  }

  return v1beta1_cluster_trust_bundle;
}


#ifdef v1beta1_cluster_trust_bundle_MAIN

void test_v1beta1_cluster_trust_bundle(int include_optional) {
    v1beta1_cluster_trust_bundle_t* v1beta1_cluster_trust_bundle_1 = instantiate_v1beta1_cluster_trust_bundle(include_optional);

	cJSON* jsonv1beta1_cluster_trust_bundle_1 = v1beta1_cluster_trust_bundle_convertToJSON(v1beta1_cluster_trust_bundle_1);
	printf("v1beta1_cluster_trust_bundle :\n%s\n", cJSON_Print(jsonv1beta1_cluster_trust_bundle_1));
	v1beta1_cluster_trust_bundle_t* v1beta1_cluster_trust_bundle_2 = v1beta1_cluster_trust_bundle_parseFromJSON(jsonv1beta1_cluster_trust_bundle_1);
	cJSON* jsonv1beta1_cluster_trust_bundle_2 = v1beta1_cluster_trust_bundle_convertToJSON(v1beta1_cluster_trust_bundle_2);
	printf("repeating v1beta1_cluster_trust_bundle:\n%s\n", cJSON_Print(jsonv1beta1_cluster_trust_bundle_2));
}

int main() {
  test_v1beta1_cluster_trust_bundle(1);
  test_v1beta1_cluster_trust_bundle(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_cluster_trust_bundle_MAIN
#endif // v1beta1_cluster_trust_bundle_TEST
