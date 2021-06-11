#ifndef JUGADOR
#define JUGADOR

#include <vector>
#include <string>


#include "Usuario.h"
#include "Partida.h" //este tiene a Videojuego.h creo
#include "Suscripcion.h"
#include "DtPartidaIndividual.h"
#include "DtPartidaEnCurso.h"
#include "DtPartidaMultijugador.h"



class Jugador : public Usuario {
	private:
		string nickname;
		string descripcion;
		vector<Partida *> partidas;
		vector<Suscripcion *> sus;
	public:
		Jugador (string unEmail, string unaContrasenia, string unNickname, string unaDescripcion);
		string getnickname ();
		string getdescripcion();
		bool esJugador();

		vector<DtPartidaIndividual *> darPartidasIndividualesFinalizadas(string nombrevid);
		vector<DtPartidaEnCurso *> darPartidasEnCurso();
		Partida* encontrarPartidasIndividual(int codigoAnterior);
		void AsociarPartidaIniciada(Partida *PI);
		void DesvincularPartida(Partida *par);
		void desvincularPartidas(string nomVJ);
		void finalizarPartida(int identificador);
		
		void eliminarSuscripciones(string nomVJ);
		vector<Suscripcion *> darSuscripcionesActivas();
		bool tieneSuscripcionActiva(string nombrevid);
		bool tieneSuscripcionActiva(Videojuego *vid);
		void cancelarSuscripcionActiva(string Juego);
		void asociarSuscripcion(Suscripcion *SNuevo);

		vector<DtPartidaMultijugador*> partidasJuntos(Jugador* jug);
		void jugadorAbandona(int identificador, Jugador* jug);
};


#endif