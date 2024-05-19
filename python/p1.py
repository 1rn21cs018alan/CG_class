from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *

def disp1():
    glClearColor(0,0,0,1)
    glClear(GL_COLOR_BUFFER_BIT)
    glColor3f(1,0,0)
    glPointSize(5)
    glBegin(GL_LINES)
    glVertex2f(25,25)
    glVertex2f(75,75)
    glVertex2f(0,50)
    glVertex2f(55,25)
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