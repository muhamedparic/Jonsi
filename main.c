#include "core/parser.h"
#include "essentials/function_run.h"
#include "essentials/var.h"

#include <stdio.h>

void debug_print(struct ast_node* node)
{
    int i;
    printf("%s\n", node->name);

    for (i = 0; i < node->child_count; i++)
    {
        printf("Down:\n");
        debug_print(node->children[i]);
        printf("Up:\n");
    }
}

int main()
{
    struct ast_node* root = ast_create("( print ( + 1 ( input ) ) )");
    //debug_print(root);
    run(root, NULL);
}