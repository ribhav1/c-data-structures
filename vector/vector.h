typedef struct
{
    int top;
    int capacity;
    float threshold;
    int *data;
} vector_t;

void vector_init(vector_t *vector, int initial_capacity, float threshold);

void vector_destroy(vector_t *vector);

void vector_resize(vector_t *vector);

void vector_insert(vector_t *vector, int value);

int vector_remove(vector_t *vector, int index, int *remove_val);

int vector_get(vector_t *vector, int index, int *get_val);

int vector_set(vector_t *vector, int index, int new_val, int *old_val);

void vector_print(vector_t *vector);