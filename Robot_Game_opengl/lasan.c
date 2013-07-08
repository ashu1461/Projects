#include<time.h>
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
MD2Model* _model_bad;
int mousevariable = 0;
int a =0;
float d =0.01;
float jfactor;
int jump =0;
int motion_flag = 0;
/*
   let us assume that 4 kinds of types exist ! 
   1 ---> static 
   2 ---> Higher 
   3 ---> Lower
   4 ---> alternating b//w higher and lower 
 */
void render_sky();
GLfloat LightAmbient[]  = {1.0f, 0.0f, 0.0f, 1.0f};
GLfloat LightDiffuse[]  = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat LightPosition[] = {20.0f, 30.0f, -20.0f, 1.0f};
int robot_dimension(float x_dim, float y_dim, float z_dim,float angle_dim);
int falling_flag=0,falling_x,falling_y;
void exit_game(int x);
void update_animation(int x);
void update_falling_block(int x);
void update_falling_y(int x);
void update_die(int x);
int mouse_x,mouse_y,dragging;
//starting
void drawoutside();
int final_x,final_y,init_x,init_y;
void mouse(int button,int state,int x,int y);
int side_tex  = 0 , up_tex = 1 ;
float ultra_boost_factor =1.0f;
float shoot_x,shoot_y,shoot_z,shoot_rot;
int mega_shoot_flag=0;
float mega_shoot_x,mega_shoot_z;
float mega_shoot_y,mega_shoot_rot;
int current_animation = 0;
int lookAt_flag=0;
float y_flag = 0;
void perform_jump(int z);
int w_flag = 1 ; 
float block_left ; 
int SCORE[5];
void makecoin(float x,float y,float z,int t_id);
void Robot_func();
int rotate_flag;
float robot_rot ;
float robot_x,robot_y,robot_z;

float robot1_x,robot1_y,robot1_z;
int WORLD[100][100];
int TOKENS[100][100];
int window; 
int i,j;
int shoot_flag = 0;
float  Scale ;
float rtri = 0.0f;
int flag_scale = 0 ;
void InitGL(int widht,int Height);
void ReSizeGLScene(int Width, int Height);
void drawblock(float x,float y,float z,float scale,int );
void make_boost();
float boost_factor = 1 ;
void update_boost(int a);
void update_shoot(int a);
void SetupWorld();
float heading,xpos,zpos;
//GLfloat xrot,yrot,xspeed,yspeed;
void makeRobot();
//GLfloat walkbias = 0;
//GLfloat walkbiasangle = 0;
//GLfloat lookupdown = 0.0;
const float piover180 = 0.0174532925f;
GLuint texture[10];
int x_dimension , y_dimension ; // indicates the x and the y co-ordiantes of the world ! 
char s[20][100] = {"stand","run","attack","pain","jump","flip","salute","taunt","wave","point","crstand","crwalk","crattack","crpain","crdeath","death"};
int scounter =0 ;
int LoadGLTextures();
void readstr(FILE *f, char *string)
{
    do {
        fgets(string, 255, f); // read the line
    } while ((string[0] == '/') || (string[0] == '\n'));
    return;
}

