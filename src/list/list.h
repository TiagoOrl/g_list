#ifndef H_LIST_MOD
#define H_LIST_MOD

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "node.h"

struct _list {
    node * top;
    node * bottom;
    unsigned int size;
};

typedef struct _list list;

void l_push(list* list, void * data, int nbytes, size_t size);
void l_insert_at(list *_list, void * data, int nbytes, int pos, size_t size);
node * l_get_at(list l, int pos);
node * l_get_by_val(list l, void * data);
void l_remove_node(list* list, node * found);
void l_remove_at(list* list, int pos);
void l_remove_val(list* list, void *data);
void* l_dequeue(list* _list);
void* l_pop(list *list);
void l_print(list list, char dir);

list l_new();
void l_free_node(node * n);
void l_free_list(list* l);
node * l_create_node(void *data, size_t size, int nbytes);

#endif
