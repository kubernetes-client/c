#ifndef v1_volume_mount_TEST
#define v1_volume_mount_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_volume_mount_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_volume_mount.h"
v1_volume_mount_t* instantiate_v1_volume_mount(int include_optional);



v1_volume_mount_t* instantiate_v1_volume_mount(int include_optional) {
  v1_volume_mount_t* v1_volume_mount = NULL;
  if (include_optional) {
    v1_volume_mount = v1_volume_mount_create(
      "0",
      "0",
      "0",
      1,
      "0",
      "0"
    );
  } else {
    v1_volume_mount = v1_volume_mount_create(
      "0",
      "0",
      "0",
      1,
      "0",
      "0"
    );
  }

  return v1_volume_mount;
}


#ifdef v1_volume_mount_MAIN

void test_v1_volume_mount(int include_optional) {
    v1_volume_mount_t* v1_volume_mount_1 = instantiate_v1_volume_mount(include_optional);

	cJSON* jsonv1_volume_mount_1 = v1_volume_mount_convertToJSON(v1_volume_mount_1);
	printf("v1_volume_mount :\n%s\n", cJSON_Print(jsonv1_volume_mount_1));
	v1_volume_mount_t* v1_volume_mount_2 = v1_volume_mount_parseFromJSON(jsonv1_volume_mount_1);
	cJSON* jsonv1_volume_mount_2 = v1_volume_mount_convertToJSON(v1_volume_mount_2);
	printf("repeating v1_volume_mount:\n%s\n", cJSON_Print(jsonv1_volume_mount_2));
}

int main() {
  test_v1_volume_mount(1);
  test_v1_volume_mount(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_volume_mount_MAIN
#endif // v1_volume_mount_TEST
