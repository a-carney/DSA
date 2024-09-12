#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"

#define _IS_NULL_(s)    (s == NULL)
#define _IS_EMPTY(s)    (s->size = 0)
#define _IS_NULL_OR_EMPTY(s)    (_IS_NULL_(s) || _IS_EMPTY(s))


typedef struct LinkedList LinkedList;
struct LinkedList {
    Node* head;
    Node* tail;
    int size;

    void (*append)(void* data);
    void* (*pop)();
    void* (*peek)();
    void (*destroy)();
};

LinkedList* new_linked_list();

#endif