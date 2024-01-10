#include <GL/glut.h>
#include "assignment.hpp"
#include<time.h>
#include "BmpLoader.h"


using namespace assignment;
MyBubbles::MyBubbles()
{

 srand(time(0));
 timetick = 0;
 vel0  =  0.006;
 accel = -0.00000000001;
}

void MyBubbles::draw(MyBubbles mybubble, int k, int z)
{
 y = vel0*timetick + 0.5*accel*timetick*timetick;


 if (y >=15.0)
 {
    y =0.0;
    timetick=0;
 }
 else{
     glPushMatrix();
     glColor3f(1.0f, 1.0f, 1.0f );
     glTranslatef(k, y, z);
     glutSolidSphere(0.5,16,16);
     glutPostRedisplay();

     glColor3f(1.0f, 1.0f, 1.0f );
     glTranslatef(k, y, z+5);
     glutSolidSphere(0.5,16,16);
     glutPostRedisplay();

     glColor3f(1.0f, 1.0f, 1.0f );
     glTranslatef(k-9, y, z+2);
     glutSolidSphere(0.5,16,16);
     glutPostRedisplay();

     glColor3f(1.0f, 1.0f, 1.0f );
     glTranslatef(k+5, y, z-9);
     glutSolidSphere(0.5,16,16);
     glutPostRedisplay();

     glColor3f(1.0f, 1.0f, 1.0f );
     glTranslatef(k+14, y, z-15);
     glutSolidSphere(0.5,16,16);
     glutPostRedisplay();

      glColor3f(1.0f, 1.0f, 1.0f );
     glTranslatef(k-12, y, z+5);
     glutSolidSphere(0.5,16,16);
     glutPostRedisplay();

      glColor3f(1.0f, 1.0f, 1.0f );
     glTranslatef(k+21, y, z+7);
     glutSolidSphere(2.0,16,16);
     glutPostRedisplay();

      glColor3f(1.0f, 1.0f, 1.0f );
     glTranslatef(k+1, y, z-8);
     glutSolidSphere(2.0,16,16);
     glutPostRedisplay();

     glColor3f(1.0f, 1.0f, 1.0f );
     glTranslatef(k+12, y, z+15);
     glutSolidSphere(2.0,16,16);
     glutPostRedisplay();
     glPopMatrix();
     }

}



void MyBubbles::tickTime(long int elapseTime)
{
 timetick += elapseTime;
};


void MySands::draw()
{
    glDisable(GL_CULL_FACE);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureMapping);

    glBegin(GL_QUAD_STRIP);
    glColor3f(0.9f, 0.698f, 0.52f );
    glTexCoord2f(0.0, 0.0); glVertex3f(-500.0f, 0.0f, -300.0f );
    glTexCoord2f(1.0, 0.0); glVertex3f(-500.0f, 0.0f, 300.0f );
    glTexCoord2f(1.0, 1.0); glVertex3f(500.0f, 0.0f, -300.0f );
    glTexCoord2f(0.0, 1.0); glVertex3f(500.0f, 0.0f, 300.0f );
    glEnd();

    glDisable(GL_TEXTURE_2D);
    glEnable(GL_CULL_FACE);
}

void MySands::init()
{

    BmpLoader image("textures/ocean_floor.bmp");

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glGenTextures(1, &textureMapping);
    glBindTexture(GL_TEXTURE_2D, textureMapping);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL );

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);

    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, image.iWidth, image.iHeight, GL_RGB, GL_UNSIGNED_BYTE, image.textureData);
}


