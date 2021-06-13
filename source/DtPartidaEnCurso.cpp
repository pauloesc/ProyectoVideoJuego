#include "../include/DtPartidaEnCurso.h"
#include "../include/DtPartidaIndividualEnCurso.h"
#include "../include/DtPartidaMultijugadorEnCurso.h"
#include "../include/DtFecha.h"
#include <string>
#include <cstring>
#include <iostream>
using namespace std;


DtPartidaEnCurso::DtPartidaEnCurso() {
    fechaIniciada = DtFecha();
	codigo = 0;
	nombreVideojuego = " ";
}

DtPartidaEnCurso::DtPartidaEnCurso(DtFecha Sfecha, int Scodigo, string SnombreVideojuego){
	fechaIniciada = Sfecha;
	codigo = Scodigo;
	nombreVideojuego = SnombreVideojuego;
}

DtFecha DtPartidaEnCurso::getFecha() const{
	return fechaIniciada;
}

int DtPartidaEnCurso::getCodigo() const{
	return codigo;
}

string DtPartidaEnCurso::getNombreVideojuego() const{
	return nombreVideojuego;
}

void DtPartidaEnCurso::setFecha(DtFecha fecha){
    this->fechaIniciada = fecha;
}

void DtPartidaEnCurso::setCodigo(int codigo){
    this->codigo = codigo;
}
void DtPartidaEnCurso::setNombreVideojuego(string nombreVideojuego){
    this->nombreVideojuego = nombreVideojuego;
}


DtPartidaEnCurso::~DtPartidaEnCurso(){

}
