#include <stdio.h>
#include <string.h>
#include "linked_list.h"

int main()
{
    char cmd[128];
    linked_list_t linked_list;
    linked_list_init(&linked_list);

    while (1)
    {
        printf("linked_list> ");
        scanf("%s", cmd);

        if (strcmp("exit", cmd) == 0)
        {
            printf("ending program");
            break;
        }
        else if (strcmp("print", cmd) == 0)
        {
            linked_list_print(&linked_list);
        }
        else if (strcmp("insert", cmd) == 0)
        {
            int insert_val;
            scanf("%d", &insert_val);
            
            linked_list_insert(&linked_list, insert_val);
            printf("inserted %d to end\n", insert_val);
        }
        else if (strcmp("remove", cmd) == 0)
        {
            int remove_val;
            scanf("%d", &remove_val);
            
            linked_list_remove(&linked_list, remove_val);
            printf("removed %d\n", remove_val);

        }
        // else if (strcmp("get", cmd) == 0)
        // {
        //     int get_idx;
        //     scanf("%d", &get_idx);

        //     int get_val;
        //     if (linked_list_get(&linked_list, get_idx, &get_val))
        //     {
        //         printf("got %d at index %d\n", get_val, get_idx);
        //     }
        //     else
        //     {
        //         printf("invalid index\n");
        //     }
        // }
        // else if (strcmp("set", cmd) == 0)
        // {
        //     int set_idx;
        //     scanf("%d", &set_idx);

        //     int new_val;
        //     scanf("%d", &new_val);

        //     int old_val;
        //     if (linked_list_set(&linked_list, set_idx, new_val, &old_val))
        //     {
        //         printf("set %d at index %d to %d\n", old_val, set_idx, new_val);
        //     }
        //     else
        //     {
        //         printf("invald index\n");
        //     }
        // }
        else
        {
            printf("not a valid command. try again\n");
        }
    }
    linked_list_destroy(&linked_list);

    return 0;
}