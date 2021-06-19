#include "../include/Partida.h"
using namespace std;

// hay que "inicializar" los atributos static
set<int> Partida::setCodigos;


int Partida::nuevoCodigo() {
	bool ingresado = false;
	int cod;
	while (!ingresado) {

		cod = rand() % 1000 + 100;  //numero "random" entre 100-1000
		set<int>::iterator raro;
		raro = setCodigos.find(cod);

		if (*raro != cod) {
			setCodigos.insert(cod);
			ingresado = true;
		}

	}
	return cod;
}

void Partida::quitarCodigo(int cod) {
	setCodigos.erase(cod);
}





void Partida::setPartida(Videojuego* v) {
	this->fecha = Reloj::getFecha();
	this->pertenece = v;

	this->codigo = Partida::nuevoCodigo();
	this->enCurso = true;
}

void Partida::terminar() {
	this->enCurso = false;
	DtFecha* actual = Reloj::getFecha();
	int a = actual->getAnio() - fecha->getAnio();
	int m = actual->getMes() - fecha->getMes();
	int d = actual->getDia() - fecha->getDia();
	int h = actual->getHora() - fecha->getHora();
	int min = actual->getMinuto() - fecha->getMinuto();
	this->duracion = (min + 60*h + 60*24*d + 60*24*30*m + 365*24*60*a);
}

DtFecha* Partida::getFecha() {
    return fecha;
}
/*
float Partida::getduracion(){
	if (!enCurso) {
		return duracion;
	} else {
		DtFecha* actual = Reloj::getFecha();
		int a = actual->getAnio() - fecha->getAnio();
		int m = actual->getMes() - fecha->getMes();
		int d = actual->getDia() - fecha->getDia();
		int h = actual->getHora() - fecha->getHora();
		int min = actual->getMinuto() - fecha->getMinuto();
		int res = (min + 60*h + 60*24*d + 60*24*30*m + 365*24*60*a);
		return res;
	}
};
*/

float Partida::getduracion(){
	if (!enCurso) {
		return duracion;
	} else {
		return 0;
	}
};


bool Partida::getenCurso() {
	return enCurso;
}

int Partida::getcodigo() {
	return codigo;
}

Videojuego* Partida::getVideojuego() {
	return pertenece;
}



bool Partida::esPartidaIndividualFinalizadaDelJuego(string nombrevid) {
	string nom = pertenece->getNombre();
	return ((nom == nombrevid) and (!enCurso));
}





//no hace nada pero tiene que estar
Partida::~Partida(){
}
