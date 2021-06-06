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
