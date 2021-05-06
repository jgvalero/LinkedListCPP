#pragma once
#include <iostream>
#include <string>
using namespace std;

template<typename T>
class Node {
    private:
    T data;
    Node<T>* next;

    public:
    // Constructor
    Node();
    // Destructor
    ~Node();

    // Getters
    T getData();
    Node<T>* getNext();

    // Setters
    void setData(T someData);
    void setNext(Node<T>* someNext);
};

// ---------- NODE CLASS ---------- //
// Constructor
template<typename T>
Node<T>::Node() {
    data = 0;
    next = NULL;
}
// Destructor
template<typename T>
Node<T>::~Node() {
    cout << "Node deleted" << endl;
}

// Getters
template<typename T>
T Node<T>::getData() {
    return data;
}
template<typename T>
Node<T>* Node<T>::getNext() {
    return next;
}

// Setters
template<typename T>
void Node<T>::setData(T someData) {
    data = someData;
}
template<typename T>
void Node<T>::setNext(Node<T>* someNext) {
    next = someNext;
}

template<typename T>
class LinkedList {
    private:
    Node<T>* head;
    Node<T>* curr;
    Node<T>* temp;

    public:
    // Constructor
    LinkedList();
    // Destructor
    ~LinkedList();
    
    // Functions
    void AddToFront(T data);              // 1
    void AddToEnd(T data);                // 2
    bool AddAtIndex(T data, int index);   // 3
    T RemoveFromFront();                  // 4
    T RemoveFromEnd();                    // 5
    void RemoveTheFirst(T data);          // 6
    void RemoveAllOf(T data);             // 7
    bool ElementExists(T data);           // 8
    Node<T>* Find(T data);                   // 9
    int IndexOf(T data);                  // 10
    T RetrieveFront();                    // 11
    T RetrieveEnd();                      // 12
    T Retrieve(int index);                // 13
    void PrintList();                       // 14
    void Empty();                           // 15
    int Length();                           // 16
};

// ---------- LINKEDLIST CLASS ---------- //
// Constructor
template<typename T>
LinkedList<T>::LinkedList() {
    head = NULL;
    curr = NULL;
    temp = NULL;
}
// Destructor
template<typename T>
LinkedList<T>::~LinkedList() {
    cout << "List Deleted" << endl;
}

// ----- ADDING NOTES ----- //
// Add node to the front of the list
template<typename T>
void LinkedList<T>::AddToFront(T data) {
    Node<T>* newNode = new Node<T>;
    newNode->setData(data);
    newNode->setNext(head);
    head = newNode;
}
// Add node to the end of the list
template<typename T>
void LinkedList<T>::AddToEnd(T data) {
    Node<T>* n = new Node<T>;
    n->setNext(NULL);
    n->setData(data);

    // If head isnt null, traverse, otherwise set head to node
    if(head != NULL) {
        curr = head;
        while (curr->getNext() != NULL) {
            curr = curr->getNext();
        }
        curr->setNext(n);
    }
    else {
        head = n;
    }
}
// Add node at selected index
template<typename T>
bool LinkedList<T>::AddAtIndex(T data, int index) {
    Node<T>* n = new Node<T>;
    n->setData(data);
    n->setNext(head);
    temp = head;
    curr = head;

    // If index 0 is chosen, use AddToFront function
    if (index == 0) {
        AddToFront(data);
        return true;
    }
    // Traverse through list until index or out of bounds
    else {
        for (int i = 1; i <= index; i ++) {
            temp = curr;
            curr = curr->getNext();
            if (curr == NULL) {
                cout << index << " is out of bounds" << endl;
                return false;
            }
        }
        temp->setNext(n);
        n->setNext(curr);
        return true;
    }
}

