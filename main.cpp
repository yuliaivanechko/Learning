
#include <iostream>
#include <thread>
#include "Distance.h"
#include "Stack.h"
#include <string>
#include <algorithm>
#include <numeric>
#include "Duration.h"
#include <queue>
#include <list>
#include <stack>
#include <chrono>
#include <mutex>

class MyClass {
private: mutex mtx, mtx1;
    recursive_mutex rmx;

public:
    void Print_char1(const char& c) {
        mtx.lock();
        //this_thread::sleep_for(chrono::milliseconds(20));
        mtx1.lock();
        for(size_t i = 0; i!=5; ++i) {
            for(size_t i = 0; i!=10; ++i) {
                cout<<c;
                this_thread::sleep_for(chrono::milliseconds(20));
            }
            cout<<endl;
        }
        mtx1.unlock();
        
        mtx.unlock();
    }
    void Print_char2(const char& c) {
        mtx1.lock();
        //this_thread::sleep_for(chrono::milliseconds(20));
        mtx.lock();
        for(size_t i = 0; i!=5; ++i) {
            for(size_t i = 0; i!=10; ++i) {
                cout<<c;
                this_thread::sleep_for(chrono::milliseconds(20));
            }
            cout<<endl;
        }
        mtx.unlock();
        mtx1.unlock();
    }
    void Recurcively(int a) {
        lock_guard<recursive_mutex> guard(rmx);
        this_thread::sleep_for(chrono::milliseconds(500));
        cout<<a<<" ";
        a--;
        if (a<=0 ) {
            cout<<endl;
            return;
        }
        Recurcively(a);
        
    }
    
};

class Point {
public:
    int x, y;
    Point(int X, int Y) {
        x = X;
        y = Y;
    }
    friend bool operator == (const Point& p1, const Point& p2);
};

bool operator == (const Point& p1, const Point& p2) {
    return p1.x == p2.x&&p1.y == p2.y;
}
int main(int argc, const char * argv[]) {
    Duration d;
    MyClass m;
    thread th(&MyClass::Recurcively, &m, 7);
    thread th1(&MyClass::Recurcively, &m, 7);
    th.join();
    th1.join();
    return 0;
}


