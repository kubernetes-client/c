#ifndef storage_v1_token_request_TEST
#define storage_v1_token_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define storage_v1_token_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/storage_v1_token_request.h"
storage_v1_token_request_t* instantiate_storage_v1_token_request(int include_optional);



storage_v1_token_request_t* instantiate_storage_v1_token_request(int include_optional) {
  storage_v1_token_request_t* storage_v1_token_request = NULL;
  if (include_optional) {
    storage_v1_token_request = storage_v1_token_request_create(
      "0",
      56
    );
  } else {
    storage_v1_token_request = storage_v1_token_request_create(
      "0",
      56
    );
  }

  return storage_v1_token_request;
}


#ifdef storage_v1_token_request_MAIN

void test_storage_v1_token_request(int include_optional) {
    storage_v1_token_request_t* storage_v1_token_request_1 = instantiate_storage_v1_token_request(include_optional);

	cJSON* jsonstorage_v1_token_request_1 = storage_v1_token_request_convertToJSON(storage_v1_token_request_1);
	printf("storage_v1_token_request :\n%s\n", cJSON_Print(jsonstorage_v1_token_request_1));
	storage_v1_token_request_t* storage_v1_token_request_2 = storage_v1_token_request_parseFromJSON(jsonstorage_v1_token_request_1);
	cJSON* jsonstorage_v1_token_request_2 = storage_v1_token_request_convertToJSON(storage_v1_token_request_2);
	printf("repeating storage_v1_token_request:\n%s\n", cJSON_Print(jsonstorage_v1_token_request_2));
}

int main() {
  test_storage_v1_token_request(1);
  test_storage_v1_token_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // storage_v1_token_request_MAIN
#endif // storage_v1_token_request_TEST
