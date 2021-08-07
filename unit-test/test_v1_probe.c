#ifndef v1_probe_TEST
#define v1_probe_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_probe_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_probe.h"
v1_probe_t* instantiate_v1_probe(int include_optional);

#include "test_v1_exec_action.c"
#include "test_v1_http_get_action.c"
#include "test_v1_tcp_socket_action.c"


v1_probe_t* instantiate_v1_probe(int include_optional) {
  v1_probe_t* v1_probe = NULL;
  if (include_optional) {
    v1_probe = v1_probe_create(
       // false, not to have infinite recursion
      instantiate_v1_exec_action(0),
      56,
       // false, not to have infinite recursion
      instantiate_v1_http_get_action(0),
      56,
      56,
      56,
       // false, not to have infinite recursion
      instantiate_v1_tcp_socket_action(0),
      56
    );
  } else {
    v1_probe = v1_probe_create(
      NULL,
      56,
      NULL,
      56,
      56,
      56,
      NULL,
      56
    );
  }

  return v1_probe;
}


#ifdef v1_probe_MAIN

void test_v1_probe(int include_optional) {
    v1_probe_t* v1_probe_1 = instantiate_v1_probe(include_optional);

	cJSON* jsonv1_probe_1 = v1_probe_convertToJSON(v1_probe_1);
	printf("v1_probe :\n%s\n", cJSON_Print(jsonv1_probe_1));
	v1_probe_t* v1_probe_2 = v1_probe_parseFromJSON(jsonv1_probe_1);
	cJSON* jsonv1_probe_2 = v1_probe_convertToJSON(v1_probe_2);
	printf("repeating v1_probe:\n%s\n", cJSON_Print(jsonv1_probe_2));
}

int main() {
  test_v1_probe(1);
  test_v1_probe(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_probe_MAIN
#endif // v1_probe_TEST
