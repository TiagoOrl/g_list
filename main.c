#include "src/list.h"


int main(int argc, char const *argv[])
{
    List * list = l_newList();

    l_push(list, "tiago");
    l_push(list, "1234");
    l_push(list, "mid");
    l_push(list, "Alamn z");
    l_push(list, "Barn");
    l_push(list, "Romeo T.");
    l_push(list, "Raff");

    l_removeVal(list, "mid");
    l_removeVal(list, "Raff");
    l_removeVal(list, "Romeo T.");
    l_removeVal(list, "Barn");

    l_print(list, 'b');
    
    return 0;
}
