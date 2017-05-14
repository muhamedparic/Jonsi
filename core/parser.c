#include "parser.h"
#include "error.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char tokens[2048][32]; // Flexibilize later
int token_count = 0;

struct ast_node* ast_create(const char* prog_code)
{
    struct ast_node* root = NULL;
    int i;

    tokenize(prog_code);
    parse_node(&root, 0);

    return root;
}

// Returns index after end
int parse_node(struct ast_node** node, int index)
{
    /*
    char err_msg[100];
    sprintf(err_msg, "Token %d invalid", index);
    assert(!strcmp(tokens[index], "("), err_msg);
    */

    int cur_token;

    if (!strcmp(tokens[index], "("))
    {
        *node = ast_node_create(tokens[index + 1]);
        (*node)->is_call = 1;
        cur_token = index + 2;
    }
    else
    {
        *node = ast_node_create(tokens[index]);
        (*node)->is_call = 0;
        return index + 1;
    }

    while (1)
    {
        assert(cur_token != token_count, "Missing closing parenthesis");

        if (!strcmp(tokens[cur_token], ")"))
        {
            return cur_token + 1;
        }
        else
        {
            struct ast_node* new_child = NULL;
            cur_token = parse_node(&new_child, cur_token);
            ast_node_add_child(*node, new_child);
        }
    }
}

static void tokenize(const char* prog_code)
{
    int token_i = 0;
    int char_i = 0;

    int i;

    for (i = 0; prog_code[i] != '\0'; i++)
    {
        if (prog_code[i] != ' ')
        {
            tokens[token_i][char_i++] = prog_code[i];
        }
        else
        {
            if (char_i > 0)
            {
                tokens[token_i][char_i] = '\0';
                token_i++;
                char_i = 0;
            }
        }
    }

    if (char_i > 0)
    {
        tokens[token_i][char_i] = '\0';
        token_i++;
    }

    token_count = token_i;
}