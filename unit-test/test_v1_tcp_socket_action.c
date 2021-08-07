#ifndef v1_tcp_socket_action_TEST
#define v1_tcp_socket_action_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_tcp_socket_action_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_tcp_socket_action.h"
v1_tcp_socket_action_t* instantiate_v1_tcp_socket_action(int include_optional);



v1_tcp_socket_action_t* instantiate_v1_tcp_socket_action(int include_optional) {
  v1_tcp_socket_action_t* v1_tcp_socket_action = NULL;
  if (include_optional) {
    v1_tcp_socket_action = v1_tcp_socket_action_create(
      "0",
      0
    );
  } else {
    v1_tcp_socket_action = v1_tcp_socket_action_create(
      "0",
      0
    );
  }

  return v1_tcp_socket_action;
}


#ifdef v1_tcp_socket_action_MAIN

void test_v1_tcp_socket_action(int include_optional) {
    v1_tcp_socket_action_t* v1_tcp_socket_action_1 = instantiate_v1_tcp_socket_action(include_optional);

	cJSON* jsonv1_tcp_socket_action_1 = v1_tcp_socket_action_convertToJSON(v1_tcp_socket_action_1);
	printf("v1_tcp_socket_action :\n%s\n", cJSON_Print(jsonv1_tcp_socket_action_1));
	v1_tcp_socket_action_t* v1_tcp_socket_action_2 = v1_tcp_socket_action_parseFromJSON(jsonv1_tcp_socket_action_1);
	cJSON* jsonv1_tcp_socket_action_2 = v1_tcp_socket_action_convertToJSON(v1_tcp_socket_action_2);
	printf("repeating v1_tcp_socket_action:\n%s\n", cJSON_Print(jsonv1_tcp_socket_action_2));
}

int main() {
  test_v1_tcp_socket_action(1);
  test_v1_tcp_socket_action(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_tcp_socket_action_MAIN
#endif // v1_tcp_socket_action_TEST
