typedef struct
{
    int top;
    int capacity;
    float threshold;
    int *data;
} vector_t;

vector_t* new_vector(int initial_capacity, float threshold);

void vector_resize(vector_t *vector);

int vector_insert(vector_t *vector, int value);

int vector_remove(vector_t *vector, int index);

void vector_print(vector_t *vector);