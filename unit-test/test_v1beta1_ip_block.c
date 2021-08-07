#ifndef v1beta1_ip_block_TEST
#define v1beta1_ip_block_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1beta1_ip_block_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1beta1_ip_block.h"
v1beta1_ip_block_t* instantiate_v1beta1_ip_block(int include_optional);



v1beta1_ip_block_t* instantiate_v1beta1_ip_block(int include_optional) {
  v1beta1_ip_block_t* v1beta1_ip_block = NULL;
  if (include_optional) {
    v1beta1_ip_block = v1beta1_ip_block_create(
      "0",
      list_create()
    );
  } else {
    v1beta1_ip_block = v1beta1_ip_block_create(
      "0",
      list_create()
    );
  }

  return v1beta1_ip_block;
}


#ifdef v1beta1_ip_block_MAIN

void test_v1beta1_ip_block(int include_optional) {
    v1beta1_ip_block_t* v1beta1_ip_block_1 = instantiate_v1beta1_ip_block(include_optional);

	cJSON* jsonv1beta1_ip_block_1 = v1beta1_ip_block_convertToJSON(v1beta1_ip_block_1);
	printf("v1beta1_ip_block :\n%s\n", cJSON_Print(jsonv1beta1_ip_block_1));
	v1beta1_ip_block_t* v1beta1_ip_block_2 = v1beta1_ip_block_parseFromJSON(jsonv1beta1_ip_block_1);
	cJSON* jsonv1beta1_ip_block_2 = v1beta1_ip_block_convertToJSON(v1beta1_ip_block_2);
	printf("repeating v1beta1_ip_block:\n%s\n", cJSON_Print(jsonv1beta1_ip_block_2));
}

int main() {
  test_v1beta1_ip_block(1);
  test_v1beta1_ip_block(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1beta1_ip_block_MAIN
#endif // v1beta1_ip_block_TEST
