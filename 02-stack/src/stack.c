#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "../../02-stack/include/stack.h"


void init_stack(Stack *stack)
{
    stack->head = NULL;
    stack->size = 0;
}

int clr_stack(Stack *stack)
{
    if(!stack || !stack->head)
        return -1;
    while (stack->head != NULL)
    {
        int *data = pop(stack);
        free(data);
    }
    return 1;   
}

int push(Stack *stack, void *data)
{
    if(!stack)
        return -1;
    Node *tmp;
    tmp = (Node *)malloc(sizeof(Node));
    if(tmp == NULL)
        return -2;
    tmp->data = data;
    tmp->link = stack->head;
    stack->head = tmp;
    stack->size++;
    return 1;
}

void* pop(Stack *stack)
{
    if(!stack || !stack->head)
        return NULL;
    Node *tmp = stack->head;
    void *data = tmp->data;
    stack->head = tmp->link;
    stack->size--;
    free(tmp);
    return data;
}

void* peek(const Stack *stack)
{
    if(!stack || !stack->head)
        return NULL;
    return stack->head->data;
}

int reverse(Stack *stack)
{
    if(!stack || !stack->head || !stack->head->link)
        return -1;
    Node *curr = stack->head;
    Node *nex = NULL;
    Node *pre = NULL;
    while (curr)
    {
        nex = curr->link;
        curr->link = pre;
        pre = curr;
        curr = nex;
    }
    stack->head = pre;
return 1;
}