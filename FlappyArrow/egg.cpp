//
//  arrow.cpp
//  FlappyArrow
//
//  Created by User on 14-2-20.
//  Copyright (c) 2014年 User. All rights reserved.
//

#include "egg.h"
#include <cmath>
float PI=3.14159;

void egg::draw()
{
    if (y+r!=wheight)//not broken
    {
        glColor3f(1, 1, 0.7);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y);
        for (int i=0; i<=20; i++)
        {
            glVertex2f(x-r*sin(PI/20*i), y-r*cos(PI/20*i));
        }
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y);
        for (int i=0; i<=20; i++)
        {
            glVertex2f(x+2*r*cos(PI/20*i-PI/2), y+r*sin(PI/20*i-PI/2));
        }
        glEnd();
    }
    else//broken
    {
        glColor3f(1, 1, 0.7);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x-r, y);
        for (int i=0; i<=20; i++)
        {
            glVertex2f(x-r+r*cos(PI*3/4+PI/20*i), y-r*sin(PI*3/4+PI/20*i));
        }
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x+r, y);
        for (int i=0; i<=20; i++)
        {
            glVertex2f(x+r+r*cos(PI*5/4+PI/20*i), y-r*sin(PI*5/4+PI/20*i));
        }
        glEnd();
        glColor3f(0.6, 0.8, 1);
        glBegin(GL_TRIANGLES);
        glVertex2f(x-r-r/2, y-r/2); glVertex2f(x-r-r/2, y); glVertex2f(x-r, y);
        glVertex2f(x-r, y); glVertex2f(x-r, y+r/2); glVertex2f(x-r+r/2, y+r/2);
        glVertex2f(x+r+r/2, y-r/2); glVertex2f(x+r+r/2, y); glVertex2f(x+r, y);
        glVertex2f(x+r, y); glVertex2f(x+r, y+r/2); glVertex2f(x+r-r/2, y+r/2);
        glEnd();
        glColor3f(1, 0.9, 0);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y+r/2);
        for (int i=0; i<=30; i++)
        {
            glVertex2f(x+r*2/3*cos(PI*2/30*i), y+r/2+r*2/3*sin(PI*2/30*i));
        }
        glEnd();
    }
}

void egg::drop()
{
    y+=v;
    v+=g;
}

void egg::up()
{
    v=-dupv;
    y+=v;
    v+=g;
}

bool egg::ishit(class pipe p)
{
    if (y<=p.up() || y>=p.down())
        return true;
    if (x+2*r>p.left() && x<p.left())//whether hit corner of pipe, not finished
    {
        
    }
    if (x>=p.left() && x<=p.right() && (y-r<=p.up() || y+r>=p.down()))
        return true;
    return false;
}

void egg::fall()
{
    v=0;
}

void egg::broke()
{
    if (y+r>=wheight)
    {
        start=0;
        y=wheight-r;
        
    }
}

