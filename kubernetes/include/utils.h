#ifndef UTILS_HPP
#define UTILS_HPP

#ifdef  __cplusplus
extern "C" {
#endif

#if !defined(HAVE_STRNDUP)
char *strndup(const char *s, size_t n);
#endif /* ! HAVE_STRNDUP */

#ifdef  __cplusplus
}
#endif

#endif //UTILS_HPP