void MyPatrickHouse::draw()
{
    glDisable(GL_CULL_FACE);
    GLUquadricObj *pObj;
    pObj = gluNewQuadric();
    //try one of these drawing style
    gluQuadricDrawStyle(pObj, GLU_FILL);
    //gluQuadricDrawStyle(pObj, GLU_LINE);
    //gluQuadricDrawStyle(pObj, GLU_POINT);
    //gluQuadricDrawStyle(pObj, GLU_SILHOUETTE);
    //try one of these surface normals mode
    //gluQuadricNormals(pObj, GLU_NONE);
    gluQuadricNormals(pObj, GLU_SMOOTH);
    //gluQuadricNormals(pObj, GLU_FLAT);

    glPushMatrix();
    //Patrick house
    glColor3f(0.1f, 0.1f, 0.0f);
    glTranslatef(-20.0f, 0.0f, 0.0f);
    gluSphere(pObj, 8.0f, 24, 12);

    //astro
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, -11.7f);
    gluCylinder(pObj, 0.6f, 0.6f, 4.0f, 72, 4);

    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(83.0f, 0.0f, 1.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, -4.0f);
    gluCylinder(pObj, 0.5f, 0.5f, 10.0f, 72, 4);

    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(120.0f, 0.0f, 1.0f, 0.0f);
    glTranslatef(0.0f, 0.0f, -3.0f);
    gluCylinder(pObj, 0.5f, 0.5f, 3.0f, 72, 4);

    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(85.0f, 0.0f, 1.0f, 0.0f);
    glTranslatef(-3.5f, 0.0f, -3.3f);
    gluCylinder(pObj, 0.5f, 0.5f, 4.0f, 72, 4);

    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(62.0f, 0.0f, 1.0f, 0.0f);
    glTranslatef(6.0f, 0.0f, -0.5f);
    gluCylinder(pObj, 0.3f, 0.3f, 4.5f, 72, 4);

    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glTranslatef(-1.5f, 0.0f, 0.0f);
    gluCylinder(pObj, 0.3f, 0.3f, 4.5f, 72, 4);
    glPopMatrix();

    glEnable(GL_CULL_FACE);

}


void MySquid::draw()
{
    glDisable(GL_CULL_FACE);
    GLUquadricObj *pObj;
    pObj = gluNewQuadric();
    //body
    glPushMatrix();
    glColor3f(0.4f, 0.6f, 0.8f);
    glTranslatef(10.0f, 20.0f, 0.0f);
    glRotatef(90.0f,1.0f,0.0f,0.0f);
    gluCylinder(pObj, 3.0f, 5.0f, 20.0f, 24, 72);
    glPopMatrix();

    //celling
    glPushMatrix();
    glColor3f(0.4f, 0.6f, 0.8f);
    glTranslatef(10.0f, 20.0f, 0.0f);
    glRotatef(90.0f,1.0f,0.0f,0.0f);
    gluDisk(pObj, 0.0f, 3.0f, 26, 13);
    glPopMatrix();

    //left ears
    glPushMatrix();
    glColor3f(0.098f, 0.098f, 0.478f);
    glTranslatef(5.7f, 15.0f, 0.0f);
    glRotatef(90.0f,1.0f,0.0f,0.0f);
    glRotatef(-5.0f,0.0f,1.0f,0.0f);
    gluCylinder(pObj, 0.8f, 0.8f, 5.5f, 24, 72);

    glPopMatrix();
    //right ears
    glPushMatrix();
    glColor3f(0.098f, 0.098f, 0.478f);
    glTranslatef(14.0f, 15.0f, 0.0f);
    glRotatef(90.0f,1.0f,0.0f,0.0f);
    glRotatef(5.0f,0.0f,1.0f,0.0f);
    gluCylinder(pObj, 0.8f, 0.8f, 5.5f, 24, 72);

    glPopMatrix();
    //face
    glPushMatrix();
    glColor3f(0.098f, 0.098f, 0.478f);
    glTranslatef(7.5f, 15.5f, 3.5f);
    glRotatef(90.0f,0.0f,1.0f,0.0f);
    gluCylinder(pObj, 0.6f, 0.6f, 4.5f, 24, 72);

    glPopMatrix();
    //nose
    glPushMatrix();
    glColor3f(0.33f, 0.33f, 0.33f);
    glTranslatef(9.7f, 15.5f, 4.0f);
    glRotatef(90.0f,1.0f,0.0f,0.0f);
    gluCylinder(pObj, 0.6f, 0.9f, 7.5f, 24, 72);

    glPopMatrix();
    //left eyes
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(8.0f, 14.0f, 3.0f);
    gluSphere(pObj, 1.0f, 24, 12);
    glPopMatrix();

    //right eyes
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(11.3f, 14.0f, 3.0f);
    gluSphere(pObj, 1.0f, 24, 12);
    glPopMatrix();

    //door
    glBegin(GL_QUADS);
    glColor3f(0.482f, 0.247f, 0.0f);
    glVertex3f( 8.0f, 5.0f, 4.5f );
    glVertex3f( 8.0f, 0.0f, 5.5f );
    glVertex3f( 11.0f, 0.0f, 5.5f );
    glVertex3f( 11.0f, 5.0f, 4.5f );
    glEnd();

    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(10.5f, 3.0f, 4.9f);
    gluSphere(pObj, 0.3f, 24, 12);
    glPopMatrix();

    glEnable(GL_CULL_FACE);

}


