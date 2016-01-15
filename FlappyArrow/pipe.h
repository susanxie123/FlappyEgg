//
//  pipe.h
//  FlappyArrow
//
//  Created by User on 14-2-20.
//  Copyright (c) 2014年 User. All rights reserved.
//

#ifndef __FlappyArrow__pipe__
#define __FlappyArrow__pipe__

#include <iostream>
#include <GLUT/GLUT.h>
using namespace std;

extern int dwidth, dgaphei, wwidth, wheight, speed;

class pipe{
    int width;//default dwidth
    int gapup;//range from mingap to maxgap
    int gaphei;//default dgaphei
    int x;//middle of pipe, start from wwidth
    
public:
    pipe(int gap){width=dwidth; gapup=gap; gaphei=dgaphei; x=wwidth; passed=false;}
    bool passed;//true for passed
    void draw();
    int left(){return x-width/2;}
    int right(){return x+width/2;}
    int up(){return gapup;}
    int down(){return gapup+gaphei;}
    void move(){x-=speed;}
};

#endif /* defined(__FlappyArrow__pipe__) */
