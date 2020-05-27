//
//  arr_func.h
//  Learn
//
//  Created by Yuliia Ivanechko on 08.11.2019.
//  Copyright © 2019 Yuliia Ivanechko. All rights reserved.
//

#ifndef arr_func_h
#define arr_func_h

#ifdef __cplusplus
extern "C" {
#endif

void arr_modify(int* arr, int multiple = 10, int size = 3) {
    arr = new int [size];
    for(int i = 0; i < size; i++) {
        arr[i] = (i+1) * multiple;
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}

#ifdef __cplusplus
}

#endif
#endif /* arr_func_h */
