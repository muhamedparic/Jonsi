#ifndef BUILTIN_FUNCTIONS_H
#define BUILTIN_FUNCTIONS_H

#include "../core/ast.h"
#include "var.h"
#include "function.h"

#include <stdio.h>
#include <stdlib.h>

void input(struct ast_node* node, struct variable* output)
{
    int* result = malloc(sizeof(int));
    scanf("%d", result);
    output->type = INT;
    output->data = result;
}

void print(struct ast_node* node, struct variable* output)
{
    struct variable* result = malloc(sizeof(struct variable));
    run(node->children[0], result);
    printf("%d", *(int*)result->data);
}

void math_plus(struct ast_node* node, struct variable* output)
{
    struct variable* params[2];
    params[0] = malloc(sizeof(struct variable));
    params[1] = malloc(sizeof(struct variable));
    run(node->children[0], params[0]);
    run(node->children[1], params[1]);

    output->type = INT;
    int* result = malloc(sizeof(int));
    *result = *(int*)params[0]->data + *(int*)params[1]->data;
    output->data = result;
}

#endif