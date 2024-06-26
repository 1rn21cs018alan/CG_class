# DDA line drawing
from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *
from math import sin,cos

def DDA_line(x1,y1,x2,y2):
    glPointSize(20)
    glBegin(GL_POINTS)
    glColor3f(1,1,1)
    dx=x2-x1
    dy=y2-y1
    steps=abs(dy)
    if(abs(dx)>steps):
        steps=abs(dx)
    x,y=x1,y1
    for k in range(steps):
        x+=dx/steps
        y+=dy/steps
        glVertex2i(int(x),int(y))
        print(int(x),int(y))
    glEnd()
    glFlush()
    
def disp1():
    glClearColor(0,0,0,1)
    glClear(GL_COLOR_BUFFER_BIT)
    DDA_line(-9,-1,9,3)


def main():
    glutInit()
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB)
    glutInitWindowPosition(10,10)
    glutInitWindowSize(400,400)
    glutCreateWindow(b"DDA")
    gluOrtho2D(-10,10,-10,10)
    glutDisplayFunc(disp1)
    glutMainLoop()
    
    
    
main()