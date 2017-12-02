#include "glwidget.h"
#include <GL/glut.h>


GLWidget::GLWidget(QWidget *parent):QGLWidget(parent)
{

}
void GLWidget::initializeGL()
{

    glClearColor(0,0,0,0);

}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);


}

void GLWidget::resizeGL(int w,int h)
{


}

void GLWidget::teapot()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 0.0f);
    glutWireTeapot(1);


    glFlush();

}


