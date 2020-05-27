//
//  Money.h
//  Learn
//
//  Created by Yuliia Ivanechko on 10/30/19.
//  Copyright © 2019 Yuliia Ivanechko. All rights reserved.
//

#ifndef Money_h
#define Money_h

#include <math.h>

int length(const char* str);

class bMoney {
    long double money;
public:
    bMoney() : money(0.0) {}
    bMoney(long double d) {
        money = d;
    }
    bMoney(char s[]) {
        int before_dot = 0;
        for(int i = 0; i<length(s); i++) {
            if (s[i] == '.'||s[i]==',') {
                before_dot = i;
                break;
            }
        }
        int multiple = pow(10, before_dot-1);
        for(int i = 0; i<length(s); i++) {
            money += (s[i] - '0')*multiple;
            multiple/=10;
            if (s[i] == '.'||s[i]==','){
                for(int j = i+1, n = 1; j<length(s)-1; j++, n++) {
                   float temp =(static_cast<double>(s[j] - '0')/(pow(10,n)));
                    money+=temp;
                
                }
            }
        }
    }
    friend bMoney operator + (bMoney, bMoney);
    friend bMoney operator - (bMoney, bMoney);
    friend bMoney operator * (long double, bMoney);
    friend bMoney operator / (long double, bMoney);
    friend bMoney round(bMoney);
    friend ostream& operator<< (ostream& o, bMoney& m);
    friend istream& operator>> (istream& i, bMoney& m);
    void Show() {
        cout<<"Money: "<<money<<endl;
    }
};
bMoney operator + (bMoney m1, bMoney m2){
    return bMoney(m1.money + m2.money);
}
bMoney operator - (bMoney m1, bMoney m2){
    return bMoney(m1.money - m2.money);
}
bMoney operator * (long double b, bMoney m2){
    return bMoney(b * m2.money);
}
bMoney operator / (long double b, bMoney m2){
    return bMoney(b / m2.money);
}
bMoney round(bMoney b){
    double intpart = 0, fractpart = 0;
    if (fractpart = modf(b.money, &intpart); fractpart<0.49) {
        b.money-=fractpart;
    } else {b.money-=fractpart;
        b.money++;}
    return bMoney(b.money);
}

ostream& operator<< (ostream& o, bMoney& m){
    o<<"Money: "<<m.money<<endl;
    return o;
}
istream& operator>> (istream& i, bMoney& m){
    i>>m.money;
    return i;
}

#endif /* Money_h */
