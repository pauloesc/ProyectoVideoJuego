#ifndef PARTIDAINDIVIDUAL
#define PARTIDAINDIVIDUAL

#include "Partida.h"





class PartidaIndividual : public Partida{
private:
	bool continuacion;
	PartidaIndividual* anterior;
public:
	PartidaIndividual(bool continuacion, DtFecha fecha, PartidaIndividual* anterior, Videojuego* v);

	bool esIndividual();         //siempre devuelve true
	bool getcontinuacion();

	void finalizar();
	void eliminarPartida();
 	float tiempoTotal();

 	DtPatidaIndividual darDatosPatida();
	DtPartidaIndividualEnCurso getDtPartida();
    
    //no hace nada pero tiene que estar
    ~PartidaIndividual();
    

    
};



#endif
