#include "../include/DtPartidaMultijugador.h"

using namespace std;


DtPartidaMultijugador::DtPartidaMultijugador(int Scodigo, DtFecha* Sfecha, string Snombrevid, bool StransmitidaEnVivo, string Sinicio, vector<string> SnicknameJugadoresUnidos) {
	codigo = Scodigo;
	fecha = Sfecha;
	nombrevid = Snombrevid;
	transmitidaEnVivo = StransmitidaEnVivo;
	inicio = Sinicio;
	nicknameJugadoresUnidos = SnicknameJugadoresUnidos;
}


int DtPartidaMultijugador::getCodigo() {
	return codigo;
}

DtFecha* DtPartidaMultijugador::getFecha() {
	return fecha;
}

string DtPartidaMultijugador::getNombreVid() {
	return nombrevid;
}

bool DtPartidaMultijugador::getTransmitidaEnVivo() {
	return transmitidaEnVivo;
}

string DtPartidaMultijugador::getInicio() {
	return inicio;
}

vector<string> DtPartidaMultijugador::getNicknameJugadoresUnidos(){
	return nicknameJugadoresUnidos;
}

ostream& operator<<(ostream &o, DtPartidaMultijugador* d) {
	o << '\n';
	o << "Partida del videojuego: " << d->getNombreVid() << '\n' << "Codigo: " << d->getCodigo() << '\n' << "Transmitida en vivo: ";

	if (d->getTransmitidaEnVivo()) {
		o << "Si" << '\n';
	} else {
		o << "No" << '\n';
	}

	o << d->getFecha() << "Partida iniciada por: " << d->getInicio() << '\n';
	o << "Lista de Jugadores Unidos: " << '\n';

	for (unsigned long int i = 0; i < (d->getNicknameJugadoresUnidos()).size(); i++) {
		o << (d->getNicknameJugadoresUnidos())[i] << ", ";
	}

	o << '\n';
	return o;

}

DtPartidaMultijugador::~DtPartidaMultijugador() {
}


