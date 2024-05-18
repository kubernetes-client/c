#ifndef v1alpha1_storage_version_migration_TEST
#define v1alpha1_storage_version_migration_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha1_storage_version_migration_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha1_storage_version_migration.h"
v1alpha1_storage_version_migration_t* instantiate_v1alpha1_storage_version_migration(int include_optional);

#include "test_v1_object_meta.c"
#include "test_v1alpha1_storage_version_migration_spec.c"
#include "test_v1alpha1_storage_version_migration_status.c"


v1alpha1_storage_version_migration_t* instantiate_v1alpha1_storage_version_migration(int include_optional) {
  v1alpha1_storage_version_migration_t* v1alpha1_storage_version_migration = NULL;
  if (include_optional) {
    v1alpha1_storage_version_migration = v1alpha1_storage_version_migration_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_v1_object_meta(0),
       // false, not to have infinite recursion
      instantiate_v1alpha1_storage_version_migration_spec(0),
       // false, not to have infinite recursion
      instantiate_v1alpha1_storage_version_migration_status(0)
    );
  } else {
    v1alpha1_storage_version_migration = v1alpha1_storage_version_migration_create(
      "0",
      "0",
      NULL,
      NULL,
      NULL
    );
  }

  return v1alpha1_storage_version_migration;
}


#ifdef v1alpha1_storage_version_migration_MAIN

void test_v1alpha1_storage_version_migration(int include_optional) {
    v1alpha1_storage_version_migration_t* v1alpha1_storage_version_migration_1 = instantiate_v1alpha1_storage_version_migration(include_optional);

	cJSON* jsonv1alpha1_storage_version_migration_1 = v1alpha1_storage_version_migration_convertToJSON(v1alpha1_storage_version_migration_1);
	printf("v1alpha1_storage_version_migration :\n%s\n", cJSON_Print(jsonv1alpha1_storage_version_migration_1));
	v1alpha1_storage_version_migration_t* v1alpha1_storage_version_migration_2 = v1alpha1_storage_version_migration_parseFromJSON(jsonv1alpha1_storage_version_migration_1);
	cJSON* jsonv1alpha1_storage_version_migration_2 = v1alpha1_storage_version_migration_convertToJSON(v1alpha1_storage_version_migration_2);
	printf("repeating v1alpha1_storage_version_migration:\n%s\n", cJSON_Print(jsonv1alpha1_storage_version_migration_2));
}

int main() {
  test_v1alpha1_storage_version_migration(1);
  test_v1alpha1_storage_version_migration(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha1_storage_version_migration_MAIN
#endif // v1alpha1_storage_version_migration_TEST
