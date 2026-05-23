#include "list.h"


node * l_create_node(unsigned char * data, size_t size)
{
    node * item = (node* )malloc(sizeof(node));
    item->next = NULL;
    item->prev = NULL;
    item->data = calloc(size + 1, sizeof(char));
    item->size = size + 1;
    item->i = -1;

    memcpy(item->data, data, size);

    item->data[item->size - 1] = '\0';

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

void l_insert_at(list *_list, unsigned char * data, int pos, size_t size)
{
    if (
        pos >= _list->size ||
        pos < 0
    )
        return;


    if (_list->size < 1)
    {
        l_push(_list, data, size);
        return;
    }

    node * new_node = l_create_node(data, size);
    node * found = l_get_at(*_list, pos);
    node * found_next = found->next; // null?

    found->next = new_node;
    new_node->prev = found;
    new_node->i = pos;

    new_node->next = found_next;

    if (found_next != NULL)
        found_next->prev = new_node;
    else 
        _list->bottom = new_node; // if next node after found is NULL, it means the new node is the BOTTOM node now
    

    node * it = new_node->prev;
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
    
    node * top_node = list->top;
    unsigned char * val = (unsigned char *)calloc(top_node->size, sizeof(char));
    
    memcpy(val, top_node->data, top_node->size);
    

    list->top = list->top->next;
    if (list->top == NULL)
        list->bottom = NULL;
    else
        list->top->prev = NULL;

    list->size--;


    l_free_node(top_node);
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
        if (memcmp(it->data, data, it->size) == 0)
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
        unsigned char * data = l_pop(list);
        free(data);
        return;
    }

    // top node
    if (found->prev == NULL)
    {
        unsigned char * data = l_pop(list);
        free(data);
        return;
    }

    // bottom node
    if (found->next == NULL)
    {
        unsigned char* data = l_dequeue(list);
        free(data);
        return;
    }

    node * upper_n = found->prev;
    node * it = upper_n;

    found->next->prev = upper_n;
    upper_n->next = found->next;
    list->size--;

    while (it != NULL)
    {
        it->i--;
        it = it->prev;
    }

    l_free_node(found);
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

void l_remove_at(list* list, int pos)
{

    if (
        list == NULL ||
        list->size < 1 || 
        list->top == NULL || 
        pos >= list->size ||
        pos < 0
    )
        return;

    node * found = NULL;

    if (pos == 0)
        found = list->bottom;
    else if (pos == list->size - 1)
        found = list->top;
    else
        found = l_get_at(*list, pos);

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

    node * old_bottom = _list->bottom;
    unsigned char * val = (unsigned char *)calloc(old_bottom->size, sizeof(char));
    memcpy(val, old_bottom->data, old_bottom->size);
    _list->bottom = old_bottom->prev;

    

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

    l_free_node(old_bottom);
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
    free(n);
}


void l_free_list(list* l)
{
    node* it = l->top;

    while (it != NULL)
    {
        node* next = it->next;
        free(it->data);
        free(it);
        it = next;
    }

    l->bottom = NULL;
    l->top = NULL;
    l->size = 0;
}   