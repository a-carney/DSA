//
// Created by User on 9/12/2024.
//

#ifndef STACK_H
#define STACK_H


#include "node.h"

typedef struct Stack Stack;

struct Stack {
    Node* top;
    int size;

    void  (*push)(void* data);
    void* (*pop)();
    void* (*peek)();
    void  (*destroy)();
};

Stack* new_stack();

#endif
