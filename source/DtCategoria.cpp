#include <string>
#include "../include/DtCategoria.h"
#include "../include/DtJugador.h"
#include "../include/DtDesarrollador.h"

DtCategoria::DtCategoria () {
	nombreCat = "";
    descripcion = "";
    tipo = "";
}

DtCategoria::DtCategoria (string SnombreCat, string Sdescripcion, string Stipo) {
	nombreCat = SnombreCat;
    descripcion = Sdescripcion;
    tipo = Stipo;
}

DtCategoria::~DtCategoria () {
}

string DtCategoria::getNombreCat () {
	return nombreCat;
}

string DtCategoria::getDescripcion () {
	return descripcion;
}

string DtCategoria::getTipo () {
	return tipo;
}

void DtCategoria::setNombreCat(string nombreCat) {
	this->nombreCat = nombreCat;
}

void DtCategoria::setDescripcion(string descripcion) {
	this->descripcion = descripcion;
}

void DtCategoria::setTipo(string tipo) {
	this->tipo = tipo;
}
ostream& operator<<(ostream &o, DtCategoria *s) {
	o << "Nombre:" << s->getNombreCat()  <<'\n';
	o << "Descripcion:" << s->getDescripcion() <<'\n';
	o << "Tipo:" << s->getTipo() <<'\n';

	return o;
}

