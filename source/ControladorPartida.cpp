#include ".../include/ControladorPartida.h"


using namespace std;

ControladorPartida* ControladorPartida::instance = NULL;
string ControladorPartida::nombrevid;
Videojuego* ControladorPartida::vid;
bool ControladorPartida::individual;
bool ControladorPartida::continuacion;
Partida* ControladorPartida::Pcont;
int ControladorPartida::codigoAnterior;
bool ControladorPartida::TransmitidaenVivo;
string ControladorPartida::jug;
vector<string> ControladorPartida::jugadoresUnidos;

ControladorPartida::ControladorPartida() {
}


ControladorPartida* ControladorPartida::getInstance() {
	if (instance == NULL) {
		instance = new ControladorPartida;
	} 
	return instance;
}




void ControladorPartida::seleccionaVideoJuego(string nombrevid) {
	ControladorPartida::nombrevid = nombrevid;
	ControladorVideojuego* cv = ControladorVideojuego::getInstance();
	ControladorPartida::vid = cv->darVideojuego(nombrevid);
}

void ControladorPartida::ingresarPartidaIndividual(bool continuacion) {
	ControladorPartida::individual = true;
	ControladorPartida::continuacion = continuacion;
}

void ControladorPartida::PartidaAcontinuar(int codigoAnterior) {
	ControladorUsuario* cu = ControladorUsuario::getInstance();
	Jugador* j = cu->darJugador();
	ControladorPartida::Pcont = j->encontrarPartidasIndividual(codigoAnterior);
}

void ControladorPartida::ingresarPartidaMultijugador(bool TransmitidaenVivo) {
	ControladorPartida::individual = false;
	ControladorPartida::TransmitidaenVivo = TransmitidaenVivo;
}


void ControladorPartida::AgregarJugador(string jug) {
	ControladorPartida::jugadoresUnidos.push_back(jug);
}




void ControladorPartida::eliminarPartidas(VideoJuego* vj) {
	vj->EliminarPartidas();
}

vector<DtPartidaEnCurso*> ControladorPartida::obtenerPartidasEnCurso() {
	ControladorUsuario* cu = ControladorUsuario::getInstance();
	Jugador* j = cu->darJugador();
	return j->darPartidasEnCurso();
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
		PartidaIndividual* part = dynamic_cast<PartidaIndividual*>(ControladorPartida::Pcont);
		Partida* p = new PartidaIndividual(ControladorPartida::continuacion,part,ControladorPartida::vid);
	} else {
		vector<Jugador*> unidos = cu->darJugadores(ControladorPartida::jugadoresUnidos);
		Partida* p = new PartidaMultijugador(ControladorPartida::TransmitidaenVivo,unidos,ControladorPartida::vid);

	}

	Jugador* j = cu->darJugador();
	j->asociarPartidaIniciada(p);
	ControladorPartida::vid->AsociarPartida(p);

	ControladorPartida::jugadoresUnidos.clear();

}


void ControladorPartida::CancelarPartida() {
	ControladorPartida::jugadoresUnidos.clear();
}









