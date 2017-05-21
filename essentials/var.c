#include "var.h"

#include <stdio.h>
#include <stdlib.h>

struct variable* var_create(enum var_type type, void* data)
{
    struct variable* product = malloc(sizeof(struct variable));
    *product = (struct variable){.type = type, .data = data};
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