#include "../include/DtPartidaMultijugadorEnCurso.h"
#include <string>
#include <iostream>
#include "list"
using namespace std;


DtPartidaMultijugadorEnCurso::DtPartidaMultijugadorEnCurso(){
     this->transmitidaEnVivo = false;
	 this->cantidadJugadoresUnidos = 0;
}

DtPartidaMultijugadorEnCurso::DtPartidaMultijugadorEnCurso(DtFecha sfecha, int scodigo, string snombreVideojuego, bool transmitidaEnVivo,  list<string> nickJugadores, int cantidadJugadores): DtPartidaEnCurso(sfecha,scodigo,snombreVideojuego)
{
	this->transmitidaEnVivo = transmitidaEnVivo;
	list<string>::iterator it;
	for(it = nickJugadores.begin(); it != nickJugadores.end(); ++it){
        this->nicknameJugadoresUnidos.push_back(*it);
    }
    this->cantidadJugadoresUnidos = cantidadJugadores;
}

DtPartidaMultijugadorEnCurso::~DtPartidaMultijugadorEnCurso(){
    list<string>::iterator it;
	for(it = this->nicknameJugadoresUnidos.begin(); it != this->nicknameJugadoresUnidos.end(); ++it){
        nicknameJugadoresUnidos.remove(*it);
    }
    nicknameJugadoresUnidos.clear();
}

bool DtPartidaMultijugadorEnCurso::getTransmitidaEnVivo() const{
	return transmitidaEnVivo;
}


list<string> DtPartidaMultijugadorEnCurso::getNicknameJugadoresUnidos(){

	list<string> res;
	list<string>::iterator it;
	for(it = this->nicknameJugadoresUnidos.begin(); it != this->nicknameJugadoresUnidos.end(); ++it){
        res.push_back(*it);
    }

	return res;
}

int DtPartidaMultijugadorEnCurso::getCantidadJugadoresUnidos() const{
	return cantidadJugadoresUnidos;
}

void DtPartidaMultijugadorEnCurso::setTransmitidaEnVivo(bool transmitidaEnVivo){
	this->transmitidaEnVivo = transmitidaEnVivo;
}


void DtPartidaMultijugadorEnCurso::setNicknameJugadoresUnidos(list<string> nicknameJugadoresUnidos) {

    list<string>::iterator it;
    for(it = this->nicknameJugadoresUnidos.begin(); it != this->nicknameJugadoresUnidos.end(); ++it){
        nicknameJugadoresUnidos.remove(*it);
    }
	this->nicknameJugadoresUnidos.clear();
	int i = 0;
	list<string>::iterator it1;
	for(it = nicknameJugadoresUnidos.begin(); it1 != nicknameJugadoresUnidos.end(); ++it1){
        this->nicknameJugadoresUnidos.push_back(*it1);
        i++;
    }
    this->cantidadJugadoresUnidos = i;
}



ostream& operator<<(ostream &o, DtPartidaMultijugadorEnCurso *s) {
    
    o << "Partida Multijugador"<< s->getFecha()<<'\n';
    o << "Código: " << s->getCodigo() <<'\n';
    o << "Nombre del Videojuego: " << s->getNombreVideojuego() <<'\n';
    o << "Transmitida en vivo: ";
		if (s->getTransmitidaEnVivo()) {
			o << "Si" <<'\n';
		} else {
			o << "No" <<'\n';
		}

    o << "Cantidad de jugadores unidos a la partida: " << s->getCantidadJugadoresUnidos() <<'\n';

    o << "Jugadores unidos a la partida: ";

         list<string> part=s->getNicknameJugadoresUnidos();
         list<string>::iterator it;
         for(it = part.begin(); it != part.end(); ++it){
            if (*it  == s->getNicknameJugadoresUnidos().back()) {
                o << *it <<'\n';
            }
            else{
                o << *it <<", ";
            }
        }
		part.clear();
	
	return o;
}







