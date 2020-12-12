#ifndef IMPRIMIRESTRUCTURA_H
#define IMPRIMIRESTRUCTURA_H

#include <iostream>

using namespace std;

struct Disp_ofensive{
    float distance=950;
    float Xo=0;
    float Yo=300;
    float DO=0.05*distance;
};

struct Disp_defensive{
    float distance=950;
    float Xd=distance;
    float Yd=50;
    float DO=0.025*distance;
};

void Imprimir(float angle,float V0of,float x,float y, int t){
    cout << "Impacto con un angulo de " << angle << " grados" << endl;
    cout << "Impacto con velocidad inicial " << V0of << endl;
    cout << "Impacto con posicion horizontal " << x << endl;
    cout << "Impacto con posicion vertical " << y << endl;
    cout << "Con tiempo: " << t << endl;
    cout << endl;
}

#endif // IMPRIMIRESTRUCTURA_H
