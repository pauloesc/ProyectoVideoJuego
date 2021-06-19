#include "../include/PartidaMultijugador.h"

#include <list>
#include <vector>
#include <set>



using namespace std;


PartidaMultijugador::PartidaMultijugador (bool enVivo, vector<Jugador*> jugadores, Videojuego* v){
	this->enVivo = enVivo;
	this->jugadoresUnidos = jugadores;

	// el set de abandonados se inicializa solo como vacio
	Partida* p = dynamic_cast<Partida*>(this);
	p->setPartida(v);


}

bool PartidaMultijugador::esIndividual() {
	return false;
}

bool PartidaMultijugador::getenVivo() {
	return enVivo;
}

void PartidaMultijugador::jugadorSeVa(Jugador* jug) {
	unsigned long int i = 0;
	bool encontrado = false;
	while ((i<jugadoresUnidos.size()) and !encontrado) {
		if (jugadoresUnidos[i] == jug) {
			encontrado = true;
		} else {
			i++;
		}
	}

	if (encontrado) {
		Abandona* ab = new Abandona(jug);
		abandonados.insert(ab);

		jugadoresUnidos.erase(jugadoresUnidos.begin()+i);
	}
}

bool PartidaMultijugador::esJugadorUnido(Jugador* jug) {
	unsigned long int i = 0;
	bool encontrado = false;
	while ((i<jugadoresUnidos.size()) and !encontrado) {
		if (jugadoresUnidos[i] == jug) {
			encontrado = true;
		} else {
			i++;
		}
	}
	return encontrado;
}

DtPartidaMultijugador* PartidaMultijugador::getDtPartidaMultijugador(string ini) {
	Partida* p = dynamic_cast<Partida*>(this);

	vector<string> vs;

	for (unsigned long int i = 0; i < jugadoresUnidos.size(); i++) {
		vs.push_back(jugadoresUnidos[i]->getnickname());
	}

	DtPartidaMultijugador* res = new DtPartidaMultijugador(p->getcodigo(), p->getFecha(), (p->getVideojuego())->getNombre(), this->getenVivo(), ini, vs);
	return res;
}

void PartidaMultijugador::finalizar() {
	Partida* p = dynamic_cast<Partida*>(this);
	p->terminar();


	//recorro el set de jugadoresUnidos 
	//(it es un puntero al contenido del set, es un puntero a un puntero de Jugador)
	for (long unsigned int i = 0; i<jugadoresUnidos.size(); i++) { 
    	
    	Abandona* ab = new Abandona(jugadoresUnidos[i]);  //pone la fecha del sistema

    	abandonados.insert(ab);

  	}

  	jugadoresUnidos.clear();
}


/*
float PartidaMultijugador::tiempoTotal() {
	Partida* p = dynamic_cast<Partida*>(this);
	float tiempo = p->getduracion();

	tiempo = tiempo*(jugadoresUnidos.size());

	DtFecha* f;
	DtFecha* inicio = this->getFecha();
	set<Abandona*>::iterator it;
	for (it=abandonados.begin(); it!=abandonados.end(); ++it) { 
    	f = (*it)->getFecha();
    	
		int a = f->getAnio() - inicio->getAnio();
		int m =f->getMes() - inicio->getMes();
		int d =f->getDia() - inicio->getDia();
		int h = f->getHora() - inicio->getHora();
		int min = f->getMinuto() - inicio->getMinuto();
		tiempo = tiempo + min + 60*h + 60*24*d + 60*24*30*m + 365*24*60*a;
  	}

  	return tiempo;
}
*/

float PartidaMultijugador::tiempoTotal() {

	float tiempoTotal=0;

	//si el jugador que inicio la partida no la finalizo aporta 0
	tiempoTotal = tiempoTotal + this->getduracion();

	DtFecha* InicioPartida = getFecha();
	DtFecha* FinPartidaDeUnIntegrate = 0;

	set<Abandona*>::iterator it;
	for (it=abandonados.begin(); it!=abandonados.end(); ++it) 
	{
		//pido la fecha en que un determinado integrate finalizo su participacion
		FinPartidaDeUnIntegrate = (*it)->getFecha();

		int a = FinPartidaDeUnIntegrate->getAnio() - InicioPartida->getAnio();
		int min = FinPartidaDeUnIntegrate->getMes() - InicioPartida->getMes();
		int d = FinPartidaDeUnIntegrate->getDia() - InicioPartida->getDia();
		int h = FinPartidaDeUnIntegrate->getHora() - InicioPartida->getHora();
		int m = FinPartidaDeUnIntegrate->getMinuto() - InicioPartida->getMinuto();

		tiempoTotal = tiempoTotal + min + 60*h + 60*24*d + 60*24*30*m + 365*24*60*a;
	}
		
	return tiempoTotal;

}

DtPartidaEnCurso* PartidaMultijugador::getDtPartida() {
	DtFecha* f = this->getFecha();
	string nom = (this->getVideojuego())->getNombre();
	string unJug;


	list<string> listilla;
	

	for (long unsigned int i = 0; i < jugadoresUnidos.size(); i++) {
		listilla.insert(listilla.begin(),jugadoresUnidos[i]->getnickname());
	}

	


	int tam = listilla.size() + 1;

	DtPartidaEnCurso* p = new DtPartidaMultijugadorEnCurso(*f,this->getcodigo(),nom,this->getenVivo(),listilla,tam);
	return p;
}

void PartidaMultijugador::eliminarPartida() {
	set<Abandona*>::iterator it;
	for (it=abandonados.begin(); it!=abandonados.end(); ++it) { 
    	delete *it;
  	}

  	abandonados.clear();
  	jugadoresUnidos.clear();
  	Partida::quitarCodigo(this->getcodigo());
}

PartidaMultijugador::~PartidaMultijugador(){
	set<Abandona*>::iterator it;
	for (it=abandonados.begin(); it!=abandonados.end(); ++it) { 
    	delete *it;
  	}

  	abandonados.clear();
  	jugadoresUnidos.clear();
  	Partida::quitarCodigo(this->getcodigo());
}
