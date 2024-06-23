// Bresenham's line drawing
#include<math.h>
#include<GL/glut.h>

void Bresen(int x1, int y1, int x2, int y2) {
    glPointSize(20);
    glBegin(GL_POINTS);
    glColor3f(1, 1, 1);
    int dx = x2 - x1;
    int dy = y2 - y1;
    int p = 2 * dy - dx;
    int inc = 2 * dy;
    int dec = 2 * dy - 2 * dx;
    int x, y, xend;
    if (y1 < y2) {
        x = x1;
        y = y1;
        xend = x2;
    }
    else {
        x = x2;
        y = y2;
        xend = x1;
    }
    glVertex2i(x, y);
    while (x < xend) {
        x += 1;
        if (p >= 0) {
            p += dec;
            y += 1;
        }
        else {
            p += inc;
        }
        glVertex2i(x, y);
    }
    glEnd();
    glFlush();
}

void disp2() {
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    Bresen(-9, -1, 9, 3);
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(10, 10);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Bresen");
    gluOrtho2D(-10, 10, -10, 10);
    glutDisplayFunc(disp2);
    glutMainLoop();
    return 0;
}