/* The main drawing function. */
void DrawGLScene()
{

    //		printf("printf here  %d %f\n",w_flag,boost_factor);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    int fx = x_dimension/2;

    if(lookAt_flag==0){

        gluLookAt(0.0f,10.0f,10.0f,0.0f,0.0f,-10.0f,0,1,0);

        glutPostRedisplay();
    }
    else if(lookAt_flag==1){

        gluLookAt(-fx+robot_x,robot_y+3,robot_z,-fx+robot_x-(float)sin(robot_rot*piover180)*1.1250f,robot_y+3.0,robot_z-(float)cos(robot_rot*piover180)*1.1250f,0,1,0);
    }

    else if(lookAt_flag==2){

        gluLookAt(-fx+robot_x+(float)sin(robot_rot*piover180)*5.0f,robot_y+3,robot_z+(float)cos(robot_rot*piover180)*5.0f,-fx+robot_x-(float)sin(robot_rot*piover180)*1.1250f,robot_y+2.7,robot_z-(float)cos(robot_rot*piover180)*1.1250f,0,1,0);
    }
    else if(lookAt_flag==3){

        gluLookAt(30.0f,20.0f,-30.0f,-10.0f,0.0f,-10.0f,0,1,0);
    }
    else if(lookAt_flag==4){

        gluLookAt(10.0f,2.0f,-10.0f,-fx+robot_x+(float)sin(robot_rot*piover180)*1.1250f,robot_y+2.7,robot_z+(float)cos(robot_rot*piover180)*1.1250f,0,1,0);

    }
    else if(lookAt_flag==5){


        gluLookAt(-fx+robot1_x/*(float)sin(180-robot_rot*piover180)*5.0f*/,robot1_y+3,robot1_z/*+(float)cos(180-robot_rot*piover180)*5.0f*/,-fx+robot_x-(float)sin(robot_rot*piover180)*1.1250f,robot_y+2.7,robot_z-(float)cos(robot_rot*piover180)*1.1250f,0,1,0);

    }

    if(w_flag == 0)	{
        _model->setAnimation("run");
    }
    else{
        if(boost_factor>2.0f)
            boost_factor=boost_factor/2;

        _model->setAnimation(s[current_animation]);
    }

render_sky();
    glTranslatef(-x_dimension/2,0,-2);

    glPushMatrix();
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
    glPopMatrix();
    // Let us draw something !! 
    int i,j;
    int make_light;
    float scale ;
    for(i=0;i<x_dimension;i=i++){
        for(j=0;j<y_dimension;j=j++){

            make_light=0;
            side_tex=0;
            up_tex =1;
            int x1 = (robot_x+1)/2;
            int y1 = -(robot_z-1)/2;
            if(x1==i&&y1==j){
                make_light = 1;
            }
            // 7 --> IT IS A TRANSPORTED BLOCK,


            glPushMatrix();
            if(WORLD[i][j]==4){
                scale = Scale;
            }
            else if(WORLD[i][j]==2){
                scale = 2.0;
            }
            else if(WORLD[i][j]==6){
                // 6 denotes moving tiles ! 
                glPushMatrix();
                side_tex = 0;
                up_tex = 1;
                drawblock(2*(float)i+block_left,3.0f,-2*(float)j,0.04,make_light);
                glPopMatrix();

            }
            else if(WORLD[i][j]==7){
                up_tex = 5;
                // make_light = 2 indicates that it is a transported block
            }
            else if(WORLD[i][j]==8){
                if((falling_flag==1)&&(falling_x==i)&&(falling_y==j))
                    make_light=2;
            }
            else
                scale=1;

            if(WORLD[i][j]!=3&&WORLD[i][j]!=6){

                drawblock(2*(float)i,0.0f,-2*(float)j,scale,make_light);
            }

            glPopMatrix();
        }
    }
    make_light = 0;
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
                    side_tex=6;
                    up_tex=7;
                    drawblock(2*(float)i,2.0f,-2*(float)j,6,make_light);
                    glPopMatrix();
                }
                else if(TOKENS[i][j]==7){
                    glPushMatrix();
                    //		glScalef(0.5f,1.0f,0.5f);
                    side_tex=6;
                    up_tex=7;
                    drawblock(2*(float)i,2.0f,-2*(float)j,4,make_light);
                    glPopMatrix();

                }
                else if(TOKENS[i][j]!=8)
                    makecoin(2*(float)i,zz,-2*(float)j,TOKENS[i][j]);
            }
            glPopMatrix();

        }
    Robot_func();
    drawoutside();
    // swap the buffers to display, since double buffering is used.
    glutSwapBuffers();
}
void Robot_func(){
    glPushMatrix();
    makeRobot();
    glPopMatrix();
}

