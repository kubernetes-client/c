#ifndef v1_shard_info_TEST
#define v1_shard_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_shard_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_shard_info.h"
v1_shard_info_t* instantiate_v1_shard_info(int include_optional);



v1_shard_info_t* instantiate_v1_shard_info(int include_optional) {
  v1_shard_info_t* v1_shard_info = NULL;
  if (include_optional) {
    v1_shard_info = v1_shard_info_create(
      "0"
    );
  } else {
    v1_shard_info = v1_shard_info_create(
      "0"
    );
  }

  return v1_shard_info;
}


#ifdef v1_shard_info_MAIN

void test_v1_shard_info(int include_optional) {
    v1_shard_info_t* v1_shard_info_1 = instantiate_v1_shard_info(include_optional);

	cJSON* jsonv1_shard_info_1 = v1_shard_info_convertToJSON(v1_shard_info_1);
	printf("v1_shard_info :\n%s\n", cJSON_Print(jsonv1_shard_info_1));
	v1_shard_info_t* v1_shard_info_2 = v1_shard_info_parseFromJSON(jsonv1_shard_info_1);
	cJSON* jsonv1_shard_info_2 = v1_shard_info_convertToJSON(v1_shard_info_2);
	printf("repeating v1_shard_info:\n%s\n", cJSON_Print(jsonv1_shard_info_2));
}

int main() {
  test_v1_shard_info(1);
  test_v1_shard_info(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_shard_info_MAIN
#endif // v1_shard_info_TEST