// ----- REMOVING NODES ----- //
// Remove node from the front of the list
template<typename T>
T LinkedList<T>::RemoveFromFront() {
    // Check if list is empty
    if (head == NULL) {
        cout << "The linked list is empty" << endl;
        return -1;
    }
    else {
        T data = head->getData();
        head = head->getNext();
        return data;
    }
}
// Remove node from the end of the list
template<typename T>
T LinkedList<T>::RemoveFromEnd() {
    temp = head;
    curr = head;
    // Check if list is empty
    if (head == NULL) {
        cout << "The linked list is empty" << endl;
        return -1;
    }
    // If only 1 node, use RemoveFromFront function
    else if (head->getNext() == NULL) {
        return RemoveFromFront();
    }
    // Traverse all the way to end
    else {
        while (curr->getNext() != NULL) {
            temp = curr;
            curr = curr->getNext();
        }
        temp->setNext(NULL);
        T data = curr->getData();
        delete curr;
        return data;
    }
}
// Remove the first node of a given data
template<typename T>
void LinkedList<T>::RemoveTheFirst(T data) {
    Node<T>* del = NULL;
    temp = head;
    curr = head;
    // If index found is at 0, use RemoveFromFront function
    if (IndexOf(data) == 0) {
        RemoveFromFront();
    }
    // Traverse list until data found
    while (curr != NULL && curr->getData() != data) {
        temp = curr;
        curr = curr->getNext();
    }
    // If list is traversed without finding data
    if(curr == NULL) {
        //cout << data << " was not in the list" << endl;
        delete del;
    }
    // Delete node
    else {
        del = curr;
        curr = curr->getNext();
        temp->setNext(curr);
        delete del;
        //cout << "The value " << data << " was deteted" << endl;
    }
}
// Remove all of a given data
template<typename T>
void LinkedList<T>::RemoveAllOf(T data) {
    Node<T>* del = NULL;
    temp = head;
    curr = head;
    // If index found is at 0, use RemoveFromFront function
    if (IndexOf(data) == 0) {
        RemoveFromFront();
    }
    // Traverse list until data found
    while (curr != NULL && curr->getData() != data) {
        temp = curr;
        curr = curr->getNext();
    }
    // If list is traversed without finding data
    if(curr == NULL) {
        //cout << data << " was not in the list" << endl;
        delete del;
    }
    // Delete node and go recursively
    else {
        del = curr;
        curr = curr->getNext();
        temp->setNext(curr);
        delete del;
        //cout << "The value " << data << " was deteted" << endl;
        RemoveAllOf(data);
    }
}

// ----- FINDING NODES ----- //
// Check if a node exists
template<typename T>
bool LinkedList<T>::ElementExists(T data) {
    temp = head;
    curr = head;
    // Traverse list until data is found returning true or false
    while (curr != NULL && curr->getData() != data) {
        temp = curr;
        curr = curr->getNext();
    }
    if(curr == NULL) {
        return false;
    }
    else {
        return true;
    }
}
// Find and return node pointer of a given data
template<typename T>
Node<T>* LinkedList<T>::Find(T data) {
    temp = head;
    curr = head;
    // Traverse list until data found or at end (returns NULL if no data found)
    while (curr != NULL && curr->getData() != data) {
        temp = curr;
        curr = curr->getNext();
    }
    return curr;
}
// Find and return index of a given data
template<typename T>
int LinkedList<T>::IndexOf(T data) {
    temp = head;
    curr = head;
    int counter = 0;
    // Traverse list, adding to counter
    while (curr != NULL && curr->getData() != data) {
        temp = curr;
        curr = curr->getNext();
        counter++;
    }
    if(curr == NULL) {
        return -1;
    }
    else {
        return counter;
    }
}

// ----- RETRIEVING NODES ----- //
// Return data of the front of the linked list
template<typename T>
T LinkedList<T>::RetrieveFront() {
    if (head == NULL) {
        return -1;
    }
    else {
        return head->getData();
    }
}
// Return data of the end of the linked list
template<typename T>
T LinkedList<T>::RetrieveEnd() {
    temp = head;
    curr = head;
    if (head == NULL) {
        return -1;
    }
    else {
        // Traverse to end of list
        while (curr != NULL) {
            temp = curr;
            curr = curr->getNext();
        }
        return temp->getData();
    }
}
// Return the data of a given index
template<typename T>
T LinkedList<T>::Retrieve(int index) {
    temp = head;
    curr = head;
    if (index == 0) {
        return RetrieveFront();
    }
    // Traverse to given index
    else {
        for (int i = 1; i <= index; i ++) {
            temp = curr;
            curr = curr->getNext();
            if (curr == NULL) {
                cout << index << " is out of bounds" << endl;
                return -1;
            }
        }
        return curr->getData();
    }
}

// ----- OTHER ----- //
// Print entire list
template<typename T>
void LinkedList<T>::PrintList() {
    curr = head;
    while(curr != NULL) {
        cout << curr->getData() << "\t";
        curr = curr->getNext();
    }
    cout << endl;
}
// Delete all nodes
template<typename T>
void LinkedList<T>::Empty() {
    temp = head;
    curr = NULL;
    while(temp != NULL) {
        curr = temp->getNext();
        delete temp;
        temp = curr;
    }
    head = NULL;
}
// Find length of a list
template<typename T>
int LinkedList<T>::Length() {
    temp = head;
    curr = head;
    int counter = 0;
    // Traverse through list, adding to counter until end
    while (curr != NULL) {
        temp = curr;
        curr = curr->getNext();
        counter++;
    }
    return counter;
}