#include "stack.h"


void add(Stack * stack, int id)
{
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->id = id;
    newNode->i = stack->size;

    if (stack->top == NULL)
        stack->top = newNode;

    else 
    {
        newNode->next = stack->top;
        stack->top = newNode;
    }
    stack->size++;
}

int pop(Stack * stack)
{
    if (stack->top == NULL)
        return 0;
    
    Node * prevTop = stack->top;
    int id = prevTop->id;

    stack->top = stack->top->next;

    stack->size--;
    free(prevTop);

    return id;
}

Stack * newStack()
{
    Stack * stack = (Stack *)malloc(sizeof(Stack));

    stack->size = 0;
    stack->top = NULL;

    return stack;
}

void print(Stack * stack)
{
    Node * it = stack->top;

    while (it != NULL)
    {
        printf("(%d)\ti: %d\n", it->id, it->i);
        it = it->next;
    }
}