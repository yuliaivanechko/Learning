//
//  Name.h
//  Learn
//
//  Created by Yuliia Ivanechko on 18.11.2019.
//  Copyright © 2019 Yuliia Ivanechko. All rights reserved.
//

#ifndef Name_h
#define Name_h

class Name {
    int number;
    string name;
    string surname;
    string father;
    static fstream file;
public:
   static void write();
   static void read(int num);
    friend ostream& operator<< (ostream& o, Name& n);
    friend istream& operator>> (istream& i, Name& n);
};
fstream Name::file("Name.dat", fstream::in|fstream::out);
ostream& operator<< (ostream& o, Name& n){
    o<<n.number<<endl<<n.name<<" "<<n.father<<" "<<n.surname<<endl;
    return o;
}
istream& operator>> (istream& i, Name& n){
    i>>n.number;
    i>>n.name;
    i>>n.father;
    i>>n.surname;
    return i;
}
void Name::write() {
        Name n;
    char ch = 'y';
    while (ch == 'y') {
    cout<<"Enter number, name, father and surname! ";
    cin>>n;
    file<<n;
        cout<<"continue? y/n"; cin>>ch;
        if(!file) {
            cout<<"Can not write in a file!!!"<<endl;
        }
    }
}

void Name::read(int num) {
        Name n;
           file.seekg(0);
    while (true) {
       
        file>>n;
        if(file.eof()) {
            break;
        }
        if(n.number == num)
        cout<<n;
    }
}
#endif /* Name_h */
