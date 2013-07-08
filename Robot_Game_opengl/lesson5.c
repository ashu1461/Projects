#include <GL/glut.h>    // Header File For The GLUT Library 
#include <GL/gl.h>	// Header File For The OpenGL32 Library
#include <GL/glu.h>	// Header File For The GLu32 Library
#include <unistd.h>     // needed to sleep

/* ASCII code for the escape key. */
#define ESCAPE 27

/* The number of our GLUT window */
int window; 
float  Scale ;
/* rotation angle for the triangle. */
float rtri = 0.0f;
int flag_scale = 0 ;
/* rotation angle for the quadrilateral. */
float rquad = 0.0f;

/* A general OpenGL initialization function.  Sets all of the initial parameters. */
void InitGL(int Width, int Height)	        // We call this right after our OpenGL window is created.
{
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);		// This Will Clear The Background Color To Black
  glClearDepth(1.0);				// Enables Clearing Of The Depth Buffer
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();				// Reset The Projection Matrix
  gluLookAt(0.0f,0.0f,10.0f,0.0f,0.0f,0.0f,0,1,0);
  glMatrixMode(GL_MODELVIEW);
}

/* The function called when our window is resized (which shouldn't happen, because we're fullscreen) */
void ReSizeGLScene(int Width, int Height)
{
  if (Height==0)				// Prevent A Divide By Zero If The Window Is Too Small
    Height=1;
}

/* The main drawing function. */
void DrawGLScene()
{
  glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);	// Clear The Screen And The Depth Buffer
  glLoadIdentity();				// Reset The View


  // draw a cube (6 quadrilaterals)
  glBegin(GL_QUADS);				// start drawing the cube.
 	 
  // top of cube
  glColor3f(0.0f,1.0f,0.0f);			// Set The Color To Blue
  glVertex3f( 1.0f, 1.0f,-1.0f);		// Top Right Of The Quad (Top)
  glVertex3f(-1.0f, 1.0f,-1.0f);		// Top Left Of The Quad (Top)
  glVertex3f(-1.0f, 1.0f, 1.0f);		// Bottom Left Of The Quad (Top)
  glVertex3f( 1.0f, 1.0f, 1.0f);		// Bottom Right Of The Quad (Top)

  // bottom of cube
  glColor3f(1.0f,0.5f,0.0f);			// Set The Color To Orange
  glVertex3f( 1.0f,-1.0f, 1.0f);		// Top Right Of The Quad (Bottom)
  glVertex3f(-1.0f,-1.0f, 1.0f);		// Top Left Of The Quad (Bottom)
  glVertex3f(-1.0f,-1.0f,-1.0f);		// Bottom Left Of The Quad (Bottom)
  glVertex3f( 1.0f,-1.0f,-1.0f);		// Bottom Right Of The Quad (Bottom)

  // front of cube
  glColor3f(1.0f,0.0f,0.0f);			// Set The Color To Red
  glVertex3f( 1.0f, 1.0f, 1.0f);		// Top Right Of The Quad (Front)
  glVertex3f(-1.0f, 1.0f, 1.0f);		// Top Left Of The Quad (Front)
  glVertex3f(-1.0f,-1.0f, 1.0f);		// Bottom Left Of The Quad (Front)
  glVertex3f( 1.0f,-1.0f, 1.0f);		// Bottom Right Of The Quad (Front)

  // back of cube.
  glColor3f(1.0f,1.0f,0.0f);			// Set The Color To Yellow
  glVertex3f( 1.0f,-1.0f,-1.0f);		// Top Right Of The Quad (Back)
  glVertex3f(-1.0f,-1.0f,-1.0f);		// Top Left Of The Quad (Back)
  glVertex3f(-1.0f, 1.0f,-1.0f);		// Bottom Left Of The Quad (Back)
  glVertex3f( 1.0f, 1.0f,-1.0f);		// Bottom Right Of The Quad (Back)

  // left of cube
  glColor3f(0.0f,0.0f,1.0f);			// Blue
  glVertex3f(-1.0f, 1.0f, 1.0f);		// Top Right Of The Quad (Left)
  glVertex3f(-1.0f, 1.0f,-1.0f);		// Top Left Of The Quad (Left)
  glVertex3f(-1.0f,-1.0f,-1.0f);		// Bottom Left Of The Quad (Left)
  glVertex3f(-1.0f,-1.0f, 1.0f);		// Bottom Right Of The Quad (Left)

  // Right of cube
  glColor3f(1.0f,0.0f,1.0f);			// Set The Color To Violet
  glVertex3f( 1.0f, 1.0f,-1.0f);	        // Top Right Of The Quad (Right)
  glVertex3f( 1.0f, 1.0f, 1.0f);		// Top Left Of The Quad (Right)
  glVertex3f( 1.0f,-1.0f, 1.0f);		// Bottom Left Of The Quad (Right)
  glVertex3f( 1.0f,-1.0f,-1.0f);		// Bottom Right Of The Quad (Right)
  glEnd();					// Done Drawing The Cube

  rtri+=15.0f;					// Increase The Rotation Variable For The Pyramid
  rquad-=1.0f;					// Decrease The Rotation Variable For The Cube

  // swap the buffers to display, since double buffering is used.
  glutSwapBuffers();
}

/* The function called whenever a key is pressed. */
void keyPressed(unsigned char key, int x, int y) 
{
    /* avoid thrashing this call */
    usleep(100);

    /* If escape is pressed, kill everything. */
    if (key == ESCAPE) 
    { 
      /* shut down our window */
      glutDestroyWindow(window); 
      
      /* exit the program...normal termination. */
      exit(0);                   
    }
}
void update(int value){
	printf("%f\n",Scale);
	if(flag_scale==0)
		Scale = Scale + 0.1;
	else
		Scale = Scale - 0.1;
	if(Scale >= 2.0 || Scale <= 0.0)
		flag_scale = !flag_scale ;


	glutTimerFunc(100,update,0);
}
int main(int argc, char **argv) 
{  
  flag_scale=0;
  Scale = 1 ;
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
  glutTimerFunc(100,update,0);
  InitGL(640, 480);
  glutMainLoop();  
  return 1;
}




