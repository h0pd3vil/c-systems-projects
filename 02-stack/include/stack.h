#ifndef STACK_H
#define STACK_H

#include <stddef.h>
#include "ds_errors.h"

typedef struct Node
{
    void *data;
    struct Node *link;
}Node;

typedef struct Stack
{
    struct Node *head;
    int size;
}Stack;

/*init && clr (lifecycles)*/

ds_status_t stack_init(Stack *s);
ds_status_t stack_clr(Stack *s);

/* core opr */
ds_status_t stack_push(Stack *s, void *data);
ds_status_t stack_pop(Stack *s, void **data);
ds_status_t stack_peek(const Stack *s, void **data);
ds_status_t stack_reverse(Stack *s);

/*helper func*/
ds_status_t stack_is_empty(const Stack *s, bool *result); // const make it read only
ds_status_t stack_size(const Stack *s, size_t *result);

#endif
