#include "src/stack.h"


int main(int argc, char const *argv[])
{
    Stack * stack = newStack();

    add(stack, 10);
    add(stack, 12);
    add(stack, 17);
    add(stack, 20);
    add(stack, 300);
    add(stack, 65);

    printf("stack size: %d\n", stack->size);

    printf("poped %d \n", pop(stack));
    printf("poped %d \n", pop(stack));

    printf("stack size: %d\n", stack->size);

    Node * it = stack->top;
    while (it != NULL)
    {
        printf("val: %d\n", it->id);
        it = it->next;
    }
    
    return 0;
}
