from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *

def disp1():
    glClearColor(0,0,0,1)
    glClear(GL_COLOR_BUFFER_BIT)
    points=[
        (10,70),
        (10,10),
        (30,10),
        (30,30),
        (40,30),
        (40,10),
        (30,10),
        (60,10),
        (60,70),    
        (10,70),
        (35,100),
        (60,70)
            ]
    glBegin(GL_LINE_LOOP)
    glColor3f(1,1,1)
    for each in points:
        glVertex2f(*each)
    glEnd()
    stars=[
        (4,0),
        (11,21),
        (17,0),
        (0,12),
        (21,12)
    ]
    
    glBegin(GL_LINE_LOOP)
    glColor3f(1,1,1)
    for each in stars:
        glVertex2f(each[0]+90,each[1]+90)
    glEnd()
    glBegin(GL_LINE_LOOP)
    glColor3f(1,1,1)
    for each in stars:
        glVertex2f(each[0]+70,each[1]+70)
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