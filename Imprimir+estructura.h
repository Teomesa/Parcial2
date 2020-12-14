#ifndef IMPRIMIRESTRUCTURA_H
#define IMPRIMIRESTRUCTURA_H

#include <disp_ofensivo.h>
#include <disp_defensive.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#define pi 3.1416
#define G 9.80

using namespace std;

void Imprimir(float angle,float V0of,float x,float y, int t){
    cout << "Impacto con un angulo de " << angle << " grados" << endl;
    cout << "Impacto con velocidad inicial " << V0of << endl;
    cout << "Impacto con posicion horizontal " << x << endl;
    cout << "Impacto con posicion vertical " << y << endl;
    cout << "Con tiempo: " << t << endl;
    cout << endl;
}

void Disparo_of(disp_ofensivo disparoO, disp_defensive disparoD, int Voo){
    float Vxo=0.0, Vyo=0.0, x=0.0, y=0.0;
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
                if(sqrt(pow((disparoD.Xd-x),2)+pow((disparoD.Yd-y),2))<disparoO.DO){
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

void Disparo_def(disp_ofensivo disparoO, disp_defensive disparoD, int Voo){
    float Vxd, Vyd, x, y;
    int V0of=0;
    int t=0;
    int angle=0;
    int flag=0;
    for(V0of=Voo; ;V0of+=5){
        for(angle=0;angle<90;angle++){
            Vxd=V0of*cos((angle)*pi/180);
            Vyd=V0of*sin((angle)*pi/180);
            x=0.0;
            y=0.0;
            for(t=0; ;t++){
                x=Vxd*t;
                y=disparoD.Yd+Vyd*t-(0.5*G*t*t);
                if(sqrt(pow((disparoO.Xo-x),2)+pow((disparoO.Yo-y),2))<disparoD.DO){
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

void Disparodef2(disp_ofensivo disparoO, disp_defensive disparoD, int Voo, int angleoo, int Vooo){
    float Vxd = 0.0, Vyd = 0.0, x, y, Vxoo, Vyoo, x2, y2;
    int V0of=0;
    int t=0;
    int angle=0;
    int flag=0;
    Vxoo=Vooo*cos((angleoo)*pi/180);
    Vyoo=Vooo*sin((angleoo)*pi/180);
    for(V0of=Voo; ;V0of+=5){
        for(angle=0;angle<90;angle++){
            Vxd=V0of*cos((angle)*pi/180);
            Vyd=V0of*sin((angle)*pi/180);
            x=0.0;
            y=0.0;
            x2=0.0;
            y2=0.0;
            for(t=0; ;t++){
                x2=Vxoo*(t+2);
                y2=disparoO.Yo+Vyoo*(t+2)-(0.5*G*(t+2)*(t+2));
                x=disparoD.Xd+Vxd*t;
                y=disparoD.Yd+Vyd*t-(0.5*G*t*t);
                if(sqrt(pow((x2-x),2)+pow((y2-y),2))<disparoD.DO){
                    if(y<0) y=0;
                    if(y2<0) y2=0;
                    Imprimir(angleoo,Vooo,x2,y2,t+2);
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
void Disparodef3(disp_ofensivo disparoO, disp_defensive disparoD, int Voo, int angleoo, int Vooo){
    float Vxd = 0.0, Vyd = 0.0, x, y, Vxoo, Vyoo, x2, y2;
    int V0of=0;
    int t=0;
    int angle=0;
    float aux, auy;
    bool flag2=0;
    int flag=0;
    Vxoo=Vooo*cos((angleoo)*pi/180);
    Vyoo=Vooo*sin((angleoo)*pi/180);
    for(V0of=Voo; ;V0of+=5){
        for(angle=0;angle<90;angle++){
            Vxd=V0of*cos((angle)*pi/180);
            Vyd=V0of*sin((angle)*pi/180);
            x=0.0;
            y=0.0;
            x2=0.0;
            y2=0.0;
            for(t=0; ;t++){
                x2=Vxoo*(t+2);
                y2=disparoO.Yo+Vyoo*(t+2)-(0.5*G*(t+2)*(t+2));
                x=disparoD.Xd+Vxd*t;
                y=disparoD.Yd+Vyd*t-(0.5*G*t*t);
                for(int t2 = t; ;t2++){
                    aux = disparoD.Xd+Vxd*t2;
                    auy = disparoD.Yd + Vyd*t2 -(0.5*G*t2*t2);
                    if(sqrt(pow((disparoO.Xo - aux),2)+pow((disparoO.Yo - auy),2)) < disparoD.DO){
                        flag2 = 1;
                        break;
                    }
                    if(auy < 0){
                        break;
                    }
                }
                if(flag2){
                    flag2 = 0;
                    cout << "No impacto en los disparos esperados"<< endl;
                    break;
                }
                if(sqrt(pow((disparoD.Xd - x2),2)+pow((disparoD.Yd - y2),2)) < disparoO.DO){
                    break;
                }
                if(sqrt(pow((x2 - x),2)+pow((y2 - y),2)) < disparoD.DO){
                    if(y<0) y = 0;
                    if(y2<0) y2=0;
                    Imprimir(angleoo,Vooo,x2,y2,t+2);
                    Imprimir(angle, V0of, x, y, t);
                    flag += 1;
                    V0of += 50;
                    break;
                }
                if(y < 0){
                    break;
                }
            }
            if(flag == 3) break;

        }
        if(flag == 3) break;
    }
    if(flag != 3){
        cout << "No impacto en los disparos esperados"<< endl;
    }
}

void neutralizacion(disp_ofensivo disparo_Of, disp_defensive disparo_Def, int Angle_Of, int vel_Of){
    int  t_Of = 0, t_Def = 2;
    float angle_Def =0, Velx_Of, Vely_Of, Velx_Def, Vely_Def, Vel_Def = 0, Distancia;
    float X_Def, Y_Def, X_Of, Y_Of;
    bool Flag = 0;
    Velx_Of = vel_Of * cos(Angle_Of * pi/180);
    Vely_Of = vel_Of * sin(Angle_Of * pi/180);
    for(t_Of=0; ;){
        for(Vel_Def=10; Vel_Def+=10;)
            for(angle_Def=20; ;angle_Def=+5){
                Velx_Def = abs(Vel_Def * cos(angle_Def * (pi/180)));
                Vely_Def = abs(Vel_Def * sin(angle_Def * (pi /180)));
                for(t_Def=0; ;t_Def++){

                    //coordenadas del disparo defensivo
                    X_Def = disparo_Def.Xd - Velx_Def * t_Def;
                    Y_Def =disparo_Def.Yd - Vely_Def * t_Def - (0.5*G*t_Def*t_Def);

                    //coordenadas del ataque ofensivo
                    X_Of = disparo_Of.Xo + Velx_Of * t_Of;
                    Y_Of = disparo_Of.Yo + Vely_Of * t_Of - (0.5*G*t_Of*t_Of);
                    //Actualizacion de los parametros de los ciclos for
                    Vel_Def+=10;
                    angle_Def+=5;

                    //comparacion de la distacia con la explosion del misil defensivo
                    Distancia = sqrt(pow(X_Of-X_Def, 2) + pow(Y_Of -Y_Def, 2));
                    if(Distancia < disparo_Def.DO){
                        cout<< "inminente explosion de ambos misiles" << endl;
                        Y_Def=0;
                        Y_Of=0;
                        Imprimir(angle_Def, Vel_Def, X_Def, Y_Def, t_Def);
                        Imprimir(Angle_Of, vel_Of, X_Of, Y_Of, t_Of);
                        break;
                        break;
                        exit(-1);

                    }
                    if(Y_Def < 0){
                        t_Of++;
                        Y_Def = 0.0;
                        break;
                    }

                }
                if(Flag)
                    break;
                else{
                    angle_Def = 20;
                    break;
                }
            }
        if(Flag)
            break;
        else
            break;
    }
}

#endif // IMPRIMIRESTRUCTURA_H
