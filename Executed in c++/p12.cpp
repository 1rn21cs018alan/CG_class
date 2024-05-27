// parallelopied
#include<GL/glut.h>

void rect(int x, int y) {
    glBegin(GL_LINE_LOOP);
    glColor3f(1, 1, 1);
    glVertex2f(15 + x, 15 + y);
    glVertex2f(15 + x, 30 + y);
    glVertex2f(45 + x, 30 + y);
    glVertex2f(45 + x, 15 + y);
    glEnd();
    glFlush();
}

void disp1() {
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    for (int i = -50;i < 51;i += 2) {
        rect(i, i);
    }
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(10, 10);
    glutInitWindowSize(700, 700);
    glutCreateWindow("points");
    gluOrtho2D(-200, 200, -200, 200);
    glutDisplayFunc(disp1);
    glutMainLoop();
    return 0;
}