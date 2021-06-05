#include <iterator>

#include "Desarrollador.h"

using namespace std;

Desarrollador::Desarrollador (string unEmail, string unaContrasenia, string unaEmpresa) : Usuario (unEmail, unaContrasenia) {
	nombreEmpresa = unaEmpresa;
}

string Desarrollador::getnomEmpresa() {
	return nombreEmpresa;
}

set <DataEstadisticaDeSegundoTipo> Desarrollador::DarEstadisticas(Videojuego vj) {
	set <DataEstadisticaDeSegundoTipo> res;
	estadisticas::iterator it;
	for (it = estadisticas.begin(); it != estadisticas.end(); ++it) 
		res.insert(it->second->DarEstadisticas(vj));
	return res;
}