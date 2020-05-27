//
//  Link_list.h
//  Learn
//
//  Created by Yuliia Ivanechko on 10/30/19.
//  Copyright © 2019 Yuliia Ivanechko. All rights reserved.
//

#ifndef Link_list_h
#define Link_list_h
template <class T>
class List {

private:
    class Node {
    public:
        Node* next;
        T value;
        Node(T data = T(), Node* ptr = nullptr){
            this->next = ptr;
            this->value = data;
        }
    };
public:
    Node* head;
    int size = 0;
    List();
    ~List();
    
    void display();
    void popfront();
    void popback();
    void pushfront(T value);
    void pushback(T value);
    void insert_at(T value, int index);
    void remove_at(int index);
    void clear();
    T& operator[] (int c);
    int Getsize() {
        return size;
    }
};

template <class T>
List<T>::List(){
    head = nullptr;
}

template <class T>
void List<T>::popfront() {
    --size;
    Node* temp = head;
    head = head -> next;
    delete temp;
}

template <class T>
void List<T>::popback() {
    remove_at(size-1);
}

template <class T>
void List<T>::pushfront(T value) {
    head = new Node(value, head);
    ++size;
}

template <class T>
void List<T>::insert_at(T value, int index) {
    
    if(index == 0) {
        pushfront(value);
        return;
    }
    Node* previous = head;
    for(int i = 0; i!=index-1; ++i) {
        previous = previous->next;
    }
    Node* newnode = new Node(value, previous->next);
    previous->next = newnode;
    size++;
}

template <class T>
void List<T>::remove_at(int index) {
    if(index == 0) {
        popfront();
        return;
    }
    Node* current = head;
    Node* prevCurrent = head;
    int i = 0;
       while(i<index) {
           prevCurrent = current;
           current = current->next;
           ++i;
       }
    Node* nextCurrent = current->next;
    delete current;
    prevCurrent->next = nextCurrent;
    --size;
}

template <class T>
void List<T>::pushback(T value) {
    Node* newNode = new Node(value);
    if(!head) {
        head = newNode;
    }
    else {
        Node* current = head;
        while(current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
    ++size;
}

template <class T>
void List<T>::clear() {
    while(size) {
        this->popfront();
    }
}

template <class T>
T& List<T>::operator[](int c){
    Node* current = head;
    int count = 0;
    while (count < c) {
        current = current->next;
        ++count;
    }
    return current->value;
}

template <class T>
void List<T>::display() {
    Node* current = head;
    while(current) {
        cout<<current<<"\t"<<current->value<<"\t"<<current->next<<endl;
        current = current->next;
    }
}

template <class T>
List<T>::~List(){
    this->clear();
}
#endif /* Link_list_h */
