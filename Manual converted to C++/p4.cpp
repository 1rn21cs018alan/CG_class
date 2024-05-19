#include<glut.h>
void disp1(){
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    int a[][2]={
        {25,25},
        {75,25},
        {75,75},
        {25,75},
        {125,125},
        {175,125},
        {175,175},
        {125,175}
    };
    glBegin(GL_LINES);
    for (int i=0;i<4;i++){
        glVertex2fv(a[i]);
        glVertex2fv(a[(i+1)%4]);
    }
    glEnd();
    glBegin(GL_LINE_LOOP);
    for (int i=4;i<8;i++){
        glVertex2fv(a[i]);
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
