#include <stdio.h>
#include <string.h>
#include "stack.h"

int main()
{
    char cmd[128];
    stack_t stack;
    stack_init(&stack);

    while (1)
    {
        printf("stack> ");
        fscanf(stdin, "%s", cmd);

        if (strcmp("exit", cmd) == 0)
        {
            printf("ending program");
            break;
        }
        else if (strcmp("print", cmd) == 0)
        {
            stack_print(&stack);
        }
        else if (strcmp("push", cmd) == 0)
        {
            int push_val;
            fscanf(stdin, "%d", &push_val);
            
            stack_push(&stack, push_val);
            printf("pushed %d to top\n", push_val);
        }
        else if (strcmp("pop", cmd) == 0)
        {
            int pop_val;
            if (stack_pop(&stack, &pop_val))
            {
                printf("popped %d from top\n", pop_val);
            }
            else
            {
                printf("stack is empty\n");
            }
        }
        else if (strcmp("peek", cmd) == 0)
        {
            int peek_val;
            if (stack_peek(&stack, &peek_val))
            {
                printf("%d is at top\n", peek_val);
            }
            else
            {
                printf("stack is empty\n");
            }
        }
        else if (strcmp("get", cmd) == 0)
        {
            int get_idx;
            fscanf(stdin, "%d", &get_idx);

            int get_val;
            if (stack_get(&stack, get_idx, &get_val))
            {
                printf("got %d at index %d\n", get_val, get_idx);
            }
            else
            {
                printf("invalid index\n");
            }
        }
        else if (strcmp("size", cmd) == 0)
        {
            printf("%d elements in stack\n", stack_size(&stack));
        }
        else if (strcmp("isempty", cmd) == 0)
        {
            if (stack_is_empty(&stack))
            {
                printf("stack is empty\n");
            }
            else
            {
                printf("stack is not empty\n");
            }
        }
        else
        {
            printf("not a valid command. try again\n");
        }
    }
    stack_destroy(&stack);

    return 0;
}