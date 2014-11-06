#ifndef TEMPLATE_STACK_CLASS_H
#define TEMPLATE_STACK_CLASS_H

#include <iostream>
#include <string>
#include <cstdlib>

class Stack
{
    bool arr[4];
    int top;
public:
    Stack()
    {
        top = -1;
        for(int i = 0; i < 4; i++)
        {
            arr[i] = NULL;
        }
    }

    inline void push(bool x);

    inline int pop();

    inline bool is_empty();

    inline bool is_full();

    inline bool not_empty();
};

#endif // TEMPLATE_STACK_CLASS_H
