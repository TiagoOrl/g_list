#ifndef H_NODE_L
#define H_NODE_L

struct _node {
    struct _node * next;
    struct _node * prev;
    unsigned int size;
    unsigned int nbytes;
    void * data;
};

typedef struct _node node;

#endif