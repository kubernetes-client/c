#ifndef v1beta1_id_range_TEST
#define v1beta1_id_range_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_id_range_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_id_range.h"
v1beta1_id_range_t* instantiate_v1beta1_id_range(int include_optional);



v1beta1_id_range_t* instantiate_v1beta1_id_range(int include_optional) {
  v1beta1_id_range_t* v1beta1_id_range = NULL;
  if (include_optional) {
    v1beta1_id_range = v1beta1_id_range_create(
      56,
      56
    );
  } else {
    v1beta1_id_range = v1beta1_id_range_create(
      56,
      56
    );
  }

  return v1beta1_id_range;
}


#ifdef v1beta1_id_range_MAIN

void test_v1beta1_id_range(int include_optional) {
    v1beta1_id_range_t* v1beta1_id_range_1 = instantiate_v1beta1_id_range(include_optional);

	cJSON* jsonv1beta1_id_range_1 = v1beta1_id_range_convertToJSON(v1beta1_id_range_1);
	printf("v1beta1_id_range :\n%s\n", cJSON_Print(jsonv1beta1_id_range_1));
	v1beta1_id_range_t* v1beta1_id_range_2 = v1beta1_id_range_parseFromJSON(jsonv1beta1_id_range_1);
	cJSON* jsonv1beta1_id_range_2 = v1beta1_id_range_convertToJSON(v1beta1_id_range_2);
	printf("repeating v1beta1_id_range:\n%s\n", cJSON_Print(jsonv1beta1_id_range_2));
}

int main() {
  test_v1beta1_id_range(1);
  test_v1beta1_id_range(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_id_range_MAIN
#endif // v1beta1_id_range_TEST
