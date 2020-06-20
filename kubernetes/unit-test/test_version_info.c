#ifndef version_info_TEST
#define version_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define version_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/version_info.h"
version_info_t* instantiate_version_info(int include_optional);



version_info_t* instantiate_version_info(int include_optional) {
  version_info_t* version_info = NULL;
  if (include_optional) {
    version_info = version_info_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    version_info = version_info_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return version_info;
}


#ifdef version_info_MAIN

void test_version_info(int include_optional) {
    version_info_t* version_info_1 = instantiate_version_info(include_optional);

	cJSON* jsonversion_info_1 = version_info_convertToJSON(version_info_1);
	printf("version_info :\n%s\n", cJSON_Print(jsonversion_info_1));
	version_info_t* version_info_2 = version_info_parseFromJSON(jsonversion_info_1);
	cJSON* jsonversion_info_2 = version_info_convertToJSON(version_info_2);
	printf("repeating version_info:\n%s\n", cJSON_Print(jsonversion_info_2));
}

int main() {
  test_version_info(1);
  test_version_info(0);

  printf("Hello world \n");
  return 0;
}

#endif // version_info_MAIN
#endif // version_info_TEST
