#include "../include/Abandona.h"



Abandona::Abandona(Jugador* j) {
	this->fecha = Reloj::getFecha();
	this->jug = j;
}

DtFecha* Abandona::getFecha() {
	return fecha;
}

Jugador* Abandona::getJugador() {
	return jug;
}