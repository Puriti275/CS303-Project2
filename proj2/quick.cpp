// quick.cpp

#include "volsort.h"

#include <iostream>
#include <string>


// quick: custom quicksort - first element as pivot, relink nodes
//     1. quick_sort(LIst &l, bool numeric): wrapper. l.head = qsort(l.head, compare)
//     2. qsort(head, compare): base case is when the head is the nullptr or head->next is the nullptr - otherwise pivot = head, partition the rest, recurse on the left/right, then concatenate on your left_sorted
//     and the pivot_plus_right_sorted
//     3. partition(head, pivot, left, right, compare): walk nodes (excluding pivot) one at a time - compare against pivot and prepend/append each node into either the 'left' or 'right' list by relinking - no new nodes
//     4. concatenate(left, right): walk to the tail of 'left', point its 'next' at 'right''s head, return left's head (or right's head if left is empty)

// Prototypes

Node *qsort(Node *head, bool numeric);
void  partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric);
Node *concatenate(Node *left, Node *right);

// Implementations

// quick_sort(List &l, bool numeric): wrapper. l.head = qsort(l.head, compare)
// quick_sort(List &l, bool numeric): wrapper. l.head = qsort(l.head, compare)
void quick_sort(List &l, bool numeric) {
    l.head = qsort(l.head, numeric);
}

// qsort(head, compare): base case is when the head is the nullptr or head->next is the nullptr - otherwise pivot = head,
// partition the rest, recurse on the left/right, then concatenate on your left_sorted and the pivot_plus_right_sorted
// qsort(head, compare): base case is when the head is the nullptr or head->next is the nullptr - otherwise pivot = head,
// partition the rest, recurse on the left/right, then concatenate on your left_sorted and the pivot_plus_right_sorted
Node *qsort(Node *head, bool numeric) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // find the middle node via slow/fast pointers, and the last node
    Node *slow = head;
    Node *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *mid  = slow;
    Node *last = (fast->next != nullptr) ? fast->next : fast;

    // pull out the three candidate values
    auto lessThan = [&](Node *a, Node *b) {
        return numeric ? (a->number < b->number) : (a->string < b->string);
    };

    // find which of head/mid/last is the median, then swap its data into head
    Node *medianNode;
    if (lessThan(head, mid) != lessThan(head, last)) {
        medianNode = head; // head is between the other two
    } else if (lessThan(mid, head) != lessThan(mid, last)) {
        medianNode = mid;
    } else {
        medianNode = last;
    }

    if (medianNode != head) {
        std::string tmpString = head->string;
        int         tmpNumber = head->number;
        head->string = medianNode->string;
        head->number = medianNode->number;
        medianNode->string = tmpString;
        medianNode->number = tmpNumber;
    }

    Node* pivot = head;
    Node* rest = head->next;
    pivot->next = nullptr;

    Node* left = nullptr;
    Node* right = nullptr;
    partition(rest, pivot, left, right, numeric);

    Node* leftSorted = qsort(left, numeric);
    Node* rightSorted = qsort(right, numeric);

    pivot->next = rightSorted;
    return concatenate(leftSorted, pivot);
}

// partition(head, pivot, left, right, compare): walk nodes (excluding pivot) one at a time
// - compare against pivot and prepend/append each node into either the 'left' or 'right' list by relinking - no new nodes
void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric) {

    left = nullptr;
    right = nullptr;

    Node *current = head;
    while (current != nullptr) {
        Node *next = current->next; // save before relinking, or we lose the rest of the list

        bool belongsLeft = numeric ? node_number_compare(current, pivot) : node_string_compare(current, pivot);

        if (belongsLeft) {
            current->next = left;
            left = current;
        } else {
            current->next = right;
            right = current;
        }

        current = next;
    }
}

// concatenate(left, right): walk to the tail of 'left', point its 'next' at 'right''s head,
// return left's head (or right's head if left is empty)
Node *concatenate(Node *left, Node *right) {
    if (left == nullptr) {
        return right;
    }

    Node* current = left;

    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = right;

    return left;
}
