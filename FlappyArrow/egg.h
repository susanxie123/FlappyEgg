//
//  arrow.h
//  FlappyArrow
//
//  Created by User on 14-2-20.
//  Copyright (c) 2014年 User. All rights reserved.
//

#ifndef __FlappyEgg__egg__
#define __FlappyEgg__egg__

#include <iostream>
#include <GLUT/GLUT.h>
#include "pipe.h"
using namespace std;

extern int dx, dy, dr, dupv, g;
extern float ddir;
extern bool start;

class egg{
    int x; //default dx, not change
    int y; //default dy
    int r; //default dr
    int v; //default 0, downward positive, upward negative
public:
    egg(){x=dx; y=dy; r=dr; v=0; falled=false;}
    bool falled;//true for falled
    void draw();
    void up();
    void drop();
    bool ishit(class pipe p);
    void fall();
    void broke();
};

#endif /* defined(__FlappyArrow__arrow__) */
