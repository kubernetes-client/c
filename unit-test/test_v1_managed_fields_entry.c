#ifndef v1_managed_fields_entry_TEST
#define v1_managed_fields_entry_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_managed_fields_entry_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_managed_fields_entry.h"
v1_managed_fields_entry_t* instantiate_v1_managed_fields_entry(int include_optional);



v1_managed_fields_entry_t* instantiate_v1_managed_fields_entry(int include_optional) {
  v1_managed_fields_entry_t* v1_managed_fields_entry = NULL;
  if (include_optional) {
    v1_managed_fields_entry = v1_managed_fields_entry_create(
      "0",
      "0",
      0,
      "0",
      "0",
      "2013-10-20T19:20:30+01:00"
    );
  } else {
    v1_managed_fields_entry = v1_managed_fields_entry_create(
      "0",
      "0",
      0,
      "0",
      "0",
      "2013-10-20T19:20:30+01:00"
    );
  }

  return v1_managed_fields_entry;
}


#ifdef v1_managed_fields_entry_MAIN

void test_v1_managed_fields_entry(int include_optional) {
    v1_managed_fields_entry_t* v1_managed_fields_entry_1 = instantiate_v1_managed_fields_entry(include_optional);

	cJSON* jsonv1_managed_fields_entry_1 = v1_managed_fields_entry_convertToJSON(v1_managed_fields_entry_1);
	printf("v1_managed_fields_entry :\n%s\n", cJSON_Print(jsonv1_managed_fields_entry_1));
	v1_managed_fields_entry_t* v1_managed_fields_entry_2 = v1_managed_fields_entry_parseFromJSON(jsonv1_managed_fields_entry_1);
	cJSON* jsonv1_managed_fields_entry_2 = v1_managed_fields_entry_convertToJSON(v1_managed_fields_entry_2);
	printf("repeating v1_managed_fields_entry:\n%s\n", cJSON_Print(jsonv1_managed_fields_entry_2));
}

int main() {
  test_v1_managed_fields_entry(1);
  test_v1_managed_fields_entry(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_managed_fields_entry_MAIN
#endif // v1_managed_fields_entry_TEST
