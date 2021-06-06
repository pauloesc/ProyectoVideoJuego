#include "../include/PartidaMultijugador.h"
#include <list>


using namespace std;


PartidaMultijugador::PartidaMultijugador (bool enVivo, set<Jugador*> jugadores, Videojuego* v){
	this->enVivo = enVivo;
	this->jugadoresUnidos = jugadores;

	// el set de abandonados se inicializa solo como vacio
	Partida* p = dynamic_cast<Partida*>(this);
	p->setPartida(v)


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
    	
    	Abandona* ab = new Abandona(*it);  //pone la fecha del sistema

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
  	Partida::quitarCodigo(this->getcodigo());
}

float PartidaMultijugador::tiempoTotal() {
	Partida* p = dynamic_cast<Partida*>(this);
	float tiempo = p->getduracion();

	tiempo = tiempo*(jugadoresUnidos.size());

	DtFecha f;
	DtFecha* actual = Reloj::getFecha();
	set<Abandona*>::iterator it;
	for (it=abandonados.begin(); it!=abandonados.end(); ++it) { 
    	f = (it*)->getFecha()
    	
		int a = actual->getAnio() - f->getAnio();
		int m = actual->getMes() - f->getMes();
		int d = actual->getDia() - f->getDia();
		int h = actual->getHora() - f->getHora();
		int min = actual->getMinuto() - f->getMinuto();
		tiempo = tiempo + min + 60*h + 60*24*d + 60*24*30*m + 365*24*60*a;
  	}

  	return tiempo;
}

DtPartidaEnCurso* PartidaMultijugador::getDtPartida() {
	DtFecha* f = this->getFecha();
	string nom = (this->getVideojuego())->getNombre();
	string unJug;


	list<string> listilla;
	list<int>::iterator it;
	it = listilla.begin();

	set<Abandona*>::iterator it;
	for (it=listilla.begin(); it!=listilla.end(); ++it) {
		unJug = ((*it)->getJugador())->getnickname();
		listilla.insert(it,unJug);
	}


	int tam = listilla.size() + 1;

	DtPartidaEnCurso* p = new DtPartidaMultijugadorEnCurso(*f,this->getcodigo(),nom,this->getenVivo(),listilla,tam);
	return p;
}

PartidaMultijugador::~PartidaMultijugador(){
}
