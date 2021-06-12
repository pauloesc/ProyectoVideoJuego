#ifndef ESTADISTICATOTALJUGADORESSUSCRIPTOS
#define ESTADISTICATOTALJUGADORESSUSCRIPTOS

#include "ControladorUsuario.h"
#include "Estadistica.h"


class TotalJugadoresSuscriptos : public Estadistica{
private:

public:
	DtEstadisticaDeSegundoTipo* DarEstadistica(VideoJuego* vjp);
};

#endif

