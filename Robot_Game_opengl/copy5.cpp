#include<math.h>

#include<SOIL/SOIL.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>    // Header File For The GLUT Library 
#include <GL/gl.h>	// Header File For The OpenGL32 Library
#include <GL/glu.h>	// Header File For The GLu32 Library
#include <unistd.h>     // needed to sleep
#define ESCAPE 27


#include "imageloader.h"
#include "md2model.h"


MD2Model* _model;

 int a =0;

/*
   let us assume that 4 kinds of types exist ! 
   1 ---> static 
   2 ---> Higher 
   3 ---> Lower
   4 ---> alternating b//w higher and lower 
 */
int lookAt_flag=0;
float y_flag = 0;
void perform_jump(int z);
int w_flag = 1 ; 
float block_left ; 
int SCORE[5];
void makecoin(float x,float y,float z,int t_id);
void Robot_func();
void update_model(int i);
int rotate_flag;
float robot_rot ;
float robot_x,robot_y,robot_z;
int WORLD[100][100];
int TOKENS[100][100];
int window; 
int i,j;
float  Scale ;
float rtri = 0.0f;
int flag_scale = 0 ;
void InitGL(int widht,int Height);
void ReSizeGLScene(int Width, int Height);
void drawblock(float x,float y,float z,float scale);
void make_boost();
float boost_factor = 1 ;
void update_boost(int a);
void SetupWorld();
float heading,xpos,zpos;
GLfloat xrot,yrot,xspeed,yspeed;
GLfloat z =0.0f;
void makeRobot();
GLfloat walkbias = 0;
GLfloat walkbiasangle = 0;
GLfloat lookupdown = 0.0;
const float piover180 = 0.0174532925f;
GLuint texture[10];
float rquad = 0.0f;
int x_dimension , y_dimension ; // indicates the x and the y co-ordiantes of the world ! 
char s[20][100] = {"stand","run","attack","pain","jump","flip","salute","taunt","wave","point","crstand","crwalk","crattack","crpain","crdeath","death"};
int scounter =0 ;

int LoadGLTextures()                                    // Load Bitmaps And Convert To Textures
{
	/* load an image file directly as a new OpenGL texture */
	texture[0] = SOIL_load_OGL_texture
		(
		 "./crate.bmp",
		 SOIL_LOAD_AUTO,
		 SOIL_CREATE_NEW_ID,
		 SOIL_FLAG_INVERT_Y
		);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	texture[1] = SOIL_load_OGL_texture
		(
		 "./grass.png",
		 SOIL_LOAD_AUTO,
		 SOIL_CREATE_NEW_ID,
		 SOIL_FLAG_INVERT_Y
		);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);


	texture[2] = SOIL_load_OGL_texture
		(
		 "./coins.bmp",
		 SOIL_LOAD_AUTO,
		 SOIL_CREATE_NEW_ID,
		 SOIL_FLAG_INVERT_Y
		);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	texture[3] = SOIL_load_OGL_texture
		(
		 "./food.bmp",
		 SOIL_LOAD_AUTO,
		 SOIL_CREATE_NEW_ID,
		 SOIL_FLAG_INVERT_Y
		);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);


	texture[4] = SOIL_load_OGL_texture
		(
		 "./boost.bmp",
		 SOIL_LOAD_AUTO,
		 SOIL_CREATE_NEW_ID,
		 SOIL_FLAG_INVERT_Y
		);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);


	texture[5] = SOIL_load_OGL_texture
		(
		 "./power.bmp",
		 SOIL_LOAD_AUTO,
		 SOIL_CREATE_NEW_ID,
		 SOIL_FLAG_INVERT_Y
		);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);



	// Typical Texture Generation Using Data From The Bitmap
	return 1;                                        // Return Success
};

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

