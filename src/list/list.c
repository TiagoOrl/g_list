#include "list.h"


node * l_create_node(unsigned char * data, size_t size)
{
    node * item = (node* )malloc(sizeof(node));
    size_t truesize = size + 1;
    item->next = NULL;
    item->prev = NULL;
    item->data = calloc(truesize, sizeof(char));
    item->size = truesize;
    item->i = -1;

    strncpy(item->data, data, size);

    item->data[truesize] = '\0';

    return item;
}

void l_push(list *_list, unsigned char * data, size_t size)
{
    node * new_node = l_create_node(data, size);

    new_node->i = _list->size;

    if (_list->top == NULL || _list->size == 0)
    {
        _list->top = new_node;
        _list->bottom = new_node;
    }
    else 
    {
        _list->top->prev = new_node;
        new_node->next = _list->top;
        _list->top = new_node;
    }
    _list->size++;
}

void l_insert_at(list *_list, unsigned char * data, size_t i, size_t size)
{
    if (
        i >= _list->size ||
        i < 0
    )
        return;


    if (_list->size < 1)
    {
        l_push(_list, data, size);
        return;
    }

    node * newNode = l_create_node(data, size);
    node * found = l_get_at(*_list, i);
    node * foundNext = found->next; // null?

    found->next = newNode;
    newNode->prev = found;
    newNode->i = i;

    newNode->next = foundNext;

    if (foundNext != NULL)
        foundNext->prev = newNode;
    else 
        _list->bottom = newNode; // new bottom is newNode
    

    node * it = newNode->prev;
    while (it != NULL)
    {
        it->i++;
        it = it->prev;
    }
    _list->size++;
    return;
}

unsigned char * l_pop(list *list)
{
    if (list->top == NULL)
        return NULL;
    
    node * topNode = list->top;
    unsigned char * val = (unsigned char *)malloc(strlen(list->top->data) * sizeof(char));
    
    strcpy(val, topNode->data);
    l_free_node(topNode);

    list->top = list->top->next;
    if (list->top == NULL)
        list->bottom = NULL;
    else
        list->top->prev = NULL;

    list->size--;
    free(topNode);

    return val;
}

node * l_get_at(list _list, int i)
{    
    node * it = NULL;

    if (i < 0 || _list.size == 0)
        return NULL;

    it = _list.top;

    while (it != NULL)
    {
        if (it->i == i)
            return it;
        it = it->next;
    }

    return it;
}

node * l_get_by_val(list _list, unsigned char * data)
{
    node * it = NULL;

    if (_list.size == 0)
        return NULL;

    it = _list.top;

    while (it != NULL)
    {
        if (strcmp(it->data, data) == 0)
            return it;
        it = it->next;
    }

    return it;
}


void l_remove_node(list* list, node * found)
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

    node * subs = found->prev;
    node * it = subs;

    found->next->prev = subs;
    subs->next = found->next;
    list->size--;

    while (it != NULL)
    {
        it->i--;
        it = it->prev;
    }

    l_free_node(found);
    free(found);
    return;
}

void l_remove_val(list* list, unsigned char * data)
{
    if (list->size < 1 || list == NULL)
        return;

    node * found = NULL;

    found = l_get_by_val(*list, data);
    l_remove_node(list, found);
}

void l_remove_at(list* list, int i)
{

    if (
        list == NULL ||
        list->size < 1 || 
        list->top == NULL || 
        i >= list->size ||
        i < 0
    )
        return;

    node * found = NULL;

    if (i == 0)
        found = list->bottom;
    else if (i == list->size - 1)
        found = list->top;
    else
        found = l_get_at(*list, i);

    l_remove_node(list, found);
}

/**
 * removes from bottom/first position
*/
unsigned char * l_dequeue(list* _list)
{
    if (
        _list == NULL ||
        _list->bottom == NULL || 
        _list->size < 1
    )
        return NULL;

    node * oldBottom = _list->bottom;
    unsigned char * val = (unsigned char *)malloc(strlen(oldBottom->data) * sizeof(char));
    strcpy(val, oldBottom->data);
    _list->bottom = oldBottom->prev;

    l_free_node(oldBottom);

    if (_list->bottom != NULL)
        _list->bottom->next = NULL;
    else
        _list->top = NULL;

    _list->size--;

    node * it = _list->bottom;
    while (it != NULL)
    {
        it->i--;
        it = it->prev;
    }

    free(oldBottom);
    return val;
}

list l_new()
{
    list new_list;

    new_list.size = 0;
    new_list.top = NULL;
    new_list.bottom = NULL;

    return new_list;
}
/**
 * prints list
 * t = top to bottom
 * b = bottom to top
*/
void l_print(list list, char dir)
{

    printf("\nstack size: %d\n", list.size);
    printf("Printing all items: \n\n");

    if (dir == 't')
    {
        node * it = list.top;
        printf("-top-\n");
        while (it != NULL && list.size > 0)
        {
            printf("(%i)\tdata: %s", it->i, it->data);
            if (it->prev != NULL)
                printf("\t prev: (%s)\n", it->prev->data);
            else
                printf("\n");
            it = it->next;
        }
        printf("-bottom-\n");
    } else 
    {
        node * it = list.bottom;

        printf("-bottom-\n");
        while (it != NULL && list.size > 0)
        {
            printf("(%i)\tdata: %s", it->i, it->data);
            if (it->prev != NULL)
                printf("\t prev: (%s)\n", it->prev->data);
            else
                printf("\n");
            it = it->prev;
        }
        printf("-top-\n");
    }

    printf("\n");

    if (list.top != NULL)
        printf("top:\t(%s)\n", list.top->data);
    
    if (list.bottom != NULL)
        printf("bottom:\t(%s)\n\n", list.bottom->data);
}

/**
 * free memory from pointers 
 * allocated and set them to NULL
*/
void l_free_node(node * n)
{
    free(n->data);
    n->data = NULL;
}