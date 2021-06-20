#include "../include/Suscripcion.h"
#include "../include/SuscripcionTemporal.h"

SuscripcionTemporal::SuscripcionTemporal(DtFecha* fecha, DtPago medioDePago, float costo, Videojuego* vj, Jugador* j, bool activa, int validez, bool cancelada): Suscripcion(fecha,medioDePago,costo,vj,j) {
	this->activa = activa;
	this->validez = validez;
	this->cancelada = cancelada;
}

bool SuscripcionTemporal::getActiva() {
	
	if (this->cancelada) {
		return false;
	} else {
		DtFecha* act = this->getFecha();
		DtFecha* fValida;

		if (this->validez == 30) {
			if (act->getMes() == 12) {
				fValida = new DtFecha(act->getDia(), 1, act->getAnio()+1, act->getHora(), act->getMinuto());
			} else {
				fValida = new DtFecha(act->getDia(), act->getMes() + 1, act->getAnio(), act->getHora(), act->getMinuto());
			}

		} else if (this->validez == 90) {
			if (act->getMes() + 3 > 12) {
				fValida = new DtFecha(act->getDia(), (act->getMes()+3)%12, act->getAnio()+1, act->getHora(), act->getMinuto());
			} else {
				fValida = new DtFecha(act->getDia(), act->getMes()+3, act->getAnio(), act->getHora(), act->getMinuto());
			}

		} else {
			fValida = new DtFecha(act->getDia(), act->getMes(), act->getAnio()+1, act->getHora(), act->getMinuto());
		}
	
		return AmenorB(Reloj::getFecha(),fValida); // retorna true si fValida > FechaActual
	}
	
}

int SuscripcionTemporal::getValidez() {
	return this->validez;
}

bool SuscripcionTemporal::getCancelada(){
	return this->cancelada;
}

DtSuscripcion* SuscripcionTemporal::crearDtSuscripcion(){
	DtSuscripcion* dtsus;
	if (this->getVideojuegoAsociado()->getCostoMensual()== this->getCosto())
        dtsus = new DtSuscripcion(this->getVideojuegoAsociado()->getNombre(),this->getCosto(),"mensual");
	else {
		if (this->getVideojuegoAsociado()->getCostoTrimestral() == this->getCosto())
			dtsus = new DtSuscripcion(this->getVideojuegoAsociado()->getNombre(), this->getCosto(), "trimestral");
		else
			dtsus = new DtSuscripcion(this->getVideojuegoAsociado()->getNombre(), this->getCosto(), "anual");
		}
	return dtsus;
}

void SuscripcionTemporal::cancelarSuscripcion() {
	this->cancelada = true;
}

SuscripcionTemporal::~SuscripcionTemporal(){}