//		printf("printf here  %d %f\n",w_flag,boost_factor);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	if(lookAt_flag==1){

		printf("jere \n");
	gluLookAt(50.0f,50.0f,50.0f,10.0f,10.0f,-10.0f,0,1,0);
	}
	else{
		printf("here at 000 \n");
	gluLookAt(00.0f,10.0f,10.0f,10.0f,10.0f,-10.0f,0,1,0);
	}

	if(w_flag == 0)	{
		_model->setAnimation("run");
	}
	else{
		boost_factor=1.0f;
		_model->setAnimation("stand");
	}
	
	
	GLfloat xtrans, ztrans, ytrans;
	GLfloat sceneroty;

	// calculate translations and rotations.
	xtrans = -xpos;
	ztrans = -zpos;
	ytrans = -walkbias-0.25f;
	sceneroty = 360.0f - yrot;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// Clear The Screen And The Depth Buffer
	glLoadIdentity();

	glRotatef(lookupdown, 1.0f, 0, 0);
	glRotatef(sceneroty, 0, 1.0f, 0);

	glTranslatef(xtrans, ytrans, ztrans);    
	//  ---> to execute the draw function !! 		

	//  glScalef(0.5f,0.5f,0.5f);
       	glTranslatef(-x_dimension/2-3,0,-2);

	// Let us draw something !! 
	int i,j;
	float scale ;
	for(i=0;i<x_dimension;i=i++){
		for(j=0;j<y_dimension;j=j++){
			glPushMatrix();
//			glScalef(1.0f,1.0f,1.0f);
			//		printf("%d %d for block i ,j \n",i,j);
			if(WORLD[i][j]==4){
				scale = Scale;
		//		glScalef(1.0f,Scale,1.0f);
			}
			else if(WORLD[i][j]==2){
				scale = 2.0;
			}
			else if(WORLD[i][j]==3){
				scale =0.1;
			}
			else if(WORLD[i][j]==6){
				// 6 denotes moving tiles ! 
				glPushMatrix();

				drawblock(2*(float)i+block_left,6.0f,-2*(float)j,0.04);

				glPopMatrix();

			}
			else
				scale=1;

			if(WORLD[i][j]!=3&&WORLD[i][j]!=6)
			//	glRotatef(rquad,0.0f,1.0f,0.0f);		// Rotate The Cube On X, Y, and Z
			drawblock(2*(float)i,0.0f,-2*(float)j,scale);
			glPopMatrix();
		}
	}
//	makecoin(0,6,0,0);
	for(i=0;i<x_dimension;i=i++)
		for(j=0;j<y_dimension;j++){

// -- > HERE WE ARE GOING TO DRAW !! FOOD COINS AND MAYBE BARRIERS , BOOST ! , POWER !! :D :D !!
			glPushMatrix();

			if(TOKENS[i][j]!=0){
				int k = WORLD[i][j];
				float zz;
				if(k == 3){
					zz=1.5f;
				}
				else if(k == 2 ){
					zz=1.5f*3.0f;
				}
				else if(k==4){
					zz=1.5f*2.0f;
				}
				else
					zz=2.0f;
				if(TOKENS[i][j]==5){
					// here we are going to make a pillar !! :D :D :D :D
//					printf("here making the pillar ! \n");
					glPushMatrix();
			//		glScalef(0.5f,1.0f,0.5f);
					drawblock(2*(float)i,0.0f,-2*(float)j,6);
					glPopMatrix();
					

				}
				else
				makecoin(2*(float)i,zz,-2*(float)j,TOKENS[i][j]);
			}
			glPopMatrix();

		}


	Robot_func();
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

void Robot_func(){
	// Translate and ROtatae ! 
	//	-- > 
	glPushMatrix();


//	glRotatef(robot_rot,0,robot_y,0);
	
	makeRobot();
	glPopMatrix();
}

