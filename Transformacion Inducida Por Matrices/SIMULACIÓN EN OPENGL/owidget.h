#ifndef OWIDGET_H
#define OWIDGET_H

#include <QGLWidget>
#include <QTimer>
#include <GL/glut.h>
#include "ovector.h"
#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

class Owidget : public QGLWidget
{
    Q_OBJECT
    public:
        explicit Owidget(QWidget *parent);

        void initializeGL();
        void paintGL();
        void resizeGL(int w, int h);

        int dim;

        list<OVector *> *listVec;

    private:
        QTimer timer;

};
#endif // OWIDGET_H
