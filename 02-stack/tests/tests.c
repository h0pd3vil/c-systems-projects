#include <stdio.h>
#include <assert.h>
#include "../../02-stack/include/stack.h"
#include <stdlib.h>

void test_init(Stack *stack);
void test_push(Stack *stack);
void test_pop(Stack *stack);
void test_peek(Stack *stack);
void test_lifo_order(Stack *stack);
void test_clear(Stack *stack);




int main() 
{
    Stack stack;
    test_init(&stack);
    test_push(&stack);
    test_pop(&stack);
    test_peek(&stack);
    test_lifo_order(&stack);
    test_clear(&stack);  
    return 0;
}


void test_init(Stack *stack)
{
    stack_init(stack);
    assert(stack->head == NULL && stack->size == 0);
}

void test_clear(Stack *stack)
{
    stack_clear(stack);
    assert(stack->head == NULL && stack->size == 0);
}

void test_pop(Stack *stack)
{
    stack_clear(stack);
    assert(stack->size == 0);
    int a = 5;
    int *val = malloc(sizeof(int));
    val  = a;
    stack_push(stack,val);
    assert(stack->size == 1);
    int *x = stack_peek(stack);
    assert(*x == 5);
    free(val);
}