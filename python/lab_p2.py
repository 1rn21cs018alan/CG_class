# DDA line drawing
from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *
from math import sin,cos

def Bresen(x1,y1,x2,y2):
    glPointSize(20)
    glBegin(GL_POINTS)
    glColor3f(1,1,1)
    dx=x2-x1
    dy=y2-y1
    p=2*dy-dx
    inc=2*dy
    dec=2*dy-2*dx
    if(y1<y2):
        x,y=x1,y1
        xend=x2
    else:
        x,y=x2,y2
        xend=x1
    glVertex2i(x,y)
    while(x<xend):
        x+=1
        if p>=0:
            p+=dec
            y+=1
        else:
            p+=inc
        print(x,y)
        glVertex2i(x,y)
    glEnd()
    glFlush()
    
def disp1():
    glClearColor(0,0,0,1)
    glClear(GL_COLOR_BUFFER_BIT)
    Bresen(-9,-1,9,3)


def main():
    glutInit()
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB)
    glutInitWindowPosition(10,10)
    glutInitWindowSize(400,400)
    glutCreateWindow(b"Bresen")
    gluOrtho2D(-10,10,-10,10)
    glutDisplayFunc(disp1)
    glutMainLoop()
    
    
    
main()