#ifndef ESTADISTICA
#define ESTADISTICA

#include "Videojuego.h"
#include "DtEstadisticaDeSegundoTipo.h"

class Videojuego;

class Estadistica {

private:
	string Nombre;
    string Descripcion;
	
public:
	Estadistica(string Nombre, string Descripcion);

	string getNombre();
	string getDescripcion();
    
    virtual DtEstadisticaDeSegundoTipo DarEstadistica(Videojuego* vjp) = 0;
    
    ~Estadistica();
};


#endif
