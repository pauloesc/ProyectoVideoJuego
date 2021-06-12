#include "../include/Suscripcion.h"
#include "../include/SuscripcionTemporal.h"

SuscripcionTemporal::SuscripcionTemporal(DtFecha* fecha, DtPago medioDePago, float costo, Videojuego* vj, Jugador* j, bool activa, int validez, bool cancelada): Suscripcion(fecha,medioDePago,costo,vj,j) {
	this->activa = activa;
	this->validez = validez;
	this->cancelada = cancelada;
}

bool SuscripcionTemporal::getActiva() {
	return this->activa;
}

int SuscripcionTemporal::getValidez() {
	return this->validez;
}

bool SuscripcionTemporal::getCancelada(){
	return this->cancelada;
}

DtSuscripcion* SuscripcionTemporal::crearDtSuscripcion(){
    DtSuscripcion* dtsus = new DtSuscripcion(this->getVideojuegoAsociado()->getNombre(),this->getCosto(),"temporal");
	return dtsus;
}

void SuscripcionTemporal::cancelarSuscripcion() {
	this->cancelada = true;
}
