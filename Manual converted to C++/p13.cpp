// DDA line drawing
#include<math.h>
#include<glut.h>

void DDA_line(int x1,int y1,int x2,int y2){
    glPointSize(20);
    glBegin(GL_POINTS);
    glColor3f(1,1,1);
    float dx,dy,steps,x,y;
    dx=x2-x1;
    dy=y2-y1;
    steps=fabs(dy);
    if(fabs(dx)>steps){
        steps=fabs(dx);
    }
    x=x1;
    y=y1;
    for (int k=0;k<steps;k++){
        x+=dx/steps;
        y+=dy/steps;
        glVertex2i((int)x,(int)y);
    }
    glEnd();
    glFlush();
}
    
void disp1(){
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    DDA_line(-9,-1,9,3);
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
