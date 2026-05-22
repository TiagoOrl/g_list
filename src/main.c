#include "./list/list.h"


int main(int argc, char const *argv[])
{
    list llist = l_new();

    l_push(&llist, "Alan", 4);
    l_push(&llist, "Brock", 5);
    l_push(&llist, "Jake", 4);
    l_push(&llist, "Paul", 4);
    l_push(&llist, "Karl W.", 7);
    l_push(&llist, "Zed", 3);

    l_print(llist, 't');

    l_insert_at(&llist, "TWO 2", 3, 5);

    l_print(llist, 't');


    
    return 0;
}
