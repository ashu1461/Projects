#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>    // Header File For The GLUT Library 
#include <GL/gl.h>	// Header File For The OpenGL32 Library
#include <GL/glu.h>	// Header File For The GLu32 Library
#include <unistd.h>     // needed to sleep
#define ESCAPE 27

	/*
	   let us assume that 4 kinds of types exist ! 
	   1 ---> static 
	   2 ---> Higher 
	   3 ---> Lower
	   4 ---> alternating b//w higher and lower 
	  */
int WORLD[100][100];
int window; 
int i,j;
float  Scale ;
float rtri = 0.0f;
int flag_scale = 0 ;
void InitGL(int widht,int Height);
void ReSizeGLScene(int Width, int Height);
void drawblock(float x,float y,float z);
void SetupWorld();
float rquad = 0.0f;
int x_dimension , y_dimension ; // indicates the x and the y co-ordiantes of the world ! 



void readstr(FILE *f, char *string)
{
	do {
		fgets(string, 255, f); // read the line
	} while ((string[0] == '/') || (string[0] == '\n'));
	return;
}



// loads the world from a text file.


/* The main drawing function. */
void DrawGLScene()
{

  glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);	// Clear The Screen And The Depth Buffer
  glLoadIdentity();				// Reset The View
//  ---> to execute the draw function !! 		

//  glScalef(0.5f,0.5f,0.5f);

// Let us draw something !! 

 for(i=0;i<x_dimension;i=i++){
	 for(j=0;j<y_dimension;j=j++){
		glPushMatrix();
//		printf("%d %d for block i ,j \n",i,j);
		if(WORLD[i][j]==4){
  		glScalef(1.0f,Scale,1.0f);
		}
		else if(WORLD[i][j]==2){
			glScalef(1.0f,2.0f,1.0f);
		}
		else if(WORLD[i][j]==3){
			glScalef(1.0f,0.5f,1.0f);
		}
  	//	glRotatef(rquad,0.0f,1.0f,0.0f);		// Rotate The Cube On X, Y, and Z
		drawblock(2*(float)i,0.0f,-2*(float)j);
		glPopMatrix();
	 }
 }

/*
  glPushMatrix();
  drawblock(0.0,0.0,0.0);	
  glPopMatrix();



  glPushMatrix();  
  glRotatef(rquad,0.0f,1.0f,0.0f);		// Rotate The Cube On X, Y, and Z
  drawblock(2.0,0.0,0.0);	
  glPopMatrix();*/
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
//	printf("%f\n",Scale);
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
	SetupWorld();
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


void InitGL(int Width, int Height)	        // We call this right after our OpenGL window is created.
{
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);		// This Will Clear The Background Color To Black
  glClearDepth(1.0);				// Enables Clearing Of The Depth Buffer
  glDepthFunc(GL_LESS);			        // The Type Of Depth Test To Do
  glEnable(GL_DEPTH_TEST);		        // Enables Depth Testing
  glShadeModel(GL_SMOOTH);			// Enables Smooth Color Shading
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();				// Reset The Projection Matrix
  gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);	// Calculate The Aspect Ratio Of The Window
//  gluLookAt(0.0f,10.0f,0.0f,0.0f,0.0f,0.0f,0,1,0);
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
  gluLookAt(0.0f,10.0f,10.0f,0.0f,0.0f,-10.0f,0,1,0);
  glMatrixMode(GL_MODELVIEW);
}


void drawblock(float x,float y,float z){
	glPushMatrix();
	glTranslatef(x,y,z);
	glBegin(GL_QUADS);				// start drawing the cube.
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
	glPopMatrix();
}
void SetupWorld() 
{
	float x, y;
	int vert;
	int numtriangles;
	FILE *filein;        // file to load the world from
	char oneline[1024];
 	int i,j ;
	int a[10];
	filein = fopen("map1", "rt");

	readstr(filein, oneline);
	sscanf(oneline, "%d %d\n", &x_dimension,&y_dimension);
	for (i = 0; i < x_dimension; i++){
			readstr(filein,oneline);
			sscanf(oneline,"%d %d %d %d %d %d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8],&a[9]);
			for(j=0;j<10;j++){
				WORLD[i][j]=a[j];
		
			}
	}
	fclose(filein);


	for(i=0;i<x_dimension;i++){
		for(j=0;j<y_dimension;j++){
			printf("%d ",WORLD[i][j]);
		}
		printf("\n");
	}
	return ;
}


