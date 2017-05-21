#ifndef VAR_H
#define VAR_H

enum var_type
{
    INT,
    BOOL,
    NULL_T
};

struct variable
{
    enum var_type type;
    void* data;
};

struct variable* var_create(enum var_type type, void* data);
void var_assign(struct variable* destination, const struct variable* source);

#endif