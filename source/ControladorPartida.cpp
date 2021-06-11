#include "../include/ControladorPartida.h"


using namespace std;

ControladorPartida* ControladorPartida::instance = NULL;


ControladorPartida::ControladorPartida() {
}


ControladorPartida* ControladorPartida::getInstance() {
	if (instance == NULL) {
		instance = new ControladorPartida;
	} 
	return instance;
}




void ControladorPartida::seleccionaVideoJuego(string nombrevid) {
	this->nombrevid = nombrevid;
	ControladorVideojuego* cv = ControladorVideojuego::getInstance();
	this->vid = cv->darVideojuego(nombrevid);
}

void ControladorPartida::ingresarPartidaIndividual(bool continuacion) {
	this->individual = true;
	this->continuacion = continuacion;
}

void ControladorPartida::PartidaAcontinuar(int codigoAnterior) {
	ControladorUsuario* cu = ControladorUsuario::getInstance();
	Jugador* j = cu->darJugador();
	this->Pcont = j->encontrarPartidasIndividual(codigoAnterior);
}

void ControladorPartida::ingresarPartidaMultijugador(bool TransmitidaenVivo) {
	this->individual = false;
	this->TransmitidaenVivo = TransmitidaenVivo;
}


void ControladorPartida::AgregarJugador(string jug) {
	this->jugadoresUnidos.push_back(jug);
}




void ControladorPartida::eliminarPartidas(Videojuego* vj) {
	vj->EliminarPartidas();
}

vector<DtPartidaEnCurso*> ControladorPartida::obtenerPartidasEnCurso() {
	ControladorUsuario* cu = ControladorUsuario::getInstance();
	Jugador* j = cu->darJugador();
	return j->darPartidasEnCurso();
}

vector<DtPartidaEnCurso*> ControladorPartida::obtenerPartidasEnCursoUnido() {
    vector<DtPartidaEnCurso*> res;
	ControladorUsuario* cu = ControladorUsuario::getInstance();
	Jugador* j = cu->darJugador();
	ControladorVideojuego* cv = ControladorVideojuego::getInstance();
	vector<string> strvid = cv->ObtenerVideoJuegos();
	vector<string>::iterator it;
	for(it = strvid.begin(); it != strvid.end(); ++it){
        VideoJuego* v = cv->darVideojuego(*it);
        vector<Partida*> partidas = v->getPartidas();
        vector<Partida*>::iterator it1;
        for(it1 = partidas.begin(); it1 != partidas.end(); ++it1){
            if (dynamic_cast<PartidaMultijugador*>(*it1) != NULL){
                PartidaMultijugador* pm = dynamic_cast<PartidaMultijugador*>(*it1);
                if (pm->perteneceAPartidaJugador(j->getnickname())){
                    res.push_back(pm->getDtPartida())
                }
            }
        }
    }
    return res;
}

void ControladorPartida::finalizarPartida(int identidicador) {
	ControladorUsuario* cu = ControladorUsuario::getInstance();
	Jugador* j = cu->darJugador();
	j->finalizarPartida(identidicador);
}

vector<string> ControladorPartida::listarVideojuegosConSuscripcionActiva() {
	ControladorSuscripciones* cs = ControladorSuscripciones::getInstance();
	return cs->obtenerNombresSuscripcionesActivas();
}

vector<DtPartidaIndividual*> ControladorPartida::HistorialDePartidasIndividualesFinalizadas() {
	ControladorUsuario* cu = ControladorUsuario::getInstance();
	Jugador* j = cu->darJugador();
	return j->darPartidasIndividualesFinalizadas(ControladorPartida::nombrevid);
}

vector<string> ControladorPartida::ListarJugadoresConSuscripcionActiva() {
	ControladorUsuario* cu = ControladorUsuario::getInstance();
	return cu->darNombreJugadoresConSuscripcionActiva(ControladorPartida::nombrevid);
}

void ControladorPartida::IniciarPartida() {
	ControladorUsuario* cu = ControladorUsuario::getInstance();
	
	if (ControladorPartida::individual) {
		PartidaIndividual* part = dynamic_cast<PartidaIndividual*>(this->Pcont);
		Partida* p = new PartidaIndividual(this->continuacion,part,this->vid);
	} else {
		vector<Jugador*> unidos = cu->darJugadores(this->jugadoresUnidos);
		Partida* p = new PartidaMultijugador(this->TransmitidaenVivo,unidos,this->vid);

	}

	Jugador* j = cu->darJugador();
	j->asociarPartidaIniciada(p);
	(this->vid)->AsociarPartida(p);

	this->jugadoresUnidos.clear();

}


void ControladorPartida::CancelarPartida() {
	this->jugadoresUnidos.clear();
}









