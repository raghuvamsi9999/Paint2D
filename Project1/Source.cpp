#include <GL/glut.h>
#include <iostream>
#include <list>
using namespace std;
GLsizei MOUSEx = 0, MOUSEy = 0;
GLfloat SIDE = 10;
GLfloat BLUE[3] = { 0,0,1 };
GLfloat GREEN[3] = { 0,1,0 };
GLfloat point = 10;
int cnt=0;
void drawpoint()
{

	glPointSize(point);
	glColor3fv(GREEN);

	glBegin(GL_POINTS);
	

	glEnd();
}

void display(void)
{
	
	glClearColor(0.0, 0.0, 0.0, 1.0);
	if(cnt==3||cnt==5||cnt==7||cnt==9||cnt==11)
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	drawpoint();

	//draw a line
	//glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,1,1);
	glPointSize(SIDE);

	glBegin(GL_LINES);
	glVertex2d(MOUSEx, MOUSEy);
	glVertex2d(10, 145);
	glEnd();

	glFlush();
}
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluPerspective (60, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
	glOrtho(0.0, 1368, 768, 0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void spindisplay(void)
{
	glutPostRedisplay();
}

void setX1(int x1)
{
	MOUSEx = x1;
}

void setY1(int y1)
{
	MOUSEy = y1;
}

void mouse(int btn, int state, int x1, int y1)
{
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		setX1(x1);
		setY1(y1);
		cnt++;cout<<cnt;
		//drawSquare(MOUSEx,HEIGHT-MOUSEy);
		glutPostRedisplay();
	}
	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		exit(1);   // To Exit the Program
	}
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1366, 768);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Assignment 2");
	glutDisplayFunc(display);
	
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutIdleFunc(spindisplay);
	glutMainLoop();
}