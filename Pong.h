#ifndef PONG_H_INCLUDED
#define PONG_H_INCLUDED

class jugador{
    int x,y;
public:
    jugador (int _x, int _y);
    void pintar() const;
    void borrar() const;
    void Y(int _y){ y += _y; }
    int RY() { return y; }
    int RX() { return x; }
};

class pelota{
    int x,y;
    int dx, dy;
public:
    pelota(int _x, int _y, int _dx, int _dy);
    void pintar() const;
    void borrar() const;
    void mover(jugador a, jugador b);
    void asign(int _x, int _y) { x = _x; y = _y;}
};

class inicio{
public:
    void portada(int &a);
};

#endif // PONG_H_INCLUDED
