#include "ast.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct ast_node* ast_node_create(const char* name)
{
    struct ast_node* product = malloc(sizeof(struct ast_node));
    product->is_call = 2; // Illegal value, needs to be set
    product->child_count = 0;
    product->child_capacity = 0;
    product->children = NULL;
    product->name = malloc(sizeof(char) * strlen(name));
    strcpy(product->name, name);

    return product;
}

void ast_node_destroy(struct ast_node* node)
{
    int i;

    for (i = 0; i < node->child_count; i++)
    {
        ast_node_destroy(node->children[i]);
        free(node->children[i]);
    }

    free(node->name);

    if (node->children)
        free(node->children);
}

void ast_node_add_child(struct ast_node* parent, struct ast_node* child)
{
    if (parent->children == NULL)
    {
        parent->children = malloc(START_CHILD_COUNT * sizeof(struct ast_node*));
        parent->children[0] = child;

        parent->child_capacity = START_CHILD_COUNT;
        parent->child_count = 1;
    }
    else if (parent->child_count == parent->child_capacity)
    {
        ast_node_double_child_capacity(parent);
        parent->children[parent->child_count++] = child;
    }
    else
    {
        parent->children[parent->child_count++] = child;
    }
}

void ast_node_double_child_capacity(struct ast_node* node)
{
    node->children = realloc(node->children, 2 * node->child_capacity * sizeof(struct ast_node*));
}