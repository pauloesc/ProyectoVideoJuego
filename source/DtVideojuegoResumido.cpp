#include <string>
#include "../include/DtVideojuegoResumido.h"

DtVideojuegoResumido::DtVideojuegoResumido(){}


DtVideojuegoResumido::DtVideojuegoResumido (string nom, string des){
    Nombre = nom;
    Descripcion = des;
}


string DtVideojuegoResumido::getNombre() {
	return Nombre;
}



string DtVideojuegoResumido::getDescripcion() {
	return Descripcion;
}


ostream& operator<<(ostream &o, DtVideojuegoResumido* d) {
  o << "Info Estadistica: " << '\n' << "Nombre: " << d->getNombre() << "Descripcion: " << d->getDescripcion();
  return o;
}
