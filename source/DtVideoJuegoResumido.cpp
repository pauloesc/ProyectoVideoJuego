#include <string>

DtVideoJuegoResumido::DtVideoJuegoResumido(){}


DtVideoJuegoResumido::DtVideoJuegoResumido (string nom, string des){
    Nombre = nom;
    Descripcion = des;
}


string DtVideoJuegoResumido::getNombre() {
	return Nombre;
}

void DtVideoJuegoResumido::setNombre(string nom) {
	Nombre = nom;
}


string DtVideoJuegoResumido::getDescripcion() {
	return Descripcion;
}

void DtVideoJuegoResumido::setDescripcion(string des) {
	Descripcion = des;
}

ostream& operator<<(ostream &o, DtVideoJuegoResumido* d) {
  o << "Info Estadistica: " << '\n' << "Nombre: " << d->getNombre() << "Descripcion: " d->getDescripcion();
  return o;
}
