#ifndef STACK_H
#define STACK_H

#include <stddef.h>

typedef struct Node
{
    void *data;
    Node *link;
}Node;

typedef struct Stack
{
    struct Node *head;
    int size;
}Stack;

/*init && clr (lifecycles)*/

void stack_init(Stack *s);
void stack_clear(Stack *s);

/* core opr */
int   stack_push(Stack *s, void *data);
void *stack_pop(Stack *s);
void *stack_peek(Stack );

/*helper func*/
int stack_is_empty(const Stack *s); // const make it read only
int stack_size(const Stack *s);

#endif
