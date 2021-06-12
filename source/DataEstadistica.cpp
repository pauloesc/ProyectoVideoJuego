#include <string>
#include "../include/DataEstadistica.h"

DataEstadistica::DataEstadistica(){}


DataEstadistica::DataEstadistica (string nom, string des){
    Nombre = nom;
    Descripcion = des;
}


string DataEstadistica::getNombre() {
	return Nombre;
}

void DataEstadistica::setNombre(string nom) {
	Nombre = nom;
}


string DataEstadistica::getDescripcion() {
	return Descripcion;
}

void DataEstadistica::setDescripcion(string des) {
	Descripcion = des;
}

ostream& operator<<(ostream &o, DataEstadistica* d) {
  o << "Info Estadistica: " << '\n' << "Nombre: " << d->getNombre() << "Descripcion: "  << d->getDescripcion();
  return o;
}