#include "../include/Suscripcion.h"
#include "../include/SuscripcionVitalicia.h"
#include "../include/Videojuego.h"
#include "../include/Jugador.h"


SuscripcionVitalicia::SuscripcionVitalicia(DtFecha* fecha, DtPago medioDePago, float costo, Videojuego* vj, Jugador* j): Suscripcion(fecha,medioDePago,costo,vj,j) {
}

DtSuscripcion* SuscripcionVitalicia::crearDtSuscripcion(){
    DtSuscripcion* dtsus = new DtSuscripcion(this->getVideojuegoAsociado()->getNombre(),this->getCosto(),"temporal");
	return dtsus;
}

void SuscripcionVitalicia::cancelarSuscripcion() {
}

SuscripcionVitalicia::~SuscripcionVitalicia(){}