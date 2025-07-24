include(CheckSymbolExists)

check_symbol_exists(strndup "string.h" HAVE_STRNDUP)
check_symbol_exists(secure_getenv "stdlib.h" HAVE_SECURE_GETENV)
check_symbol_exists(getenv "stdlib.h" HAVE_GETENV)
check_symbol_exists(strtok_r "string.h" HAVE_STRTOK_R)
