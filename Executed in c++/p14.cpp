//moving Text
#include<iostream>
#include<GL/glut.h>
using namespace std;
int cx1 = 50;
int cy1 = 100;
string inp;

void update(int j) {
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);
    glRasterPos2i(cx1, cy1);
    glRasterPos2i(cx1 + 5 * j, cy1);
    for (int i = 0;i < inp.length();i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, inp[i]);
    glFlush();
    if (j > 30)
        glutTimerFunc(100, update, 0);
    else
        glutTimerFunc(100, update, j + 1);
}


void disp() {
    glFlush();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(10, 10);
    glutInitWindowSize(700, 700);
    cout << "Enter String:";
    cin >> inp;
    glutCreateWindow("points");
    gluOrtho2D(0, 200, 0, 200);
    glutDisplayFunc(disp);
    glutTimerFunc(100, update, 0);
    glutMainLoop();
}