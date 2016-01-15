//
//  pipe.cpp
//  FlappyArrow
//
//  Created by User on 14-2-20.
//  Copyright (c) 2014年 User. All rights reserved.
//

#include "pipe.h"

void pipe::draw()
{
    glColor3f(0, 1, 0);
    glRecti(x-width/2, 0, x+width/2, gapup-10);
    glRecti(x-width/2-2, gapup-10, x+width/2+2, gapup);
    glRecti(x-width/2, gapup+gaphei+10, x+width/2, wheight);
    glRecti(x-width/2-2, gapup+gaphei, x+width/2+2, gapup+gaphei+10);
}