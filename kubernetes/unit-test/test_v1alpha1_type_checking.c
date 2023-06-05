#ifndef v1alpha1_type_checking_TEST
#define v1alpha1_type_checking_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1alpha1_type_checking_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1alpha1_type_checking.h"
v1alpha1_type_checking_t* instantiate_v1alpha1_type_checking(int include_optional);



v1alpha1_type_checking_t* instantiate_v1alpha1_type_checking(int include_optional) {
  v1alpha1_type_checking_t* v1alpha1_type_checking = NULL;
  if (include_optional) {
    v1alpha1_type_checking = v1alpha1_type_checking_create(
      list_createList()
    );
  } else {
    v1alpha1_type_checking = v1alpha1_type_checking_create(
      list_createList()
    );
  }

  return v1alpha1_type_checking;
}


#ifdef v1alpha1_type_checking_MAIN

void test_v1alpha1_type_checking(int include_optional) {
    v1alpha1_type_checking_t* v1alpha1_type_checking_1 = instantiate_v1alpha1_type_checking(include_optional);

	cJSON* jsonv1alpha1_type_checking_1 = v1alpha1_type_checking_convertToJSON(v1alpha1_type_checking_1);
	printf("v1alpha1_type_checking :\n%s\n", cJSON_Print(jsonv1alpha1_type_checking_1));
	v1alpha1_type_checking_t* v1alpha1_type_checking_2 = v1alpha1_type_checking_parseFromJSON(jsonv1alpha1_type_checking_1);
	cJSON* jsonv1alpha1_type_checking_2 = v1alpha1_type_checking_convertToJSON(v1alpha1_type_checking_2);
	printf("repeating v1alpha1_type_checking:\n%s\n", cJSON_Print(jsonv1alpha1_type_checking_2));
}

int main() {
  test_v1alpha1_type_checking(1);
  test_v1alpha1_type_checking(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1alpha1_type_checking_MAIN
#endif // v1alpha1_type_checking_TEST