void makeRobot(){



    int x = (robot_x+1)/2;
    int y = -(robot_z-1)/2;
    int k = WORLD[x][y];

    if(k == 3||TOKENS[x][y]==8){

        exit_game(0);

    }

    else if(k == 2 ){
        robot_y=2.7f*1.2+y_flag;
    }

    else if(k==4 ){

        robot_y=2.7f*Scale*0.5+y_flag;
    }

    else if(k==7){
        current_animation = 12;
        glutTimerFunc(3000,update_animation,0);
    }

    else if(k==8){
        falling_flag=1;
        falling_x = x;
        falling_y = y;
        glutTimerFunc(3000,update_falling_block,0);

    }

    else
        robot_y=2.7f + y_flag;


    if(TOKENS[x][y]!=0&&TOKENS[x][y]!=5&&TOKENS[x][y]!=7){
        //	printf("collected %d\n",TOKENS[x][y]-1);
        SCORE[TOKENS[x][y]-1]++;

        if(TOKENS[x][y]==3){

            boost_factor =  boost_factor*3.0f ; 
        }

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



    float r = (float)rand()/(float)RAND_MAX;
    float g = (float)rand()/(float)RAND_MAX;
    float b = (float)rand()/(float)RAND_MAX;
    glPushMatrix();

    glColor3f(1.0f,0.0f,1.0f);
    glTranslatef(robot1_x,robot1_y,robot1_z);
    glScalef(0.1f,0.1f,0.1f);
    glRotatef(180-robot_rot,0,1,0);
    glRotatef(-90.0f,1.0f,0.0f,0.0f);
    glRotatef(90.0f,0.0f,0.0f,1.0f);
    _model_bad->draw();	
    glColor3f(1.0f,1.0f,1.0f);
    glPopMatrix();
    if(shoot_flag==1){
        glPushMatrix();

        glColor3f(1.0f,0.0f,0.0f);
        glTranslatef(shoot_x,2.7,shoot_z);
        glutSolidSphere(0.2,22,22);
        glColor3f(1.0f,1.0f,1.0f);
        glPopMatrix();
    }

    if(mega_shoot_flag==1){
        glPushMatrix();

        glColor3f(r,g,b);
        glTranslatef(mega_shoot_x,2.7,mega_shoot_z);
        glutSolidSphere(0.5,22,22);
        glColor3f(1.0f,1.0f,1.0f);
    }

}


void perform_jump(int p){
    int x = (robot_x+1)/2;
    int y = -(robot_z-1)/2;
    int k = WORLD[x][y];
    printf("here y_flag=%f jfactor=%f jump=%d\n",y_flag,jfactor,jump);

    //	printf("%d %d\n",x,y);
    //	printf("%d %d\n",a,k);
    if(k==2||k==4){

        jump=0;
        robot_z -= (float)cos(robot_rot*piover180) * 0.53f*boost_factor;
        robot_x -= (float)sin(robot_rot*piover180) * 0.53f*boost_factor;
    }
    if(jump == 1)
    {
        y_flag += jfactor;
        jfactor -= 0.1;
        if(y_flag < 0.3){
            y_flag =0;
            jump=0;
        }
        robot_z -= (float)cos(robot_rot*piover180) * 0.07f*boost_factor;
        robot_x -= (float)sin(robot_rot*piover180) * 0.07f*boost_factor;
        //	printf("here y_flag=%d jfactor=%d\n",y_flag,jfactor);
    }




    // perform a trajectile projection !! :D !!

    glutTimerFunc(100,perform_jump,0);

}

void update_falling_block(int x){

    WORLD[falling_x][falling_y]=3;
}

void makecoin(float x,float y,float z,int t_id){
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture[t_id+1]);
    glTranslatef(x,y,z);
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
}


