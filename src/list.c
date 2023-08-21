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

Node * getAt(List * list, int i)
{    
    Node * it = NULL;

    if (i < 0 || list == NULL)
        return NULL;

    it = list->top;

    while (it != NULL)
    {
        if (it->i == i)
            return it;
        it = it->next;
    }

    return it;
}

Node * getByVal(List * list, int id)
{
    Node * it = NULL;

    if (list == NULL)
        return;

    it = list->top;

    while (it != NULL)
    {
        if (it->id == id)
            return it;
        it = it->next;
    }

    return it;
}

void insertAt(List * list, int i, int id)
{
    if (
        list->size < 1 || 
        list->top == NULL || 
        i >= list->size ||
        i < 0
    )
        return;

    Node * found = NULL;
    Node * newNode = createNode();

    newNode->id = id;
    newNode->i = i;

    if (i == 0)
        found = list->bottom;
    else if (i == list->size - 1)
        found = list->top;
    else
        found = getAt(list, i);

    if (found == NULL)
        return;

    found->id = id;
    return;
}

void removeNode(List * list, Node * found)
{
    if (found == NULL)
        return;

    if (found->prev == NULL && found->next == NULL)
    {
        pop(list);
        return;
    }

    // top node
    if (found->prev == NULL)
    {
        Node * nextSubs = found->next;
        nextSubs->prev = NULL;
        list->top = nextSubs;
        list->size--;

        free(found);
        return;
    }

    // bottom node
    if (found->next == NULL)
    {
        Node * prevSubs = found->prev;
        Node * it = prevSubs;
        prevSubs->next = NULL;
        list->bottom = prevSubs;

        list->size--;

        while(it != NULL)
        {
            it->i--;
            it = it->prev;
        }

        free(found);
        return;
    }

    Node * subs = found->prev;
    Node * it = subs;

    found->next->prev = subs;
    subs->next = found->next;
    list->size--;

    while (it != NULL)
    {
        it->i--;
        it = it->prev;
    }

    free(found);
    return;
}

void removeVal(List * list, int id)
{
    if (list->size < 1)
        return;

    Node * found = NULL;

    found = getByVal(list, id);
    removeNode(list, found);
}

void removeAt(List * list, int i)
{

    if (
        list->size < 1 || 
        list->top == NULL || 
        i >= list->size ||
        i < 0
    )
        return;



    Node * found = NULL;

    if (i == 0)
        found = list->bottom;
    else if (i == list->size - 1)
        found = list->top;
    else
        found = getAt(list, i);

    removeNode(list, found);
}

void enqueue(List * list, int id)
{
    if (list == NULL)
        return;
    
    Node * newNode = createNode();
    newNode->i = 0;
    newNode->id = id;

    if (list->bottom == NULL || list->size < 1)
    {
        list->bottom = newNode;
        list->top = newNode;
    }
    else 
    {
        list->bottom->next = newNode;
        newNode->prev = list->bottom;
        list->bottom = newNode;
    }

    Node * it = list->bottom->prev;

    while (it != NULL)
    {
        it->i++;
        it = it->prev;
    }
    list->size++;
}

int dequeue(List * list)
{
    if (
        list == NULL || 
        list->bottom == NULL || 
        list->size < 1
    )
        return NULL;

    Node * oldBottom = list->bottom;
    int val = oldBottom->id;
    list->bottom = oldBottom->prev;

    if (list->bottom != NULL)
        list->bottom->next = NULL;
    else
        list->top = NULL;

    list->size--;

    Node * it = list->bottom;
    while (it != NULL)
    {
        it->i--;
        it = it->prev;
    }

    free(oldBottom);
    return val;
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

    while (it != NULL && list->size > 0)
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