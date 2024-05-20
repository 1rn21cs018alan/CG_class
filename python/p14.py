from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *
cx1=50
cy1=100
string=""

def update(j):
    glClearColor(0,0,0,1)
    glClear(GL_COLOR_BUFFER_BIT)
    glColor3f(1,0,0)
    glRasterPos2i(cx1,cy1)
    glRasterPos2i(cx1+5*j,cy1)
    for each in string:
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,ord(each))
    glFlush()
    if(j>30):
        glutTimerFunc(100,update,0)
    else:
        glutTimerFunc(100,update,j+1)
def disp():
    glFlush()
    
    
def main():
    global string
    glutInit()
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB)
    glutInitWindowPosition(10,10)
    glutInitWindowSize(700,700)
    string=input("Enter String:")
    glutCreateWindow(b"points")
    gluOrtho2D(0,200,0,200)
    glutDisplayFunc(disp)
    glutTimerFunc(100,update,0)
    glutMainLoop()
    
    
main()