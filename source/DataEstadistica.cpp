#include <string>

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
  o << "Info mimpdf dnjknjdnvkjdfnd: " <<'\n';
  return o;
}