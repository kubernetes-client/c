#ifndef v1_node_features_TEST
#define v1_node_features_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_node_features_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_node_features.h"
v1_node_features_t* instantiate_v1_node_features(int include_optional);



v1_node_features_t* instantiate_v1_node_features(int include_optional) {
  v1_node_features_t* v1_node_features = NULL;
  if (include_optional) {
    v1_node_features = v1_node_features_create(
      1
    );
  } else {
    v1_node_features = v1_node_features_create(
      1
    );
  }

  return v1_node_features;
}


#ifdef v1_node_features_MAIN

void test_v1_node_features(int include_optional) {
    v1_node_features_t* v1_node_features_1 = instantiate_v1_node_features(include_optional);

	cJSON* jsonv1_node_features_1 = v1_node_features_convertToJSON(v1_node_features_1);
	printf("v1_node_features :\n%s\n", cJSON_Print(jsonv1_node_features_1));
	v1_node_features_t* v1_node_features_2 = v1_node_features_parseFromJSON(jsonv1_node_features_1);
	cJSON* jsonv1_node_features_2 = v1_node_features_convertToJSON(v1_node_features_2);
	printf("repeating v1_node_features:\n%s\n", cJSON_Print(jsonv1_node_features_2));
}

int main() {
  test_v1_node_features(1);
  test_v1_node_features(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_node_features_MAIN
#endif // v1_node_features_TEST
