//
//  Distance.h
//  Learn
//
//  Created by Yuliia Ivanechko on 10/29/19.
//  Copyright © 2019 Yuliia Ivanechko. All rights reserved.
//

#ifndef Distance_h
#define Distance_h

#include <string>
#include <cstdlib>
#include "Tree.hpp"

using namespace std;

bool isFeet(string str);

class Distance {
    int feet;
    float inches;
public:
    class Inches{
    public:
        string function;
        float inc;
        Inches(){}
        Inches(string f, float i){function = f; inc = i;}
    };
    Distance():feet(0),inches(0.0) {}
    Distance(int f, float i) {
        if (i>=12.0) {
            throw Inches("constructor", i);
        }
        feet = f;
        inches = i;
    }
    Distance(float santimetres) {
        float inch = santimetres / 2.54;
        feet = static_cast<int>(inch/12);
        inches = inch - feet*12;
    }
    void Display() { cout << feet << "\'-" << inches << '\"';}
    void Getdistance();
    friend float operator * (Distance , Distance );
    friend ostream& operator<< (ostream& o, Distance& d);
    friend istream& operator>> (istream& i, Distance& d);
};
float operator * (Distance d1, Distance d2) {
    
    float result =(d1.feet*12 +d1.inches) * (d2.feet*12 +d2.inches);
    return result;
}

void Distance::Getdistance(){
   
        cout<<"Enter feet: ";
      
        cin>>feet;
        
        cout<<"Enter inches: ";
        
        cin>>inches;
      if (inches>=12.0) {
            throw Inches();
        }
}

ostream& operator<< (ostream& o, Distance& d) {
       o<<d.feet<<"\'-"<<d.inches<<'\"';
       return o;
}
istream& operator>> (istream& i, Distance& d) {
    char dummy;
    i>>d.feet>>dummy>>d.inches>>dummy;
    return i;
}


#endif /* Distance_h */
