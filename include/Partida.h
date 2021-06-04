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
	
	int nuevoCodigo();
	void quitarCodigo(int cod);

	DtFechaHora getFecha();
	float getduracion();
	bool getenCurso();
	int getcodigo();
	Videojuego* getVideojuego();

	bool esPartidaIndividualFinalizadaDelJuego(string nombrevid);
	DtPartidaEnCurso* getDtPartida() ;
 	virtual finalizar() = 0;;
	virtual eliminarPartida() = 0;
 	virtual tiempoTotal() = 0;


	virtual bool esIndividual() = 0;
    
    //no hace nada pero tiene que estar
    virtual ~Partida();
};


#endif