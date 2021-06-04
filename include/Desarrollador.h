#ifndef DESARROLLADOR
#define DESARROLLADOR

#include <set>
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
		Desarrollador (string unEmail, string unaContraseña, string unaEmpresa);
		string getnomEmpresa ();
		set <DataEstadisticaDeSegundoTipo> DarEstadisticas(Videojuego vj);
};


#endif
