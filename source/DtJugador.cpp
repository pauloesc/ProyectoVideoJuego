#include <string>
#include "../include/DtJugador.h"
#include "../include/DtUsuario.h"

DtJugador::DtJugador() :DtUsuario (){

    nickname = " ";
    descripcion = " ";
}


DtJugador::DtJugador (string Semail, string Scontrasenia, string Snickname, string Sdescripcion):DtUsuario (Semail,Scontrasenia) {
    nickname = Snickname;
    descripcion = Sdescripcion;
}

DtJugador::~DtJugador () {

};

string DtJugador::getNickname() {
	return nickname;
}

string DtJugador::getDescripcion() {
	return descripcion;
}
void DtJugador::setNickname(string nickname){
	this->nickname = nickname;
}

void DtJugador::setDescripcion(string descripcion){
	this->descripcion = descripcion;
}

