//
//  Deque.h
//  Learn
//
//  Created by Yuliia Ivanechko on 16.12.2019.
//  Copyright © 2019 Yuliia Ivanechko. All rights reserved.
//

#ifndef Deque_h
#define Deque_h

const int M = 3;
template <class T>
class Deque {
private:
    int top;
    int bottom;
    static int c;
    T st[M];
public:
    class Full {};
    class Empty {};
    Deque();
    void push(T value);
    T pop ();
};
template <class T>
int Deque<T>::c = 0;

template <class T>
Deque<T>::Deque():top(2), bottom(2) {}

template <class T>
void Deque<T>::push(T value) {
    if(c > M-1){
        throw Full();
    }
    st[top--] = value;
    ++c;
    if (top==-1) {
        bottom = 2;
    }
}

template <class T>
T Deque<T>::pop() {
    if(c == 0) {
        throw Empty();
    }
    if(bottom==0) {
        top = 2;
        bottom = 2;
        c--;
        return st[0];
    }
    else c--;
    return st[bottom--];
}

#endif /* Deque_h */
