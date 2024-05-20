#include<glut.h>
void disp1() {
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	float a[][2] = {
		{25,25},
		{75,25},
		{50,75},
		{125,125},
		{175,125},
		{150,175}
	};
	glBegin(GL_LINES);
	for (int i = 0; i < 3; i++) {
		glVertex2fv(a[i]);
		glVertex2fv(a[(i + 1) % 3]);
	}
	glEnd();
	glBegin(GL_LINE_LOOP);
	for (int i = 3; i < 6; i++) {
		glVertex2fv(a[i]);
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