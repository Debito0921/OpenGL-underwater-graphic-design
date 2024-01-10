#ifndef assignment_HPP
#define assignment_HPP
#include "header.hpp"
#include<time.h>
#include <vector>
#include <fstream>




namespace assignment {
//class declaration

class Model {
  private:
    class Face {
      public:
        int e;
        int *v;
        int *texcoords;
        int n;

        Face(int e, int *v, int *texcoords, int n = -1) {
            this->e = e;
            this->v = v;
            this->texcoords = texcoords;
            this->n = n;
        }
    };
    vector<float *> v;
    vector<float *> normals;
    vector<Face> vfaces;
    vector<float *> texcoords;
    GLuint list;
  public:
    GLfloat posx, posy, posz;
    GLfloat roty;
    GLfloat velx, vely, velz;
    Model();
    void tickTime(long int elapseTime);
    void load(const char *filename) {
        string line;
        vector<std::string> vlines;
        ifstream in(filename);
        if (!in.is_open()) {
            printf("Cannot load model %s\n", filename);
            return;
        }
        while (!in.eof()) {
            std::getline(in, line);
            vlines.push_back(line);
        }
        in.close();
        float a, b, c;
        for (string &line : vlines) {
            if (line[0] == 'v') {
                if (line[1] == ' ') {
                    sscanf(line.c_str(), "v %f %f %f", &a, &b, &c);
                    v.push_back(new float[3]{a, b, c});
                } else if (line[1] == 't') {
                    sscanf(line.c_str(), "vt %f %f", &a, &b);
                    texcoords.push_back(new float[2]{a, b});
                } else {
                    sscanf(line.c_str(), "vn %f %f %f", &a, &b, &c);
                    normals.push_back(new float[3]{a, b, c});
                }
            } else if (line[0] == 'f') {
                int v0, v1, v2, t0, t1, t2, n;
                sscanf(line.c_str(), "f %d/%d/%d %d/%d/%d %d/%d/%d", &v0, &t0, &n, &v1, &t1, &n, &v2, &t2, &n);
                int *v = new int[3]{v0 - 1, v1 - 1, v2 - 1};
                vfaces.push_back(Face(3, v, NULL, n - 1));
            }
        }
        list = glGenLists(1);
        glNewList(list, GL_COMPILE);
        for (Face &face : vfaces) {
            if (face.n != -1)
                glNormal3fv(normals[face.n]);
            else
                glDisable(GL_LIGHTING);
            glBegin(GL_POLYGON);
            for (int i = 0; i < face.e; i++)
                glVertex3fv(v[face.v[i]]);
            glEnd();
            if (face.n == -1)
                glEnable(GL_LIGHTING);
        }
        glEndList();
        for (float *data : v)
            delete data;
        v.clear();
        for (float *data : texcoords)
            delete data;
        texcoords.clear();
        for (float *data : normals)
            delete data;
        normals.clear();
        vfaces.clear();
    }
    void draw() {
         glCallList(list);

    }
};
class MySands
{
public:
void draw();
void init();
private:
    GLuint textureMapping;
};
class MyPatrickHouse
{
public:
void draw();
};
class MySquid
{
public:
void draw();
};
class MyPineapple
{
public:
void draw();
};
class MySotong
{
public:
    MySotong();
    void draw();
    void tickTime(long int elapseTime);
private:
    GLfloat posx, posy, posz;
    GLfloat roty;
    GLfloat velx, vely, velz;

};

class MyJellyfish
{
public:
    MyJellyfish();
    void draw();
    void tickTime(long int elapseTime);
private:
    GLfloat posx, posy, posz;
    GLfloat roty;
    GLfloat velx, vely, velz;
};
class MyFish1
{
public:
    void draw();
};
class MyTurtle
{
public:
    MyTurtle();
    void setup(const GLfloat* controlPoints,
    GLint uOrder, GLint vOrder,
    const bool autonormal = false);
    void draw(GLenum draw_mode = GL_FILL, //or GL_LINE or GL_POINT
    GLint ures = 100,GLint vres = 100);
    void draw2(GLenum draw_mode = GL_FILL, //or GL_LINE or GL_POINT
    GLint ures = 100,GLint vres = 100);
    void tickTime(long int elapseTime);


private:
    GLint uorder, vorder;
    const GLfloat* controlpoints;
    GLfloat posx, posy, posz;
    GLfloat roty;
    GLfloat velx, vely, velz;

};

class MyBubbles
{

 public:
    MyBubbles();
    void draw(MyBubbles mybubble,int k, int z);
    void tickTime(long int elapseTime);
    float y;
    float z;
    long int timetick;

