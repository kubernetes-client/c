#ifndef v1_volume_projection_TEST
#define v1_volume_projection_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_volume_projection_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_volume_projection.h"
v1_volume_projection_t* instantiate_v1_volume_projection(int include_optional);

#include "test_v1_config_map_projection.c"
#include "test_v1_downward_api_projection.c"
#include "test_v1_secret_projection.c"
#include "test_v1_service_account_token_projection.c"


v1_volume_projection_t* instantiate_v1_volume_projection(int include_optional) {
  v1_volume_projection_t* v1_volume_projection = NULL;
  if (include_optional) {
    v1_volume_projection = v1_volume_projection_create(
       // false, not to have infinite recursion
      instantiate_v1_config_map_projection(0),
       // false, not to have infinite recursion
      instantiate_v1_downward_api_projection(0),
       // false, not to have infinite recursion
      instantiate_v1_secret_projection(0),
       // false, not to have infinite recursion
      instantiate_v1_service_account_token_projection(0)
    );
  } else {
    v1_volume_projection = v1_volume_projection_create(
      NULL,
      NULL,
      NULL,
      NULL
    );
  }

  return v1_volume_projection;
}


#ifdef v1_volume_projection_MAIN

void test_v1_volume_projection(int include_optional) {
    v1_volume_projection_t* v1_volume_projection_1 = instantiate_v1_volume_projection(include_optional);

	cJSON* jsonv1_volume_projection_1 = v1_volume_projection_convertToJSON(v1_volume_projection_1);
	printf("v1_volume_projection :\n%s\n", cJSON_Print(jsonv1_volume_projection_1));
	v1_volume_projection_t* v1_volume_projection_2 = v1_volume_projection_parseFromJSON(jsonv1_volume_projection_1);
	cJSON* jsonv1_volume_projection_2 = v1_volume_projection_convertToJSON(v1_volume_projection_2);
	printf("repeating v1_volume_projection:\n%s\n", cJSON_Print(jsonv1_volume_projection_2));
}

int main() {
  test_v1_volume_projection(1);
  test_v1_volume_projection(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_volume_projection_MAIN
#endif // v1_volume_projection_TEST