void makeRobot(){

/*
	glPushMatrix();
m	glTranslatef(0.0f,2.6f,0.0f);
	glRotatef(-90.0f,1.0f,0.0f,0.0f);
//	glRotatef(90.0f,0.0f,1.0f,0.0f);
	_model->draw();
	glPopMatrix();
*/

	/*
	glBegin(GL_LINES);
	glColor3f(1.0f,0.0f,0.0f);                    // Set The Color To Red
	glVertex3f(0.0f,0.0f,5.0f);
	glVertex3f(0.0f,0.0f,0.0f);
	glColor3f(0.0f,1.0f,0.0f);                    // Set The Color To Red
	glVertex3f(0.0f,5.0f,0.0f);
	glVertex3f(0.0f,0.0f,0.0f);
	glColor3f(0.0f,0.0f,1.0f);                    // Set The Color To Red
	glVertex3f(5.0f,0.0f,0.0f);
	glVertex3f(0.0f,0.0f,0.0f);
	glEnd();
	*/

		
//	printf("Here in the anonymous world !! %f/0.07f %f/0.07f %f/0.07f %f\n",robot_x*0.07,robot_y*0.07,robot_z*0.07,robot_rot);
	//printf("Here in the anonymous world !! %f %f %f %f\n",robot_x,robot_y,robot_z,robot_rot);
        // x is x/2 y is -y/2


	int x = (robot_x+1)/2;
	int y = -(robot_z-1)/2;
	int k = WORLD[x][y];
//	printf("%d here is the fun \n",WORLD[x][y]);
	if(k == 3){
		robot_y=2.7f*0.1+y_flag;
	}
	else if(k == 2 ){
		robot_y=2.7f*1.2+y_flag;
	}
	else if(k==4 ){
		robot_y=2.7f*Scale*0.5+y_flag;
	}
	else
		robot_y=2.7f + y_flag;

//rintf("world co-ordinates and TOKne x -- %d y -- %d token ---%d k --- %d \n",x,y,TOKENS[x][y],k);
	if(TOKENS[x][y]!=0){
	SCORE[TOKENS[x][y]]++;
	TOKENS[x][y]=0;
	}

	glPushMatrix();
	glTranslatef(robot_x,robot_y,robot_z);
	glScalef(0.07f,0.07f,0.07f);
	glRotatef(robot_rot,0,1,0);
	glRotatef(-90.0f,1.0f,0.0f,0.0f);
	glRotatef(90.0f,0.0f,0.0f,1.0f);
	_model->draw();	

	glPopMatrix();


	//	glPushMatrix();

	/*
	   glTranslatef(robot_x,robot_y,robot_z);
	   glRotatef(robot_rot,0.0f,0.0f,1.0f);
	   glPopMatrix();
	   rotate_flag=0;
	   }
	   else
	   {
	   }*/
	/*
	   else{
	   glRotatef(robot_rot,0.0f,0.0f,1);
	//	glPopMatrix();
	glTranslatef(robot_x,robot_y,robot_z);
	}

	 */


	//lPopMatrix();

	/*

	   glScalef(0.05f,0.05f,0.05f);*/
	/// ->> Make the main character in the screen ! 
	/// ->> Make the main character in the screen ! 


	}

void perform_jump(int x){
	
/*	if(y_flag < 2)
	y_flag= y_flag+0.1;*/
/*	if(y_flag > 2)
	y_flag = y_flag- 0.1; 
*/
	robot_x += (float)sin(robot_rot*piover180) * 0.05f*boost_factor+0.1;
	// perform a trajectile projection !! :D !! 

	glutTimerFunc(100,perform_jump,0);


}



void makecoin(float x,float y,float z,int t_id){
	// to make the coins in the code !! 
	// --- >> ??? 
	// t_id is the texture id! 

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, texture[t_id+1]);       
	//	glScalef(0.5f,1.0f,1.0f);
	//	glColor3f(1.0f,0.0f,0.0f);
	//	printf("here with %f %f %f\n",x,y,z);
	// go UP !! 
	glTranslatef(x,y,z);
	/*
	   glBegin(GL_LINES);
	   glVertex2f(0.0f,0.0f);
	   glVertex2f(0.0f,10.0f);
	   glEnd();

	 */
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(0.5f,0.0f,0.0f);
	glTexCoord2f(0.0f,1.0f);
	glVertex3f(0.0f,0.5f,0.0f);
	glTexCoord2f(1.0f,0.0f);
	glVertex3f(-0.5f,0.0f,0.0f);
	glTexCoord2f(1.0f,1.0f);
	glVertex3f(0.0f,-0.5f,0.0f);	
	glEnd();
	glPopMatrix();
	//	glColor3f(1.0f,0.0f,1.0f);

}


