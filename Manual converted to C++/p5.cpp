#include<glut.h>

void disp1(){
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    int a[][2]={
        {10,70},
        {10,10},
        {30,10},
        {30,30},
        {40,30},
        {40,10},
        {30,10},
        {60,10},
        {60,70},    
        {10,70},
        {35,100},
        {60,70}
    };
    glBegin(GL_LINE_LOOP);
    glColor3f(1,1,1);
    for (int i=0;i<12;i++){
        glVertex2f(a[i]);
    }
    glEnd();
    int stars[][2]={
        {4,0},
        {11,21},
        {17,0},
        {0,12},
        {21,12}
    };
    
    glBegin(GL_LINE_LOOP);
    glColor3f(1,1,1);
    for (int i=0;i<5;i++){
        glVertex2f(stars[i][0]+90,stars[i][1]+90);
    }
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(1,1,1);    
    for (int i=0;i<5;i++){
        glVertex2f(stars[i][0]+70,stars[i][1]+70);
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
