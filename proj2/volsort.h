// volsort.h

#ifndef VOLSORT_H
#define VOLSORT_H

#include <string>

struct Node {
    std::string string;
    int         number;
    Node       *next;
};

struct List {
    Node       *head;
    size_t      size;

    List(); 					// define in list.cpp
    ~List();					// define in list.cpp

    void push_front(const std::string &s);	// also define in list.cpp
};


// Functions -------------------------------------------------------------------

void stl_sort(List &l, bool numeric);	// define in stl.cpp - sort using std::sort
void qsort_sort(List &l, bool numeric);	// define in qsort.cpp - sort using qsort from cstdlib
void merge_sort(List &l, bool numeric);	// define in merge.cpp - your implementation
void quick_sort(List &l, bool numeric);	// define in quick.cpp - your implementation

// C++ Style comparison function
inline bool node_number_compare(const Node *a, const Node *b) {
    // true for Node b, false for Node a

    if (a->number < b->number) {
        return true;
    }
    else {
        return false;
    }
}

inline bool node_string_compare(const Node *a, const Node *b) {

    // true for Node b, false for Node a
    if (a->string < b->string) {
        return true;
    }
    else {
        return false;
    }
}
#endif
