#include "src/list.h"


int main(int argc, char const *argv[])
{
    List * list = l_newList();

    l_push(list, "Alan");
    l_push(list, "Brock");
    l_push(list, "Catherine");
    l_push(list, "Fabian");
    l_push(list, "Haroldo");
    l_push(list, "Jake");
    l_push(list, "Jacob");

    l_dequeue(list);

    l_print(list, 'b');
    
    return 0;
}
