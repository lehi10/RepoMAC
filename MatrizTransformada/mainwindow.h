#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtOpenGL>
#include <glwidget.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_checkButton_clicked();

    void on_agregarButton_clicked();

private:
    Ui::MainWindow *ui;
    GLWidget glwindow;
};

#endif // MAINWINDOW_H
