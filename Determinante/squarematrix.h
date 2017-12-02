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
#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H

#include <vector>
using namespace std;


class SquareMatrix
{
public:
    SquareMatrix(int n);

    float **matrix;

    float ** create_matrix(int dim);
    float det_Recursive(float **subMatrix,int n);

    float det_echelon();
    void print_matrix(float **matriz,int dim);
    float **inversa(float **matriz,int dim);
    float **adjunta(float **matriz,int dim);

    int N;

};

#endif // SQUAREMATRIX_H
