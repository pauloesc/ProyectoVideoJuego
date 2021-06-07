#include "../include/Suscripcion.h"
#include "../include/SuscripcionVitalicia.h"

SuscripcionVitalicia::SuscripcionVitalicia(DtFecha* fecha, DtPago medioDePago, float costo, Videojuego* vj, Jugador* j): Suscripcion(fecha,medioDePago,costo,vj,j) {
}

DtSuscripcion SuscripcionVitalicia::crearDtSuscripcion(){
    dtsus = DtSuscripcion(this->getVideojuegoAsociado()->getNombre(),this->costo,"temporal");
	return dtsus
}

void SuscripcionVitalicia::cancelarSuscripcion() {
}
