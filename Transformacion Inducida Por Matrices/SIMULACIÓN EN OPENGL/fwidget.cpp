#include "fwidget.h"
#include <GL/glut.h>

#define val_reescale  1


void fcoord2d()
{
    glScalef(val_reescale,val_reescale,val_reescale);
    float lineSize=300;
    glColor3f(1,1,1);
    glBegin(GL_LINES);
        glVertex3f(-lineSize,0,0);
        glVertex3f(lineSize,0,0);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(0,-lineSize,0);
        glVertex3f(0,lineSize,0);
    glEnd();
}

void fcoord3d()
{

     glScalef(val_reescale,val_reescale,val_reescale);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluPerspective((float) 55.0, (float) 1.0, (float) 1.0, (float) 100.0);

     glMatrixMode(GL_MODELVIEW);
     gluLookAt((float) 1.5, (float) 2.0, (float) 2.5, (float) 0, (float) 0, (float) 0, (float) 0, (float) 1, (float) 0);
     glRotated(-90,1,0,0);
     glRotated(-90,0,0,1);



    float lineSize=1000;
    glColor3f(1,0,0);
    glBegin(GL_LINES);
        glVertex3f(-lineSize,0,0);
        glVertex3f(lineSize,0,0);
    glEnd();
    glColor3f(0,0,1);
    glBegin(GL_LINES);
        glVertex3f(0,-lineSize,0);
        glVertex3f(0,lineSize,0);
    glEnd();
    glColor3f(1,1,1);
    glBegin(GL_LINES);
        glVertex3f(0,0,-lineSize);
        glVertex3f(0,0,lineSize);
    glEnd();
}


Fwidget::Fwidget (QWidget *parent): QGLWidget(parent)
{
    connect( &timer, SIGNAL(timeout()), this, SLOT(updateGL()) );
    timer.start(16);
}

void Fwidget::initializeGL()
{
    glClearColor(0.2, 0.2, 0.2, 1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    listVec = new list<OVector *>();
    dim=2;
}


void Fwidget::paintGL()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt( 0,0,5,  0,0,0,  0,1,0 );


    if(!listVec->empty() )
    {
        if(dim==2)
            fcoord2d();
        if(dim==3)
            fcoord3d();


        int j=0;
        for_each (listVec->begin(), listVec->end(), [&j](OVector * i){


            glColor3f(0,1,0);

            glBegin(GL_LINES);
                glVertex3f(0.0, 0.0, 0.0);
                glVertex3f(i->vec[0],i->vec[1],i->vec[2]);
            glEnd();

            glBegin(GL_LINES);
                glVertex3f(i->vec[0],0,0);
                glVertex3f(i->vec[0],i->vec[1],0);
            glEnd();

            glBegin(GL_LINES);
                glVertex3f(0,i->vec[1],0);
                glVertex3f(i->vec[0],i->vec[1],0);
            glEnd();
            glBegin(GL_LINES);
                glVertex3f(i->vec[0],i->vec[1],0);
                glVertex3f(i->vec[0],i->vec[1],i->vec[2]);
            glEnd();


            glColor3f(1,0,0);
            glPointSize(5);
            glBegin(GL_POINTS);
                glVertex3f(i->vec[0],i->vec[1],i->vec[2]);
            glEnd();
            j++;

        });

        glFlush();
    }
}


void Fwidget::resizeGL(int w, int h)
{

    glViewport(0,0, w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective( 45.0, (float)w/h, 0.01, 100.0 );


    updateGL();
}