void MyPineapple::draw()
{
    glDisable(GL_CULL_FACE);
    GLUquadricObj *pObj;
    pObj = gluNewQuadric();

    //body
    glPushMatrix();
    glColor3f(1.0f, 0.5f, 0.0f);
    glTranslatef(40.0f, -4.0f, 0.0f);
    glRotatef(270.0f,1.0f,0.0f,0.0f);
    gluCylinder(pObj, 8.0f, 3.5f, 23.0f, 10, 13);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f);
    gluQuadricDrawStyle(pObj, GLU_LINE);
    gluQuadricNormals(pObj, GLU_NONE);
    glTranslatef(40.0f, -4.0f, 0.0f);
    glRotatef(270.0f,1.0f,0.0f,0.0f);
    gluCylinder(pObj, 8.1f, 3.6f, 23.0f, 8, 5);
    glPopMatrix();

    //window
    glPushMatrix();
    gluQuadricDrawStyle(pObj, GLU_FILL);
    gluQuadricNormals(pObj, GLU_SMOOTH);
    glColor3f(0.0f, 0.5f, 1.0f);
    glTranslatef(38.0f, 10.0f, 4.2f);
    gluSphere(pObj, 1.5f, 24, 12);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(38.0f, 10.2f, 5.0f);
    gluSphere(pObj, 1.0f, 24, 12);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0f, 0.5f, 1.0f);
    glTranslatef(44.0f, 3.0f, 4.0f);
    gluSphere(pObj, 1.5f, 24, 12);

    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(0.7f, 0.2f, 0.8f);
    gluSphere(pObj, 1.0f, 24, 12);
    glPopMatrix();

    //door
    glBegin(GL_QUADS);
    glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
    glVertex3f( 39.0f, 5.0f, 6.5f );
    glVertex3f( 39.0f, 0.0f, 7.2f );
    glVertex3f( 42.5f, 0.0f, 7.2f );
    glVertex3f( 42.5f, 5.0f, 6.5f );
    glEnd();

    glPushMatrix();
    glColor3f(0.0f, 0.5f, 1.0f);
    glTranslatef(41.0f, 2.5f, 6.5f);
    gluSphere(pObj, 0.7f, 24, 12);

    glColor3f(0.0f, 0.5f, 1.0f);
    glRotatef(90.0f,1.0f,1.0f,0.0f);
    glTranslatef(-0.3f, 0.5f, -1.1f);
    gluCylinder(pObj, 0.1f, 0.1f, 2.3f, 8, 5);

    glColor3f(0.0f, 0.5f, 1.0f);
    glRotatef(105.0f,0.0f,2.0f,1.0f);
    glTranslatef(-0.9f, 0.7f, -1.0f);
    gluCylinder(pObj, 0.1f, 0.1f, 2.3f, 8, 5);
    glPopMatrix();

    //celling
    glPushMatrix();
    glColor3f(1.0f, 0.5f, 0.0f);
    glTranslatef(40.0f, 19.0f, 0.0f);
    glRotatef(90.0f,1.0f,0.0f,0.0f);
    gluDisk(pObj, 0.0f, 3.5f, 10, 13);
    glPopMatrix();

    //smoke pipe
    glPushMatrix();
    glColor3f(0.0f, 0.5f, 1.0f);
    glTranslatef(44.0f, 16.0f, 0.0f);
    glRotatef(90.0f,0.0f,1.0f,0.0f);
    gluCylinder(pObj, 0.5f, 0.5f, 2.5f, 10, 13);

    glColor3f(0.0f, 0.5f, 1.0f);
    glTranslatef(0.0f, 2.5f, 2.2f);
    glRotatef(90.0f,1.0f,0.0f,0.0f);
    gluCylinder(pObj, 0.5f, 0.5f, 2.5f, 10, 13);
    glPopMatrix();

    //pineapple leaves
    glPushMatrix();
    glColor3f(0.0f, 1.0f, 0.0f);
    glTranslatef(40.0f, 19.2f, 0.0f);
    glRotatef(270.0f,1.0f,0.0f,0.0f);
    gluCylinder(pObj, 1.5f, 0.1f, 5.5f, 10, 13);

    glColor3f(0.0f, 1.0f, 0.0f);
    glTranslatef(0.0f, 2.0, 0.0f);
    gluCylinder(pObj, 1.5f, 0.1f, 5.5f, 10, 13);

    glColor3f(0.0f, 1.0f, 0.0f);
    glTranslatef(2.0f, -1.0f, 0.0f);
    gluCylinder(pObj, 1.5f, 0.1f, 5.5f, 10, 13);

    glColor3f(0.0f, 1.0f, 0.0f);
    glTranslatef(0.0f, -2.0f, 0.0f);
    gluCylinder(pObj, 1.5f, 0.1f, 5.5f, 10, 13);

    glColor3f(0.0f, 1.0f, 0.0f);
    glTranslatef(-2.0f, -1.0f, 0.0f);
    gluCylinder(pObj, 1.5f, 0.1f, 5.5f, 10, 13);

    glColor3f(0.0f, 1.0f, 0.0f);
    glTranslatef(-2.0f, 1.0f, 0.0f);
    gluCylinder(pObj, 1.5f, 0.1f, 5.5f, 10, 13);

    glColor3f(0.0f, 1.0f, 0.0f);
    glTranslatef(0.0f, 2.0f, 0.0f);
    gluCylinder(pObj, 1.5f, 0.1f, 5.5f, 10, 13);
    glPopMatrix();

    glEnable(GL_CULL_FACE);
}

