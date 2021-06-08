#ifndef ESTADISTICA
#define ESTADISTICA
#include "Videojuego.h"
#include "DataEstadisticaDeSegundoTipo.h"

class Estadistica {

private:
	string Nombre;
    string Descripcion;
	
public:
	Estadistica(string Nombre, string Descripcion);

	string getNombre();
	string getDescripcion();
    
    virtual DataEstadisticaDeSegundoTipo DarEstadistica(VideoJuego* vjp) = 0;
    
    ~Estadistica();
};


#endif
