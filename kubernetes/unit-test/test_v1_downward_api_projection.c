#ifndef v1_downward_api_projection_TEST
#define v1_downward_api_projection_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_downward_api_projection_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_downward_api_projection.h"
v1_downward_api_projection_t* instantiate_v1_downward_api_projection(int include_optional);



v1_downward_api_projection_t* instantiate_v1_downward_api_projection(int include_optional) {
  v1_downward_api_projection_t* v1_downward_api_projection = NULL;
  if (include_optional) {
    v1_downward_api_projection = v1_downward_api_projection_create(
      list_create()
    );
  } else {
    v1_downward_api_projection = v1_downward_api_projection_create(
      list_create()
    );
  }

  return v1_downward_api_projection;
}


#ifdef v1_downward_api_projection_MAIN

void test_v1_downward_api_projection(int include_optional) {
    v1_downward_api_projection_t* v1_downward_api_projection_1 = instantiate_v1_downward_api_projection(include_optional);

	cJSON* jsonv1_downward_api_projection_1 = v1_downward_api_projection_convertToJSON(v1_downward_api_projection_1);
	printf("v1_downward_api_projection :\n%s\n", cJSON_Print(jsonv1_downward_api_projection_1));
	v1_downward_api_projection_t* v1_downward_api_projection_2 = v1_downward_api_projection_parseFromJSON(jsonv1_downward_api_projection_1);
	cJSON* jsonv1_downward_api_projection_2 = v1_downward_api_projection_convertToJSON(v1_downward_api_projection_2);
	printf("repeating v1_downward_api_projection:\n%s\n", cJSON_Print(jsonv1_downward_api_projection_2));
}

int main() {
  test_v1_downward_api_projection(1);
  test_v1_downward_api_projection(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_downward_api_projection_MAIN
#endif // v1_downward_api_projection_TEST
