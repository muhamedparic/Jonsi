#include "function_run.h"
#include "function.h"
#include "../core/error.h"

#include <string.h>
#include <stdlib.h>

void run(struct ast_node* node, struct variable* output)
{
    int i;
    void* data;

    if (node->is_call)
    {
        for (i = 0; i < FUNCTION_COUNT; i++)
        {
            if (!strcmp(node->name, function_table.names[i]))
            {
                ((builtin_function*)function_table.functions[i])(node, output);
                return;
            }
        }

        assert(0, "Called an undefined function");
    }
    else
    {
        if (!strcmp(node->name, "true"))
        {
            output->type = BOOL;
            data = malloc(sizeof(int));
            *((int*)data) = 1;
            output->data = data;
        }
        else if (!strcmp(node->name, "false"))
        {
            output->type = BOOL;
            data = malloc(sizeof(int));
            *((int*)data) = 0;
            output->data = data;
        }
        else if (!strcmp(node->name, "null"))
        {
            output->type = NULL_T;
            data = NULL;
            output->data = data;
        }
        else
        {
            output->type = INT;
            data = malloc(sizeof(int));
            *((int*)data) = atoi(node->name);
            output->data = data;
        }
    }
}