#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <vector>
#include <cmath>
#include <cstdlib>
#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

float angle=5,xpos=-1;
double rand1, rand2, rand3, rand4 = 0;

void idle()
  {

angle+=5;

if(xpos<=1)
xpos+=0.0004;
else
xpos=xpos-2;

glutPostRedisplay();
}

void ban()

{
     glClearColor(1, 1, 1, 0); // white background
     glClear(GL_COLOR_BUFFER_BIT);

     glPushMatrix();
     glTranslatef(xpos,-0.25,0);
     glRotatef(0,0,0,0);
     glBegin(GL_POLYGON);
     glColor3f(0.9, 0.5, 0.3);

     glVertex3f(-0.5, 0.5, 0.5);
     glVertex3f(-rand1, 0.2, 0.5);
     glVertex3f(-rand2, 0.3, 0.5);
     glVertex3f(-rand3, 0.4, 0.5);
     glVertex3f(0, -0.01, 0.5);

     glVertex3f(0, 0.5, 0.5);
     glVertex3f(-rand3, 0.2, 0.5);
     glVertex3f(-rand2, 0.3, 0.5);
     glVertex3f(-rand1, 0.4, 0.5);
     glVertex3f(0, -0.01, 0);

     glVertex3f(0, 0.5, 0);
     glVertex3f(-rand1, 0.2, 0);
     glVertex3f(-rand2, 0.3, 0);
     glVertex3f(-rand3, 0.2, 0);
     glVertex3f(-0.5, -0.01, 0);

     glVertex3f(-0.5, 0.5, 0);
     glVertex3f(-rand3, 0.1, 0);
     glVertex3f(-rand2, 0.2, 0);
     glVertex3f(-rand1, 0.1, 0);
     glVertex3f(-0.5, -0.01, 0.5);

     glEnd();
     if (xpos += 0.0004){
        double randomnum = rand() % 5 + 1;
        if (randomnum > 1)
        {
            rand1 = randomnum;

            // randomnum = 3.4;
            rand2 = randomnum;

            // randomnum = 4;
            rand3 = randomnum;
        }
        else
        {
            rand1 = 1;
            rand2 = 0.2;
            rand3 = 0;
        }
        }
        else{}
     glPopMatrix();

	 glPushMatrix();
     glTranslatef(xpos,0,0);
     glRotatef(angle,0,0,1);


     glColor3f(0,0,0); // black torus
     glScalef(0.1,0.1,0.1);
     glutSolidTorus(0.5, 2.0, 110, 30);
     glColor3f(1,1,1); // white tire pattern
     glutWireTorus(0.25, 2.35, 3, 30);
     glColor3f(1,0,0); // red rims
     glutSolidTorus(0.25, 1.20, 100, 15);
     glutSolidCube(1.5);
     glPopMatrix();


     glutPostRedisplay();
     glFlush();
}
void display()
 {
     ban();
     glutSwapBuffers();
 }

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("ban");

    glutDisplayFunc(display);
    glutIdleFunc(idle);

    glutMainLoop();
}
