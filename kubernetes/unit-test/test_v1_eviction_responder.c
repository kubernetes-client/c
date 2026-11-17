#ifndef v1_eviction_responder_TEST
#define v1_eviction_responder_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_eviction_responder_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_eviction_responder.h"
v1_eviction_responder_t* instantiate_v1_eviction_responder(int include_optional);



v1_eviction_responder_t* instantiate_v1_eviction_responder(int include_optional) {
  v1_eviction_responder_t* v1_eviction_responder = NULL;
  if (include_optional) {
    v1_eviction_responder = v1_eviction_responder_create(
      "0",
      56
    );
  } else {
    v1_eviction_responder = v1_eviction_responder_create(
      "0",
      56
    );
  }

  return v1_eviction_responder;
}


#ifdef v1_eviction_responder_MAIN

void test_v1_eviction_responder(int include_optional) {
    v1_eviction_responder_t* v1_eviction_responder_1 = instantiate_v1_eviction_responder(include_optional);

	cJSON* jsonv1_eviction_responder_1 = v1_eviction_responder_convertToJSON(v1_eviction_responder_1);
	printf("v1_eviction_responder :\n%s\n", cJSON_Print(jsonv1_eviction_responder_1));
	v1_eviction_responder_t* v1_eviction_responder_2 = v1_eviction_responder_parseFromJSON(jsonv1_eviction_responder_1);
	cJSON* jsonv1_eviction_responder_2 = v1_eviction_responder_convertToJSON(v1_eviction_responder_2);
	printf("repeating v1_eviction_responder:\n%s\n", cJSON_Print(jsonv1_eviction_responder_2));
}

int main() {
  test_v1_eviction_responder(1);
  test_v1_eviction_responder(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_eviction_responder_MAIN
#endif // v1_eviction_responder_TEST
