#ifndef ABANDONA
#define ABANDONA

#include "Jugador.h"
#include "DtFecha.h"
#include "Reloj.h"

class Jugador;

class Abandona {
private:
	DtFecha* fecha;
	Jugador* jug;
public:
	Abandona(Jugador* j);

	Jugador* getJugador();
	DtFecha* getFecha();
};




#endif