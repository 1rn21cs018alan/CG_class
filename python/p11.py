# cylinder
from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *
from math import sin,cos

def circle(x,y):
    glBegin(GL_LINE_LOOP)
    glColor3f(1,1,1)
    i=0
    while(i<=360):
        ang=3.1415/180*i
        glVertex2f(15*cos(ang)+x,15*sin(ang)+y)
        i+=1
    glEnd()
    glFlush()
    
def disp1():
    glClearColor(0,0,0,1)
    glClear(GL_COLOR_BUFFER_BIT)
    for i in range(-50,51,2):
        circle(0,i)


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