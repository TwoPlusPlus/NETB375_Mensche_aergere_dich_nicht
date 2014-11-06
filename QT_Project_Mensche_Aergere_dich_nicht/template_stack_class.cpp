#include "template_stack_class.h"

void Stack::push(bool x)
{
    arr[++top] = x;
}
int Stack::pop()
{
    return arr[top--];
}
bool Stack::is_empty()
{
    return (top < 0);
}
bool Stack::is_full()
{
    return (top == 3);
}
bool Stack::not_empty()
{
    return (top >= 0);
}
