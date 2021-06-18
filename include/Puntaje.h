#ifndef PUNTAJE
#define PUNTAJE



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

#include "Jugador.h"
#endif