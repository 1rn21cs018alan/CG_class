#include<GL/glut.h>
#include<math.h>
#include<iostream>
using namespace std;
double tx, ty, o;
void init() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-300, 300, -300, 300);
	glMatrixMode(GL_MODELVIEW);
}

void transform(int x, int y) {
	x -= tx;
	y -= ty;
	glVertex2f(x * cos(o) - y * sin(o) + tx, x * sin(o) + y * cos(o) + ty);
}
void disp() {
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 1);
	glBegin(GL_TRIANGLES);
	transform(50, -50);
	transform(-50, -50);
	transform(0, 50);
	glEnd();
	glFlush();
}

void reshape(int w, int h) {
	glViewport(0, 0, w, h);
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
	cout << "Enter pivot point and angle\n";
	cin >> tx >> ty >> o;
	o = 3.1415 * o / 180;
	glutCreateWindow("Moving text");
	init();
	glutReshapeFunc(reshape);
	glutDisplayFunc(disp);
	glutMainLoop();
	return 0;
}
