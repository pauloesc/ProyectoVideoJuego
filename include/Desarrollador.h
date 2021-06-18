#ifndef DESARROLLADOR
#define DESARROLLADOR

#include <vector>

#include "Usuario.h"
#include "DtEstadisticaDeSegundoTipo.h"


class Estadistica;
class Videojuego;

class Desarrollador : public Usuario {
	private:
		string nombreEmpresa;
		vector <Estadistica *> estadisticas;
	public:
		Desarrollador (string unEmail, string unaContrasenia, string unaEmpresa);
		string getnomEmpresa ();
		vector<DtEstadisticaDeSegundoTipo *> DarEstadisticas(Videojuego *vj);
		bool esJugador();
        void setEstadisticas(vector<Estadistica *> estadist);
		
		~Desarrollador();
};

#include "Estadistica.h"
#include "Videojuego.h"

#endif