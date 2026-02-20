#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include "stack.h"


ds_status_t stack_init(Stack *stack)
{
    if(!stack)
        return DS_ERR_NULL;
    stack->head = NULL;
    stack->size = 0;
    return DS_OK;
}

ds_status_t stack_clr(Stack *stack)
{
    if(!stack)
        return DS_ERR_NULL;

    while (stack->head)
    {
        void *data;
        ds_status_t status = stack_pop(stack, &data);
        if (status != DS_OK)
        {
            return status;
        }
       
    }
    return DS_OK;   
}

ds_status_t stack_push(Stack *stack, void *data)
{
    if(!stack)
        return DS_ERR_NULL;
    Node *tmp;
    tmp = (Node *)malloc(sizeof(Node));
    if(tmp == NULL)
        return DS_ERR_OOM;

    tmp->data = data;
    tmp->link = stack->head;
    stack->head = tmp;
    stack->size++;
    return DS_OK;
}

ds_status_t stack_pop(Stack *stack, void **data)
{
    if(!stack || !data)
        return DS_ERR_NULL;

    if(!stack->head)
        return DS_ERR_EMPTY;

    Node *tmp = stack->head;

    *data = tmp->data;
    stack->head = tmp->link;
    stack->size--;
    free(tmp);
    return DS_OK;
}

ds_status_t stack_peek(const Stack *stack, void **out_data)
{
    if(!stack)
        return DS_ERR_NULL;

    if(!stack->head)
        return DS_ERR_EMPTY;

    *out_data = stack->head->data;
    return DS_OK;
}

ds_status_t stack_reverse(Stack *stack)
{
    if(!stack)
        return DS_ERR_NULL;
    
    if(!stack->head)
        return DS_ERR_EMPTY;

    if(!stack->head->link)
        return DS_OK;
        
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
return DS_OK;
}

ds_status_t stack_is_empty(const Stack *stack, bool *result)
{
    if(!stack)
        return DS_ERR_NULL;
    
    *result = (stack->head == NULL);

    return DS_OK;
}

ds_status_t stack_size(const Stack *stack, size_t *out_size)
{
    if(!stack || !out_size)
        return DS_ERR_NULL;
    *out_size = stack->size;
    return DS_OK;
}