#include "./list/list.h"


int main(int argc, char const *argv[])
{
    list llist = l_new();

    l_push(&llist, "Alan", sizeof(char), 5);
    l_push(&llist, "Brock", sizeof(char), 6);
    l_push(&llist, "Jake", sizeof(char), 5);
    l_push(&llist, "Paul", sizeof(char), 5);
    l_push(&llist, "Karl W.", sizeof(char), 8);
    l_push(&llist, "Zed", sizeof(char), 4);

    // l_print(llist, 't');

    l_insert_at(&llist, "INSERTED 4", sizeof(char), 2, 12);
    l_insert_at(&llist, "INSERTED 4", sizeof(char), 2, 12);

    l_push(&llist, "Alan", sizeof(char), 5);
    l_push(&llist, "Brock", sizeof(char), 6);
    l_push(&llist, "Jake", sizeof(char), 5);
    l_push(&llist, "Paul", sizeof(char), 5);
    l_push(&llist, "Karl W.", sizeof(char), 8);


    l_remove_at(&llist, 4);
    l_remove_at(&llist, 4);
    l_remove_at(&llist, 4);

    l_remove_at(&llist, 0);


    l_print(llist, 't');

    l_free_list(&llist);

    
    return 0;
}
