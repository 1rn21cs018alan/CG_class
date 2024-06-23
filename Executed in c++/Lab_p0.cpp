#include<glut.h>

void disp1() {//draw 2 points
	glClearColor(0, 0.5, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0.6);
	glPointSize(15);
	glBegin(GL_POINTS);
	glVertex2f(25, 25);
	glVertex2f(75, 75);
	glEnd();
	glFlush();
}



int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(700, 700);
	glutCreateWindow("points");
	gluOrtho2D(-200, 200, -200, 200);
	glutDisplayFunc(disp1);
	glutMainLoop();
	return 0;
}
