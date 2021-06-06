#include <iterator>


#include "Jugador.h"

using namespace std;

Jugador::Jugador(string unEmail, string unaContrasenia string unNickname, string unaDescripcion) :Usuario (unEmail, unaContrasenia) {
	nickname = unNickname;
	descripcion = unaDescripcion;
}

string Jugador::getnickname () {
	return nickname;
}

bool Jugador::esJugador() {
	return true;
}

string Jugador::getdescripcion() {
	return descripcion;
}

vector<DtPartidaIndividual> Jugador::darPartidasIndividualesFinalizadas(string nombrevid) {
	vector<DtPartidaIndividual> res;
	partidas::iterator it;
	for (it = partidas.begin(); it != partidas.end(); ++it)
		if (it->second->esPartidaIndividualFinalizadaDelJuego(nombrevid))
			res.push_back(it->second->darDatosPartida());
	return res;
}

vector<DtPartidaEnCurso> Jugador::darPartidasEnCurso() {
	vector<DtPartidaEnCurso> res;
	partidas::iterator it;
	for (it = partidas.begin(); it != partidas.end(); ++it)
		if (it->second->getEnCurso())
			res.push_back(it->second->getDtPartida());
	return res;
}

Partida Jugador::encontrarPartidasIndividual(int codigoAnterior) {
	partidas::iterator it = partidas.begin()
	while (it->first != codigoAnterior) //existe una partida con ese codigo
		++it;
	return *it->second;
}

void Jugador::AsociarPartidaIniciada(Partida PI) {
	partidas[(*PI)->getcodigo()] = (*PI);
}

void Jugador::DesvincularPartida(Partida par) {
	partidas::iterator it;
	for(it = partidas.begin(); *it->second != par; ++it);
	partidas.erase(it->first);
}

void Jugador::desvincularPartidas(string nomVJ) {
	partidas::iterator it;
	for (it = partidas.begin(); it != partidas.end(); ++it)
		if (it->second->getVideJuegoAsociado() == nomVJ)
			partidas.erase(it->first);
}

void Jugador::finalizarPartida(int identificador) {
	partidas.erase(identificador);
}


void Jugador::eliminarSuscripciones(string nomVJ) {
	sus::iterator it;
	for (it = sus.begin(); !encontre; ++it) //Ya tiene una suscripcion
		if ((*it)->getVideojuegoAsociado()->getNombre() == nomVJ) //Chequear esto
			encontre = true;
	sus.erase((*it), (*it)); //Revisar
}

vector<Suscripcion> Jugador::darSuscripcionesActivas() {     
	vector<Suscripcion> res;
	sus::iterator it;
	for (it = sus.begin(); it != sus.end(); ++it)
		if ((*it)->esActiva())
			res.push_back((*it)->crearDtSuscripcion());
	return res;
}

bool Jugador::tieneSuscripcionActiva(string nombrevid) { //como es la misma función que la sig no es una sobre carga?
	sus::iterator it = sus.begin();
	while (it != sus.end() && !((*it)->esActiva(nombrevid)))
		++it;
	return it != sus.end();
}

bool Jugador::tieneSuscripcionActiva(Videojuego vid) {
	sus::iterator it = sus.begin();
	res = false;
	while (it != sus.end() && !res)
		if ((*it)->esActiva() && (*it)->getVideojuegoAsociado() == vid)
			res = true;
	return res;
}

void Jugador::cancelarSuscripcionActiva(string Juego) {
	sus::iterator it;
	bool terminar = false;
	for (it = sus.begin(); it != sus.end() && !terminar; ++it)
		if ((*it)->esActiva(Juego)) {
			(*it)->cancelarSuscripcion();
			terminar = true;
		}
}

void Jugador::asociarSuscripcion(Suscripcion SNuevo) {
	sus.push_back(SNuevo);
}