void MyJellyfish::draw(){
    glDisable(GL_CULL_FACE);
    GLUquadricObj *pObj;
    pObj = gluNewQuadric();

    //body
    glPushMatrix();
    glTranslatef(posx, posy, posz);
    glPushMatrix();
    glColor3f(0.0f, 0.5f, 1.0f);
    glTranslatef(-30.0f, 14.0f, 3.0f);
    gluSphere(pObj, 4.0f, 24, 12);
    glPopMatrix();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.5f, 1.0f);
    glVertex3f( -33.0f, 14.5f, 5.5f );
    glVertex3f( -33.0f, 10.0f, 5.5f );
    glVertex3f( -27.0f, 10.0f, 5.5f );
    glVertex3f( -27.0f, 14.5f, 5.5f );
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.5f, 1.0f);
    glVertex3f( -33.0f, 14.5f, 1.0f );
    glVertex3f( -33.0f, 10.0f, 1.0f );
    glVertex3f( -27.0f, 10.0f, 1.0f );
    glVertex3f( -27.0f, 14.5f, 1.0f );
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.5f, 1.0f);
    glVertex3f( -33.0f, 14.5f, 5.5f );
    glVertex3f( -33.0f, 10.0f, 5.5f );
    glVertex3f( -33.0f, 10.0f, 1.0f );
    glVertex3f( -33.0f, 14.5f, 1.0f );
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.5f, 1.0f);
    glVertex3f( -27.0f, 14.5f, 5.5f );
    glVertex3f( -27.0f, 10.0f, 5.5f );
    glVertex3f( -27.0f, 10.0f, 1.0f );
    glVertex3f( -27.0f, 14.5f, 1.0f );
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.5f, 1.0f);
    glVertex3f( -33.0f, 10.0f, 5.5f );
    glVertex3f( -33.0f, 10.0f, 1.0f );
    glVertex3f( -27.0f, 10.0f, 5.5f );
    glVertex3f( -27.0f, 10.0f, 1.0f );
    glEnd();

    //leg
    glPushMatrix();
    glColor3f(0.0f, 0.7f, 1.0f);
    glTranslatef(-29.0f, 11.0f, 1.0f);
    glRotatef(90.0f,1.0f,0.0f,0.0f);
    gluCylinder(pObj, 0.3f, 0.3f, 5.0f, 24, 72);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0f, 0.7f, 1.0f);
    glTranslatef(-29.0f, 11.0f, 5.0f);
    glRotatef(90.0f,1.0f,0.0f,0.0f);
    gluCylinder(pObj, 0.3f, 0.3f, 5.0f, 24, 72);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0f, 0.7f, 1.0f);
    glTranslatef(-31.5f, 11.0f, 5.0f);
    glRotatef(90.0f,1.0f,0.0f,0.0f);
    gluCylinder(pObj, 0.3f, 0.3f, 5.0f, 24, 72);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0f, 0.7f, 1.0f);
    glTranslatef(-31.5f, 11.0f, 1.0f);
    glRotatef(90.0f,1.0f,0.0f,0.0f);
    gluCylinder(pObj, 0.3f, 0.3f, 5.0f, 24, 72);
    glPopMatrix();
    glPopMatrix();
    glEnable(GL_CULL_FACE);

}

