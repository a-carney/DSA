#include <stdio.h>

#include "node.h"
#include <stdlib.h>


Node* new_node(void* data) {
    Node *n = (Node *) malloc(sizeof(Node));

    if (n == NULL) return NULL;

    n->data = data;
    n->next = NULL;

    return n;
}

void destroy_node(Node* node) {
    if (node != NULL)   free(node);
}

void insert_node_first(Node** head, Node* next) {
    if (next == NULL)   return;

    next->next = *head;
    *head = next;
}

void insert_node_last(Node** head, Node** tail, Node* next) {
    if (next == NULL)   return;

    (*tail != NULL) ? (*tail)->next = next : *head = next;
    *tail = next;
}

void* remove_first_node(Node** head, Node** tail) {
    if (*head == NULL)  return NULL;
    Node* temp; void* data;

    temp = *head;
    data = temp->data;

    *head = (*head)->next;

    if (*head == NULL) {
        *tail = NULL;
    }

    destroy_node(temp);

    return data;
}

void remove_all_nodes(Node** head) {
    Node *curr = *head;
    while (current != NULL) {
        Node *next = curr->next;
        destroy_node(next);
        curr = next;
    }
    *head = NULL;
}

}



