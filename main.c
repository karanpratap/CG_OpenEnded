#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <unistd.h>

int j = 0;

void rowDisplay(int i, int k) {
  glPushMatrix();
    glColor3f(1, 0, 0);
    glTranslated(-0.9+(i*0.2), 1-(k*0.1), 0);
    glScalef(2,2,2);
    glutSolidSphere(0.05,70,70);
  glPopMatrix();
}

void curtainMove(){
	glFlush();
	glClear(GL_COLOR_BUFFER_BIT);
	int i;
	for(int k=0; k<j; k++) {
    	for(int i=0; i<10; i++) {
     		rowDisplay(i, k);
    	}
  	}
	glFlush();
}


void display()
{
  glFlush();
  glClearColor(0,0,0,1);
  glClear(GL_COLOR_BUFFER_BIT);
  
  for(j=0;j<=20;j++)
	  curtainMove();
	
  curtainMove();

  for(j=20;j>=0;j--)
	  curtainMove();

  glFlush();
  sleep(1);

  //glBitmapCharacter("KPS");


}

void mykeys(unsigned char key,int x, int y)
{
  switch(key)
  {
    case 's':
			break; 
    case 'd': 
			if(j<=20)
                j++;
              break;
  }
}

int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
    glutInitWindowSize(700, 700);
    glutCreateWindow("Curtains");
    glutDisplayFunc(display);
    //glutKeyboardFunc(mykeys);
    glutMainLoop();
    return 0;
}
