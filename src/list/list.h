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

void l_push(list* list, unsigned char * data, size_t size);
void l_insert_at(list *_list, unsigned char * data, size_t i, size_t size);
node * l_get_at(list l, int i);
node * l_get_by_val(list l, unsigned char * data);
void l_remove_node(list* list, node * found);
void l_remove_at(list* list, int i);
void l_remove_val(list* list, unsigned char * data);
unsigned char * l_dequeue(list* _list);
unsigned char * l_pop(list *list);
void l_print(list list, char dir);

list l_new();
void l_free_node(node * n);
node * l_create_node(unsigned char * data, size_t size);

#endif
