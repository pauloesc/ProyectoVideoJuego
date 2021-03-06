
#ifndef CONTROLADORPARTIDA
#define CONTROLADORPARTIDA

#include "IControladorPartida.h"

#include <vector>

#include "ControladorVideojuego.h"
#include "ControladorUsuario.h"
#include "ControladorSuscripciones.h"


#include "Videojuego.h"
#include "Jugador.h"
#include "PartidaIndividual.h"
#include "PartidaMultijugador.h"


#include "DtPartidaIndividual.h"
#include "DtPartidaMultijugador.h"
#include "DtPartidaEnCurso.h"


class ControladorPartida : public IControladorPartida {

private:
	static ControladorPartida* instance;
	
	string nombrevid;
	Videojuego* vid = 0;
	bool individual;
	bool continuacion;
	Partida* Pcont = 0;
	int codigoAnterior;
	bool TransmitidaenVivo;
	vector<string> jugadoresUnidos;
	
	ControladorPartida();
public:
	static ControladorPartida* getInstance();

	void seleccionaVideoJuego(string nombrevid);
	void ingresarPartidaIndividual(bool continuacion);
	void PartidaAcontinuar(int codigoAnterior);
	void ingresarPartidaMultijugador(bool TransmitidaenVivo);
	void AgregarJugador(string jug);
	

	void abandonarPartida(int indentificador);
	vector<DtPartidaMultijugador*> obtenerPartidasEnCursoUnido();
	void eliminarPartidas(Videojuego* vj);
	vector<DtPartidaEnCurso*> obtenerPartidasEnCurso();
	void finalizarPartida(int identidicador);
	vector<string> listarVideojuegosConSuscripcionActiva();
	vector<DtPartidaIndividual*> HistorialDePartidasIndividualesFinalizadas();
	vector<string> ListarJugadoresConSuscripcionActiva();
	void IniciarPartida();
	int IniciarPartidaConCodigo();
	void CancelarPartida();
	~ControladorPartida();


};



#endif