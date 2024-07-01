#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>
double rot = 0,rot2=0,move_x=0,move_y=0,move_z=0;
void init() {
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
}
void face(float P[8][3], int a,int b,int c,int d) {
	glBegin(GL_QUADS);
	glVertex3fv(P[a]);
	glVertex3fv(P[b]);
	glVertex3fv(P[c]);
	glVertex3fv(P[d]);
	glEnd();
}
void cube() {
	float P[8][3] = {
		{-1,-1,-1},
		{-1,-1,+1},
		{+1,-1,+1},
		{+1,-1,-1},
		{-1,+1,-1},
		{-1,+1,+1},
		{+1,+1,+1},
		{+1,+1,-1}
	};
	glColor3f(1, 0, 0);
	face(P, 0, 1, 2, 3);
	glColor3f(1, 1, 0);
	face(P, 0, 1, 5, 4);
	glColor3f(0, 1, 0);
	face(P, 1, 2, 6, 5);
	glColor3f(0, 1, 1);
	face(P, 2, 3, 7, 6);
	glColor3f(0, 0, 1);
	face(P, 3, 0, 4, 7);
	glColor3f(1, 0, 1);
	face(P, 4, 5, 6, 7);
}

void disp() {
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glScalef(0.3,0.3,0.3);
	glRotatef(rot2, 1, 0, 0);
	glRotatef(rot, 0,1, 0);
	glTranslatef(move_x, move_y, move_z);
	cube();
	glutSwapBuffers();
}
void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'w':move_y+=0.05;break;
	case 'a':move_x-=0.05;break;
	case 's':move_y-=0.05;break;
	case 'd':move_x+=0.05;break;
	case '.':rot--;break;
	case ',':rot++;break;
	case '[':rot2--;break;
	case ']':rot2++;break;
	case 'r':move_x=move_y=rot=rot2=0;break;
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
