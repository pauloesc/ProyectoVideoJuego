#include <string>

DtVideojuegoResumido::DtVideojuegoResumido(){}


DtVideojuegoResumido::DtVideojuegoResumido (string nom, string des){
    Nombre = nom;
    Descripcion = des;
}


string DtVideojuegoResumido::getNombre() {
	return Nombre;
}

void DtVideojuegoResumido::setNombre(string nom) {
	Nombre = nom;
}


string DtVideojuegoResumido::getDescripcion() {
	return Descripcion;
}

void DtVideojuegoResumido::setDescripcion(string des) {
	Descripcion = des;
}

ostream& operator<<(ostream &o, DtVideojuegoResumido* d) {
  o << "Info Estadistica: " << '\n' << "Nombre: " << d->getNombre() << "Descripcion: " d->getDescripcion();
  return o;
}
