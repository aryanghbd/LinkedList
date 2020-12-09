#ifndef LinkedList_hpp
#define LinkedList_hpp
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int data; //This will hold the data part, we also need a pointer to the next node.
    node* next;
};

void printList(node* n) {
    /* We want to print the whole list, this can be done by outputting the data component, then making next = n, this is the iteration.
    1-->2-->3-->NULL.
    */
    cout << "List elements are: ";
    while(n != NULL) {
        cout << n->data << ", ";
        n = n->next;
    }
}

void pushFront(int n, node** headreference) {
    /*How do we want this to work, we need to consider the data aspect of it.
    1-->2-->3-->--4-->NULL
    we want NEW-->1, so we want to instead point to this one as the first one.
    */
    node* newitem = NULL;
    newitem = new node;
    newitem->data = n;
    newitem->next = (*headreference); //This points to the next thing, then we have to change the point..
    (*headreference) = newitem; //After linking, we switch the head.
}

void append(int n, node** ref) {
    /* What I want is to initialise the node, points to null and has a value.

    Then traverse the list until the final one normally, until the last one (so until ref->next = NULL), and then change ref->next to be that new node
    */
    node* last = (*ref);
    node* newitem = new node;
    newitem->data = n;
    newitem->next = NULL;
    while(last->next != NULL) {
        last = last->next;
    }
    last->next = (newitem);
}

void specificAdd(int n, node** ref) {
    /*
    1-->2-->3-->4-->5
    New node, points to reference->next
    1-->2-->NEW-->3-->4-->5    
    */
   node* newitem = new node; //Declare new node
   newitem->data = n; //Input data
   newitem->next = (*ref)->next; //For the new node, the next node is meant to be the one that went after the original node
   (*ref)->next = newitem; //For original node, the next item is now going to be the new addition
    
}

int SearchList(int n, node* ref) {
    int count = 0;
    while(count != n) {
        (ref) = (ref)->next;
        count++;
    }
    return (ref)->data;
}



#endif