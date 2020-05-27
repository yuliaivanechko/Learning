//
//  String.h
//  Learn
//
//  Created by Yuliia Ivanechko on 10/31/19.
//  Copyright © 2019 Yuliia Ivanechko. All rights reserved.
//

#ifndef String_h
#define String_h
using namespace std;

int length(const char* str);
void copy(char* dest, const char* src);
void sort(char**r, int n);
void order(char** i, char** j);
void sum_arr (float *p1, float* p2, float* p3, int n);
int compstr(const char* d1, const char* d2);


class String {
private:
    char* str;
public:
    String() {
        str = nullptr;
    }
    String(const char* s) {
        str = new char[length(s)];
        copy(str,s);
    }
    void display() {
       std::cout<<str<<endl;
    }
    void upit() {
        char* p = str;
        int i =0;
        while(*p)
        {
            str[i++] = toupper(*p++);
        }
    }
    ~String() {
        delete [] str;
        str = nullptr;
    }
    friend ostream & operator<< (ostream& os, String& s);
};

int length(const char* str) {
    int l = 0;
    while(*str) {
        *str++;
        l++;
    }
    l++;
    return l;
}

void copy(char* dest, const char* src) {
    while(*src)
    {
        *dest++ = *src++;
    }
    *dest = '\0';
}

void sum_arr (float *p1, float* p2, float* p3, int n)
{
    for(int i = 0; i<n; i++)
    {
        p3[i] = p1[i] + p2[i];
    }
}
    float Average(const float* p,const int c) {
        float a = 0.0;
        for(int i = 0; i<c; i++ )
        {
            a+= p[i];
        }
        return a/c;
    }
void sort(char**r, int n) {
    for(int i = 0; i<n-1; i++) {
        for(int j = i+1; j<n; j++) {
            order(r+i, r+j);
            }
        }
    }

void order(char** i, char** j)
{
    if((**i)>(**j)) {
        char* temp = *i;
        *i = *j;
        *j = temp;
    }
}
int compstr(const char* d1, const char* d2) {
    if(*d1>*d2)
        return -1;
     else if (*d1 == *d2)
         return 0;
     else return 1;
}
ostream & operator<< (ostream& os, String& s) {
    os<<s.str<<" ";
    return os;
}

#endif /* String_h */
