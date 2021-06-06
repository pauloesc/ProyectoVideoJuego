#include <string>
#include <iostream>
#include "../include/DtPartidaIndividual.h"
#include "../include/DtPartida.h"
using namespace std;


DtPartidaIndividual::DtPartidaIndividual(): DtPartida() {
	this->continuarPartidaAnterior = false;
}

DtPartidaIndividual::DtPartidaIndividual(DtFecha fecha, float duracion, int codigo, bool enCurso, bool continuarPartidaAnterior): DtPartida(fecha, duracion, codigo, enCurso) {
	this->continuarPartidaAnterior = continuarPartidaAnterior;
}


bool DtPartidaIndividual::getContinuaPartidaAnterior() {
	return this->continuarPartidaAnterior;
}

void DtPartidaIndividual::setContinuaPartidaAnterior(bool continuarPartidaAnterior) {
	this->continuarPartidaAnterior = continuarPartidaAnterior;
}

DtPartidaIndividual::~DtPartidaIndividual(){

}
