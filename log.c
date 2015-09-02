#include <sys/syscall.h>

pid_t gettid()
{
    return syscall(SYS_gettid);
}


void MyDebug(const char *file, const int line, const char *func, char *format,  ...)
{
    char szData[512] = {0};
    va_list args;
    va_start(args, format);
    vsprintf(szData, format, args);
    va_end(args);

    printf("[%s][%d][%s][%d] - %s", file, line, func, gettid(), szData);
    fflush(stdout);
}


#ifdef MY_DEBUG
#define IOTC_DBG_TRACE(...) MyDebug(__FILE__, __LINE__, __FUNCTION__, __VA_ARGS__)
#else
#define IOTC_DBG_TRACE(...) ((void *)0)
#endif
