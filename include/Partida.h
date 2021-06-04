// falta incluir "DtPartidaEnCurso" y "DtFecha", esperando decicion acerca de los datatypes


#ifndef PARTIDA
#define PARTIDA

#include "Videojuego.h"



class Videojuego;

class Partida {
private:
	DtFecha fecha;
	float duracion;
	int codigo;
	bool enCurso;

	Videojuego* pertenece;
public:

	DtFechaHora getFecha();
	float getduracion();
	bool getenCurso();
	int getcodigo();
	Videojuego* getVideojuego();

	bool esPartidaIndividualFinalizadaDelJuego(nombrevid:string);
	DtPartidaEnCurso* getDtPartida() ;

 	virtual finalizar() = 0;;
	virtual eliminarPartida() = 0;
 	virtual tiempoTotal() = 0;


	virtual bool esIndividual() = 0;
    
    //no hace nada pero tiene que estar
    virtual ~Partida();
};


#endif