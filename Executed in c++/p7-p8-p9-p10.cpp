#include<glut.h>
#include<math.h>
void disp1() {
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	glPointSize(3);
	glColor3f(1, 1, 1);
	int i = 0;
	while (i <= 360) {
		double ang = 3.1415 / 180 * i;
		glVertex2f(30 * cos(ang), 30 * sin(ang));
		i += 1;
	}
	glEnd();
	glColor3f(1, 0, 0);
	glBegin(GL_LINES);
	i = 0;
	while (i <= 360) {
		double ang = 3.1415 / 180 * i;
		glVertex2f(50 * cos(ang), 50 * sin(ang));
		i += 1;
		ang = 3.1415 / 180 * i;
		glVertex2f(50 * cos(ang), 50 * sin(ang));
	}
	glEnd();
	glColor3f(0, 1, 0);
	glBegin(GL_LINE_LOOP);
	i = 0;
	while (i <= 360) {
		double ang = 3.1415 / 180 * i;
		glVertex2f(40 * cos(ang), 40 * sin(ang));
		i += 1;
	}
	glEnd();
	glColor3f(0,0, 1);
	glBegin(GL_LINES);
	i = 0;
	while (i <= 360) {
		double ang = 3.1415 / 180 * i;
		glVertex2f(35 * cos(ang), 35 * sin(ang));
		glVertex2f(45 * cos(ang), 45 * sin(ang));
		i += 10;
	}
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