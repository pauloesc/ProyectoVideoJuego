#include "../include/Partida.h"

#include <iostream>

using namespace std;



DtFecha Partida::getFecha() {
    return fecha;
}

float Partida::getduracion(){
    return duracion;
};

bool getenCurso() {
	return enCurso;
}

int getcodigo() {
	return codigo;
}

Videojuego* getVideojuego() {
	return pertenece;
}



bool esPartidaIndividualFinalizadaDelJuego(nombrevid:string) {
	string nom = pertenece->getnombre();
	return ((nom == nombrevid) and (enCurso));
}

DtPartidaEnCurso* getDtPartida() {
	// falta implemetar, falta revision de los datatypes

}



//no hace nada pero tiene que estar
Partida::~Partida(){
};
