#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QOpenGLWidget>
#include "myglwidget.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_checkButton_clicked()
{
    ui->GLoriginal->teapot();
}
void MainWindow::on_agregarButton_clicked()
{


}
