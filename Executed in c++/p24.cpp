#include<GL/glut.h>
#include<math.h>
void init() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-300, 300, -300, 300);
	glMatrixMode(GL_MODELVIEW);
}
void rotate(int x, int y, int o) {
	double ang = o * 3.1415 / 180;
	glVertex2f(x * cos(ang) - y * sin(ang), y * cos(ang) + x * sin(ang));
}
void disp() {
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 1);
	glBegin(GL_LINES);
	rotate(0, 0, 45);
	rotate(100, 0, 45);
	glEnd();

	glBegin(GL_TRIANGLES);
	rotate(0, 0, 135);
	rotate(100, 0, 135);
	rotate(50, 100, 135);
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

	glutCreateWindow("Moving text");
	init();
	glutReshapeFunc(reshape);
	glutDisplayFunc(disp);
	glutMainLoop();
	return 0;
}