MyJellyfish::MyJellyfish()
{
posx, posy, posz= -30.0f, 14.0f, 3.0f;
velx = 0.0f;
vely = 0.5f;
velz = 0.5f;
}

void MyJellyfish::tickTime(long int elapseTime)
{
float elapseTimeInSec = elapseTime / 1000.0f;
posx += elapseTimeInSec * velx;
posy += elapseTimeInSec * vely;
posz += elapseTimeInSec * velz;

}

void MyFish1::draw()
{
    glDisable(GL_CULL_FACE);
    GLUquadricObj *pObj;
    pObj = gluNewQuadric();
    //fish
    glPushMatrix();
    glColor3f(0.62f, 0.64f, 0.64f);
    glTranslatef(15.0f, 10.0f, 10.0f);
    glRotatef(180.0f,0.0f,1.0f,0.0f);
    gluCylinder(pObj, 0.0f, 1.0f, 2.0f, 10, 13);

    glColor3f(0.62f, 0.64f, 0.64f);
    glTranslatef(0.0f, 0.0f, 2.0f);
    gluCylinder(pObj, 1.0f, 1.0f, 4.0f, 10, 13);

    glColor3f(0.62f, 0.64f, 0.64f);
    glTranslatef(0.0f, 0.0f, 2.0f);
    gluCylinder(pObj, 1.0f, 1.0f, 4.0f, 10, 13);


    glColor3f(0.62f, 0.64f, 0.64f);
    glTranslatef(0.0f, 0.3f, 3.0f);
    glRotatef(45.0f,1.0f,0.0f,0.0f);
    gluCylinder(pObj, 1.0f, 0.0f, 4.0f, 10, 13);

    glColor3f(0.62f, 0.64f, 0.64f);
    glTranslatef(0.0f, 0.1f, 0.2f);
    glRotatef(270.0f,1.0f,0.0f,0.0f);
    gluCylinder(pObj, 1.0f, 0.0f, 4.0f, 10, 13);
    glPopMatrix();

    //fin
    glPushMatrix();
    glColor3f(0.54f, 0.52f, 0.86f);
    glTranslatef(15.0f, 10.6f, 6.2f);
    glRotatef(247.0f,1.0f,0.0f,0.0f);
    gluCylinder(pObj, 0.6f, 0.0f, 1.5f, 10, 13);

    glColor3f(0.54f, 0.52f, 0.86f);
    glTranslatef(0.0f, 0.6f, 0.0f);
    gluCylinder(pObj, 0.6f, 0.0f, 1.5f, 10, 13);

    glColor3f(0.54f, 0.52f, 0.86f);
    glTranslatef(0.0f, 0.4f, 0.0f);
    gluCylinder(pObj, 0.6f, 0.0f, 1.5f, 10, 13);

    glColor3f(0.54f, 0.52f, 0.86f);
    glTranslatef(0.0f, 0.3f, 0.0f);
    gluCylinder(pObj, 0.6f, 0.0f, 1.5f, 10, 13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.54f, 0.52f, 0.86f);
    glTranslatef(15.5f, 9.5f, 6.5f);
    glRotatef(90.0f,1.0f,0.0f,0.0f);
    gluCylinder(pObj, 0.4f, 0.0f, 1.0f, 10, 13);
    glPopMatrix();

    //fish eye
    glPushMatrix();
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
    glTranslatef(15.5f, 10.1f, 8.7f);
    gluSphere(pObj, 0.3f, 24, 12);

    glColor3f(0.0f, 0.0f, 0.0f);
    glTranslatef(0.2f, 0.0f, 0.1f);
    gluSphere(pObj, 0.2f, 24, 12);
    glPopMatrix();

     glPushMatrix();
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
    glTranslatef(14.5f, 10.1f, 8.7f);
    gluSphere(pObj, 0.3f, 24, 12);

    glColor3f(0.0f, 0.0f, 0.0f);
    glTranslatef(-0.2f, 0.0f, 0.1f);
    gluSphere(pObj, 0.2f, 24, 12);
    glPopMatrix();

}