 private:

    float vel0;
    float accel;

};

class MyVirtualWorld
{
public:
 //create an instance of the MyUmbrella class
 Model model;
 Model submarine;
 MySands mysand;
 MyBubbles mybubble;
 MyPatrickHouse mypatrick;
 MySquid mysquid;
 MyPineapple mypineapple;
 MyFish1 myfish1;
 MySotong mysotong;
 MyTurtle myturtle;
 MyJellyfish myjellyfish;

 long int timeold, timenew, elapseTime;
  void tickTime()
    {
     timenew    = glutGet(GLUT_ELAPSED_TIME);
     elapseTime = timenew - timeold;
     timeold    = timenew;
     mybubble.tickTime(elapseTime);
     myturtle.tickTime(elapseTime);
     mysotong.tickTime(elapseTime);
     model.tickTime(elapseTime);
     submarine.tickTime(elapseTime);
     myjellyfish.tickTime(elapseTime);
    }
 void draw()
 {

 myturtle.draw(GL_FILL);
 myturtle.draw2(GL_FILL);

 model.load("Models//Shark.obj");
 //call the draw() function of MyUmbrella class
 glPushMatrix();
 glTranslatef(model.posx,model.posy,model.posz);
 glPushMatrix();
 glColor3f(0.204,0.212,0.2275f);
 glTranslatef(35.0f,30.0f,-15.0f);
 glScalef(5.0f,5.0f,5.0f);
 model.draw();
 glPopMatrix();

 glPushMatrix();
 glTranslatef(35.0f,29.5f,-13.0f);
 model.draw();
 glTranslatef(2.0f,0.0f,-15.0f);
 model.draw();
 glTranslatef(-6.0f,0.0f,-24.0f);
 model.draw();
 glPopMatrix();

 glPopMatrix();

 submarine.load("Models//Submarine.obj");

 glPushMatrix();
 glTranslatef(model.posx,model.posy,model.posz);
 glPushMatrix();
 glColor3f(0.0,0.0,0.0f);
 glTranslatef(0.0f,50.0f,-50.0f);
 glScalef(3.0f,3.0f,3.0f);
 submarine.draw();
 glPopMatrix();

 glPopMatrix();

 mysand.draw();
 mypatrick.draw();
 mysquid.draw();
 mypineapple.draw();
 myfish1.draw();
 myturtle.draw();

 glPushMatrix();
 glTranslatef(-10.0f,5.0f,0.0f);
 myjellyfish.draw();
 glPopMatrix();

 glPushMatrix();
 glTranslatef(0.0f,10.0f,0.0f);
 myjellyfish.draw();
 glPopMatrix();


for (int i=0; i<75; i++){
    glPushMatrix();
    if (i == 0){
        glScalef(0.5f, 0.5f, 0.5f);
        glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    }
    glTranslatef(rand()%50,rand()%60 , rand()%100);
    myfish1.draw();
    glPopMatrix();
}

mysotong.draw();


 int x=0;
 srand(time(0));

 if(mybubble.y>=14.9){
    x = rand()%20;
    mybubble.timetick=0;

 }
 mybubble.draw(mybubble,x,5);
 mybubble.draw(mybubble,x+5,-10);
 mybubble.draw(mybubble,x+10,15);
 mybubble.draw(mybubble,x-25,-20);
 mybubble.draw(mybubble,x-30,5);


 }

 //for any one-time only initialization of the
 // virtual world before any rendering takes place
 // BUT after OpenGL has been initialized
 void init()
 {
    timeold = glutGet(GLUT_ELAPSED_TIME);
    mysand.init();
    static GLfloat controlpoints2[] =
    { -5.0f, 0.0f, 10.0f,
    -8.0f, 10.0f, 10.0f,
    8.0f, 10.0f, 10.0f,
    5.0f, 0.0f, 10.0f,
    -15.0f,0.0f, 5.0f,
    -10.0f, 15.0f, 5.0f,
    10.0f, 15.0f, 5.0f,
    15.0f,0.0f, 5.0f,
    -15.0f,0.0f, -5.0f,
    -10.0f, 15.0f, -5.0f,
    10.0f, 15.0f, -5.0f,
    15.0f,0.0f, -5.0f,
    -5.0f, 0.0f,-10.0f,
    -8.0f, 5.0f,-10.0f,
    8.0f, 5.0f,-10.0f,
    5.0f, 0.0f,-10.0f
    };
    myturtle.setup(controlpoints2, 4, 4);

 }
};
}
#endif
