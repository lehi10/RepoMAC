#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <string>
#include <ovector.h>

using namespace std;

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
void transformVectwithMatrix(int dim_ini,int dim_end,float **Mat_o_Transf,OVector *vec_orig ,OVector * result )
{

    for(int i=0;i<dim_end;i++)
    {
        float temp_res=0;
        for(int j=0;j<dim_ini;j++)
        {
            temp_res+= Mat_o_Transf[i][j]*vec_orig->vec[j];
        }
        result->vec[i]=temp_res;
        cout<< temp_res<<endl;
    }
}




void MainWindow::on_newPointButton_clicked()
{

    try
    {

        string::size_type sz;

        int dim=atoi(ui->dim1->currentText().toStdString().c_str());
        int dimRes=atoi(ui->dim2->currentText().toStdString().c_str());


        float x=stof(ui->p_x->text().toStdString().c_str(),&sz);
        float y=stof(ui->p_y->text().toStdString().c_str(),&sz);



        OVector *vec_org = new OVector(dim);



        if(dim==3)
        {
            float z=stof(ui->p_z->text().toStdString().c_str(),&sz);

            vec_org->setCoord3D(x,y,z);
            ui->OrWidget->listVec->push_back(vec_org);
            ui->OrWidget->dim=3;
        }
        else
        {
            vec_org->setCoord2D(x,y);
            ui->OrWidget->listVec->push_back(vec_org);
            ui->OrWidget->dim=2;
        }



        float **matrizDeT= new float*[dimRes];

        for(int i=0;i<dimRes;i++)
        {
            matrizDeT[i]=new float[dim];
            for(int j=0;j<dim;j++)
            {
                matrizDeT[i][j]=ui->matrizT->item(i,j)->text().toFloat();
            }
        }

        //---------------------------------------------------------------


        OVector *vec_res_T=new OVector(dimRes);

        transformVectwithMatrix ( dim , dimRes,matrizDeT, vec_org , vec_res_T );

        ui->FinWidget->listVec->push_back(vec_res_T);
        ui->FinWidget->dim=dimRes;


        //---------------------------------------------------------------


    }
    catch(...)
    {
        cout<<"Error"<<endl;

    }



}
