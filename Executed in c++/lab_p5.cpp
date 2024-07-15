#include<stdlib.h>
#include<GL/glut.h>
double r1 = 0, r2 = 0, x = 0, y = 0, s = 0.5;
void init() {
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
}
void c(float a, float b, float c) {
	glColor3f(a, b, c);
}
void f(float P[8][3], int a, int b, int c, int d) {
	glBegin(GL_QUADS);
	glVertex3fv(P[a]);
	glVertex3fv(P[b]);
	glVertex3fv(P[c]);
	glVertex3fv(P[d]);
	glEnd();
}
void cube() {			// No need to write these comments
	float P[8][3] = {	// x values -> [-1] 4 times,[+1] 4 times											00001111
		{-1,-1,-1},		// y values -> [-1] 2 times,[+1] 2 times, [-1] 2 times,[+1] 2 times,				00110011
		{-1,-1,+1},		// z values -> [-1] 1 time ,[+1] 2 times, [-1] 2 times,[+1] 2 times,[-1] 1 time		01100110
		{-1,+1,+1},
		{-1,+1,-1},
		{+1,-1,-1},
		{+1,-1,+1},
		{+1,+1,+1},
		{+1,+1,-1}
	};
	c(1, 0, 0);
	f(P, 0, 1, 2, 3);
	c(1, 1, 0);
	f(P, 0, 1, 5, 4);
	c(0, 1, 0);
	f(P, 1, 2, 6, 5);
	c(0, 1, 1);
	f(P, 2, 3, 7, 6);
	c(0, 0, 1);
	f(P, 3, 0, 4, 7);
	c(1, 0, 1);
	f(P, 4, 5, 6, 7);
}

void disp() {
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glScalef(s,s,s);
	glRotatef(r1, 1, 0, 0);
	glRotatef(r2, 0, 1, 0);
	glTranslatef(x, y, 0);
	cube();
	glutSwapBuffers();
}
void keyboard(unsigned char key, int _x, int _y) {
	switch (key) {
	case 'w':y += 0.05;break;
	case 's':y -= 0.05;break;
	case 'a':x -= 0.05;break;
	case 'd':x += 0.05;break;
	case '.':r1--;break;
	case ',':r1++;break;
	case '[':r2--;break;
	case ']':r2++;break;
	case '-':s -= 0.1;break;
	case '=':s += 0.1;break;
	case 'q': exit(0);
	}
	glutPostRedisplay();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(300, 300);

	glutCreateWindow("3D Operation");
	init();
	glutDisplayFunc(disp);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
