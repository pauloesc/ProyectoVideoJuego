#include "../include/Reloj.h"

DtFecha* Reloj::fecha=0;

DtFecha* Reloj::getFecha() {
	return fecha;
}

void Reloj::setFecha(int Sdia, int Smes, int Sanio, int Shora, int Sminuto) {

	if ( Reloj::fecha != 0){
		delete fecha;
	}

	DtFecha* f = new DtFecha(Sdia,Smes,Sanio,Shora,Sminuto);
	fecha = f;
}

void Reloj::Destructor(){
	delete fecha;
}