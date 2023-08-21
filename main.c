#include "src/list.h"


int main(int argc, char const *argv[])
{
    List * list = newList();

    print(list);

    push(list, 203);
    push(list, 50);
    push(list, 30);
    push(list, 22);
    push(list, 4);
    

    print(list);

    dequeue(list);
    dequeue(list);

    print(list);
    
    return 0;
}
