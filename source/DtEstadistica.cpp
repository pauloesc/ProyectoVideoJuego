#include "../include/DtEstadistica.h"

DtEstadistica::DtEstadistica () {
	nombre = "";
    descripcion = "";
}

DtEstadistica::DtEstadistica(string Snombre, string Sdescripcion) {
	nombre = Snombre;
    descripcion = Sdescripcion;
}

DtEstadistica::~DtEstadistica () {
}

string DtEstadistica::getNombre () {
	return nombre;
}

string DtEstadistica::getDescripcion () {
	return descripcion;
}
void DtEstadistica::setNombre(string nombre) {
	this->nombre = nombre;
}

void DtEstadistica::setDescripcion(string descripcion) {
	this->descripcion = descripcion;
}

ostream& operator<<(ostream &o, DtEstadistica *s) {
	o << "Nombre: "<< s->getNombre() <<'\n';
	o << "Descripción: "<< s->getDescripcion() <<'\n';
	return o;
}

