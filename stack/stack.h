#include "../vector/vector.h"

typedef struct stack_struct
{
    vector_t list;
} stack_t;

void stack_init(stack_t *stack);

void stack_destroy(stack_t *stack);

void stack_print(stack_t *stack);

void stack_push(stack_t *stack, int value);

int stack_pop(stack_t *stack, int *pop_val);

int stack_peek(stack_t *stack, int *peek_val);

int stack_get(stack_t *stack, int index, int *get_val);

int stack_size(stack_t *stack);

bool stack_is_empty(stack_t *stack);