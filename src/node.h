#ifndef H_NODE_L
#define H_NODE_L

struct _node {
    struct _node * next;
    struct _node * prev;
    unsigned int i;
    char * data;
};

typedef struct _node Node;

#endif