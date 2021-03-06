#include"stdafx.h"
#include<iostream>
#include<stdio.h>
#include<GL\glew.h>
#include<GL\GL.h>
#include<GL\GLU.h>
#include<GL\glut.h>

#define GL_GLEXT_PROTOTYPES


void init() {
	//OpenGL Init
	glewInit();
	glClearColor(0.0, 0.0, 0.0, 0.0); // RGBA
	glRenderMode(GL_SMOOTH); // GL_SMOOTH and GL_FLAT
	
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glTranslatef(0.0, 0.0, -1.5);

	glColor3f(1.0, 0.0, 0.0);
	glutWireTeapot(0.0);
	glPopMatrix();
	glutSwapBuffers();
	glLoadIdentity();
	glFlush();
}
void reshape(int width, int height) {
	glViewport(0, 0, (GLsizei)width,(GLsizei)height); //GLint x, GLint y, GSize width, GSize height
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (GLfloat)width / (GLfloat)height, 1.0, 100.0); // FOV, Aspect, zNear, zFar
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	
	glutCreateWindow("Selterstadt Engine");
	init();
	
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	
	glutMainLoop();

	
	return 0;
}
