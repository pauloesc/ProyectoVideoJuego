#ifndef ESTADISTICATOTALHORASJUGADAS
#define ESTADISTICATOTALHORASJUGADAS

#include "Estadistica.h"

class TotalHorasJugadas : public Estadistica {
private:

public:
	TotalHorasJugadas(string nom, string desc);
	DtEstadisticaDeSegundoTipo* DarEstadistica(Videojuego* vjp);

	~TotalHorasJugadas();

};



#endif
