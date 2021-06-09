#ifndef PARTIDAMULTIJUGADOR
#define PARTIDAMULTIJUGADOR

#include "Partida.h"
#include "Abandona.h"
#include "Jugador.h"






class PartidaMultijugador : public Partida{
private:
	bool enVivo;

	set<Abandona*> abandonados;
	vector<Jugador*> jugadoresUnidos;

public:
	PartidaMultijugador(bool enVivo, vector<Jugador*> jugadores, Videojuego* v);

	bool esIndividual();         //siempre devuelve false
	bool getenVivo();

	void finalizar();
	void eliminarPartida();
	bool perteneceAPartidaJugador(string nombreJug);
	void abandonarPartida(string nombreJug);
 	float tiempoTotal();

	DtPartidaEnCurso* getDtPartida(); //*DtPartidaMultijugadorEnCurso
    
    //no hace nada pero tiene que estar
    ~PartidaMultijugador();
    

    
};



#endif
