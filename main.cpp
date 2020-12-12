#include <iostream>
#include <math.h>
#include "Imprimir+estructura.h"
#include "disp_defensive.h"
#include "disp_ofensivo.h"

using namespace std;

int main()
{
    disp_defensive disparo_canon_defensivo;
    disp_ofensivo disparo_canon_ofensivo;
    int Velocidadof;
    cout << "Ingresa una velocidad inicial del canon of: "; cin >> Velocidadof;
    Disparo_of(disparo_canon_ofensivo, disparo_canon_defensivo,Velocidadof);
}
