#ifndef H_NODE_L
#define H_NODE_L

struct _node {
    struct _node * next;
    struct _node * prev;
    unsigned int i;
    unsigned int size;
    unsigned char * data;
};

typedef struct _node node;

#endif