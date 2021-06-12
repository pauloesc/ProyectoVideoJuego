#include "../include/Desarrollador.h"

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

vector<DtEstadisticaDeSegundoTipo *> Desarrollador::DarEstadisticas(Videojuego *vj) {
	vector<DtEstadisticaDeSegundoTipo *> res;
	for (long unsigned int i = 0; i < estadisticas.size(); i++)
		res.push_back((estadisticas[i])->DarEstadistica(vj));
	return res;
}

void Desarrollador::setEstadisticas(vector<Estadistica *> estadist) {
    estadisticas = estadist;
}
