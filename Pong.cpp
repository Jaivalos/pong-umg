#include "Pong.h"
#include <stdio.h>
#include <conio.h>
#include "libgame.h"
#include <windows.h>

jugador::jugador(int _x, int _y) : x(_x), y(_y) {}

void jugador::pintar() const{
    gotoxy(x , y-1); printf("%c",219);
    gotoxy(x , y); printf("%c",219);
    gotoxy(x , y+1); printf("%c",219);
}

void jugador::borrar() const{
    gotoxy(x , y-1); printf(" ");
    gotoxy(x , y); printf(" ");
    gotoxy(x , y+1); printf(" ");
}



pelota::pelota(int _x, int _y, int _dx, int _dy) : x(_x), y(_y), dx(_dx), dy(_dy) {}
void pelota::pintar() const{
    gotoxy(x,y); printf("O");
}
void pelota::borrar() const{
    gotoxy(x,y); printf(" ");
}
void pelota::mover(jugador a, jugador b){
    borrar();
    x +=dx; y +=dy;
    pintar();

    if(x + dx == 3 || x + dx == 76){
        borrar();
        asign(38, 14);
        dx = -dx;
    }

    if(y + dy == 3 || y + dy == 23){dy = -dy;}

    if(x + dx == a.RX() && y >= a.RY()-2 && y<= a.RY()+2){ dx=-dx; Beep(500, 50);}
    if(x + dx == b.RX() && y >= b.RY()-2 && y<= b.RY()+2){ dx=-dx; Beep(500, 50);}

    if((x + dx == 40) && (y >= 8 && y <= 19)){ dx = -dx; Beep(500, 50);}
}

void inicio::portada(int &a){

char port[18][70] =
    {
    "                                                  ",
    "aaaaaaas                                                      ",
    "aaaaaaaaaass                             1.- INICIAR    ",
    "aa       aass                                               ",
    "aa       aass                                                  ",
    "aa       aass                                               ",
    "aaaaaaaass                                                    ",
    "aaaaaaaas                                                     ",
    "ass                                                         ",
    "ass    aaaas    aaas    aa   aa  aaaaaaa  aaaaaa aa         aaaa ",
    "ass  aa      aas    aas aa   as aa    aa aaa     aa      aaa    aaa",
    "ass  aa      aas    aas aaaaaaa aa    aa aaa     aaaaa   aaa    aaa",
    "ass  aa      aas    aas      aa aa  aaaa aaa     aaaaa   aaa    aaa",
    "ass  aa      aas    aas      aa aa       aaa     aa      aaa    aaa",
    "ass  aa      aas    aas      as aa       aaa     aa      aaa    aaa",
    "ass  aa         aaas    aasaaaa  aaaaaaa  aaaaaa aaaaaaaa   aaaa",

    };

    for(int i=0; i<18; i++){
        for(int j=0; j<70; j++){
            gotoxy(j+5, i+5);
            printf("%c", port[i][j]);
        }
    }

    a = getch();

    for(int i=0; i<18; i++){
        for(int j=0; j<100; j++){
            gotoxy(j+2, i+5);
            printf(" ");
        }
    }

}