void MySotong::draw()
{
    glDisable(GL_CULL_FACE);
    GLUquadricObj *pObj;
    pObj = gluNewQuadric();

    glRotatef(45.0f, 0.0f, 1.0f, 0.0f);
    glPushMatrix();
    glTranslatef(posx, posy, posz);
    //head
    glPushMatrix();
    glColor3f(0.99f, 0.39f, 0.39f);
    glTranslatef(-30.0f, 50.5f, -25.0f);
    glRotatef(90.0f,1.0f,0.0f,0.0f);
    gluCylinder(pObj, 0.2f, 4.5f, 5.5f, 24, 72);

    //head2
    glColor3f(0.99f, 0.45f, 0.45f);
    glTranslatef(0.0f, 0.0f, 0.0f);
    gluCylinder(pObj, 0.5f, 5.0f, 20.5f, 24, 72);

    //head3
    glColor3f(0.99f, 0.39f, 0.39f);
    glTranslatef(0.0f, 0.0f, 20.0f );
    gluCylinder(pObj, 4.7f, 4.1f, 7.0f, 24, 72);
    glPopMatrix();

    //eyes
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(-27.3f,27.5f, -21.5f);
    gluSphere(pObj, 0.8f, 24, 12);

    glColor3f(0.0f, 0.0f, 0.0f);
    glTranslatef(0.0f,0.0f, 0.3f);
    gluSphere(pObj, 0.6f, 24, 12);

    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(-4.0f,0.0f, 0.0f);
    gluSphere(pObj, 0.8f, 24, 12);

    glColor3f(0.0f, 0.0f, 0.0f);
    glTranslatef(0.0f,0.0f, 0.3f);
    gluSphere(pObj, 0.6f, 24, 12);
    glPopMatrix();

    //legs
    glPushMatrix();
    glColor3f(0.99f, 0.39f, 0.39f);
    glTranslatef(-27.0f,23.5f, -23.5f);
    glRotatef(90.0f,1.0f,0.0f,0.0f);
    glRotatef(45.0f,0.0f,1.0f,0.0f);
    gluCylinder(pObj, 1.0f, 1.0f, 17.0f, 24, 72);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.99f, 0.39f, 0.39f);
    glTranslatef(-28.7f,24.5f, -23.5f);
    glRotatef(100.0f,1.0f,0.1f,0.0f);
    gluCylinder(pObj, 1.0f, 1.0f, 18.0f, 24, 72);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.99f, 0.39f, 0.39f);
    glTranslatef(-30.7f,24.5f, -23.5f);
    glRotatef(90.0f,1.0f,0.0f,0.0f);
    glRotatef(350.0f, 0.0f, 1.0f, 0.0f);
    gluCylinder(pObj, 1.0f, 1.0f, 18.0f, 24, 72);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.99f, 0.39f, 0.39f);
    glTranslatef(-32.5f,24.5f, -23.5f);
    glRotatef(90.0f,1.0f,0.0f,0.0f);
    glRotatef(325.0f, 0.0f, 1.0f, 0.0f);
    gluCylinder(pObj, 1.0f, 1.0f, 17.0f, 24, 72);
    glPopMatrix();

    //hand
    glPushMatrix();
    glColor3f(0.99f, 0.39f, 0.39f);
    glTranslatef(-28.7f,26.5f, -23.5f);
    glRotatef(90.0f,0.0f,1.0f,0.0f);
    glRotatef(325.0f, 1.0f, 0.0f, 0.0f);
    gluCylinder(pObj, 1.0f, 1.0f, 21.0f, 24, 72);

    glColor3f(0.99f, 0.39f, 0.39f);
    glTranslatef(0.0f,0.0f, 22.5f);
    glRotatef(180.0f,0.0f,1.0f,0.0f);
    gluCylinder(pObj, 0.8f, 1.7f, 3.5f, 24, 72);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.99f, 0.39f, 0.39f);
    glTranslatef(-32.7f,26.5f, -23.5f);
    glRotatef(90.0f,0.0f,1.0f,0.0f);
    glRotatef(200.0f, 1.0f, 0.0f, 0.0f);
    gluCylinder(pObj, 1.0f, 1.0f, 21.0f, 24, 72);

    glColor3f(0.99f, 0.39f, 0.39f);
    glTranslatef(0.0f,0.0f, 22.5f);
    glRotatef(180.0f,0.0f,1.0f,0.0f);
    gluCylinder(pObj, 0.8f, 1.7f, 3.5f, 24, 72);
    glPopMatrix();
