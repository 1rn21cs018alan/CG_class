// Bresenham's line drawing
#include<math.h>
#include<GL/glut.h>

void Bresen(int x1, int y1, int x2, int y2) {
    glPointSize(2);
    glBegin(GL_POINTS);
    glColor3f(1, 1, 1);
    int dx = x2 - x1;
    int dy = y2 - y1;
    int x, y, xend,octant=1,t;
    

    if (dx >= 0 && dy >= 0) {

        if (dx >= dy) {

            octant = 1;
            x = x1;
            y = y1;
            xend = x2;
        }
        else {

            octant = 2;
            t = dx;
            dx= dy;
            dy = t;
            x = y1;
            y = x1;
            xend = y2;
        }
    }
    else if(dx < 0 && dy >= 0) {
        if (-dx >= dy) {
            octant = 4;
            dx = -dx;
            x = -x1;
            y = y1;
            xend = -x2;
        }
        else
        {
            octant = 3;
            t = -dx;
            dx = dy;
            dy = t;
            x = y1;
            y = -x1;
            xend = y2;
        }
    }
    else if(dx < 0 && dy < 0)
    {
        if (-dx >= -dy)
        {
            octant = 5;
            dx = -dx;
            dy = -dy;
            x = -x1;
            y = -y1;
            xend = -x2;
        }
        else
        {
            octant = 6;
            t = -dx;
            dx = -dy;
            dy = t;
            x = -y1;
            y = -x1;
            xend = -y2;
        }
    }
    else
    {
        if (dx >= -dy)
        {
            octant = 8;
            dy = -dy;
            x = x1;
            y = -y1;
            xend = x2;
        }
        else
        {
            octant = 7;
            t = dx;
            dx = -dy;
            dy=t;
            x = -y1;
            y = x1;
            xend = -y2;
        }
    }
    
    int p = 2 * dy - dx;
    int inc = 2 * dy;
    int dec = 2 * dy - 2 * dx;

    glVertex2i(x1, y1);
    while (x < xend) {
        x += 1;
        if (p >= 0) {
            p += dec;
            y += 1;
        }
        else {
            p += inc;
        }
        switch (octant) {
        case 1:glVertex2i( x, y);break;
        case 2:glVertex2i( y, x);break;
        case 3:glVertex2i( y,-x);break;
        case 4:glVertex2i(-x, y);break;
        case 5:glVertex2i(-x,-y);break;
        case 6:glVertex2i(-y,-x);break;
        case 7:glVertex2i(-y, x);break;
        case 8:glVertex2i( x,-y);break;
        }
    }
    glEnd();
    glFlush();
}

void disp2() {
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    //Bresen(-10, -80, 10, 80);
    //Bresen( 10,  80,-10,-80);
    //Bresen(-80,  10, 80,-10);
    //Bresen(-10, -80, 10, 80);
    Bresen(0,0,60, 20);
    Bresen(0,0,20, 60);
    Bresen(0,0, -60, 20);
    Bresen(0,0, -20, 60);
    Bresen(0,0, -60, -20);
    Bresen(0,0, -20, -60);
    Bresen(0,0, 60, -20);
    Bresen(0,0, 20, -60);
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(10, 10);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Bresen");
    gluOrtho2D(-100, 100, -100, 100);
    glutDisplayFunc(disp2);
    glutMainLoop();
    return 0;
}
