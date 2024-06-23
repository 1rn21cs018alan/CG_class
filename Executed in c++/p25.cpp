#include<GL/glut.h>
#include<math.h>
void init() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-300, 300, -300, 300);
	glMatrixMode(GL_MODELVIEW);
}
void scale(int x, int y, float sx,float sy) {
	glVertex2f(x * sx, y * sy);
}
void disp() {
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 1);
	glBegin(GL_TRIANGLES);
	scale(0, 0, 2,2);
	scale(100, 0, 2,2);
	scale(50, 100, 2,2);
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