glPopMatrix();
}

MyTurtle::MyTurtle()
{
posx, posy, posz= -30.0f,40.0f,35.0f;
velx = 0.0f;
vely = 0.0f;
velz = 1.0f;
}

Model::Model()
{
posx, posy, posz= 35.0f,30.0f,-15.0f;
velx = 0.0f;
vely = 0.0f;
velz = 2.0f;
}


MySotong::MySotong()
{
posx, posy, posz= -30.0f, 50.5f, -25.0f;
velx = 0.0f;
vely = 2.0f;
velz = 0.0f;
}

void MyTurtle::setup(const GLfloat* controlPoints,GLint uOrder, GLint vOrder,const bool autonormal)
{
    controlpoints = controlPoints;
    uorder = uOrder;
    vorder = vOrder;
    //setup the bezier
    glMap2f(GL_MAP2_VERTEX_3, //to be generated data, surface vertex
    0.0f, //lower u range
    1.0f, //higher u range
    3, //u control point stride in array
    uorder, //order of u or number of u control point
    0.0f, //lower v range
    1.0f, //higher v range
    3 * uorder, //v control point stride in array
    vorder, //order of v or number of v control point
    controlpoints); //the control points array
    //enabling bezier evaluator
    glEnable(GL_MAP2_VERTEX_3);
    //enabling auto generation of normals for use with lighting

}

