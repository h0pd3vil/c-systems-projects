#ifndef STACK_H
#define STACK_H

#include <stddef.h>

typedef struct Stack Stack;
typedef struct Node  Node;


Node
{
    void *data;
    Node *link;
};

Stack
{
    struct node *head;
    int size;
};

/*init && clr (lifecycles)*/

void stack_init(Stack *s);
void stack_clear(Stack *s);

/* core opr */
int   stack_push(Stack *s, void *data);
void *stack_pop(Stack *s);
void *stack_peek(Stack );

/*helper func*/
int stack_is_empty(const Stack *s);
int stack_size(const Stack *s);

#endif
