from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *

def disp1():
    glClearColor(0,0,0,1)
    glClear(GL_COLOR_BUFFER_BIT)
    glColor3f(1,0,0)
    a=[
        [25,25],
        [75,25],
        [50,75],
        [125,125],
        [175,125],
        [150,175],
    ]
    glBegin(GL_LINES)
    for i in range(3):
        glVertex2fv(a[i])
        glVertex2fv(a[(i+1)%3])
    glEnd()
    glBegin(GL_LINE_LOOP)
    for i in range(3):
        glVertex2fv(a[i+3])
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