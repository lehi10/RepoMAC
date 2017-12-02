#ifndef FWIDGET_H
#define FWIDGET_H
#include <QGLWidget>
#include <QTimer>
#include "ovector.h"
#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

class Fwidget : public QGLWidget
{
    Q_OBJECT
    public:
        explicit Fwidget(QWidget *parent);

        void initializeGL();
        void paintGL();
        void resizeGL(int w, int h);

        int dim;

        list<OVector *> *listVec;

    private:
        QTimer timer;
};

#endif // FWIDGET_H
