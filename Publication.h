//
//  Publication.h
//  Learn
//
//  Created by Yuliia Ivanechko on 10/29/19.
//  Copyright © 2019 Yuliia Ivanechko. All rights reserved.
//

#ifndef Publication_h
#define Publication_h

#include <iostream>
using namespace std;
enum publication_type {tpublication, tbook, ttape};

class Publication {
protected:
    char* name;
    float price;
    static int count;
    static Publication* vec[];
    
public:
    virtual void getdata(){
        cout<<"Enter name: "; cin>>name;
        cout<<"Enter price: "; cin>>price;
    }
    virtual void putdata(){
        cout<<"Name: "<<name<<endl;
        cout<<"Price: "<<price<<endl;
    }
    virtual publication_type gettype();
    static void add();
    static void display();
    static void read();
    static void write();
    friend ostream& operator << (ostream& o, Publication const& p);
    friend istream& operator >> (istream& i, Publication& p);
};
Publication* Publication::vec[20];

class Book: virtual public Publication {
    int pages;
public:
    void getdata() {
        Publication::getdata();
        cout<<"Enter pages: "; cin>>pages;
    }
    void putdata() {
        Publication::putdata();
        cout<<"Pages: "<<pages<<endl;
    }

};
class Tape : virtual public Publication{
    int minutes;
public:
    void getdata() {
        Publication::getdata();
        cout<<"Enter minutes: "; cin>>minutes;
    }
    void putdata() {
        Publication::putdata();
        cout<<"Minutes: "<<minutes<<endl;
    }

};
publication_type Publication::gettype() {
    if(typeid(*this) == typeid(Publication)) {
        return tpublication;
    } else if (typeid(*this) == typeid(Book)) {
        return tbook;
    } else if (typeid(*this) == typeid(Tape)) {
        return ttape;
    } else {
            cerr<<"Unknown type!!! "<<endl; exit(1);
    }
}
int Publication::count = 0;
void Publication::add() {
    char answer = 'y';
    cout<<"Enter the name of new object: \np - publication\nt - tape\nb - book";
    cin>>answer;
    switch(answer) {
        case 'p' : vec[count] = new Publication; break;
        case 'b' : vec[count] = new Book; break;
        case 't' : vec[count] = new Tape; break;
    }
    vec[count++]->getdata();
}
void Publication::display() {
    for(int i = 0; i<count; i++) {
        cout<<i+1<<endl;
        if (vec[i]->gettype() == tpublication) {
            cout<<"Publication: "<<endl;
        } else if (vec[i]->gettype() == tbook) {
            cout<<"Book: "<<endl;
        } else {
             cout<<"Tape: "<<endl;
        }
        vec[i] -> putdata();
        cout<<endl;
    }
}

void Publication::write() {
    int size;
    ofstream ouf;
    publication_type ptype;
    ouf.open("pub.dat", ios::trunc | ios::binary);
    if(!ouf) {
        cerr<<"Can not open the file"<<endl; exit(1);
    }
    for(int i = 0; i<count; i++) {
        ptype = vec[i]->gettype();
        ouf.write(reinterpret_cast<char*>(&ptype), sizeof(ptype));
        switch(ptype) {
            case tpublication: size = sizeof(Publication); break;
            case tbook : size = sizeof(Book); break;
            case ttape : size = sizeof(Tape); break;
        }
        ouf.write(reinterpret_cast<char*>(vec[i]), size);
        if(!ouf) {
            cerr<<"Can not write in a file!"<<endl; exit(1);
        }
    }
}

void Publication::read() {
    int size;
    ifstream iuf;
    publication_type ptype;
    iuf.open("pub.dat", ios::binary);
    if(!iuf) {
           cerr<<"Can not open the file"<<endl; exit(1);
    }
    int n = 0;
    while(true) {
        iuf.read(reinterpret_cast<char*>(&ptype), sizeof(ptype));
        if(iuf.eof()) {
            break;
        }
     
        switch(ptype) {
            
            case tpublication: vec[n] = new Publication; size = sizeof(Publication); break;
            case tbook : vec[n] = new Book; size = sizeof(Book); break;
            case ttape : vec[n] = new Tape; size = sizeof(Tape); break;
        }
        iuf.read(reinterpret_cast<char*>(vec[n]), size);
        n++;
        if(!iuf) {
            cerr<<"Can not read from a file!"<<endl; exit(1);
        }
    }
}
ostream& operator << (ostream& o, Publication const& p){
    o<<p.name<<" "<<p.price<<endl;
    return o;
}
istream& operator >> (istream& i, Publication& p){
    cout<<"Enter name: ";
    i>>p.name;
    cout<<"Enter price: ";
    i>>p.price;
    
    return i;
}

#endif /* Publication_h */
