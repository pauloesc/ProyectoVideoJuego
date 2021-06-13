#ifndef ICONTROLADORPARTIDA
#define ICONTROLADORPARTIDA

#include <vector>



#include "DtPartidaIndividual.h"
#include "DtPartidaMultijugador.h"
#include "DtPartidaEnCurso.h"


class IControladorPartida {

public:

	virtual void seleccionaVideoJuego(string nombrevid)=0;
	virtual void ingresarPartidaIndividual(bool continuacion)=0;
	virtual void PartidaAcontinuar(int codigoAnterior)=;
	virtual void ingresarPartidaMultijugador(bool TransmitidaenVivo)=0;
	virtual void AgregarJugador(string jug)=0;
	

	virtual void abandonarPartida(int indentificador)=0;
	virtual vector<DtPartidaMultijugador*> obtenerPartidasEnCursoUnido()=0;
	
	virtual vector<DtPartidaEnCurso*> obtenerPartidasEnCurso()=0;
	virtual void finalizarPartida(int identidicador)=0;
	virtual vector<string> listarVideojuegosConSuscripcionActiva()=0;
	virtual vector<DtPartidaIndividual*> HistorialDePartidasIndividualesFinalizadas()=0;
	virtual vector<string> ListarJugadoresConSuscripcionActiva()=0;
	virtual void IniciarPartida()=0;
	virtual void CancelarPartida()=0;


};



#endif
