#include<GL/glut.h>
#include<stdlib.h>
int r = 1, g, b,sizef=5;
void init() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-300, 300, -300, 300);
	glMatrixMode(GL_MODELVIEW);
}

void disp() {
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(r, g, b);
	glBegin(GL_QUADS);
	glVertex2i( sizef,  sizef);
	glVertex2i( sizef, -sizef);
	glVertex2i(-sizef, -sizef);
	glVertex2i(-sizef,  sizef);
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
void d_menu(int option) {
	switch (option) {
	case 0:
		r = 1;
		g = b = 0;
		break;
	case 1:
		g = 1;
		r = b = 0;
		break;
	case 2:
		b = 1;
		r = g = 0;
		break;
	case 3:
		sizef += 5;
		break;
	case 4:
		sizef = 5;
		break;
	case 5:
		sizef-= 5;
		if (sizef < 0)sizef = 0;
		break;
	case 6:exit(0);
	}
	glutPostRedisplay();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(300, 300);

	glutCreateWindow("Mouse Control");
	init();
	glutReshapeFunc(reshape);
	int sub=glutCreateMenu(d_menu);
	glutAddMenuEntry("Red", 0);
	glutAddMenuEntry("Green", 1);
	glutAddMenuEntry("Blue", 2);
	glutCreateMenu(d_menu);
	glutAddMenuEntry("Increase", 3);
	glutAddMenuEntry("Reset", 4);
	glutAddMenuEntry("Decrease", 5);
	glutAddSubMenu("Change color", sub);
	glutAddMenuEntry("Quit", 6);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutDisplayFunc(disp);
	glutMainLoop();
	return 0;
}
