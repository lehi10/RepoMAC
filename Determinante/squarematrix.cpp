/*Author: Lehi Quincho Mamani
 * Universidad Nacional de San Agustín
 * Matematica aplicada a la Computación
 * Determinantes usando la reducción a una matriz escalonada con Gauss  (metodo iterativo)
 * Determinantes usando el metodo de Cofactores (Metodo recursivo)
 *
 * El programa ha sido desarrollado en C++ , y para poder probarlo se necesita compilar el archivo main.cpp
 *  con los otros dos archivos que son parte del proyecto que son squarematrix.h y squarematrix.cpp (clase creada para matrices cuadradas).
 *  Las funciones se encuentran dentro de la clase ScuaqueMatrix con los nombres de det_echelon (determinante por medio de la matriz escalonada)
 *  y det_Rec (Determinante por medio de Cofactores).
 *
*/

#include "squarematrix.h"
#include <math.h>
#include <iostream>
using namespace std;


SquareMatrix::SquareMatrix(int n)
{
    this->N=n;
    matrix=new float *[n];
    for(int i=0;i<n;i++)
    {
        matrix[i]=new float[n];
        for(int j=0;j<n;j++)
        {
            cin>>matrix[i][j];
        }
    }
}


float ** SquareMatrix::create_matrix(int dim)
{
    matrix=new float *[dim];
    for(int i=0;i<dim;i++)
        matrix[i]=new float[dim];
    return matrix;
}


float SquareMatrix::det_Recursive(float **subMatrix,int n)
{
    if(n==1)
        return subMatrix[0][0];
    if(n==2)
        return (subMatrix[0][0]*subMatrix[1][1]) - (subMatrix[0][1]*subMatrix[1][0]);
    float res=0;
    for(int i=0;i<n;i++)
    {
        float ** childMatrix=create_matrix(n-1);
        int j=0;
        for(int row=1;row<n;row++)
        {
            int k=0;
            for(int col=0;col<n;col++)
            {
                if(i != col)
                {
                    childMatrix[j][k]=subMatrix[row][col];
                    k++;
                }
            }
            j++;
        }
        float detA=det_Recursive(childMatrix,n-1);
        res+= subMatrix[0][i]  * pow(-1,(i+1)+1) * detA ;
        delete childMatrix;
    }
    return res;
}


float SquareMatrix::det_echelon()
{
    for(int i=0;i<N-1;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            float mult=(matrix[j][i]*(-1))/matrix[i][i];
            for(int k=0;k<N;k++)
                matrix[j][k] += (matrix[i][k]*mult) ;
        }
    }
    float res=1;
    for(int i=0;i<N;i++)
        res*=matrix[i][i];
    cout<<"La determinante reduciendo la matriz a una matriz escalonada es  : "<<res<<endl;
    return res;
}


void SquareMatrix::print_matrix(float **matriz, int dim)
{


    for(int i=0;i<dim;i++)
    {
        for(int j=0;j<dim;j++)
            printf("%.2f   ", matriz[i][j]);
        cout<<endl;
    }
}


// ADJUNTA DE UNA MATRIZ CUADRADA


float **SquareMatrix::adjunta(float **matriz,int dim)
{
    float **res=create_matrix(dim);
    for(int i=0;i<dim;i++)
    {
        for(int j=0;j<dim;j++)
        {
            float **Mtemp=create_matrix(dim-1);
            int ii=0;
            for(int x=0;x<dim;x++)
            {
                int jj=0;
                if(x!=i)
                {
                    for(int y=0;y<dim;y++)
                    {
                        if(y!=j)
                        {
                            Mtemp[ii][jj]=matriz[x][y];
                            jj++;
                        }
                    }
                    ii++;
                }
            }
            res[i][j]=pow(-1,(i+1)+(j+1))*det_Recursive(Mtemp,dim-1);
            delete Mtemp;
        }
    }
    return res;
}

// INVERSA DE UNA MATRIZ CUADRADA

float **SquareMatrix::inversa(float **matriz,int dim)
{
    float **res=create_matrix(dim);
    float **adj =adjunta(matriz,dim);
    float detM=det_Recursive(matriz,dim);

    for(int i=0;i<dim;i++)
    {
        for(int j=0;j<dim;j++) // hallando la transpuesta
            res[j][i]=(1.0/detM)*adj[i][j];
    }
    return res;
}


