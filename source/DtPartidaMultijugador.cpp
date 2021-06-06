#include "../include/DtPartidaMultijugador.h"
#include <string>
#include <iostream>
using namespace std;


DtPartidaMultijugador::DtPartidaMultijugador():DtPartida(){
    this->transmitidaEnVivo = false;
}

DtPartidaMultijugador::DtPartidaMultijugador(DtFecha sfecha, float sduracion, int scodigo, bool senCurso, bool transmitidaEnVivo): DtPartida(sfecha,sduracion,scodigo, senCurso)
{
	this->transmitidaEnVivo = transmitidaEnVivo;
}

bool DtPartidaMultijugador::getTransmitidaEnVivo() const{
	return transmitidaEnVivo;
}

void DtPartidaMultijugador::setTransmitidaEnVivo(bool transmitidaEnVivo){
	this->transmitidaEnVivo = transmitidaEnVivo;
}
DtPartidaMultijugador::~DtPartidaMultijugador() {
}


