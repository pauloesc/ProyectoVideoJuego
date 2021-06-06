#include "../include/Reloj.h"

DtFecha* Reloj::fecha;

DtFecha* Reloj::getFecha() {
	return fecha;
}

void Reloj::setFecha(int Sdia, int Smes, int Sanio, int Shora, int Sminuto) {
	DtFecha* f = new DtFecha(Sdia,Smes,Sanio,Shora,Sminuto);
	fecha = f;
}