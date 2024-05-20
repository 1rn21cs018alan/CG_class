# parallelopied
from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *

def rect(x,y):
    glBegin(GL_LINE_LOOP)
    glColor3f(1,1,1)
    glVertex2f(15+x,15+y)
    glVertex2f(15+x,30+y)
    glVertex2f(45+x,30+y)
    glVertex2f(45+x,15+y)
    glEnd()
    glFlush()
    
def disp1():
    glClearColor(0,0,0,1)
    glClear(GL_COLOR_BUFFER_BIT)
    for i in range(-50,51):
        rect(i,i)


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