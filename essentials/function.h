#ifndef RUN_H
#define RUN_H

#include "ast.h"
#include "var.h"
#include "builtin_functions.h"

struct function_table_t
{
    char** names = {"input", "print", "+"};
    void** functions = {&input, &print, &math_plus};
    int count = 3;
} function_table;

void run(struct ast_node* node, struct variable* output);

#endif