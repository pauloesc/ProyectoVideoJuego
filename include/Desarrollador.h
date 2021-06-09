#ifndef DESARROLLADOR
#define DESARROLLADOR

#include <vector>

#include "Usuario.h"
#include "Videojuego.h"
#include "DataEstadisticaDeSegundoTipo.h"
#include "Estadistica.h"


class Desarrollador : public Usuario {
	private:
		string nombreEmpresa;
		vector <Estadistica *> estadisticas;
	public:
		Desarrollador (string unEmail, string unaContrasenia, string unaEmpresa);
		string getnomEmpresa ();
		vector<DataEstadisticaDeSegundoTipo *> DarEstadisticas(Videojuego *vj);
		bool esJugador();
        void getEstadisticas(vector<Estadistica *> estadist);
};


#endif