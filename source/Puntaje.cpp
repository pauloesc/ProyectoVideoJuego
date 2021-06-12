#include "../include/Puntaje.h"

Puntaje::Puntaje(int Puntos, Jugador* punteroj) {
    this->Puntos = Puntos;
    this->vidj = punteroj;
}

int Puntaje::getPuntos(){
    return Puntos;
}

Jugador* Puntaje::getJugador(){
    return vidj;
}

void Puntaje::setPuntos(int p){
    this->Puntos = p;
}

void Puntaje::setJugador(Jugador* j){
    this->vidj = j;
}

Puntaje::~Puntaje(){
}
