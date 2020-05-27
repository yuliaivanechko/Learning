//
//  Stack.h
//  Learn
//
//  Created by Yuliia Ivanechko on 25.11.2019.
//  Copyright © 2019 Yuliia Ivanechko. All rights reserved.
//

#ifndef Stack_h
#define Stack_h
using namespace  std;
const int MAX = 3;
template <class T>
class Stack {
private:
    int top;
    T st[MAX];
public:
    class Full:public exception {};
    class Empty :public runtime_error {
    public: Empty(const char* msg, int f):runtime_error(msg){
        this->n = f;
        cout<<n<<endl;}
        int n;
    };
    Stack();
    void push(T value);
    T pop ();
};

template <class T>
Stack<T>::Stack():top(-1) {}

template <class T>
void Stack<T>::push(T value) {
    st[++top] = value;
    if (top>MAX-1) {
        throw Full();
    }
}

template <class T>
T Stack<T>::pop() {
    if(top<0) {
        throw Empty("Stack is empty!", 5);
    }
    return st[top--];
}

#endif /* Stack_h */
