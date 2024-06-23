#include<GL/glut.h>
int turn = 2;
double angle = 0;
void init() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-300, 300, -300, 300);
	glMatrixMode(GL_MODELVIEW);
}

void disp() {
	glClearColor(0,0,0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(angle, 0, 0, 1);
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2f(50, 50);
	glVertex2f(50,- 50);
	glVertex2f(-50,- 50);
	glVertex2f(-50, 50);
	glEnd();
	glFlush();
}

void mouse(int b, int s, int x, int y) {
	if (s == 0) {
		turn = b;
	}
}

void idle() {
	if (turn != 2) angle += 0.01;
	glutPostRedisplay();
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
	glutMouseFunc(mouse);
	glutDisplayFunc(disp);
	glutIdleFunc(idle);
	glutMainLoop();
	return 0;
}
