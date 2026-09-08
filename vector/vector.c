
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

void vector_init(vector_t *vector, int initial_capacity, float threshold)
{
    vector->top = 0;
    vector->capacity = initial_capacity;
    vector->threshold = threshold;
    vector->data = malloc(initial_capacity * sizeof(int));
}

void vector_destroy(vector_t *vector)
{
    free(vector->data);
}

void vector_resize(vector_t *vector)
{
    vector->capacity *= 2;
    vector->data = realloc(vector->data, vector->capacity * sizeof(int));
}

void vector_insert(vector_t *vector, int value)
{
    if ((float)(vector->top + 1) / vector->capacity >= vector->threshold)
    {
        vector_resize(vector);
    }

    vector->data[vector->top] = value;
    vector->top++;
}

int vector_remove(vector_t *vector, int index, int *remove_val)
{
    if (index < 0 || index >= vector->top)
    {
        return 0;
    }

    int removed = vector->data[index];
    for (int i = index + 1; i < vector->top; i++)
    {
        vector->data[i - 1] = vector->data[i];
    }
    vector->top--;

    *remove_val = removed;
    return 1;
}

int vector_get(vector_t *vector, int index, int *get_val)
{
    if (index < 0 || index >= vector->top)
    {
        return 0;
    }

    *get_val = vector->data[index];
    return 1;
}

int vector_set(vector_t *vector, int index, int new_val, int *old_val)
{
    if (index < 0 || index >= vector->top)
    {
        return 0;
    }

    *old_val = vector->data[index];
    vector->data[index] = new_val;

    return 1;
}

void vector_print(vector_t *vector)
{
    for (int i = 0; i < vector->top; i++)
    {
        printf("index %d: %d\n", i, vector->data[i]);
    }
}

