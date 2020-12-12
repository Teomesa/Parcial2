#include <iostream>
#include <math.h>
#include "Imprimir+estructura.h"
#include "disp_defensive.h"
#include "disp_ofensivo.h"

using namespace std;

bool si=true;

int main()
{
    disp_defensive disparo_canon_defensivo;
    disp_ofensivo disparo_canon_ofensivo;
    while (si==true) {
        int opcion;
            cout<<"1. Para Generar disparos ofensivos que comprometan la integridad del canon defensivo " << endl;
            cout<<"2. Generar disparos defensivos que comprometan la integridad del canon ofensivo." << endl;
            cout<<"3. Dado un disparo ofensivo, generar disparos defensivos que impida que el caonn defensivo sea destruido sin importar si el canon ofensivo pueda ser destruido." << endl;
            cout<<"4. Dado un disparo ofensivo, generar disparo defensivos que impidan que los canones defensivo y ofensivo puedan ser destruidos." << endl;
            cout<<"5. Dado un disparo ofensivo efectivo y un disparo defensivo que comprometa la efectividad del ataque ofensivo, generar (al menos tres) disparos que neutralicen el ataque defensivo y permitan que el ataque ofensivo sea efectivo." << endl;
            cout << ':' << endl;
            cin >> opcion;
        switch (opcion) {
        case 1:
        {
            int velocidadof;
            cout << "Ingrese la velocidad de la bala del canon ofensivo para la simulacion que quieres hacer: "; cin >> velocidadof;
            Disparo_of(disparo_canon_ofensivo, disparo_canon_defensivo, velocidadof);
            si=false;
            break;
        }
        case 2:
        {
            int velocidadof=0;
            cout << "Ingrese la velocidad de la bala del canon ofensivo para la simulacion que quieres hacer: "; cin >> velocidadof;
            Disparo_def(disparo_canon_ofensivo, disparo_canon_defensivo, velocidadof);
            si=false;
            break;
        }
        case 3:
        {
            int velocidadof=0;
            float angleo, vooo;
            cout << "Ingrese la velocidad de la bala del canon ofensivo para la simulacion que quieres hacer: "; cin >> velocidadof;
            cout << "Ingresa el angulo de disparo: "; cin >> angleo;
            cout << "Ingresa la velocidad del disparo: "; cin >> vooo;
            cout << endl;
            Disparodef2(disparo_canon_ofensivo, disparo_canon_defensivo, velocidadof, angleo, vooo);
            si=false;
            break;
        }
        case 4:
        {
            int velocidadof=0;
            float angleo, vooo;
            cout << "Ingrese la velocidad de la bala del canon ofensivo para la simulacion que quieres hacer: "; cin >> velocidadof;
            cout << "Ingresa el angulo de disparo: "; cin >> angleo;
            cout << "Ingresa la velocidad del disparo: "; cin >> vooo;
            cout << endl;
            Disparodef2(disparo_canon_ofensivo, disparo_canon_defensivo, velocidadof, angleo, vooo);
            si=false;
            break;
        }
        default:
        {
            cout << "Dato para la simulacion invalido, intente nuevamente" << endl << endl;
        }
        }
    }
}
