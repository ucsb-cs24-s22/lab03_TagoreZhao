// intlist.cpp
// Implements class IntList
// YOUR NAME(S), AND DATE

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    //IMPLEMENT THIS
    Node *n = source.first;
    first = new Node;
    first->info = n->info;
    first->next = 0;
    Node *m = first;
    if (source.first == 0) { 
        first = 0;
        delete m;
    }
    else {
        while (n->next){
        n = n->next;
        m->next = new Node;
        m->next->info = n->info;
        m->next->next = 0;
        m = m ->next;
        }
    }
}

// destructor deletes all nodes
IntList::~IntList() {
    //IMPLEMENT THIS
    Node* c = first;
    while ( c != 0 ){
        Node* n = c->next;
        delete c;
        c = n;
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
    return m;
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
    return false;
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
    return m->info;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if (first == 0){
        return 0.000;
    }
    return sum()/(count()+0.0);
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
    Node* temp = first;
    first = new Node;
    first->info = value;
    first->next = temp;
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    Node* c = first;
    while ( c != 0 ){
        Node* n = c->next;
        delete c;
        c = n;
    }
    Node *n = source.first;
    first = new Node;
    first->info = n->info;
    first->next = 0;
    Node *m = first;
    if (source.first == 0) { 
        first = 0;
        delete m;
    }
    else {
        while (n->next){
        n = n->next;
        m->next = new Node;
        m->next->info = n->info;
        m->next->next = 0;
        m = m ->next;
        }
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
