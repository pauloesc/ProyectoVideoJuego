#include "../include/Suscripcion.h"
#include "../include/SuscripcionVitalicia.h"

SuscripcionVitalicia::SuscripcionVitalicia(DtFecha* fecha, DtPago medioDePago, float costo, Videojuego* vj, Jugador* j): Suscripcion(fecha,medioDePago,costo,vj,j) {
}

DtSuscripcion* SuscripcionVitalicia::crearDtSuscripcion(){
    DtSuscripcion* dtsus = new DtSuscripcion(this->getVideojuegoAsociado()->getNombre(),this->getCosto(),"temporal");
	return dtsus;
}

void SuscripcionVitalicia::cancelarSuscripcion() {
}