void MyTurtle::draw(GLenum draw_mode,GLint ures,GLint vres)
{
glDisable(GL_CULL_FACE);
glColor3f(0.569f, 0.5451f, 0.447f);
glPushMatrix();
glTranslatef(-30.0f,40.0f,35.0f);
glPushMatrix();
glTranslatef(posx, posy, posz);
GLUquadricObj *pObj;
pObj = gluNewQuadric();

//setting the 2D grid map containing ures * vres points
//map to u range 0.0 - 1.0, v range 0.0 - 1.0
glMapGrid2f(ures, 0.0f, 1.0f, vres, 0.0f, 1.0f);
//evaluate the bezier surface
glEvalMesh2(draw_mode, 0, ures, 0, vres);
//body
    glColor3f(0.4431f,0.5451f,0.353f);
    glTranslatef(0,0,7);
    gluSphere(pObj, 6.8f, 24, 12);
    glTranslatef(0,0,8);
    gluSphere(pObj, 1.8f, 24, 12);
    glColor3f(1,1,1);
    glTranslatef(-1,0.5,1.5);
    gluSphere(pObj, 0.4f, 24, 12);
    glTranslatef(2,0,0);
    gluSphere(pObj, 0.4f, 24, 12);
    glColor3f(0,0,0);
    glTranslatef(0,0,0.3);
    gluSphere(pObj, 0.2f, 24, 12);
    glTranslatef(-2,0,0.0);
    gluSphere(pObj, 0.2f, 24, 12);
    glColor3f(1,0,0);
    glTranslatef(1,-1,0.0);
    glPushMatrix();
    glRotatef(45,1,0,0);
    gluDisk(pObj, 0.0f, 0.6f, 26, 13);
    glPopMatrix();
    glColor3f(0.4431f,0.5451f,0.353f);
    glTranslatef(0,-1.2,-24.5);
    gluSphere(pObj, 6.0f, 24, 12);


// Legs
    glPushMatrix();
    glRotatef(145.0f,1.0f,0.0f,0.0f);
    glRotatef(35.0f,0.0f,1.0f,0.0f);
    gluCylinder(pObj, 1.0f, 1.0f, 12.0f, 24, 72);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-6,-5,-7);
    glRotatef(145.0f,1.0f,0.0f,0.0f);
    glRotatef(135.0f,0.0f,1.0f,0.0f);
    gluCylinder(pObj, 1.0f, 1.0f, 12.0f, 24, 72);
    glPopMatrix();

// Hands
    glTranslatef(0,0,19.8);
    glRotatef(20,0,1,0);
    glPushMatrix();
    glTranslatef(0,0,-4.1);
    glRotatef(215.0f,1.0f,0.0f,0.0f);
    glRotatef(135.0f,0.0f,1.0f,0.0f);
    gluCylinder(pObj, 1.0f, 1.0f, 12.0f, 24, 72);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-6,-5,-7);
    glRotatef(145.0f,1.0f,0.0f,0.0f);
    glRotatef(135.0f,0.0f,1.0f,0.0f);
    gluCylinder(pObj, 1.0f, 1.0f, 12.0f, 24, 72);
    glPopMatrix();

    glPopMatrix();
        glPopMatrix();
    glEnable(GL_CULL_FACE);
}

void MyTurtle::draw2(GLenum draw_mode,GLint ures,GLint vres)
{
glDisable(GL_CULL_FACE);
glColor3f(0.569f, 0.5451f, 0.447f);
glPushMatrix();
glTranslatef(-30.0f,40.0f,35.0f);
glPushMatrix();

glTranslatef(posx, posy, posz);
glRotatef(180,1,0,0);
//setting the 2D grid map containing ures * vres points
//map to u range 0.0 - 1.0, v range 0.0 - 1.0
glMapGrid2f(ures, 0.0f, 1.0f, vres, 0.0f, 1.0f);
//evaluate the bezier surface
glEvalMesh2(draw_mode, 0, ures, 0, vres);
glPopMatrix();
glPopMatrix();
glEnable(GL_CULL_FACE);
}

void MyTurtle::tickTime(long int elapseTime)
{
float elapseTimeInSec = elapseTime / 1000.0f;
posx += elapseTimeInSec * velx;
posy += elapseTimeInSec * vely;
posz += elapseTimeInSec * velz;

}

void MySotong::tickTime(long int elapseTime)
{
float elapseTimeInSec = elapseTime / 1000.0f;
posx += elapseTimeInSec * velx;
posy += elapseTimeInSec * vely;
posz += elapseTimeInSec * velz;

}


void Model::tickTime(long int elapseTime)
{
float elapseTimeInSec = elapseTime / 1000.0f;
posx += elapseTimeInSec * velx;
posy += elapseTimeInSec * vely;
posz += elapseTimeInSec * velz;

}
