#ifndef PARTIDA
#define PARTIDA


#include "Reloj.h"
#include "DtPartidaMultijugador.h"
#include "DtFecha.h"
#include "DtPartidaEnCurso.h"
#include "DtPartidaIndividualEnCurso.h"
#include "DtPartidaMultijugadorEnCurso.h"



#include <iostream>
#include <set>
#include <vector>




class Videojuego;
class Abandona;

class Partida {
private:
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
    
    virtual ~Partida();
};
#include "Videojuego.h"    
#include "Abandona.h"

#endif