// qsort.cpp

#include "volsort.h"

#include <cstdlib>
#include <array>
#include <vector>
#include <iostream>

using namespace std;

int qComparisonInt(const void * a, const void * b) {

       const Node * ia = *(const Node **) a;
       const Node * ib = *(const Node **) b;

       if (ia->number < ib->number) return -1;  // sorts in ascending order
       if (ia->number > ib->number) return 1;
       return 0;                                                                                         
}

int qComparisonStr(const void * a, const void * b) {

       const Node * ia = *(const Node **) a;
       const Node * ib = *(const Node **) b;

       if (ia->string < ib->string) return -1;  // sorts in ascending order
       if (ia->string > ib->string) return 1;
       return 0;                                                                                         
}

void qsort_sort(List &l, bool numeric) {
    
    if (l.head == nullptr){
        return;
    }
    
    Node* current = l.head;
    vector<Node *> nodes;

    // #1 populate vector with sorted numbers
    while (current->next != nullptr) {
        nodes.push_back(current);
        current = current->next;
    }
        nodes.push_back(current); // account for the last node.

    // #2 https://man7.org/linux/man-pages/man3/qsort.3.html
    if(numeric){
        // qsort(&argv[1], argc - 1, sizeof(char *), cmpstringp);
        qsort(&nodes[0], nodes.size(), sizeof(Node *), qComparisonInt);
    } else {
        qsort(&nodes[0], nodes.size(), sizeof(Node *), qComparisonStr);
    }

    // #3 where we walk the vector and fix the pointers
    for (int i = 0; i < nodes.size(); ++i) {
        if(i < nodes.size()-1){
            nodes.at(i)->next = nodes.at(i+1);
        } else {
            nodes.at(i)->next = nullptr;
        }
    }

    //reset the head of the list to the front of our sorted list of nodes
    l.head = nodes[0];
  
}

