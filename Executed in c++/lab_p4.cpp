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
void cube(float tx,float ty,float tz,float rx,float ry,float rz,float scale,float c) {
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
	rx += rot2;
	ry += rot;
	rx = rx * 3.1415 / 180;
	ry = ry * 3.1415 / 180;
	rz = rz * 3.1415 / 180;
	for (int i = 0;i < 8;i++) {
		float x= P[i][0], y= P[i][1], z= P[i][2],t;
		x = x*scale+tx;
		y = y*scale+ty;
		z = z*scale+tz;
		t = y * cos(rx) - z * sin(rx);
		z = y * sin(rx) + z * cos(rx);
		y = t;

		t = z * cos(ry) - x * sin(ry);
		x = z * sin(ry) + x * cos(ry);
		z = t;

		t = x * cos(rz) - y * sin(rz);
		y = x * sin(rz) + y * cos(rz);
		x = t;

		P[i][0] = x +move_x;
		P[i][1] = y +move_y;
		P[i][2] = z +move_z;
	}
	glColor3f(c, 0, 0);
	face(P, 0, 1, 2, 3);
	glColor3f(c, c, 0);
	face(P, 0, 1, 5, 4);
	glColor3f(0, c, 0);
	face(P, 1, 2, 6, 5);
	glColor3f(0, c, c);
	face(P, 2, 3, 7, 6);
	glColor3f(0, 0, c);
	face(P, 3, 0, 4, 7);
	glColor3f(c, 0, c);
	face(P, 4, 5, 6, 7);
}

void disp() {
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	cube(0, 0, 0, 0, 0, 0, 0.1, 1.0);
	//cube(0.5, 0, 0, 0, 0, 0, 0.2, 0.9);
	//cube(0, 0.5, 0, 0, 0, 0, 0.2, 0.8);
	//cube(0, 0, 0.5, 0, 0, 0, 0.2, 0.7);
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
	case 'r':move_x=move_z=rot=rot2=0;break;
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
