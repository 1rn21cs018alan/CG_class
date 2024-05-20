#include<glut.h>
void disp1() {
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	float a[][2] = {
		{22,-25},
		{22,-70},
		{70,-70},
		{70,-25},
		{33,-70},
		{33,-98},
		{40,-98},
		{40,-70},
		{53,-70},
		{53,-98},
		{60,-98},
		{60,-70},
		{41,-20},
		{41,-25},
		{53,-25},
		{53,-20},
		{36,-20},
		{36,0},
		{58,0},
		{58,-20},
		{22,-25},
		{22,-30},
		{2,-60},
		{2,-55},
		{70,-25},
		{70,-30},
		{90,-60},
		{90,-55},
		{38,-10},
		{38,-5},
		{43,-5},
		{43,-10},
		{51,-10},
		{51,-5},
		{56,-5},
		{56,-10},
		{40,-15},
		{54,-15}
	};
	glBegin(GL_LINE_LOOP);
	glColor3f(1, 1, 1);
	for (int i = 0; i < 38; i++) {
		glVertex2fv(a[i]);
		if (i % 4 == 3) {
			glEnd();
			glBegin(GL_LINE_LOOP);
		}
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