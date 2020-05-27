//
//  Array.h
//  Learn
//
//  Created by Yuliia Ivanechko on 10/30/19.
//  Copyright © 2019 Yuliia Ivanechko. All rights reserved.
//

#ifndef Array_h
#define Array_h
template <class T>
class Array {
    T* ptr;
    int size;
public:
    class exc {
    public: int number;
        exc(int index){
            number = index;
        }};
    Array<T>(int n) {
        size = n;
        ptr = new T[size];
        ptr[size] = {};
    }
    Array<T>() {
        ptr = nullptr;
        size = 0;
    }
    Array<T>(Array<T>& a) {
        size = a.size;
        ptr = new T[size];
        for (int i = 0; i<a.size; i++) {
               ptr[i] = a[i];
    }
}
    
    Array<T>& operator = (Array<T>& a) {
        size = a.size;
        ptr = new T[size];
        for (int i = 0; i<a.size; i++) {
               ptr[i] = a[i];
           }
        return *this;
    }
    
    
    ~Array<T>() {delete [] ptr;}
    
    T& operator[] (int n) {
        if(n>=size|| n<0) {
            throw exc(n);
        }
        return ptr[n];
    }
    
};
#endif /* Array_h */
