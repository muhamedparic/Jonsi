#ifndef PARSER_H
#define PARSER_H

#include "ast.h"

struct ast_node* ast_create(const char* prog_code);
void ast_destroy(struct ast_node* root_node);

static void tokenize(const char* prog_code);
static int parse_node(struct ast_node** node, int index);

#endif