#ifndef v1_ingress_backend_TEST
#define v1_ingress_backend_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_ingress_backend_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_ingress_backend.h"
v1_ingress_backend_t* instantiate_v1_ingress_backend(int include_optional);

#include "test_v1_typed_local_object_reference.c"
#include "test_v1_ingress_service_backend.c"


v1_ingress_backend_t* instantiate_v1_ingress_backend(int include_optional) {
  v1_ingress_backend_t* v1_ingress_backend = NULL;
  if (include_optional) {
    v1_ingress_backend = v1_ingress_backend_create(
       // false, not to have infinite recursion
      instantiate_v1_typed_local_object_reference(0),
       // false, not to have infinite recursion
      instantiate_v1_ingress_service_backend(0)
    );
  } else {
    v1_ingress_backend = v1_ingress_backend_create(
      NULL,
      NULL
    );
  }

  return v1_ingress_backend;
}


#ifdef v1_ingress_backend_MAIN

void test_v1_ingress_backend(int include_optional) {
    v1_ingress_backend_t* v1_ingress_backend_1 = instantiate_v1_ingress_backend(include_optional);

	cJSON* jsonv1_ingress_backend_1 = v1_ingress_backend_convertToJSON(v1_ingress_backend_1);
	printf("v1_ingress_backend :\n%s\n", cJSON_Print(jsonv1_ingress_backend_1));
	v1_ingress_backend_t* v1_ingress_backend_2 = v1_ingress_backend_parseFromJSON(jsonv1_ingress_backend_1);
	cJSON* jsonv1_ingress_backend_2 = v1_ingress_backend_convertToJSON(v1_ingress_backend_2);
	printf("repeating v1_ingress_backend:\n%s\n", cJSON_Print(jsonv1_ingress_backend_2));
}

int main() {
  test_v1_ingress_backend(1);
  test_v1_ingress_backend(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_ingress_backend_MAIN
#endif // v1_ingress_backend_TEST
