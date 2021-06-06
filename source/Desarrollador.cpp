#include <iterator>

#include "Desarrollador.h"

using namespace std;

Desarrollador::Desarrollador (string unEmail, string unaContrasenia, string unaEmpresa) : Usuario (unEmail, unaContrasenia) {
	nombreEmpresa = unaEmpresa;
}

string Desarrollador::getnomEmpresa() {
	return nombreEmpresa;
}

bool Desarrollador::esJugador() {
	return false;
}

vector<DataEstadisticaDeSegundoTipo> Desarrollador::DarEstadisticas(Videojuego vj) {
	vector<DataEstadisticaDeSegundoTipo> res;
	estadisticas::iterator it;
	for (it = estadisticas.begin(); it != estadisticas.end(); ++it) 
		res.push_back(it->second->DarEstadisticas(vj));
	return res;
}