void specialKeyPressed(int key, int x, int y) 
{
	/* avoid thrashing this procedure */
	usleep(100);

	switch (key) {    


		case GLUT_KEY_UP: // walk forward (bob head)
			xpos -= (float)sin(yrot*piover180) * 0.05f;
			zpos -= (float)cos(yrot*piover180) * 0.05f;	
			if (walkbiasangle >= 359.0f)
				walkbiasangle = 0.0f;	
			else 
				walkbiasangle+= 10;
			walkbias = (float)sin(walkbiasangle * piover180)/20.0f;
			break;

		case GLUT_KEY_DOWN: // walk back (bob head)
			xpos += (float)sin(yrot*piover180) * 0.05f;
			zpos += (float)cos(yrot*piover180) * 0.05f;	
			if (walkbiasangle <= 1.0f)
				walkbiasangle = 359.0f;	
			else 
				walkbiasangle-= 10;
			walkbias = (float)sin(walkbiasangle * piover180)/20.0f;
			break;

		case GLUT_KEY_LEFT: // look left
			yrot += 1.5f;
			break;

		case GLUT_KEY_RIGHT: // look right
			yrot -= 1.5f;
			break;

		default:
			printf ("Special key %d pressed. No action there yet.\n", key);
			break;
	}	
}

void keyUp(unsigned char key, int x, int y){
	switch(key){
	case 'w' :
//		boost_factor=1;
		w_flag=1;
		break ;
	case 's' : 
//		boost_factor =1;
		w_flag =1 ;
		break;
	}

}
void update_boost(int x){
	boost_factor = 1 ;
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

		_model->advance(0.025f);

		/*
		glutDestroyWindow(window); 
*/
		/* exit the program...normal termination. */
//		exit(0);                   
	}
