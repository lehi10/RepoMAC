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


#include <iostream>
#include "squarematrix.h"

using namespace std;




int main(int argc, char *argv[])
{

    int dim=3;
    SquareMatrix mat(dim);

    cout<<"-------------MATRIZ ORIGINAL---------------"<<endl;
    mat.print_matrix(mat.matrix,dim);

    cout<<"-------------MATRIZ INVERSA---------------"<<endl;

    float **inver=mat.inversa(mat.matrix,dim);

    mat.print_matrix(inver,dim);






    return 0;
}
