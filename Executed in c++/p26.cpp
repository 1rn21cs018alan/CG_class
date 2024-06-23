#include<GL/glut.h>
#include<random>
#include<iostream>
int W = 600, H = 600;
void init() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-300, 300, -300, 300);
	glMatrixMode(GL_MODELVIEW);
}

void disp() {
	glFlush();
}

float color() {
	return (float)rand() / RAND_MAX;
}

void mouse(int b, int s, int x, int y) {
	x -= (W / 2);
	y = H / 2 - y;
	if (s == 0) {
		if (b == 0) {
			glColor3f(color(),color(),color());
			glBegin(GL_QUADS);
			glVertex2f(x  - 10, y - 10);
			glVertex2f(x - 10, y + 10);
			glVertex2f(x + 10, y + 10);
			glVertex2f(x + 10, y - 10);
			glEnd();
			glFlush();

		}
		else if (b == 2) {
			glClear(GL_COLOR_BUFFER_BIT);
			glFlush();
		}
		glutPostRedisplay();
	}
}

void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	W = w;
	H = h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w > h) {
		gluOrtho2D(-300 * w / (float)h, 300 * w / (float)h, -300, 300);
	}
	else {
		gluOrtho2D(-300, 300, -300 * h / (float)w, 300 * h / (float)w);
	}
	glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(300, 300);

	glutCreateWindow("Moving text");
	init();
	glClearColor(1,1,1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutDisplayFunc(disp);
	glutMainLoop();
	return 0;
}
