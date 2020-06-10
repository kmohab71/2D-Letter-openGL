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
    //struct for the middle points to make every object relative to them.
    float x;
    float y;
}middle;
middle mid;
//initial rotating angle
int angle = 5;
//rotate flag 1 to rotate and 0 to stop
int rotate = 1;
void init()
{
    //initializing the view
    glClearColor (1.0, 1.0, 1.0, 0.0);
    glMatrixMode (GL_PROJECTION);        //Viewport
    //make the camera view perdendicular to xy-axis
    gluOrtho2D( 0.0,680,0.0,400.0);

}

void display()
{
    //glearing the GPU buffer and setting the background color to white
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 0.0, 0.0);
    glFlush ();
}
void drawLetter()
{
    //draw the letter K as three polygons
    //first polygon is the 90 degree rectangle with width of 20 and height of 255
    glBegin(GL_POLYGON);
    glColor3f( 1.0, 0.0, 0.0 );
    glVertex2f(  mid.x-40.0, mid.y-127.5 );
    glVertex2f(  mid.x-40.0, mid.y+127.5 );
    glVertex2f(  mid.x-20.0, mid.y+127.5 );
    glVertex2f(  mid.x-20.0, mid.y-127.5 );
    glEnd();

    //second polygon is the 45 degree rectangle starting from the middle of the first polygon
    glBegin(GL_POLYGON);
    glColor3f(   1.0,  0.0, 0.0 );
    glVertex2f(  mid.x-20.0, mid.y+17.5  );
    glVertex2f(  mid.x+20.0, mid.y+127.5 );
    glVertex2f(  mid.x+40.0, mid.y+127.5 );
    glVertex2f(  mid.x-20.0, mid.y-3.5   );
    glEnd();
    //third polygon is the -45 degree rectangle starting from the middle of the first polygon
    glBegin(GL_POLYGON);
    glColor3f(   1.0,  0.0, 0.0 );
    glVertex2f(  mid.x-20.0, mid.y-17.5  );
    glVertex2f(  mid.x+20.0, mid.y-127.5 );
    glVertex2f(  mid.x+40.0, mid.y-127.5 );
    glVertex2f(  mid.x-20.0, mid.y+3.5   );
    glEnd();

    glFlush ();
}
void Reshapefunc()
{
    //the rotating function
    //first the center of the figure is moved to the origin
    glTranslatef(mid.x, mid.y, 1);
    glPushMatrix();
    //then the rotation happens
    glRotatef(angle, 0, 0, 1);
    glPushMatrix();
    //then the figure is moved to its original coordinats
    glTranslatef(-mid.x, -mid.y, -1);
    glFlush ();
}
void Mousefun(int btn, int state, int x, int y)
{
    //controlling the rotation flag using the left and right bottons
    
    if(btn==GLUT_RIGHT_BUTTON)
    {
        //stop rotating in the right button is pressed.
        rotate = 0;
    }
    if(btn==GLUT_LEFT_BUTTON)
    {
        //start rotating if the left button is pressed
        rotate = 1;
    }
}
void Idlefunc()
{
    //the function that continually render the letter.
    drawLetter();
    if (rotate == 1)
    {
        //rotate the letter if the rotating flag is 1.
        Reshapefunc();
        glutPostRedisplay();
    }
}
int main(int argc, char** argv)
{
    //set the midpoints
    mid.x=205.0;
    mid.y=207.5;
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (600, 300);
    glutInitWindowPosition (100, 100);
    glutCreateWindow("2D K");
    glutDisplayFunc(display);
    glutReshapeFunc(Reshapefunc);
    glutMouseFunc(Mousefun);
    glutIdleFunc(Idlefunc);
    init ();
    glutMainLoop();
    return 0;
}
