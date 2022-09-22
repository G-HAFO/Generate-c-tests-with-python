#ifndef  __dbg_h__
#define __dbg_h__

#include <stdio.h>
#include <string.h>
#include <errno.h>


#ifdef NDEBUG
#define DEBUG(M, ...)
#else

#define print(M, ...) fprintf(stderr, "" M "\n", ##__VA_ARGS__)
#define printl(M, ...) fprintf(stderr, "" M "", ##__VA_ARGS__)
#define DEBUG(M, ...) fprintf(stderr, "[DEBUG] %s:%d: " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)

#define clean_errno() (errno == 0 ? "None" : strerror(errno))
#define LOG_ERR(M, ...) fprintf(stderr "[ERROR] (%s:%d: errno: %s) " M "\n",\
                            __FILE__, __LINE__, clean_errno(),##__VA_ARGS__)

#define LOG_WARN(M, ...) fprintf(stderr, "[WARN] (%s:%d: errno %s) " M "\n",\
                            __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)
#define INFO(M, ...) fprintf(stderr, "[INFO] :" M "\n", ##__VA_ARGS__)

#define CHECK(A, M, ...) if(!(A)) {LOG_WARN(M, ##__VA_ARGS__); errno=0; \
                           goto error; }

#endif
#endif





