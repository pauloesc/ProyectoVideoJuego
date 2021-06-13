#ifndef ESTADISTICATOTALJUGADORESSUSCRIPTOS
#define ESTADISTICATOTALJUGADORESSUSCRIPTOS

#include "ControladorUsuario.h"
#include "Estadistica.h"


class TotalJugadoresSuscriptos : public Estadistica{
private:

public:
	TotalJugadoresSuscriptos(string nom, string des);
	DtEstadisticaDeSegundoTipo* DarEstadistica(Videojuego* vjp);

	~TotalJugadoresSuscriptos();
};

#endif

