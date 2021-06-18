#include "../include/PartidaIndividual.h"
#include "../include/Videojuego.h"


using namespace std;


PartidaIndividual::PartidaIndividual (bool continuacion, PartidaIndividual* anterior, Videojuego* v){
	this->continuacion = continuacion;
	this->anterior = anterior;

	Partida* p = dynamic_cast<Partida*>(this);
	p->setPartida(v);


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
	Partida::quitarCodigo(this->getcodigo());
}

float PartidaIndividual::tiempoTotal() {
	Partida* p = dynamic_cast<Partida*>(this);
	return p->getduracion();
}

DtPartidaIndividual* PartidaIndividual::darDatosPartida() {
	DtFecha* f = this->getFecha();
	DtPartidaIndividual* dt = new DtPartidaIndividual(f,this->getduracion(),this->getcodigo(),this->getenCurso(),this->getcontinuacion());
	return dt;
}

DtPartidaEnCurso* PartidaIndividual::getDtPartida() {
	DtFecha* f = this->getFecha();
	string nom = (this->getVideojuego())->getNombre();
	DtPartidaEnCurso* p = new DtPartidaIndividualEnCurso(*f,this->getcodigo(),nom,this->getcontinuacion());
	return p;
}



PartidaIndividual::~PartidaIndividual(){
}
