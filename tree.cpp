/*
#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#define xpix 500
#include <cstring>
using namespace std;

float r, g, b, x, y;
bool flag = true;
bool line = true;
int counter = 0;
void print( float x, float y, char *st)
{
    int l,i;

    l=strlen( st ); // see how many characters are in text string.
   glColor3f(0.2,1.0,0.7);
    glDisable(GL_LIGHTING);
    glRasterPos2f( x, y); // location to start printing text
    for( i=0; i < l; i++) // loop until i is greater then l
    {
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);
    }
}
// Function works on mouse click
void mouse(int button, int state,
		int mousex, int mousey)
{
	if (button == GLUT_LEFT_BUTTON
		&& state == GLUT_DOWN) {
		flag = true;
		x = mousex;
		cout << x <<endl;
		y = 600 - mousey;
		cout <<y <<endl;
		
	
	}

	// Change color of circle
 if (button == GLUT_RIGHT_BUTTON
			&& state == GLUT_DOWN) {
		if (counter > 4) {
			counter = 0;
		}

		counter++;

		//	line = true;
	//	 Redisplay();
		glutPostRedisplay();
	}
}

// Function that exits from program
void keyboard(unsigned char key,
			int x, int y)
{
	switch (key) {
	case 27:
		glutHideWindow();
	}
}

// Function to draw the circle
void display(void)
{
	float angle_theta;
	// Matrix mode
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 800.0,
			0.0, 600.0);
	if (flag) {
		glBegin(GL_POLYGON);
		for (int i = 0; i < 360; i++) {
			angle_theta = i * 3.142 / 180;
			glVertex2f(x + 20 * cos(angle_theta),
					y + 20 * sin(angle_theta));
				
		}
		glEnd();
				print(x,y+20,"s");
	}
/*	if(line){
		glBegin(GL_LINES);
            glVertex2i(x,y);
            glVertex2i(40,61);
            glEnd();
	}*/
	// Flushes the frame buffer
	// to the screen
/*8	glFlush();
}

// Driver Code
int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	// Creates the window as
	// specified by the user
	glutCreateWindow("Circle Creation "
					"on mouse click");

	// Sets the background color
	glClearColor(0, 0, 0, 0);

	// Clears the frame buffer
	glClear(GL_COLOR_BUFFER_BIT);

	// Links display event with the
	// display event handler(display)
	glutDisplayFunc(display);

	// Mouse event handler
	glutMouseFunc(mouse);

	// Keyboard event handler
	glutKeyboardFunc(keyboard);

	// Loops the current event
	glutMainLoop();
}*/
#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#define xpix 500
#include <cstring>
using namespace std;
void drawCircle(float x,float y)
{

	float angle_theta;
	// Matrix mode
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 800.0,
			0.0, 600.0);
		glBegin(GL_POLYGON);
		for (int i = 0; i < 360; i++) {
			angle_theta = i * 3.142 / 180;
			glVertex2f(x + 20 * cos(angle_theta),
					y + 20 * sin(angle_theta));
				
		}
		glEnd();
			glFlush();
}
void display(void)
{
	drawCircle(60,70);
	for(int i = 0; i < 600; i+ 50){
		drawCircle(60+ i,70+i);
	}
	}
int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	// Creates the window as
	// specified by the user
	glutCreateWindow("Circle Creation "
					"on mouse click");

	// Sets the background color
//	glClearColor(0, 0, 0, 0);

	// Clears the frame buffer
	glClear(GL_COLOR_BUFFER_BIT);

	// Links display event with the
	// display event handler(display)
	glutDisplayFunc(display);

	glutMainLoop();
}
