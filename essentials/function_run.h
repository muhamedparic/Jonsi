#ifndef FUNCTION_RUN_H
#define FUNCTION_RUN_H

#include "../core/ast.h"
#include "var.h"

void run(struct ast_node* node, struct variable* output);

#endif