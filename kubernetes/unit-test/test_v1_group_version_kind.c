#ifndef v1_group_version_kind_TEST
#define v1_group_version_kind_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_group_version_kind_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_group_version_kind.h"
v1_group_version_kind_t* instantiate_v1_group_version_kind(int include_optional);



v1_group_version_kind_t* instantiate_v1_group_version_kind(int include_optional) {
  v1_group_version_kind_t* v1_group_version_kind = NULL;
  if (include_optional) {
    v1_group_version_kind = v1_group_version_kind_create(
      "0",
      "0",
      "0"
    );
  } else {
    v1_group_version_kind = v1_group_version_kind_create(
      "0",
      "0",
      "0"
    );
  }

  return v1_group_version_kind;
}


#ifdef v1_group_version_kind_MAIN

void test_v1_group_version_kind(int include_optional) {
    v1_group_version_kind_t* v1_group_version_kind_1 = instantiate_v1_group_version_kind(include_optional);

	cJSON* jsonv1_group_version_kind_1 = v1_group_version_kind_convertToJSON(v1_group_version_kind_1);
	printf("v1_group_version_kind :\n%s\n", cJSON_Print(jsonv1_group_version_kind_1));
	v1_group_version_kind_t* v1_group_version_kind_2 = v1_group_version_kind_parseFromJSON(jsonv1_group_version_kind_1);
	cJSON* jsonv1_group_version_kind_2 = v1_group_version_kind_convertToJSON(v1_group_version_kind_2);
	printf("repeating v1_group_version_kind:\n%s\n", cJSON_Print(jsonv1_group_version_kind_2));
}

int main() {
  test_v1_group_version_kind(1);
  test_v1_group_version_kind(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_group_version_kind_MAIN
#endif // v1_group_version_kind_TEST
