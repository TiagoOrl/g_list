#include <stdlib.h>
#include <stdio.h>
#include "node.h"

struct _list {
    Node * top;
    Node * bottom;
    unsigned int size;
};

typedef struct _list List;

void push(List * list, int id);
void insertAt(int i, int id);
void removeAt(int i);
void removeVal(int id);
int pop(List * list);
void print(List * list);
List * newList();
Node * createNode();
