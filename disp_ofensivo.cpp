#include "disp_ofensivo.h"

void disp_ofensivo::Disparo_of(Disp_ofensive disparoO, Disp_defensive disparoD){
    int Voo;
    cout << "Ingrese una velocidad de la bala para hacer la simulacion: "; cin >> Voo;
    float Vxo, Vyo, x, y;
    int V0of=0;
    int t=0;
    int angle=0;
    int flag=0;
    for(V0of=Voo; ;V0of+=5){
        for(angle=0;angle<90;angle++){
            Vxo=V0of*cos(angle*pi/180);
            Vyo=V0of*sin(angle*pi/180);
            x=0.0;
            y=0.0;
            for(t=0; ;t++){
                x=Vxo*t;
                y=disparoO.Yo+Vyo*t-(0.5*G*t*t);
                if(sqrt(pow((disparoD.distance-x),2)+pow((disparoD.Yd-y),2))<disparoO.DO){
                    if(y<0) y=0;
                    Imprimir(angle, V0of, x, y, t);
                    flag+=1;
                    V0of+=50;
                    break;
                }
                if(y<0){
                    break;
                }
            }
            if(flag == 3) break;
        }
        if(flag==3) break;
    }
    if(flag!=3){
        cout << "No impacto en los disparos esperados" << endl;
    }
}