//	printf("%c key\n",key);
	switch(key){


		case '0':
		//	printf("here at 0 \n");
		//	gluLookAt(0.0f,10.0f,10.0f,0.0f,0.0f,-10.0f,0,1,0);
			break;
		case '1':
			printf("here at 1\n");
			lookAt_flag=1;
			break;

		case 'b': 
//			boost_factor = 6 ;
			glutTimerFunc(1000,update_boost,0);
			break;

		case 'B': // switch the blending
			z -= 0.2f;
			lookupdown -= 0.2f;
			break;

		case 'f': 
		case 'F': // switch the filter
			z += 0.2f;
			lookupdown += 1.0f;
			break;
		case 'w':
			w_flag=0;
	//		_model->setAnimation("run");
			robot_x -= (float)sin(robot_rot*piover180) * 0.05f*boost_factor;
			robot_z -= (float)cos(robot_rot*piover180) * 0.05f*boost_factor;
			if(boost_factor < 3.0f)
			boost_factor=boost_factor+0.3;
//			glutTimerFunc(3000,update_model,0);
			break;
		case 's':
			w_flag=0;
	//		_model->setAnimation("run");
			robot_x += (float)sin(robot_rot*piover180) * 0.05f*boost_factor;
			robot_z += (float)cos(robot_rot*piover180) * 0.05f*boost_factor;
			if(boost_factor < 3.0f)
			boost_factor=boost_factor+0.3;
			//			robot_rot = 360 - robot_rot;
//			glutTimerFunc(3000,update_model,0);
			break;
		case 'j':
			printf("here\n");
			glutTimerFunc(10,perform_jump,0);
			//			robot_z=robot_z-2;
			break;
		case 'a' :

			rotate_flag=1;
			robot_rot += 2.5f;
			break;

		case 'd' :

			robot_rot -= 2.5f;
			break;

		case 'q' :

			printf("Here are the scores -- > coins %d %d %d %d\n",SCORE[1],SCORE[2],SCORE[3],SCORE[4]);
			exit(0);
			break;

		case 'l' :
			scounter=(scounter+1)%17;
			int counter = scounter;
			_model->setAnimation(s[scounter]);
			printf("executing %s\n",s[counter]);
	}

}
void update(int value){
	


	DrawGLScene();
	glutPostRedisplay();		
	
//	block_left =block_left +  0.1f;		
//	robot_rot ++ ;
	//	printf("%f\n",Scale);
	_model->advance(0.025f);
	if(flag_scale==0){
		Scale = Scale + 0.1;
		block_left = block_left + 0.1f;
	}
	else{
		block_left = block_left - 0.1f;
		Scale = Scale - 0.1;
	}
	if(Scale >= 2.0 || Scale <= 0.0)
		flag_scale = !flag_scale ;
/*	if(w_flag!=1){
		_model->setAnimation("stand");
		w_flag=0;
	}*/

	glutTimerFunc(100,update,0);
}
void IdleScene(){

///	printf("ger\n");
//	_model->setAnimation("stand");
}
void update_model(int value){
//	printf("----------jere\n");
//	robot_rot ++ ;
	//	printf("%f\n",Scale);
/*		_model->advance(0.025f);
	if(flag_scale==0)
		Scale = Scale + 0.1;
	else
		Scale = Scale - 0.1;
	if(Scale >= 2.0 || Scale <= 0.0)
		flag_scale = !flag_scale ;
*/
//	_model->setAnimation("stand");
//	glutTimerFunc(1000,update_model,0);
}
int main(int argc, char **argv) 
{
	block_left=0.0f;
	SCORE[0]=SCORE[1]=SCORE[2]=SCORE[3]=SCORE[4]=0;
	robot_x=robot_z=0;
	robot_y=3;
	robot_rot=0.0f;
	SetupWorld();
	flag_scale=0;
	Scale = 1 ;
	glutInit(&argc, argv);  
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);  
	glutInitWindowSize(640, 480);  
	glutInitWindowPosition(0, 0);  
	window = glutCreateWindow("Jeff Molofee's GL Code Tutorial ... NeHe '99");  
	glutDisplayFunc(&DrawGLScene);  
//	glutFullScreen();
//	glutIdleFunc(IdleScene);
	glutIdleFunc(&DrawGLScene);
	glutReshapeFunc(&ReSizeGLScene);
	glutKeyboardFunc(&keyPressed);

	glutSpecialFunc(&specialKeyPressed);
	glutKeyboardUpFunc(keyUp);
	glutTimerFunc(100,update,0);
	InitGL(640, 480);
	glutMainLoop();  
	return 1;
}


void InitGL(int Width, int Height)	        // We call this right after our OpenGL window is created.
{

	LoadGLTextures();
//	printf("jere");
	glEnable(GL_TEXTURE_2D);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);		// This Will Clear The Background Color To Black
	glClearDepth(1.0);				// Enables Clearing Of The Depth Buffer
	glDepthFunc(GL_LESS);			        // The Type Of Depth Test To Do
	glEnable(GL_DEPTH_TEST);		        // Enables Depth Testing
	glShadeModel(GL_SMOOTH);			// Enables Smooth Color Shading
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();				// Reset The Projection Matrix
//	gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);	// Calculate The Aspect Ratio Of The Window
	//  gluLookAt(0.0f,10.0f,0.0f,0.0f,0.0f,0.0f,0,1,0);
// ----->> LOADING OUR MODEL !! :D :D :D :D !! 
	_model = MD2Model::load("model.md2");
	_model->setAnimation("stand");

//	glMatrixMode(GL_MODELVIEW);
}



