#ifndef v1_linux_container_user_TEST
#define v1_linux_container_user_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_linux_container_user_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_linux_container_user.h"
v1_linux_container_user_t* instantiate_v1_linux_container_user(int include_optional);



v1_linux_container_user_t* instantiate_v1_linux_container_user(int include_optional) {
  v1_linux_container_user_t* v1_linux_container_user = NULL;
  if (include_optional) {
    v1_linux_container_user = v1_linux_container_user_create(
      56,
      list_createList(),
      56
    );
  } else {
    v1_linux_container_user = v1_linux_container_user_create(
      56,
      list_createList(),
      56
    );
  }

  return v1_linux_container_user;
}


#ifdef v1_linux_container_user_MAIN

void test_v1_linux_container_user(int include_optional) {
    v1_linux_container_user_t* v1_linux_container_user_1 = instantiate_v1_linux_container_user(include_optional);

	cJSON* jsonv1_linux_container_user_1 = v1_linux_container_user_convertToJSON(v1_linux_container_user_1);
	printf("v1_linux_container_user :\n%s\n", cJSON_Print(jsonv1_linux_container_user_1));
	v1_linux_container_user_t* v1_linux_container_user_2 = v1_linux_container_user_parseFromJSON(jsonv1_linux_container_user_1);
	cJSON* jsonv1_linux_container_user_2 = v1_linux_container_user_convertToJSON(v1_linux_container_user_2);
	printf("repeating v1_linux_container_user:\n%s\n", cJSON_Print(jsonv1_linux_container_user_2));
}

int main() {
  test_v1_linux_container_user(1);
  test_v1_linux_container_user(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_linux_container_user_MAIN
#endif // v1_linux_container_user_TEST
