#include "error.h"

void assert(int condition, const char* message)
{
    if (!condition)
    {
        printf("%s", message);
        exit(1);
    }
}