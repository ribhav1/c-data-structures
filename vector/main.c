#include <stdio.h>
#include <string.h>
#include "vector.h"

int main()
{
    char cmd[128];
    vector_t vector;
    vector_init(&vector, 10, 0.7f);

    while (1)
    {
        printf("vector> ");
        fscanf(stdin, "%s", cmd);

        if (strcmp("exit", cmd) == 0)
        {
            printf("ending program");
            break;
        }
        else if (strcmp("print", cmd) == 0)
        {
            vector_print(&vector);
        }
        else if (strcmp("insert", cmd) == 0)
        {
            int insert_val;
            fscanf(stdin, "%d", &insert_val);
            
            int insert_idx;
            vector_insert(&vector, insert_val, &insert_idx);
            printf("inserted %d at index %d\n", insert_val, insert_idx);
        }
        else if (strcmp("remove", cmd) == 0)
        {
            int remove_idx;
            fscanf(stdin, "%d", &remove_idx);
            
            int remove_val;
            if (vector_remove(&vector, remove_idx, &remove_val))
            {
                printf("removed %d at index %d\n", remove_val, remove_idx);
            }
            else
            {
                printf("invalid index\n");
            }
        }
        else if (strcmp("get", cmd) == 0)
        {
            int get_idx;
            fscanf(stdin, "%d", &get_idx);

            int get_val;
            if (vector_get(&vector, get_idx, &get_val))
            {
                printf("got %d at index %d\n", get_val, get_idx);
            }
            else
            {
                printf("invalid index\n");
            }
        }
        else if (strcmp("set", cmd) == 0)
        {
            int set_idx;
            fscanf(stdin, "%d", &set_idx);

            int new_val;
            fscanf(stdin, "%d", &new_val);

            int old_val;
            if (vector_set(&vector, set_idx, new_val, &old_val))
            {
                printf("set %d at index %d to %d\n", old_val, set_idx, new_val);
            }
            else
            {
                printf("invald index\n");
            }
        }
        else
        {
            printf("not a valid command. try again\n");
        }
    }

    return 0;
}