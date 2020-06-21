#ifndef v1_http_header_TEST
#define v1_http_header_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define v1_http_header_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/v1_http_header.h"
v1_http_header_t* instantiate_v1_http_header(int include_optional);



v1_http_header_t* instantiate_v1_http_header(int include_optional) {
  v1_http_header_t* v1_http_header = NULL;
  if (include_optional) {
    v1_http_header = v1_http_header_create(
      "0",
      "0"
    );
  } else {
    v1_http_header = v1_http_header_create(
      "0",
      "0"
    );
  }

  return v1_http_header;
}


#ifdef v1_http_header_MAIN

void test_v1_http_header(int include_optional) {
    v1_http_header_t* v1_http_header_1 = instantiate_v1_http_header(include_optional);

	cJSON* jsonv1_http_header_1 = v1_http_header_convertToJSON(v1_http_header_1);
	printf("v1_http_header :\n%s\n", cJSON_Print(jsonv1_http_header_1));
	v1_http_header_t* v1_http_header_2 = v1_http_header_parseFromJSON(jsonv1_http_header_1);
	cJSON* jsonv1_http_header_2 = v1_http_header_convertToJSON(v1_http_header_2);
	printf("repeating v1_http_header:\n%s\n", cJSON_Print(jsonv1_http_header_2));
}

int main() {
  test_v1_http_header(1);
  test_v1_http_header(0);

  printf("Hello world \n");
  return 0;
}

#endif // v1_http_header_MAIN
#endif // v1_http_header_TEST
