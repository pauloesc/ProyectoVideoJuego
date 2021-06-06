#include "../include/DtPartida.h"
#include "../include/DtPartidaIndividual.h"
#include "../include/DtPartidaMultijugador.h"
#include "../include/DtFecha.h"
#include <string>
#include <iostream>
using namespace std;


DtPartida::DtPartida() {
    fechaIniciada = DtFecha();
	duracion = 0;
	codigo = 0;
	enCurso = false;
}

DtPartida::DtPartida(DtFecha Sfecha, float duracionPartida, int codigo, bool enCurso){
	fechaIniciada = Sfecha;
	duracion = duracionPartida;
	codigo = codigo;
	enCurso = enCurso;
}

DtFecha DtPartida::getFecha() const{
	return fechaIniciada;
}

float DtPartida::getDuracion() const{
	return duracion;
}

int DtPartida::getCodigo() const{
	return codigo;
}

bool DtPartida::getEnCurso() const{
	return enCurso;
}

void DtPartida::setFecha(DtFecha fecha){
    this->fechaIniciada = fecha;
}
void DtPartida::setDuracion(float duracion){
    this->duracion = duracion;
}

void DtPartida::setCodigo(int codigo){
    this->codigo = codigo;
}
void DtPartida::setEnCurso(bool enCurso){
    this->enCurso = enCurso;
}



ostream& operator<<(ostream &o, DtPartida *s) {
	o << s->getFecha();
	o << "Duración de la partida (en horas): " << s->getDuracion() <<'\n';
    o << "Código: " << s->getCodigo() <<'\n';
    o << "Está en curso: ";
		if (s->getEnCurso()) {
			o << "Si" <<'\n';
		} else {
			o << "No" <<'\n';
		}
	if (dynamic_cast<DtPartidaIndividual*>(s) != NULL) {
		DtPartidaIndividual *p = dynamic_cast<DtPartidaIndividual*>(s);

		o << "Continuación de la partida anterior: ";
		if (p->getContinuaPartidaAnterior()) {
			o << "Si" <<'\n';
		} else {
			o << "No" <<'\n';
		}

	} else {
		DtPartidaMultijugador *p = dynamic_cast<DtPartidaMultijugador*>(s);

		o << "Transmitida en vivo: ";
		if (p->getTransmitidaEnVivo()) {
			o << "Si" <<'\n';
		} else {
			o << "No" <<'\n';
		}
	}
	return o;
}
DtPartida::~DtPartida(){

}
