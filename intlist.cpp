// intlist.cpp
// Implements class IntList
// YOUR NAME(S), AND DATE Tagore Zhao, 29th, April

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    //IMPLEMENT THIS
    Node *n = source.first;
    while (n) {
        append(n->info);
        n = n->next;
    }

}

// destructor deletes all nodes
IntList::~IntList() {
    //IMPLEMENT THIS
    for (int i=0; i < count(); i++){
        Node *n = first;
        while (n){
            n = n->next;
        }
        delete n;
    }

}


// return sum of values in list
int IntList::sum() const {
    int m = 0;
    Node *n = first;
    while(n){
        m += n->info;
        n = n->next;
    }
    return m; // REPLACE THIS NON-SOLUTION
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node *n = first;
    while (n) {
        if (value == n->info){
            return true;
        }
        n = n->next;
    }
    return false; // REPLACE THIS NON-SOLUTION
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    Node *n = first;
    Node *m = first;
    if (first != 0){
        while (n) {
            if (n->info > m->info){
                m = n;
            }
            n = n->next;
        }
    }
    else{
        return 0;
    }
    return m->info; // REPLACE THIS NON-SOLUTION
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if (first == 0){
        return 0.000;
    }
    return sum()/(count()+0.0); // REPLACE THIS NON-SOLUTION
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
    // IMPLEMENT
    Node* temp = first;
    first = new Node;
    first->info = value;
    first->next = temp;
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    //IMPLEMENT
     for (int i=0; i < count(); i++){
        Node *n = first;
        while (n->next){
            n = n->next;
        }
        delete n;
    }
    this->first = 0;
    Node* n = first;
    for (int i=0; i<source.count(); i++ ){
        append(n->info);
        n = n->next;
    }
    return *this;
}



// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) { }


// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}