void specialKeyPressed(int key, int x, int y) 
{
    /* avoid thrashing this procedure */
    usleep(100);

    switch (key) {    

        default:
            //	printf ("Special key %d pressed. No action there yet.\n", key);
            break;
    }	
}
void mousemotion(int x,int y){
    //printf("here inside !\n ");
    //	printf("here is %d\n",mousevariable);
    if(mousevariable%2==1&&motion_flag==0)
    {
        init_x == x ;
        init_y == y ; 
        motion_flag=1;
    }
    //	else if()
    //	{
    else{
        //		printf("second time !");
        final_x = x ;
        final_y = y ;
        //		yrot = yrot + (final_x- init_x);
        //	}
}
}
void mouse(int button,int state,int x,int y){


}
void  mouse_move(int x,int y){

    if(dragging){

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
void update_animation(int x){
    current_animation = 0 ;
    if(rand()%2==0)
        robot_dimension(3.8,2.7,-20.1,0.0f);
    else
        robot_dimension(30.4, 2.7, -33.1,0.0f);
}

void update_shoot(int a){
    if(shoot_flag==1){
        shoot_x -= (float)sin(shoot_rot*piover180) * 0.5f;
        shoot_z -= (float)cos(shoot_rot*piover180) * 0.5f;
        int x1 = (shoot_x+1)/2;
        int y1 = -(shoot_z-1)/2;
        int k1 = TOKENS[x1][y1];
        if(k1==5){
            TOKENS[x1][y1]=7;
            shoot_flag = 0 ;
        }
        else if(k1==7){
            TOKENS[x1][y1]=0;
            shoot_flag = 0 ;
        }
    }
    glutTimerFunc(100,update_shoot,0);
}

/// BRAISE YOURSELF MEGA DEATH BALL IS COMING !! 
void mega_update_shoot(int a){
    if(mega_shoot_flag==1){
        if(SCORE[0]+1>4&&SCORE[2]+1>2&&SCORE[3]+1>2){

            printf("Current resources coins  %d  food %d power %d \n",SCORE[0],SCORE[1],SCORE[3]);
            mega_shoot_x -= (float)sin(mega_shoot_rot*piover180) * 0.5f;
            mega_shoot_z -= (float)cos(mega_shoot_rot*piover180) * 0.5f;
            int x1 = (mega_shoot_x+1)/2;
            int y1 = -(mega_shoot_z-1)/2;
            int k1 = TOKENS[x1][y1];
            if(k1==8){
                _model_bad->setAnimation("death");
                printf("You WIn !! :D \n \n");
                mega_shoot_flag = 0 ;
                glutTimerFunc(3000,exit_game,0);
            }
        }
        else{
            printf("Not enough resources coins  %d  food %d power %d \n",SCORE[0],SCORE[1],SCORE[3]);
            mega_shoot_flag=0;
        }
    }
    glutTimerFunc(100,mega_update_shoot,0);
}

void exit_game(int x){
    glutTimerFunc(100,update_falling_y,0);
    glutTimerFunc(1700,update_die,0);
    current_animation=3;
}
void update_falling_y(int x)
{

    robot_y +=d;
    d-=0.01;
    glutTimerFunc(400,update_falling_y,0);
}

void update_die(int x){
    exit(0);
}

void update_boost(int x){
    boost_factor = 1 ;
}
void keyPressed(unsigned char key, int x, int y) 
{

    int x1,y1,k1,k2;
    usleep(100);
    if (key == ESCAPE) 
    { 
        _model->advance(0.025f);
    }
    switch(key){
        int counter;
        int xa,ya,ka;


        case '0':
        lookAt_flag=0;
        break;

        case '1':
        lookAt_flag=1;
        break;

        case '2':
        lookAt_flag=2;
        break;
        case '3':
        lookAt_flag=3;
        break;

        case '4':
        lookAt_flag = 4;
        break;


        case '5':
        lookAt_flag = 5;
        break ;


        case 'b': 
        glutTimerFunc(1000,update_boost,0);
        break;

        case 'B': // switch the blending
        break;

        case 'f': 
        case 'F': // switch the filter
        break;
        case 'w':


        w_flag=0;
        //		_model->setAnimation("run");
        xa = (robot_x+1)/2;
        ya = -(robot_z-1)/2;
        ka =WORLD[xa][ya];	
        //			printf("-------- %d\n",ka);
        robot_x -= (float)sin(robot_rot*piover180) * 0.05f*boost_factor;
        robot_z -= (float)cos(robot_rot*piover180) * 0.05f*boost_factor;

        x1 = (robot_x+1)/2;
        y1 = -(robot_z-1)/2;
        k1 = WORLD[x1][y1];

        if((k1==2||k1==4||TOKENS[x1][y1]==5||TOKENS[x1][y1]==7)&&(ka!=2)&&(ka!=4)){
            //					printf("here ka %d\n",ka);
            robot_x += (float)sin(robot_rot*piover180) * 0.52f*boost_factor;
            robot_z += (float)cos(robot_rot*piover180) * 0.52f*boost_factor;

        }


        if(boost_factor < 3.0f)
            boost_factor=boost_factor+0.3;
        //--------

        break;
        case 's':
        w_flag=0;

        //		_model->setAnimation("run");
        robot_x += (float)sin(robot_rot*piover180) * 0.05f*boost_factor;
        robot_z += (float)cos(robot_rot*piover180) * 0.05f*boost_factor;

        x1 = (robot_x+1)/2;
        y1 = -(robot_z-1)/2;
        k1 = WORLD[x1][y1];

        if((k1==2||k1==4||TOKENS[x1][y1]==5||TOKENS[x1][y1]==7)&&(y_flag!=-1)){

            robot_x -= (float)sin(robot_rot*piover180) * 0.52f*boost_factor;
            robot_z -= (float)cos(robot_rot*piover180) * 0.52f*boost_factor;
        }
        if(boost_factor < 3.0f)

            boost_factor=boost_factor+0.3;
        //			robot_rot = 360 - robot_rot;
        break;

        case 'j':
            if(jump!=1){
            jfactor=0.6;
                        jump=1;
            //			printf("here\n");
                        glutTimerFunc(10,perform_jump,0);
                        //			robot_z=robot_z-2;
            }
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
        counter = scounter;
        _model->setAnimation(s[scounter]);
        printf("executing %s\n",s[counter]);
        break;

        case 'r':
        shoot_flag=1;
        shoot_x = robot_x ;
        shoot_y = robot_y ;
        shoot_z = robot_z ;
        shoot_rot = robot_rot ;
        break;


        case 'm':
        mega_shoot_flag=1;
        mega_shoot_x = robot_x ;
        mega_shoot_y = robot_y ;
        mega_shoot_z = robot_z ;
        mega_shoot_rot = robot_rot ;
        break;

        case ']':

        robot_dimension(3.8,2.7,-20.1,0.0f);
        break;

        case '[':
        printf("the values of the robot are === > %f %f %f\n",robot_x,robot_y,robot_z);
        break;
        case 'c':

            SCORE[0]=SCORE[1]=SCORE[3]=SCORE[2]=10;
        break;
    }

}
void update(int value){

    _model_bad->advance(0.025f);
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
    glutTimerFunc(100,update,0);

}
int robot_dimension(float x_dim, float y_dim, float z_dim,float angle_dim){
    robot_x = x_dim;
    robot_y = y_dim;
    robot_z = z_dim;
    robot_rot=angle_dim;
}

int main(int argc, char **argv) 
{

    srand(time(0));
    block_left=0.0f;
    SCORE[0]=SCORE[1]=SCORE[2]=SCORE[3]=SCORE[4]=0;
    //	robot_x=10;
    //	robot_z=-2;
    //	robot_y=3;
    robot_dimension(10.0f,3.0f,-2.0f,0.0f);


    robot1_x = 15;
    robot1_z =-15;
    robot1_y = 3;



    SetupWorld();
    flag_scale=0;
    Scale = 1 ;
    glutInit(&argc, argv);  
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);  
    glutInitWindowSize(640, 480);  
    glutInitWindowPosition(0, 0);  
    window = glutCreateWindow("Jeff Molofee's GL Code Tutorial ... NeHe '99");  
    glutDisplayFunc(DrawGLScene);  
    //	glutFullScreen();
    glutIdleFunc(DrawGLScene);
    glutReshapeFunc(&ReSizeGLScene);
    glutKeyboardFunc(&keyPressed);
    glutMouseFunc(mouse);
    glutMotionFunc(mousemotion);
    glutSpecialFunc(&specialKeyPressed);
    glutKeyboardUpFunc(keyUp);
    glutTimerFunc(100,update,0);
    glutTimerFunc(100,update_shoot,0);
    glutTimerFunc(100,mega_update_shoot,0);
    InitGL(640, 480);
    glutMainLoop();  
    return 1;
}


void InitGL(int Width, int Height)	        // We call this right after our OpenGL window is created.
{

    LoadGLTextures();
    glEnable(GL_TEXTURE_2D);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);		// This Will Clear The Background Color To Black
    glClearDepth(1.0);				// Enables Clearing Of The Depth Buffer
    glDepthFunc(GL_LESS);			        // The Type Of Depth Test To Do
    glEnable(GL_DEPTH_TEST);		        // Enables Depth Testing
    glShadeModel(GL_SMOOTH);			// Enables Smooth Color Shading
    _model = MD2Model::load("model.md2");
    _model->setAnimation("stand");
    _model_bad = MD2Model::load("model.md2");
    _model_bad->setAnimation("attack");
    glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);	
    glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);
    glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);
    glEnable(GL_LIGHT1);	
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
    glLoadIdentity();
}

