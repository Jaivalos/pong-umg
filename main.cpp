#include <stdio.h>
#include <conio.h>
#include "libgame.h"
#include "Pong.h"
#include <stdlib.h>
#include <windows.h>
#include <iostream>

int main(){

    system("Color 0D");

    OcultaCursor();

    pintar_marco();
    int cont = 0, op=0;
    inicio M; M.portada(op);
    jugador a(6,15); a.pintar();
    jugador b(74,15); b.pintar();

    pelota p(38,14,1,1);

    PlaySound("Karibu-Watu-Wangu.wav", NULL, SND_ALIAS|SND_LOOP);

    //char cancion[]="C:\Users\Nuevo Usuario\Documents\Ingenieria en sistemas\Semestre 2\Algoritmos\Fase 2 V1\Karibu-Watu-Wangu.wav";

    char tecla;
     pintar_marco();
    lineam();


    while(true){
        if(kbhit()){
            a.borrar(); b.borrar();
            tecla = getch();
            if(tecla == 'q' && a.RY() > 5) a.Y(-1); else if(tecla=='a' && a.RY() < 21) a.Y(1);
            if(tecla == 'o' && b.RY() > 5) b.Y(-1); else if(tecla=='l' && b.RY() < 21) b.Y(1);
            a.pintar(); b.pintar();
        }
        if(!cont++) p.mover(a, b);
        if(cont > 5) cont = 0;
        pausa(5);
        if(tecla == 'c') {
            borrar_marco();
            a.borrar();
            b.borrar();
            exit(1);
        }
    }

}
