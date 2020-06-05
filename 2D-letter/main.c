////
////  main.c
////  2D-letter
////
////  Created by Khaled Mohab on 6/4/20.
////  Copyright © 2020 Khaled Mohab. All rights reserved.
////
//
#include <GLUT/glut.h>
#include <stdlib.h>      // LIBRARIES
#include <stdio.h>
#include <math.h>
typedef struct middle
{
    float x;
    float y;
}middle;
middle mid;
int angle = 5;
int rotate = 1;
void init()
{
    glClearColor (1.0, 1.0, 1.0, 0.0);
    glMatrixMode (GL_PROJECTION);        //Viewport
    gluOrtho2D( 0.0,680,0.0,400.0);    //Viewport, i.e., camera position.

}

void display()
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 0.0, 0.0);
    glFlush ();
}
void drawLetter()
{
    glBegin(GL_LINES);
    
    glVertex2f(mid.x-40.0, mid.y-127.5);
    glVertex2f(mid.x-40.0, mid.y+127.5);

    glVertex2f(mid.x-40.0, mid.y+127.5);
    glVertex2f(mid.x-20.0, mid.y+127.5);

    glVertex2f(mid.x-20.0, mid.y+127.5);
    glVertex2f(mid.x-20.0, mid.y+17.5);

    glVertex2f(mid.x-20.0, mid.y+17.5);
    glVertex2f(mid.x+20.0, mid.y+127.5);

    glVertex2f(mid.x+20.0, mid.y+127.5);
    glVertex2f(mid.x+40.0, mid.y+127.5);

    glVertex2f(mid.x+40.0, mid.y+127.5);
    glVertex2f(mid.x, mid.y-2.5);

    glVertex2f(mid.x, mid.y-2.5);
    glVertex2f(mid.x+40.0, mid.y-127.5);

    glVertex2f(mid.x+40.0, mid.y-127.5);
    glVertex2f(mid.x+20.0, mid.y-127.5);

    glVertex2f(mid.x+20.0, mid.y-127.5);
    glVertex2f(mid.x-20.0, mid.y-17.5);

    glVertex2f(mid.x-20.0, mid.y-17.5);
    glVertex2f(mid.x-20.0, mid.y-127.5);

    glVertex2f(mid.x-20.0, mid.y-127.5);
    glVertex2f(mid.x-40.0, mid.y-127.5);
    
    glEnd();

    glFlush ();
}
void Reshapefunc()
{
    glTranslatef(mid.x, mid.y, 1);
    glPushMatrix();
    glRotatef(angle, 0, 0, 1);
    glPushMatrix();
    glTranslatef(-mid.x, -mid.y, -1);
}
void Mousefun(int btn, int state, int x, int y)
{
    if(btn==GLUT_RIGHT_BUTTON)
    {
        rotate = 0;
    }
    if(btn==GLUT_LEFT_BUTTON)
    {
        rotate = 1;
    }
}
void Idlefunc()
{
    drawLetter();
    if (rotate == 1)
    {
        Reshapefunc();
        glutPostRedisplay();
    }
}
int main(int argc, char** argv)
{
    mid.x=205.0;
    mid.y=207.5;
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (600, 300);
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);
    glutDisplayFunc(display);
    glutReshapeFunc(Reshapefunc);
    glutMouseFunc(Mousefun);
    glutIdleFunc(Idlefunc);
    init ();
    glutMainLoop();
    return 0;
}
