#ifndef PARTIDAINDIVIDUAL
#define PARTIDAINDIVIDUAL



#include "DtPartidaIndividual.h"
#include "../include/Videojuego.h"



class Partida;

class PartidaIndividual : public Partida{
private:
	bool continuacion;
	PartidaIndividual* anterior;
public:
	PartidaIndividual(bool continuacion, PartidaIndividual* anterior, Videojuego* v);

	bool esIndividual();         //siempre devuelve true
	bool getcontinuacion();

	void finalizar();
	void eliminarPartida();
 	float tiempoTotal();

 	DtPartidaIndividual* darDatosPartida();
	DtPartidaEnCurso* getDtPartida(); //*DtPartidaIndividualEnCurso
    
    ~PartidaIndividual();
    

    
};

#include "Partida.h"

#endif
