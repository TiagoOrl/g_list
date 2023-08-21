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

void insertAt(List * l, int i, int id);

Node * getAt(List * l, int i);

Node * getByVal(List * l, int id);

void removeNode(List * l, Node * n);

void removeAt(List * list, int i);

void removeVal(List * l, int id);

void enqueue(List * l, int id);

int dequeue(List * l);

int pop(List * list);

void print(List * list);

List * newList();

Node * createNode();
