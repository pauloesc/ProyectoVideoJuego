//falta revisar posibles funcines faltantes en todos los casos de uso.
#ifndef CONTROLADORPARTIDA
#define CONTROLADORPARTIDA

#include <vector>

#include "ControladorVideojuego.h"
#include "ControladorUsuario.h"
#include "ControladorSuscripciones.h"


#include "Videojuego.h"
#include "Jugador"
#include "PartidaIndividual.h"
#include "PartidaMultijugador.h"


#include "DtPartidaIndividual.h"
#include "DtPartidaEnCurso.h"

class ControladorPartida {

private:
	static ControladorPartida* instance;
	
	static string nombrevid;
	static Videojuego* vid;
	static bool individual;
	static bool continuacion;
	static Partida* Pcont;
	static int codigoAnterior;
	static bool TransmitidaenVivo;
	static vector<string> jugadoresUnidos;
	
	ControladorPartida();
public:
	static ControladorPartida* getInstance();

	void seleccionaVideoJuego(string nombrevid);
	void ingresarPartidaIndividual(bool continuacion);
	void PartidaAcontinuar(int codigoAnterior);
	void ingresarPartidaMultijugador(bool TransmitidaenVivo);
	void AgregarJugador(string jug);
	

	void eliminarPartidas(VideoJuego* vj);
	vector<DtPartidaEnCurso*> obtenerPartidasEnCurso();
	void finalizarPartida(int identidicador);
	vector<string> listarVideojuegosConSuscripcionActiva();
	vector<DtPartidaIndividual*> HistorialDePartidasIndividualesFinalizadas();
	vector<string> ListarJugadoresConSuscripcionActiva();
	void IniciarPartida():
	void CancelarPartida();


};



#endif