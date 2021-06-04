//falta revisar getDruacion "reloj"

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





DtFecha Partida::getFecha() {
    return fecha;
}

float Partida::getduracion(){
	if (!enCurso) {
		return duracion;
	} else {
		actual = reloj->getFecha();
		int a = getanio(actual) - getanio(fecha);
		int m = getmes(actual) - getmes(fecha);
		int d = getdia(actual) - getdia(fecha);
		int h = gethora(actual) - gethora(fecha);
		int min = getminuto(actual) - getminuto(fecha);
		return (min + 60*h + 60*24*d + 60*24*30*m + 365*24*60*a);
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
	string nom = pertenece->getnombre();
	return ((nom == nombrevid) and (enCurso));
}

DtPartidaEnCurso* Partida::getDtPartida() {
	// falta implemetar, falta revision de los datatypes

}



//no hace nada pero tiene que estar
Partida::~Partida(){
};
