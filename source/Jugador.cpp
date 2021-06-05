#include <iterator>


#include "Jugador.h"

using namespace std;

//Esta mal, necesito revisar // Le agregue el email y contrasenia porque lo necesito como parametro para crear la operacion en el controlador usuario


Jugador::Jugador(string unEmail, string unaContrasenia string unNickname, string unaDescripcion) :Usuario (unEmail, unaContrasenia) {
	nickname = unNickname;
	descripcion = unaDescripcion;
}

string Jugador::getnickname () {
	return nickname;
}

string Jugador::getdescripcion() {
	return descripcion;
}

set(DtPartidaIndividual) Jugador::darPartidasIndividualesFinalizadas(string nombrevid) {
	set(DtPartidaIndividual) res;
	partidas::iterator it;
	for (it = partidas.begin(); it != partidas.end(); ++it)
		if (it->second->esPartidaIndividualFinalizadaDelJuego(nombrevid))
			res.insert(it->second->darDatosPartida());
	return res;
}

set(DtPartidaEnCurso) Jugador::darPartidasEnCurso() {
	set(DtPartidaEnCurso) res;
	partidas::iterator it;
	for (it = partidas.begin(); it != partidas.end(); ++it)
		if (it->second->getEnCurso())
			res.insert(it->second->getDtPartida());
	return res;
}

Partida Jugador::encontrarPartidasIndividual(int codigoAnterior) {
	partidas::iterator it;
	it = partidas.begin();
	while (it->first != codigoAnterior) //existe una partida con ese codigo
		++it;
	return it->second; //it->second es un puntero a Partida, ¿Devuelvo el mismo tipo de la función?
}

void Jugador::AsociarPartidaIniciada(Partida PI) {
	partidas[PI->getCodigo()] = PI; //Supongo que el getter de codigo de la partida es asi(tengo que revisar despues)
}

void Jugador::DesvincularPartida(Partida par) {
	partidas::iterator it;
	for(it = partidas.begin(); it != partidas.end() && it->second != par; ++it); //it->second es un puntero a Partida, ¿Se puede hacer esta comparación?
	it->second->erase();
}

void Jugador::finalizarPartida(int identificador) {
	partidas::iterator it;
	for (it = partidas.begin(); it != partidas.end() && it->first != identificador; ++it);
	it->second->finalizar();
}


//Parte de Suscripcion debe estar todo mal la sintexis pq no se usar vector aún, pero la idea de resolución es asi

void Jugador::eliminarSuscripciones(string nomVJ) {
	sus::iterator it;
	for (it = sus.begin(); it != sus.end(); ++it)
		if (it->getVideojuegoAsociado()->getNombre() == nomVJ) //Chequear esto
			it->erase(); //dudoso
}

set(Suscripcion) Jugador::darSuscripcionesActivas() {
	set(Suscripcion) res;
	sus::iterator it;
	for (it = sus.begin(); it != sus.end(); ++it)
		if (it->esActiva())
			res.insert(it->crearDtSuscripcion());
	return res;
}

bool Jugador::tieneSuscripcionActiva(string nombrevid) {
	sus::iterator it;
	it = sus.begin();
	while (it != sus.end() && !it->esActiva(nombrevid))
		++it;
	return it->esActiva(nombrevid);
}

bool Jugador::tieneSuscripcionActiva(Videojuego vid) {
	sus::iterator it;
	bool res = false;
	for (it = sus.begin(); it != sus.end(); ++it)
		if (it->esActiva() && it->getVideojuegoAsociado() == vid)
			res = true;
	return res;
}

void Jugador::cancelarSuscripcionActiva(string Juego) {
	sus::iterator it;
	for (it = sus.begin(); it != sus.end(); ++it)
		if (it->esActiva(Juego))
			it->cancelarSuscripcion();
}

void Jugador::asociarSuscripcion(Suscripcion SNuevo) {
	sus.insert(SNuevo); //khe
}