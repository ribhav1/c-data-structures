
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

vector_t *new_vector(int initial_capacity, float threshold)
{
    vector_t *ret_vector = malloc(sizeof(vector_t));

    ret_vector->top = 0;
    ret_vector->capacity = initial_capacity;
    ret_vector->threshold = threshold;
    ret_vector->data = malloc(initial_capacity * sizeof(int));

    return ret_vector;
}

void vector_resize(vector_t *vector)
{
    vector->capacity *= 2;
    vector->data = realloc(vector->data, vector->capacity * sizeof(int));
}

int vector_insert(vector_t *vector, int value)
{
    if ((float)(vector->top + 1) / vector->capacity >= vector->threshold)
    {
        vector_resize(vector);
    }

    vector->data[vector->top] = value;
    vector->top++;

    return vector->top-1;
}

int vector_remove(vector_t *vector, int index)
{
    if (index < 0 || index >= vector->top)
    {
        return -1;
    }

    int remove_val = vector->data[index];
    for (int i = index + 1; i < vector->top; i++)
    {
        vector->data[i - 1] = vector->data[i];
    }
    vector->top--;

    return remove_val;
}

void vector_print(vector_t *vector)
{
    for (int i = 0; i < vector->top; i++)
    {
        printf("index %d: %d\n", i, vector->data[i]);
    }
}

