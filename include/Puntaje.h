#ifndef PUNTAJE
#define PUNTAJE

#include "Jugador.h"

class Jugador;

using namespace std;

class Puntaje {
private:
    
    int Puntos;
    Jugador* vidj;
	
public:
	Puntaje(int Puntos, Jugador* punteroVj);
    
    int getPuntos();
    Jugador* getJugador();
    
    void setPuntos(int p);
    void setJugador(Jugador* vj);

    ~Puntaje();
    
};
#endif