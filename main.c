#include "src/list.h"


int main(int argc, char const *argv[])
{
    List * list = l_newList();

    l_push(list, "Alan");
    l_push(list, "Brock");
    l_push(list, "Jake");
    l_push(list, "Paul");
    l_push(list, "Karl W.");
    l_push(list, "Zed");

    l_insertAt(list, "SA44", list->size - 1);
    l_insertAt(list, "Test", list->size - 1);
    l_insertAt(list, "ABC", list->size - 1);

    l_insertAt(list, "TWO 2", 2);

    l_print(list, 't');

    l_dequeue(list);
    l_dequeue(list);
    l_dequeue(list);
    l_dequeue(list);

    l_pop(list);
    l_pop(list);

    

    l_print(list, 't');
    
    return 0;
}