void ReSizeGLScene(int Width, int Height)
{
	printf("here in resize \n");
	if (Height==0)				// Prevent A Divide By Zero If The Window Is Too Small
		Height=1;
	glViewport(0, 0, Width, Height);		// Reset The Current Viewport And Perspective Transformation
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();	
	gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);
	gluLookAt(0.0f,10.0f,10.0f,0.0f,0.0f,-10.0f,0,1,0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void drawblock(float x,float y,float z , float scale){
//	printf("here drawing for %f %f %f\n",x,y,z);	
	glBindTexture(GL_TEXTURE_2D, texture[0]);       
// Let Us Apply Textures !! :D :D :D :D !! 
	glPushMatrix();
	glTranslatef(x,y,z);


	glBegin(GL_QUADS);				// start drawing the cube.
	//Front Face
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);	// Bottom Left Of The Texture and Quad
	glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);	// Bottom Right Of The Texture and Quad
	glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  scale,  1.0f);	// Top Right Of The Texture and Quad
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  scale,  1.0f);	// Top Left Of The Texture and Quad

	// Back Face
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);	// Bottom Right Of The Texture and Quad
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  scale, -1.0f);	// Top Right Of The Texture and Quad
	glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  scale, -1.0f);	// Top Left Of The Texture and Quad
	glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);	// Bottom Left Of The Texture and Quad

	/*
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);	// Top Left Of The Texture and Quad
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f);	// Bottom Left Of The Texture and Quad
	glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  scale,  1.0f);	// Bottom Right Of The Texture and Quad
	glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  scale, -1.0f);	// Top Right Of The Texture and Quad

	// Bottom Face       
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);	// Top Right Of The Texture and Quad
	glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);	// Top Left Of The Texture and Quad
	glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);	// Bottom Left Of The Texture and Quad
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);	// Bottom Right Of The Texture and Quad
*/

	// Right face
	glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);	// Bottom Right Of The Texture and Quad
	glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  scale, -1.0f);	// Top Right Of The Texture and Quad
	glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  scale,  1.0f);	// Top Left Of The Texture and Quad
	glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);	// Bottom Left Of The Texture and Quad

	// Left Face
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);	// Bottom Left Of The Texture and Quad
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);	// Bottom Right Of The Texture and Quad
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  scale,  1.0f);	// Top Right Of The Texture and Quad
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  scale, -1.0f);	// Top Left Of The Texture and Quad
     
	glEnd();					// Done Drawing The Cube


// --> Drawing an another texture ! 


	glBindTexture(GL_TEXTURE_2D, texture[1]);   
	glBegin(GL_QUADS);				// start drawing the cube.

// Top Face
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  scale, -1.0f);	// Top Left Of The Texture and Quad
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  scale,  1.0f);	// Bottom Left Of The Texture and Quad
	glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  scale,  1.0f);	// Bottom Right Of The Texture and Quad
	glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  scale, -1.0f);	// Top Right Of The Texture and Quad

	// Bottom Face       
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);	// Top Right Of The Texture and Quad
	glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);	// Top Left Of The Texture and Quad
	glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);	// Bottom Left Of The Texture and Quad
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);	// Bottom Right Of The Texture and Quad

	glEnd();


	glPopMatrix();
}
void SetupWorld() 
{
	FILE *filein;        // file to load the world from
	char oneline[1024];
	int i,j ;
	int a[20];
	filein = fopen("map1", "rt");

	readstr(filein, oneline);
	sscanf(oneline, "%d %d\n", &x_dimension,&y_dimension);
	for (i = 0; i < x_dimension; i++){
		readstr(filein,oneline);
		sscanf(oneline,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8],&a[9],&a[10],&a[11],&a[12],&a[13],&a[14],&a[15],&a[16],&a[17],&a[18],&a[19]);
		for(j=0;j<20;j++){
			WORLD[i][j]=a[j];

		}
	}
	for (i = 0; i < x_dimension; i++){
		readstr(filein,oneline);
		sscanf(oneline,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8],&a[9],&a[10],&a[11],&a[12],&a[13],&a[14],&a[15],&a[16],&a[17],&a[18],&a[19]);

		for(j=0;j<20;j++){
			TOKENS[i][j]=a[j];

		}
	}


	fclose(filein);


	for(i=0;i<x_dimension;i++){
		for(j=0;j<y_dimension;j++){
		//	printf("%d ",TOKENS[i][j]);
		}
		printf("\n");
	}
	return ;
}
