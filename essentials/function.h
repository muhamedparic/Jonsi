#ifndef RUN_H
#define RUN_H

#include "ast.h"
#include "var.h"

struct function_table
{
    struct ast_node** nodes;
    int node_count;
    int node_capacity;
};

struct function_table* function_table_create();
void function_table_add(struct ast_node* new_function);
void function_table_destroy(struct function_table* table);

int run(struct function_table* table, const char* function_name, struct variable* output);

#endif