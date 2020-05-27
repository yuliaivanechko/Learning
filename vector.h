//
//  vector.h
//  Learn
//
//  Created by Yuliia Ivanechko on 14.02.2020.
//  Copyright © 2020 Yuliia Ivanechko. All rights reserved.
//

#ifndef vector_h
#define vector_h
template <class T>
class Vector {
    T* arr;
    Vector<int>* v;
    int n;
public:
    class Range{};
    Vector();
    Vector(int num);
    Vector(const Vector& v);
    void operator = (const Vector<T> &v) ;
    T & operator [] (int num) const;
    void Display();
    ~Vector();
};
template <class T>
Vector<T>::Vector():arr(nullptr), n(0) {}

template <class T>
Vector<T>::Vector(int num) {
    if (num<0) throw Range();
    n = num;
    arr = new T[n];
}
template <class T>
Vector<T>::~Vector() {

    delete [] arr;
    arr = nullptr;
}

template <class T>
Vector<T>::Vector(const Vector<T> & v) {
    n = v.n;
    arr = new T[n];
    for(int i = 0; i!=n; ++i)
        arr[i] = v.arr[i];
}

template <class T>
void Vector<T>::operator=(const Vector<T> &v)  {
    if(n!=v.n) {
        delete [] arr;
        n = v.n;
        arr = new T[n];
        for(int i = 0; i!=n; ++i)
            arr[i] = v.arr[i];
    } else {
    for(int i = 0; i!=n; ++i)
        arr[i] = v.arr[i]; }
}

template <class T>
T & Vector<T>::operator[](int num) const {
    if (num<0) throw Range();
    return arr[num];
}

template<class T>
void Vector<T>::Display() {
    for(int i = 0; i!=n; ++i)
        cout<<arr[i]<<" ";
    cout<<endl;
}

#endif /* vector_h */
