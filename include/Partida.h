// falta incluir "DtPartidaEnCurso" y "DtFecha", esperando decicion acerca de los datatypes


#ifndef PARTIDA
#define PARTIDA

#include "Videojuego.h"

#include <iostream>
#include <set>




class Videojuego;

class Partida {
private:
	// es necesario llevar un set de codigos para no crear uno repetido
	static set<int> setCodigos;

	DtFecha fecha;
	float duracion; //minutos
	int codigo;
	bool enCurso;

	Videojuego* pertenece;
public:
	
	static int nuevoCodigo();
	static void quitarCodigo(int cod);

	void setPartida(DtFecha f, Videojuego* v);
	void terminar();
	DtFechaHora getFecha();
	float getduracion();
	bool getenCurso();
	int getcodigo();
	Videojuego* getVideojuego();

	bool esPartidaIndividualFinalizadaDelJuego(string nombrevid);
	DtPartidaEnCurso* getDtPartida() ;
 	virtual void finalizar() = 0;;
	virtual void eliminarPartida() = 0;
 	virtual void tiempoTotal() = 0;


	virtual bool esIndividual() = 0;
    
    //no hace nada pero tiene que estar
    virtual ~Partida();
};


#endif