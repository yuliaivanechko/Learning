//
//  Person.h
//  Learn
//
//  Created by Yuliia Ivanechko on 10.02.2020.
//  Copyright © 2020 Yuliia Ivanechko. All rights reserved.
//

#ifndef Person_h
#define Person_h

class Person {
private:
    string firstname;
    string lastname;
    long phonenumber;
public:
    Person():firstname(""), lastname(""),phonenumber(0){}
    Person(string fn, string ln, long pn): firstname(fn), lastname(ln), phonenumber(pn) {}
    void Display() const {
        cout<<firstname<<" "<<lastname<<" "<<phonenumber<<endl;
    }
    friend bool operator <(const Person&, const Person&);
    friend bool operator ==(const Person&, const Person&);
};
bool operator<(const Person& p1, const Person& p2) {
    if (p1.firstname == p2.firstname) {
        return p1.lastname<p2.lastname;
    }
    return(p1.firstname<p2.firstname) ? true : false;
}
bool operator==(const Person& p1, const Person& p2) {
    return(p1.firstname==p2.firstname&&p1.lastname==p2.lastname);
}

class comparePers {
public:   bool operator() (const Person* p, const Person* p1) const {
        return ((*p)<(*p1));
    }
};
class displayPers {
public: void operator() (const Person* p) {
        p->Display();
    }
};


#endif /* Person_h */
