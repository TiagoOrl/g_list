#include <stdlib.h>
#include <stdio.h>
#include "node.h"

struct _stack {
    Node * top;
    unsigned int size;
};

typedef struct _stack Stack;

void add(Stack * stack, int id);
int pop(Stack * stack);

Stack * newStack();
