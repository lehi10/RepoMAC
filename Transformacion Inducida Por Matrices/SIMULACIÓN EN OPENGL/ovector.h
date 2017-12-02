#ifndef OVECTOR_H
#define OVECTOR_H

class OVector
{
    public :
        float vec[3]={0.0,0.0,0.0};
        OVector(int dimention):dim(dimention){

        }

        void setCoord2D(float x,float y){vec[0]=x;vec[1]=y;}
        void setCoord3D(float x,float y,float z){vec[0]=x;vec[1]=y;vec[2]=z;}

        int dim;



};


#endif // OVECTOR_H
