//
// Created by User on 9/12/2024.
//

#include "stack.h"
#include <stdlib.h>



static Stack* s = NULL; /* will store current stack */

void _push_internal(void* data) {
    if (_IS_NULL_(s))  return;

    Node* n = new_node(data);
    if (_IS_NULL_(n))  return;

    insert_node_first()

}

void* _pop_internal() {
    if (_IS_NULL_OR_EMPTY(s)) return NULL;

    void* data = remove_first_node(&s->top)

    free(temp);
    return data;
}

void* _peek_internal() {
    if (s->size == 0) return NULL;

    return s->top->data;
}

void _destroy_internal() {
    while (s->size > 0) {
        _pop_internal();
    }
}


Stack* new_stack() {
    if (!_IS_NULL_(s)) {
        _destroy_internal();
    }
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (_IS_NULL_(stack)) return NULL;

    s = stack;

    stack->top = NULL;
    stack->size = 0;
    stack->push = _push_internal;
    stack->pop = _pop_internal;
    stack->peek = _peek_internal;
    stack->destroy = _destroy_internal;

    return stack;
}

int main() {
    Stack* stack = new_stack();

    char* first = "alex";
    char* last = "carney";

    stack->push(first);
    stack->push(last);

    while (stack->size >= 0) {
        puts(stack->pop());
    }


}