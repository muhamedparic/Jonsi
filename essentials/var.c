#include "var.h"

#include <stdio.h>

struct variable* var_create(var_type type, void* data)
{
    struct variable* product = {.type = var_type, .data = data};
    return product;
}

void var_assign(struct variable* destination, const struct variable* source)
{
    destination->type = source->type;
    if (destination->data)
    {
        free(destination->data);
    }
    destination->data = source->data;
}