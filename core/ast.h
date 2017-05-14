#ifndef AST_H
#define AST_H

#define START_CHILD_COUNT 4

struct ast_node
{
    char* name;
    struct ast_node** children;
    int is_call;
    int child_count;
    int child_capacity;
};

struct ast_node* ast_node_create(const char* name);
void ast_node_destroy(struct ast_node* node);
void ast_node_add_child(struct ast_node* parent, struct ast_node* child);

static void ast_node_double_child_capacity(struct ast_node* node);

#endif