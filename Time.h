//
//  Time.h
//  Learn
//
//  Created by Yuliia Ivanechko on 18.11.2019.
//  Copyright © 2019 Yuliia Ivanechko. All rights reserved.
//

#ifndef Time_h
#define Time_h
class Time {
private:
    int hour;
    int minute;
    int second;
public:
    void gettime(){
        while(true) {
            hour = 0; minute = 0; second = 0;
            cout<<"Enter hours: ";
            cin.setf(ios::skipws);
            cin.clear();

            cin>>hour;
            if(hour<0 || hour>23){
                cout<<"Wrong hour!"<<endl;
                cin.clear(ios::failbit);
            }
            if(cin.good()){
                cin.ignore(10, '\n');
                break;
            }
            cin.clear();
            cin.ignore(10, '\n');
            cout<<"Wrong hour enter!"<<endl;
        }
        while(true) {
            cout<<"Enter minutes: ";
            cin.unsetf(ios::skipws);
            cin>>minute;
            if(minute<0 || minute>59){
                cout<<"Wrong minute!"<<endl;
                cin.clear(ios::failbit);
            }
            if(cin.good()){
                cin.ignore(10, '\n');
                break;
            }
            cin.clear();
            cin.ignore(10, '\n');
            cout<<"Wrong minute enter!"<<endl;
        }
        while(true) {
            cout<<"Enter seconds: ";
            cin.unsetf(ios::skipws);
            cin>>second;
            if(second<0 || second>59){
                cout<<"Wrong second!"<<endl;
                cin.clear(ios::failbit);
            }
            if(cin.good()){
                cin.ignore(10, '\n');
                break;
            }
            cin.clear();
            cin.ignore(10, '\n');
            cout<<"Wrong second enter!"<<endl;
        }
    }
    void puttime() {
        hour<=9?cout<<"0"<<hour<<":":cout<<hour<<":";
        minute<=9?cout<<"0"<<minute<<":":cout<<minute<<":";
        second<=9?cout<<"0"<<second<<'\n':cout<<second<<'\n';
    }
    
};

#endif /* Time_h */
