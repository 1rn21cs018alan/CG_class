#include<GL/glut.h>
int t = 2;
double angle = 0;
void init() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-300, 300, -300, 300);
	glMatrixMode(GL_MODELVIEW);
}

void disp() {
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(angle, 0, 0, 1);
	glColor3f(1, 1, 1);
	glBegin(GL_TRIANGLES);
	glVertex2f(50, -50);
	glVertex2f(-50, -50);
	glVertex2f(0, 50);
	glEnd();
	glutSwapBuffers();
}

void mouse(int b, int s, int x, int y) {
	t = b;
}

void idle() {
	if (t != 2) angle += 0.05;
	glutPostRedisplay();
}

void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w > h) gluOrtho2D(-300.0 * w / h, 300.0 * w / h, -300, 300);
	else gluOrtho2D(-300, 300, -300.0 * h / w, 300.0 * h / w);
	glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Moving text");
	init();
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutDisplayFunc(disp);
	glutIdleFunc(idle);
	glutMainLoop();
	return 0;
}