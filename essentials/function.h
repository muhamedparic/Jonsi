#ifndef RUN_H
#define RUN_H

#include "../core/ast.h"
#include "var.h"
#include "builtin_functions.h"

#define FUNCTION_COUNT 3

typedef void builtin_function(struct ast_node*, struct variable*);

struct function_table_t
{
    char* names[FUNCTION_COUNT];
    void* functions[FUNCTION_COUNT];
};

struct function_table_t function_table =
{
    .names =  {"input", "print", "+"},
    .functions = {input, print, math_plus}
};

#endif