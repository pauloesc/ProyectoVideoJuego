#ifndef PARTIDA
#define PARTIDA

#include "Videojuego.h"
#include "Reloj.h"

#include "DtFecha.h"
#include "DtPartidaEnCurso.h"
#include "DtPartidaIndividualEnCurso.h"
#include "DtPartidaMultijugadorEnCurso.h"



#include <iostream>
#include <set>
#include <vector>





class Videojuego;

class Partida {
private:
	// es necesario llevar un set  de codigos para no crear uno repetido
	// el set es completamente interno, no hace falta pasarlo a vector
	static set<int> setCodigos;

	DtFecha* fecha;
	float duracion; //minutos
	int codigo;
	bool enCurso;

	Videojuego* pertenece;
public:
	
	static int nuevoCodigo();
	static void quitarCodigo(int cod);

	void setPartida(Videojuego* v);
	void terminar();
	DtFecha* getFecha();
	float getduracion();
	bool getenCurso();
	int getcodigo();
	Videojuego* getVideojuego();

	bool esPartidaIndividualFinalizadaDelJuego(string nombrevid);
	virtual DtPartidaEnCurso* getDtPartida() = 0;
 	virtual void finalizar() = 0;
	virtual void eliminarPartida() = 0;
 	virtual float tiempoTotal() = 0;


	virtual bool esIndividual() = 0;
    
    //no hace nada pero tiene que estar
    virtual ~Partida();
};


#endif