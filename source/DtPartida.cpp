#include "../include/DtPartida.h"
#include "../include/DtFecha.h"
#include <string>
#include <iostream>
using namespace std;


DtPartida::DtPartida() {
    fechaIniciada = new DtFecha();
	duracion = 0;
	codigo = 0;
	enCurso = false;
}

DtPartida::DtPartida(DtFecha* Sfecha, float duracionPartida, int codigo, bool enCurso){
	fechaIniciada = Sfecha;
	duracion = duracionPartida;
	codigo = codigo;
	enCurso = enCurso;
}

DtFecha* DtPartida::getFecha(){
	return fechaIniciada;
}

float DtPartida::getDuracion(){
	return duracion;
}

int DtPartida::getCodigo(){
	return codigo;
}

bool DtPartida::getEnCurso(){
	return enCurso;
}

void DtPartida::setFecha(DtFecha* fecha){
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


DtPartida::~DtPartida(){

}
