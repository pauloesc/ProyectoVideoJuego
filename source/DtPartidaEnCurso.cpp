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



ostream& operator<<(ostream &o, DtPartidaEnCurso *s) {
	o << s->getFecha();
    o << "Código: " << s->getCodigo() <<'\n';
    o << "Nombre del Videojuego: " << s->getNombreVideojuego() <<'\n';
	if (dynamic_cast<DtPartidaIndividualEnCurso*>(s) != NULL) {
		DtPartidaIndividualEnCurso *p = dynamic_cast<DtPartidaIndividualEnCurso*>(s);

		o << "Continuación de la partida anterior: ";
		if (p->getContinuaPartidaAnterior()) {
			o << "Si" <<'\n';
		} else {
			o << "No" <<'\n';
		}

	} else {
		DtPartidaMultijugadorEnCurso *p = dynamic_cast<DtPartidaMultijugadorEnCurso*>(s);

		o << "Transmitida en vivo: ";
		if (p->getTransmitidaEnVivo()) {
			o << "Si" <<'\n';
		} else {
			o << "No" <<'\n';
		}

		o << "Cantidad de jugadores unidos a la partida: " << p->getCantidadJugadoresUnidos() <<'\n';

		o << "Jugadores unidos a la partida: ";


		list<string> part=p->getNicknameJugadoresUnidos();
        list<string>::iterator it;
        for(it = part.begin(); it != part.end(); ++it){
            if (*it  == p->getNicknameJugadoresUnidos().back()) {
                o << *it <<'\n';
            }
            else{
                o << *it <<", ";
            }
        }
		part.clear();
	}
	return o;
}
DtPartidaEnCurso::~DtPartidaEnCurso(){

}
