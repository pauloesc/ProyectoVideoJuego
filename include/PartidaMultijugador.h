#ifndef PARTIDAMULTIJUGADOR
#define PARTIDAMULTIJUGADOR

#include "Jugador.h"
#include "Abandona.h"
#include "Partida.h"

class Jugador;

class PartidaMultijugador : public Partida {
private:
	bool enVivo;

	set<Abandona*> abandonados;
	vector<Jugador*> jugadoresUnidos;

public:
	PartidaMultijugador(bool enVivo, vector<Jugador*> jugadores, Videojuego* v);

	bool esIndividual();         //siempre devuelve false
	bool getenVivo();

	void jugadorSeVa(Jugador* jug);
	bool esJugadorUnido(Jugador* jug);
	DtPartidaMultijugador* getDtPartidaMultijugador(string ini);
	void eliminarPartida();
	void finalizar();
 	float tiempoTotal();

	DtPartidaEnCurso* getDtPartida(); //*DtPartidaMultijugadorEnCurso
    
    
    ~PartidaMultijugador();
    

    
};



#endif
