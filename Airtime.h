//
//  Header.h
//  Learn
//
//  Created by Yuliia Ivanechko on 11.02.2020.
//  Copyright © 2020 Yuliia Ivanechko. All rights reserved.
//

#ifndef Header_h
#define Header_h

class Airtime {
    private:
        int hours;
        int minutes;
    public:
    Airtime():hours(0), minutes(0) {}
    Airtime(int h, int m):hours(h),minutes(m){}
    void Display() const {
        cout<<hours<<" : "<<minutes<<endl;
    }
    void Get() {
        cout<<"Enter time: ";
        cin>>hours>>minutes;
    }
    Airtime operator + (const Airtime a) const;
//    bool operator == (const Airtime a) {
//        return (hours == a.hours && minutes == a.minutes);
//    }
//    bool operator != (const Airtime a) {
//        return (*this!=a);
//    }
//    bool operator < (const Airtime a) {
//        return ((hours<a.hours)||((hours==a.hours)&&(minutes<a.minutes)));
//    }
//    bool operator > (const Airtime a) {
//        return ((hours>a.hours)||((hours==a.hours)&&(minutes>a.minutes)));
//    }
    
};
Airtime Airtime::operator+(const Airtime a)const {
    int m = minutes+a.minutes;
    int h = 0;
    if(m>=60) {
        m-=60;
        h++;
    }
    h+=hours+a.hours;
    return Airtime(h,m);
}

#endif /* Header_h */
