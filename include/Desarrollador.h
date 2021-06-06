#ifndef DESARROLLADOR
#define DESARROLLADOR

#include <vector>
#include <map>

#include "Usuario.h"
#include "Videojuego.h"
#include "DataEstadisticaDeSegundoTipo.h" //Acordarme que si ponen todos los dt en una carpeta cambiar esto
#include "Estadistica.h"


class Desarrollador : public Usuario {
	private:
		string nombreEmpresa;
		map <string, Estadistica *> estadisticas;
	public:
		Desarrollador (string unEmail, string unaContrasenia, string unaEmpresa);
		string getnomEmpresa ();
		vector<DataEstadisticaDeSegundoTipo> DarEstadisticas(Videojuego vj);
		bool esJugador();
};


#endif
