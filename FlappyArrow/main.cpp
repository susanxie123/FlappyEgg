//
//  main.cpp
//  FlappyArrow
//
//  Created by User on 14-2-20.
//  Copyright (c) 2014年 User. All rights reserved.
//

int wwidth=400, wheight=480;
int dx=150, dy=240, dr=10, dupv=15, g=2;
float ddir=0;
int dwidth=50, dgaphei=120, speed=5, dgapwid=200, mingap=40, maxgap=320;
bool start=0;
int countt=0, countp=0, counts=0;

#include <iostream>
#include <GLUT/GLUT.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "egg.h"
#include "pipe.h"
using namespace std;

void set2DMode(int width, int height);
void myDisplay(void);
void mymouse(int button,int state,int x,int y);
void onTimer(int n);
void myKeyboard(unsigned char key, int x, int y);

egg E;
vector<class pipe*> pips;

int main(int argc, char * argv[])
{
    srand((int)time(0));
    glutInit(&argc, argv);
    glutInitWindowPosition(150, 150);
    glutInitWindowSize(wwidth, wheight);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("FlappyEgg v1.0");
    glutDisplayFunc(&myDisplay);
    glutMouseFunc(&mymouse);
    glutKeyboardFunc(&myKeyboard);
    glutTimerFunc(50,&onTimer, 0);
    set2DMode(wwidth, wheight);
    
    glutMainLoop();
    
    return 0;
}

//copy from lecture slides:
void set2DMode(int width, int height)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, height, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glDisable(GL_DEPTH_TEST);
}

void myDisplay()
{
    //background
    glClearColor(0.6, 0.8, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    //pipes
    if (countp>0)
    {
        for (long int i=pips.size(); i>0; i--)
        {
            if (pips[i-1]->right()>0)
                pips[i-1]->draw();
            else
                break;
        }
    }
    //egg
    E.draw();
    //scorecount
    string scores= to_string(counts);
    glColor3f(1, 1, 1);
    for (int i=0; i<scores.length(); i++)
    {
        glRasterPos2i(wwidth/2+i*25, wheight/3);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, scores[i]);
    }
    glFlush();
}

void myKeyboard(unsigned char key, int x, int y)
{
    if (key==27)
        exit(0);
    if (key==32)
        start? start=false: start=true;
}

void mymouse(int button, int state, int x, int y)
{
    if (button==GLUT_LEFT_BUTTON && state==GLUT_DOWN && !E.falled)
    {
        E.up();
        E.draw();
        glFlush();
    }
}

void onTimer(int n)
{
    glutTimerFunc(50,&onTimer, 0);
    if (start)
    {
        //egg drops
        E.drop();
        E.draw();
        //whether egg broke
        E.broke();
        //pipes move and whether egg hit and fall, count score, these part together because we need a reverse loop of pipes
        if (countp>0 && !E.falled)
        {
            for (long int i=pips.size(); i>0; i--)
            {
                if (pips[i-1]->left()<=dx+2*dr && pips[i-1]->right()>=dx-dr)
                {
                    if (E.ishit(*pips[i-1]))
                    {
                        E.falled=true;
                        E.fall();
                        break;
                    }
                }
                if (pips[i-1]->right()<dx-dr && pips[i-1]->passed==false)
                {
                    counts++;
                    pips[i-1]->passed=true;
                }
                if (pips[i-1]->right()>0)
                    pips[i-1]->move();
                else
                    break;
            }
        }
        //whether create new pipe
        if (!E.falled)
        {
            if (countt<dgapwid/speed-1)
            countt++;
            else
            {
                countt=0;
                int temp=rand()%(maxgap-mingap)+mingap;
                pips.push_back(new class pipe(temp));
                countp++;
            }
        }
        
    }
    glutPostRedisplay();
}