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

vector<DataEstadisticaDeSegundoTipo *> Desarrollador::DarEstadisticas(Videojuego *vj) {
	vector<DataEstadisticaDeSegundoTipo *> res;
	for (int i = 0; i < estadisticas.size(); i++)
		res.push_back(*estadisticas[i]->DarEstadisticas(vj));
	return res;
}

void Desarrollador::getEstadisticas(vector<Estadistica *> estadist) {
    estadisticas = estadist;
}
