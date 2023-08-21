#include "src/list.h"


int main(int argc, char const *argv[])
{
    List * list = newList();

    push(list, 10);
    push(list, 20);
    push(list, 30);
    push(list, 41);
    push(list, 56);
    push(list, 60);
    push(list, 71);

    print(list);

    dequeue(list);
    dequeue(list);


    print(list);
    
    return 0;
}
