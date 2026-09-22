typedef struct node_struct
{
    int val;
    struct node_struct *next;
} node_t;

typedef struct linked_list_struct
{
    node_t *root;
} linked_list_t;


void linked_list_init(linked_list_t *linked_list);

void linked_list_destroy(linked_list_t *linked_list);

void linked_list_insert(linked_list_t *linked_list, int value);
node_t* recursive_insert(node_t *curr, int value);

void linked_list_remove(linked_list_t *linked_list, int value);

void linked_list_print(linked_list_t *linked_list);