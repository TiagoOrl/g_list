#include "./list/list.h"


int main(int argc, char const *argv[])
{
    list list = l_new();

    struct _obj {
        int id;
        char name[50];
    };

    typedef struct _obj obj;

    obj obj1 = {
        .id = 1,
        .name = "tiago"
    };

    obj obj2 = {
        .id = 2,
        .name = "maria"
    };

    obj obj3 = {
        .id = 3,
        .name = "gabriela"
    };

    obj objs[45000];

    l_push(&list, (void*)&obj1, sizeof(obj), sizeof(obj1));
    l_push(&list, (void*)&obj2, sizeof(obj), sizeof(obj2));
    l_push(&list, (void*)&obj3, sizeof(obj), sizeof(obj3));


    node* it = list.top;
    while (it != NULL)
    {
        obj *item = (obj*)it->data;
        printf("id %i; name %s\n",item->id, item->name);
        it = it->next;
    }


    l_free_list(&list);

    
    return 0;
}
