#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <stdlib.h>
// #include "Moviment2.hpp"
// #include "Animation.hpp"
#include "Drawer.hpp"
using namespace Moviments;
using namespace Animations;
using namespace std;

GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_shininess[] = { 25.0 };
GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
GLfloat angle = 60, fAspect;
int rotate = 0.0;
int rotateControl=0;
float desX=0;
float xPosition=0;
int camera=1;
int perspective=1;
Animation doll(12);
Drawer body;

void init(void)
{
    doll.get_moviment(1)->set_moviment(0,0.0,0.0,
                                    5.0,-15.0,-5.0,
                                    0.0,-15.0,5.0,
                                    5.0,15.0,
                                    0.0,15.0
                                );
    doll.get_moviment(2)->set_moviment(0,0.0,0.0,
                                    10.0,-15.0,-10.0,
                                    -5.0,-15.0,10.0,
                                    10.0,15.0,
                                    -5.0,15.0
                                );
    doll.get_moviment(3)->set_moviment(0,0.0,0.0,
                                    15.0,-15.0,-15.0,
                                    -10.0,-15.0,15.0,
                                    15.0,15.0,
                                    -10.0,15.0
                                );
    doll.get_moviment(4)->set_moviment(0,0.0,0.0,
                                    20.0,-15.0,0.0,
                                    -5.0,-15.0,0.0,
                                    20.0,15.0,
                                    -5.0,15.0
                                );
    doll.get_moviment(5)->set_moviment(0,0.0,0.0,
                                    15.0,-15.0,0.0,
                                    5.0,-15.0,0.0,
                                    15.0,15.0,
                                    5.0,15.0
                                );
    doll.get_moviment(6)->set_moviment(0,0.0,0.0,
                                    10.0,-15.0,0.0,
                                    10.0,-15.0,0.0,
                                    10.0,15.0,
                                    10.0,15.0
                                );
    doll.get_moviment(7)->set_moviment(0,0.0,0.0,
                                    5.0,-15.0,0.0,
                                    15.0,-15.0,0.0,
                                    5.0,15.0,
                                    15.0,15.0
                                );
    doll.get_moviment(8)->set_moviment(0,0.0,0.0,
                                    -5.0,-15.0,0.0,
                                    20.0,-15.0,0.0,
                                    -5.0,15.0,
                                    20.0,15.0
                                );
    doll.get_moviment(9)->set_moviment(0,0.0,0.0,
                                    -10.0,-15.0,0.0,
                                    15.0,-15.0,0.0,
                                    -10.0,15.0,
                                    15.0,15.0
                                );
    doll.get_moviment(10)->set_moviment(0,0.0,0.0,
                                    -5.0,-15.0,0.0,
                                    10.0,-15.0,0.0,
                                    -5.0,15.0,
                                    10.0,15.0
                                );
    doll.get_moviment(11)->set_moviment(0,0.0,0.0,
                                    0.0,-15.0,0.0,
                                    5.0,-15.0,0.0,
                                    0.0,15.0,
                                    5.0,15.0
                                );

    glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65, 1, 2, 500);
    glMatrixMode(GL_MODELVIEW);
    angle = 60;

    glColor3f(0.0, 0.0,0.0);
   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_DEPTH_TEST);
}

void Draw(void){

    //Ilumination
    glShadeModel (GL_SMOOTH);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_COLOR_MATERIAL);
    glClear (GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(perspective){
        gluPerspective(65, 1, 2, 500);
    }else{
        glOrtho(-4,8,-0,16,0,40);
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    switch (camera) {
        case 1:
            gluLookAt(0,0,10,
                      0,-0,0,
                      0,1,0);
            break;
        case 2:
        gluLookAt(-3,-5.,0,
            0,0,0, -1,1,0);
            break;
        case 3:
            gluLookAt(doll.get_moviment()->tx +0.2*desX -5,doll.get_moviment()->ty +20,doll.get_moviment()->tz ,
                      doll.get_moviment()->tx +0.2*desX,doll.get_moviment()->ty,doll.get_moviment()->tz,
                      0,0.1,0);
            break;
        case 4:
            gluLookAt(-6,10,0, 0,0,0, 0,1,0);
            break;
        default:
            gluLookAt(0,0,10, 0,-0,0, 0,1,0);
    }
    if(camera==3){
       xPosition=doll.get_moviment()->tx +desX*0.2;
       glTranslated(xPosition,0,0);
       glRotated(rotate,0,-1.0,0.0);
       glTranslated(-xPosition,0,0);
   }else{
       glRotated(rotate,0,-1.0,0.0);
   }
    glColor3f(0.5, 0.5,0.5);
    glPushMatrix();
    body.drawDoll(doll,desX);
    glPopMatrix();
    glutSwapBuffers();
}




void ChangeWindowSize (int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    if(h == 0) h = 1;

}

void Timer(int value)
{
    if(value > 0)
    {
        value--;
        doll.Next_Frame();
        // LeftLeg.Next_Frame();
        glutTimerFunc(200,Timer,value);
        glutPostRedisplay();
    }
}

void Keyboard(unsigned char key, int x, int y)
{
   if(key=='0'){
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      desX=0;
      rotate=0;
   }
    if(key=='1'){
        camera=1;
        cout<< camera<<endl;
    }
    if(key=='2'){
        camera=2;
        cout<< camera<<endl;
    }
    if(key=='3'){
        camera=3;
        cout<< camera<<endl;
    }
    if(key=='4'){
        camera=4;
        cout<< camera<<endl;
    }
    if(key=='5'){
        perspective=!perspective;
        cout<<perspective<<endl;
    }
    if (key == 'a')
    {
        rotate -= 5 ;
        rotate = rotate%360;
    }
    if (key == 'd')
    {
        rotate += 5 ;
        rotate = rotate%360;
    }
    if(key == 'w')
    {
        doll.Next_Frame();
        // LeftLeg.Next_Frame();
        // RightArm.Next_Frame();
        // LeftArm.Next_Frame();
        desX=desX+1;
        cout<<"x : "<< desX<<endl;
        //glutTimerFunc(200,Timer,Perna.num_quadros);

    }
    if(key=='s'){
        desX=desX-1;
        doll.Previous_Frame();
        // LeftLeg.Previous_Frame();
        // LeftArm.Previous_Frame();
        // RightArm.Previous_Frame();
    }

    glutPostRedisplay();

}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode (GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);

    glutInitWindowSize (800, 800);

    glutInitWindowPosition ((1280 - 800)/2, (800 - 800)/2);

    glutCreateWindow ("Doll");

    glutDisplayFunc(Draw);

    glutReshapeFunc(ChangeWindowSize);

    glutKeyboardFunc(Keyboard);


    init();

    glutMainLoop();
    return 0;
}
