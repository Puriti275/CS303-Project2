#include "volsort.h"

List::List() : head(nullptr), size(0) {}

List::~List() {
    Node *current = head;
    while (current != nullptr) {
        Node *next = current->next;
        delete current;
        current = next;
    }
}

void List::push_front(const std::string &s) {
    Node *node = new Node;
    node->string = s;
    node->number = stoi(s);
    node->next = head;
    head = node;
    size += 1;
}

