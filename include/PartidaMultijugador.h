#ifndef PARTIDAMULTIJUGADOR
#define PARTIDAMULTIJUGADOR

#include "Partida.h"
#include "Abandona.h"





class PartidaMultijugador : public Partida{
private:
	bool enVivo;

	set<Abandona*> abandonados;
	set<Jugador*> jugadoresUnidos;
	// set<Comentario*> comentarios;

public:
	PartidaMultijugador(bool enVivo, DtFecha fecha, set<Jugador*> jugadores, Videojuego* v);

	bool esIndividual();         //siempre devuelve false
	bool getenVivo();

	void finalizar();
	void eliminarPartida();
 	float tiempoTotal();

	DtPartidaMultijugadorEnCurso getDtPartida();
    
    //no hace nada pero tiene que estar
    ~PartidaMultijugador();
    

    
};



#endif
