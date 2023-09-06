#ifndef v1alpha1_server_storage_version_TEST
#define v1alpha1_server_storage_version_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha1_server_storage_version_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha1_server_storage_version.h"
v1alpha1_server_storage_version_t* instantiate_v1alpha1_server_storage_version(int include_optional);



v1alpha1_server_storage_version_t* instantiate_v1alpha1_server_storage_version(int include_optional) {
  v1alpha1_server_storage_version_t* v1alpha1_server_storage_version = NULL;
  if (include_optional) {
    v1alpha1_server_storage_version = v1alpha1_server_storage_version_create(
      "0",
      list_createList(),
      "0",
      list_createList()
    );
  } else {
    v1alpha1_server_storage_version = v1alpha1_server_storage_version_create(
      "0",
      list_createList(),
      "0",
      list_createList()
    );
  }

  return v1alpha1_server_storage_version;
}


#ifdef v1alpha1_server_storage_version_MAIN

void test_v1alpha1_server_storage_version(int include_optional) {
    v1alpha1_server_storage_version_t* v1alpha1_server_storage_version_1 = instantiate_v1alpha1_server_storage_version(include_optional);

	cJSON* jsonv1alpha1_server_storage_version_1 = v1alpha1_server_storage_version_convertToJSON(v1alpha1_server_storage_version_1);
	printf("v1alpha1_server_storage_version :\n%s\n", cJSON_Print(jsonv1alpha1_server_storage_version_1));
	v1alpha1_server_storage_version_t* v1alpha1_server_storage_version_2 = v1alpha1_server_storage_version_parseFromJSON(jsonv1alpha1_server_storage_version_1);
	cJSON* jsonv1alpha1_server_storage_version_2 = v1alpha1_server_storage_version_convertToJSON(v1alpha1_server_storage_version_2);
	printf("repeating v1alpha1_server_storage_version:\n%s\n", cJSON_Print(jsonv1alpha1_server_storage_version_2));
}

int main() {
  test_v1alpha1_server_storage_version(1);
  test_v1alpha1_server_storage_version(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha1_server_storage_version_MAIN
#endif // v1alpha1_server_storage_version_TEST
