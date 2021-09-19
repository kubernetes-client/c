#ifndef v1_seccomp_profile_TEST
#define v1_seccomp_profile_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_seccomp_profile_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_seccomp_profile.h"
v1_seccomp_profile_t* instantiate_v1_seccomp_profile(int include_optional);



v1_seccomp_profile_t* instantiate_v1_seccomp_profile(int include_optional) {
  v1_seccomp_profile_t* v1_seccomp_profile = NULL;
  if (include_optional) {
    v1_seccomp_profile = v1_seccomp_profile_create(
      "0",
      "0"
    );
  } else {
    v1_seccomp_profile = v1_seccomp_profile_create(
      "0",
      "0"
    );
  }

  return v1_seccomp_profile;
}


#ifdef v1_seccomp_profile_MAIN

void test_v1_seccomp_profile(int include_optional) {
    v1_seccomp_profile_t* v1_seccomp_profile_1 = instantiate_v1_seccomp_profile(include_optional);

	cJSON* jsonv1_seccomp_profile_1 = v1_seccomp_profile_convertToJSON(v1_seccomp_profile_1);
	printf("v1_seccomp_profile :\n%s\n", cJSON_Print(jsonv1_seccomp_profile_1));
	v1_seccomp_profile_t* v1_seccomp_profile_2 = v1_seccomp_profile_parseFromJSON(jsonv1_seccomp_profile_1);
	cJSON* jsonv1_seccomp_profile_2 = v1_seccomp_profile_convertToJSON(v1_seccomp_profile_2);
	printf("repeating v1_seccomp_profile:\n%s\n", cJSON_Print(jsonv1_seccomp_profile_2));
}

int main() {
  test_v1_seccomp_profile(1);
  test_v1_seccomp_profile(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_seccomp_profile_MAIN
#endif // v1_seccomp_profile_TEST
