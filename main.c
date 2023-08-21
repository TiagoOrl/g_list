#include "src/list.h"


int main(int argc, char const *argv[])
{
    List * list = newList();

    push(list, 10);
    push(list, 12);
    push(list, 17);
    push(list, 20);
    push(list, 300);
    push(list, 420);
    push(list, 426);

    print(list);

    insertAt(list, list->size - 1, 8451);
    insertAt(list, 2, 44);

    // push(list, 27);
    // push(list, 29);

    print(list);
    
    return 0;
}
