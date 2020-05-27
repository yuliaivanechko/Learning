//
//  Header.h
//  Learn
//
//  Created by Yuliia Ivanechko on 03.03.2020.
//  Copyright © 2020 Yuliia Ivanechko. All rights reserved.
//

#ifndef Image_h
#define Image_h

class Pixel {
private:
    float r;
    float g;
    float b;
public:
    Pixel() : r(0.0f), g(0.0f), b(0.0f){}
    Pixel(float red, float green, float blue) : r(red), g(green), b(blue){}
    string Getinfo() {
        return "Red: \t"+to_string(r)+"\tGreen\t"+to_string(g)+"\tBlue\t"+to_string(b);
    }
};

class Image {
private:
    
   static const int Length = 5;
    Pixel p[Length] {{4.5, 7.4, 1.2}, {4.1, 7.7, 5.6}, {1.3, 5.8, 4.3}, {7.1, 5.2, 6.3}, {8.2, 1.2, 6.3}};
public:
    Image() {}
    void Get_information() {
        for(int i = 0; i<Length; ++i)
            cout<<p[i].Getinfo()<<endl;
    }
    
};



#endif /* Image_h */
