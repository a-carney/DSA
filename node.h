#ifndef NODE_H
#define NODE_H

#define _IS_NULL_(s)    (s == NULL)
#define _IS_EMPTY(s)    (s->size = 0)
#define _IS_NULL_OR_EMPTY(s)    (_IS_NULL_(s) || _IS_EMPTY(s))

typedef struct Node Node;

struct Node {
    void* data;
    Node* next;
};

Node* new_node(void* data);
void destroy_node(Node* node);
void insert_node_first(Node** head, Node* next);
void insert_node_last(Node** head, Node** tail, Node* next);
void remove_first_node(Node** head, Node** tail);
void remove_all_nodes(Node** head);


#endif

