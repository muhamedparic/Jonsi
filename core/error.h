#ifndef ERROR_H
#define ERROR_H

#include <stdio.h>
#include <stdlib.h>

void assert(int condition, const char* message)
{
    if (!condition)
    {
        printf("%s", message);
        exit(1);
    }
}

#endif