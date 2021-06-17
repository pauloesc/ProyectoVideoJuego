#include "../include/Jugador.h"

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
	PartidaIndividual* pi;
    for (long unsigned int i = 0; i < partidas.size(); i++) {
        if (partidas[i]->esPartidaIndividualFinalizadaDelJuego(nombrevid)) {
            pi = dynamic_cast<PartidaIndividual*>(partidas[i]);
            res.push_back(pi->darDatosPartida());
        }
    }
	return res;
}

vector<DtPartidaEnCurso*> Jugador::darPartidasEnCurso() {
	vector<DtPartidaEnCurso *> res;
	for (unsigned long int i = 0; i < partidas.size(); i++){
		if (partidas[i]->getenCurso()){
			res.push_back(partidas[i]->getDtPartida());
		}
	}
	return res;
}

Partida* Jugador::encontrarPartidasIndividual(int codigoAnterior) {
	Partida* res = NULL;
	unsigned long int i = 0;
	bool listo = false;

	while (!listo and (i < partidas.size())) {
		if (partidas[i]->getcodigo() == codigoAnterior) {
			listo = true;
			res = partidas[i];
		}
		i++;
	}
	return res;
}

void Jugador::AsociarPartidaIniciada(Partida *PI) {
	partidas.push_back(PI);
}

void Jugador::DesvincularPartida(Partida *par) {
    int i;
	for(i = 0; partidas[i] != par; i++);
	partidas.erase(partidas.begin() + i);
}

void Jugador::desvincularPartidas(string nomVJ) {
	long unsigned int i = 0;

	while (i < partidas.size()) {
		if ((partidas[i]->getVideojuego())->getNombre() == nomVJ) {
			partidas.erase(partidas.begin() + i);
		} else {
			i++;
		}
	}

}


void Jugador::finalizarPartida(int identificador) { 
    for (long unsigned int i = 0; i < partidas.size(); i++) {
    	if (partidas[i]->getcodigo() == identificador) {
    		partidas[i]->finalizar();
    	}
    }
}


void Jugador::eliminarSuscripciones(string nomVJ) {
	long unsigned int i = 0;
	
	while (i < sus.size()) {
		if ((sus[i]->getVideojuegoAsociado())->getNombre() == nomVJ) {
			delete sus[i];
			sus.erase(sus.begin()+i);
		} else {
			i++;
		}
	}
}

vector<DtSuscripcion*> Jugador::darSuscripcionesActivas() {     
	vector<DtSuscripcion*> res;
	for (long unsigned int i = 0; i < sus.size(); i++)
		if (sus[i]->esActiva())
			res.push_back(sus[i]->crearDtSuscripcion());
	return res;
}

bool Jugador::tieneSuscripcionActiva(string nombrevid) {
	long unsigned int i;
	for (i = 0; i < sus.size() && !(sus[i]->esActiva(nombrevid)); i++);
	return i < sus.size();
}

bool Jugador::tieneSuscripcionActiva(Videojuego *vid) {
	bool res = false;
    long unsigned int i = 0;
	while (i != sus.size() && !res) { 
		if (sus[i]->esActiva() && sus[i]->getVideojuegoAsociado() == vid) { 
			res = true;
		}
		i++;
	}
	return res;
}

bool Jugador::tieneSuscripcionActivaVitalicia(Videojuego *vid) {
	bool res = false;
    long unsigned int i = 0;
	while (i != sus.size() && !res) { 
		if (sus[i]->esActiva() && sus[i]->getVideojuegoAsociado() == vid && (dynamic_cast<SuscripcionVitalicia*>(sus[i]) != NULL))
			res = true;
		i++;
	}
	return res;
}

void Jugador::cancelarSuscripcionActiva(string Juego) {
	bool terminar = false;
	for (long unsigned int i = 0; i < sus.size() && !terminar; i++)
		if (sus[i]->esActiva(Juego)) {
			sus[i]->cancelarSuscripcion();
			terminar = true;
		}
}

void Jugador::asociarSuscripcion(Suscripcion *SNuevo) {
	sus.push_back(SNuevo);
}

vector<DtPartidaMultijugador*> Jugador::partidasJuntos(Jugador* jug) {
	bool indi, es;
	string yo = this->getnickname();
	vector<DtPartidaMultijugador*> res;

	for (unsigned long int i = 0; i < partidas.size(); i++) {
		indi = partidas[i]->esIndividual();

		if (!indi) {
			PartidaMultijugador* p = dynamic_cast<PartidaMultijugador*>(partidas[i]);
			es = p->esJugadorUnido(jug);

			if (es) {
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

Jugador::~Jugador(){
    
}
