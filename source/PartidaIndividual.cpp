//faltan implementar las funciones de los datatypes
#include "../include/PartidaIndividual.h"



PartidaIndividual::PartidaIndividual (bool continuacion, DtFecha fecha, PartidaIndividual* anterior, Videojuego* v){
	this->continuacion = continuacion;
	this->anterior = anterior;

	Partida* p = dynamic_cast<Partida*>(this);
	p->setPartida(fecha,v)


}

bool PartidaIndividual::esIndividual() {
	return true;
}

bool PartidaIndividual::getcontinuacion() {
	return continuacion;
}

void PartidaIndividual::finalizar() {
	Partida* p = dynamic_cast<Partida*>(this);
	p->terminar();
}

//aclaracion: no es un destructor, para eliminar toda la memoria de 
// Partida* p hay que hacer p->eliminarPartida() y delete p
void PartidaIndividual::eliminarPartida() {
	// no hay que eliminar nada extra XD
}

float PartidaIndividual::tiempoTotal() {
	Partida* p = dynamic_cast<Partida*>(this);
	return p->getduracion();
}

PartidaIndividual::~PartidaIndividual(){
}