void drawblock(float x,float y,float z , float scale,int make_light){
    glBindTexture(GL_TEXTURE_2D, texture[side_tex]);       
    glPushMatrix();
    glTranslatef(x,y,z);
    if(up_tex==1)
        glColor3f(0.0f,0.5f,0.0f);
    glBegin(GL_QUADS);				// start drawing the cube.
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);	// Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);	// Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  scale,  1.0f);	// Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  scale,  1.0f);	// Top Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);	// Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  scale, -1.0f);	// Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  scale, -1.0f);	// Top Left Of The Texture and Quad
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);	// Bottom Left Of The Texture and Quad
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

    glColor3f(1.0f,1.0f,1.0f);
    glEnd();					// Done Drawing The Cube


    // --> Drawing an another texture ! 


    glBindTexture(GL_TEXTURE_2D, texture[up_tex]);   
    glBegin(GL_QUADS);				// start drawing the cube.
    if(make_light==1){

        glColor3f(0.0f,0.0f,1.0f);
    }
    else if(make_light==2){

        float r = (float)rand()/(float)RAND_MAX;
        float g = (float)rand()/(float)RAND_MAX;
        float b = (float)rand()/(float)RAND_MAX;
        glColor3f(r,g,b);
    }

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
    glColor3f(1.0f,1.0f,1.0f);
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
        //("\n");
    }
    return ;
}
int LoadGLTextures()                                    // Load Bitmaps And Convert To Textures
{


    //	float robot1_x,robot1_y,robot1_z;
    // texture123
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

    texture[6] = SOIL_load_OGL_texture
        (
         "./wall5.bmp",
         SOIL_LOAD_AUTO,
         SOIL_CREATE_NEW_ID,
         SOIL_FLAG_INVERT_Y
        );
    glBindTexture(GL_TEXTURE_2D, texture[6]);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);


    texture[7] = SOIL_load_OGL_texture
        (
         "./wall_top.bmp",
         SOIL_LOAD_AUTO,
         SOIL_CREATE_NEW_ID,
         SOIL_FLAG_INVERT_Y
        );
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);


    texture[1] = SOIL_load_OGL_texture
        (
         "./floor1.bmp",
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


    texture[8] = SOIL_load_OGL_texture
        (
         "./mywall.bmp",
         SOIL_LOAD_AUTO,
         SOIL_CREATE_NEW_ID,
         SOIL_FLAG_INVERT_Y
        );
    glBindTexture(GL_TEXTURE_2D, texture[8]);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);


    texture[10] = SOIL_load_OGL_texture
        (
         "./1a.bmp",
         SOIL_LOAD_AUTO,
         SOIL_CREATE_NEW_ID,
         SOIL_FLAG_INVERT_Y
        );
    glBindTexture(GL_TEXTURE_2D, texture[10]);

    texture[11] = SOIL_load_OGL_texture
        (
         "./2a.bmp",
         SOIL_LOAD_AUTO,
         SOIL_CREATE_NEW_ID,
         SOIL_FLAG_INVERT_Y
        );
    glBindTexture(GL_TEXTURE_2D, texture[11]);
    texture[12] = SOIL_load_OGL_texture
        (
         "./3a.bmp",
         SOIL_LOAD_AUTO,
         SOIL_CREATE_NEW_ID,
         SOIL_FLAG_INVERT_Y
        );
    glBindTexture(GL_TEXTURE_2D, texture[12]);
    texture[13] = SOIL_load_OGL_texture
        (
         "./4a.bmp",
         SOIL_LOAD_AUTO,
         SOIL_CREATE_NEW_ID,
         SOIL_FLAG_INVERT_Y
        );
    glBindTexture(GL_TEXTURE_2D, texture[13]);
    texture[14] = SOIL_load_OGL_texture
        (
         "./5a.bmp",
         SOIL_LOAD_AUTO,
         SOIL_CREATE_NEW_ID,
         SOIL_FLAG_INVERT_Y
        );
    glBindTexture(GL_TEXTURE_2D, texture[14]);
    texture[15] = SOIL_load_OGL_texture
        (
         "./6a.bmp",
         SOIL_LOAD_AUTO,
         SOIL_CREATE_NEW_ID,
         SOIL_FLAG_INVERT_Y
        );
    glBindTexture(GL_TEXTURE_2D, texture[15]);

    // Typical Texture Generation Using Data From The Bitmap
    return 1;                                        // Return Success
}



