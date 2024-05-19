from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *
from math import sin,cos
def disp1():
    glClearColor(0,0,0,1)
    glClear(GL_COLOR_BUFFER_BIT)
    glBegin(GL_LINES)
    glColor3f(1,1,1)
    i=0
    while(i<=360):
        ang=3.1415/180*i
        glVertex2f(35*cos(ang),35*sin(ang))
        glVertex2f(20*cos(ang),20*sin(ang))
        i+=10
    glEnd()
    glFlush()
    


def main():
    glutInit()
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB)
    glutInitWindowPosition(10,10)
    glutInitWindowSize(700,700)
    glutCreateWindow(b"points")
    gluOrtho2D(-200,200,-200,200)
    glutDisplayFunc(disp1)
    glutMainLoop()
    
    
    
main()