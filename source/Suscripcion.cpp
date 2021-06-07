#include "../include/Suscripcion.h"
#include "../include/SuscripcionTemporal.h"
#include "../include/SuscripcionActiva.h"

Suscripcion(DtFecha* fecha, DtPago medioDePago, float costo, Videojuego* vj, Jugador* j) {
	this->fecha = Reloj::getFecha();
	this->medioDePago = medioDePago;
	this->costo = costo;
	this->videoj = vj;
	this->jug = j;
}

DtFecha* Suscripcion::getFecha() {
	return this->fecha;
}

DtPago Suscripcion::getMedioDePago() {
	return this->medioDePago;
}

float Suscripcion::getCosto() {
	return this->costo;
}

VideoJuego* Suscripcion::getVideojuegoAsociado() {
	return this->videoj;
}

Jugador* Suscripcion::getJugador() {
	return this->jug;
}


bool Suscripcion::esActiva(string juego) {
	if (this->getVideojuegoAsociado->getNombre() == juego){
        if (dynamic_cast<SuscripcionTemporal*>(this) != NULL){
            SuscripcionTemporal* stemp = dynamic_cast<SuscripcionTemporal*>(this);
            return stemp->getActiva();
        }else{
            return true;
        }
	}else{
        return false;
	}
}

bool Suscripcion::esActiva() {
	if (dynamic_cast<SuscripcionTemporal*>(this) != NULL){
        SuscripcionTemporal* stemp = dynamic_cast<SuscripcionTemporal*>(this);
        return stemp->getActiva();
	}else{
        return true;
	}
}


