#ifndef v1_volume_mount_status_TEST
#define v1_volume_mount_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_volume_mount_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_volume_mount_status.h"
v1_volume_mount_status_t* instantiate_v1_volume_mount_status(int include_optional);



v1_volume_mount_status_t* instantiate_v1_volume_mount_status(int include_optional) {
  v1_volume_mount_status_t* v1_volume_mount_status = NULL;
  if (include_optional) {
    v1_volume_mount_status = v1_volume_mount_status_create(
      "0",
      "0",
      1,
      "0"
    );
  } else {
    v1_volume_mount_status = v1_volume_mount_status_create(
      "0",
      "0",
      1,
      "0"
    );
  }

  return v1_volume_mount_status;
}


#ifdef v1_volume_mount_status_MAIN

void test_v1_volume_mount_status(int include_optional) {
    v1_volume_mount_status_t* v1_volume_mount_status_1 = instantiate_v1_volume_mount_status(include_optional);

	cJSON* jsonv1_volume_mount_status_1 = v1_volume_mount_status_convertToJSON(v1_volume_mount_status_1);
	printf("v1_volume_mount_status :\n%s\n", cJSON_Print(jsonv1_volume_mount_status_1));
	v1_volume_mount_status_t* v1_volume_mount_status_2 = v1_volume_mount_status_parseFromJSON(jsonv1_volume_mount_status_1);
	cJSON* jsonv1_volume_mount_status_2 = v1_volume_mount_status_convertToJSON(v1_volume_mount_status_2);
	printf("repeating v1_volume_mount_status:\n%s\n", cJSON_Print(jsonv1_volume_mount_status_2));
}

int main() {
  test_v1_volume_mount_status(1);
  test_v1_volume_mount_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_volume_mount_status_MAIN
#endif // v1_volume_mount_status_TEST
