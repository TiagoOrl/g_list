#include "list.h"


Node * l_createNode(char * data)
{
    Node * node = (Node *)malloc(sizeof(Node));
    node->next = NULL;
    node->prev = NULL;
    node->data = (char *)malloc(strlen(data) * sizeof(char));
    node->i = -1;

    strcpy(node->data, data);

    return node;
}

void l_push(List * list, char * data)
{
    Node * newNode = l_createNode(data);

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

char * l_pop(List * list)
{
    if (list->top == NULL)
        return NULL;
    
    Node * topNode = list->top;
    char * val = (char *)malloc(strlen(list->top->data) * sizeof(char));
    
    strcpy(val, topNode->data);
    l_cleanupNode(topNode);

    list->top = list->top->next;
    if (list->top == NULL)
        list->bottom = NULL;
    else
        list->top->prev = NULL;

    list->size--;
    free(topNode);

    return val;
}

Node * l_getAt(List * list, int i)
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

Node * l_getByVal(List * list, char * data)
{
    Node * it = NULL;

    if (list == NULL)
        return NULL;

    it = list->top;

    while (it != NULL)
    {
        if (strcmp(it->data, data) == 0)
            return it;
        it = it->next;
    }

    return it;
}


void l_removeNode(List * list, Node * found)
{
    if (found == NULL)
        return;


    if (found->prev == NULL && found->next == NULL)
    {
        l_pop(list);
        return;
    }

    // top node
    if (found->prev == NULL)
    {
        l_pop(list);
        return;
    }

    // bottom node
    if (found->next == NULL)
    {
        l_dequeue(list);
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

    l_cleanupNode(found);
    free(found);
    return;
}

void l_removeVal(List * list, char * data)
{
    if (list->size < 1)
        return;

    Node * found = NULL;

    found = l_getByVal(list, data);
    l_removeNode(list, found);
}

void l_removeAt(List * list, int i)
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
        found = l_getAt(list, i);

    l_removeNode(list, found);
}

/**
 * removes from bottom/first position
*/
char * l_dequeue(List * list)
{
    if (
        list == NULL || 
        list->bottom == NULL || 
        list->size < 1
    )
        return NULL;

    Node * oldBottom = list->bottom;
    char * val = (char *)malloc(strlen(oldBottom->data) * sizeof(char));
    strcpy(val, oldBottom->data);
    list->bottom = oldBottom->prev;

    l_cleanupNode(oldBottom);

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

List * l_newList()
{
    List * list = (List *)malloc(sizeof(List));

    list->size = 0;
    list->top = NULL;
    list->bottom = NULL;

    return list;
}
/**
 * prints list
 * t = top to bottom
 * b = bottom to top
*/
void l_print(List * list, char dir)
{

    printf("\nstack size: %d\n", list->size);
    printf("Printing all items: \n\n");

    if (dir == 't')
    {
        Node * it = list->top;

        while (it != NULL && list->size > 0)
        {
            printf("(%i)\tdata: %s", it->i, it->data);
            if (it->prev != NULL)
                printf("\t prev: (%s)\n", it->prev->data);
            else
                printf("\n");
            it = it->next;
        }
    } else 
    {
        Node * it = list->bottom;

        while (it != NULL && list->size > 0)
        {
            printf("(%i)\tdata: %s", it->i, it->data);
            if (it->prev != NULL)
                printf("\t prev: (%s)\n", it->prev->data);
            else
                printf("\n");
            it = it->prev;
        }
    }

    printf("\n");

    if (list->top != NULL)
        printf("top:\t(%s)\n", list->top->data);
    
    if (list->bottom != NULL)
        printf("bottom:\t(%s)\n\n", list->bottom->data);
}

/**
 * free memory from pointers 
 * allocated and set them to NULL
*/
void l_cleanupNode(Node * n)
{
    free(n->data);
    n->data = NULL;
}