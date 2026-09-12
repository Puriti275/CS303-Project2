// stl.cpp

#include "volsort.h"

#include <algorithm>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// C++ Style comparison function
bool node_number_compare(const Node *a, const Node *b) {
    // true for Node a, false for Node b

    if (a->number >= b->number) {
        return true;
    }
    else {
        return false;
    }
}

bool node_string_compare(const Node *a, const Node *b) {
    int num_a = stoi(a->string);
    int num_b = stoi(b->string);

    // true for Node a, false for Node b
    if (num_a >= num_b) {
        return true;
    }
    else {
        return false;
    }
}

void stl_sort(List &l, bool numeric) {

    Node* current = l.head;
    vector<string> string_container;

    // populate vector with sorted numbers
    while (current->next != nullptr) {
        string_container.push_back(current->string);
        current = current->next;
    }

    sort(string_container.begin(), string_container.end());

    List list;

    for (int i = 0; i < string_container.size(); i++) {
        string element = string_container[i];
        list.push_front(element);
    }

    // l = &list;
}

