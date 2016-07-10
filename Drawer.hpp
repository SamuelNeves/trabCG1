#include <GL/gl.h>
#include <GL/glut.h>
#include "Animation.hpp"
using namespace Animations;
class Drawer{
public:
    Drawer(){

    }

void drawPlan(){
    glColor3f(0.1,0.5,0.1);
    glPushMatrix();
    glTranslated(0.0,-6.1,0.0);
    glBegin(GL_POLYGON);
    glVertex3f(50.0,0.0,50.0);
    glVertex3f(50.0,0.0,-50.0);
    glVertex3f(-50.0,0.0,-50.0);
    glVertex3f(-50.0,0.0,50.0);
    glEnd();
    glPopMatrix();
}
void drawDoll(Animation doll,float x){
    drawPlan();
    glColor3f(1,0,0);

    glTranslated(doll.get_moviment()->tx +x*0.2,doll.get_moviment()->ty,doll.get_moviment()->tz);
    drawToraxAndHead(doll);
    rightArm(doll);
    leftArm(doll);
    leftLeg(doll);
    rightLeg(doll);
}

void drawToraxAndHead(Animation doll){
    glPushMatrix();
        GLUquadricObj* q = gluNewQuadric();
        glTranslated(0,6.2,0);
        glRotated(90,1,0,0);
        gluQuadricDrawStyle(q,GLU_SMOOTH);
        gluCylinder(q, 0.1, 1.2, 0.3, 4,4);
    glPopMatrix();
    //cabeca
    glPushMatrix();
        glTranslated(0,5.4,0);
        glutSolidSphere(0.7, 10, 10);
        glPopMatrix();
    glPushMatrix();
        glTranslated(0,4.8,0);
        glRotated(90,1,0,0);
        gluQuadricDrawStyle(q,GLU_SMOOTH);
        gluCylinder(q, 0.2, 0.8, 0.3, 5,5);
    glPopMatrix();
    //tronco
    glPushMatrix();
        glTranslated(0,4.5,0);
        glRotated(90,1,0,0);
        gluQuadricDrawStyle(q,GLU_SMOOTH);
        gluCylinder(q, 0.8, 0.5, 2.5, 10,10);
    glPopMatrix();
    glPushMatrix();
        glTranslated(0,2,0);
        glRotated(90,1,0,0);
        gluQuadricDrawStyle(q,GLU_SMOOTH);
        gluCylinder(q, 0.5, 0.8, 2.0, 10,10);
        gluDeleteQuadric(q);
    glPopMatrix();
    // Superior Cylinder-
    glutSolidSphere(0.74, 5, 5);
}
void rightArm(Animation doll){
    glPushMatrix();
        glTranslated(0,4.4,-1);
        glutSolidSphere(0.3, 5, 5);

        glRotated(doll.get_moviment()->rightArm1,0,0,1);

        glPushMatrix();
            GLUquadricObj* q = gluNewQuadric();
            glRotated(90,1,0,0);
            gluQuadricDrawStyle(q,GLU_SMOOTH);
            gluCylinder(q, 0.15, 0.15, 1.8, 10,10);
            // gluDeleteQuadric(q);
        glPopMatrix();

        glTranslated(0,-1.7,0);
        glPushMatrix();
            glutSolidSphere(0.2, 5, 5);
        glPopMatrix();

        // glRotated(bracoD.get_moviment()->rodar_eixo2,0,0,1);
        glRotated(doll.get_moviment()->rightArm2,0,0,1);

        glPushMatrix();
            glTranslated(0,-0.1,0);
            glRotated(90,1,0,0);
            gluQuadricDrawStyle(q,GLU_SMOOTH);
            gluCylinder(q, 0.15, 0.15, 2, 10,10);
        glPopMatrix();


        glPushMatrix();
            glColor3f(0,1,0);
            glTranslated(0.0,-2.2,0);
            glScalef(1,2,1);
            glColor3f(0,0,1);
            glutSolidCube (0.40);
            glColor3f(1,0,0);
        glPopMatrix();

        gluDeleteQuadric(q);

    glPopMatrix();
}
void leftArm(Animation doll){
    glPushMatrix();
        glTranslated(0,4.4,1);
        glutSolidSphere(0.3, 5, 5);
        glRotated(doll.get_moviment()->leftArm1,0,0,1);
        glPushMatrix();
            GLUquadricObj* q = gluNewQuadric();
            glRotated(90,1,0,0);
            gluQuadricDrawStyle(q,GLU_SMOOTH);
            gluCylinder(q, 0.15, 0.15, 1.8, 10,10);
            // gluDeleteQuadric(q);
            glutSolidSphere(0.2, 5, 5);
        glPopMatrix();

        glTranslated(0,-1.7,0);
        glPushMatrix();
            glutSolidSphere(0.2, 5, 5);
        glPopMatrix();


        glRotated(doll.get_moviment()->leftArm2,0,0,1);
        glPushMatrix();
            glTranslated(0,-0.1,0);
            glRotated(90,1,0,0);
            gluQuadricDrawStyle(q,GLU_SMOOTH);
            gluCylinder(q, 0.15, 0.15, 2, 10,10);
            gluDeleteQuadric(q);
        glPopMatrix();

        glPushMatrix();
            glColor3f(0,0,1);
            glTranslated(0.0,-2.2,0);
            glScalef(1,2,1);
            glutSolidCube (0.40);
            glColor3f(1,0,0);
        glPopMatrix();
        glColor3f(1,0,0);
    glPopMatrix();
}

void leftLeg(Animation doll){
    glPushMatrix();
        glRotated(doll.get_moviment()->leftLeg1,0,0,1);
        glTranslated(doll.get_moviment()->tx,doll.get_moviment()->ty,doll.get_moviment()->tz);
        glTranslated(0,0,0.5);
        glPushMatrix();
            GLUquadricObj* q = gluNewQuadric();
            glRotated(90,1,0,0);
            gluQuadricDrawStyle(q,GLU_SMOOTH);
            gluCylinder(q, 0.2, 0.2, 3.0, 10,10);
        glPopMatrix();
            glTranslated(0,-3,0);
            glRotated(doll.get_moviment()->leftLeg2,0,0,1);
            glPushMatrix();
                //Sphere
            glutSolidSphere(0.37, 10, 5);
                //Inferior Cylinder
            glRotated(90,1,0,0);
            gluQuadricDrawStyle(q,GLU_SMOOTH);
            gluCylinder(q, 0.2, 0.2, 3.0, 10,10);
            gluDeleteQuadric(q);
        glPopMatrix();
        //

        glColor3f(0,0,1);
        glPushMatrix();
            glTranslated(0,-2.68,0);
            glutSolidSphere(0.37, 10, 5);
        glPopMatrix();

        glPushMatrix();
            glTranslated(0.6,-2.688,0);
            glRotated(doll.get_moviment()->leftLeg3,0,0,1);
            glScalef(2.2,1,1);
            glutSolidCube (0.50);
        glPopMatrix();
        glColor3f(1,0,0);
    glPopMatrix();
}

void rightLeg(Animation doll){

            glPushMatrix();
                glRotated(doll.get_moviment()->rightLeg1,0,0,1);
                glTranslated(doll.get_moviment()->tx,doll.get_moviment()->ty,doll.get_moviment()->tz);
                glTranslated(0,0,-0.5);
                glPushMatrix();
                    GLUquadricObj* q = gluNewQuadric();
                    glRotated(90,1,0,0);
                    gluQuadricDrawStyle(q,GLU_SMOOTH);
                    gluCylinder(q, 0.2, 0.2, 3.0, 10,10);
                glPopMatrix();

                glTranslated(0,-3,0);

                glRotated(doll.get_moviment()->rightLeg2,0,0,1);

                glPushMatrix();
                        //Sphere
                        glutSolidSphere(0.37, 10, 5);
                        //  GLUquadricObj* q = gluNewQuadric();
                        //Inferior Cylinder
                        glRotated(90,1,0,0);
                        gluQuadricDrawStyle(q,GLU_SMOOTH);
                        gluCylinder(q, 0.2, 0.2, 3.0, 10,10);
                        gluDeleteQuadric(q);
                        // glTranslated(1,0,2);
                glPopMatrix();
                glColor3f(0,0,1);
                glPushMatrix();
                    glTranslated(0,-2.68,0);
                    glutSolidSphere(0.37, 10, 5);
                glPopMatrix();
                glPushMatrix();
                    glTranslated(0.6,-2.688,0);
                    glRotated(doll.get_moviment()->rightLeg3,0,0,1);
                    glScalef(2.2,1,1);
                    glutSolidCube (0.50);
                glPopMatrix();
                glColor3f(1,0,0);
            glPopMatrix();
}
};
