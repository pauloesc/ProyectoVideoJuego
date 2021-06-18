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

/*
esta funcion funcion pero solo hay que usarla si es que queremos que el desarollador pueda seguir ingresando estadisticas sin borrar las anteriores
void Desarrollador::setEstadisticas(vector<Estadistica *> estadist) {

	int max = estadist.size();

	for( int i=0; i < max; i++ ){

		Estadistica * eAgregar = estadist[i];

		bool Encontrado = 0; 
		int j = 0;
		int max2 = estadisticas.size();

		while ( (j < max2) && (!Encontrado) ){
			
			if( estadisticas[j] == eAgregar ){
				Encontrado = 1;
			}

			j++;
		}
		
		if(!Encontrado){
			estadisticas.push_back(eAgregar);
		}
	}
}
*/


void Desarrollador::setEstadisticas(vector<Estadistica *> estadist) {
    estadisticas = estadist;
}

Desarrollador::~Desarrollador(){
    
}
