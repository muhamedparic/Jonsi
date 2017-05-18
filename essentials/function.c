#include "function.h"
#include "error.h"

#include <string.h>
#include <stdlib.h>

void run(struct ast_node* node, struct variable* output)
{
    int i;
    void* data;

    if (node->is_call)
    {
        for (i = 0; i < function_table.count; i++)
        {
            if (!strcmp(node->name, function_table.names[i]))
            {
                (*function_table.functions[i])(node, output);
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
            node->data = data;
        }
        else if (!strcmp(node->name, "false"))
        {
            output->type = BOOL;
            data = malloc(sizeof(int));
            *((int*)data) = 0;
            node->data = data;
        }
        else if (!strcmp(node->name, "null"))
        {
            output->type = NULL_T;
            data = NULL;
            node->data = data;
        }
        else
        {
            output->type = INT;
            data = malloc(sizeof(int));
            *((int*)data) = atoi(node->name);
            node->data = data;
        }
    }
}