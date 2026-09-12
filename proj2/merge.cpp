// merge.cpp

#include "volsort.h"

#include <iostream>

// Prototypes

Node *msort(Node *head, bool numeric);
void  split(Node *head, Node *&left, Node *&right);
Node *merge(Node *left, Node *right, bool numeric);

// Implementations

// merge_sort takes a struct List and whether or not the comparison should be numeric and performs the top-down merge
// sort algorithm. This function serves as a wrapper or helper function for the recursive msort function.
void merge_sort(List &l, bool numeric) {
    // Handle base case

    // Divide into left and right sublists

    // Conquer left and right sublists

    // Combine left and right sublists
}

// msort is the recursive portion of the algorithm and calls split to divide and calls merge to conquer. It returns
// the new head of the list.
Node *msort(Node *head, bool numeric) {
}

// split is a helper function that splits the singly-linked list in half by using the slow- and fast- pointer technique
// (aka [tortoise and hare]).
void split(Node *head, Node *&left, Node *&right) {
}

// merge is a helper function that combines both the left and right lists and returns the new head of the list.
Node *merge(Node *left, Node *right, bool numeric) {
    Node dummy;
    dummy.number = 0;
    Node* tail = &dummy;

    // combine both left and right lists

    // compare the values of each node and then build a new one
    
    
}
