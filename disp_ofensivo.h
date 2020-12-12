#ifndef DISP_OFENSIVO_H
#define DISP_OFENSIVO_H
#define G 9.81
#define pi 3.1416
#include<math.h>
#include<iostream>
#include<Imprimir+estructura.h>

using namespace std;

class disp_ofensivo: public Disp_ofensive
{
public:
    void Disparo_of(Disp_ofensive disparoO, Disp_defensive disparoD);
    disp_ofensivo();
};

#endif // DISP_OFENSIVO_H
