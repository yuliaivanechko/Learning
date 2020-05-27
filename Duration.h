//
//  Duration.h
//  Learn
//
//  Created by Yuliia Ivanechko on 08.05.2020.
//  Copyright © 2020 Yuliia Ivanechko. All rights reserved.
//

#ifndef Duration_h
#define Duration_h
#include <chrono>

class Duration {
private:
    std::chrono::time_point<std::chrono::steady_clock> begin, end;
    std::chrono::duration<float> duration;
public:
    Duration() {
        begin = std::chrono::high_resolution_clock::now();
    }
    ~Duration() {
        end = std::chrono::high_resolution_clock::now();
        duration = end - begin;
        cout<<"Duration is "<<duration.count()<<endl;
    }
    
};

#endif /* Duration_h */
