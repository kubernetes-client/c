#ifndef v1_cluster_trust_bundle_projection_TEST
#define v1_cluster_trust_bundle_projection_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_cluster_trust_bundle_projection_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_cluster_trust_bundle_projection.h"
v1_cluster_trust_bundle_projection_t* instantiate_v1_cluster_trust_bundle_projection(int include_optional);

#include "test_v1_label_selector.c"


v1_cluster_trust_bundle_projection_t* instantiate_v1_cluster_trust_bundle_projection(int include_optional) {
  v1_cluster_trust_bundle_projection_t* v1_cluster_trust_bundle_projection = NULL;
  if (include_optional) {
    v1_cluster_trust_bundle_projection = v1_cluster_trust_bundle_projection_create(
       // false, not to have infinite recursion
      instantiate_v1_label_selector(0),
      "0",
      1,
      "0",
      "0"
    );
  } else {
    v1_cluster_trust_bundle_projection = v1_cluster_trust_bundle_projection_create(
      NULL,
      "0",
      1,
      "0",
      "0"
    );
  }

  return v1_cluster_trust_bundle_projection;
}


#ifdef v1_cluster_trust_bundle_projection_MAIN

void test_v1_cluster_trust_bundle_projection(int include_optional) {
    v1_cluster_trust_bundle_projection_t* v1_cluster_trust_bundle_projection_1 = instantiate_v1_cluster_trust_bundle_projection(include_optional);

	cJSON* jsonv1_cluster_trust_bundle_projection_1 = v1_cluster_trust_bundle_projection_convertToJSON(v1_cluster_trust_bundle_projection_1);
	printf("v1_cluster_trust_bundle_projection :\n%s\n", cJSON_Print(jsonv1_cluster_trust_bundle_projection_1));
	v1_cluster_trust_bundle_projection_t* v1_cluster_trust_bundle_projection_2 = v1_cluster_trust_bundle_projection_parseFromJSON(jsonv1_cluster_trust_bundle_projection_1);
	cJSON* jsonv1_cluster_trust_bundle_projection_2 = v1_cluster_trust_bundle_projection_convertToJSON(v1_cluster_trust_bundle_projection_2);
	printf("repeating v1_cluster_trust_bundle_projection:\n%s\n", cJSON_Print(jsonv1_cluster_trust_bundle_projection_2));
}

int main() {
  test_v1_cluster_trust_bundle_projection(1);
  test_v1_cluster_trust_bundle_projection(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_cluster_trust_bundle_projection_MAIN
#endif // v1_cluster_trust_bundle_projection_TEST
