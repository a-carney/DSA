#include <stdlib.h>
#include "linked_list.h"

static LinkedList* this = NULL;

void _append_internal(void* data) {
    if (this == NULL) return;

    Node* n = new_node(data);
    if (n == NULL)    return;

    insert_node_last(&this->head, &this->tail, n);
    this->size++;
}

void* _pop_internal() {
    if (_IS_NULL_OR_EMPTY(this))   return NULL;

    void* data = remove_first_node(&this->head, &this->tail);
    this->size--;

    return data;
}

void* _peek_internal() {
    if (_IS_NULL_OR_EMPTY(this)) {
        return NULL;
    } else {
        return this->head->data;
    }
}

void _destroy_internal() {
    if (_IS_NULL_(this)) return NULL;

    remove_all_nodes(&this->head);
    this->tail = NULL;
    this->size = 0;

    free(this);
    this = NULL;
}

LinkedList* new_linked_list() {
    if (!_IS_NULL_(this)) _destroy_internal();

    LinkedList* ll = (LinkedList*)malloc(sizeof(LinkedList));
    if (_IS_NULL_(ll)) return NULL;

    this = ll;
    ll->head = NULL;
    ll->tail = NULL;
    ll->size = 0;

    ll->append = _append_internal;
    ll->pop = _pop_internal;
    ll->peek = _peek_internal;
    ll->destroy = _destroy_internal;

    return ll;

}

int main() {
}
