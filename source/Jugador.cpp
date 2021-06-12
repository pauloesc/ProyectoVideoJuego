#include "Jugador.h"

using namespace std;

Jugador::Jugador(string unEmail, string unaContrasenia, string unNickname, string unaDescripcion) :Usuario (unEmail, unaContrasenia) {
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

vector<DtPartidaIndividual *> Jugador::darPartidasIndividualesFinalizadas(string nombrevid) {
	vector<DtPartidaIndividual *> res;
    for (int i = 0; i < partidas.size(); i++)
        if (*partidas[i]->esPartidaIndividualFinalizadaDelJuego(nombrevid))
            res.push_back(*partidas[i]->darDatosPartida());
	return res;
}

vector<DtPartidaEnCurso *> Jugador::darPartidasEnCurso() {
	vector<DtPartidaEnCurso *> res;
	for (int i = 0; i < partidas.size(); i++)
		if (*partidas[i]->getEnCurso())
			res.push_back(*partidas[i]->getDtPartida());
	return res;
}

*Partida Jugador::encontrarPartidasIndividual(int codigoAnterior) {
	partidas::iterator it = partidas.begin()
    int i;
    for (i = 0; *partidas[i]->getcodigo() != codigoAnterior; i++);
    return *partidas[i];
}

void Jugador::AsociarPartidaIniciada(Partida *PI) {
	partidas.push_back(PI);
}

void Jugador::DesvincularPartida(Partida *par) {
    int i;
	for(i = 0; *partidas[i] != par; i++);
	partidas.erase(partidas.begin() + i);
}

void Jugador::desvincularPartidas(string nomVJ) {
	int i;
	for (i = 0; i < partidas.size(); i++)
		if (*partidas[i]->getVideJuegoAsociado() == nomVJ)
			partidas.erase(partidas.begin() + i);
}

void Jugador::finalizarPartida(int identificador) { //identificador es el lugar donde esta la partida en el vector o es el codigo?
	partidas.erase(partidas.begin() + identificador);
}

void Jugador::finalizarPartida(int identificador) { //Dejo las dos operaciones, despues borro segun la respuesta
    int i;
    for (i = 0; *partidas[i]->getcodigo != identificador; i++);
    partidas.erase(partidas.begin() + i);
}


void Jugador::eliminarSuscripciones(string nomVJ) {
	int i;
	for (i = 0; *sus[i]->getVideojuegoAsociado()->getNombre() != nomVJ; i++)//Ya tiene una suscripcion
    sus.erase(sus.begin() + i);
}

vector<DtSuscripcion*> Jugador::darSuscripcionesActivas() {     
	vector<Suscripcion *> res;
	for (int i = 0; i < sus.size(); i++)
		if (*sus[i]->esActiva())
			res.push_back(*sus[i]->crearDtSuscripcion());
	return res;
}

bool Jugador::tieneSuscripcionActiva(string nombrevid) { //como es la misma función que la sig no es una sobre carga?
	int i;
	for (i = 0; i < sus.size() && !(*sus[i]->esActiva(nombrevid)); i++);
	return i < sus.size();
}

bool Jugador::tieneSuscripcionActiva(Videojuego *vid) {
	bool res = false;
    int i = 0;
	while (i != sus.size() && !res)
		if (*sus[i]->esActiva() && *sus[i]->getVideojuegoAsociado() == vid)
			res = true;
	return res;
}

void Jugador::cancelarSuscripcionActiva(string Juego) {
	bool terminar = false;
	for (int i = 0; i < sus.size() && !terminar; i++)
		if (*sus[i]->esActiva(Juego)) {
			*sus[i]->cancelarSuscripcion();
			terminar = true;
		}
}

void Jugador::asociarSuscripcion(Suscripcion *SNuevo) {
	sus.push_back(SNuevo);
}

vector<DtPartidaMultijugador*> Jugador::partidasJuntos(Jugador* jug) {
	bool indi, es;
	string yo = this->getnickname()
	vector<DtPartidaMultijugador*> res;

	for (unsigned long int i = 0; i < partidas.size(); i++) {
		indi = partidas[i].esIndividual();

		if (indi) {
			es = partidas[i]->esJugadorUnido(jug);

			if (es) {
				PartidaMultijugador* p = dynamic_cast<PartidaMultijugador*>(partidas[i]);
				res.push_back(p->getDtPartidaMultijugador(yo));
			}
		}
	}

	return res;

}

void Jugador::jugadorAbandona(int identificador, Jugador* jug) {
	for (unsigned long int i = 0; i < partidas.size(); i++) {
		if (partidas[i]->getcodigo() == identificador) {
			PartidaMultijugador* p = dynamic_cast<PartidaMultijugador*>(partidas[i]);
			p->jugadorSeVa(jug);
		}
	}
}