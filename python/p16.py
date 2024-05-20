# cylinder
from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *
from math import sin,cos

def disp1():
    global gap
    glClearColor(0,0,0,1)
    glClear(GL_COLOR_BUFFER_BIT)
    for i in range(-50,51,20):
        glBegin(GL_LINES)
        glVertex2f(-50,i)
        glVertex2f(50,i)
        glVertex2f(i,50)
        glVertex2f(i,-50)
        glEnd()
        glBegin(GL_LINE_LOOP)
        glVertex2f(-50,-i)
        glVertex2f(i,50)
        glVertex2f(50,i)
        glVertex2f(-i,-50)
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