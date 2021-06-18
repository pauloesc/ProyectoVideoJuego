#ifndef ABANDONA
#define ABANDONA


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

#include "Jugador.h"


#endif