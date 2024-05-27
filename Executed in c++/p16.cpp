// Mesh
#include<GL/glut.h>


void disp1() {
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    for (int i = -50;i < 51;i += 20) {
        glBegin(GL_LINES);
        glVertex2f(-50, i);
        glVertex2f(50, i);
        glVertex2f(i, 50);
        glVertex2f(i, -50);
        glEnd();
        glBegin(GL_LINE_LOOP);
        glVertex2f(-50, -i);
        glVertex2f(i, 50);
        glVertex2f(50, i);
        glVertex2f(-i, -50);
        glEnd();
    }

    glFlush();
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