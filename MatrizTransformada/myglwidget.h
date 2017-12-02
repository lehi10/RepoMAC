#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QGLWidget>


class glOriginal : public QGLWidget
{
    Q_OBJECT

public :
    explicit glOriginal (QWidget *parent=0);

    void initializeGL()
    {
        glClearColor(1,1,0,1);

    }

    void paintGL()
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void resizeGL(int w,int h)
    {

    }
};

#endif // MYGLWIDGET_H
