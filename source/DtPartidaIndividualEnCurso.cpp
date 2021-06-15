#include <string>
#include <iostream>
#include "../include/DtPartidaIndividualEnCurso.h"
#include "../include/DtPartidaEnCurso.h"
using namespace std;


DtPartidaIndividualEnCurso::DtPartidaIndividualEnCurso(): DtPartidaEnCurso() {
	this->continuarPartidaAnterior = false;
}

DtPartidaIndividualEnCurso::DtPartidaIndividualEnCurso(DtFecha fecha, int codigo, string nombreVideojuego, bool continuarPartidaAnterior): DtPartidaEnCurso(fecha,codigo,nombreVideojuego) {
	this->continuarPartidaAnterior = continuarPartidaAnterior;
}


bool DtPartidaIndividualEnCurso::getContinuaPartidaAnterior() {
	return this->continuarPartidaAnterior;
}

void DtPartidaIndividualEnCurso::setContinuaPartidaAnterior(bool continuarPartidaAnterior) {
	this->continuarPartidaAnterior = continuarPartidaAnterior;
}

DtPartidaIndividualEnCurso::~DtPartidaIndividualEnCurso(){

}

void DtPartidaIndividualEnCurso::imprimir() {
	cout << this;
}

ostream& operator<<(ostream &o, DtPartidaIndividualEnCurso *s) {
    o << "Partida Individual: "<< s->getFecha()<<'\n';
    o << "Código: " << s->getCodigo() <<'\n';
    o << "Nombre del Videojuego: " << s->getNombreVideojuego() <<'\n';
    o << "Continuación de la partida anterior: ";
		if (s->getContinuaPartidaAnterior()) {
			o << "Si" <<'\n';
		} else {
			o << "No" <<'\n';
		}
	
     return o;
}

