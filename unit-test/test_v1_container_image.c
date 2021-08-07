#ifndef v1_container_image_TEST
#define v1_container_image_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_container_image_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_container_image.h"
v1_container_image_t* instantiate_v1_container_image(int include_optional);



v1_container_image_t* instantiate_v1_container_image(int include_optional) {
  v1_container_image_t* v1_container_image = NULL;
  if (include_optional) {
    v1_container_image = v1_container_image_create(
      list_create(),
      56
    );
  } else {
    v1_container_image = v1_container_image_create(
      list_create(),
      56
    );
  }

  return v1_container_image;
}


#ifdef v1_container_image_MAIN

void test_v1_container_image(int include_optional) {
    v1_container_image_t* v1_container_image_1 = instantiate_v1_container_image(include_optional);

	cJSON* jsonv1_container_image_1 = v1_container_image_convertToJSON(v1_container_image_1);
	printf("v1_container_image :\n%s\n", cJSON_Print(jsonv1_container_image_1));
	v1_container_image_t* v1_container_image_2 = v1_container_image_parseFromJSON(jsonv1_container_image_1);
	cJSON* jsonv1_container_image_2 = v1_container_image_convertToJSON(v1_container_image_2);
	printf("repeating v1_container_image:\n%s\n", cJSON_Print(jsonv1_container_image_2));
}

int main() {
  test_v1_container_image(1);
  test_v1_container_image(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_container_image_MAIN
#endif // v1_container_image_TEST
