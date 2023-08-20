#include "list.h"


Node * createNode()
{
    Node * node = (Node *)malloc(sizeof(Node));
    node->next = NULL;
    node->prev = NULL;
    node->id = NULL;
    node->i = -1;

    return node;
}

void push(List * list, int id)
{
    Node * newNode = createNode();

    newNode->id = id;
    newNode->i = list->size;

    if (list->top == NULL || list->size == 0)
    {
        list->top = newNode;
        list->bottom = newNode;
    }
    else 
    {
        list->top->prev = newNode;
        newNode->next = list->top;
        list->top = newNode;
    }
    list->size++;
}

int pop(List * list)
{
    if (list->top == NULL)
        return NULL;
    
    Node * topNode = list->top;
    int id = topNode->id;

    list->top = list->top->next;
    if (list->top == NULL)
        list->bottom = NULL;
    else
        list->top->prev = NULL;

    list->size--;
    free(topNode);

    return id;
}

List * newList()
{
    List * list = (List *)malloc(sizeof(List));

    list->size = 0;
    list->top = NULL;
    list->bottom = NULL;

    return list;
}

void print(List * list)
{
    Node * it = list->top;

    printf("\nstack size: %d\n", list->size);

    printf("Printing all items: \n\n");

    while (it != NULL)
    {
        printf("(%d)\ti: %d", it->id, it->i);
        if (it->prev != NULL)
            printf("\t prev: (%d)\n", it->prev->id);
        else
            printf("\n");
        it = it->next;
    }

    printf("\n");

    if (list->top != NULL)
        printf("top:\t(%d)\n", list->top->id);
    
    if (list->bottom != NULL)
        printf("bottom:\t(%d)\n\n", list->bottom->id);
}