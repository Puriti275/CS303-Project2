#include "volsort.h"

// struct Node {
//     std::string string;
//     int         number;
//     Node       *next;
// };

// struct List {
//     Node       *head;
//     size_t      size;

//     List(); 					// define in list.cpp
//     ~List();					// define in list.cpp

//     void push_front(const std::string &s);	// also define in list.cpp
// };

List::List() {
    Node* head;
    head->next = nullptr;
    head->string = "";
    head->number = 0;
    size = 1;
}

List::~List() {
    Node* current = head;

    while (current->next != nullptr) {
        delete current;
        current = current->next;
    }
}

void List::push_front(const std::string &s) {
    
    // if head doesn't exist
    if (head == nullptr) {
        Node* node = new Node;
        node->string = s;
        node->number = 0;
        node->next = nullptr;

        head = node;
        return;
    }

    Node* current = head;

    while (head->next != nullptr) {
        current = current->next;
    }

    Node* node = new Node;
    node->string = s;
    node->number = 0;

    current->next = node;
    size += 1;
}
