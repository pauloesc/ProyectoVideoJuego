#include <string>
#include "../include/DtSuscripcion.h"

DtSuscripcion::DtSuscripcion(){

    nombre = " ";
    costo = 0;
    tipoSuscripcion = " ";
}


DtSuscripcion::DtSuscripcion (string snombre, float scosto, string stipoSuscripcion) {
    nombre = snombre;
    costo = scosto;
    tipoSuscripcion = stipoSuscripcion;
}

DtSuscripcion::~DtSuscripcion () {
}

string DtSuscripcion::getNombre() {
	return nombre;
}

float DtSuscripcion::getCosto() {
	return costo;
}

string DtSuscripcion::getTipoSuscripcion() {
	return tipoSuscripcion;
}

void DtSuscripcion::setNombre(string nombre){
	this->nombre = nombre;
}

void DtSuscripcion::setCosto(float costo){
	this->costo = costo;
}
void DtSuscripcion::setTipoSuscripcion(string tipoSuscripcion){
	this->tipoSuscripcion = tipoSuscripcion;
}

ostream& operator<<(ostream &o, DtSuscripcion *s) {
	o << "Nombre: " << s->getNombre() << '\n';
	o << "Costo: " << s->getCosto() << '\n';
	o << "Tipo Suscripción: " << s->getTipoSuscripcion() << '\n';
	return o;
}

