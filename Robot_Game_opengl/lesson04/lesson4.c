#include <GL/glut.h>    // Header File For The GLUT Library 
#include <GL/gl.h>	// Header File For The OpenGL32 Library
#include <GL/glu.h>	// Header File For The GLu32 Library
#include <unistd.h>     // Header File For sleeping.
#define ESCAPE 27
int window; 
float rtri = 0.0f;
float rquad = 0.0f;
void InitGL(int Width, int Height)	        // We call this right after our OpenGL window is created.
{
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);		// This Will Clear The Background Color To Black
  glClearDepth(1.0);				// Enables Clearing Of The Depth Buffer
  glDepthFunc(GL_LESS);				// The Type Of Depth Test To Do
  glEnable(GL_DEPTH_TEST);			// Enables Depth Testing
  glShadeModel(GL_SMOOTH);			// Enables Smooth Color Shading

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();				// Reset The Projection Matrix

  gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);	// Calculate The Aspect Ratio Of The Window

  glMatrixMode(GL_MODELVIEW);
}
void ReSizeGLScene(int Width, int Height)
{
  if (Height==0)				// Prevent A Divide By Zero If The Window Is Too Small
    Height=1;

  glViewport(0, 0, Width, Height);		// Reset The Current Viewport And Perspective Transformation

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);
  glMatrixMode(GL_MODELVIEW);
}
void DrawGLScene()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// Clear The Screen And The Depth Buffer
  glLoadIdentity();				// Reset The View

  glTranslatef(-1.5f,0.0f,-6.0f);		// Move Left 1.5 Units And Into The Screen 6.0
	
//  glRotatef(rtri,0.0f,1.0f,0.0f);		// Rotate The Triangle On The Y axis 
  // draw a triangle (in smooth coloring mode)
  glBegin(GL_TRIANGLES);				// start drawing a polygon
  glColor3f(1.0f,0.0f,0.0f);			// Set The Color To Red
  glVertex3f( 0.0f, 1.0f, 0.0f);		// Top
  glColor3f(0.0f,1.0f,0.0f);			// Set The Color To Green
  glVertex3f( 1.0f,-1.0f, 0.0f);		// Bottom Right
  glColor3f(0.0f,0.0f,1.0f);			// Set The Color To Blue
  glVertex3f(-1.0f,-1.0f, 0.0f);		// Bottom Left	
  glEnd();					// we're done with the polygon (smooth color interpolation)

  glLoadIdentity();				// make sure we're no longer rotated.
  glTranslatef(1.5f,0.0f,-6.0f);		// Move Right 3 Units, and back into the screen 6.0
	
  glRotatef(rquad,1.0f,0.0f,0.0f);		// Rotate The Quad On The X axis 
  // draw a square (quadrilateral)
  glColor3f(0.5f,0.5f,1.0f);			// set color to a blue shade.
  // swap the buffers to display, since double buffering is used.
  glutSwapBuffers();
}

void keyPressed(unsigned char key, int x, int y) 
{
    usleep(100);
    if (key == ESCAPE) 
    { 
	glutDestroyWindow(window); 
	exit(0);                   
    }
}
int main(int argc, char **argv) 
{  
  glutInit(&argc, argv);  
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);  
  glutInitWindowSize(640, 480);  
  glutInitWindowPosition(0, 0);  
  window = glutCreateWindow("Jeff Molofee's GL Code Tutorial ... NeHe '99");  
  glutDisplayFunc(&DrawGLScene);  
  glutFullScreen();
  glutIdleFunc(&DrawGLScene);
  glutReshapeFunc(&ReSizeGLScene);
  glutKeyboardFunc(&keyPressed);
  InitGL(640, 480);
  glutMainLoop();  
  return 1;
}
