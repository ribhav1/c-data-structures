#include "stack.h"
#include <stdio.h>

#define DEFAULT_INITIAL_CAPACITY 10
#define DEFAULT_THRESHOLD 0.7f

void stack_init(stack_t *stack)
{
    vector_init(&stack->list, DEFAULT_INITIAL_CAPACITY, DEFAULT_THRESHOLD);
}

void stack_destroy(stack_t *stack)
{
    vector_destroy(&stack->list);
}

void stack_print(stack_t *stack)
{
    printf("top\n");
    for (int i = stack->list.top-1; i >= 0; i--)
    {
        printf("index %d: %d\n", i, stack->list.data[i]);
    }
    printf("bottom\n");
}

void stack_push(stack_t *stack, int value)
{
    vector_insert(&stack->list, value);
}

int stack_pop(stack_t *stack, int *pop_val)
{
    if (stack_is_empty(stack))
    {
        return 0;
    }

    vector_remove(&stack->list, stack->list.top-1, pop_val);
    return 1;
}

int stack_peek(stack_t *stack, int *peek_val)
{
    if (stack_is_empty(stack))
    {
        return 0;
    }

    *peek_val = stack->list.data[stack->list.top-1];
    return 1;
}

int stack_get(stack_t *stack, int index, int *get_val)
{
    if (index < 0 || index >= stack->list.top)
    {
        return 0;
    }

    *get_val = stack->list.data[index];
    return 1;
}

int stack_size(stack_t *stack)
{
    return stack->list.top;
}

bool stack_is_empty(stack_t *stack)
{
    return stack_size(stack) == 0;
}

