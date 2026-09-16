// stl.cpp
// **WILL ADD MORE COMMENTS**
// Resources used: Maggie, C++ reference, slideshow pictures from lab
// https://en.cppreference.com/w/cpp/algorithm/sort
// https://web.eecs.utk.edu/~semrich/cs303-26/assignments/proj02.html

#include "volsort.h"

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;



void stl_sort(List &l, bool numeric) {

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

    // #2 on the STL slide picture
    if(numeric){
        sort(nodes.begin(), nodes.end(), node_number_compare);
    } else {
        sort(nodes.begin(), nodes.end(), node_string_compare);
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

