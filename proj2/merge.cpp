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
if (l.head == nullptr || l.head->next == nullptr) {
        return;
    }
    l.head = msort(l.head, numeric);
}

// msort is the recursive portion of the algorithm and calls split to divide and calls merge to conquer. It returns
// the new head of the list.
Node *msort(Node *head, bool numeric) {
    Node *left = nullptr;
    Node *right = nullptr;

    if (head == nullptr || head->next == nullptr) {
        return head;
    } else {
        split(head, left, right);
        left = msort(left, numeric);
        right = msort(right, numeric);
        return merge(left, right, numeric);
    }
}

// split is a helper function that splits the singly-linked list in half by using the slow- and fast- pointer technique
// (aka [tortoise and hare]).
void split(Node *head, Node *&left, Node *&right) {
    if (head == nullptr || head->next == nullptr) {
        left = head;
        right = nullptr;
        return;
    }
    Node *slow = head;
    Node *fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    right = slow->next;
    left = head;
    slow->next = nullptr; // break the list into two halves
}

// merge is a helper function that combines both the left and right lists and returns the new head of the list.
Node *merge(Node *left, Node *right, bool numeric) {
    Node dummy;
    dummy.number = 0;
    Node* tail = &dummy;

    // combine both left and right lists
    if (numeric) {
        while (left != nullptr && right != nullptr) {
            if (node_number_compare(left, right)) {
                tail->next = left;
                left = left->next;
                tail = tail->next;
                tail->next = nullptr;
            } else {
                tail->next = right;
                right = right->next;
                tail = tail->next;
                tail->next = nullptr;
            }
        }
        if (left != nullptr) {
            tail->next = left;
        } else if (right != nullptr) {
            tail->next = right;
        }
        return dummy.next;
    } else {
        while (left != nullptr && right != nullptr) {
            if (node_string_compare(left, right)) {     // compare the values of each node and then build a new one 
                tail->next = left;
                left = left->next;
                tail = tail->next;
                tail->next = nullptr;
            } else {
                tail->next = right;
                right = right->next;
                tail = tail->next;
                tail->next = nullptr;
            }
        }
        if (left != nullptr) {
            tail->next = left;
        } else if (right != nullptr) {
            tail->next = right;
        }
        return dummy.next;
    }
}
