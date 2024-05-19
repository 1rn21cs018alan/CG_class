#include<glut.h>
#include<math.h>

void disp1(){
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
    glColor3f(1,1,1);
    i=0;
    while(i<=360){
        ang=3.1415/180*i;
        glVertex2f(15*cos(ang),15*sin(ang));
        i+=1;
    }
    glEnd();
    glFlush();
}
    

     
int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(10,10);
    glutInitWindowSize(700,700);
    glutCreateWindow("points");
    gluOrtho2D(-200,200,-200,200);
    glutDisplayFunc(disp1);
    glutMainLoop();
    return 0;   
}
