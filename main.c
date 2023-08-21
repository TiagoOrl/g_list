#include "src/list.h"


int main(int argc, char const *argv[])
{
    List * list = newList();

    print(list);

    enqueue(list, 203);
    enqueue(list, 481);
    enqueue(list, 66);
    enqueue(list, 120);

    print(list);
    
    return 0;
}
