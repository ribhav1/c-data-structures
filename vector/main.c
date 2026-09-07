#include <stdio.h>
#include <string.h>
#include "vector.h"

int main()
{
    char cmd[128];
    vector_t* vector = new_vector(10, 0.7f);

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
            vector_print(vector);
        }
        else if (strcmp("insert", cmd) == 0)
        {
            int insert_val;
            fscanf(stdin, "%d", &insert_val);
            
            int insert_idx = vector_insert(vector, insert_val);
            printf("inserted %d at index %d\n", insert_val, insert_idx);
        }
        else if (strcmp("remove", cmd) == 0)
        {
            int remove_idx;
            fscanf(stdin, "%d", &remove_idx);
            
            int remove_val = vector_remove(vector, remove_idx);
            if (remove_val != -1)
            {
                printf("removed %d at index %d\n", remove_val, remove_idx);
            }
            else
            {
                printf("invalid index\n");
            }
        }
        else
        {
            printf("not a valid command. try again\n");
        }
    }

    return 0;
}