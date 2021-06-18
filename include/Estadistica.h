#ifndef ESTADISTICA
#define ESTADISTICA


#include "DtEstadisticaDeSegundoTipo.h"

#include <string>


class Videojuego;

class Estadistica {

private:
	string Nombre;
    string Descripcion;
	
public:
	Estadistica(string Nombre, string Descripcion);

	string getNombre();
	string getDescripcion();
    
    virtual DtEstadisticaDeSegundoTipo* DarEstadistica(Videojuego* vjp) = 0;
    
    virtual ~Estadistica() = 0;
};

#include "Videojuego.h"

#endif
