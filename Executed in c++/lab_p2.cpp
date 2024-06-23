#include<GL/glut.h>
#include<math.h>
double tx=20, ty=-50, rot=30, s=0.5;
void init() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-300, 300, -300, 300);
	glMatrixMode(GL_MODELVIEW);
}

void transform(float x, float y) {
	x = s * x;
	y = y * s;//scaling
	double ang = rot * 3.1415 / 180;
	glVertex2f(x * cos(ang) - y * sin(ang) + tx,x * sin(ang) + y * cos(ang) + ty);// rotation and translation
}

void disp() {
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 1);
	glBegin(GL_TRIANGLES);
	transform(-100, -100);
	transform(100, -100);
	transform(0, 100);
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

	glutCreateWindow("2D Operation");
	init();
	glutReshapeFunc(reshape);
	glutDisplayFunc(disp);
	glutMainLoop();
	return 0;
}
