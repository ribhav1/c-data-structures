#include "linked_list.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

void linked_list_init(linked_list_t *linked_list)
{
    linked_list->root = NULL;
}

void linked_list_destroy(linked_list_t *linked_list)
{
    free(linked_list->root);
}

void linked_list_insert(linked_list_t *linked_list, int value)
{
    linked_list->root = recursive_insert(linked_list->root, value);

}

node_t* recursive_insert(node_t *curr, int value)
{
    if (curr == NULL || curr->val > value)
    {
        node_t* new_node = malloc(sizeof(node_t));
        new_node->val = value;
        new_node->next = curr;

        return new_node;
    }

    curr->next = recursive_insert(curr->next, value);
    return curr;
}

node_t* recursive_remove(node_t *curr, int value)
{
    if (curr == NULL) return NULL;

    if (curr->val == value)
    {
        return curr->next;
    }

    curr->next = recursive_remove(curr->next, value);
    return curr;
}

void linked_list_remove(linked_list_t *linked_list, int value)
{
    linked_list->root = recursive_remove(linked_list->root, value);
}

bool recursive_contains(node_t *curr, int value)
{
    if (curr == NULL) return false;
    if (curr->val == value) return true;

    return recursive_contains(curr->next, value);
}

bool linked_list_contains(linked_list_t *linked_list, int value)
{
    return recursive_contains(linked_list->root, value);
}


void linked_list_print(linked_list_t *linked_list)
{
    node_t *curr = linked_list->root;

    while (curr != NULL)
    {
        printf("%d", curr->val);
        if (curr->next != NULL)
        {
            printf(" -> ");
        }

        curr = curr->next;
    }

    printf("\n");
}