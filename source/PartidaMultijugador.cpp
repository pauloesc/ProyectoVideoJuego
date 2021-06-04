//faltan implementar las funciones de los datatypes, y revisar lo del reloj
#include "../include/PartidaMultijugador.h"



PartidaMultijugador::PartidaMultijugador (bool enVivo, DtFecha fecha, set<Jugador*> jugadores, Videojuego* v){
	this->enVivo = enVivo;
	this->jugadoresUnidos = jugadores;

	// el set de abanconados se inicializa solo como vacio
	Partida* p = dynamic_cast<Partida*>(this);
	p->setPartida(fecha,v)


}

bool PartidaMultijugador::esIndividual() {
	return false;
}

bool PartidaMultijugador::getenVivo() {
	return enVivo;
}

void PartidaMultijugador::finalizar() {
	Partida* p = dynamic_cast<Partida*>(this);
	p->terminar();


	//recorro el set de jugadoresUnidos 
	//(it es un puntero al contenido del set, es un puntero a un puntero de Jugador)
	set<Jugadores*>::iterator it;
	for (it=jugadoresUnidos.begin(); it!=jugadoresUnidos.end(); ++it) { 
    	
    	Abandona* ab = new Abandona();  //pone la fecha del sistema
    	ab->setJugador(*it)
    	abandonados.insert(ab);

    	jugadoresUnidos.erase(*it);
  	}

}

//aclaracion: no es un destructor, para eliminar toda la memoria de 
// Partida* p hay que hacer p->eliminarPartida() y delete p
void PartidaMultijugador::eliminarPartida() {
	set<Abandona*>::iterator it;
	for (it=abandonados.begin(); it!=abandonados.end(); ++it) { 
    	delete *it;
  	}

  	abandonados.clear();
  	jugadoresUnidos.clear();
}

float PartidaMultijugador::tiempoTotal() {
	Partida* p = dynamic_cast<Partida*>(this);
	float tiempo = p->getduracion();

	tiempo = tiempo*(jugadoresUnidos.size());

	DtFecha f;
	DtFecha actual = reloj->getFecha();
	set<Abandona*>::iterator it;
	for (it=abandonados.begin(); it!=abandonados.end(); ++it) { 
    	f = (it*)->getFecha()
    	
		int a = getanio(actual) - getanio(f);
		int m = getmes(actual) - getmes(f);
		int d = getdia(actual) - getdia(f);
		int h = gethora(actual) - gethora(f);
		int min = getminuto(actual) - getminuto(fecha);
		tiempo = tiempo + min + 60*h + 60*24*d + 60*24*30*m + 365*24*60*a;
  	}

  	return tiempo;
}


PartidaMultijugador::~PartidaMultijugador(){
}
