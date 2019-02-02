//
//  main.c
//  Rotating Stick
//
//  Created by Sai Vittal B on 1/31/19.
//  Copyright © 2019 Sai Vittal B. All rights reserved.
//

#include <GLUT/glut.h>
#include <OpenGL/glu.h>
#include <OpenGL/gl.h>
#include <stdio.h>

int frameNumber = 0;

double speed;

void input(void){
    printf("Enter a number for regulating the rotation speed of the stick = ");
    scanf("%lf", &speed);
}

void draw(void) {
    glTranslatef(-0.25, 1, 0);
    glRotated(frameNumber * (speed), 0, 0, -1);
    glColor3f(0.1f, 0.1f, 0.1f);
    glRotated(180, 0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex2f(0.1, 0);
    glVertex2f(2.0f, 2.0f);
    glVertex2f(-2.0f, -2.0f);
    glEnd();
}

void display(void) {
    
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    
    glPushMatrix();
    glTranslated(3.7,0.8,0);
    glScaled(0.7,0.7,1);
    draw();
    glPopMatrix();
    
    glutSwapBuffers();
    
}

void doFrame(int v) {
    frameNumber++;
    glutPostRedisplay();
    glutTimerFunc(30,doFrame,0);
}

void init(void) {
    glClearColor(0.5f, 0.5f, 1, 1);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 7, -1, 4, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char** argv) {
    input();
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(650,550);
    glutInitWindowPosition(375,150);
    glutCreateWindow("OpenGL Modeling 2D Rotating Stick");
    
    init();
    
    glutDisplayFunc(display);
    glutTimerFunc(200,doFrame,0);
    
    glutMainLoop();
    return 0;
}