void drawoutside(){

    // in the drawoutside functio n
    // xdimension 
    // y dimension

    // make from  2*dimension , 0 2*dimension , -2*dimension 
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture[8]);       
    // Let Us Apply Textures !! :D :D :D :D !! 
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(2*x_dimension,0.0f,  2*y_dimension);	// Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f(2*x_dimension, 0.0f, -3*y_dimension);	// Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f(2.6*x_dimension, 0.0f,-3*y_dimension);	// Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f(2.6*x_dimension,0.0f,2*y_dimension);	// Top Left Of The Texture and Quad

    glTexCoord2f(0.0f, 0.0f); glVertex3f(2.6*x_dimension, 0.0f,-3*y_dimension);	// Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f(2.6*x_dimension, 0.0f,2*y_dimension);	// Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f(2.6*x_dimension, x_dimension,2*y_dimension);	// Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f(2.6*x_dimension,x_dimension,-3*y_dimension);	// Top Left Of The Texture and Quad


    glTexCoord2f(0.0f, 0.0f); glVertex3f(0,0.0f,  2*y_dimension);	// Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0, 0.0f, -3*y_dimension);	// Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.6, 0.0f,-3*y_dimension);	// Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.6,0.0f,2*y_dimension);	// Top Left Of The Texture and Quad

    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.6, 0.0f,-3*y_dimension);	// Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.6, 0.0f,2*y_dimension);	// Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.6, x_dimension,2*y_dimension);	// Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.6,x_dimension,-3*y_dimension);
    //------------------------------------------------------------------------------------------------
    glTexCoord2f(0.0f, 0.0f); glVertex3f(3.6*x_dimension,0.0f,  -3*y_dimension);	// Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f(3.6*x_dimension, 0.0f, -2*y_dimension);	// Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.6, 0.0f,-2*y_dimension);	// Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.6,0.0f,-3*y_dimension);	// Top Left Of The Texture and Quad

    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.6, x_dimension,-3*y_dimension);	// Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.6, 0.0f,-3*y_dimension);	// Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f(3.6*x_dimension, 0.0f,-3*y_dimension);	// Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f(3.6*x_dimension,x_dimension,-3*y_dimension);

    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.6, 0.0f,+y_dimension);	// Bottom Left Of The Texture and Quad
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.6, 0.0f,+0.0f);	// Bottom Right Of The Texture and Quad
    glTexCoord2f(1.0f, 1.0f); glVertex3f(3.6*x_dimension, 0.0f,+0.0f);	// Top Right Of The Texture and Quad
    glTexCoord2f(0.0f, 1.0f); glVertex3f(3.6*x_dimension,0.0f,+y_dimension);

    glEnd();
    glPopMatrix();

}
void render_sky()
{
    glPushMatrix();		    // Store the current matrix
    glLoadIdentity();
    //gluLookAt(0,0,0,-250,100,-250,0,1,0);	    // Reset and transform the matrix.
    glPushAttrib(GL_ENABLE_BIT);		    // Enable/Disable features
    glEnable(GL_TEXTURE_2D);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_BLEND);
    glColor4f(1,1,1,1);
    //printf("here\n");
    //front quad
    glBindTexture(GL_TEXTURE_2D, texture[10]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f(  0.5f, -0.5f, -0.5f );
    glTexCoord2f(1, 0); glVertex3f( -0.5f, -0.5f, -0.5f );
    glTexCoord2f(1, 1); glVertex3f( -0.5f,  0.5f, -0.5f );
    glTexCoord2f(0, 1); glVertex3f(  0.5f,  0.5f, -0.5f );
    glEnd();

    //left
    glBindTexture(GL_TEXTURE_2D, texture[11]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f(  0.5f, -0.5f,  0.5f );
    glTexCoord2f(1, 0); glVertex3f(  0.5f, -0.5f, -0.5f );
    glTexCoord2f(1, 1); glVertex3f(  0.5f,  0.5f, -0.5f );
    glTexCoord2f(0, 1); glVertex3f(  0.5f,  0.5f,  0.5f );
    glEnd();

    //back
    glBindTexture(GL_TEXTURE_2D, texture[12]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f( -0.5f, -0.5f,  0.5f );
    glTexCoord2f(1, 0); glVertex3f(  0.5f, -0.5f,  0.5f );
    glTexCoord2f(1, 1); glVertex3f(  0.5f,  0.5f,  0.5f );
    glTexCoord2f(0, 1); glVertex3f( -0.5f,  0.5f,  0.5f );
    glEnd();

    //right
    glBindTexture(GL_TEXTURE_2D, texture[13]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f( -0.5f, -0.5f, -0.5f );
    glTexCoord2f(1, 0); glVertex3f( -0.5f, -0.5f,  0.5f );
    glTexCoord2f(1, 1); glVertex3f( -0.5f,  0.5f,  0.5f );
    glTexCoord2f(0, 1); glVertex3f( -0.5f,  0.5f, -0.5f );
    glEnd();

    //top
    glBindTexture(GL_TEXTURE_2D, texture[14]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 1); glVertex3f( -0.5f,  0.5f, -0.5f );
    glTexCoord2f(0, 0); glVertex3f( -0.5f,  0.5f,  0.5f );
    glTexCoord2f(1, 0); glVertex3f(  0.5f,  0.5f,  0.5f );
    glTexCoord2f(1, 1); glVertex3f(  0.5f,  0.5f, -0.5f );
    glEnd();

    //bottom
    glBindTexture(GL_TEXTURE_2D, texture[15]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f( -0.5f, -0.5f, -0.5f );
    glTexCoord2f(0, 1); glVertex3f( -0.5f, -0.5f,  0.5f );
    glTexCoord2f(1, 1); glVertex3f(  0.5f, -0.5f,  0.5f );
    glTexCoord2f(1, 0); glVertex3f(  0.5f, -0.5f, -0.5f );
    glEnd();

    // Restore enable bits and matrix
    glPopAttrib();
    glPopMatrix();
}
