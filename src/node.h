struct _node {
    struct _node * next;
    struct _node * prev;
    unsigned int i;
    int id;
};

typedef struct _node Node;