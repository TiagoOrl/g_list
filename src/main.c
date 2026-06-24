#include "./list/list.h"


int main(int argc, char const *argv[])
{
    list list = l_new();

    l_push(&list, "Alan", sizeof(char), 5);
    l_push(&list, "Brock", sizeof(char), 6);
    l_push(&list, "Jake", sizeof(char), 5);
    l_push(&list, "Paul", sizeof(char), 5);
    l_push(&list, "Karl W.", sizeof(char), 8);
    l_push(&list, "Zed", sizeof(char), 4);

    l_print(list, 't');

    l_remove_at(&list, 2);
    l_insert_at(&list, "JEFFF", sizeof(char), 0, 6);

    l_print(list, 't');

    l_free_list(&list);

    
    return 0;
}
