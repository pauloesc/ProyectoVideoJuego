#include "../include/DtEstadisticaDeSegundoTipo.h"

DtEstadisticaDeSegundoTipo::DtEstadisticaDeSegundoTipo () {
	nombre = "";
    valorNumeroDeEstadisica = 0;
}

DtEstadisticaDeSegundoTipo::DtEstadisticaDeSegundoTipo (string Snombre, float SvalorNumeroDeEstadisica) {
	nombre = Snombre;
    valorNumeroDeEstadisica = SvalorNumeroDeEstadisica;
}

DtEstadisticaDeSegundoTipo::~DtEstadisticaDeSegundoTipo () {
}

string DtEstadisticaDeSegundoTipo::getNombre () {
	return nombre;
}

float DtEstadisticaDeSegundoTipo::getValorNumeroDeEstadisica () {
	return valorNumeroDeEstadisica;
}
void DtEstadisticaDeSegundoTipo::setNombre(string nombre) {
	this->nombre = nombre;
}

void DtEstadisticaDeSegundoTipo::setValorNumeroDeEstadisica(float valorNumeroDeEstadisica) {
	this->valorNumeroDeEstadisica = valorNumeroDeEstadisica;
}

ostream& operator<<(ostream &o, DtEstadisticaDeSegundoTipo *s) {
	o << "Nombre: "<< s->getNombre() <<'\n';
	o << "Valor de Número de Estadisica: "<< s->getValorNumeroDeEstadisica() <<'\n';

	return o;
}

